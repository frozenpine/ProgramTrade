// ������ DLL �ļ���

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

	///��ȡϵͳ�汾��
	///@param nMajorVersion ���汾��
	///@param nMinorVersion �Ӱ汾��
	///@return ϵͳ��ʶ�ַ���
	const String^ CLRCQdpFtdcMduserApi::GetVersion(int &nMajorVersion, int &nMinorVersion)
	{
		return gcnew String(CQdpFtdcMduserApi::GetVersion(nMajorVersion, nMinorVersion));
	};

	///ɾ���ӿڶ�����
	///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
	void CLRCQdpFtdcMduserApi::Release() 
	{ m_pNativeApi->Release(); }

	//�ಥ���ÿ���
	void CLRCQdpFtdcMduserApi::SetMultiCast(bool bMultiCast) 
	{ m_pNativeApi->SetMultiCast(bMultiCast = false); }

	//ע��ಥ��ַ
	void CLRCQdpFtdcMduserApi::RegTopicMultiAddr(String^ MultiAddr) 
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(MultiAddr);
		char *pMultiAddr = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegTopicMultiAddr(pMultiAddr); 
	}

	///��ʼ��
	///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
	void CLRCQdpFtdcMduserApi::Init() { m_pNativeApi->Init(); }

	///�ȴ��ӿ��߳̽�������
	///@return �߳��˳�����
	int CLRCQdpFtdcMduserApi::Join() { return m_pNativeApi->Join(); }

	///��ȡ��ǰ������
	///@retrun ��ȡ���Ľ�����
	///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
	const String^ CLRCQdpFtdcMduserApi::GetTradingDay() 
	{ 
		return gcnew String(m_pNativeApi->GetTradingDay());
	}

	///ע��ǰ�û������ַ
	///@param pszFrontAddress��ǰ�û������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
	void CLRCQdpFtdcMduserApi::RegisterFront(String^ FrontAddress)
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(FrontAddress);
		char *pszFrontAddress = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegisterFront(pszFrontAddress); 
	}

	///ע�����ַ����������ַ
	///@param pszNsAddress�����ַ����������ַ��
	///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
	///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
	///@remark RegisterFront������RegisterNameServer
	void CLRCQdpFtdcMduserApi::RegisterNameServer(String^ NsAddress) 
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(NsAddress);
		char *pszNsAddress = static_cast<char *>(p.ToPointer());
		m_pNativeApi->RegisterNameServer(pszNsAddress); 
	}

	///�����ڴ�ȡֵ
	///@param CQdpFtdcShmDepthMarketDataField  �������
	///@param CQdpFtdcDepthMarketDataField ��ѯ��������ֵ
	///@return 0 �����ɹ�
	///@return -1 ����־�ļ�ʧ��
	void CLRCQdpFtdcMduserApi::ShmMarketData(CLRCQdpFtdcShmDepthMarketDataField Reqfield, CLRCQdpFtdcDepthMarketDataField Defdata)
	{
		CQdpFtdcShmDepthMarketDataField *reqfield = new CQdpFtdcShmDepthMarketDataField;
		Marshal::StructureToPtr(Reqfield, IntPtr(reqfield), true);
		CQdpFtdcDepthMarketDataField *defdata = new CQdpFtdcDepthMarketDataField;
		Marshal::StructureToPtr(Defdata, IntPtr(defdata), true);
		m_pNativeApi->ShmMarketData(reqfield, defdata);
	}

	///����UDP����
	///@param  udpip�㲥��ַ
	///@return 0 �����ɹ�
	///@return -1 ��ȡUDPʧ��
	void CLRCQdpFtdcMduserApi::setudpchannel(String^ UdpIP) 
	{
		IntPtr p = Marshal::StringToHGlobalAnsi(UdpIP);
		char *udpip = static_cast<char *>(p.ToPointer());
		m_pNativeApi->setudpchannel(udpip); 
	}

	///ע��ص��ӿ�
	///@param pSpi �����Իص��ӿ����ʵ��
	void CLRCQdpFtdcMduserApi::RegisterSpi(CLRCQdpFtdcMduserSpi^ Spi)
	{
		m_pNativeApi->RegisterSpi(Spi->m_pSpi); 
	}

	///����֤��
	///@param pszCertFileName �û�֤���ļ���
	///@param pszKeyFileName �û�˽Կ�ļ���
	///@param pszCaFileName ������CA֤���ļ���
	///@param pszKeyFilePassword �û�˽Կ�ļ�����
	///@return 0 �����ɹ�
	///@return -1 ������CA֤������ʧ��
	///@return -2 �û�֤������ʧ��
	///@return -3 �û�˽Կ����ʧ��	
	///@return -4 �û�֤��У��ʧ��
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

	///�����г����顣
	///@param nTopicID �г���������  
	///@param nResumeType �г������ش���ʽ  
	///        QDP_TERT_RESTART:�ӱ������տ�ʼ�ش�
	///        QDP_TERT_RESUME:���ϴ��յ�������(�Ƕ���ȫ����Լʱ����֧������ģʽ)
	///        QDP_TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
	///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
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

	///���ĺ�Լ���顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
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

	///�˶���Լ���顣
	///@param ppInstrumentID ��ԼID  
	///@param nCount Ҫ����/�˶�����ĺ�Լ����
	///@remark 
	/*int CLRCQdpFtdcMduserApi::UnSubMarketData(char *ppInstrumentID[], int nCount)
	{
		return m_pNativeApi->UnSubMarketData(ppInstrumentID, nCount);
	}*/

	///����������ʱʱ�䡣
	///@param timeout ������ʱʱ��(��)  
	void CLRCQdpFtdcMduserApi::SetHeartbeatTimeout(unsigned int timeout) { m_pNativeApi->SetHeartbeatTimeout(timeout); }

	///�û���¼����
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

	///�û��˳�����
	int CLRCQdpFtdcMduserApi::ReqUserLogout(CLRCQdpFtdcReqUserLogoutField ReqUserLogout, int nRequestID)
	{
		CQdpFtdcReqUserLogoutField *pReqUserLogout = new CQdpFtdcReqUserLogoutField;
		Marshal::StructureToPtr(ReqUserLogout, IntPtr(pReqUserLogout), true);
		return m_pNativeApi->ReqUserLogout(pReqUserLogout, nRequestID);
	}

	///������������
	int CLRCQdpFtdcMduserApi::ReqSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID)
	{
		CQdpFtdcDisseminationField *pDissemination = new CQdpFtdcDisseminationField;
		Marshal::StructureToPtr(Dissemination, IntPtr(pDissemination), true);
		return m_pNativeApi->ReqSubscribeTopic(pDissemination, nRequestID);
	}

	///�����ѯ����
	int CLRCQdpFtdcMduserApi::ReqQryTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID)
	{
		CQdpFtdcDisseminationField *pDissemination = new CQdpFtdcDisseminationField;
		Marshal::StructureToPtr(Dissemination, IntPtr(pDissemination), true);
		return m_pNativeApi->ReqQryTopic(pDissemination, nRequestID);
	}

	///Topic��ѯ
	/*int CLRCQdpFtdcMduserApi::ReqTopicSearch(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID)
	{
		CQdpFtdcSpecificInstrumentField *pSpecificInstrument = new CQdpFtdcSpecificInstrumentField;
		Marshal::StructureToPtr(SpecificInstrument, IntPtr(pSpecificInstrument), true);
		return m_pNativeApi->ReqTopicSearch(pSpecificInstrument, nRequestID);
	}*/

	///�˶���Լ�������Ϣ
	int CLRCQdpFtdcMduserApi::ReqUnSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID)
	{
		CQdpFtdcSpecificInstrumentField *pSpecificInstrument = new CQdpFtdcSpecificInstrumentField;
		Marshal::StructureToPtr(SpecificInstrument, IntPtr(pSpecificInstrument), true);
		return m_pNativeApi->ReqUnSubMarketData(pSpecificInstrument, nRequestID);
	}

	//�����ಥ
	//���޷���¼������������£����ô˽ӿڿ��Խ����鲥����
	//�ڿ��Ե�¼�������������ô˽ӿ�
	//@param TradingDay �����գ���û�е�¼������£���������Ȼ�գ�����Ҫע�⽻�����Ľ�����
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
