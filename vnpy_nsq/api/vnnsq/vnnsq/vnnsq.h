//系统
#ifdef WIN32
#include "stdafx.h"
#endif

#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <iostream>
#include <codecvt>
#include <condition_variable>
#include <locale>

#include "pybind11/pybind11.h"
#include "nsq/HSNsqApi.h"

using namespace std;
using namespace pybind11;

//任务结构体
struct Task
{
	int task_name;		//回调函数名称对应的常量
	void *task_data;	//数据指针
	void *task_info;	//信息指针
	void *task_error;	//错误指针
	int task_id;		//请求id
	bool task_last;		//是否为最后返回
};

class TerminatedError : std::exception
{};

class TaskQueue
{
private:
	queue<Task> queue_;						//标准库队列
	mutex mutex_;							//互斥锁
	condition_variable cond_;				//条件变量

	bool _terminate = false;

public:

	//存入新的任务
	void push(const Task &task)
	{
		unique_lock<mutex > mlock(mutex_);
		queue_.push(task);					//向队列中存入数据
		mlock.unlock();						//释放锁
		cond_.notify_one();					//通知正在阻塞等待的线程
	}

	//取出老的任务
	Task pop()
	{
		unique_lock<mutex> mlock(mutex_);
		cond_.wait(mlock, [&]() {
			return !queue_.empty() || _terminate;
		});				//等待条件变量通知
		if (_terminate)
			throw TerminatedError();
		Task task = queue_.front();			//获取队列中的最后一个任务
		queue_.pop();						//删除该任务
		return task;						//返回该任务
	}

	void terminate()
	{
		_terminate = true;
		cond_.notify_all();					//通知正在阻塞等待的线程
	}
};


//从字典中获取某个建值对应的整数，并赋值到请求结构体对象的值上
void getInt(const dict &d, const char *key, int *value)
{
	if (d.contains(key))		//检查字典中是否存在该键值
	{
		object o = d[key];		//获取该键值
		*value = o.cast<int>();
	}
};

//从字典中获取某个建值对应的整数，并赋值到请求结构体对象的值上
void getLonglong(const dict &d, const char *key, long long *value)
{
	if (d.contains(key))		//检查字典中是否存在该键值
	{
		object o = d[key];		//获取该键值
		*value = o.cast<long long>();
	}
};


//从字典中获取某个建值对应的浮点数，并赋值到请求结构体对象的值上
void getDouble(const dict &d, const char *key, double *value)
{
	if (d.contains(key))
	{
		object o = d[key];
		*value = o.cast<double>();
	}
};


//从字典中获取某个建值对应的字符，并赋值到请求结构体对象的值上
void getChar(const dict &d, const char *key, char *value)
{
	if (d.contains(key))
	{
		object o = d[key];
		*value = o.cast<char>();
	}
};


template <size_t size>
using string_literal = char[size];

//从字典中获取某个建值对应的字符串，并赋值到请求结构体对象的值上
template <size_t size>
void getString(const pybind11::dict &d, const char *key, string_literal<size> &value)
{
	if (d.contains(key))
	{
		object o = d[key];
		string s = o.cast<string>();
		const char *buf = s.c_str();
		strcpy(value, buf);
	}
};

//将GBK编码的字符串转换为UTF8
inline string toUtf(const string &gb2312)
{
#ifdef _MSC_VER
	const static locale loc("zh-CN");
#else
	const static locale loc("zh_CN.GB18030");
#endif

	vector<wchar_t> wstr(gb2312.size());
	wchar_t* wstrEnd = nullptr;
	const char* gbEnd = nullptr;
	mbstate_t state = {};
	int res = use_facet<codecvt<wchar_t, char, mbstate_t> >
		(loc).in(state,
			gb2312.data(), gb2312.data() + gb2312.size(), gbEnd,
			wstr.data(), wstr.data() + wstr.size(), wstrEnd);

	if (codecvt_base::ok == res)
	{
		wstring_convert<codecvt_utf8<wchar_t>> cutf8;
		return cutf8.to_bytes(wstring(wstr.data(), wstrEnd));
	}

	return string();
}

//常量
#define ONFRONTCONNECTED 0
#define ONFRONTDISCONNECTED 1
#define ONRSPUSERLOGIN 2
#define ONRSPFUTUDEPTHMARKETDATASUBSCRIBE 3
#define ONRSPFUTUDEPTHMARKETDATACANCEL 4
#define ONRTNFUTUDEPTHMARKETDATA 5
#define ONRSPQRYFUTUINSTRUMENTS 6
#define ONRSPQRYFUTUDEPTHMARKETDATA 7
#define ONRSPSECUDEPTHMARKETDATASUBSCRIBE 8
#define ONRSPSECUDEPTHMARKETDATACANCEL 9
#define ONRTNSECUDEPTHMARKETDATA 10
#define ONRTNSECUATPMARKETDATA 11
#define ONRSPSECUTRANSACTIONSUBSCRIBE 12
#define ONRSPSECUTRANSACTIONCANCEL 13
#define ONRTNSECUTRANSACTIONTRADEDATA 14
#define ONRTNSECUTRANSACTIONENTRUSTDATA 15
#define ONRTNSECUATPTRANSACTIONTRADEDATA 16
#define ONRTNBONDTRANSACTIONTRADEDATA 17
#define ONRTNBONDTRANSACTIONENTRUSTDATA 18
#define ONRSPQRYSECUINSTRUMENTS 19
#define ONRSPQRYSECUDEPTHMARKETDATA 20
#define ONRSPOPTDEPTHMARKETDATASUBSCRIBE 21
#define ONRSPOPTDEPTHMARKETDATACANCEL 22
#define ONRTNOPTDEPTHMARKETDATA 23
#define ONRSPQRYOPTINSTRUMENTS 24
#define ONRSPQRYOPTDEPTHMARKETDATA 25
#define ONRSPSECUDEPTHMARKETDATAPLUSSUBSCRIBE 26
#define ONRSPSECUDEPTHMARKETDATAPLUSCANCEL 27
#define ONRTNSECUDEPTHMARKETDATAPLUS 28
#define ONRTNSECUDEPTHMARKETDATAPLUSSTOPNOTICE 29
#define ONRSPSECUTRANSACTIONDATA 30
#define ONRSPSECUTRANSACTIONDATATIMEOUT 31
#define ONRSPQRYHKTINSTRUMENTS 32
#define ONRTNHKTDEPTHMARKETDATA 33

//API的继承实现
///-------------------------------------------------------------------------------------
///C++ SPI的回调函数方法实现
///-------------------------------------------------------------------------------------

//API的继承实现
class MdApi : public CHSNsqSpi
{
private:
	CHSNsqApi* api;            //API对象
	thread task_thread;                    //工作线程指针（向python中推送数据）
	TaskQueue task_queue;                //任务队列
	bool active = false;                //工作状态

public:
	MdApi()
	{
	};

	~MdApi()
	{
		if (this->active)
		{
			this->exit();
		}
	};

	//-------------------------------------------------------------------------------------
	//API回调函数
	//-------------------------------------------------------------------------------------
	/// Description: 当客户端与后台开始建立通信连接，连接成功后此方法被回调。
	virtual void OnFrontConnected();

	/// Description:当客户端与后台通信连接异常时，该方法被调用。
	/// Others     :通过GetApiErrorMsg(nResult)获取详细错误信息。
	virtual void OnFrontDisconnected(int nResult);


	/// Description:客户登录应答
	virtual void OnRspUserLogin(CHSNsqRspUserLoginField *pRspUserLogin, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	////以下是期货接口

	/// Description: 期货订阅-行情应答
	virtual void OnRspFutuDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 期货订阅取消-行情应答
	virtual void OnRspFutuDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-期货行情
	virtual void OnRtnFutuDepthMarketData(CHSNsqFutuDepthMarketDataField *pFutuDepthMarketData);

	/// Description: 获取当前交易日合约应答
	virtual void OnRspQryFutuInstruments(CHSNsqFutuInstrumentStaticInfoField *pFutuInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 获取合约的最新快照信息应答
	virtual void OnRspQryFutuDepthMarketData(CHSNsqFutuDepthMarketDataField *pFutuDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	////以下是现货接口

	/// Description: 订阅-现货快照行情应答	
	virtual void OnRspSecuDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 订阅取消-现货快照行情应答
	virtual void OnRspSecuDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-现货快照行情
	///Others     :Bid1Volume买一队列数组, Bid1Count买一队列数组个数, MaxBid1Count买一总委托笔数
	///           :Ask1Volume卖一队列数组, Ask1Count卖一队列数组个数, MaxAsk1Count卖一总委托笔数
	virtual void OnRtnSecuDepthMarketData(CHSNsqSecuDepthMarketDataField *pSecuDepthMarketData, HSIntVolume Bid1Volume[], HSNum Bid1Count, HSNum MaxBid1Count, HSIntVolume Ask1Volume[], HSNum Ask1Count, HSNum MaxAsk1Count);


	/// Description: 主推-现货盘后定价快照行情
	///Others     :Bid1Volume买一队列数组, Bid1Count买一队列数组个数, MaxBid1Count买一总委托笔数
	///           :Ask1Volume卖一队列数组, Ask1Count卖一队列数组个数, MaxAsk1Count卖一总委托笔数
	virtual void OnRtnSecuATPMarketData(CHSNsqSecuATPMarketDataField *pSecuDepthMarketData, HSIntVolume Bid1Volume[], HSNum Bid1Count, HSNum MaxBid1Count, HSIntVolume Ask1Volume[], HSNum Ask1Count, HSNum MaxAsk1Count);


	/// Description: 订阅-现货逐笔行情应答
	virtual void OnRspSecuTransactionSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 订阅取消-现货逐笔行情应答
	virtual void OnRspSecuTransactionCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-现货逐笔成交行情
	virtual void OnRtnSecuTransactionTradeData(CHSNsqSecuTransactionTradeDataField *pSecuTransactionTradeData);

	/// Description: 主推-现货逐笔委托行情
	virtual void OnRtnSecuTransactionEntrustData(CHSNsqSecuTransactionEntrustDataField *pSecuTransactionEntrustData);


	/// Description: 主推-现货盘后固定逐笔成交行情
	virtual void OnRtnSecuATPTransactionTradeData(CHSNsqSecuTransactionTradeDataField *pSecuTransactionTradeData);

	/// Description: 主推-深证新债券逐笔成交行情
	virtual void OnRtnBondTransactionTradeData(CHSNsqBondTransactionTradeDataField* pSecuTransactionTradeData);

	/// Description: 主推-深证新债券逐笔委托行情
	virtual void OnRtnBondTransactionEntrustData(CHSNsqBondTransactionEntrustDataField* pSecuTransactionEntrustData);


	/// Description: 获取当前交易日现货合约应答
	virtual void OnRspQrySecuInstruments(CHSNsqSecuInstrumentStaticInfoField *pSecuInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 获取现货合约的最新快照信息应答
	virtual void OnRspQrySecuDepthMarketData(CHSNsqSecuDepthMarketDataField *pSecuDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	////以下是期权接口

	/// Description: 期权订阅-行情应答
	virtual void OnRspOptDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 期权订阅取消-行情应答
	virtual void OnRspOptDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-期权行情
	virtual void OnRtnOptDepthMarketData(CHSNsqOptDepthMarketDataField *pOptDepthMarketData);

	/// Description: 获取当前交易日合约应答
	virtual void OnRspQryOptInstruments(CHSNsqOptInstrumentStaticInfoField *pOptInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 获取合约的最新快照信息应答
	virtual void OnRspQryOptDepthMarketData(CHSNsqOptDepthMarketDataField *pOptDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	////以下是现货快照Plus接口

	/// Description: 订阅-现货快照Plus行情应答	
	virtual void OnRspSecuDepthMarketDataPlusSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 订阅取消-现货快照Plus行情应答
	virtual void OnRspSecuDepthMarketDataPlusCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-现货快照Plus行情
	virtual void OnRtnSecuDepthMarketDataPlus(CHSNsqSecuDepthMarketDataPlusField *pSecuDepthMarketDataPlus);

	/// Description: 主推-现货快照Plus行情停止通知
	///Others     :当“快照Plus”服务发现交易所下发的某个通道的逐笔数据存在丢包时，“快照Plus”服务会自行发起对丢失逐笔数据的重建。
	///           在重建完成之前，“快照Plus”服务会周期性推送具体通道的停止通知，从而触发本回调。
	///           当重建完成后，具体通道的停止通知会停止推送，同时“快照Plus”服务会继续推送相应通道重建出来的快照
	virtual void OnRtnSecuDepthMarketDataPlusStopNotice(CHSNsqSecuDepthMarketDataPlusStopNoticeField *pSecuDepthMarketDataPlusStopNotice);

	////以下是现货逐笔重建接口

	/// Description: 重建应答-现货逐笔数据
	virtual void OnRspSecuTransactionData(CHSNsqSecuTransactionDataField *pSecuTransactionData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 重建应答超时-现货逐笔数据（本回调线程与其他回调线程不同）
	virtual void OnRspSecuTransactionDataTimeout(int nRequestID);


	////以下是港股通接口

	/// Description: 获取当前交易日合约应答
	virtual void OnRspQryHktInstruments(CHSNsqHktInstrumentStaticInfoField *pHktInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: 主推-港股通行情
	virtual void OnRtnHktDepthMarketData(CHSNsqHktDepthMarketDataField *pHktDepthMarketData);

	//-------------------------------------------------------------------------------------
	//task：任务
	//-------------------------------------------------------------------------------------

	void processTask();

	void processFrontConnected(Task *task);

	void processFrontDisconnected(Task *task);

	void processRspUserLogin(Task *task);

	void processRspFutuDepthMarketDataSubscribe(Task *task);

	void processRspFutuDepthMarketDataCancel(Task *task);

	void processRtnFutuDepthMarketData(Task *task);

	void processRspQryFutuInstruments(Task *task);

	void processRspQryFutuDepthMarketData(Task *task);

	void processRspSecuDepthMarketDataSubscribe(Task *task);

	void processRspSecuDepthMarketDataCancel(Task *task);

	void processRtnSecuDepthMarketData(Task *task);

	void processRtnSecuATPMarketData(Task *task);

	void processRspSecuTransactionSubscribe(Task *task);

	void processRspSecuTransactionCancel(Task *task);

	void processRtnSecuTransactionTradeData(Task *task);

	void processRtnSecuTransactionEntrustData(Task *task);

	void processRtnSecuATPTransactionTradeData(Task *task);

	void processRtnBondTransactionTradeData(Task *task);

	void processRtnBondTransactionEntrustData(Task *task);

	void processRspQrySecuInstruments(Task *task);

	void processRspQrySecuDepthMarketData(Task *task);

	void processRspOptDepthMarketDataSubscribe(Task *task);

	void processRspOptDepthMarketDataCancel(Task *task);

	void processRtnOptDepthMarketData(Task *task);

	void processRspQryOptInstruments(Task *task);

	void processRspQryOptDepthMarketData(Task *task);

	void processRspSecuDepthMarketDataPlusSubscribe(Task *task);

	void processRspSecuDepthMarketDataPlusCancel(Task *task);

	void processRtnSecuDepthMarketDataPlus(Task *task);

	void processRtnSecuDepthMarketDataPlusStopNotice(Task *task);

	void processRspSecuTransactionData(Task *task);

	void processRspSecuTransactionDataTimeout(Task *task);

	void processRspQryHktInstruments(Task *task);

	void processRtnHktDepthMarketData(Task *task);

	//-------------------------------------------------------------------------------------
	//data：回调函数的数据字典
	//error：回调函数的错误字典
	//id：请求id
	//last：是否为最后返回
	//i：整数
	//-------------------------------------------------------------------------------------

	virtual void onFrontConnected() {};

	virtual void onFrontDisconnected(int result) {};

	virtual void onRspUserLogin(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspFutuDepthMarketDataSubscribe(const dict &error, int requestid, bool islast) {};

	virtual void onRspFutuDepthMarketDataCancel(const dict &error, int requestid, bool islast) {};

	virtual void onRtnFutuDepthMarketData(const dict &data) {};

	virtual void onRspQryFutuInstruments(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryFutuDepthMarketData(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspSecuDepthMarketDataSubscribe(const dict &error, int requestid, bool islast) {};

	virtual void onRspSecuDepthMarketDataCancel(const dict &error, int requestid, bool islast) {};

	virtual void onRtnSecuDepthMarketData(const dict &data) {};

	virtual void onRtnSecuATPMarketData(const dict &data) {};

	virtual void onRspSecuTransactionSubscribe(const dict &error, int requestid, bool islast) {};

	virtual void onRspSecuTransactionCancel(const dict &error, int requestid, bool islast) {};

	virtual void onRtnSecuTransactionTradeData(const dict &data) {};

	virtual void onRtnSecuTransactionEntrustData(const dict &data) {};

	virtual void onRtnSecuATPTransactionTradeData(const dict &data) {};

	virtual void onRtnBondTransactionTradeData(const dict &data) {};

	virtual void onRtnBondTransactionEntrustData(const dict &data) {};

	virtual void onRspQrySecuInstruments(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQrySecuDepthMarketData(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspOptDepthMarketDataSubscribe(const dict &error, int requestid, bool islast) {};

	virtual void onRspOptDepthMarketDataCancel(const dict &error, int requestid, bool islast) {};

	virtual void onRtnOptDepthMarketData(const dict &data) {};

	virtual void onRspQryOptInstruments(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspQryOptDepthMarketData(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspSecuDepthMarketDataPlusSubscribe(const dict &error, int requestid, bool islast) {};

	virtual void onRspSecuDepthMarketDataPlusCancel(const dict &error, int requestid, bool islast) {};

	virtual void onRtnSecuDepthMarketDataPlus(const dict &data) {};

	virtual void onRtnSecuDepthMarketDataPlusStopNotice(const dict &data) {};

	virtual void onRspSecuTransactionData(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRspSecuTransactionDataTimeout(int requestid) {};

	virtual void onRspQryHktInstruments(const dict &data, const dict &error, int requestid, bool islast) {};

	virtual void onRtnHktDepthMarketData(const dict &data) {};

	//-------------------------------------------------------------------------------------
	//req:主动函数的请求字典
	//-------------------------------------------------------------------------------------

	void newNsqApi(string pszFlowPath);

	void newNsqApiExt(string pszFlowPath, string sdkCfgFilePath);

	void release();

	int init(string licFile);

	int join();

	int exit();

	string getApiErrorMsg(int errorCode);

	int registerFront(string pszFrontAddress);

	int registerFensServer(string pszFensAddress, string pszAccountID);

	int reqUserLogin(const dict &req, int reqid);

	int reqFutuDepthMarketDataSubscribe(const dict &req, int count, int reqid);

	int reqFutuDepthMarketDataCancel(const dict &req, int count, int reqid);

	int reqQryFutuInstruments(const dict &req, int count, int reqid);

	int reqQryFutuDepthMarketData(const dict &req, int count, int reqid);

	int reqSecuDepthMarketDataSubscribe(const dict &req, int count, int reqid);

	int reqSecuDepthMarketDataCancel(const dict &req, int count, int reqid);

	int reqSecuTransactionSubscribe(string type, const dict &req, int count, int reqid);

	int reqSecuTransactionCancel(string type, const dict &req, int count, int reqid);

	int reqQrySecuInstruments(const dict &req, int count, int reqid);

	int reqQrySecuDepthMarketData(const dict &req, int count, int reqid);

	int reqOptDepthMarketDataSubscribe(const dict &req, int count, int reqid);

	int reqOptDepthMarketDataCancel(const dict &req, int count, int reqid);

	int reqQryOptInstruments(const dict &req, int count, int reqid);

	int reqQryOptDepthMarketData(const dict &req, int count, int reqid);

	int reqSecuDepthMarketDataPlusSubscribe(const dict &req, int count, int reqid);

	int reqSecuDepthMarketDataPlusCancel(const dict &req, int count, int reqid);

	int reqSecuTransactionRebuild(const dict &req, int reqid);

	int reqQryHktInstruments(const dict &req, int count, int reqid);

};
