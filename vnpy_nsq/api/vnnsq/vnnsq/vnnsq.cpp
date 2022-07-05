// vnnsq.cpp : 定义 DLL 应用程序的导出函数。
//

#include "vnnsq.h"


///-------------------------------------------------------------------------------------
///C++的回调函数将数据保存到队列中
///-------------------------------------------------------------------------------------

void MdApi::OnFrontConnected()
{
	Task task = Task();
	task.task_name = ONFRONTCONNECTED;
	this->task_queue.push(task);
};

void MdApi::OnFrontDisconnected(int nResult)
{
	Task task = Task();
	task.task_name = ONFRONTDISCONNECTED;
	task.task_id = nResult;
	this->task_queue.push(task);
};

void MdApi::OnRspUserLogin(CHSNsqRspUserLoginField *pRspUserLogin, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPUSERLOGIN;
	if (pRspUserLogin)
	{
		CHSNsqRspUserLoginField *task_data = new CHSNsqRspUserLoginField();
		*task_data = *pRspUserLogin;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspFutuDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFUTUDEPTHMARKETDATASUBSCRIBE;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspFutuDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPFUTUDEPTHMARKETDATACANCEL;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnFutuDepthMarketData(CHSNsqFutuDepthMarketDataField *pFutuDepthMarketData)
{
	Task task = Task();
	task.task_name = ONRTNFUTUDEPTHMARKETDATA;
	if (pFutuDepthMarketData)
	{
		CHSNsqFutuDepthMarketDataField *task_data = new CHSNsqFutuDepthMarketDataField();
		*task_data = *pFutuDepthMarketData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspQryFutuInstruments(CHSNsqFutuInstrumentStaticInfoField *pFutuInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUTUINSTRUMENTS;
	if (pFutuInstrumentStaticInfo)
	{
		CHSNsqFutuInstrumentStaticInfoField *task_data = new CHSNsqFutuInstrumentStaticInfoField();
		*task_data = *pFutuInstrumentStaticInfo;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspQryFutuDepthMarketData(CHSNsqFutuDepthMarketDataField *pFutuDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYFUTUDEPTHMARKETDATA;
	if (pFutuDepthMarketData)
	{
		CHSNsqFutuDepthMarketDataField *task_data = new CHSNsqFutuDepthMarketDataField();
		*task_data = *pFutuDepthMarketData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspSecuDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSECUDEPTHMARKETDATASUBSCRIBE;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspSecuDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSECUDEPTHMARKETDATACANCEL;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnSecuDepthMarketData(CHSNsqSecuDepthMarketDataField *pSecuDepthMarketData, HSIntVolume Bid1Volume[], HSNum Bid1Count, HSNum MaxBid1Count, HSIntVolume Ask1Volume[], HSNum Ask1Count, HSNum MaxAsk1Count)
{
	Task task = Task();
	task.task_name = ONRTNSECUDEPTHMARKETDATA;
	if (pSecuDepthMarketData)
	{
		CHSNsqSecuDepthMarketDataField *task_data = new CHSNsqSecuDepthMarketDataField();
		*task_data = *pSecuDepthMarketData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSecuATPMarketData(CHSNsqSecuATPMarketDataField *pSecuDepthMarketData, HSIntVolume Bid1Volume[], HSNum Bid1Count, HSNum MaxBid1Count, HSIntVolume Ask1Volume[], HSNum Ask1Count, HSNum MaxAsk1Count)
{
	Task task = Task();
	task.task_name = ONRTNSECUATPMARKETDATA;
	if (pSecuDepthMarketData)
	{
		CHSNsqSecuATPMarketDataField *task_data = new CHSNsqSecuATPMarketDataField();
		*task_data = *pSecuDepthMarketData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSecuTransactionSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSECUTRANSACTIONSUBSCRIBE;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspSecuTransactionCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSECUTRANSACTIONCANCEL;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnSecuTransactionTradeData(CHSNsqSecuTransactionTradeDataField *pSecuTransactionTradeData)
{
	Task task = Task();
	task.task_name = ONRTNSECUTRANSACTIONTRADEDATA;
	if (pSecuTransactionTradeData)
	{
		CHSNsqSecuTransactionTradeDataField *task_data = new CHSNsqSecuTransactionTradeDataField();
		*task_data = *pSecuTransactionTradeData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSecuTransactionEntrustData(CHSNsqSecuTransactionEntrustDataField *pSecuTransactionEntrustData)
{
	Task task = Task();
	task.task_name = ONRTNSECUTRANSACTIONENTRUSTDATA;
	if (pSecuTransactionEntrustData)
	{
		CHSNsqSecuTransactionEntrustDataField *task_data = new CHSNsqSecuTransactionEntrustDataField();
		*task_data = *pSecuTransactionEntrustData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSecuATPTransactionTradeData(CHSNsqSecuTransactionTradeDataField *pSecuTransactionTradeData)
{
	Task task = Task();
	task.task_name = ONRTNSECUATPTRANSACTIONTRADEDATA;
	if (pSecuTransactionTradeData)
	{
		CHSNsqSecuTransactionTradeDataField *task_data = new CHSNsqSecuTransactionTradeDataField();
		*task_data = *pSecuTransactionTradeData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnBondTransactionTradeData(CHSNsqBondTransactionTradeDataField* pSecuTransactionTradeData)
{
	Task task = Task();
	task.task_name = ONRTNBONDTRANSACTIONTRADEDATA;
	if (pSecuTransactionTradeData)
	{
		CHSNsqBondTransactionTradeDataField *task_data = new CHSNsqBondTransactionTradeDataField();
		*task_data = *pSecuTransactionTradeData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnBondTransactionEntrustData(CHSNsqBondTransactionEntrustDataField* pSecuTransactionEntrustData)
{
	Task task = Task();
	task.task_name = ONRTNBONDTRANSACTIONENTRUSTDATA;
	if (pSecuTransactionEntrustData)
	{
		CHSNsqBondTransactionEntrustDataField *task_data = new CHSNsqBondTransactionEntrustDataField();
		*task_data = *pSecuTransactionEntrustData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspQrySecuInstruments(CHSNsqSecuInstrumentStaticInfoField *pSecuInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSECUINSTRUMENTS;
	if (pSecuInstrumentStaticInfo)
	{
		CHSNsqSecuInstrumentStaticInfoField *task_data = new CHSNsqSecuInstrumentStaticInfoField();
		*task_data = *pSecuInstrumentStaticInfo;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspQrySecuDepthMarketData(CHSNsqSecuDepthMarketDataField *pSecuDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYSECUDEPTHMARKETDATA;
	if (pSecuDepthMarketData)
	{
		CHSNsqSecuDepthMarketDataField *task_data = new CHSNsqSecuDepthMarketDataField();
		*task_data = *pSecuDepthMarketData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspOptDepthMarketDataSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPOPTDEPTHMARKETDATASUBSCRIBE;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspOptDepthMarketDataCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPOPTDEPTHMARKETDATACANCEL;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnOptDepthMarketData(CHSNsqOptDepthMarketDataField *pOptDepthMarketData)
{
	Task task = Task();
	task.task_name = ONRTNOPTDEPTHMARKETDATA;
	if (pOptDepthMarketData)
	{
		CHSNsqOptDepthMarketDataField *task_data = new CHSNsqOptDepthMarketDataField();
		*task_data = *pOptDepthMarketData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspQryOptInstruments(CHSNsqOptInstrumentStaticInfoField *pOptInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTINSTRUMENTS;
	if (pOptInstrumentStaticInfo)
	{
		CHSNsqOptInstrumentStaticInfoField *task_data = new CHSNsqOptInstrumentStaticInfoField();
		*task_data = *pOptInstrumentStaticInfo;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspQryOptDepthMarketData(CHSNsqOptDepthMarketDataField *pOptDepthMarketData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYOPTDEPTHMARKETDATA;
	if (pOptDepthMarketData)
	{
		CHSNsqOptDepthMarketDataField *task_data = new CHSNsqOptDepthMarketDataField();
		*task_data = *pOptDepthMarketData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspSecuDepthMarketDataPlusSubscribe(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSECUDEPTHMARKETDATAPLUSSUBSCRIBE;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspSecuDepthMarketDataPlusCancel(CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSECUDEPTHMARKETDATAPLUSCANCEL;
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnSecuDepthMarketDataPlus(CHSNsqSecuDepthMarketDataPlusField *pSecuDepthMarketDataPlus)
{
	Task task = Task();
	task.task_name = ONRTNSECUDEPTHMARKETDATAPLUS;
	if (pSecuDepthMarketDataPlus)
	{
		CHSNsqSecuDepthMarketDataPlusField *task_data = new CHSNsqSecuDepthMarketDataPlusField();
		*task_data = *pSecuDepthMarketDataPlus;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRtnSecuDepthMarketDataPlusStopNotice(CHSNsqSecuDepthMarketDataPlusStopNoticeField *pSecuDepthMarketDataPlusStopNotice)
{
	Task task = Task();
	task.task_name = ONRTNSECUDEPTHMARKETDATAPLUSSTOPNOTICE;
	if (pSecuDepthMarketDataPlusStopNotice)
	{
		CHSNsqSecuDepthMarketDataPlusStopNoticeField *task_data = new CHSNsqSecuDepthMarketDataPlusStopNoticeField();
		*task_data = *pSecuDepthMarketDataPlusStopNotice;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

void MdApi::OnRspSecuTransactionData(CHSNsqSecuTransactionDataField *pSecuTransactionData, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPSECUTRANSACTIONDATA;
	if (pSecuTransactionData)
	{
		CHSNsqSecuTransactionDataField *task_data = new CHSNsqSecuTransactionDataField();
		*task_data = *pSecuTransactionData;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRspSecuTransactionDataTimeout(int nRequestID)
{
	Task task = Task();
	task.task_name = ONRSPSECUTRANSACTIONDATATIMEOUT;
	task.task_id = nRequestID;
	this->task_queue.push(task);
};

void MdApi::OnRspQryHktInstruments(CHSNsqHktInstrumentStaticInfoField *pHktInstrumentStaticInfo, CHSNsqRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	Task task = Task();
	task.task_name = ONRSPQRYHKTINSTRUMENTS;
	if (pHktInstrumentStaticInfo)
	{
		CHSNsqHktInstrumentStaticInfoField *task_data = new CHSNsqHktInstrumentStaticInfoField();
		*task_data = *pHktInstrumentStaticInfo;
		task.task_data = task_data;
	}
	if (pRspInfo)
	{
		CHSNsqRspInfoField *task_error = new CHSNsqRspInfoField();
		*task_error = *pRspInfo;
		task.task_error = task_error;
	}
	task.task_id = nRequestID;
	task.task_last = bIsLast;
	this->task_queue.push(task);
};

void MdApi::OnRtnHktDepthMarketData(CHSNsqHktDepthMarketDataField *pHktDepthMarketData)
{
	Task task = Task();
	task.task_name = ONRTNHKTDEPTHMARKETDATA;
	if (pHktDepthMarketData)
	{
		CHSNsqHktDepthMarketDataField *task_data = new CHSNsqHktDepthMarketDataField();
		*task_data = *pHktDepthMarketData;
		task.task_data = task_data;
	}
	this->task_queue.push(task);
};

///-------------------------------------------------------------------------------------
///工作线程从队列中取出数据，转化为python对象后，进行推送
///-------------------------------------------------------------------------------------


void MdApi::processTask()
{
	try
	{
		while (this->active)
		{
			Task task = this->task_queue.pop();

			switch (task.task_name)
			{
			case ONFRONTCONNECTED:
			{
				this->processFrontConnected(&task);
				break;
			}

			case ONFRONTDISCONNECTED:
			{
				this->processFrontDisconnected(&task);
				break;
			}

			case ONRSPUSERLOGIN:
			{
				this->processRspUserLogin(&task);
				break;
			}

			case ONRSPFUTUDEPTHMARKETDATASUBSCRIBE:
			{
				this->processRspFutuDepthMarketDataSubscribe(&task);
				break;
			}

			case ONRSPFUTUDEPTHMARKETDATACANCEL:
			{
				this->processRspFutuDepthMarketDataCancel(&task);
				break;
			}

			case ONRTNFUTUDEPTHMARKETDATA:
			{
				this->processRtnFutuDepthMarketData(&task);
				break;
			}

			case ONRSPQRYFUTUINSTRUMENTS:
			{
				this->processRspQryFutuInstruments(&task);
				break;
			}

			case ONRSPQRYFUTUDEPTHMARKETDATA:
			{
				this->processRspQryFutuDepthMarketData(&task);
				break;
			}

			case ONRSPSECUDEPTHMARKETDATASUBSCRIBE:
			{
				this->processRspSecuDepthMarketDataSubscribe(&task);
				break;
			}

			case ONRSPSECUDEPTHMARKETDATACANCEL:
			{
				this->processRspSecuDepthMarketDataCancel(&task);
				break;
			}

			case ONRTNSECUDEPTHMARKETDATA:
			{
				this->processRtnSecuDepthMarketData(&task);
				break;
			}

			case ONRTNSECUATPMARKETDATA:
			{
				this->processRtnSecuATPMarketData(&task);
				break;
			}

			case ONRSPSECUTRANSACTIONSUBSCRIBE:
			{
				this->processRspSecuTransactionSubscribe(&task);
				break;
			}

			case ONRSPSECUTRANSACTIONCANCEL:
			{
				this->processRspSecuTransactionCancel(&task);
				break;
			}

			case ONRTNSECUTRANSACTIONTRADEDATA:
			{
				this->processRtnSecuTransactionTradeData(&task);
				break;
			}

			case ONRTNSECUTRANSACTIONENTRUSTDATA:
			{
				this->processRtnSecuTransactionEntrustData(&task);
				break;
			}

			case ONRTNSECUATPTRANSACTIONTRADEDATA:
			{
				this->processRtnSecuATPTransactionTradeData(&task);
				break;
			}

			case ONRTNBONDTRANSACTIONTRADEDATA:
			{
				this->processRtnBondTransactionTradeData(&task);
				break;
			}

			case ONRTNBONDTRANSACTIONENTRUSTDATA:
			{
				this->processRtnBondTransactionEntrustData(&task);
				break;
			}

			case ONRSPQRYSECUINSTRUMENTS:
			{
				this->processRspQrySecuInstruments(&task);
				break;
			}

			case ONRSPQRYSECUDEPTHMARKETDATA:
			{
				this->processRspQrySecuDepthMarketData(&task);
				break;
			}

			case ONRSPOPTDEPTHMARKETDATASUBSCRIBE:
			{
				this->processRspOptDepthMarketDataSubscribe(&task);
				break;
			}

			case ONRSPOPTDEPTHMARKETDATACANCEL:
			{
				this->processRspOptDepthMarketDataCancel(&task);
				break;
			}

			case ONRTNOPTDEPTHMARKETDATA:
			{
				this->processRtnOptDepthMarketData(&task);
				break;
			}

			case ONRSPQRYOPTINSTRUMENTS:
			{
				this->processRspQryOptInstruments(&task);
				break;
			}

			case ONRSPQRYOPTDEPTHMARKETDATA:
			{
				this->processRspQryOptDepthMarketData(&task);
				break;
			}

			case ONRSPSECUDEPTHMARKETDATAPLUSSUBSCRIBE:
			{
				this->processRspSecuDepthMarketDataPlusSubscribe(&task);
				break;
			}

			case ONRSPSECUDEPTHMARKETDATAPLUSCANCEL:
			{
				this->processRspSecuDepthMarketDataPlusCancel(&task);
				break;
			}

			case ONRTNSECUDEPTHMARKETDATAPLUS:
			{
				this->processRtnSecuDepthMarketDataPlus(&task);
				break;
			}

			case ONRTNSECUDEPTHMARKETDATAPLUSSTOPNOTICE:
			{
				this->processRtnSecuDepthMarketDataPlusStopNotice(&task);
				break;
			}

			case ONRSPSECUTRANSACTIONDATA:
			{
				this->processRspSecuTransactionData(&task);
				break;
			}

			case ONRSPSECUTRANSACTIONDATATIMEOUT:
			{
				this->processRspSecuTransactionDataTimeout(&task);
				break;
			}

			case ONRSPQRYHKTINSTRUMENTS:
			{
				this->processRspQryHktInstruments(&task);
				break;
			}

			case ONRTNHKTDEPTHMARKETDATA:
			{
				this->processRtnHktDepthMarketData(&task);
				break;
			}
			};
		}
	}
	catch (const TerminatedError&)
	{
	}
};

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
		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 5; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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
		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 5; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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
		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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
	this->onRtnSecuDepthMarketData(data);
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
	this->onRtnSecuATPMarketData(data);
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

		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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

		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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

		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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

		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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

		pybind11::list ask;
		pybind11::list ask_qty;
		pybind11::list bid;
		pybind11::list bid_qty;

		for (int i = 0; i < 10; i++)
		{
			ask.append(task_data->AskPrice[i]);
			ask_qty.append(task_data->AskVolume[i]);
			bid.append(task_data->BidPrice[i]);
			bid_qty.append(task_data->BidVolume[i]);
		}
		data["ask"] = ask;
		data["bid"] = bid;
		data["bid_qty"] = bid_qty;
		data["ask_qty"] = ask_qty;

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

///-------------------------------------------------------------------------------------
///主动函数
///-------------------------------------------------------------------------------------

void MdApi::newNsqApi(string pszFlowPath)
{
	this->api = NewNsqApi(pszFlowPath.c_str());
	this->api->RegisterSpi(this);
};

void MdApi::newNsqApiExt(string pszFlowPath, string sdkCfgFilePath)
{
	this->api = NewNsqApiExt(pszFlowPath.c_str(), sdkCfgFilePath.c_str());
	this->api->RegisterSpi(this);
};

void MdApi::release()
{
	this->api->ReleaseApi();
};

int MdApi::init(string licFile)
{
	this->active = true;
	this->task_thread = thread(&MdApi::processTask, this);

	int i = this->api->Init(licFile.c_str());
	return i;

};
int MdApi::join()
{
	int i = this->api->Join();
	return i;
};

int MdApi::exit()
{
	this->active = false;
	this->task_queue.terminate();
	this->task_thread.join();

	this->api->RegisterSpi(NULL);
	this->api->ReleaseApi();
	this->api = NULL;
	return 1;
};

string MdApi::getApiErrorMsg(int errorCode)
{
	string i = this->api->GetApiErrorMsg(errorCode);
	return toUtf(i);

};

int MdApi::registerFront(string pszFrontAddress)
{
	int i = this->api->RegisterFront(pszFrontAddress.c_str());
	return i;
};

int MdApi::registerFensServer(string pszFensAddress, string pszAccountID)
{
	int i = this->api->RegisterFensServer(pszFensAddress.c_str(), pszAccountID.c_str());
	return i;
};

int MdApi::reqUserLogin(const dict &req, int reqid)
{
	CHSNsqReqUserLoginField myreq = CHSNsqReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "Password", myreq.Password);
	getChar(req, "UserApplicationType", &myreq.UserApplicationType);
	getString(req, "UserApplicationInfo", myreq.UserApplicationInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqUserLogin(&myreq, reqid);
	return i;
};

int MdApi::reqFutuDepthMarketDataSubscribe(const dict &req, int count, int reqid)
{
	CHSNsqReqFutuDepthMarketDataField myreq = CHSNsqReqFutuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqFutuDepthMarketDataSubscribe(&myreq, count, reqid);
	return i;
};

int MdApi::reqFutuDepthMarketDataCancel(const dict &req, int count, int reqid)
{
	CHSNsqReqFutuDepthMarketDataField myreq = CHSNsqReqFutuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqFutuDepthMarketDataCancel(&myreq, count, reqid);
	return i;
};

int MdApi::reqQryFutuInstruments(const dict &req, int count, int reqid)
{
	CHSNsqReqFutuDepthMarketDataField myreq = CHSNsqReqFutuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryFutuInstruments(&myreq, count, reqid);
	return i;
};

int MdApi::reqQryFutuDepthMarketData(const dict &req, int count, int reqid)
{
	CHSNsqReqFutuDepthMarketDataField myreq = CHSNsqReqFutuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryFutuDepthMarketData(&myreq, count, reqid);
	return i;
};

int MdApi::reqSecuDepthMarketDataSubscribe(const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSecuDepthMarketDataSubscribe(&myreq, count, reqid);
	return i;
};

int MdApi::reqSecuDepthMarketDataCancel(const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSecuDepthMarketDataCancel(&myreq, count, reqid);
	return i;
};

int MdApi::reqSecuTransactionSubscribe(string type, const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSecuTransactionSubscribe((char)type.c_str(), &myreq, count, reqid);
	return i;
};

int MdApi::reqSecuTransactionCancel(string type, const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSecuTransactionCancel((char)type.c_str(), &myreq, count, reqid);
	return i;
};

int MdApi::reqQrySecuInstruments(const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQrySecuInstruments(&myreq, count, reqid);
	return i;
};

int MdApi::reqQrySecuDepthMarketData(const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQrySecuDepthMarketData(&myreq, count, reqid);
	return i;
};

int MdApi::reqOptDepthMarketDataSubscribe(const dict &req, int count, int reqid)
{
	CHSNsqReqOptDepthMarketDataField myreq = CHSNsqReqOptDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqOptDepthMarketDataSubscribe(&myreq, count, reqid);
	return i;
};

int MdApi::reqOptDepthMarketDataCancel(const dict &req, int count, int reqid)
{
	CHSNsqReqOptDepthMarketDataField myreq = CHSNsqReqOptDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqOptDepthMarketDataCancel(&myreq, count, reqid);
	return i;
};

int MdApi::reqQryOptInstruments(const dict &req, int count, int reqid)
{
	CHSNsqReqOptDepthMarketDataField myreq = CHSNsqReqOptDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptInstruments(&myreq, count, reqid);
	return i;
};

int MdApi::reqQryOptDepthMarketData(const dict &req, int count, int reqid)
{
	CHSNsqReqOptDepthMarketDataField myreq = CHSNsqReqOptDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryOptDepthMarketData(&myreq, count, reqid);
	return i;
};

int MdApi::reqSecuDepthMarketDataPlusSubscribe(const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSecuDepthMarketDataPlusSubscribe(&myreq, count, reqid);
	return i;
};

int MdApi::reqSecuDepthMarketDataPlusCancel(const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSecuDepthMarketDataPlusCancel(&myreq, count, reqid);
	return i;
};

int MdApi::reqSecuTransactionRebuild(const dict &req, int reqid)
{
	CHSNsqReqSecuTransactionRebuildField myreq = CHSNsqReqSecuTransactionRebuildField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getInt(req, "ChannelNo", &myreq.ChannelNo);
	getLonglong(req, "BeginSeqNo", &myreq.BeginSeqNo);
	getLonglong(req, "EndSeqNo", &myreq.EndSeqNo);
	getChar(req, "RebuildType", &myreq.RebuildType);
	int i = this->api->ReqSecuTransactionRebuild(&myreq, reqid);
	return i;
};

int MdApi::reqQryHktInstruments(const dict &req, int count, int reqid)
{
	CHSNsqReqHktDepthMarketDataField myreq = CHSNsqReqHktDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqQryHktInstruments(&myreq, count, reqid);
	return i;
};

///-------------------------------------------------------------------------------------
///Boost.Python封装
///-------------------------------------------------------------------------------------

class PyMdApi : public MdApi
{
public:
	using MdApi::MdApi;

	void onFrontConnected() override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onFrontConnected);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onFrontDisconnected(int result) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onFrontDisconnected, result);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspUserLogin(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspUserLogin, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFutuDepthMarketDataSubscribe(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspFutuDepthMarketDataSubscribe, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspFutuDepthMarketDataCancel(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspFutuDepthMarketDataCancel, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnFutuDepthMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnFutuDepthMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFutuInstruments(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspQryFutuInstruments, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryFutuDepthMarketData(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspQryFutuDepthMarketData, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuDepthMarketDataSubscribe(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuDepthMarketDataSubscribe, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuDepthMarketDataCancel(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuDepthMarketDataCancel, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecuDepthMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecuDepthMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecuATPMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecuATPMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuTransactionSubscribe(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuTransactionSubscribe, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuTransactionCancel(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuTransactionCancel, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecuTransactionTradeData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecuTransactionTradeData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecuTransactionEntrustData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecuTransactionEntrustData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecuATPTransactionTradeData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecuATPTransactionTradeData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnBondTransactionTradeData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnBondTransactionTradeData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnBondTransactionEntrustData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnBondTransactionEntrustData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySecuInstruments(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspQrySecuInstruments, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQrySecuDepthMarketData(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspQrySecuDepthMarketData, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOptDepthMarketDataSubscribe(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspOptDepthMarketDataSubscribe, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspOptDepthMarketDataCancel(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspOptDepthMarketDataCancel, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnOptDepthMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnOptDepthMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOptInstruments(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspQryOptInstruments, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryOptDepthMarketData(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspQryOptDepthMarketData, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuDepthMarketDataPlusSubscribe(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuDepthMarketDataPlusSubscribe, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuDepthMarketDataPlusCancel(const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuDepthMarketDataPlusCancel, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecuDepthMarketDataPlus(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecuDepthMarketDataPlus, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnSecuDepthMarketDataPlusStopNotice(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnSecuDepthMarketDataPlusStopNotice, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuTransactionData(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuTransactionData, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspSecuTransactionDataTimeout(int requestid) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspSecuTransactionDataTimeout, requestid);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRspQryHktInstruments(const dict &data, const dict &error, int requestid, bool islast) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRspQryHktInstruments, data, error, requestid, islast);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};

	void onRtnHktDepthMarketData(const dict &data) override
	{
		try
		{
			PYBIND11_OVERLOAD(void, MdApi, onRtnHktDepthMarketData, data);
		}
		catch (const error_already_set &e)
		{
			cout << e.what() << endl;
		}
	};
};


PYBIND11_MODULE(vnnsq, m)
{
	class_<MdApi, PyMdApi> MdApi(m, "MdApi", module_local());
	MdApi
		.def(init<>())
		.def("newNsqApi", &MdApi::newNsqApi)
		.def("newNsqApiExt", &MdApi::newNsqApiExt)
		.def("release", &MdApi::release)
		.def("init", &MdApi::init)
		.def("join", &MdApi::join)
		.def("exit", &MdApi::exit)
		.def("getApiErrorMsg", &MdApi::getApiErrorMsg)
		.def("registerFront", &MdApi::registerFront)
		.def("registerFensServer", &MdApi::registerFensServer)
		.def("reqUserLogin", &MdApi::reqUserLogin)
		.def("reqFutuDepthMarketDataSubscribe", &MdApi::reqFutuDepthMarketDataSubscribe)
		.def("reqFutuDepthMarketDataCancel", &MdApi::reqFutuDepthMarketDataCancel)
		.def("reqQryFutuInstruments", &MdApi::reqQryFutuInstruments)
		.def("reqQryFutuDepthMarketData", &MdApi::reqQryFutuDepthMarketData)
		.def("reqSecuDepthMarketDataSubscribe", &MdApi::reqSecuDepthMarketDataSubscribe)
		.def("reqSecuDepthMarketDataCancel", &MdApi::reqSecuDepthMarketDataCancel)
		.def("reqSecuTransactionSubscribe", &MdApi::reqSecuTransactionSubscribe)
		.def("reqSecuTransactionCancel", &MdApi::reqSecuTransactionCancel)
		.def("reqQrySecuInstruments", &MdApi::reqQrySecuInstruments)
		.def("reqQrySecuDepthMarketData", &MdApi::reqQrySecuDepthMarketData)
		.def("reqOptDepthMarketDataSubscribe", &MdApi::reqOptDepthMarketDataSubscribe)
		.def("reqOptDepthMarketDataCancel", &MdApi::reqOptDepthMarketDataCancel)
		.def("reqQryOptInstruments", &MdApi::reqQryOptInstruments)
		.def("reqQryOptDepthMarketData", &MdApi::reqQryOptDepthMarketData)
		.def("reqSecuDepthMarketDataPlusSubscribe", &MdApi::reqSecuDepthMarketDataPlusSubscribe)
		.def("reqSecuDepthMarketDataPlusCancel", &MdApi::reqSecuDepthMarketDataPlusCancel)
		.def("reqSecuTransactionRebuild", &MdApi::reqSecuTransactionRebuild)
		.def("reqQryHktInstruments", &MdApi::reqQryHktInstruments)

		.def("onFrontConnected", &MdApi::onFrontConnected)
		.def("onFrontDisconnected", &MdApi::onFrontDisconnected)
		.def("onRspUserLogin", &MdApi::onRspUserLogin)
		.def("onRspFutuDepthMarketDataSubscribe", &MdApi::onRspFutuDepthMarketDataSubscribe)
		.def("onRspFutuDepthMarketDataCancel", &MdApi::onRspFutuDepthMarketDataCancel)
		.def("onRtnFutuDepthMarketData", &MdApi::onRtnFutuDepthMarketData)
		.def("onRspQryFutuInstruments", &MdApi::onRspQryFutuInstruments)
		.def("onRspQryFutuDepthMarketData", &MdApi::onRspQryFutuDepthMarketData)
		.def("onRspSecuDepthMarketDataSubscribe", &MdApi::onRspSecuDepthMarketDataSubscribe)
		.def("onRspSecuDepthMarketDataCancel", &MdApi::onRspSecuDepthMarketDataCancel)
		.def("onRtnSecuDepthMarketData", &MdApi::onRtnSecuDepthMarketData)
		.def("onRtnSecuATPMarketData", &MdApi::onRtnSecuATPMarketData)
		.def("onRspSecuTransactionSubscribe", &MdApi::onRspSecuTransactionSubscribe)
		.def("onRspSecuTransactionCancel", &MdApi::onRspSecuTransactionCancel)
		.def("onRtnSecuTransactionTradeData", &MdApi::onRtnSecuTransactionTradeData)
		.def("onRtnSecuTransactionEntrustData", &MdApi::onRtnSecuTransactionEntrustData)
		.def("onRtnSecuATPTransactionTradeData", &MdApi::onRtnSecuATPTransactionTradeData)
		.def("onRtnBondTransactionTradeData", &MdApi::onRtnBondTransactionTradeData)
		.def("onRtnBondTransactionEntrustData", &MdApi::onRtnBondTransactionEntrustData)
		.def("onRspQrySecuInstruments", &MdApi::onRspQrySecuInstruments)
		.def("onRspQrySecuDepthMarketData", &MdApi::onRspQrySecuDepthMarketData)
		.def("onRspOptDepthMarketDataSubscribe", &MdApi::onRspOptDepthMarketDataSubscribe)
		.def("onRspOptDepthMarketDataCancel", &MdApi::onRspOptDepthMarketDataCancel)
		.def("onRtnOptDepthMarketData", &MdApi::onRtnOptDepthMarketData)
		.def("onRspQryOptInstruments", &MdApi::onRspQryOptInstruments)
		.def("onRspQryOptDepthMarketData", &MdApi::onRspQryOptDepthMarketData)
		.def("onRspSecuDepthMarketDataPlusSubscribe", &MdApi::onRspSecuDepthMarketDataPlusSubscribe)
		.def("onRspSecuDepthMarketDataPlusCancel", &MdApi::onRspSecuDepthMarketDataPlusCancel)
		.def("onRtnSecuDepthMarketDataPlus", &MdApi::onRtnSecuDepthMarketDataPlus)
		.def("onRtnSecuDepthMarketDataPlusStopNotice", &MdApi::onRtnSecuDepthMarketDataPlusStopNotice)
		.def("onRspSecuTransactionData", &MdApi::onRspSecuTransactionData)
		.def("onRspSecuTransactionDataTimeout", &MdApi::onRspSecuTransactionDataTimeout)
		.def("onRspQryHktInstruments", &MdApi::onRspQryHktInstruments)
		.def("onRtnHktDepthMarketData", &MdApi::onRtnHktDepthMarketData)
		;
}
