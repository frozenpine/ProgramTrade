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
		///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		virtual void OnFrontConnected() { m_owner->callOnFrontConnected(); }

		///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		///@param nReason 错误原因
		///        0x1001 网络读失败
		///        0x1002 网络写失败
		///        0x2001 接收心跳超时
		///        0x2002 发送心跳失败
		///        0x2003 收到错误报文
		virtual void OnFrontDisconnected(int nReason) { m_owner->callOnFrontDisconnected(nReason); }

		///心跳超时警告。当长时间未收到报文时，该方法被调用。
		///@param nTimeLapse 距离上次接收报文的时间
		virtual void OnHeartBeatWarning(int nTimeLapse) { m_owner->callOnHeartBeatWarning(nTimeLapse); }

		///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
		///@param nTopicID 主题代码（如私有流、公共流、行情流等）
		///@param nSequenceNo 报文序号
		//virtual void OnPackageStart(int nTopicID, int nSequenceNo) { m_owner->callOnPackageStart(nTopicID, nSequenceNo); }

		///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
		///@param nTopicID 主题代码（如私有流、公共流、行情流等）
		///@param nSequenceNo 报文序号
		//virtual void OnPackageEnd(int nTopicID, int nSequenceNo) { m_owner->callOnPackageEnd(nTopicID, nSequenceNo); }


		///错误应答
		virtual void OnRspError(CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspError(pRspInfo, nRequestID, bIsLast);
		}

		///用户登录应答
		virtual void OnRspUserLogin(CQdpFtdcRspUserLoginField *pRspUserLogin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
		}

		///用户退出应答
		virtual void OnRspUserLogout(CQdpFtdcRspUserLogoutField *pRspUserLogout, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogout(pRspUserLogout, pRspInfo, nRequestID, bIsLast);
		}

		///用户密码修改应答
		virtual void OnRspUserPasswordUpdate(CQdpFtdcUserPasswordUpdateField *pUserPasswordUpdate, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserPasswordUpdate(pUserPasswordUpdate, pRspInfo, nRequestID, bIsLast);
		}

		///报单录入应答
		virtual void OnRspOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspOrderInsert(pInputOrder, pRspInfo, nRequestID, bIsLast);
		}

		///报单操作应答
		virtual void OnRspOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspOrderAction(pOrderAction, pRspInfo, nRequestID, bIsLast);
		}

		///数据流回退通知
		virtual void OnRtnFlowMessageCancel(CQdpFtdcFlowMessageCancelField *pFlowMessageCancel) 
		{
			m_owner->callOnRtnFlowMessageCancel(pFlowMessageCancel);
		}

		///成交回报
		virtual void OnRtnTrade(CQdpFtdcTradeField *pTrade) { m_owner->callOnRtnTrade(pTrade); }

		///报单回报
		virtual void OnRtnOrder(CQdpFtdcOrderField *pOrder) { m_owner->callOnRtnOrder(pOrder); }

		///报单录入错误回报
		virtual void OnErrRtnOrderInsert(CQdpFtdcInputOrderField *pInputOrder, CQdpFtdcRspInfoField *pRspInfo) 
		{
			m_owner->callOnErrRtnOrderInsert(pInputOrder, pRspInfo);
		}

		///报单操作错误回报
		virtual void OnErrRtnOrderAction(CQdpFtdcOrderActionField *pOrderAction, CQdpFtdcRspInfoField *pRspInfo) 
		{
			m_owner->callOnErrRtnOrderAction(pOrderAction, pRspInfo);
		}

		///合约交易状态通知
		virtual void OnRtnInstrumentStatus(CQdpFtdcInstrumentStatusField *pInstrumentStatus) 
		{
			m_owner->callOnRtnInstrumentStatus(pInstrumentStatus);
		}

		///账户出入金回报
		virtual void OnRtnInvestorAccountDeposit(CQdpFtdcInvestorAccountDepositResField *pInvestorAccountDepositRes) 
		{
			m_owner->callOnRtnInvestorAccountDeposit(pInvestorAccountDepositRes);
		}

		///QDP警告消息通知
		virtual void OnRtnMessageNotify(CQdpFtdcMessageNotifyInfoField *pMessageNotifyInfo) 
		{
			m_owner->callOnRtnMessageNotify(pMessageNotifyInfo);
		}

		///报单查询应答
		virtual void OnRspQryOrder(CQdpFtdcOrderField *pOrder, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryOrder(pOrder, pRspInfo, nRequestID, bIsLast);
		}

		///成交单查询应答
		virtual void OnRspQryTrade(CQdpFtdcTradeField *pTrade, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryTrade(pTrade, pRspInfo, nRequestID, bIsLast);
		}

		///可用投资者账户查询应答
		virtual void OnRspQryUserInvestor(CQdpFtdcRspUserInvestorField *pRspUserInvestor, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryUserInvestor(pRspUserInvestor, pRspInfo, nRequestID, bIsLast);
		}

		///投资者资金账户查询应答
		virtual void OnRspQryInvestorAccount(CQdpFtdcRspInvestorAccountField *pRspInvestorAccount, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorAccount(pRspInvestorAccount, pRspInfo, nRequestID, bIsLast);
		}

		///合约查询应答
		virtual void OnRspQryInstrument(CQdpFtdcRspInstrumentField *pRspInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInstrument(pRspInstrument, pRspInfo, nRequestID, bIsLast);
		}

		///交易所查询应答
		virtual void OnRspQryExchange(CQdpFtdcRspExchangeField *pRspExchange, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryExchange(pRspExchange, pRspInfo, nRequestID, bIsLast);
		}

		///投资者持仓查询应答
		virtual void OnRspQryInvestorPosition(CQdpFtdcRspInvestorPositionField *pRspInvestorPosition, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorPosition(pRspInvestorPosition, pRspInfo, nRequestID, bIsLast);
		}

		///订阅主题应答
		virtual void OnRspSubscribeTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspSubscribeTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		}

		///主题查询应答
		virtual void OnRspQryTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		}

		///投资者手续费率查询应答
		virtual void OnRspQryInvestorFee(CQdpFtdcInvestorFeeField *pInvestorFee, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorFee(pInvestorFee, pRspInfo, nRequestID, bIsLast);
		}

		///投资者保证金率查询应答
		virtual void OnRspQryInvestorMargin(CQdpFtdcInvestorMarginField *pInvestorMargin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryInvestorMargin(pInvestorMargin, pRspInfo, nRequestID, bIsLast);
		}

		///交易所时间偏差查询应答
		virtual void OnRspQryExchangeDiffTime(CQdpFtdcRspExchangeDiffTimeField *pRspExchangeDiffTime, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryExchangeDiffTime(pRspExchangeDiffTime, pRspInfo, nRequestID, bIsLast);
		}

		///实时行情查询应答
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
		
		///获取系统版本号
		///@param nMajorVersion 主版本号
		///@param nMinorVersion 子版本号
		///@return 系统标识字符串
		static const String^ GetVersion(int &nMajorVersion, int &nMinorVersion);

		///删除接口对象本身
		///@remark 不再使用本接口对象时,调用该函数删除接口对象
		void Release();

		///初始化
		///@remark 初始化运行环境,只有调用后,接口才开始工作
		void Init();

		///等待接口线程结束运行
		///@return 线程退出代码
		void Join();

		///获取当前交易日
		///@retrun 获取到的交易日
		///@remark 只有登录成功后,才能得到正确的交易日
		const String^ GetTradingDay();

		///注册前置机网络地址
		///@param pszFrontAddress：前置机网络地址。
		///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
		///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
		void RegisterFront(String^ FrontServer);

		///注册名字服务器网络地址
		///@param pszNsAddress：名字服务器网络地址。
		///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
		///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
		///@remark RegisterFront优先于RegisterNameServer
		void RegisterNameServer(String^ NameServer);

		///注册回调接口
		///@param pSpi 派生自回调接口类的实例
		void RegisterSpi(CLRCQdpFtdcTraderSpi^ Spi);

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
		int RegisterCertificateFile(const char *pszCertFileName, const char *pszKeyFileName, const char *pszCaFileName, const char *pszKeyFilePassword);

		///订阅私有流。
		///@param nResumeType 私有流重传方式  
		///        QDP_TERT_RESTART:从本交易日开始重传
		///        QDP_TERT_RESUME:从上次收到的续传
		///        QDP_TERT_QUICK:只传送登录后私有流的内容
		void SubscribePrivateTopic(CLRQDP_TE_RESUME_TYPE nResumeType);

		///订阅公共流。
		///@param nResumeType 公共流重传方式  
		///        QDP_TERT_RESTART:从本交易日开始重传
		///        QDP_TERT_RESUME:从上次收到的续传
		///        QDP_TERT_QUICK:只传送登录后公共流的内容
		///@remark 该方法要在Init方法前调用。若不调用则不会收到公共流的数据。
		void SubscribePublicTopic(CLRQDP_TE_RESUME_TYPE nResumeType);

		///订阅交易员流。
		///@param nResumeType 交易员流重传方式  
		///        QDP_TERT_RESTART:从本交易日开始重传
		///        QDP_TERT_RESUME:从上次收到的续传
		///        QDP_TERT_QUICK:只传送登录后交易员流的内容
		///@remark 该方法要在Init方法前调用。若不调用则不会收到交易员流的数据。
		void SubscribeUserTopic(CLRQDP_TE_RESUME_TYPE nResumeType);

		///设置心跳超时时间。
		///@param timeout 心跳超时时间(秒)  
		void SetHeartbeatTimeout(unsigned int timeout);

		///打开请求日志文件
		///@param pszReqLogFileName 请求日志文件名  
		///@return 0 操作成功
		///@return -1 打开日志文件失败
		int OpenRequestLog(String^ ReqLogFileName);

		///打开应答日志文件
		///@param pszRspLogFileName 应答日志文件名  
		///@return 0 操作成功
		///@return -1 打开日志文件失败
		int OpenResponseLog(String^ RspLogFileName);

		///用户登录请求
		int ReqUserLogin(CLRCQdpFtdcReqUserLoginField^ ReqUserLogin, int nRequestID);

		///用户退出请求
		int ReqUserLogout(CLRCQdpFtdcReqUserLogoutField^ ReqUserLogout, int nRequestID);

		///用户密码修改请求
		int ReqUserPasswordUpdate(CLRCQdpFtdcUserPasswordUpdateField^ UserPasswordUpdate, int nRequestID);

		///报单录入请求
		int ReqOrderInsert(CLRCQdpFtdcInputOrderField^ InputOrder, int nRequestID);

		///报单操作请求
		int ReqOrderAction(CLRCQdpFtdcOrderActionField^ OrderAction, int nRequestID);

		///报单查询请求
		int ReqQryOrder(CLRCQdpFtdcQryOrderField^ QryOrder, int nRequestID);

		///成交单查询请求
		int ReqQryTrade(CLRCQdpFtdcQryTradeField^ QryTrade, int nRequestID);

		///可用投资者账户查询请求
		int ReqQryUserInvestor(CLRCQdpFtdcQryUserInvestorField^ QryUserInvestor, int nRequestID);

		///投资者资金账户查询请求
		int ReqQryInvestorAccount(CLRCQdpFtdcQryInvestorAccountField^ QryInvestorAccount, int nRequestID);

		///合约查询请求
		int ReqQryInstrument(CLRCQdpFtdcQryInstrumentField^ QryInstrument, int nRequestID);

		///交易所查询请求
		int ReqQryExchange(CLRCQdpFtdcQryExchangeField^ QryExchange, int nRequestID);

		///投资者持仓查询请求
		int ReqQryInvestorPosition(CLRCQdpFtdcQryInvestorPositionField^ QryInvestorPosition, int nRequestID);

		///订阅主题请求
		int ReqSubscribeTopic(CLRCQdpFtdcDisseminationField^ Dissemination, int nRequestID);

		///主题查询请求
		int ReqQryTopic(CLRCQdpFtdcDisseminationField^ Dissemination, int nRequestID);

		///投资者手续费率查询请求
		int ReqQryInvestorFee(CLRCQdpFtdcQryInvestorFeeField^ QryInvestorFee, int nRequestID);

		///投资者保证金率查询请求
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
		///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		virtual void OnFrontConnected() { m_owner->callOnFrontConnected(); };

		///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		///@param nReason 错误原因
		///        0x1001 网络读失败
		///        0x1002 网络写失败
		///        0x2001 接收心跳超时
		///        0x2002 发送心跳失败
		///        0x2003 收到错误报文
		virtual void OnFrontDisconnected(int nReason) { m_owner->callOnFrontDisconnected(nReason); };

		///心跳超时警告。当长时间未收到报文时，该方法被调用。
		///@param nTimeLapse 距离上次接收报文的时间
		virtual void OnHeartBeatWarning(int nTimeLapse) { m_owner->callOnHeartBeatWarning(nTimeLapse); };

		///报文回调开始通知。当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
		///@param nTopicID 主题代码（如私有流、公共流、行情流等）
		///@param nSequenceNo 报文序号
		virtual void OnPackageStart(int nTopicID, int nSequenceNo) { m_owner->callOnPackageStart(nTopicID, nSequenceNo); };

		///报文回调结束通知。当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
		///@param nTopicID 主题代码（如私有流、公共流、行情流等）
		///@param nSequenceNo 报文序号
		virtual void OnPackageEnd(int nTopicID, int nSequenceNo) { m_owner->callOnPackageEnd(nTopicID, nSequenceNo); };

		//新增多播心跳接口 add by zbz 20150304
		virtual void  OnMultiHeartbeat(char *CurrTime, char *MultiCastIP) { m_owner->callOnMultiHeartbeat(CurrTime, MultiCastIP); };

		//当广播收到值得时候，回调函数被调用，返回qmdata
		virtual void UdpMarketData(CQdpFtdcDepthMarketDataField *qmdata) { m_owner->callUdpMarketData(qmdata); };

		///错误应答
		virtual void OnRspError(CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) { m_owner->callOnRspError(pRspInfo, nRequestID, bIsLast); };

		///用户登录应答
		virtual void OnRspUserLogin(CQdpFtdcRspUserLoginField *pRspUserLogin, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
		};

		///用户退出应答
		virtual void OnRspUserLogout(CQdpFtdcRspUserLogoutField *pRspUserLogout, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspUserLogout(pRspUserLogout, pRspInfo, nRequestID, bIsLast);
		};

		///订阅主题应答
		virtual void OnRspSubscribeTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspSubscribeTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		};

		///主题查询应答
		virtual void OnRspQryTopic(CQdpFtdcDisseminationField *pDissemination, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspQryTopic(pDissemination, pRspInfo, nRequestID, bIsLast);
		};

		///深度行情通知
		virtual void OnRtnDepthMarketData(CQdpFtdcDepthMarketDataField *pDepthMarketData) { m_owner->callOnRtnDepthMarketData(pDepthMarketData); };

		///订阅合约的相关信息
		virtual void OnRspSubMarketData(CQdpFtdcSpecificInstrumentField *pSpecificInstrument, CQdpFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
		{
			m_owner->callOnRspSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
		};

		///退订合约的相关信息
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

		///获取系统版本号
		///@param nMajorVersion 主版本号
		///@param nMinorVersion 子版本号
		///@return 系统标识字符串
		static const String^ GetVersion(int &nMajorVersion, int &nMinorVersion);

		///删除接口对象本身
		///@remark 不再使用本接口对象时,调用该函数删除接口对象
		void Release();

		//多播设置开关
		void SetMultiCast(bool bMultiCast);

		//注册多播地址
		void RegTopicMultiAddr(String^ MultiAddr);

		///初始化
		///@remark 初始化运行环境,只有调用后,接口才开始工作
		void Init();

		///等待接口线程结束运行
		///@return 线程退出代码
		int Join();

		///获取当前交易日
		///@retrun 获取到的交易日
		///@remark 只有登录成功后,才能得到正确的交易日
		const String^ GetTradingDay();

		///注册前置机网络地址
		///@param pszFrontAddress：前置机网络地址。
		///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:17001”。 
		///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”17001”代表服务器端口号。
		void RegisterFront(String^ FrontAddress);

		///注册名字服务器网络地址
		///@param pszNsAddress：名字服务器网络地址。
		///@remark 网络地址的格式为：“protocol://ipaddress:port”，如：”tcp://127.0.0.1:12001”。 
		///@remark “tcp”代表传输协议，“127.0.0.1”代表服务器地址。”12001”代表服务器端口号。
		///@remark RegisterFront优先于RegisterNameServer
		void RegisterNameServer(String^ NsAddress);

		///共享内存取值
		///@param CQdpFtdcShmDepthMarketDataField  传入参数
		///@param CQdpFtdcDepthMarketDataField 查询到的行情值
		///@return 0 操作成功
		///@return -1 打开日志文件失败
		void ShmMarketData(CLRCQdpFtdcShmDepthMarketDataField reqfield, CLRCQdpFtdcDepthMarketDataField defdata);

		///建立UDP连接
		///@param  udpip广播地址
		///@return 0 操作成功
		///@return -1 读取UDP失败
		void setudpchannel(String^ UdpIP);

		///注册回调接口
		///@param pSpi 派生自回调接口类的实例
		void RegisterSpi(CLRCQdpFtdcMduserSpi^ Spi);

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
		int RegisterCertificateFile(String^ CertFileName, String^ KeyFileName, String^ CaFileName, String^ KeyFilePassword);

		///订阅市场行情。
		///@param nTopicID 市场行情主题  
		///@param nResumeType 市场行情重传方式  
		///        QDP_TERT_RESTART:从本交易日开始重传
		///        QDP_TERT_RESUME:从上次收到的续传(非订阅全部合约时，不支持续传模式)
		///        QDP_TERT_QUICK:先传送当前行情快照,再传送登录后市场行情的内容
		///@remark 该方法要在Init方法前调用。若不调用则不会收到私有流的数据。
		void SubscribeMarketDataTopic(int nTopicID, CLRQDP_TE_RESUME_TYPE ResumeType) ;

		///订阅合约行情。
		///@param ppInstrumentID 合约ID  
		///@param nCount 要订阅/退订行情的合约个数
		///@remark 
		int SubMarketData(array<String^>^ InstrumentID);

		///退订合约行情。
		///@param ppInstrumentID 合约ID  
		///@param nCount 要订阅/退订行情的合约个数
		///@remark 
		//int UnSubMarketData(char *ppInstrumentID[], int nCount);

		///设置心跳超时时间。
		///@param timeout 心跳超时时间(秒)  
		void SetHeartbeatTimeout(unsigned int timeout);

		///用户登录请求
		int ReqUserLogin(CLRCQdpFtdcReqUserLoginField^ ReqUserLogin, int nRequestID);

		///用户退出请求
		int ReqUserLogout(CLRCQdpFtdcReqUserLogoutField ReqUserLogout, int nRequestID);

		///订阅主题请求
		int ReqSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID);

		///主题查询请求
		int ReqQryTopic(CLRCQdpFtdcDisseminationField Dissemination, int nRequestID);

		///Topic查询
		//int ReqTopicSearch(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID);

		///退订合约的相关信息
		int ReqUnSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, int nRequestID);

		//启动多播
		//在无法登录服务器的情况下，调用此接口可以接收组播行情
		//在可以登录的情况下无需调用此接口
		//@param TradingDay 交易日，在没有登录的情况下，可以是自然日，但是要注意交易所的交易日
		void ActiveMultiMarketData(String^ TradingDay);

		CQdpFtdcMduserApi *m_pNativeApi;
	};
}

