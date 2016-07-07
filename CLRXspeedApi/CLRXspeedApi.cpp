// 这是主 DLL 文件。

#include "stdafx.h"
#include "CLRXspeedApi.h"

namespace CLRXspeedApi
{
#pragma region CLRTraderApi
	void CLRDFITCTraderApi::Release(void)
	{
		m_pNativeApi->Release();
	}
	int CLRDFITCTraderApi::Init(String ^ FrontAddr, CLRDFITCTraderSpi ^ Spi)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(FrontAddr);
		char *pszFrontAddr = static_cast<char *>(p.ToPointer());
		return m_pNativeApi->Init(pszFrontAddr, Spi->m_pNativeSpi);
	}
	int CLRDFITCTraderApi::Join(void)
	{
		return m_pNativeApi->Join();
	}
	int CLRDFITCTraderApi::ReqUserLogin(CLRDFITCUserLoginField ^ UserLoginData)
	{
		DFITCUserLoginField *pUserLoginData = new DFITCUserLoginField;
		Marshal::StructureToPtr(UserLoginData, IntPtr(pUserLoginData), true);
		return m_pNativeApi->ReqUserLogin(pUserLoginData);
	}
	int CLRDFITCTraderApi::ReqUserLogout(CLRDFITCUserLogoutField ^ UserLogoutData)
	{
		DFITCUserLogoutField *pUserLogoutData = new DFITCUserLogoutField;
		Marshal::StructureToPtr(UserLogoutData, IntPtr(pUserLogoutData), true);
		return m_pNativeApi->ReqUserLogout(pUserLogoutData);
	}
	int CLRDFITCTraderApi::ReqCancelOrder(CLRDFITCCancelOrderField ^ CancelOrderData)
	{
		DFITCCancelOrderField *pCancelOrderData = new DFITCCancelOrderField;
		Marshal::StructureToPtr(CancelOrderData, IntPtr(pCancelOrderData), true);
		return m_pNativeApi->ReqCancelOrder(pCancelOrderData);
	}
	int CLRDFITCTraderApi::ReqQryPosition(CLRDFITCPositionField ^ PositionData)
	{
		DFITCPositionField *pPositionData = new DFITCPositionField;
		Marshal::StructureToPtr(PositionData, IntPtr(pPositionData), true);
		return m_pNativeApi->ReqQryPosition(pPositionData);
	}
	int CLRDFITCTraderApi::ReqQryExchangeInstrument(CLRDFITCExchangeInstrumentField ^ ExchangeInstrumentData)
	{
		DFITCExchangeInstrumentField *pExchangeInstrumentData = new DFITCExchangeInstrumentField;
		Marshal::StructureToPtr(ExchangeInstrumentData, IntPtr(pExchangeInstrumentData), true);
		return m_pNativeApi->ReqQryExchangeInstrument(pExchangeInstrumentData);
	}
	int CLRDFITCTraderApi::ReqQryArbitrageInstrument(CLRDFITCAbiInstrumentField ^ AbtriInstrumentData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryOrderInfo(CLRDFITCOrderField ^ OrderData)
	{
		DFITCOrderField *pOrderData = new DFITCOrderField;
		Marshal::StructureToPtr(OrderData, IntPtr(pOrderData), true);
		return m_pNativeApi->ReqQryOrderInfo(pOrderData);
	}
	int CLRDFITCTraderApi::ReqQryMatchInfo(CLRDFITCMatchField ^ MatchData)
	{
		DFITCMatchField *pMatchData = new DFITCMatchField;
		Marshal::StructureToPtr(MatchData, IntPtr(pMatchData), true);
		return m_pNativeApi->ReqQryMatchInfo(pMatchData);
	}
	int CLRDFITCTraderApi::ReqQrySpecifyInstrument(CLRDFITCSpecificInstrumentField ^ Instrument)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryPositionDetail(CLRDFITCPositionDetailField ^ PositionDetailData)
	{
		DFITCPositionDetailField *pPositionDetailData = new DFITCPositionDetailField;
		Marshal::StructureToPtr(PositionDetailData, IntPtr(pPositionDetailData), true);
		return m_pNativeApi->ReqQryPositionDetail(pPositionDetailData);
	}
	int CLRDFITCTraderApi::ReqConfirmProductInfo(CLRDFITCProductField ^ ConfirmProductData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqResetPassword(CLRDFITCResetPwdField ^ ResetPasswordData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqBillConfirm(CLRDFITCBillConfirmField ^ BillConfirmData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryTradeCode(CLRDFITCQryTradeCodeField ^ TradeCodeData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqEquityComputMode()
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryBill(CLRDFITCQryBillField ^ QryBillData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqTradingDay(CLRDFITCTradingDayField^ TradingDay)
	{
		DFITCTradingDayField *pTradingDay = new DFITCTradingDayField;
		Marshal::StructureToPtr(TradingDay, IntPtr(pTradingDay), true);
		return m_pNativeApi->ReqTradingDay(pTradingDay);
	}
	int CLRDFITCTraderApi::ReqQryQuoteNotice(CLRDFITCQryQuoteNoticeField ^ QryQuoteNoticeData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQuoteInsert(CLRDFITCQuoteInsertField ^ QuoteInsertOrderData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQuoteCancel(CLRDFITCCancelOrderField^ QuoteCancelOrderData)
	{
		DFITCCancelOrderField *pQuoteCancelOrderData = new DFITCCancelOrderField;
		Marshal::StructureToPtr(QuoteCancelOrderData, IntPtr(pQuoteCancelOrderData), true);
		return m_pNativeApi->ReqQuoteCancel(pQuoteCancelOrderData);
	}
	int CLRDFITCTraderApi::ReqCancelAllOrder(CLRDFITCCancelAllOrderField^ CancelAllOrderData)
	{
		DFITCCancelAllOrderField *pCancelAllOrderData = new DFITCCancelAllOrderField;
		Marshal::StructureToPtr(CancelAllOrderData, IntPtr(pCancelAllOrderData), true);
		return m_pNativeApi->ReqCancelAllOrder(pCancelAllOrderData);
	}
	int CLRDFITCTraderApi::ReqForQuote(CLRDFITCForQuoteField ^ ForQuoteData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryForQuote(CLRDFITCQryForQuoteField ^ QryForQuoteData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryQuoteOrderInfo(CLRDFITCQuoteOrderField ^ QuoteOrderData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryTransferBank(CLRDFITCQryTransferBankField ^ QryTransferBank)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryTransferSerial(CLRDFITCQryTransferSerialField ^ QryTransferSerial)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqFromBankToFutureByFuture(CLRDFITCReqTransferField ^ ReqTransfer)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqFromFutureToBankByFuture(CLRDFITCReqTransferField ^ ReqTransfer)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryExchangeStatus(CLRDFITCQryExchangeStatusField^ QryExchangeStatusData)
	{
		DFITCQryExchangeStatusField *pQryExchangeStatusData = new DFITCQryExchangeStatusField;
		Marshal::StructureToPtr(QryExchangeStatusData, IntPtr(pQryExchangeStatusData), true);
		return m_pNativeApi->ReqQryExchangeStatus(pQryExchangeStatusData);
	}
	int CLRDFITCTraderApi::ReqQryDepthMarketData(CLRDFITCQryDepthMarketDataField ^ QryDepthMarketData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryExchangeRate(CLRDFITCQryExchangeRateField ^ QryExchangeRate)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqPricesTrigger(CLRDFITCPricesTriggerField ^ PricesTriggerData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqQryExtOrder(CLRDFITCQryExtOrderField ^ QryEXOrderData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqCancelExtOrder(CLRDFITCCancelExtOrderField ^ CancelEXOrderData)
	{
		return 0;
	}
	int CLRDFITCTraderApi::ReqInsertOrder(CLRDFITCInsertOrderField^ InsertOrderData)
	{
		DFITCInsertOrderField *pInsertOrderData = new DFITCInsertOrderField;
		Marshal::StructureToPtr(InsertOrderData, IntPtr(pInsertOrderData), true);
		return m_pNativeApi->ReqInsertOrder(pInsertOrderData);
	}
	int CLRDFITCTraderApi::ReqQryCustomerCapital(CLRDFITCCapitalField^ CapitalData)
	{
		DFITCCapitalField *pCapitalData = new DFITCCapitalField;
		Marshal::StructureToPtr(CapitalData, IntPtr(pCapitalData), true);
		return m_pNativeApi->ReqQryCustomerCapital(pCapitalData);
	}
#pragma endregion

#pragma region CLRTraderSpi
	void CLRDFITCTraderSpi::callOnFrontConnected()
	{
		if(!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		this->OnFrontConnected();
	}
	void CLRDFITCTraderSpi::callOnFrontDisconnected(int nReason)
	{
		if(!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		this->OnFrontDisconnected(nReason);
	}
	void CLRDFITCTraderSpi::callOnRspUserLogin(DFITCUserLoginInfoRtnField * pRspUserLogin, DFITCErrorRtnField * pErrorInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCUserLoginInfoRtnField^ RspUserLogin = gcnew CLRDFITCUserLoginInfoRtnField;
		RspUserLogin = (CLRDFITCUserLoginInfoRtnField^)Marshal::PtrToStructure(IntPtr(pRspUserLogin), RspUserLogin->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspUserLogin(*RspUserLogin, *ErrorInfo);
	}
	void CLRDFITCTraderSpi::callOnRspUserLogout(DFITCUserLogoutInfoRtnField * pRspUserLogout, DFITCErrorRtnField * pErrorInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCUserLogoutInfoRtnField^ RspUserLogout = gcnew CLRDFITCUserLogoutInfoRtnField;
		RspUserLogout = (CLRDFITCUserLogoutInfoRtnField^)Marshal::PtrToStructure(IntPtr(pRspUserLogout), RspUserLogout->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		this->OnRspUserLogout(*RspUserLogout, *ErrorInfo);
	}
	void CLRDFITCTraderSpi::callOnRspInsertOrder(DFITCOrderRspDataRtnField * pRspOrder, DFITCErrorRtnField * pErrorInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCOrderRspDataRtnField^ RspOrder = gcnew CLRDFITCOrderRspDataRtnField;
		RspOrder = (CLRDFITCOrderRspDataRtnField^)Marshal::PtrToStructure(IntPtr(pRspOrder), RspOrder->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspInsertOrder(*RspOrder, *ErrorInfo);
	}
	void CLRDFITCTraderSpi::callOnRspCancelOrder(DFITCOrderRspDataRtnField * pRspOrderCancel, DFITCErrorRtnField * pErrorInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCOrderRspDataRtnField^ RspOrderCancel = gcnew CLRDFITCOrderRspDataRtnField;
		RspOrderCancel = (CLRDFITCOrderRspDataRtnField^)Marshal::PtrToStructure(IntPtr(pRspOrderCancel), RspOrderCancel->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspCancelOrder(*RspOrderCancel, *ErrorInfo);
	}
	void CLRDFITCTraderSpi::callOnRtnErrorMsg(DFITCErrorRtnField * pErrorInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		this->OnRtnErrorMsg(*ErrorInfo);
	}
	void CLRDFITCTraderSpi::callOnRtnMatchedInfo(DFITCMatchRtnField * pRtnMatchData)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCMatchRtnField^ RtnMatchData = gcnew CLRDFITCMatchRtnField;
		RtnMatchData = (CLRDFITCMatchRtnField^)Marshal::PtrToStructure(IntPtr(pRtnMatchData), RtnMatchData->GetType());
		this->OnRtnMatchedInfo(*RtnMatchData);
	}
	void CLRDFITCTraderSpi::callOnRtnOrder(DFITCOrderRtnField * pRtnOrderData)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCOrderRtnField^ RtnOrderData = gcnew CLRDFITCOrderRtnField;
		RtnOrderData = (CLRDFITCOrderRtnField^)Marshal::PtrToStructure(IntPtr(pRtnOrderData), RtnOrderData->GetType());
		this->OnRtnOrder(*RtnOrderData);
	}
	void CLRDFITCTraderSpi::callOnRtnCancelOrder(DFITCOrderCanceledRtnField * pRtnCancelOrderData)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCOrderCanceledRtnField^ RtnCancelOrderData = gcnew CLRDFITCOrderCanceledRtnField;
		RtnCancelOrderData = (CLRDFITCOrderCanceledRtnField^)Marshal::PtrToStructure(IntPtr(pRtnCancelOrderData), RtnCancelOrderData->GetType());
		this->OnRtnCancelOrder(*RtnCancelOrderData);
	}
	void CLRDFITCTraderSpi::callOnRspQryOrderInfo(DFITCOrderCommRtnField * pOrderData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		if(!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCOrderCommRtnField^ OrderData = gcnew CLRDFITCOrderCommRtnField;
		OrderData = (CLRDFITCOrderCommRtnField^)Marshal::PtrToStructure(IntPtr(pOrderData), OrderData->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspQryOrderInfo(*OrderData, *ErrorInfo, bIsLast);
	}
	void CLRDFITCTraderSpi::callOnRspQryMatchInfo(DFITCMatchedRtnField * pMatchData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCMatchedRtnField^ MatchData = gcnew CLRDFITCMatchedRtnField;
		MatchData = (CLRDFITCMatchedRtnField^)Marshal::PtrToStructure(IntPtr(pMatchData), MatchData->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspQryMatchInfo(*MatchData, *ErrorInfo, bIsLast);
	}
	void CLRDFITCTraderSpi::callOnRspQryPosition(DFITCPositionInfoRtnField * pPositionInfo, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCPositionInfoRtnField^ PositionInfo = gcnew CLRDFITCPositionInfoRtnField;
		PositionInfo = (CLRDFITCPositionInfoRtnField^)Marshal::PtrToStructure(IntPtr(pPositionInfo), PositionInfo->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspQryPosition(*PositionInfo, *ErrorInfo, bIsLast);
	}
	void CLRDFITCTraderSpi::callOnRspCustomerCapital(DFITCCapitalInfoRtnField * pCapitalInfo, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryExchangeInstrument(DFITCExchangeInstrumentRtnField * pInstrumentData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		if(!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCExchangeInstrumentRtnField^ InstrumentData = gcnew CLRDFITCExchangeInstrumentRtnField;
		InstrumentData = (CLRDFITCExchangeInstrumentRtnField^)Marshal::PtrToStructure(IntPtr(pInstrumentData), InstrumentData->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspQryExchangeInstrument(*InstrumentData, *ErrorInfo, bIsLast);
	}
	void CLRDFITCTraderSpi::callOnRspArbitrageInstrument(DFITCAbiInstrumentRtnField * pAbiInstrumentData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQrySpecifyInstrument(DFITCInstrumentRtnField * pInstrument, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCInstrumentRtnField^ Instrument = gcnew CLRDFITCInstrumentRtnField;
		Instrument = (CLRDFITCInstrumentRtnField^)Marshal::PtrToStructure(IntPtr(pInstrument), Instrument->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspQrySpecifyInstrument(*Instrument, *ErrorInfo, bIsLast);
	}
	void CLRDFITCTraderSpi::callOnRspQryPositionDetail(DFITCPositionDetailRtnField * pPositionDetail, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCPositionDetailRtnField^ PositionDetail = gcnew CLRDFITCPositionDetailRtnField;
		PositionDetail = (CLRDFITCPositionDetailRtnField^)Marshal::PtrToStructure(IntPtr(pPositionDetail), PositionDetail->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspQryPositionDetail(*PositionDetail, *ErrorInfo, bIsLast);
	}
	void CLRDFITCTraderSpi::callOnRtnTradingNotice(DFITCTradingNoticeInfoField * pTradingNoticeInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCTradingNoticeInfoField^ TradingNoticeInfo = gcnew CLRDFITCTradingNoticeInfoField;
		TradingNoticeInfo = (CLRDFITCTradingNoticeInfoField^)Marshal::PtrToStructure(IntPtr(pTradingNoticeInfo), TradingNoticeInfo->GetType());
		this->OnRtnTradingNotice(*TradingNoticeInfo);
	}
	void CLRDFITCTraderSpi::callOnRspResetPassword(DFITCResetPwdRspField * pResetPassword, DFITCErrorRtnField * pErrorInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCResetPwdRspField^ ResetPassword = gcnew CLRDFITCResetPwdRspField;
		ResetPassword = (CLRDFITCResetPwdRspField^)Marshal::PtrToStructure(IntPtr(pResetPassword), ResetPassword->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspResetPassword(*ResetPassword, *ErrorInfo);
	}
	void CLRDFITCTraderSpi::callOnRspQryTradeCode(DFITCQryTradeCodeRtnField * pTradeCode, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCQryTradeCodeRtnField^ TradeCode = gcnew CLRDFITCQryTradeCodeRtnField;
		TradeCode = (CLRDFITCQryTradeCodeRtnField^)Marshal::PtrToStructure(IntPtr(pTradeCode), TradeCode->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspQryTradeCode(*TradeCode, *ErrorInfo, bIsLast);
	}
	void CLRDFITCTraderSpi::callOnRspBillConfirm(DFITCBillConfirmRspField * pBillConfirm, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspEquityComputMode(DFITCEquityComputModeRtnField * pEquityComputMode)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryBill(DFITCQryBillRtnField * pQryBill, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspConfirmProductInfo(DFITCProductRtnField * pRspProductData)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspTradingDay(DFITCTradingDayRtnField * pTradingDayRtnData)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCTradingDayRtnField^ TradingDayRtnData = gcnew CLRDFITCTradingDayRtnField;
		TradingDayRtnData = (CLRDFITCTradingDayRtnField^)Marshal::PtrToStructure(IntPtr(pTradingDayRtnData), TradingDayRtnData->GetType());
		this->OnRspTradingDay(*TradingDayRtnData);
	}
	void CLRDFITCTraderSpi::callOnRspQuoteInsert(DFITCQuoteRspField * pRspQuote, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnQuoteInsert(DFITCQuoteRtnField * pRtnQuote)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQuoteCancel(DFITCQuoteRspField * pRspQuoteCancel, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnQuoteCancel(DFITCQuoteCanceledRtnField * pRtnQuoteCanceled)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnQuoteMatchedInfo(DFITCQuoteMatchRtnField * pRtnQuoteMatched)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnForQuoteRsp(DFITCQuoteSubscribeRtnField * pForQuoteRspData)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspCancelAllOrder(DFITCCancelAllOrderRspField * pRspCancelAllOrderData, DFITCErrorRtnField * pErrorInfo)
	{
		if (!m_pNativeSpi)
			throw gcnew System::ObjectDisposedException("CLRDFITCTraderSpi");
		CLRDFITCCancelAllOrderRspField^ RspCancelAllOrderData = gcnew CLRDFITCCancelAllOrderRspField;
		RspCancelAllOrderData = (CLRDFITCCancelAllOrderRspField^)Marshal::PtrToStructure(IntPtr(pRspCancelAllOrderData), RspCancelAllOrderData->GetType());
		CLRDFITCErrorRtnField^ ErrorInfo = gcnew CLRDFITCErrorRtnField;
		if (pErrorInfo != nullptr)
		{
			ErrorInfo = (CLRDFITCErrorRtnField^)Marshal::PtrToStructure(IntPtr(pErrorInfo), ErrorInfo->GetType());
		}
		this->OnRspCancelAllOrder(*RspCancelAllOrderData, *ErrorInfo);
	}
	void CLRDFITCTraderSpi::callOnRspQryQuoteNotice(DFITCQryQuoteNoticeRtnField * pQryQuoteNoticeData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspForQuote(DFITCForQuoteRspField * pRspForQuoteData, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnForQuote(DFITCForQuoteRtnField * pRtnForQuote)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryQuoteOrderInfo(DFITCQuoteOrderRtnField * pQuoteOrderData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryForQuote(DFITCQryForQuoteRtnField * pQryForQuoteData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryTransferBank(DFITCTransferBankRspField * pTransferBank, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryTransferSerial(DFITCTransferSerialRspField * pTransferSerial, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspFromBankToFutureByFuture(DFITCTransferRspField * pRspTransfer, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspFromFutureToBankByFuture(DFITCTransferRspField * pRspTransfer, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnFromBankToFutureByFuture(DFITCTransferRtnField * pRtnTransfer, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnFromFutureToBankByFuture(DFITCTransferRtnField * pRtnTransfer, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnRepealFromFutureToBankByBank(DFITCRepealRtnField * pRspRepeal)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryExchangeStatus(DFITCExchangeStatusRspField * pRspExchangeStatusData)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnExchangeStatus(DFITCExchangeStatusRtnField * pRtnExchangeStatusData)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryDepthMarketData(DFITCDepthMarketDataField * pDepthMarketData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryExchangeRate(DFITCExchangeRateField * pExchangeRate, DFITCErrorRtnField * pRspInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspQryPricesTrigger(DFITCQryPricesTriggerField * pQryPricesTriggerRspData, DFITCErrorRtnField * pErrorInfo, bool bIsLast)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspExtInsertOrder(DFITCExtOrderRspDataField * pOrderRsp, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRspExtCancelOrder(DFITCExtOrderRspDataField * pOrderCancelRsp, DFITCErrorRtnField * pErrorInfo)
	{
		throw gcnew System::NotImplementedException();
	}
	void CLRDFITCTraderSpi::callOnRtnPricesTrigger(DFITCPricesTriggerRtnField * pOrderRtn)
	{
		throw gcnew System::NotImplementedException();
	}
	CLRDFITCTraderSpi::CLRDFITCTraderSpi()
	{
		m_pNativeSpi = new TradeSpiHandler(this);
	}
	CLRDFITCTraderSpi::~CLRDFITCTraderSpi()
	{
		if (m_pNativeSpi)
		{
			delete m_pNativeSpi;
			m_pNativeSpi = 0;
		}
	}
#pragma endregion
}
