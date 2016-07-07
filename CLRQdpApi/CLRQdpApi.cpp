// 这是主 DLL 文件。

#include "CLRQdpApi.h"

namespace CLRQdpApi
{
	///************************************
	///CLRCQdpFtdcTraderSpi Functions Start
	///************************************
	CLRCQdpFtdcTraderSpi::CLRCQdpFtdcTraderSpi()
	{
		m_pSpi = new TraderSpiHandler(this);
	}

	CLRCQdpFtdcTraderSpi::~CLRCQdpFtdcTraderSpi()
	{
		if (m_pSpi)
		{
			delete m_pSpi;
			m_pSpi = 0;
		}
	}

	void CLRCQdpFtdcTraderSpi::callOnFrontConnected()
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		this->OnFrontConnected();
	}

	void CLRCQdpFtdcTraderSpi::callOnFrontDisconnected(int nReason)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		this->OnFrontDisconnected(nReason);
	}

	void CLRCQdpFtdcTraderSpi::callOnHeartBeatWarning(int nTimeLapse)
	{
		if(!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		this->OnHeartBeatWarning(nTimeLapse);
	}

	/*void CLRCQdpFtdcTraderSpi::callOnPackageStart(int nTopicID, int nSequenceNo)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		this->callOnPackageStart(nTopicID, nSequenceNo);
	}

	void CLRCQdpFtdcTraderSpi::callOnPackageEnd(int nTopicID, int nSequenceNo)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		this->callOnPackageEnd(nTopicID, nSequenceNo);
	}*/

	void CLRCQdpFtdcTraderSpi::callOnRspError(CQdpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspError(*RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspUserLogin(CQdpFtdcRspUserLoginField* pRspUserLogin, CQdpFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspUserLoginField^ RspUserLogin = gcnew CLRCQdpFtdcRspUserLoginField;
		RspUserLogin = (CLRCQdpFtdcRspUserLoginField^)Marshal::PtrToStructure(IntPtr(pRspUserLogin), RspUserLogin->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspUserLogin(*RspUserLogin, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspUserLogout(CQdpFtdcRspUserLogoutField * pRspUserLogout, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspUserLogoutField^ RspUserLogout = gcnew CLRCQdpFtdcRspUserLogoutField;
		RspUserLogout = (CLRCQdpFtdcRspUserLogoutField^)Marshal::PtrToStructure(IntPtr(pRspUserLogout), RspUserLogout->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspUserLogout(*RspUserLogout, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspUserPasswordUpdate(CQdpFtdcUserPasswordUpdateField * pUserPasswordUpdate, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcUserPasswordUpdateField^ UserPasswordUpdate = gcnew CLRCQdpFtdcUserPasswordUpdateField;
		UserPasswordUpdate = (CLRCQdpFtdcUserPasswordUpdateField^)Marshal::PtrToStructure(IntPtr(pUserPasswordUpdate), UserPasswordUpdate->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspUserPasswordUpdate(*UserPasswordUpdate, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspOrderInsert(CQdpFtdcInputOrderField * pInputOrder, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcInputOrderField^ InputOrder = gcnew CLRCQdpFtdcInputOrderField;
		InputOrder = (CLRCQdpFtdcInputOrderField^)Marshal::PtrToStructure(IntPtr(pInputOrder), InputOrder->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspOrderInsert(*InputOrder, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspOrderAction(CQdpFtdcOrderActionField * pOrderAction, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcOrderActionField^ OrderAction = gcnew CLRCQdpFtdcOrderActionField;
		OrderAction = (CLRCQdpFtdcOrderActionField^)Marshal::PtrToStructure(IntPtr(pOrderAction), OrderAction->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspOrderAction(*OrderAction, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRtnFlowMessageCancel(CQdpFtdcFlowMessageCancelField * pFlowMessageCancel)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcFlowMessageCancelField^ FlowMessageCancel = gcnew CLRCQdpFtdcFlowMessageCancelField;
		FlowMessageCancel = (CLRCQdpFtdcFlowMessageCancelField^)Marshal::PtrToStructure(IntPtr(pFlowMessageCancel), FlowMessageCancel->GetType());
		this->OnRtnFlowMessageCancel(*FlowMessageCancel);
	}

	void CLRCQdpFtdcTraderSpi::callOnRtnTrade(CQdpFtdcTradeField * pTrade)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcTradeField^ Trade = gcnew CLRCQdpFtdcTradeField;
		Trade = (CLRCQdpFtdcTradeField^)Marshal::PtrToStructure(IntPtr(pTrade), Trade->GetType());
		this->OnRtnTrade(*Trade);
	}

	void CLRCQdpFtdcTraderSpi::callOnRtnOrder(CQdpFtdcOrderField * pOrder)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcOrderField^ Order = gcnew CLRCQdpFtdcOrderField;
		Order = (CLRCQdpFtdcOrderField^)Marshal::PtrToStructure(IntPtr(pOrder), Order->GetType());
		this->OnRtnOrder(*Order);
	}

	void CLRCQdpFtdcTraderSpi::callOnErrRtnOrderInsert(CQdpFtdcInputOrderField * pInputOrder, CQdpFtdcRspInfoField * pRspInfo)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcInputOrderField^ InputOrder = gcnew CLRCQdpFtdcInputOrderField;
		InputOrder = (CLRCQdpFtdcInputOrderField^)Marshal::PtrToStructure(IntPtr(pInputOrder), InputOrder->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnErrRtnOrderInsert(*InputOrder, *RspInfo);
	}

	void CLRCQdpFtdcTraderSpi::callOnErrRtnOrderAction(CQdpFtdcOrderActionField * pOrderAction, CQdpFtdcRspInfoField * pRspInfo)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcOrderActionField^ OrderAction = gcnew CLRCQdpFtdcOrderActionField;
		OrderAction = (CLRCQdpFtdcOrderActionField^)Marshal::PtrToStructure(IntPtr(pOrderAction), OrderAction->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnErrRtnOrderAction(*OrderAction, *RspInfo);
	}

	void CLRCQdpFtdcTraderSpi::callOnRtnInstrumentStatus(CQdpFtdcInstrumentStatusField * pInstrumentStatus)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcInstrumentStatusField^ InstrumentStatus = gcnew CLRCQdpFtdcInstrumentStatusField;
		InstrumentStatus = (CLRCQdpFtdcInstrumentStatusField^)Marshal::PtrToStructure(IntPtr(pInstrumentStatus), InstrumentStatus->GetType());
		this->OnRtnInstrumentStatus(*InstrumentStatus);
	}

	void CLRCQdpFtdcTraderSpi::callOnRtnInvestorAccountDeposit(CQdpFtdcInvestorAccountDepositResField * pInvestorAccountDepositRes)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcInvestorAccountDepositResField^ InvestorAccountDepositRes = gcnew CLRCQdpFtdcInvestorAccountDepositResField;
		InvestorAccountDepositRes = (CLRCQdpFtdcInvestorAccountDepositResField^)Marshal::PtrToStructure(IntPtr(pInvestorAccountDepositRes), InvestorAccountDepositRes->GetType());
		this->OnRtnInvestorAccountDeposit(*InvestorAccountDepositRes);
	}

	void CLRCQdpFtdcTraderSpi::callOnRtnMessageNotify(CQdpFtdcMessageNotifyInfoField * pMessageNotifyInfo)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcMessageNotifyInfoField^ MessageNotifyInfo = gcnew CLRCQdpFtdcMessageNotifyInfoField;
		MessageNotifyInfo = (CLRCQdpFtdcMessageNotifyInfoField^)Marshal::PtrToStructure(IntPtr(pMessageNotifyInfo), MessageNotifyInfo->GetType());
		this->OnRtnMessageNotify(*MessageNotifyInfo);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryOrder(CQdpFtdcOrderField * pOrder, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcOrderField^ Order = gcnew CLRCQdpFtdcOrderField;
		Order = (CLRCQdpFtdcOrderField^)Marshal::PtrToStructure(IntPtr(pOrder), Order->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryOrder(*Order, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryTrade(CQdpFtdcTradeField * pTrade, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcTradeField^ Trade = gcnew CLRCQdpFtdcTradeField;
		Trade = (CLRCQdpFtdcTradeField^)Marshal::PtrToStructure(IntPtr(pTrade), Trade->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryTrade(*Trade, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryUserInvestor(CQdpFtdcRspUserInvestorField * pRspUserInvestor, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspUserInvestorField^ RspUserInvestor = gcnew CLRCQdpFtdcRspUserInvestorField;
		RspUserInvestor = (CLRCQdpFtdcRspUserInvestorField^)Marshal::PtrToStructure(IntPtr(pRspUserInvestor), RspUserInvestor->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryUserInvestor(*RspUserInvestor, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryInvestorAccount(CQdpFtdcRspInvestorAccountField * pRspInvestorAccount, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspInvestorAccountField^ RspInvestorAccount = gcnew CLRCQdpFtdcRspInvestorAccountField;
		RspInvestorAccount = (CLRCQdpFtdcRspInvestorAccountField^)Marshal::PtrToStructure(IntPtr(pRspInvestorAccount), RspInvestorAccount->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryInvestorAccount(*RspInvestorAccount, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryInstrument(CQdpFtdcRspInstrumentField * pRspInstrument, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspInstrumentField^ RspInstrument = gcnew CLRCQdpFtdcRspInstrumentField;
		RspInstrument = (CLRCQdpFtdcRspInstrumentField^)Marshal::PtrToStructure(IntPtr(pRspInstrument), RspInstrument->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryInstrument(*RspInstrument, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryExchange(CQdpFtdcRspExchangeField * pRspExchange, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspExchangeField^ RspExchange = gcnew CLRCQdpFtdcRspExchangeField;
		RspExchange = (CLRCQdpFtdcRspExchangeField^)Marshal::PtrToStructure(IntPtr(pRspExchange), RspExchange->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryExchange(*RspExchange, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryInvestorPosition(CQdpFtdcRspInvestorPositionField * pRspInvestorPosition, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspInvestorPositionField^ RspInvestorPosition = gcnew CLRCQdpFtdcRspInvestorPositionField;
		RspInvestorPosition = (CLRCQdpFtdcRspInvestorPositionField^)Marshal::PtrToStructure(IntPtr(pRspInvestorPosition), RspInvestorPosition->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryInvestorPosition(*RspInvestorPosition, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspSubscribeTopic(CQdpFtdcDisseminationField * pDissemination, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcDisseminationField^ Dissemination = gcnew CLRCQdpFtdcDisseminationField;
		Dissemination = (CLRCQdpFtdcDisseminationField^)Marshal::PtrToStructure(IntPtr(pDissemination), Dissemination->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspSubscribeTopic(*Dissemination, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryTopic(CQdpFtdcDisseminationField * pDissemination, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcDisseminationField^ Dissemination = gcnew CLRCQdpFtdcDisseminationField;
		Dissemination = (CLRCQdpFtdcDisseminationField^)Marshal::PtrToStructure(IntPtr(pDissemination), Dissemination->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryTopic(*Dissemination, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryInvestorFee(CQdpFtdcInvestorFeeField * pInvestorFee, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcInvestorFeeField^ InvestorFee = gcnew CLRCQdpFtdcInvestorFeeField;
		InvestorFee = (CLRCQdpFtdcInvestorFeeField^)Marshal::PtrToStructure(IntPtr(pInvestorFee), InvestorFee->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryInvestorFee(*InvestorFee, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryInvestorMargin(CQdpFtdcInvestorMarginField * pInvestorMargin, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcInvestorMarginField^ InvestorMargin = gcnew CLRCQdpFtdcInvestorMarginField;
		InvestorMargin = (CLRCQdpFtdcInvestorMarginField^)Marshal::PtrToStructure(IntPtr(pInvestorMargin), InvestorMargin->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryInvestorMargin(*InvestorMargin, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryExchangeDiffTime(CQdpFtdcRspExchangeDiffTimeField * pRspExchangeDiffTime, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcRspExchangeDiffTimeField^ RspExchangDiffTime = gcnew CLRCQdpFtdcRspExchangeDiffTimeField;
		RspExchangDiffTime = (CLRCQdpFtdcRspExchangeDiffTimeField^)Marshal::PtrToStructure(IntPtr(pRspExchangeDiffTime), RspExchangDiffTime->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryExchangeDiffTime(*RspExchangDiffTime, *RspInfo, nRequestID, bIsLast);
	}

	void CLRCQdpFtdcTraderSpi::callOnRspQryMarketData(CQdpFtdcMarketDataField * pMarketData, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcTraderSpi");
		CLRCQdpFtdcMarketDataField^ MarketData = gcnew CLRCQdpFtdcMarketDataField;
		MarketData = (CLRCQdpFtdcMarketDataField^)Marshal::PtrToStructure(IntPtr(pMarketData), MarketData->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryMarketData(*MarketData, *RspInfo, nRequestID, bIsLast);
	}
	///**********************************
	///CLRCQdpFtdcTraderSpi Functions End
	///**********************************

	///************************************
	///CLRCQdpFtdcTraderApi Functions Start
	///************************************
	const String^ CLRCQdpFtdcTraderApi::GetVersion(int &nMajorVersion, int &nMinorVersion)
	{
		return gcnew String(CQdpFtdcTraderApi::GetVersion(nMajorVersion, nMinorVersion));
	}

	void CLRCQdpFtdcTraderApi::Release() { m_pNativeApi->Release(); }

	void CLRCQdpFtdcTraderApi::Init() { m_pNativeApi->Init(); }

	void CLRCQdpFtdcTraderApi::Join() { m_pNativeApi->Join(); }

	const String^ CLRCQdpFtdcTraderApi::GetTradingDay()
	{
		String^ tmp = gcnew String(m_pNativeApi->GetTradingDay());
		return tmp;
	}

	void CLRCQdpFtdcTraderApi::RegisterFront(String^ FrontServer)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(FrontServer);
		char *pszFrontAddress = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegisterFront(pszFrontAddress);
	}

	void CLRCQdpFtdcTraderApi::RegisterNameServer(String^ NameServer)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(NameServer);
		char *pszNsAddress = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegisterNameServer(pszNsAddress);
	}

	void CLRCQdpFtdcTraderApi::RegisterSpi(CLRCQdpFtdcTraderSpi^ Spi)
	{
		m_pNativeApi->RegisterSpi(Spi->m_pSpi);
	}

	int CLRCQdpFtdcTraderApi::RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName,
		const char *pszCaFileName, const char *pszKeyFilePassword)
	{
		return m_pNativeApi->RegisterCertificateFile(pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
	}

	void CLRCQdpFtdcTraderApi::SubscribePrivateTopic(CLRQDP_TE_RESUME_TYPE nResumeType)
	{
		switch (nResumeType)
		{
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_QUICK:
			m_pNativeApi->SubscribePrivateTopic(QDP_TE_RESUME_TYPE::QDP_TERT_QUICK);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESTART:
			m_pNativeApi->SubscribePrivateTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESTART);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESUME:
			m_pNativeApi->SubscribePrivateTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESUME);
			break;
		default:
			m_pNativeApi->SubscribePrivateTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESUME);
		}
	}

	void CLRCQdpFtdcTraderApi::SubscribePublicTopic(CLRQDP_TE_RESUME_TYPE nResumeType)
	{
		switch (nResumeType)
		{
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_QUICK:
			m_pNativeApi->SubscribePublicTopic(QDP_TE_RESUME_TYPE::QDP_TERT_QUICK);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESTART:
			m_pNativeApi->SubscribePublicTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESTART);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESUME:
			m_pNativeApi->SubscribePublicTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESUME);
			break;
		default:
			m_pNativeApi->SubscribePublicTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESUME);
		}
	}

	void CLRCQdpFtdcTraderApi::SubscribeUserTopic(CLRQDP_TE_RESUME_TYPE nResumeType)
	{
		switch (nResumeType)
		{
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_QUICK:
			m_pNativeApi->SubscribeUserTopic(QDP_TE_RESUME_TYPE::QDP_TERT_QUICK);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESTART:
			m_pNativeApi->SubscribeUserTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESTART);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESUME:
			m_pNativeApi->SubscribeUserTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESUME);
		default:
			m_pNativeApi->SubscribeUserTopic(QDP_TE_RESUME_TYPE::QDP_TERT_RESUME);
			break;
		}
	}

	void CLRCQdpFtdcTraderApi::SetHeartbeatTimeout(unsigned int timeout) { m_pNativeApi->SetHeartbeatTimeout(timeout); }

	int CLRCQdpFtdcTraderApi::OpenRequestLog(String^ ReqLogFileName)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(ReqLogFileName);
		char *pszReqLogFileName = static_cast<char *>(p.ToPointer());
		return m_pNativeApi->OpenRequestLog(pszReqLogFileName);
	}

	int CLRCQdpFtdcTraderApi::OpenResponseLog(String^ RspLogFileName)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(RspLogFileName);
		char *pszRspLogFileName = static_cast<char *>(p.ToPointer());
		return m_pNativeApi->OpenResponseLog(pszRspLogFileName);
	}

	int CLRCQdpFtdcTraderApi::ReqUserLogin(CLRCQdpFtdcReqUserLoginField^ ReqUserLogin, int nRequestID)
	{
		CQdpFtdcReqUserLoginField* pReqUserLogin = new CQdpFtdcReqUserLoginField;
		Marshal::StructureToPtr(ReqUserLogin, IntPtr(pReqUserLogin), true);

		return m_pNativeApi->ReqUserLogin(pReqUserLogin, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqUserLogout(CLRCQdpFtdcReqUserLogoutField^ ReqUserLogout, int nRequestID)
	{
		CQdpFtdcReqUserLogoutField* pReqUserLogout = new CQdpFtdcReqUserLogoutField;
		Marshal::StructureToPtr(ReqUserLogout, IntPtr(pReqUserLogout), true);
		return m_pNativeApi->ReqUserLogout(pReqUserLogout, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqUserPasswordUpdate(CLRCQdpFtdcUserPasswordUpdateField^ UserPasswordUpdate, int nRequestID)
	{
		CQdpFtdcUserPasswordUpdateField* pUserPasswordUpdate = new CQdpFtdcUserPasswordUpdateField;
		Marshal::StructureToPtr(UserPasswordUpdate, IntPtr(pUserPasswordUpdate), true);
		return m_pNativeApi->ReqUserPasswordUpdate(pUserPasswordUpdate, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqOrderInsert(CLRCQdpFtdcInputOrderField^ InputOrder, int nRequestID)
	{
		CQdpFtdcInputOrderField* pInputOrder = new CQdpFtdcInputOrderField;
		Marshal::StructureToPtr(InputOrder, IntPtr(pInputOrder), false);
		return m_pNativeApi->ReqOrderInsert(pInputOrder, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqOrderAction(CLRCQdpFtdcOrderActionField^ OrderAction, int nRequestID)
	{
		CQdpFtdcOrderActionField* pOrderAction = new CQdpFtdcOrderActionField;
		Marshal::StructureToPtr(OrderAction, IntPtr(pOrderAction), true);
		return m_pNativeApi->ReqOrderAction((CQdpFtdcOrderActionField*)pOrderAction, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryOrder(CLRCQdpFtdcQryOrderField^ QryOrder, int nRequestID)
	{
		CQdpFtdcQryOrderField* pQryOrder = new CQdpFtdcQryOrderField;
		Marshal::StructureToPtr(QryOrder, IntPtr(pQryOrder), true);
		return m_pNativeApi->ReqQryOrder(pQryOrder, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryTrade(CLRCQdpFtdcQryTradeField^ QryTrade, int nRequestID)
	{
		CQdpFtdcQryTradeField* pQryTrade = new CQdpFtdcQryTradeField;
		Marshal::StructureToPtr(QryTrade, IntPtr(pQryTrade), true);
		return m_pNativeApi->ReqQryTrade(pQryTrade, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryUserInvestor(CLRCQdpFtdcQryUserInvestorField^ QryUserInvestor, int nRequestID)
	{
		CQdpFtdcQryUserInvestorField* pQryUserInvestor = new CQdpFtdcQryUserInvestorField;
		Marshal::StructureToPtr(QryUserInvestor, IntPtr(pQryUserInvestor), true);
		return m_pNativeApi->ReqQryUserInvestor(pQryUserInvestor, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryInvestorAccount(CLRCQdpFtdcQryInvestorAccountField^ QryInvestorAccount, int nRequestID)
	{
		CQdpFtdcQryInvestorAccountField* pQryInvestorAccount = new CQdpFtdcQryInvestorAccountField;
		Marshal::StructureToPtr(QryInvestorAccount, IntPtr(pQryInvestorAccount), true);
		return m_pNativeApi->ReqQryInvestorAccount(pQryInvestorAccount, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryInstrument(CLRCQdpFtdcQryInstrumentField^ QryInstrument, int nRequestID)
	{
		CQdpFtdcQryInstrumentField* pQryInstrument = new CQdpFtdcQryInstrumentField;
		Marshal::StructureToPtr(QryInstrument, IntPtr(pQryInstrument), true);
		return m_pNativeApi->ReqQryInstrument(pQryInstrument, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryExchange(CLRCQdpFtdcQryExchangeField^ QryExchange, int nRequestID)
	{
		CQdpFtdcQryExchangeField* pQryExchange = new CQdpFtdcQryExchangeField;
		Marshal::StructureToPtr(QryExchange, IntPtr(pQryExchange), true);
		return m_pNativeApi->ReqQryExchange(pQryExchange, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryInvestorPosition(CLRCQdpFtdcQryInvestorPositionField^ QryInvestorPosition, int nRequestID)
	{
		CQdpFtdcQryInvestorPositionField* pQryInvestorPosition = new CQdpFtdcQryInvestorPositionField;
		Marshal::StructureToPtr(QryInvestorPosition, IntPtr(pQryInvestorPosition), true);
		return m_pNativeApi->ReqQryInvestorPosition(pQryInvestorPosition, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqSubscribeTopic(CLRCQdpFtdcDisseminationField^ Dissemination, int nRequestID)
	{
		CQdpFtdcDisseminationField* pDissemination = new CQdpFtdcDisseminationField;
		Marshal::StructureToPtr(Dissemination, IntPtr(pDissemination), true);
		return m_pNativeApi->ReqSubscribeTopic(pDissemination, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryTopic(CLRCQdpFtdcDisseminationField^ Dissemination, int nRequestID)
	{
		CQdpFtdcDisseminationField* pDissemination = new CQdpFtdcDisseminationField;
		Marshal::StructureToPtr(Dissemination, IntPtr(pDissemination), true);
		return m_pNativeApi->ReqQryTopic(pDissemination, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryInvestorFee(CLRCQdpFtdcQryInvestorFeeField^ QryInvestorFee, int nRequestID)
	{
		CQdpFtdcQryInvestorFeeField* pQryInvestorFee = new CQdpFtdcQryInvestorFeeField;
		Marshal::StructureToPtr(QryInvestorFee, IntPtr(pQryInvestorFee), true);
		return m_pNativeApi->ReqQryInvestorFee(pQryInvestorFee, nRequestID);
	}

	int CLRCQdpFtdcTraderApi::ReqQryInvestorMargin(CLRCQdpFtdcQryInvestorMarginField^ QryInvestorMargin, int nRequestID)
	{
		CQdpFtdcQryInvestorMarginField* pQryInvestorMargin = new CQdpFtdcQryInvestorMarginField;
		Marshal::StructureToPtr(QryInvestorMargin, IntPtr(pQryInvestorMargin), true);
		return m_pNativeApi->ReqQryInvestorMargin(pQryInvestorMargin, nRequestID);
	}
	///**********************************
	///CLRCQdpFtdcTraderApi Functions End
	///**********************************

	///***********************************
	///CLRCQdpFtdcMduserSpi Functions Start
	///***********************************
	CLRCQdpFtdcMduserSpi::CLRCQdpFtdcMduserSpi()
	{
		m_pSpi = new MduserSpiHandler(this);
	}

	CLRCQdpFtdcMduserSpi::~CLRCQdpFtdcMduserSpi()
	{
		if (m_pSpi)
		{
			delete m_pSpi;
			m_pSpi = 0;
		}
	}
	void CLRCQdpFtdcMduserSpi::callOnFrontConnected()
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		this->OnFrontConnected();
		
	}
	void CLRCQdpFtdcMduserSpi::callOnFrontDisconnected(int nReason)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		this->OnFrontDisconnected(nReason);
	}
	void CLRCQdpFtdcMduserSpi::callOnHeartBeatWarning(int nTimeLapse)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		this->OnHeartBeatWarning(nTimeLapse);
	}
	void CLRCQdpFtdcMduserSpi::callOnPackageStart(int nTopicID, int nSequenceNo)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		this->OnPackageStart(nTopicID, nSequenceNo);
	}
	void CLRCQdpFtdcMduserSpi::callOnPackageEnd(int nTopicID, int nSequenceNo)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		this->OnPackageEnd(nTopicID, nSequenceNo);
	}
	void CLRCQdpFtdcMduserSpi::callOnMultiHeartbeat(char * CurrTime, char * MultiCastIP)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		this->OnMultiHeartbeat(gcnew String(CurrTime), gcnew String(MultiCastIP));
	}
	void CLRCQdpFtdcMduserSpi::callUdpMarketData(CQdpFtdcDepthMarketDataField * qmdata)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcDepthMarketDataField^ qmData = gcnew CLRCQdpFtdcDepthMarketDataField;
		qmData = (CLRCQdpFtdcDepthMarketDataField^)Marshal::PtrToStructure(IntPtr(qmdata), qmData->GetType());
		this->UdpMarketData(*qmData);
	}
	void CLRCQdpFtdcMduserSpi::callOnRspError(CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspError(*RspInfo, nRequestID, bIsLast);
	}
	void CLRCQdpFtdcMduserSpi::callOnRspUserLogin(CQdpFtdcRspUserLoginField * pRspUserLogin, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcRspUserLoginField^ RspUserLogin = gcnew CLRCQdpFtdcRspUserLoginField;
		RspUserLogin = (CLRCQdpFtdcRspUserLoginField^)Marshal::PtrToStructure(IntPtr(pRspUserLogin), RspUserLogin->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspUserLogin(*RspUserLogin, *RspInfo, nRequestID, bIsLast);
	}
	void CLRCQdpFtdcMduserSpi::callOnRspUserLogout(CQdpFtdcRspUserLogoutField * pRspUserLogout, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcRspUserLogoutField^ RspUserLogout = gcnew CLRCQdpFtdcRspUserLogoutField;
		RspUserLogout = (CLRCQdpFtdcRspUserLogoutField^)Marshal::PtrToStructure(IntPtr(pRspUserLogout), RspUserLogout->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspUserLogout(*RspUserLogout, *RspInfo, nRequestID, bIsLast);
	}
	void CLRCQdpFtdcMduserSpi::callOnRspSubscribeTopic(CQdpFtdcDisseminationField * pDissemination, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcDisseminationField^ Dissemination = gcnew CLRCQdpFtdcDisseminationField;
		Dissemination = (CLRCQdpFtdcDisseminationField^)Marshal::PtrToStructure(IntPtr(pDissemination), Dissemination->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspSubscribeTopic(*Dissemination, *RspInfo, nRequestID, bIsLast);
	}
	void CLRCQdpFtdcMduserSpi::callOnRspQryTopic(CQdpFtdcDisseminationField * pDissemination, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcDisseminationField^ Dissemination = gcnew CLRCQdpFtdcDisseminationField;
		Dissemination = (CLRCQdpFtdcDisseminationField^)Marshal::PtrToStructure(IntPtr(pDissemination), Dissemination->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspQryTopic(*Dissemination, *RspInfo, nRequestID, bIsLast);
	}
	void CLRCQdpFtdcMduserSpi::callOnRtnDepthMarketData(CQdpFtdcDepthMarketDataField * pDepthMarketData)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcDepthMarketDataField^ DepthMarketData = gcnew CLRCQdpFtdcDepthMarketDataField;
		DepthMarketData = (CLRCQdpFtdcDepthMarketDataField^)Marshal::PtrToStructure(IntPtr(pDepthMarketData), DepthMarketData->GetType());
		this->OnRtnDepthMarketData(*DepthMarketData);
	}
	void CLRCQdpFtdcMduserSpi::callOnRspSubMarketData(CQdpFtdcSpecificInstrumentField * pSpecificInstrument, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcSpecificInstrumentField^ SpecificInstrument = gcnew CLRCQdpFtdcSpecificInstrumentField;
		SpecificInstrument = (CLRCQdpFtdcSpecificInstrumentField^)Marshal::PtrToStructure(IntPtr(pSpecificInstrument), SpecificInstrument->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		//this->OnRspSubMarketData(*SpecificInstrument, *RspInfo, nRequestID, bIsLast);
		this->OnRspSubMarketData(*SpecificInstrument, nRequestID, bIsLast);
	}
	void CLRCQdpFtdcMduserSpi::callOnRspUnSubMarketData(CQdpFtdcSpecificInstrumentField * pSpecificInstrument, CQdpFtdcRspInfoField * pRspInfo, int nRequestID, bool bIsLast)
	{
		if (!m_pSpi)
			throw gcnew ObjectDisposedException("CLRCQdpFtdcMduserSpi");
		CLRCQdpFtdcSpecificInstrumentField^ SpecificInstrument = gcnew CLRCQdpFtdcSpecificInstrumentField;
		SpecificInstrument = (CLRCQdpFtdcSpecificInstrumentField^)Marshal::PtrToStructure(IntPtr(pSpecificInstrument), SpecificInstrument->GetType());
		CLRCQdpFtdcRspInfoField^ RspInfo = gcnew CLRCQdpFtdcRspInfoField;
		RspInfo = (CLRCQdpFtdcRspInfoField^)Marshal::PtrToStructure(IntPtr(pRspInfo), RspInfo->GetType());
		this->OnRspUnSubMarketData(*SpecificInstrument, *RspInfo, nRequestID, bIsLast);
	}
	///***********************************
	///CLRCQdpFtdcMduserSpi Functions End
	///***********************************

	///************************************
	///CLRCQdpFtdcMduserApi Functions Start
	///************************************

	///获取系统版本号
	///@param nMajorVersion 主版本号
	///@param nMinorVersion 子版本号
	///@return 系统标识字符串
	const String^ CLRCQdpFtdcMduserApi::GetVersion(int &nMajorVersion, int &nMinorVersion)
	{
		return gcnew String(CQdpFtdcMduserApi::GetVersion(nMajorVersion, nMinorVersion));
	};

	///删除接口对象本身
	///@remark 不再使用本接口对象时,调用该函数删除接口对象
	void CLRCQdpFtdcMduserApi::Release() 
	{ m_pNativeApi->Release(); }

	//多播设置开关
	void CLRCQdpFtdcMduserApi::SetMultiCast(bool bMultiCast) 
	{ m_pNativeApi->SetMultiCast(bMultiCast = false); }

	//注册多播地址
	void CLRCQdpFtdcMduserApi::RegTopicMultiAddr(String^ MultiAddr) 
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(MultiAddr);
		char *pMultiAddr = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegTopicMultiAddr(pMultiAddr); 
	}

	///初始化
	///@remark 初始化运行环境,只有调用后,接口才开始工作
	void CLRCQdpFtdcMduserApi::Init() { m_pNativeApi->Init(); }

	///等待接口线程结束运行
	///@return 线程退出代码
	int CLRCQdpFtdcMduserApi::Join() { return m_pNativeApi->Join(); }

	///获取当前交易日
	///@retrun 获取到的交易日
	///@remark 只有登录成功后,才能得到正确的交易日
	const String^ CLRCQdpFtdcMduserApi::GetTradingDay() 
	{ 
		return gcnew String(m_pNativeApi->GetTradingDay());
	}

	///注册前置机网络地址
	///@param pszFrontAddress：前置机网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
	void CLRCQdpFtdcMduserApi::RegisterFront(String^ FrontAddress)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(FrontAddress);
		char *pszFrontAddress = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegisterFront(pszFrontAddress); 
	}

	///注册名字服务器网络地址
	///@param pszNsAddress：名字服务器网络地址。
	///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
	///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
	///@remark RegisterFront优先于RegisterNameServer
	void CLRCQdpFtdcMduserApi::RegisterNameServer(String^ NsAddress) 
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(NsAddress);
		char *pszNsAddress = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegisterNameServer(pszNsAddress); 
	}

	///共享内存取值
	///@param CQdpFtdcShmDepthMarketDataField  传入参数
	///@param CQdpFtdcDepthMarketDataField 查询到的行情值
	///@return 0 操作成功
	///@return -1 打开日志文件失败
	void CLRCQdpFtdcMduserApi::ShmMarketData(CLRCQdpFtdcShmDepthMarketDataField Reqfield, CLRCQdpFtdcDepthMarketDataField Defdata)
	{
		CQdpFtdcShmDepthMarketDataField *reqfield = new CQdpFtdcShmDepthMarketDataField;
		Marshal::StructureToPtr(Reqfield, IntPtr(reqfield), true);
		CQdpFtdcDepthMarketDataField *defdata = new CQdpFtdcDepthMarketDataField;
		Marshal::StructureToPtr(Defdata, IntPtr(defdata), true);
		m_pNativeApi->ShmMarketData(reqfield, defdata);
	}

	///建立UDP连接
	///@param  udpip广播地址
	///@return 0 操作成功
	///@return -1 读取UDP失败
	void CLRCQdpFtdcMduserApi::setudpchannel(String^ UdpIP) 
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(UdpIP);
		char *udpip = static_cast<char *>(p.ToPointer());
		m_pNativeApi->setudpchannel(udpip); 
	}

	///注册回调接口
	///@param pSpi 派生自回调接口类的实例
	void CLRCQdpFtdcMduserApi::RegisterSpi(CLRCQdpFtdcMduserSpi^ Spi)
	{
		m_pNativeApi->RegisterSpi(Spi->m_pSpi); 
	}

	///加载证书
	///@param pszCertFileName 用户证书文件名
	///@param pszKeyFileName 用户私钥文件名
	///@param pszCaFileName 可信任CA证书文件名
	///@param pszKeyFilePassword 用户私钥文件密码
	///@return 0 操作成功
	///@return -1 可信任CA证书载入失败
	///@return -2 用户证书载入失败
	///@return -3 用户私钥载入失败	
	///@return -4 用户证书校验失败
	int CLRCQdpFtdcMduserApi::RegisterCertificateFile(String^ CertFileName, String^ KeyFileName, String^ CaFileName, String^ KeyFilePassword)
	{
		IntPtr p1 = Marshal::StringToHGlobalAnsi(CertFileName);
		char *pszCertFileName = static_cast<char *>(p1.ToPointer());
		IntPtr p2 = Marshal::StringToHGlobalAnsi(KeyFileName);
		char *pszKeyFileName = static_cast<char *>(p2.ToPointer());
		IntPtr p3 = Marshal::StringToHGlobalAnsi(CaFileName);
		char *pszCaFileName = static_cast<char *>(p3.ToPointer());
		IntPtr p4 = Marshal::StringToHGlobalAnsi(KeyFilePassword);
		char *pszKeyFilePassword = static_cast<char *>(p4.ToPointer());
		return m_pNativeApi->RegisterCertificateFile(pszCertFileName, pszKeyFileName, pszCaFileName, pszKeyFilePassword);
	}

	///订阅市场行情。
	///@param nTopicID 市场行情主题  
	///@param nResumeType 市场行情重传方式  
	///        QDP_TERT_RESTART:从本交易日开始重传
	///        QDP_TERT_RESUME:从上次收到的续传(非订阅全部合约时，不支持续传模式)
	///        QDP_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
	///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
	void CLRCQdpFtdcMduserApi::SubscribeMarketDataTopic(int nTopicID, CLRQDP_TE_RESUME_TYPE ResumeType)
	{
		switch (ResumeType)
		{
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_QUICK:
			m_pNativeApi->SubscribeMarketDataTopic(nTopicID, QDP_TE_RESUME_TYPE::QDP_TERT_QUICK);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESTART:
			m_pNativeApi->SubscribeMarketDataTopic(nTopicID, QDP_TE_RESUME_TYPE::QDP_TERT_RESTART);
			break;
		case CLRQDP_TE_RESUME_TYPE::QDP_TERT_RESUME:
			m_pNativeApi->SubscribeMarketDataTopic(nTopicID, QDP_TE_RESUME_TYPE::QDP_TERT_RESUME);
			break;
		default:
			m_pNativeApi->SubscribeMarketDataTopic(nTopicID, QDP_TE_RESUME_TYPE::QDP_TERT_QUICK);
			break;
		}
	}

	///订阅合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	int CLRCQdpFtdcMduserApi::SubMarketData(array<String^>^ InstrumentID) 
	{
		/*char *ppInstrumentID[nCount];
		Parallel::ForEach<String^>(InstrumentID, );
		return m_pNativeApi->SubMarketData(ppInstrumentID, nCount);*/
		int size = InstrumentID->Length;
		char **ppInstrumentID = static_cast<char **>(Marshal::AllocHGlobal(sizeof(int) * size).ToPointer());
		for (int i = 0; i < InstrumentID->Length; i++)
		{
			*(ppInstrumentID + i) = static_cast<char *>(Marshal::StringToHGlobalAnsi(InstrumentID[i]).ToPointer());
		}
		return m_pNativeApi->SubMarketData(ppInstrumentID, size);
	}

	///退订合约行情。
	///@param ppInstrumentID 合约ID  
	///@param nCount 要订阅/退订行情的合约个数
	///@remark 
	/*int CLRCQdpFtdcMduserApi::UnSubMarketData(char *ppInstrumentID[], int nCount)
	{
		return m_pNativeApi->UnSubMarketData(ppInstrumentID, nCount);
	}*/

	///设置心跳超时时间。
	///@param timeout 心跳超时时间(秒)  
	void CLRCQdpFtdcMduserApi::SetHeartbeatTimeout(unsigned int timeout) { m_pNativeApi->SetHeartbeatTimeout(timeout); }

	///用户登录请求
	int CLRCQdpFtdcMduserApi::ReqUserLogin(CLRCQdpFtdcReqUserLoginField^ ReqUserLogin, int nRequestID)
	{
		CQdpFtdcReqUserLoginField *pReqUserLogin = new CQdpFtdcReqUserLoginField;
		Marshal::StructureToPtr(ReqUserLogin, IntPtr(pReqUserLogin), true);
		return m_pNativeApi->ReqUserLogin(pReqUserLogin, nRequestID);
		/*int size = Marshal::SizeOf(ReqUserLogin);
		IntPtr p = Marshal::AllocHGlobal(size);
		Marshal::StructureToPtr(ReqUserLogin, p, false);
		return m_pNativeApi->ReqUserLogin((CQdpFtdcReqUserLoginField *)p.ToPointer(), nRequestID);*/
	}

	///用户退出请求
	int CLRCQdpFtdcMduserApi::ReqUserLogout(CLRCQdpFtdcReqUserLogoutField ReqUserLogout, int nRequestID)
	{
		CQdpFtdcReqUserLogoutField *pReqUserLogout = new CQdpFtdcReqUserLogoutField;
		Marshal::StructureToPtr(ReqUserLogout, IntPtr(pReqUserLogout), true);
		return m_pNativeApi->ReqUserLogout(pReqUserLogout, nRequestID);
	}

	///订阅主题请求
	int CLRCQdpFtdcMduserApi::ReqSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID)
	{
		CQdpFtdcDisseminationField *pDissemination = new CQdpFtdcDisseminationField;
		Marshal::StructureToPtr(Dissemination, IntPtr(pDissemination), true);
		return m_pNativeApi->ReqSubscribeTopic(pDissemination, nRequestID);
	}

	///主题查询请求
	int CLRCQdpFtdcMduserApi::ReqQryTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID)
	{
		CQdpFtdcDisseminationField *pDissemination = new CQdpFtdcDisseminationField;
		Marshal::StructureToPtr(Dissemination, IntPtr(pDissemination), true);
		return m_pNativeApi->ReqQryTopic(pDissemination, nRequestID);
	}

	///Topic查询
	/*int CLRCQdpFtdcMduserApi::ReqTopicSearch(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID)
	{
		CQdpFtdcSpecificInstrumentField *pSpecificInstrument = new CQdpFtdcSpecificInstrumentField;
		Marshal::StructureToPtr(SpecificInstrument, IntPtr(pSpecificInstrument), true);
		return m_pNativeApi->ReqTopicSearch(pSpecificInstrument, nRequestID);
	}*/

	///退订合约的相关信息
	int CLRCQdpFtdcMduserApi::ReqUnSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID)
	{
		CQdpFtdcSpecificInstrumentField *pSpecificInstrument = new CQdpFtdcSpecificInstrumentField;
		Marshal::StructureToPtr(SpecificInstrument, IntPtr(pSpecificInstrument), true);
		return m_pNativeApi->ReqUnSubMarketData(pSpecificInstrument, nRequestID);
	}

	//启动多播
	//在无法登录服务器的情况下，调用此接口可以接收组播行情
	//在可以登录的情况下无需调用此接口
	//@param TradingDay 交易日，在没有登录的情况下，可以是自然日，但是要注意交易所的交易日
	void CLRCQdpFtdcMduserApi::ActiveMultiMarketData(String^ TradingDay) 
	{ 
		IntPtr p = Marshal::StringToHGlobalAnsi(TradingDay);
		char *pszTradingDay = static_cast<char *>(p.ToPointer());
		m_pNativeApi->ActiveMultiMarketData(pszTradingDay); 
	}
	///**********************************
	///CLRCQdpFtdcMduserApi Functions End
	///**********************************
}
