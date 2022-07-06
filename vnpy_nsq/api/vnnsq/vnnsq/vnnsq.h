//ϵͳ
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

//����ṹ��
struct Task
{
	int task_name;		//�ص��������ƶ�Ӧ�ĳ���
	void *task_data;	//����ָ��
	void *task_info;	//��Ϣָ��
	void *task_error;	//����ָ��
	int task_id;		//����id
	bool task_last;		//�Ƿ�Ϊ��󷵻�
};

class TerminatedError : std::exception
{};

class TaskQueue
{
private:
	queue<Task> queue_;						//��׼�����
	mutex mutex_;							//������
	condition_variable cond_;				//��������

	bool _terminate = false;

public:

	//�����µ�����
	void push(const Task &task)
	{
		unique_lock<mutex > mlock(mutex_);
		queue_.push(task);					//������д�������
		mlock.unlock();						//�ͷ���
		cond_.notify_one();					//֪ͨ���������ȴ����߳�
	}

	//ȡ���ϵ�����
	Task pop()
	{
		unique_lock<mutex> mlock(mutex_);
		cond_.wait(mlock, [&]() {
			return !queue_.empty() || _terminate;
		});				//�ȴ���������֪ͨ
		if (_terminate)
			throw TerminatedError();
		Task task = queue_.front();			//��ȡ�����е����һ������
		queue_.pop();						//ɾ��������
		return task;						//���ظ�����
	}

	void terminate()
	{
		_terminate = true;
		cond_.notify_all();					//֪ͨ���������ȴ����߳�
	}
};


//���ֵ��л�ȡĳ����ֵ��Ӧ������������ֵ������ṹ������ֵ��
void getInt(const dict &d, const char *key, int *value)
{
	if (d.contains(key))		//����ֵ����Ƿ���ڸü�ֵ
	{
		object o = d[key];		//��ȡ�ü�ֵ
		*value = o.cast<int>();
	}
};

//���ֵ��л�ȡĳ����ֵ��Ӧ������������ֵ������ṹ������ֵ��
void getLonglong(const dict &d, const char *key, long long *value)
{
	if (d.contains(key))		//����ֵ����Ƿ���ڸü�ֵ
	{
		object o = d[key];		//��ȡ�ü�ֵ
		*value = o.cast<long long>();
	}
};


//���ֵ��л�ȡĳ����ֵ��Ӧ�ĸ�����������ֵ������ṹ������ֵ��
void getDouble(const dict &d, const char *key, double *value)
{
	if (d.contains(key))
	{
		object o = d[key];
		*value = o.cast<double>();
	}
};


//���ֵ��л�ȡĳ����ֵ��Ӧ���ַ�������ֵ������ṹ������ֵ��
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

//���ֵ��л�ȡĳ����ֵ��Ӧ���ַ���������ֵ������ṹ������ֵ��
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

//��GBK������ַ���ת��ΪUTF8
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

//����
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

//API�ļ̳�ʵ��
///-------------------------------------------------------------------------------------
///C++ SPI�Ļص���������ʵ��
///-------------------------------------------------------------------------------------

//API�ļ̳�ʵ��
class MdApi : public CHSNsqSpi
{
private:
	CHSNsqApi* api;            //API����
	thread task_thread;                    //�����߳�ָ�루��python���������ݣ�
	TaskQueue task_queue;                //�������
	bool active = false;                //����״̬

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
	//API�ص�����
	//-------------------------------------------------------------------------------------
	/// Description: ���ͻ������̨��ʼ����ͨ�����ӣ����ӳɹ���˷������ص���
	virtual void OnFrontConnected();

	/// Description:���ͻ������̨ͨ�������쳣ʱ���÷��������á�
	/// Others     :ͨ��GetApiErrorMsg(nResult)��ȡ��ϸ������Ϣ��
	virtual void OnFrontDisconnected(int nResult);


	/// Description:�ͻ���¼Ӧ��
	virtual void OnRspUserLogin(CHSNsqRspUserLoginField *pRspUserLogin, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	////�������ڻ��ӿ�

	/// Description: �ڻ�����-����Ӧ��
	virtual void OnRspFutuDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: �ڻ�����ȡ��-����Ӧ��
	virtual void OnRspFutuDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-�ڻ�����
	virtual void OnRtnFutuDepthMarketData(CHSNsqFutuDepthMarketDataField *pFutuDepthMarketData);

	/// Description: ��ȡ��ǰ�����պ�ԼӦ��
	virtual void OnRspQryFutuInstruments(CHSNsqFutuInstrumentStaticInfoField *pFutuInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ��ȡ��Լ�����¿�����ϢӦ��
	virtual void OnRspQryFutuDepthMarketData(CHSNsqFutuDepthMarketDataField *pFutuDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	////�������ֻ��ӿ�

	/// Description: ����-�ֻ���������Ӧ��	
	virtual void OnRspSecuDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����ȡ��-�ֻ���������Ӧ��
	virtual void OnRspSecuDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-�ֻ���������
	///Others     :Bid1Volume��һ��������, Bid1Count��һ�����������, MaxBid1Count��һ��ί�б���
	///           :Ask1Volume��һ��������, Ask1Count��һ�����������, MaxAsk1Count��һ��ί�б���
	virtual void OnRtnSecuDepthMarketData(CHSNsqSecuDepthMarketDataField *pSecuDepthMarketData, HSIntVolume Bid1Volume[], HSNum Bid1Count, HSNum MaxBid1Count, HSIntVolume Ask1Volume[], HSNum Ask1Count, HSNum MaxAsk1Count);


	/// Description: ����-�ֻ��̺󶨼ۿ�������
	///Others     :Bid1Volume��һ��������, Bid1Count��һ�����������, MaxBid1Count��һ��ί�б���
	///           :Ask1Volume��һ��������, Ask1Count��һ�����������, MaxAsk1Count��һ��ί�б���
	virtual void OnRtnSecuATPMarketData(CHSNsqSecuATPMarketDataField *pSecuDepthMarketData, HSIntVolume Bid1Volume[], HSNum Bid1Count, HSNum MaxBid1Count, HSIntVolume Ask1Volume[], HSNum Ask1Count, HSNum MaxAsk1Count);


	/// Description: ����-�ֻ��������Ӧ��
	virtual void OnRspSecuTransactionSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����ȡ��-�ֻ��������Ӧ��
	virtual void OnRspSecuTransactionCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-�ֻ���ʳɽ�����
	virtual void OnRtnSecuTransactionTradeData(CHSNsqSecuTransactionTradeDataField *pSecuTransactionTradeData);

	/// Description: ����-�ֻ����ί������
	virtual void OnRtnSecuTransactionEntrustData(CHSNsqSecuTransactionEntrustDataField *pSecuTransactionEntrustData);


	/// Description: ����-�ֻ��̺�̶���ʳɽ�����
	virtual void OnRtnSecuATPTransactionTradeData(CHSNsqSecuTransactionTradeDataField *pSecuTransactionTradeData);

	/// Description: ����-��֤��ծȯ��ʳɽ�����
	virtual void OnRtnBondTransactionTradeData(CHSNsqBondTransactionTradeDataField* pSecuTransactionTradeData);

	/// Description: ����-��֤��ծȯ���ί������
	virtual void OnRtnBondTransactionEntrustData(CHSNsqBondTransactionEntrustDataField* pSecuTransactionEntrustData);


	/// Description: ��ȡ��ǰ�������ֻ���ԼӦ��
	virtual void OnRspQrySecuInstruments(CHSNsqSecuInstrumentStaticInfoField *pSecuInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ��ȡ�ֻ���Լ�����¿�����ϢӦ��
	virtual void OnRspQrySecuDepthMarketData(CHSNsqSecuDepthMarketDataField *pSecuDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);


	////��������Ȩ�ӿ�

	/// Description: ��Ȩ����-����Ӧ��
	virtual void OnRspOptDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ��Ȩ����ȡ��-����Ӧ��
	virtual void OnRspOptDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-��Ȩ����
	virtual void OnRtnOptDepthMarketData(CHSNsqOptDepthMarketDataField *pOptDepthMarketData);

	/// Description: ��ȡ��ǰ�����պ�ԼӦ��
	virtual void OnRspQryOptInstruments(CHSNsqOptInstrumentStaticInfoField *pOptInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ��ȡ��Լ�����¿�����ϢӦ��
	virtual void OnRspQryOptDepthMarketData(CHSNsqOptDepthMarketDataField *pOptDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	////�������ֻ�����Plus�ӿ�

	/// Description: ����-�ֻ�����Plus����Ӧ��	
	virtual void OnRspSecuDepthMarketDataPlusSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����ȡ��-�ֻ�����Plus����Ӧ��
	virtual void OnRspSecuDepthMarketDataPlusCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-�ֻ�����Plus����
	virtual void OnRtnSecuDepthMarketDataPlus(CHSNsqSecuDepthMarketDataPlusField *pSecuDepthMarketDataPlus);

	/// Description: ����-�ֻ�����Plus����ֹ֪ͣͨ
	///Others     :��������Plus�������ֽ������·���ĳ��ͨ����������ݴ��ڶ���ʱ��������Plus����������з���Զ�ʧ������ݵ��ؽ���
	///           ���ؽ����֮ǰ��������Plus����������������;���ͨ����ֹ֪ͣͨ���Ӷ��������ص���
	///           ���ؽ���ɺ󣬾���ͨ����ֹ֪ͣͨ��ֹͣ���ͣ�ͬʱ������Plus����������������Ӧͨ���ؽ������Ŀ���
	virtual void OnRtnSecuDepthMarketDataPlusStopNotice(CHSNsqSecuDepthMarketDataPlusStopNoticeField *pSecuDepthMarketDataPlusStopNotice);

	////�������ֻ�����ؽ��ӿ�

	/// Description: �ؽ�Ӧ��-�ֻ��������
	virtual void OnRspSecuTransactionData(CHSNsqSecuTransactionDataField *pSecuTransactionData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: �ؽ�Ӧ��ʱ-�ֻ�������ݣ����ص��߳��������ص��̲߳�ͬ��
	virtual void OnRspSecuTransactionDataTimeout(int nRequestID);


	////�����Ǹ۹�ͨ�ӿ�

	/// Description: ��ȡ��ǰ�����պ�ԼӦ��
	virtual void OnRspQryHktInstruments(CHSNsqHktInstrumentStaticInfoField *pHktInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

	/// Description: ����-�۹�ͨ����
	virtual void OnRtnHktDepthMarketData(CHSNsqHktDepthMarketDataField *pHktDepthMarketData);

	//-------------------------------------------------------------------------------------
	//task������
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
	//data���ص������������ֵ�
	//error���ص������Ĵ����ֵ�
	//id������id
	//last���Ƿ�Ϊ��󷵻�
	//i������
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
	//req:���������������ֵ�
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
