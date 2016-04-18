#pragma once
#pragma managed

#include <stdio.h>
#include <math.h>
#include "QdpFtdcUserApiStruct.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace CLRQdpApi
{
	public enum class CLRQDP_FTFAIL_REASON
	{
		NORMAL_DISCONN=0x0,
		NET_RD_FAIL=0x1001,
		NET_WR_FAIL=0x1002,
		RCV_HTB_TMOUT=0x2001,
		SED_HTB_FAIL=0x2002,
		RCV_ERR_PKG=0x2003
	};
	
	public enum class CLRQDP_TE_RESUME_TYPE
	{
		QDP_TERT_RESTART = 0,
		QDP_TERT_RESUME = 1,
		QDP_TERT_QUICK = 2
	};

	public enum class CLRQDP_TSS
	{
		DIALOG = 1,                             ///�Ի���
		PRIVATE = 2,                            ///˽����
		PUBLIC = 3,                             ///������
		QUERY = 4,                              ///��ѯ
		USER = 5                                ///�û�˽����
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcVolumeConditionType��һ���ɽ�����������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_VC :char
	{
		AV = '1',                         ///�κ�����
		MV = '2',                         ///��С����
		CV = '3'                          ///ȫ������
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcForceCloseReasonType��һ��ǿƽԭ������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_FCR :char
	{
		NotForceClose = '0',              ///��ǿƽ
		LackDeposit = '1',                ///�ʽ���
		ClientOverPositionLimit = '2',    ///�ͻ�����
		MemberOverPositionLimit = '3',    ///��Ա����
		NotMultiple = '4'                 ///�ֲַ�������
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcInstrumentStatusType��һ����Լ����״̬����
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_IS : char
	{
		BeforeTrading = '0',              ///����ǰ
		NoTrading = '1',                  ///�ǽ���
		Continous = '2',                  ///��������
		AuctionOrdering = '3',            ///���Ͼ��۱���
		AuctionBalance = '4',             ///���Ͼ��ۼ۸�ƽ��
		AuctionMatch = '5',               ///���Ͼ��۴��
		Closed = '6'                      ///����
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOffsetFlagType��һ����ƽ��־����
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OF : char
	{
		Open = '0',                       ///����
		Close = '1',                      ///ƽ��
		ForceClose = '2',                 ///ǿƽ
		CloseToday = '3',                 ///ƽ��
		CloseYesterday = '4'              ///ƽ��
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOrderPriceTypeType��һ�������۸���������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OPT : char
	{
		AnyPrice = '1',                   ///�����
		LimitPrice = '2',                 ///�޼�
		BestPrice = '3',                  ///���ż�
		FiveLevelPrice = '4'              ///�嵵��
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOrderStatusType��һ������״̬����
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OS : char
	{
		AllTraded = '0',                  ///ȫ���ɽ�
		PartTradedQueueing = '1',         ///���ֳɽ����ڶ�����
		PartTradedNotQueueing = '2',      ///���ֳɽ����ڶ�����
		NoTradeQueueing = '3',            ///δ�ɽ����ڶ�����
		NoTradeNotQueueing = '4',         ///δ�ɽ����ڶ�����
		Canceled = '5',                   ///����
		AcceptedNoReply = '6'             ///�����ѱ��뽻����δӦ��
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcUserTypeType��һ���û���������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_UT : char
	{
		Person = '1',                     ///��Ȼ��
		Product = '2',                    ///��Ʋ�Ʒ
		Manager = '3',                    ///�ڻ���˾����Ա
		Seat = '4'                        ///ϯλ
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcTradingRightType��һ������Ȩ������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_TR : char
	{
		Allow = '0',                      ///���Խ���
		CloseOnly = '1',                  ///ֻ��ƽ��
		Forbidden = '2'                   ///���ܽ���
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcTimeConditionType��һ����Ч����������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_TC : char
	{
		IOC = '1',                        ///������ɣ�������
		GFS = '2',                        ///������Ч
		GFD = '3',                        ///������Ч
		GTD = '4',                        ///ָ������ǰ��Ч
		GTC = '5',                        ///����ǰ��Ч
		GFA = '6'                         ///���Ͼ�����Ч
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOrderSourceType��һ��������Դ����
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_ODS : char
	{
		Participant = '0',                ///���Բ�����
		Administrator = '1'               ///���Թ���Ա
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcDirectionType��һ��������������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_D : char
	{
		Buy = '0',                        ///��
		Sell = '1'                        ///��               
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcCurrencyType��һ����������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_C : char
	{
		RMB = '1',                        ///�����
		USD = '2'                         ///��Ԫ
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcAccountDirectionType��һ�������������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_AD : char
	{
		In = '1',                         ///���
		Out = '2'                         ///����
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcClientHedgeFlagType��һ���ͻ�Ͷ���ױ���־����
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_CHF : char
	{
		Speculation = '1',                ///Ͷ��
		Arbitrage = '2',                  ///����
		Hedge = '3',                      ///�ױ�
		MarketMaker = '4'                 ///������
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcActionFlagType��һ��������־����
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_AF : char
	{
		Delete = '0',                     ///ɾ��
		Suspend = '1',                    ///����
		Active = '2',                     ///����
		Modify = '3'                      ///�޸�
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcPositionTypeType��һ���ֲ���������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_PT : char
	{
		Net = '1',                        ///���ֲ�
		Gross = '2'                       ///�ۺϳֲ�
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOptionsTypeType��һ����Ȩ��������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OT : char
	{
		NotOptions = '0',                 ///����Ȩ
		CallOptions = '1',                ///����
		PutOptions = '2'                  ///����
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcIsActiveType��һ���Ƿ��Ծ����
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_UIA : char
	{
		NoActive = '0',                   ///����Ծ
		Active = '1'                      ///��Ծ
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcBusinessTypeType��һ��ҵ���������
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_BT : char
	{
		Normal = '1',                     ///��ͨ
		Cancel = '2',                     ///����
		AppliedForRedeemed = '3',         ///ETF����
		FiveLevelIOC = '4',               ///�����嵵��ʱ�ɽ�ʣ�೷��
		FiveLevelGFD = '5',               ///�����嵵��ʱ�ɽ�ʣ��ת�޼�
		BestPriceIOC = '6',               ///��ʱ�ɽ�ʣ�೷��
		FOK = '7',                        ///ȫ��ɽ�����
		SelfGFD = '8',                    ///�������ż۸�
		CpGFD = '9'                       ///�Է����ż۸�
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcReqUserLoginField                                                    ///ϵͳ�û���¼����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�����û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ Password;                          ///����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ UserProductInfo;                   ///�û��˲�Ʒ��Ϣ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ InterfaceProductInfo;              ///�ӿڶ˲�Ʒ��Ϣ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ ProtocolInfo;                      ///Э����Ϣ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ IPAddress;                         ///IP��ַ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ MacAddress;                        ///Mac��ַ
		System::Int32 DataCenterID;																		///�������Ĵ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ OneTimePassword;                   ///��̬����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ ClientIPAddress;                   ///�ն�IP��ַ
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspUserLoginField                                                    ///ϵͳ�û���¼Ӧ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�����û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ LoginTime;                          ///��¼�ɹ�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ MaxOrderLocalID;                   ///�û�������󱨵���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 61)]String^ TradingSystemName;                 ///����ϵͳ����
		System::Int32 DataCenterID;                                                                     ///�������Ĵ���
		System::Int32 PrivateFlowSize;                                                                  ///��Ա˽������ǰ����
		System::Int32 UserFlowSize;                                                                     ///����Ա˽������ǰ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcReqUserLogoutField                                                   ///�û��ǳ�����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�����û�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspUserLogoutField                                                   ///�û��ǳ�Ӧ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�����û�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcForceUserExitField                                                   ///ǿ���û��˳�
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�����û�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcUserPasswordUpdateField                                              ///�û������޸�
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�����û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ OldPassword;                       ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ NewPassword;                       ///������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInputOrderField                                                      ///���뱨��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///ϵͳ�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///�û����ر�����
		System::Char OrderPriceType;                     												///��������
		System::Char Direction;																			///��������
		System::Char OffsetFlag;																		///��ƽ��־
		System::Char HedgeFlag;																			///Ͷ���ױ���־
		System::Double LimitPrice;																		///�۸�
		System::Int32 Volume;																			///����
		System::Char TimeCondition;																		///��Ч������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ GTDDate;                            ///GTD����
		System::Char VolumeCondition;																	///�ɽ�������
		System::Int32 MinVolume;																		///��С�ɽ���
		System::Double StopPrice;																		///ֹ���
		System::Char ForceCloseReason;																	///ǿƽԭ��
		System::Int32 IsAutoSuspend;																	///�Զ������־
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ BusinessUnit;                      ///ҵ��Ԫ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 65)]String^ UserCustom;                        ///�û��Զ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]String^ BranchID;                           ///Ӫҵ������
		System::Int32 RecNum;																			///��¼���
		System::Char BusinessType;																		///ҵ�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcOrderActionField                                                     ///��������
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderActiconLocalID;           ///���α��������ı��ر��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///�����������ı��ر��
		System::Char ActionFlag;																		///����������־
		System::Double LimitPrice;																		///�۸�
		System::Int32 VolumeChange;																		///�����仯
		System::Int32 RecNum;																			///��¼���
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMemDbField                                                           ///�ڴ����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 61)]String^ MemTableName;                      ///�ڴ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInfoField                                                         ///��Ӧ��Ϣ
	{
	public:
		System::Int32 ErrorID;																					///�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]String^ ErrorMsg;                          ///������Ϣ
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryOrderField                                                        ///������ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryTradeField                                                        ///�ɽ���ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ TradeID;                           ///�ɽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInstrumentField                                                   ///��Լ��ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///��Ʒ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInstrumentField                                                   ///��Լ��ѯӦ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///��Ʒ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ ProductName;                       ///Ʒ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ InstrumentName;                    ///��Լ����
		System::Int32 DeliveryYear;																		///�������
		System::Int32 DeliveryMonth;																	///������
		System::Int32 MaxLimitOrderVolume;																///�޼۵�����µ���
		System::Int32 MinLimitOrderVolume;																///�޼۵���С�µ���
		System::Int32 MaxMarketOrderVolume;																///�м۵�����µ���
		System::Int32 MinMarketOrderVolume;																///�м۵���С�µ���
		System::Int32 VolumeMultiple;																	///��������
		System::Double PriceTick;																		///���۵�λ
		System::Char Currency;																			///����
		System::Int32 LongPosLimit;																		///��ͷ�޲�
		System::Int32 ShortPosLimit;																	///��ͷ�޲�
		System::Double LowerLimitPrice;																	///��ͣ���
		System::Double UpperLimitPrice;																	///��ͣ���
		System::Double PreSettlementPrice;																///���ս����
		System::Char InstrumentStatus;																	///��Լ����״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ CreateDate;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ OpenDate;                           ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ ExpireDate;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ StartDelivDate;                     ///��ʼ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ EndDelivDate;                       ///��󽻸���
		System::Double BasisPrice;																		///���ƻ�׼��
		System::Int32 IsTrading;																		///��ǰ�Ƿ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ UnderlyingInstrID;                 ///������Ʒ����
		System::Int32 UnderlyingMultiple;																///������Ʒ����
		System::Char PositionType;																		///�ֲ�����
		System::Double StrikePrice;																		///ִ�м�
		System::Char OptionsType;																		///��Ȩ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInstrumentStatusField                                                ///��Լ״̬
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///��Ʒ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ ProductName;                       ///Ʒ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ InstrumentName;                    ///��Լ����
		System::Int32 DeliveryYear;																		///�������
		System::Int32 DeliveryMonth;																	///������
		System::Int32 MaxLimitOrderVolume;																///�޼۵�����µ���
		System::Int32 MinLimitOrderVolume;																///�޼۵���С�µ���
		System::Int32 MaxMarketOrderVolume;																///�м۵�����µ���
		System::Int32 MinMarketOrderVolume;																///�м۵���С�µ���
		System::Int32 VolumeMultiple;																	///��������
		System::Double PriceTick;																		///���۵�λ
		System::Char Currency;																			///����
		System::Int32 LongPosLimit;																		///��ͷ�޲�
		System::Int32 ShortPosLimit;																	///��ͷ�޲�
		System::Double LowerLimitPrice;																	///��ͣ���
		System::Double UpperLimitPrice;																	///��ͣ���
		System::Double PreSettlementPrice;																///���ս����
		System::Char InstrumentStatus;																	///��Լ����״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ CreateDate;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ OpenDate;                           ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ ExpireDate;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ StartDelivDate;                     ///��ʼ������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ EndDelivDate;                       ///��󽻸���
		System::Double BasisPrice;																		///���ƻ�׼��
		System::Int32 IsTrading;																		///��ǰ�Ƿ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ UnderlyingInstrID;                 ///������Ʒ����
		System::Int32 UnderlyingMultiple;																///������Ʒ����
		System::Char PositionType;																		///�ֲ�����
		System::Double StrikePrice;																		///ִ�м�
		System::Char OptionsType;																		///��Ȩ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorAccountField                                              ///Ͷ�����ʽ��ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInvestorAccountField                                              ///Ͷ�����ʽ�Ӧ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���ù�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ AccountID;                         ///�ʽ��˺�
		System::Double PreBalance;																		///�ϴν���׼����
		System::Double PreAvailable;																	///���տ����ʽ�
		System::Double Deposit;																			///�����
		System::Double Withdraw;																		///������
		System::Double Margin;																			///ռ�ñ�֤��
		System::Double Premium;																			///��ȨȨ������֧
		System::Double Fee;																				///������
		System::Double FrozenMargin;																	///����ı�֤��
		System::Double FrozenPremium;																	///�����Ȩ����
		System::Double FrozenFee;																		///�����������
		System::Double CloseProfit;																		///ƽ��ӯ��
		System::Double PositionProfit;																	///�ֲ�ӯ��
		System::Double Available;																		///�����ʽ�
		System::Double Balance;																			///����׼����
		System::Double LongMargin;																		///��ͷռ�ñ�֤��
		System::Double ShortMargin;																		///��ͷռ�ñ�֤��
		System::Double LongFrozenMargin;																///��ͷ���ᱣ֤��
		System::Double ShortFrozenMargin;																///��ͷ���ᱣ֤��
		System::Double DynamicRights;																	///��̬Ȩ��
		System::Double Risk;																			///���ն�
		System::Double OtherFee;																		///��������
		System::Double Mortage;																			///��Ѻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^ Currency;                           ///����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryUserInvestorField                                                 ///����Ͷ���߲�ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspUserInvestorField                                                 ///����Ͷ����Ӧ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryTradingCodeField                                                  ///���ױ����ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspTradingCodeField                                                  ///���ױ���Ӧ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ AccountID;                         ///�ʽ��˺�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///��Ա���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///�ͻ�����
		System::Char ClientRight;																		///�ͻ�Ȩ�޴���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]String^ ClientType;                         ///�ͻ�����
		System::Char ClientHedgeFlag;																	///�ͻ���ֵ����
		System::Char IsActive;																			///�Ƿ��Ծ
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryExchangeField                                                     ///��������ѯ����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspExchangeField                                                     ///��������ѯӦ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ ExchangeName;                      ///����������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorPositionField												///Ͷ���ֲֲ߳�ѯ����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���ߴ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInvestorPositionField                                             ///Ͷ���ֲֲ߳�ѯӦ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���ߴ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///��Ա���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///�ͻ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		System::Char Direction;																			///��������
		System::Char HedgeFlag;																			///Ͷ���ױ���־
		System::Double UsedMargin;																		///ռ�ñ�֤��
		System::Int32 Position;																			///���ճֲ���
		System::Double PositionCost;																	///���ճֲֳɱ�
		System::Int32 YdPosition;																		///���ճֲ���
		System::Double YdPositionCost;																	///���ճֲֳɱ�
		System::Double FrozenMargin;																	///����ı�֤��
		System::Int32 FrozenPosition;																	///���ֶ���ֲ�
		System::Int32 FrozenClosing;																	///ƽ�ֶ���ֲ�
		System::Double FrozenPremium;																	///�����Ȩ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ LastTradeID;                       ///���һ�ʳɽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^ LastOrderLocalID;                  ///���һ�ʱ��ر������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^ Currency;                           ///����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryUserField                                                         ///�û���ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ StartUserID;                       ///�����û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ EndUserID;                         ///�����û�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcUserField                                                            ///�û�
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ Password;                          ///�û���¼����
		System::Char IsActive;																			///�Ƿ��Ծ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ UserName;                          ///�û�����
		System::Char UserType;																			///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ Department;                        ///Ӫҵ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]String^ GrantFuncSet;                       ///��Ȩ���ܼ�
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorFeeField													///Ͷ�����������ʲ�ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		System::Char HedgeFlag;																			///Ͷ���ױ���־
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInvestorFeeField                                                     ///Ͷ������������
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		System::Char HedgeFlag;																			///Ͷ���ױ���־
		System::Double OpenFeeRate;                                                                     ///���������Ѱ�����
		System::Double OpenFeeAmt;                                                                      ///���������Ѱ�����
		System::Double OffsetFeeRate;                                                                   ///ƽ�������Ѱ�����
		System::Double OffsetFeeAmt;                                                                    ///ƽ�������Ѱ�����
		System::Double OTFeeRate;                                                                       ///ƽ��������Ѱ�����
		System::Double OTFeeAmt;                                                                        ///ƽ��������Ѱ�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorMarginField                                               ///Ͷ���߱�֤���ʲ�ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		System::Char HedgeFlag;																			///Ͷ���ױ���־
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInvestorMarginField                                                  ///Ͷ���߱�֤����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		System::Char HedgeFlag;																			///Ͷ���ױ���־
		System::Double LongMarginRate;                                                                  ///��ͷռ�ñ�֤�𰴱���
		System::Double LongMarginAmt;                                                                   ///��ͷ��֤������
		System::Double ShortMarginRate;                                                                 ///��ͷռ�ñ�֤�𰴱���
		System::Double ShortMarginAmt;                                                                  ///��ͷ��֤������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryExchangeDiffTimeField                                             ///������ʱ��ƫ���ѯ����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspExchangeDiffTimeField                                             ///������ʱ��ƫ���ѯӦ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ ExchangeTime;                       ///������ʱ��
		System::Int32 DiffSnd;                                                                          ///ƫ��ʱ��
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcTradeField                                                           ///�ɽ�
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///��Ա���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ SeatID;                            ///�µ�ϯλ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ TradeID;                           ///�ɽ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///���ر������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		System::Char Direction;																			///��������
		System::Char OffsetFlag;																		///��ƽ��־
		System::Char HedgeFlag;																			///Ͷ���ױ���־
		System::Double TradePrice;                                                                      ///�ɽ��۸�
		System::Int32 TradeVolume;                                                                      ///�ɽ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradeTime;                          ///�ɽ�ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ClearingPartID;                    ///�����Ա���
		System::Double TradeAmnt;                                                                       ///�ɽ����
		System::Int32 RecNum;                                                                           ///��¼���
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcOrderField                                                           ///����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///�������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///���ر������
		System::Char OrderPriceType;																	///��������
		System::Char Direction;																			///��������
		System::Char OffsetFlag;																		///��ƽ��־
		System::Char HedgeFlag;																			///Ͷ���ױ���־
		System::Double LimitPrice;                                                                      ///�۸�
		System::Int32 Volume;                                                                           ///����
		System::Char TimeCondition;																		///��Ч������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ GTDDate;                            ///GTD����
		System::Char VolumeCondition;																	///�ɽ�������
		System::Int32 MinVolume;                                                                        ///��С�ɽ���
		System::Double StopPrice;                                                                       ///ֹ���
		System::Char ForceCloseReason;																	///ǿƽԭ��
		System::Int32 IsAutoSuspend;                                                                    ///�Զ������־
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ BussinessUnit;                     ///ҵ��Ԫ
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 65)]String^ UserCustom;                        ///�û��Զ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]String^ BranchID;                           ///Ӫҵ������
		System::Int32 RecNum;                                                                           ///��¼���
		System::Char BusinessType;																		///ҵ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///��Ա���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///�ͻ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ SeatID;                            ///�µ�ϯλ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ InsertTime;                         ///����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^ OrderLocalID;                      ///���ر������
		System::Char OrderSource;																		///������Դ
		System::Char OrderStatus;																		///����״̬
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ CancleTime;                         ///����ʱ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ CancelUserID;                      ///�����û����
		System::Int32 VolumeTraded;                                                                     ///��ɽ�����
		System::Int32 VolumeRemain;                                                                     ///ʣ������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcFlowMessageCancelField												///����������
	{
	public:
		System::Int32 SequenceSeries;                                                                   ///����ϵ�к�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;							///������
		System::Int32 DataCenterID;                                                                     ///�������Ĵ���
		System::Int32 StartSequenceNo;                                                                  ///������ʼ���к�
		System::Int32 EndSequenceNo;                                                                    ///���˽������к�
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcDisseminationField													///��Ϣ�ַ�
	{
	public:
		System::Int32 SequenceSeries;                                                                   ///����ϵ�к�
		System::Int32 SequenceNo;                                                                       ///���к�
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInvestorAccountDepositResField                                       ///�������
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ AccountID;                         ///�ʽ��ʺ�
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ AccountSeqNo;                      ///�ʽ���ˮ��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ AccountInsideSeqNo;                ///�������������ʽ���ˮ��
		System::Double Amount;                                                                          ///���
		System::Char AmountDirection;																	///�������
		System::Double Available;                                                                       ///�����ʽ�
		System::Double Balance;                                                                         ///����׼����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�û�����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMessageNotifyInfoField                                               ///QDP������Ϣ֪ͨ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///���͹�˾���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///�޸��û����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///Ͷ���߱��
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		System::Int32 Nums;                                                                             ///�ۼӴ���
		System::Char BusinessType;																		///ҵ�����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]String^ WarnMsg;                           ///������Ϣ
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBaseField                                                  ///�����������
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ SettlementGroupID;                  ///���������
		System::Int32 SettlementID;                                                                     ///������
		System::Double PreSettlementPrice;                                                              ///�����
		System::Double PreClosePrice;                                                                   ///������
		System::Double PreOpeninterest;                                                                 ///��ֲ���
		System::Double PreDelta;                                                                        ///����ʵ��
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataStaticField                                                ///���龲̬����
	{
	public:
		System::Double OpenPrice;                                                                       ///����
		System::Double HighestPrice;                                                                    ///��߼�
		System::Double LowestPrice;                                                                     ///��ͼ�
		System::Double ClosePrice;                                                                      ///������
		System::Double UpperLimitPrice;                                                                 ///��ͣ���
		System::Double LowerLimitPrice;                                                                 ///��ͣ���
		System::Double SettlementPrice;                                                                 ///�����
		System::Double CurrDelta;                                                                       ///����ʵ��
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataLastMatchField                                             ///�������³ɽ�����
	{
	public:
		System::Double LastPrice;                                                                       ///���¼�
		System::Int32 Volume;                                                                           ///����
		System::Double Turnover;                                                                        ///�ɽ����
		System::Double Openinterest;                                                                    ///�ֲ���
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBestPriceField                                             ///�������ż�����
	{
	public:
		System::Double BidPrice1;                                                                       ///�����һ
		System::Int32 BidVolume1;                                                                       ///������һ
		System::Double AskPrice1;                                                                       ///������һ
		System::Int32 AskVolume1;                                                                       ///������һ
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBid23Field                                                 ///�����������������
	{
	public:
		System::Double BidPrice2;																		///����۶�
		System::Int32 BidVolume2;                                                                       ///��������
		System::Double BidPrice3;                                                                       ///�������
		System::Int32 BidVolume3;                                                                       ///��������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataAsk23Field                                                 ///������������������
	{
	public:
		System::Double AskPrice2;                                                                       ///�����۶�
		System::Int32 AskVolume2;                                                                       ///��������
		System::Double AskPrice3;                                                                       ///��������
		System::Int32 AskVolume3;                                                                       ///��������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBid45Field                                                 ///���������ġ�������
	{
	public:
		System::Double BidPrice4;                                                                       ///�������
		System::Int32 BidVolume4;                                                                       ///��������
		System::Double BidPrice5;                                                                       ///�������
		System::Int32 BidVolume5;                                                                       ///��������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataAsk45Field                                                 ///���������ġ�������
	{
	public:
		System::Double AskPrice4;                                                                       ///��������
		System::Int32 AskVolume4;                                                                       ///��������
		System::Double AskPrice5;                                                                       ///��������
		System::Int32 AskVolume5;                                                                       ///��������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataUpdateTimeField                                            ///�������ʱ������
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ UpdateTime;                         ///����޸�ʱ��
		System::Int32 UpdateMillisec;                                                                   ///����޸ĺ���
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcDepthMarketDataField                                                 ///�������
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ SettlementGroupID;                  ///���������
		System::Int32 SettlementID;                                                                     ///������
		System::Double PreSettlementPrice;                                                              ///�����
		System::Double PreClosePrice;                                                                   ///������
		System::Double PreOpeninterest;																	///��ֲ���
		System::Double PreDelta;                                                                        ///����ʵ��
		System::Double OpenPrice;                                                                       ///����
		System::Double HighestPrice;																	///��߼�
		System::Double LowestPrice;                                                                     ///��ͼ�
		System::Double ClosePrice;                                                                      ///������
		System::Double UpperLimitPrice;                                                                 ///��ͣ���
		System::Double LowerLimitPrice;                                                                 ///��ͣ���
		System::Double SettlementPrice;                                                                 ///�����
		System::Double CurrDelta;                                                                       ///����ʵ��
		System::Double LastPrice;                                                                       ///���¼�
		System::Int32 Volume;                                                                           ///����
		System::Double Turnover;                                                                        ///�ɽ����
		System::Double Openinterest;                                                                    ///�ֲ���
		System::Double BidPrice1;                                                                       ///�����һ
		System::Int32 BidVolume1;                                                                       ///������һ
		System::Double AskPrice1;                                                                       ///������һ
		System::Int32 AskVolume1;                                                                       ///������һ
		System::Double BidPrice2;                                                                       ///����۶�
		System::Int32 BidVolume2;                                                                       ///��������
		System::Double BidPrice3;                                                                       ///�������
		System::Int32 BidVolume3;                                                                       ///��������
		System::Double AskPrice2;                                                                       ///�����۶�
		System::Int32 AskVolume2;                                                                       ///��������
		System::Double AskPrice3;                                                                       ///��������
		System::Int32 AskVolume3;                                                                       ///��������
		System::Double BidPrice4;                                                                       ///�������
		System::Int32 BidVolume4;                                                                       ///��������
		System::Double BidPrice5;                                                                       ///�������
		System::Int32 BidVolume5;                                                                       ///��������
		System::Double AskPrice4;                                                                       ///��������
		System::Int32 AskVolume4;                                                                       ///��������
		System::Double AskPrice5;                                                                       ///��������
		System::Int32 AskVolume5;                                                                       ///��������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ UpdateTime;                         ///����޸�ʱ��
		System::Int32 UpdateMillisec;                                                                   ///����޸ĺ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcSpecificInstrumentField                                              ///���ĺ�Լ�������Ϣ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcShmDepthMarketDataField                                              ///�����ڴ������ѯ
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ IPAddress;                         ///IP��ַ
		System::Int32 TopicID;                                                                          ///���ĺ�
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryMarketDataField                                                   ///ʵʱ�����ѯ����
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///��Ʒ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataField                                                      ///ʵʱ�����ѯӦ��
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///��Լ����
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///Ʒ�ִ���
		System::Double OpenPrice;                                                                       ///����
		System::Double AskPrice1;                                                                       ///������һ
		System::Int32 AskVolume1;                                                                       ///������һ
		System::Double BidPrice1;                                                                       ///�����һ
		System::Int32 Bidvolume1;                                                                       ///������һ
		System::Double HighestPrice;                                                                    ///��߼�
		System::Double LowestPrice;                                                                     ///��ͼ�
		System::Double LastPrice;                                                                       ///���¼�
		System::Int32 Volume;                                                                           ///����
		System::Double TurnOver;                                                                        ///�ɽ����
		System::Double LowerLimitPrice;                                                                 ///��ͣ���
		System::Double UpperLimitPrice;                                                                 ///��ͣ���
		System::Int32 Openinterest;                                                                     ///�ֲ���
		System::Double PreClosePrice;                                                                   ///������
		System::Int32 Preinterest;																		///��ֲ���
		System::Double PreSettlementPrice;                                                              ///�����
		System::Double SettlementPrice;                                                                 ///�����
		System::Int32 Millisec;                                                                         ///����޸ĺ���
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ UpdateTime;                         ///����޸�ʱ��
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataExchangeIDField                                            ///����������
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///����������
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcTopicSearchField                                                     ///TOPIC��ѯ
	{
	public:
		System::Int32 TopicID;                                                                          ///���ĺ�
	};
}