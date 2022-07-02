void MdApi::processFrontConnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontConnected();
};

void MdApi::processFrontDisconnected(Task *task)
{
	gil_scoped_acquire acquire;
	this->onFrontDisconnected(task->task_id);
};

void MdApi::processRspUserLogin(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqRspUserLoginField *task_data = (CHSNsqRspUserLoginField*)task->task_data;
		data["BranchID"] = task_data->BranchID;
		data["AccountID"] = toUtf(task_data->AccountID);
		data["UserName"] = toUtf(task_data->UserName);
		data["TradingDay"] = task_data->TradingDay;
		data["PreTradingDay"] = task_data->PreTradingDay;
		data["BillConfirmFlag"] = task_data->BillConfirmFlag;
		data["SessionID"] = task_data->SessionID;
		data["UserApplicationType"] = task_data->UserApplicationType;
		data["UserApplicationInfo"] = toUtf(task_data->UserApplicationInfo);
		data["RiskLevel"] = toUtf(task_data->RiskLevel);
		data["LastMacAddress"] = toUtf(task_data->LastMacAddress);
		data["LastIPAddress"] = toUtf(task_data->LastIPAddress);
		data["LastLoginTime"] = task_data->LastLoginTime;
		data["CZCETime"] = task_data->CZCETime;
		data["DCETime"] = task_data->DCETime;
		data["SHFETime"] = task_data->SHFETime;
		data["CFFEXTime"] = task_data->CFFEXTime;
		data["INETime"] = task_data->INETime;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspUserLogin(data, error, task->task_id, task->task_last);
};

void MdApi::processRspFutuDepthMarketDataSubscribe(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspFutuDepthMarketDataSubscribe(error, task->task_id, task->task_last);
};

void MdApi::processRspFutuDepthMarketDataCancel(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspFutuDepthMarketDataCancel(error, task->task_id, task->task_last);
};

void MdApi::processRtnFutuDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqFutuDepthMarketDataField *task_data = (CHSNsqFutuDepthMarketDataField*)task->task_data;
		data["TradingDay"] = task_data->TradingDay;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["OpenInterest"] = task_data->OpenInterest;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["UpdateTime"] = task_data->UpdateTime;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		data["AveragePrice"] = task_data->AveragePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		delete task_data;
	}
	this->onRtnFutuDepthMarketData(data);
};

void MdApi::processRspQryFutuInstruments(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqFutuInstrumentStaticInfoField *task_data = (CHSNsqFutuInstrumentStaticInfoField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["SecurityType"] = task_data->SecurityType;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PriceTick"] = task_data->PriceTick;
		data["BuyVolumeUnit"] = task_data->BuyVolumeUnit;
		data["SellVolumeUnit"] = task_data->SellVolumeUnit;
		data["TradeDate"] = task_data->TradeDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFutuInstruments(data, error, task->task_id, task->task_last);
};

void MdApi::processRspQryFutuDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqFutuDepthMarketDataField *task_data = (CHSNsqFutuDepthMarketDataField*)task->task_data;
		data["TradingDay"] = task_data->TradingDay;
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighestPrice"] = task_data->HighestPrice;
		data["LowestPrice"] = task_data->LowestPrice;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["OpenInterest"] = task_data->OpenInterest;
		data["ClosePrice"] = task_data->ClosePrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["UpdateTime"] = task_data->UpdateTime;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		data["AveragePrice"] = task_data->AveragePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryFutuDepthMarketData(data, error, task->task_id, task->task_last);
};

void MdApi::processRspSecuDepthMarketDataSubscribe(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSecuDepthMarketDataSubscribe(error, task->task_id, task->task_last);
};

void MdApi::processRspSecuDepthMarketDataCancel(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSecuDepthMarketDataCancel(error, task->task_id, task->task_last);
};

void MdApi::processRtnSecuDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuDepthMarketDataField *task_data = (CHSNsqSecuDepthMarketDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighPrice"] = task_data->HighPrice;
		data["LowPrice"] = task_data->LowPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["TradeDate"] = task_data->TradeDate;
		data["UpdateTime"] = task_data->UpdateTime;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["AveragePrice"] = task_data->AveragePrice;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		data["TradesNum"] = task_data->TradesNum;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		data["TotalBidVolume"] = task_data->TotalBidVolume;
		data["TotalAskVolume"] = task_data->TotalAskVolume;
		data["MaBidPrice"] = task_data->MaBidPrice;
		data["MaAskPrice"] = task_data->MaAskPrice;
		data["MaBondBidPrice"] = task_data->MaBondBidPrice;
		data["MaBondAskPrice"] = task_data->MaBondAskPrice;
		data["YieldToMaturity"] = task_data->YieldToMaturity;
		data["IOPV"] = task_data->IOPV;
		data["EtfBuycount"] = task_data->EtfBuycount;
		data["EtfSellCount"] = task_data->EtfSellCount;
		data["EtfBuyVolume"] = task_data->EtfBuyVolume;
		data["EtfBuyBalance"] = task_data->EtfBuyBalance;
		data["EtfSellVolume"] = task_data->EtfSellVolume;
		data["EtfSellBalance"] = task_data->EtfSellBalance;
		data["TotalWarrantExecVolume"] = task_data->TotalWarrantExecVolume;
		data["WarrantLowerPrice"] = task_data->WarrantLowerPrice;
		data["WarrantUpperPrice"] = task_data->WarrantUpperPrice;
		data["CancelBuyNum"] = task_data->CancelBuyNum;
		data["CancelSellNum"] = task_data->CancelSellNum;
		data["CancelBuyVolume"] = task_data->CancelBuyVolume;
		data["CancelSellVolume"] = task_data->CancelSellVolume;
		data["CancelBuyValue"] = task_data->CancelBuyValue;
		data["CancelSellValue"] = task_data->CancelSellValue;
		data["TotalBuyNum"] = task_data->TotalBuyNum;
		data["TotalSellNum"] = task_data->TotalSellNum;
		data["DurationAfterBuy"] = task_data->DurationAfterBuy;
		data["DurationAfterSell"] = task_data->DurationAfterSell;
		data["BidOrdersNum"] = task_data->BidOrdersNum;
		data["AskOrdersNum"] = task_data->AskOrdersNum;
		data["PreIOPV"] = task_data->PreIOPV;
		data["ChannelNo"] = task_data->ChannelNo;
		data["BondLastAuctionPrice"] = task_data->BondLastAuctionPrice;
		data["BondAuctionVolume"] = task_data->BondAuctionVolume;
		data["BondAuctionBalance"] = task_data->BondAuctionBalance;
		data["BondLastTradeType"] = task_data->BondLastTradeType;
		delete task_data;
	}
	this->onRtnSecuDepthMarketData(data, task->task_volume, task->task_count, task->task_count, task->task_volume, task->task_count, task->task_count);
};

void MdApi::processRtnSecuATPMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuATPMarketDataField *task_data = (CHSNsqSecuATPMarketDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["TradeDate"] = task_data->TradeDate;
		data["UpdateTime"] = task_data->UpdateTime;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["TradesNum"] = task_data->TradesNum;
		data["TotalBidVolume"] = task_data->TotalBidVolume;
		data["TotalAskVolume"] = task_data->TotalAskVolume;
		data["CancelBuyNum"] = task_data->CancelBuyNum;
		data["CancelSellNum"] = task_data->CancelSellNum;
		data["CancelBuyVolume"] = task_data->CancelBuyVolume;
		data["CancelSellVolume"] = task_data->CancelSellVolume;
		data["BidPrice1"] = task_data->BidPrice1;
		data["AskPrice1"] = task_data->AskPrice1;
		data["BidVolume1"] = task_data->BidVolume1;
		data["AskVolume1"] = task_data->AskVolume1;
		data["ChannelNo"] = task_data->ChannelNo;
		delete task_data;
	}
	this->onRtnSecuATPMarketData(data, task->task_volume, task->task_count, task->task_count, task->task_volume, task->task_count, task->task_count);
};

void MdApi::processRspSecuTransactionSubscribe(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSecuTransactionSubscribe(error, task->task_id, task->task_last);
};

void MdApi::processRspSecuTransactionCancel(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSecuTransactionCancel(error, task->task_id, task->task_last);
};

void MdApi::processRtnSecuTransactionTradeData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuTransactionTradeDataField *task_data = (CHSNsqSecuTransactionTradeDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["TransFlag"] = task_data->TransFlag;
		data["SeqNo"] = task_data->SeqNo;
		data["ChannelNo"] = task_data->ChannelNo;
		data["TradeDate"] = task_data->TradeDate;
		data["TransactTime"] = task_data->TransactTime;
		data["TrdPrice"] = task_data->TrdPrice;
		data["TrdVolume"] = task_data->TrdVolume;
		data["TrdMoney"] = task_data->TrdMoney;
		data["TrdBuyNo"] = task_data->TrdBuyNo;
		data["TrdSellNo"] = task_data->TrdSellNo;
		data["TrdBSFlag"] = task_data->TrdBSFlag;
		data["BizIndex"] = task_data->BizIndex;
		delete task_data;
	}
	this->onRtnSecuTransactionTradeData(data);
};

void MdApi::processRtnSecuTransactionEntrustData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuTransactionEntrustDataField *task_data = (CHSNsqSecuTransactionEntrustDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["TransFlag"] = task_data->TransFlag;
		data["SeqNo"] = task_data->SeqNo;
		data["ChannelNo"] = task_data->ChannelNo;
		data["TradeDate"] = task_data->TradeDate;
		data["TransactTime"] = task_data->TransactTime;
		data["OrdPrice"] = task_data->OrdPrice;
		data["OrdVolume"] = task_data->OrdVolume;
		data["OrdSide"] = task_data->OrdSide;
		data["OrdType"] = task_data->OrdType;
		data["OrdNo"] = task_data->OrdNo;
		data["BizIndex"] = task_data->BizIndex;
		delete task_data;
	}
	this->onRtnSecuTransactionEntrustData(data);
};

void MdApi::processRtnSecuATPTransactionTradeData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuTransactionTradeDataField *task_data = (CHSNsqSecuTransactionTradeDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["TransFlag"] = task_data->TransFlag;
		data["SeqNo"] = task_data->SeqNo;
		data["ChannelNo"] = task_data->ChannelNo;
		data["TradeDate"] = task_data->TradeDate;
		data["TransactTime"] = task_data->TransactTime;
		data["TrdPrice"] = task_data->TrdPrice;
		data["TrdVolume"] = task_data->TrdVolume;
		data["TrdMoney"] = task_data->TrdMoney;
		data["TrdBuyNo"] = task_data->TrdBuyNo;
		data["TrdSellNo"] = task_data->TrdSellNo;
		data["TrdBSFlag"] = task_data->TrdBSFlag;
		data["BizIndex"] = task_data->BizIndex;
		delete task_data;
	}
	this->onRtnSecuATPTransactionTradeData(data);
};

void MdApi::processRtnBondTransactionTradeData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqBondTransactionTradeDataField *task_data = (CHSNsqBondTransactionTradeDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["TransFlag"] = task_data->TransFlag;
		data["SeqNo"] = task_data->SeqNo;
		data["ChannelNo"] = task_data->ChannelNo;
		data["TradeDate"] = task_data->TradeDate;
		data["TransactTime"] = task_data->TransactTime;
		data["TrdPrice"] = task_data->TrdPrice;
		data["TrdVolume"] = task_data->TrdVolume;
		data["TrdBuyNo"] = task_data->TrdBuyNo;
		data["TrdSellNo"] = task_data->TrdSellNo;
		data["TrdBSFlag"] = task_data->TrdBSFlag;
		data["TradeType"] = task_data->TradeType;
		data["SettlPeriod"] = task_data->SettlPeriod;
		data["SettlType"] = task_data->SettlType;
		delete task_data;
	}
	this->onRtnBondTransactionTradeData(data);
};

void MdApi::processRtnBondTransactionEntrustData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqBondTransactionEntrustDataField *task_data = (CHSNsqBondTransactionEntrustDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["TransFlag"] = task_data->TransFlag;
		data["SeqNo"] = task_data->SeqNo;
		data["ChannelNo"] = task_data->ChannelNo;
		data["TradeDate"] = task_data->TradeDate;
		data["TransactTime"] = task_data->TransactTime;
		data["OrdPrice"] = task_data->OrdPrice;
		data["OrdVolume"] = task_data->OrdVolume;
		data["OrdSide"] = task_data->OrdSide;
		data["OrdType"] = task_data->OrdType;
		data["TradeType"] = task_data->TradeType;
		data["SettlPeriod"] = task_data->SettlPeriod;
		data["SettlType"] = task_data->SettlType;
		data["QuoteID"] = toUtf(task_data->QuoteID);
		data["MemberID"] = toUtf(task_data->MemberID);
		data["InvestorType"] = toUtf(task_data->InvestorType);
		data["InvestorID"] = toUtf(task_data->InvestorID);
		data["TraderCode"] = toUtf(task_data->TraderCode);
		delete task_data;
	}
	this->onRtnBondTransactionEntrustData(data);
};

void MdApi::processRspQrySecuInstruments(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuInstrumentStaticInfoField *task_data = (CHSNsqSecuInstrumentStaticInfoField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["SecurityType"] = task_data->SecurityType;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PriceTick"] = task_data->PriceTick;
		data["BuyVolumeUnit"] = task_data->BuyVolumeUnit;
		data["SellVolumeUnit"] = task_data->SellVolumeUnit;
		data["TradeDate"] = task_data->TradeDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecuInstruments(data, error, task->task_id, task->task_last);
};

void MdApi::processRspQrySecuDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuDepthMarketDataField *task_data = (CHSNsqSecuDepthMarketDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighPrice"] = task_data->HighPrice;
		data["LowPrice"] = task_data->LowPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["TradeDate"] = task_data->TradeDate;
		data["UpdateTime"] = task_data->UpdateTime;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["AveragePrice"] = task_data->AveragePrice;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		data["TradesNum"] = task_data->TradesNum;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		data["TotalBidVolume"] = task_data->TotalBidVolume;
		data["TotalAskVolume"] = task_data->TotalAskVolume;
		data["MaBidPrice"] = task_data->MaBidPrice;
		data["MaAskPrice"] = task_data->MaAskPrice;
		data["MaBondBidPrice"] = task_data->MaBondBidPrice;
		data["MaBondAskPrice"] = task_data->MaBondAskPrice;
		data["YieldToMaturity"] = task_data->YieldToMaturity;
		data["IOPV"] = task_data->IOPV;
		data["EtfBuycount"] = task_data->EtfBuycount;
		data["EtfSellCount"] = task_data->EtfSellCount;
		data["EtfBuyVolume"] = task_data->EtfBuyVolume;
		data["EtfBuyBalance"] = task_data->EtfBuyBalance;
		data["EtfSellVolume"] = task_data->EtfSellVolume;
		data["EtfSellBalance"] = task_data->EtfSellBalance;
		data["TotalWarrantExecVolume"] = task_data->TotalWarrantExecVolume;
		data["WarrantLowerPrice"] = task_data->WarrantLowerPrice;
		data["WarrantUpperPrice"] = task_data->WarrantUpperPrice;
		data["CancelBuyNum"] = task_data->CancelBuyNum;
		data["CancelSellNum"] = task_data->CancelSellNum;
		data["CancelBuyVolume"] = task_data->CancelBuyVolume;
		data["CancelSellVolume"] = task_data->CancelSellVolume;
		data["CancelBuyValue"] = task_data->CancelBuyValue;
		data["CancelSellValue"] = task_data->CancelSellValue;
		data["TotalBuyNum"] = task_data->TotalBuyNum;
		data["TotalSellNum"] = task_data->TotalSellNum;
		data["DurationAfterBuy"] = task_data->DurationAfterBuy;
		data["DurationAfterSell"] = task_data->DurationAfterSell;
		data["BidOrdersNum"] = task_data->BidOrdersNum;
		data["AskOrdersNum"] = task_data->AskOrdersNum;
		data["PreIOPV"] = task_data->PreIOPV;
		data["ChannelNo"] = task_data->ChannelNo;
		data["BondLastAuctionPrice"] = task_data->BondLastAuctionPrice;
		data["BondAuctionVolume"] = task_data->BondAuctionVolume;
		data["BondAuctionBalance"] = task_data->BondAuctionBalance;
		data["BondLastTradeType"] = task_data->BondLastTradeType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQrySecuDepthMarketData(data, error, task->task_id, task->task_last);
};

void MdApi::processRspOptDepthMarketDataSubscribe(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptDepthMarketDataSubscribe(error, task->task_id, task->task_last);
};

void MdApi::processRspOptDepthMarketDataCancel(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspOptDepthMarketDataCancel(error, task->task_id, task->task_last);
};

void MdApi::processRtnOptDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqOptDepthMarketDataField *task_data = (CHSNsqOptDepthMarketDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighPrice"] = task_data->HighPrice;
		data["LowPrice"] = task_data->LowPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["OpenInterest"] = task_data->OpenInterest;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PreDelta"] = task_data->PreDelta;
		data["CurDelta"] = task_data->CurDelta;
		data["TradeDate"] = task_data->TradeDate;
		data["UpdateTime"] = task_data->UpdateTime;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["AveragePrice"] = task_data->AveragePrice;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		data["TradesNum"] = task_data->TradesNum;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		data["OpenRestriction"] = toUtf(task_data->OpenRestriction);
		data["AuctionPrice"] = task_data->AuctionPrice;
		data["AuctionVolume"] = task_data->AuctionVolume;
		data["LastEnquiryTime"] = task_data->LastEnquiryTime;
		data["LeaveQty"] = task_data->LeaveQty;
		data["ChannelNo"] = task_data->ChannelNo;
		delete task_data;
	}
	this->onRtnOptDepthMarketData(data);
};

void MdApi::processRspQryOptInstruments(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqOptInstrumentStaticInfoField *task_data = (CHSNsqOptInstrumentStaticInfoField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstrumentTradeID"] = toUtf(task_data->InstrumentTradeID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["SecurityType"] = task_data->SecurityType;
		data["UnderlyingInstrID"] = toUtf(task_data->UnderlyingInstrID);
		data["OptionsType"] = task_data->OptionsType;
		data["ExerciseStyle"] = task_data->ExerciseStyle;
		data["ContractMultiplierUnit"] = task_data->ContractMultiplierUnit;
		data["ExercisePrice"] = task_data->ExercisePrice;
		data["StartDate"] = task_data->StartDate;
		data["EndDate"] = task_data->EndDate;
		data["ExerciseDate"] = task_data->ExerciseDate;
		data["DeliveryDate"] = task_data->DeliveryDate;
		data["ExpireDate"] = task_data->ExpireDate;
		data["TotalLongPosition"] = task_data->TotalLongPosition;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["PreSettlPrice"] = task_data->PreSettlPrice;
		data["UnderlyingClosePrice"] = task_data->UnderlyingClosePrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["MarginUnit"] = task_data->MarginUnit;
		data["MarginRatioParam1"] = task_data->MarginRatioParam1;
		data["MarginRatioParam2"] = task_data->MarginRatioParam2;
		data["VolumeMultiple"] = task_data->VolumeMultiple;
		data["MinLimitOrderVolume"] = task_data->MinLimitOrderVolume;
		data["MaxLimitOrderVolume"] = task_data->MaxLimitOrderVolume;
		data["MinMarketOrderVolume"] = task_data->MinMarketOrderVolume;
		data["MaxMarketOrderVolume"] = task_data->MaxMarketOrderVolume;
		data["PriceTick"] = task_data->PriceTick;
		data["TradeDate"] = task_data->TradeDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptInstruments(data, error, task->task_id, task->task_last);
};

void MdApi::processRspQryOptDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqOptDepthMarketDataField *task_data = (CHSNsqOptDepthMarketDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighPrice"] = task_data->HighPrice;
		data["LowPrice"] = task_data->LowPrice;
		data["ClosePrice"] = task_data->ClosePrice;
		data["PreOpenInterest"] = task_data->PreOpenInterest;
		data["OpenInterest"] = task_data->OpenInterest;
		data["PreSettlementPrice"] = task_data->PreSettlementPrice;
		data["SettlementPrice"] = task_data->SettlementPrice;
		data["UpperLimitPrice"] = task_data->UpperLimitPrice;
		data["LowerLimitPrice"] = task_data->LowerLimitPrice;
		data["PreDelta"] = task_data->PreDelta;
		data["CurDelta"] = task_data->CurDelta;
		data["TradeDate"] = task_data->TradeDate;
		data["UpdateTime"] = task_data->UpdateTime;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["AveragePrice"] = task_data->AveragePrice;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		data["TradesNum"] = task_data->TradesNum;
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		data["OpenRestriction"] = toUtf(task_data->OpenRestriction);
		data["AuctionPrice"] = task_data->AuctionPrice;
		data["AuctionVolume"] = task_data->AuctionVolume;
		data["LastEnquiryTime"] = task_data->LastEnquiryTime;
		data["LeaveQty"] = task_data->LeaveQty;
		data["ChannelNo"] = task_data->ChannelNo;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryOptDepthMarketData(data, error, task->task_id, task->task_last);
};

void MdApi::processRspSecuDepthMarketDataPlusSubscribe(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSecuDepthMarketDataPlusSubscribe(error, task->task_id, task->task_last);
};

void MdApi::processRspSecuDepthMarketDataPlusCancel(Task *task)
{
	gil_scoped_acquire acquire;
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSecuDepthMarketDataPlusCancel(error, task->task_id, task->task_last);
};

void MdApi::processRtnSecuDepthMarketDataPlus(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuDepthMarketDataPlusField *task_data = (CHSNsqSecuDepthMarketDataPlusField*)task->task_data;
		data["ChannelNo"] = task_data->ChannelNo;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LastPrice"] = task_data->LastPrice;
		data["OpenPrice"] = task_data->OpenPrice;
		data["HighPrice"] = task_data->HighPrice;
		data["LowPrice"] = task_data->LowPrice;
		data["TradeDate"] = task_data->TradeDate;
		data["UpdateTime"] = task_data->UpdateTime;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["TotalBidVolume"] = task_data->TotalBidVolume;
		data["TotalAskVolume"] = task_data->TotalAskVolume;
		data["TradesNum"] = task_data->TradesNum;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		delete task_data;
	}
	this->onRtnSecuDepthMarketDataPlus(data);
};

void MdApi::processRtnSecuDepthMarketDataPlusStopNotice(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuDepthMarketDataPlusStopNoticeField *task_data = (CHSNsqSecuDepthMarketDataPlusStopNoticeField*)task->task_data;
		data["ChannelNo"] = task_data->ChannelNo;
		delete task_data;
	}
	this->onRtnSecuDepthMarketDataPlusStopNotice(data);
};

void MdApi::processRspSecuTransactionData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqSecuTransactionDataField *task_data = (CHSNsqSecuTransactionDataField*)task->task_data;
		data["LatestSeqNo"] = task_data->LatestSeqNo;
		data["TransType"] = task_data->TransType;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspSecuTransactionData(data, error, task->task_id, task->task_last);
};

void MdApi::processRspSecuTransactionDataTimeout(Task *task)
{
	gil_scoped_acquire acquire;
	this->onRspSecuTransactionDataTimeout(task->task_id);
};

void MdApi::processRspQryHktInstruments(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqHktInstrumentStaticInfoField *task_data = (CHSNsqHktInstrumentStaticInfoField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["InstrumentName"] = toUtf(task_data->InstrumentName);
		data["SecurityType"] = task_data->SecurityType;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["BuyVolumeUnit"] = task_data->BuyVolumeUnit;
		data["SellVolumeUnit"] = task_data->SellVolumeUnit;
		data["TradeDate"] = task_data->TradeDate;
		delete task_data;
	}
	dict error;
	if (task->task_error)
	{
		CHSNsqRspInfoField *task_error = (CHSNsqRspInfoField*)task->task_error;
		error["ErrorID"] = task_error->ErrorID;
		error["ErrorMsg"] = toUtf(task_error->ErrorMsg);
		delete task_error;
	}
	this->onRspQryHktInstruments(data, error, task->task_id, task->task_last);
};

void MdApi::processRtnHktDepthMarketData(Task *task)
{
	gil_scoped_acquire acquire;
	dict data;
	if (task->task_data)
	{
		CHSNsqHktDepthMarketDataField *task_data = (CHSNsqHktDepthMarketDataField*)task->task_data;
		data["ExchangeID"] = toUtf(task_data->ExchangeID);
		data["InstrumentID"] = toUtf(task_data->InstrumentID);
		data["LastPrice"] = task_data->LastPrice;
		data["PreClosePrice"] = task_data->PreClosePrice;
		data["HighPrice"] = task_data->HighPrice;
		data["LowPrice"] = task_data->LowPrice;
		data["NomianlPrice"] = task_data->NomianlPrice;
		data["TradeDate"] = task_data->TradeDate;
		data["UpdateTime"] = task_data->UpdateTime;
		data["TradeVolume"] = task_data->TradeVolume;
		data["TradeBalance"] = task_data->TradeBalance;
		data["BidPrice"] = toUtf(task_data->BidPrice);
		data["AskPrice"] = toUtf(task_data->AskPrice);
		data["BidVolume"] = toUtf(task_data->BidVolume);
		data["AskVolume"] = toUtf(task_data->AskVolume);
		data["InstrumentTradeStatus"] = task_data->InstrumentTradeStatus;
		data["BoardLotOrderBidLimit"] = task_data->BoardLotOrderBidLimit;
		data["BoardLotOrderAskLimit"] = task_data->BoardLotOrderAskLimit;
		data["OddLotOrderBidLimit"] = task_data->OddLotOrderBidLimit;
		data["OddLotOrderAskLimit"] = task_data->OddLotOrderAskLimit;
		data["ChannelNo"] = task_data->ChannelNo;
		delete task_data;
	}
	this->onRtnHktDepthMarketData(data);
};

