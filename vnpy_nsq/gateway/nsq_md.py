import sys
from datetime import datetime
from typing import Dict
from pathlib import Path

from vnpy.trader.constant import Exchange, Product
from vnpy.trader.gateway import BaseGateway
from vnpy.trader.object import (
    TickData,
    ContractData,
    SubscribeRequest,
)
from vnpy.trader.utility import get_folder_path, ZoneInfo

from ..api import (
    MdApi,
    HS_EI_SSE,
    HS_EI_SZSE
)


# 交易所映射
EXCHANGE_NSQ2VT: Dict[str, Exchange] = {
    HS_EI_SSE: Exchange.SSE,
    HS_EI_SZSE: Exchange.SZSE
}
EXCHANGE_VT2NSQ: Dict[Exchange, str] = {v: k for k, v in EXCHANGE_NSQ2VT.items()}

# 其他常量
MAX_FLOAT = sys.float_info.max                  # 浮点数极限值
CHINA_TZ = ZoneInfo("Asia/Shanghai")       # 中国时区


class NsqMdApi(MdApi):
    """"""

    def __init__(self, gateway: BaseGateway) -> None:
        """构造函数"""
        super().__init__()

        self.gateway: BaseGateway = gateway
        self.gateway_name: str = gateway.gateway_name

        self.reqid: int = 0

        self.inited: bool = False
        self.login_status: bool = False
        self.subscribed: set = set()
        self.symbol_contract_map: Dict[str, ContractData] = {}

        self.accountid: str = ""
        self.password: str = ""

    def onFrontConnected(self) -> None:
        """服务器连接成功回报"""
        self.gateway.write_log("行情服务器连接成功")
        self.login()

    def onFrontDisconnected(self, reason: int) -> None:
        """服务器连接断开回报"""
        self.login_status ==  False
        msg: str = self.getApiErrorMsg(reason)
        self.gateway.write_log(f"行情服务器连接断开，原因{msg}")

    def onRspUserLogin(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """用户登录请求回报"""
        if not error["ErrorID"]:
            self.login_status = True
            self.gateway.write_log("行情服务器登录成功")
            self.query_contract()

        else:
            self.gateway.write_error("行情服务器登录失败", error)

    def onRspQrySecuInstruments(self, data: dict, error: dict, reqid: int, last: bool) -> None:
        """合约信息查询回报"""
        if not error["ErrorID"]:
            return

        contract: ContractData = ContractData(
            symbol=data["InstrumentID"],
            exchange=EXCHANGE_NSQ2VT[data["ExchangeID"]],
            name=data["InstrumentName"],
            product=Product.EQUITY,
            size=1,
            pricetick=data["PriceTick"],
            gateway_name=self.gateway_name
        )
        self.gateway.on_contract(contract)
        self.symbol_contract_map[contract.symbol] = contract

        if last:
            self.gateway.write_log(f"{contract.exchange.value}合约信息查询成功")

    def onRspSecuDepthMarketDataSubscribe(self, error: dict, reqid: int, last: bool) -> None:
        """订阅行情回报"""
        if not error["ErrorID"]:
            return

        self.gateway.write_error("行情订阅失败", error)

    def onRtnSecuDepthMarketData(self, data: dict) -> None:
        """行情数据推送"""
        # 过滤没有时间戳的异常行情数据
        if not data["UpdateTime"]:
            return

        # 过滤还没有收到合约数据前的行情推送
        symbol: str = data["InstrumentID"]
        contract: ContractData = self.symbol_contract_map.get(symbol, None)
        if not contract:
            return

        timestamp: str = f"{data['TradeDate']} {data['UpdateTime']}"
        dt: datetime = datetime.strptime(timestamp, "%Y%m%d %H:%M:%S%f")
        dt: datetime = dt.replace(tzinfo=CHINA_TZ)

        tick: TickData = TickData(
            symbol=symbol,
            exchange=contract.exchange,
            datetime=dt,
            name=contract.name,
            volume=data["TradeVolume"],
            turnover=data["TradeBalance"],
            last_price=adjust_price(data["LastPrice"]),
            limit_up=data["UpperLimitPrice"],
            limit_down=data["LowerLimitPrice"],
            open_price=adjust_price(data["OpenPrice"]),
            high_price=adjust_price(data["HighPrice"]),
            low_price=adjust_price(data["LowPrice"]),
            pre_close=adjust_price(data["ClosePrice"]),
            gateway_name=self.gateway_name
        )

        tick.bid_price_1, tick.bid_price_2, tick.bid_price_3, tick.bid_price_4, tick.bid_price_5 = data["bid"][0:5]
        tick.ask_price_1, tick.ask_price_2, tick.ask_price_3, tick.ask_price_4, tick.ask_price_5 = data["ask"][0:5]
        tick.bid_volume_1, tick.bid_volume_2, tick.bid_volume_3, tick.bid_volume_4, tick.bid_volume_5 = data["bid_qty"][0:5]
        tick.ask_volume_1, tick.ask_volume_2, tick.ask_volume_3, tick.ask_volume_4, tick.ask_volume_5 = data["ask_qty"][0:5]

        self.gateway.on_tick(tick)

    def connect(self, accountid: str, password: str) -> None:
        """连接服务器"""
        self.accountid = accountid
        self.password = password

        # 禁止重复发起连接，会导致异常崩溃
        if not self.inited:
            path: Path = get_folder_path(self.gateway_name.lower())
            self.newNsqApi((str(path) + "\\Md").encode("GBK"))

            self.init("", "", "", "", "")

            self.inited = True

    def login(self) -> None:
        """用户登录"""
        nsq_req: dict = {
            "AccountID": self.accountid,
            "Password": self.password,
        }

        self.reqid += 1
        self.reqUserLogin(nsq_req, self.reqid)

    def subscribe(self, req: SubscribeRequest) -> None:
        """订阅行情"""
        contract: ContractData = self.symbol_contract_map.get(req.symbol, None)

        if contract:
            self.reqid += 1
            nsq_req: dict = {
                "ExchangeID":EXCHANGE_VT2NSQ[req.exchange],
                "InstrumentID": req.symbol
            }
            self.reqSecuDepthMarketDataSubscribe(nsq_req, 1, self.reqid)
            self.subscribed.add(req.symbol)

    def query_contract(self) -> None:
        """查询合约"""
        self.reqid += 1
        self.reqQrySecuInstruments({"ExchangeID": EXCHANGE_VT2NSQ[Exchange.SSE]}, 0, self.reqid)
        self.reqid += 1
        self.reqQrySecuInstruments({"ExchangeID": EXCHANGE_VT2NSQ[Exchange.SZSE]}, 0, self.reqid)

    def close(self) -> None:
        """关闭连接"""
        if self.inited:
            self.exit()


def adjust_price(price: float) -> float:
    """将异常的浮点数最大值（MAX_FLOAT）数据调整为0"""
    if price == MAX_FLOAT:
        price = 0
    return price
