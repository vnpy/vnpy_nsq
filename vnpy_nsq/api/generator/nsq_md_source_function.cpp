int MdApi::reqUserLogin(const dict &req, int count, int reqid)
{
	CHSNsqReqUserLoginField myreq = CHSNsqReqUserLoginField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "AccountID", myreq.AccountID);
	getString(req, "Password", myreq.Password);
	getChar(req, "UserApplicationType", &myreq.UserApplicationType);
	getString(req, "UserApplicationInfo", myreq.UserApplicationInfo);
	getString(req, "MacAddress", myreq.MacAddress);
	getString(req, "IPAddress", myreq.IPAddress);
	int i = this->api->ReqUserLogin(&myreq, count, reqid);
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
	int i = this->api->ReqSecuTransactionSubscribe((char)type, &myreq, count, reqid);
	return i;
};

int MdApi::reqSecuTransactionCancel(string type, const dict &req, int count, int reqid)
{
	CHSNsqReqSecuDepthMarketDataField myreq = CHSNsqReqSecuDepthMarketDataField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getString(req, "InstrumentID", myreq.InstrumentID);
	int i = this->api->ReqSecuTransactionCancel((char)type, &myreq, count, reqid);
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

int MdApi::reqSecuTransactionRebuild(const dict &req, int count, int reqid)
{
	CHSNsqReqSecuTransactionRebuildField myreq = CHSNsqReqSecuTransactionRebuildField();
	memset(&myreq, 0, sizeof(myreq));
	getString(req, "ExchangeID", myreq.ExchangeID);
	getInt(req, "ChannelNo", &myreq.ChannelNo);
	getInt(req, "BeginSeqNo", &myreq.BeginSeqNo);
	getInt(req, "EndSeqNo", &myreq.EndSeqNo);
	getChar(req, "RebuildType", &myreq.RebuildType);
	int i = this->api->ReqSecuTransactionRebuild(&myreq, count, reqid);
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

