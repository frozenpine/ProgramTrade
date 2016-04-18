// CLRQdpApi.h

#pragma once
#pragma comment(lib,"qdpmduserapi.lib")
#pragma comment(lib,"qdptraderapi.lib")

#pragma managed

#include <stdio.h>
#include <windows.h>
#include <string>
#include <gcroot.h>
#include <msclr/auto_gcroot.h>
#include "QdpFtdcTraderApi.h"
#include "QdpFtdcMduserApi.h"
#include "CLRQdpApiDataStruct.h"

using namespace System;
using namespace Collections;
using namespace Threading;
using namespace Tasks;
using namespace Runtime::InteropServices;

namespace CLRQdpApi {

	public ref class CLRCQdpFtdcTraderSpi abstract
	{
	public:
		CLRCQdpFtdcTraderSpi();
		~CLRCQdpFtdcTraderSpi();
		CQdpFtdcTraderSpi* m_pSpi;
	protected:
		virtual void OnFrontConnected() = 0;
		virtual void OnFrontDisconnected(int nReason) = 0;
		virtual void OnHeartBeatWarning(int nTimeLapse) = 0;
		//virtual void OnPackageStart(int nTopicID, int nSequenceNo) = 0;
		//virtual void OnPackageEnd(int nTopicID, int nSequenceNo) = 0;
		virtual void OnRspError(CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspUserLogin(CLRCQdpFtdcRspUserLoginField RspUserLogin, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspUserLogout(CLRCQdpFtdcRspUserLogoutField RspUserLogout, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspUserPasswordUpdate(CLRCQdpFtdcUserPasswordUpdateField UserPasswordUpdate, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspOrderInsert(CLRCQdpFtdcInputOrderField InputOrder, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspOrderAction(CLRCQdpFtdcOrderActionField OrderAction, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRtnFlowMessageCancel(CLRCQdpFtdcFlowMessageCancelField FlowMessageCancel) = 0;
		virtual void OnRtnTrade(CLRCQdpFtdcTradeField Trade) = 0;
		virtual void OnRtnOrder(CLRCQdpFtdcOrderField Order) = 0;
		virtual void OnErrRtnOrderInsert(CLRCQdpFtdcInputOrderField InputOrder, CLRCQdpFtdcRspInfoField RspInfo) = 0;
		virtual void OnErrRtnOrderAction(CLRCQdpFtdcOrderActionField OrderAction, CLRCQdpFtdcRspInfoField RspInfo) = 0;
		virtual void OnRtnInstrumentStatus(CLRCQdpFtdcInstrumentStatusField InstrumentStatus) = 0;
		virtual void OnRtnInvestorAccountDeposit(CLRCQdpFtdcInvestorAccountDepositResField InvestorAccountDepositRes) = 0;
		virtual void OnRtnMessageNotify(CLRCQdpFtdcMessageNotifyInfoField MessageNotifyInfo) = 0;
		virtual void OnRspQryOrder(CLRCQdpFtdcOrderField Order, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryTrade(CLRCQdpFtdcTradeField Trade, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryUserInvestor(CLRCQdpFtdcRspUserInvestorField RspUserInvestor, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryInvestorAccount(CLRCQdpFtdcRspInvestorAccountField RspInvestorAccount, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryInstrument(CLRCQdpFtdcRspInstrumentField RspInstrument, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryExchange(CLRCQdpFtdcRspExchangeField RspExchange, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryInvestorPosition(CLRCQdpFtdcRspInvestorPositionField RspInvestorPosition, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryInvestorFee(CLRCQdpFtdcInvestorFeeField InvestorFee, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryInvestorMargin(CLRCQdpFtdcInvestorMarginField InvestorMargin, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryExchangeDiffTime(CLRCQdpFtdcRspExchangeDiffTimeField RspExchangeDiffTime, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
		virtual void OnRspQryMarketData(CLRCQdpFtdcMarketDataField MarketData, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) = 0;
	internal:
		void callOnFrontConnected();
		void callOnFrontDisconnected(int nReason);
		void callOnHeartBeatWarning(int nTimeLapse);
		//void callOnPackageStart(int nTopicID, int nSequenceNo);
		//void callOnPackageEnd(int nTopicID, int nSequenceNo);
		void callOnRspError(CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspUserLogin(CQdpFtdcRspUserLoginField *pRspUserLogin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspUserLogout(CQdpFtdcRspUserLogoutField *pRspUserLogout, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspUserPasswordUpdate(CQdpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRtnFlowMessageCancel(CQdpFtdcFlowMessageCancelField *pFlowMessageCancel);
		void callOnRtnTrade(CQdpFtdcTradeField *pTrade);
		void callOnRtnOrder(CQdpFtdcOrderField *pOrder);
		void callOnErrRtnOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo);
		void callOnErrRtnOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo);
		void callOnRtnInstrumentStatus(CQdpFtdcInstrumentStatusField *pInstrumentStatus);
		void callOnRtnInvestorAccountDeposit(CQdpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes);
		void callOnRtnMessageNotify(CQdpFtdcMessageNotifyInfoField *pMessageNotifyInfo);
		void callOnRspQryOrder(CQdpFtdcOrderField *pOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryTrade(CQdpFtdcTradeField *pTrade, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryUserInvestor(CQdpFtdcRspUserInvestorField *pRspUserInvestor, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryInvestorAccount(CQdpFtdcRspInvestorAccountField *pRspInvestorAccount, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryInstrument(CQdpFtdcRspInstrumentField *pRspInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryExchange(CQdpFtdcRspExchangeField *pRspExchange, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryInvestorPosition(CQdpFtdcRspInvestorPositionField *pRspInvestorPosition, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspSubscribeTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryInvestorFee(CQdpFtdcInvestorFeeField *pInvestorFee, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryInvestorMargin(CQdpFtdcInvestorMarginField *pInvestorMargin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryExchangeDiffTime(CQdpFtdcRspExchangeDiffTimeField *pRspExchangeDiffTime, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryMarketData(CQdpFtdcMarketDataField *pMarketData, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	};

	class TraderSpiHandler : public CQdpFtdcTraderSpi
	{
	public:
		TraderSpiHandler(CLRCQdpFtdcTraderSpi ^owner) : m_owner(owner) {}
		~TraderSpiHandler() {};
		gcroot<CLRCQdpFtdcTraderSpi^> m_owner;
	public:
		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		virtual void OnFrontConnected() { m_owner->callOnFrontConnected(); }

		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		virtual void OnFrontDisconnected(int nReason) { m_owner->callOnFrontDisconnected(nReason); }

		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		virtual void OnHeartBeatWarning(int nTimeLapse) { m_owner->callOnHeartBeatWarning(nTimeLapse); }

		///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
		///@param nTopicID ������루��˽���������������������ȣ�
		///@param nSequenceNo �������
		//virtual void OnPackageStart(int nTopicID, int nSequenceNo) { m_owner->callOnPackageStart(nTopicID, nSequenceNo); }

		///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
		///@param nTopicID ������루��˽���������������������ȣ�
		///@param nSequenceNo �������
		//virtual void OnPackageEnd(int nTopicID, int nSequenceNo) { m_owner->callOnPackageEnd(nTopicID, nSequenceNo); }


		///����Ӧ��
		virtual void OnRspError(CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspError(pRspInfo, nRequestID, bIsLast);
		}

		///�û���¼Ӧ��
		virtual void OnRspUserLogin(CQdpFtdcRspUserLoginField *pRspUserLogin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
		}

		///�û��˳�Ӧ��
		virtual void OnRspUserLogout(CQdpFtdcRspUserLogoutField *pRspUserLogout, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogout(pRspUserLogout, pRspInfo, nRequestID, bIsLast);
		}

		///�û������޸�Ӧ��
		virtual void OnRspUserPasswordUpdate(CQdpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
		}

		///����¼��Ӧ��
		virtual void OnRspOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspOrderInsert(pInputOrder, pRspInfo, nRequestID, bIsLast);
		}

		///��������Ӧ��
		virtual void OnRspOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspOrderAction(pOrderAction, pRspInfo, nRequestID, bIsLast);
		}

		///����������֪ͨ
		virtual void OnRtnFlowMessageCancel(CQdpFtdcFlowMessageCancelField *pFlowMessageCancel) 
		{
			m_owner->callOnRtnFlowMessageCancel(pFlowMessageCancel);
		}

		///�ɽ��ر�
		virtual void OnRtnTrade(CQdpFtdcTradeField *pTrade) { m_owner->callOnRtnTrade(pTrade); }

		///�����ر�
		virtual void OnRtnOrder(CQdpFtdcOrderField *pOrder) { m_owner->callOnRtnOrder(pOrder); }

		///����¼�����ر�
		virtual void OnErrRtnOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo) 
		{
			m_owner->callOnErrRtnOrderInsert(pInputOrder, pRspInfo);
		}

		///������������ر�
		virtual void OnErrRtnOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo) 
		{
			m_owner->callOnErrRtnOrderAction(pOrderAction, pRspInfo);
		}

		///��Լ����״̬֪ͨ
		virtual void OnRtnInstrumentStatus(CQdpFtdcInstrumentStatusField *pInstrumentStatus) 
		{
			m_owner->callOnRtnInstrumentStatus(pInstrumentStatus);
		}

		///�˻������ر�
		virtual void OnRtnInvestorAccountDeposit(CQdpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) 
		{
			m_owner->callOnRtnInvestorAccountDeposit(pInvestorAccountDepositRes);
		}

		///QDP������Ϣ֪ͨ
		virtual void OnRtnMessageNotify(CQdpFtdcMessageNotifyInfoField *pMessageNotifyInfo) 
		{
			m_owner->callOnRtnMessageNotify(pMessageNotifyInfo);
		}

		///������ѯӦ��
		virtual void OnRspQryOrder(CQdpFtdcOrderField *pOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryOrder(pOrder, pRspInfo, nRequestID, bIsLast);
		}

		///�ɽ�����ѯӦ��
		virtual void OnRspQryTrade(CQdpFtdcTradeField *pTrade, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryTrade(pTrade, pRspInfo, nRequestID, bIsLast);
		}

		///����Ͷ�����˻���ѯӦ��
		virtual void OnRspQryUserInvestor(CQdpFtdcRspUserInvestorField *pRspUserInvestor, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryUserInvestor(pRspUserInvestor, pRspInfo, nRequestID, bIsLast);
		}

		///Ͷ�����ʽ��˻���ѯӦ��
		virtual void OnRspQryInvestorAccount(CQdpFtdcRspInvestorAccountField *pRspInvestorAccount, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorAccount(pRspInvestorAccount, pRspInfo, nRequestID, bIsLast);
		}

		///��Լ��ѯӦ��
		virtual void OnRspQryInstrument(CQdpFtdcRspInstrumentField *pRspInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInstrument(pRspInstrument, pRspInfo, nRequestID, bIsLast);
		}

		///��������ѯӦ��
		virtual void OnRspQryExchange(CQdpFtdcRspExchangeField *pRspExchange, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryExchange(pRspExchange, pRspInfo, nRequestID, bIsLast);
		}

		///Ͷ���ֲֲ߳�ѯӦ��
		virtual void OnRspQryInvestorPosition(CQdpFtdcRspInvestorPositionField *pRspInvestorPosition, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorPosition(pRspInvestorPosition, pRspInfo, nRequestID, bIsLast);
		}

		///��������Ӧ��
		virtual void OnRspSubscribeTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspSubscribeTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		}

		///�����ѯӦ��
		virtual void OnRspQryTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		}

		///Ͷ�����������ʲ�ѯӦ��
		virtual void OnRspQryInvestorFee(CQdpFtdcInvestorFeeField *pInvestorFee, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorFee(pInvestorFee, pRspInfo, nRequestID, bIsLast);
		}

		///Ͷ���߱�֤���ʲ�ѯӦ��
		virtual void OnRspQryInvestorMargin(CQdpFtdcInvestorMarginField *pInvestorMargin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorMargin(pInvestorMargin, pRspInfo, nRequestID, bIsLast);
		}

		///������ʱ��ƫ���ѯӦ��
		virtual void OnRspQryExchangeDiffTime(CQdpFtdcRspExchangeDiffTimeField *pRspExchangeDiffTime, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryExchangeDiffTime(pRspExchangeDiffTime, pRspInfo, nRequestID, bIsLast);
		}

		///ʵʱ�����ѯӦ��
		virtual void OnRspQryMarketData(CQdpFtdcMarketDataField *pMarketData, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryMarketData(pMarketData, pRspInfo, nRequestID, bIsLast);
		}
	};

	public ref class CLRCQdpFtdcTraderApi
	{
	public:
		CLRCQdpFtdcTraderApi(String^ FlowPath)
		{
			if(!FlowPath)
				m_pNativeApi = CQdpFtdcTraderApi::CreateFtdcTraderApi();
			else
			{
				IntPtr p = Marshal::StringToHGlobalAnsi(FlowPath);
				char *pszFlowPath = static_cast<char *>(p.ToPointer());
				m_pNativeApi = CQdpFtdcTraderApi::CreateFtdcTraderApi(pszFlowPath);
			}
		}
		~CLRCQdpFtdcTraderApi() { }
		
		///��ȡϵͳ�汾��
		///@param nMajorVersion ���汾��
		///@param nMinorVersion �Ӱ汾��
		///@return ϵͳ��ʶ�ַ���
		static const String^ GetVersion(int &nMajorVersion, int &nMinorVersion);

		///ɾ���ӿڶ�����
		///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
		void Release();

		///��ʼ��
		///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
		void Init();

		///�ȴ��ӿ��߳̽�������
		///@return �߳��˳�����
		void Join();

		///��ȡ��ǰ������
		///@retrun ��ȡ���Ľ�����
		///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
		const String^ GetTradingDay();

		///ע��ǰ�û������ַ
		///@param pszFrontAddress��ǰ�û������ַ��
		///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
		///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
		void RegisterFront(String^ FrontServer);

		///ע�����ַ����������ַ
		///@param pszNsAddress�����ַ����������ַ��
		///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
		///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
		///@remark RegisterFront������RegisterNameServer
		void RegisterNameServer(String^ NameServer);

		///ע��ص��ӿ�
		///@param pSpi �����Իص��ӿ����ʵ��
		void RegisterSpi(CLRCQdpFtdcTraderSpi^ Spi);

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
		int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, const char *pszCaFileName, const char *pszKeyFilePassword);

		///����˽������
		///@param nResumeType ˽�����ش���ʽ  
		///        QDP_TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        QDP_TERT_RESUME:���ϴ��յ�������
		///        QDP_TERT_QUICK:ֻ���͵�¼��˽����������
		void SubscribePrivateTopic(CLRQDP_TE_RESUME_TYPE nResumeType);

		///���Ĺ�������
		///@param nResumeType �������ش���ʽ  
		///        QDP_TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        QDP_TERT_RESUME:���ϴ��յ�������
		///        QDP_TERT_QUICK:ֻ���͵�¼�󹫹���������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ������������ݡ�
		void SubscribePublicTopic(CLRQDP_TE_RESUME_TYPE nResumeType);

		///���Ľ���Ա����
		///@param nResumeType ����Ա���ش���ʽ  
		///        QDP_TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        QDP_TERT_RESUME:���ϴ��յ�������
		///        QDP_TERT_QUICK:ֻ���͵�¼����Ա��������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�����Ա�������ݡ�
		void SubscribeUserTopic(CLRQDP_TE_RESUME_TYPE nResumeType);

		///����������ʱʱ�䡣
		///@param timeout ������ʱʱ��(��)  
		void SetHeartbeatTimeout(unsigned int timeout);

		///��������־�ļ�
		///@param pszReqLogFileName ������־�ļ���  
		///@return 0 �����ɹ�
		///@return -1 ����־�ļ�ʧ��
		int OpenRequestLog(String^ ReqLogFileName);

		///��Ӧ����־�ļ�
		///@param pszRspLogFileName Ӧ����־�ļ���  
		///@return 0 �����ɹ�
		///@return -1 ����־�ļ�ʧ��
		int OpenResponseLog(String^ RspLogFileName);

		///�û���¼����
		int ReqUserLogin(CLRCQdpFtdcReqUserLoginField^ ReqUserLogin, int nRequestID);

		///�û��˳�����
		int ReqUserLogout(CLRCQdpFtdcReqUserLogoutField^ ReqUserLogout, int nRequestID);

		///�û������޸�����
		int ReqUserPasswordUpdate(CLRCQdpFtdcUserPasswordUpdateField^ UserPasswordUpdate, int nRequestID);

		///����¼������
		int ReqOrderInsert(CLRCQdpFtdcInputOrderField^ InputOrder, int nRequestID);

		///������������
		int ReqOrderAction(CLRCQdpFtdcOrderActionField^ OrderAction, int nRequestID);

		///������ѯ����
		int ReqQryOrder(CLRCQdpFtdcQryOrderField^ QryOrder, int nRequestID);

		///�ɽ�����ѯ����
		int ReqQryTrade(CLRCQdpFtdcQryTradeField^ QryTrade, int nRequestID);

		///����Ͷ�����˻���ѯ����
		int ReqQryUserInvestor(CLRCQdpFtdcQryUserInvestorField^ QryUserInvestor, int nRequestID);

		///Ͷ�����ʽ��˻���ѯ����
		int ReqQryInvestorAccount(CLRCQdpFtdcQryInvestorAccountField^ QryInvestorAccount, int nRequestID);

		///��Լ��ѯ����
		int ReqQryInstrument(CLRCQdpFtdcQryInstrumentField^ QryInstrument, int nRequestID);

		///��������ѯ����
		int ReqQryExchange(CLRCQdpFtdcQryExchangeField^ QryExchange, int nRequestID);

		///Ͷ���ֲֲ߳�ѯ����
		int ReqQryInvestorPosition(CLRCQdpFtdcQryInvestorPositionField^ QryInvestorPosition, int nRequestID);

		///������������
		int ReqSubscribeTopic(CLRCQdpFtdcDisseminationField^ Dissemination, int nRequestID);

		///�����ѯ����
		int ReqQryTopic(CLRCQdpFtdcDisseminationField^ Dissemination, int nRequestID);

		///Ͷ�����������ʲ�ѯ����
		int ReqQryInvestorFee(CLRCQdpFtdcQryInvestorFeeField^ QryInvestorFee, int nRequestID);

		///Ͷ���߱�֤���ʲ�ѯ����
		int ReqQryInvestorMargin(CLRCQdpFtdcQryInvestorMarginField^ QryInvestorMargin, int nRequestID);

	public:
		CQdpFtdcTraderApi *m_pNativeApi;
	};

	public ref class CLRCQdpFtdcMduserSpi abstract
	{
	public:
		CLRCQdpFtdcMduserSpi();
		~CLRCQdpFtdcMduserSpi();
		CQdpFtdcMduserSpi *m_pSpi;
	protected:
		virtual void OnFrontConnected() =0 ;
		virtual void OnFrontDisconnected(int nReason) =0 ;
		virtual void OnHeartBeatWarning(int nTimeLapse) =0 ;
		virtual void OnPackageStart(int nTopicID, int nSequenceNo) =0 ;
		virtual void OnPackageEnd(int nTopicID, int nSequenceNo) =0 ;
		virtual void OnMultiHeartbeat(String^ CurrTime, String^ MultiCastIP) =0 ;
		virtual void UdpMarketData(CLRCQdpFtdcDepthMarketDataField qmdata) =0 ;
		virtual void OnRspError(CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) =0 ;
		virtual void OnRspUserLogin(CLRCQdpFtdcRspUserLoginField RspUserLogin, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) =0 ;
		virtual void OnRspUserLogout(CLRCQdpFtdcRspUserLogoutField RspUserLogout, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) =0 ;
		virtual void OnRspSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) =0 ;
		virtual void OnRspQryTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) =0 ;
		virtual void OnRtnDepthMarketData(CLRCQdpFtdcDepthMarketDataField DepthMarketData) =0 ;
		virtual void OnRspSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) =0 ;
		virtual void OnRspUnSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast) =0 ;
	internal:
		void callOnFrontConnected();
		void callOnFrontDisconnected(int nReason);
		void callOnHeartBeatWarning(int nTimeLapse);
		void callOnPackageStart(int nTopicID, int nSequenceNo);
		void callOnPackageEnd(int nTopicID, int nSequenceNo);
		void callOnMultiHeartbeat(char *CurrTime, char *MultiCastIP);
		void callUdpMarketData(CQdpFtdcDepthMarketDataField *qmdata);
		void callOnRspError(CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspUserLogin(CQdpFtdcRspUserLoginField *pRspUserLogin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspUserLogout(CQdpFtdcRspUserLogoutField *pRspUserLogout, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspSubscribeTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspQryTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRtnDepthMarketData(CQdpFtdcDepthMarketDataField *pDepthMarketData);
		void callOnRspSubMarketData(CQdpFtdcSpecificInstrumentField *pSpecificInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void callOnRspUnSubMarketData(CQdpFtdcSpecificInstrumentField *pSpecificInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	};

	class MduserSpiHandler :public CQdpFtdcMduserSpi
	{
	public:
		MduserSpiHandler(CLRCQdpFtdcMduserSpi ^owner) :m_owner(owner) {};
		~MduserSpiHandler() {};
		gcroot<CLRCQdpFtdcMduserSpi^>m_owner;
	public:
		///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
		virtual void OnFrontConnected() { m_owner->callOnFrontConnected(); };

		///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
		///@param nReason ����ԭ��
		///        0x1001 �����ʧ��
		///        0x1002 ����дʧ��
		///        0x2001 ����������ʱ
		///        0x2002 ��������ʧ��
		///        0x2003 �յ�������
		virtual void OnFrontDisconnected(int nReason) { m_owner->callOnFrontDisconnected(nReason); };

		///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
		///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
		virtual void OnHeartBeatWarning(int nTimeLapse) { m_owner->callOnHeartBeatWarning(nTimeLapse); };

		///���Ļص���ʼ֪ͨ����API�յ�һ�����ĺ����ȵ��ñ�������Ȼ���Ǹ�������Ļص�������Ǳ��Ļص�����֪ͨ��
		///@param nTopicID ������루��˽���������������������ȣ�
		///@param nSequenceNo �������
		virtual void OnPackageStart(int nTopicID, int nSequenceNo) { m_owner->callOnPackageStart(nTopicID, nSequenceNo); };

		///���Ļص�����֪ͨ����API�յ�һ�����ĺ����ȵ��ñ��Ļص���ʼ֪ͨ��Ȼ���Ǹ�������Ļص��������ñ�������
		///@param nTopicID ������루��˽���������������������ȣ�
		///@param nSequenceNo �������
		virtual void OnPackageEnd(int nTopicID, int nSequenceNo) { m_owner->callOnPackageEnd(nTopicID, nSequenceNo); };

		//�����ಥ�����ӿ� add by zbz 20150304
		virtual void  OnMultiHeartbeat(char *CurrTime, char *MultiCastIP) { m_owner->callOnMultiHeartbeat(CurrTime, MultiCastIP); };

		//���㲥�յ�ֵ��ʱ�򣬻ص����������ã�����qmdata
		virtual void UdpMarketData(CQdpFtdcDepthMarketDataField *qmdata) { m_owner->callUdpMarketData(qmdata); };

		///����Ӧ��
		virtual void OnRspError(CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) { m_owner->callOnRspError(pRspInfo, nRequestID, bIsLast); };

		///�û���¼Ӧ��
		virtual void OnRspUserLogin(CQdpFtdcRspUserLoginField *pRspUserLogin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
		};

		///�û��˳�Ӧ��
		virtual void OnRspUserLogout(CQdpFtdcRspUserLogoutField *pRspUserLogout, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogout(pRspUserLogout, pRspInfo, nRequestID, bIsLast);
		};

		///��������Ӧ��
		virtual void OnRspSubscribeTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspSubscribeTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		};

		///�����ѯӦ��
		virtual void OnRspQryTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		};

		///�������֪ͨ
		virtual void OnRtnDepthMarketData(CQdpFtdcDepthMarketDataField *pDepthMarketData) { m_owner->callOnRtnDepthMarketData(pDepthMarketData); };

		///���ĺ�Լ�������Ϣ
		virtual void OnRspSubMarketData(CQdpFtdcSpecificInstrumentField *pSpecificInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
		};

		///�˶���Լ�������Ϣ
		virtual void OnRspUnSubMarketData(CQdpFtdcSpecificInstrumentField *pSpecificInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUnSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
		};
	};

	public ref class CLRCQdpFtdcMduserApi
	{
	public:
		CLRCQdpFtdcMduserApi(String^ FlowPath) 
		{ 
			IntPtr p = Marshal::StringToHGlobalAnsi(FlowPath);
			const char *pFlowPath = static_cast<char *>(p.ToPointer());
			m_pNativeApi = CQdpFtdcMduserApi::CreateFtdcMduserApi(pFlowPath);
		}
		~CLRCQdpFtdcMduserApi() {};

		///��ȡϵͳ�汾��
		///@param nMajorVersion ���汾��
		///@param nMinorVersion �Ӱ汾��
		///@return ϵͳ��ʶ�ַ���
		static const String^ GetVersion(int &nMajorVersion, int &nMinorVersion);

		///ɾ���ӿڶ�����
		///@remark ����ʹ�ñ��ӿڶ���ʱ,���øú���ɾ���ӿڶ���
		void Release();

		//�ಥ���ÿ���
		void SetMultiCast(bool bMultiCast);

		//ע��ಥ��ַ
		void RegTopicMultiAddr(String^ MultiAddr);

		///��ʼ��
		///@remark ��ʼ�����л���,ֻ�е��ú�,�ӿڲſ�ʼ����
		void Init();

		///�ȴ��ӿ��߳̽�������
		///@return �߳��˳�����
		int Join();

		///��ȡ��ǰ������
		///@retrun ��ȡ���Ľ�����
		///@remark ֻ�е�¼�ɹ���,���ܵõ���ȷ�Ľ�����
		const String^ GetTradingDay();

		///ע��ǰ�û������ַ
		///@param pszFrontAddress��ǰ�û������ַ��
		///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:17001���� 
		///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����17001������������˿ںš�
		void RegisterFront(String^ FrontAddress);

		///ע�����ַ����������ַ
		///@param pszNsAddress�����ַ����������ַ��
		///@remark �����ַ�ĸ�ʽΪ����protocol://ipaddress:port�����磺��tcp://127.0.0.1:12001���� 
		///@remark ��tcp��������Э�飬��127.0.0.1�������������ַ����12001������������˿ںš�
		///@remark RegisterFront������RegisterNameServer
		void RegisterNameServer(String^ NsAddress);

		///�����ڴ�ȡֵ
		///@param CQdpFtdcShmDepthMarketDataField  �������
		///@param CQdpFtdcDepthMarketDataField ��ѯ��������ֵ
		///@return 0 �����ɹ�
		///@return -1 ����־�ļ�ʧ��
		void ShmMarketData(CLRCQdpFtdcShmDepthMarketDataField reqfield, CLRCQdpFtdcDepthMarketDataField defdata);

		///����UDP����
		///@param  udpip�㲥��ַ
		///@return 0 �����ɹ�
		///@return -1 ��ȡUDPʧ��
		void setudpchannel(String^ UdpIP);

		///ע��ص��ӿ�
		///@param pSpi �����Իص��ӿ����ʵ��
		void RegisterSpi(CLRCQdpFtdcMduserSpi^ Spi);

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
		int RegisterCertificateFile(String^ CertFileName, String^ KeyFileName, String^ CaFileName, String^ KeyFilePassword);

		///�����г����顣
		///@param nTopicID �г���������  
		///@param nResumeType �г������ش���ʽ  
		///        QDP_TERT_RESTART:�ӱ������տ�ʼ�ش�
		///        QDP_TERT_RESUME:���ϴ��յ�������(�Ƕ���ȫ����Լʱ����֧������ģʽ)
		///        QDP_TERT_QUICK:�ȴ��͵�ǰ�������,�ٴ��͵�¼���г����������
		///@remark �÷���Ҫ��Init����ǰ���á����������򲻻��յ�˽���������ݡ�
		void SubscribeMarketDataTopic(int nTopicID, CLRQDP_TE_RESUME_TYPE ResumeType) ;

		///���ĺ�Լ���顣
		///@param ppInstrumentID ��ԼID  
		///@param nCount Ҫ����/�˶�����ĺ�Լ����
		///@remark 
		int SubMarketData(array<String^>^ InstrumentID);

		///�˶���Լ���顣
		///@param ppInstrumentID ��ԼID  
		///@param nCount Ҫ����/�˶�����ĺ�Լ����
		///@remark 
		//int UnSubMarketData(char *ppInstrumentID[], int nCount);

		///����������ʱʱ�䡣
		///@param timeout ������ʱʱ��(��)  
		void SetHeartbeatTimeout(unsigned int timeout);

		///�û���¼����
		int ReqUserLogin(CLRCQdpFtdcReqUserLoginField^ ReqUserLogin, int nRequestID);

		///�û��˳�����
		int ReqUserLogout(CLRCQdpFtdcReqUserLogoutField ReqUserLogout, int nRequestID);

		///������������
		int ReqSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID);

		///�����ѯ����
		int ReqQryTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID);

		///Topic��ѯ
		//int ReqTopicSearch(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID);

		///�˶���Լ�������Ϣ
		int ReqUnSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID);

		//�����ಥ
		//���޷���¼������������£����ô˽ӿڿ��Խ����鲥����
		//�ڿ��Ե�¼�������������ô˽ӿ�
		//@param TradingDay �����գ���û�е�¼������£���������Ȼ�գ�����Ҫע�⽻�����Ľ�����
		void ActiveMultiMarketData(String^ TradingDay);

		CQdpFtdcMduserApi *m_pNativeApi;
	};
}

