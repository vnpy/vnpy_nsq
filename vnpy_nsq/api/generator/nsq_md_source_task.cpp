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
	if (Bid1Volume[])
	{
		HSIntVolume *task_data = new HSIntVolume();
		*task_data = *Bid1Volume[];
		task.task_data = task_data;
	}
	if (Bid1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *Bid1Count;
		task.task_data = task_data;
	}
	if (MaxBid1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *MaxBid1Count;
		task.task_data = task_data;
	}
	if (Ask1Volume[])
	{
		HSIntVolume *task_data = new HSIntVolume();
		*task_data = *Ask1Volume[];
		task.task_data = task_data;
	}
	if (Ask1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *Ask1Count;
		task.task_data = task_data;
	}
	if (MaxAsk1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *MaxAsk1Count;
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
	if (Bid1Volume[])
	{
		HSIntVolume *task_data = new HSIntVolume();
		*task_data = *Bid1Volume[];
		task.task_data = task_data;
	}
	if (Bid1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *Bid1Count;
		task.task_data = task_data;
	}
	if (MaxBid1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *MaxBid1Count;
		task.task_data = task_data;
	}
	if (Ask1Volume[])
	{
		HSIntVolume *task_data = new HSIntVolume();
		*task_data = *Ask1Volume[];
		task.task_data = task_data;
	}
	if (Ask1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *Ask1Count;
		task.task_data = task_data;
	}
	if (MaxAsk1Count)
	{
		HSNum *task_data = new HSNum();
		*task_data = *MaxAsk1Count;
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

