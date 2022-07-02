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

void onRtnSecuDepthMarketData(const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRtnSecuDepthMarketData, data, data, data, data, data, data, data);
	}
	catch (const error_already_set &e)
	{
		cout << e.what() << endl;
	}
};

void onRtnSecuATPMarketData(const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data) override
{
	try
	{
		PYBIND11_OVERLOAD(void, MdApi, onRtnSecuATPMarketData, data, data, data, data, data, data, data);
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

