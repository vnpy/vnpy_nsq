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

