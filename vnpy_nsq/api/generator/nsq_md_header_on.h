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

virtual void onRtnSecuDepthMarketData(const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data) {};

virtual void onRtnSecuATPMarketData(const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data, const dict &data) {};

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

