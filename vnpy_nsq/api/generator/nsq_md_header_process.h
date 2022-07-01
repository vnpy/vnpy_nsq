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

