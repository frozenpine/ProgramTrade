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
		DIALOG = 1,                             ///对话流
		PRIVATE = 2,                            ///私有流
		PUBLIC = 3,                             ///公共流
		QUERY = 4,                              ///查询
		USER = 5                                ///用户私有流
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcVolumeConditionType是一个成交量类型类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_VC :char
	{
		AV = '1',                         ///任何数量
		MV = '2',                         ///最小数量
		CV = '3'                          ///全部数量
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcForceCloseReasonType是一个强平原因类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_FCR :char
	{
		NotForceClose = '0',              ///非强平
		LackDeposit = '1',                ///资金不足
		ClientOverPositionLimit = '2',    ///客户超仓
		MemberOverPositionLimit = '3',    ///会员超仓
		NotMultiple = '4'                 ///持仓非整数倍
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcInstrumentStatusType是一个合约交易状态类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_IS : char
	{
		BeforeTrading = '0',              ///开盘前
		NoTrading = '1',                  ///非交易
		Continous = '2',                  ///连续交易
		AuctionOrdering = '3',            ///集合竞价报单
		AuctionBalance = '4',             ///集合竞价价格平衡
		AuctionMatch = '5',               ///集合竞价撮合
		Closed = '6'                      ///收盘
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOffsetFlagType是一个开平标志类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OF : char
	{
		Open = '0',                       ///开仓
		Close = '1',                      ///平仓
		ForceClose = '2',                 ///强平
		CloseToday = '3',                 ///平今
		CloseYesterday = '4'              ///平昨
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOrderPriceTypeType是一个报单价格条件类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OPT : char
	{
		AnyPrice = '1',                   ///任意价
		LimitPrice = '2',                 ///限价
		BestPrice = '3',                  ///最优价
		FiveLevelPrice = '4'              ///五档价
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOrderStatusType是一个报单状态类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OS : char
	{
		AllTraded = '0',                  ///全部成交
		PartTradedQueueing = '1',         ///部分成交还在队列中
		PartTradedNotQueueing = '2',      ///部分成交不在队列中
		NoTradeQueueing = '3',            ///未成交还在队列中
		NoTradeNotQueueing = '4',         ///未成交不在队列中
		Canceled = '5',                   ///撤单
		AcceptedNoReply = '6'             ///订单已报入交易所未应答
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcUserTypeType是一个用户类型类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_UT : char
	{
		Person = '1',                     ///自然人
		Product = '2',                    ///理财产品
		Manager = '3',                    ///期货公司管理员
		Seat = '4'                        ///席位
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcTradingRightType是一个交易权限类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_TR : char
	{
		Allow = '0',                      ///可以交易
		CloseOnly = '1',                  ///只能平仓
		Forbidden = '2'                   ///不能交易
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcTimeConditionType是一个有效期类型类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_TC : char
	{
		IOC = '1',                        ///立即完成，否则撤销
		GFS = '2',                        ///本节有效
		GFD = '3',                        ///当日有效
		GTD = '4',                        ///指定日期前有效
		GTC = '5',                        ///撤销前有效
		GFA = '6'                         ///集合竞价有效
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOrderSourceType是一个报单来源类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_ODS : char
	{
		Participant = '0',                ///来自参与者
		Administrator = '1'               ///来自管理员
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcDirectionType是一个买卖方向类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_D : char
	{
		Buy = '0',                        ///买
		Sell = '1'                        ///卖               
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcCurrencyType是一个币种类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_C : char
	{
		RMB = '1',                        ///人民币
		USD = '2'                         ///美元
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcAccountDirectionType是一个出入金方向类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_AD : char
	{
		In = '1',                         ///入金
		Out = '2'                         ///出金
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcClientHedgeFlagType是一个客户投机套保标志类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_CHF : char
	{
		Speculation = '1',                ///投机
		Arbitrage = '2',                  ///套利
		Hedge = '3',                      ///套保
		MarketMaker = '4'                 ///做市商
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcActionFlagType是一个操作标志类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_AF : char
	{
		Delete = '0',                     ///删除
		Suspend = '1',                    ///挂起
		Active = '2',                     ///激活
		Modify = '3'                      ///修改
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcPositionTypeType是一个持仓类型类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_PT : char
	{
		Net = '1',                        ///净持仓
		Gross = '2'                       ///综合持仓
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcOptionsTypeType是一个期权类型类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_OT : char
	{
		NotOptions = '0',                 ///非期权
		CallOptions = '1',                ///看涨
		PutOptions = '2'                  ///看跌
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcIsActiveType是一个是否活跃类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_UIA : char
	{
		NoActive = '0',                   ///不活跃
		Active = '1'                      ///活跃
	};

	/////////////////////////////////////////////////////////////////////////
	///TFtdcBusinessTypeType是一个业务类别类型
	/////////////////////////////////////////////////////////////////////////
	public enum class CLRQDP_FTDC_BT : char
	{
		Normal = '1',                     ///普通
		Cancel = '2',                     ///撤单
		AppliedForRedeemed = '3',         ///ETF申赎
		FiveLevelIOC = '4',               ///最优五档即时成交剩余撤销
		FiveLevelGFD = '5',               ///最优五档即时成交剩余转限价
		BestPriceIOC = '6',               ///即时成交剩余撤销
		FOK = '7',                        ///全额成交或撤销
		SelfGFD = '8',                    ///本方最优价格
		CpGFD = '9'                       ///对方最优价格
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcReqUserLoginField                                                    ///系统用户登录请求
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///交易用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ Password;                          ///密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ UserProductInfo;                   ///用户端产品信息
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ InterfaceProductInfo;              ///接口端产品信息
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ ProtocolInfo;                      ///协议信息
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ IPAddress;                         ///IP地址
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ MacAddress;                        ///Mac地址
		System::Int32 DataCenterID;																		///数据中心代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ OneTimePassword;                   ///动态密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ ClientIPAddress;                   ///终端IP地址
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspUserLoginField                                                    ///系统用户登录应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///交易用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ LoginTime;                          ///登录成功时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ MaxOrderLocalID;                   ///用户本地最大报单号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 61)]String^ TradingSystemName;                 ///交易系统名称
		System::Int32 DataCenterID;                                                                     ///数据中心代码
		System::Int32 PrivateFlowSize;                                                                  ///会员私有流当前长度
		System::Int32 UserFlowSize;                                                                     ///交易员私有流当前长度
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcReqUserLogoutField                                                   ///用户登出请求
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///交易用户代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspUserLogoutField                                                   ///用户登出应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///交易用户代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcForceUserExitField                                                   ///强制用户退出
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///交易用户代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcUserPasswordUpdateField                                              ///用户口令修改
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///交易用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ OldPassword;                       ///旧密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ NewPassword;                       ///新密码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInputOrderField                                                      ///输入报单
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///系统报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///用户本地报单号
		System::Char OrderPriceType;                     												///报单类型
		System::Char Direction;																			///买卖方向
		System::Char OffsetFlag;																		///开平标志
		System::Char HedgeFlag;																			///投机套保标志
		System::Double LimitPrice;																		///价格
		System::Int32 Volume;																			///数量
		System::Char TimeCondition;																		///有效期类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ GTDDate;                            ///GTD日期
		System::Char VolumeCondition;																	///成交量类型
		System::Int32 MinVolume;																		///最小成交量
		System::Double StopPrice;																		///止损价
		System::Char ForceCloseReason;																	///强平原因
		System::Int32 IsAutoSuspend;																	///自动挂起标志
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ BusinessUnit;                      ///业务单元
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 65)]String^ UserCustom;                        ///用户自定义域
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]String^ BranchID;                           ///营业部代码
		System::Int32 RecNum;																			///记录编号
		System::Char BusinessType;																		///业务类别
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcOrderActionField                                                     ///报单操作
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderActiconLocalID;           ///本次报单操作的本地编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///被操作报单的本地编号
		System::Char ActionFlag;																		///报单操作标志
		System::Double LimitPrice;																		///价格
		System::Int32 VolumeChange;																		///数量变化
		System::Int32 RecNum;																			///记录编号
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMemDbField                                                           ///内存表导出
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 61)]String^ MemTableName;                      ///内存表名
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInfoField                                                         ///响应信息
	{
	public:
		System::Int32 ErrorID;																					///错误代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]String^ ErrorMsg;                          ///错误信息
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryOrderField                                                        ///报单查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryTradeField                                                        ///成交查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ TradeID;                           ///成交编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInstrumentField                                                   ///合约查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///产品代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInstrumentField                                                   ///合约查询应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///产品代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ ProductName;                       ///品种名称
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ InstrumentName;                    ///合约名称
		System::Int32 DeliveryYear;																		///交割年份
		System::Int32 DeliveryMonth;																	///交割月
		System::Int32 MaxLimitOrderVolume;																///限价单最大下单量
		System::Int32 MinLimitOrderVolume;																///限价单最小下单量
		System::Int32 MaxMarketOrderVolume;																///市价单最大下单量
		System::Int32 MinMarketOrderVolume;																///市价单最小下单量
		System::Int32 VolumeMultiple;																	///数量乘数
		System::Double PriceTick;																		///报价单位
		System::Char Currency;																			///币种
		System::Int32 LongPosLimit;																		///多头限仓
		System::Int32 ShortPosLimit;																	///空头限仓
		System::Double LowerLimitPrice;																	///跌停板价
		System::Double UpperLimitPrice;																	///涨停板价
		System::Double PreSettlementPrice;																///昨日结算价
		System::Char InstrumentStatus;																	///合约交易状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ CreateDate;                         ///创建日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ OpenDate;                           ///上市日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ ExpireDate;                         ///到期日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ StartDelivDate;                     ///开始交割日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ EndDelivDate;                       ///最后交割日
		System::Double BasisPrice;																		///挂牌基准价
		System::Int32 IsTrading;																		///当前是否交易
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ UnderlyingInstrID;                 ///基础商品代码
		System::Int32 UnderlyingMultiple;																///基础商品乘数
		System::Char PositionType;																		///持仓类型
		System::Double StrikePrice;																		///执行价
		System::Char OptionsType;																		///期权类型
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInstrumentStatusField                                                ///合约状态
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchageID;                         ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///产品代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ ProductName;                       ///品种名称
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ InstrumentName;                    ///合约名称
		System::Int32 DeliveryYear;																		///交割年份
		System::Int32 DeliveryMonth;																	///交割月
		System::Int32 MaxLimitOrderVolume;																///限价单最大下单量
		System::Int32 MinLimitOrderVolume;																///限价单最小下单量
		System::Int32 MaxMarketOrderVolume;																///市价单最大下单量
		System::Int32 MinMarketOrderVolume;																///市价单最小下单量
		System::Int32 VolumeMultiple;																	///数量乘数
		System::Double PriceTick;																		///报价单位
		System::Char Currency;																			///币种
		System::Int32 LongPosLimit;																		///多头限仓
		System::Int32 ShortPosLimit;																	///空头限仓
		System::Double LowerLimitPrice;																	///跌停板价
		System::Double UpperLimitPrice;																	///涨停板价
		System::Double PreSettlementPrice;																///昨日结算价
		System::Char InstrumentStatus;																	///合约交易状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ CreateDate;                         ///创建日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ OpenDate;                           ///上市日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ ExpireDate;                         ///到期日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ StartDelivDate;                     ///开始交割日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ EndDelivDate;                       ///最后交割日
		System::Double BasisPrice;																		///挂牌基准价
		System::Int32 IsTrading;																		///当前是否交易
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ UnderlyingInstrID;                 ///基础商品代码
		System::Int32 UnderlyingMultiple;																///基础商品乘数
		System::Char PositionType;																		///持仓类型
		System::Double StrikePrice;																		///执行价
		System::Char OptionsType;																		///期权类型
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorAccountField                                              ///投资者资金查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInvestorAccountField                                              ///投资者资金应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经济公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ AccountID;                         ///资金账号
		System::Double PreBalance;																		///上次结算准备金
		System::Double PreAvailable;																	///上日可用资金
		System::Double Deposit;																			///入金金额
		System::Double Withdraw;																		///出金金额
		System::Double Margin;																			///占用保证金
		System::Double Premium;																			///期权权利金收支
		System::Double Fee;																				///手续费
		System::Double FrozenMargin;																	///冻结的保证金
		System::Double FrozenPremium;																	///冻结的权利金
		System::Double FrozenFee;																		///冻结的手续费
		System::Double CloseProfit;																		///平仓盈亏
		System::Double PositionProfit;																	///持仓盈亏
		System::Double Available;																		///可用资金
		System::Double Balance;																			///结算准备金
		System::Double LongMargin;																		///多头占用保证金
		System::Double ShortMargin;																		///空头占用保证金
		System::Double LongFrozenMargin;																///多头冻结保证金
		System::Double ShortFrozenMargin;																///空头冻结保证金
		System::Double DynamicRights;																	///动态权益
		System::Double Risk;																			///风险度
		System::Double OtherFee;																		///其他费用
		System::Double Mortage;																			///质押金额
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^ Currency;                           ///币种
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryUserInvestorField                                                 ///可用投资者查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspUserInvestorField                                                 ///可用投资者应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryTradingCodeField                                                  ///交易编码查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspTradingCodeField                                                  ///交易编码应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ AccountID;                         ///资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///会员编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///客户代码
		System::Char ClientRight;																		///客户权限代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 2)]String^ ClientType;                         ///客户类型
		System::Char ClientHedgeFlag;																	///客户保值类型
		System::Char IsActive;																			///是否活跃
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryExchangeField                                                     ///交易所查询请求
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspExchangeField                                                     ///交易所查询应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ ExchangeName;                      ///交易所名称
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorPositionField												///投资者持仓查询请求
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspInvestorPositionField                                             ///投资者持仓查询应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///会员编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///客户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		System::Char Direction;																			///买卖方向
		System::Char HedgeFlag;																			///投机套保标志
		System::Double UsedMargin;																		///占用保证金
		System::Int32 Position;																			///今日持仓量
		System::Double PositionCost;																	///今日持仓成本
		System::Int32 YdPosition;																		///昨日持仓量
		System::Double YdPositionCost;																	///昨日持仓成本
		System::Double FrozenMargin;																	///冻结的保证金
		System::Int32 FrozenPosition;																	///开仓冻结持仓
		System::Int32 FrozenClosing;																	///平仓冻结持仓
		System::Double FrozenPremium;																	///冻结的权利金
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ LastTradeID;                       ///最后一笔成交编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^ LastOrderLocalID;                  ///最后一笔本地报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^ Currency;                           ///币种
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryUserField                                                         ///用户查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ StartUserID;                       ///交易用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ EndUserID;                         ///交易用户代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcUserField                                                            ///用户
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ Password;                          ///用户登录密码
		System::Char IsActive;																			///是否活跃
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ UserName;                          ///用户名称
		System::Char UserType;																			///用户类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^ Department;                        ///营业部
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 5)]String^ GrantFuncSet;                       ///授权功能集
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorFeeField													///投资者手续费率查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		System::Char HedgeFlag;																			///投机套保标志
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInvestorFeeField                                                     ///投资者手续费率
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		System::Char HedgeFlag;																			///投机套保标志
		System::Double OpenFeeRate;                                                                     ///开仓手续费按比例
		System::Double OpenFeeAmt;                                                                      ///开仓手续费按手数
		System::Double OffsetFeeRate;                                                                   ///平仓手续费按比例
		System::Double OffsetFeeAmt;                                                                    ///平仓手续费按手数
		System::Double OTFeeRate;                                                                       ///平今仓手续费按比例
		System::Double OTFeeAmt;                                                                        ///平今仓手续费按手数
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryInvestorMarginField                                               ///投资者保证金率查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		System::Char HedgeFlag;																			///投机套保标志
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInvestorMarginField                                                  ///投资者保证金率
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		System::Char HedgeFlag;																			///投机套保标志
		System::Double LongMarginRate;                                                                  ///多头占用保证金按比例
		System::Double LongMarginAmt;                                                                   ///多头保证金按手数
		System::Double ShortMarginRate;                                                                 ///空头占用保证金按比例
		System::Double ShortMarginAmt;                                                                  ///空头保证金按手数
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryExchangeDiffTimeField                                             ///交易所时间偏差查询请求
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcRspExchangeDiffTimeField                                             ///交易所时间偏差查询应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ ExchangeTime;                       ///交易所时间
		System::Int32 DiffSnd;                                                                          ///偏差时间
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcTradeField                                                           ///成交
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///会员编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ SeatID;                            ///下单席位号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ TradeID;                           ///成交编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///本地报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		System::Char Direction;																			///买卖方向
		System::Char OffsetFlag;																		///开平标志
		System::Char HedgeFlag;																			///投机套保标志
		System::Double TradePrice;                                                                      ///成交价格
		System::Int32 TradeVolume;                                                                      ///成交数量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradeTime;                          ///成交时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ClearingPartID;                    ///清算会员编号
		System::Double TradeAmnt;                                                                       ///成交金额
		System::Int32 RecNum;                                                                           ///记录编号
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcOrderField                                                           ///报单
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ OrderSysID;                        ///报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 23)]String^ UserOrderLocalID;                  ///本地报单编号
		System::Char OrderPriceType;																	///报单类型
		System::Char Direction;																			///买卖方向
		System::Char OffsetFlag;																		///开平标志
		System::Char HedgeFlag;																			///投机套保标志
		System::Double LimitPrice;                                                                      ///价格
		System::Int32 Volume;                                                                           ///数量
		System::Char TimeCondition;																		///有效期类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ GTDDate;                            ///GTD日期
		System::Char VolumeCondition;																	///成交量类型
		System::Int32 MinVolume;                                                                        ///最小成交量
		System::Double StopPrice;                                                                       ///止损价
		System::Char ForceCloseReason;																	///强平原因
		System::Int32 IsAutoSuspend;                                                                    ///自动挂起标志
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ BussinessUnit;                     ///业务单元
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 65)]String^ UserCustom;                        ///用户自定义域
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 7)]String^ BranchID;                           ///营业部代码
		System::Int32 RecNum;                                                                           ///记录编号
		System::Char BusinessType;																		///业务类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ParticipantID;                     ///会员编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ ClientID;                          ///客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ SeatID;                            ///下单席位号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ InsertTime;                         ///插入时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^ OrderLocalID;                      ///本地报单编号
		System::Char OrderSource;																		///报单来源
		System::Char OrderStatus;																		///报单状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ CancleTime;                         ///撤销时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ CancelUserID;                      ///撤单用户编号
		System::Int32 VolumeTraded;                                                                     ///今成交数量
		System::Int32 VolumeRemain;                                                                     ///剩余数量
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcFlowMessageCancelField												///数据流回退
	{
	public:
		System::Int32 SequenceSeries;                                                                   ///序列系列号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;							///交易日
		System::Int32 DataCenterID;                                                                     ///数据中心代码
		System::Int32 StartSequenceNo;                                                                  ///回退起始序列号
		System::Int32 EndSequenceNo;                                                                    ///回退结束序列号
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcDisseminationField													///信息分发
	{
	public:
		System::Int32 SequenceSeries;                                                                   ///序列系列号
		System::Int32 SequenceNo;                                                                       ///序列号
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcInvestorAccountDepositResField                                       ///出入金结果
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ AccountID;                         ///资金帐号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ AccountSeqNo;                      ///资金流水号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ AccountInsideSeqNo;                ///连续递增的总资金流水号
		System::Double Amount;                                                                          ///金额
		System::Char AmountDirection;																	///出入金方向
		System::Double Available;                                                                       ///可用资金
		System::Double Balance;                                                                         ///结算准备金
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///用户代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMessageNotifyInfoField                                               ///QDP警告消息通知
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ BrokerID;                          ///经纪公司编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^ UserID;                            ///修改用户编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 19)]String^ InvestorID;                        ///投资者编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		System::Int32 Nums;                                                                             ///累加次数
		System::Char BusinessType;																		///业务类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 81)]String^ WarnMsg;                           ///警告信息
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBaseField                                                  ///行情基础属性
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ SettlementGroupID;                  ///结算组代码
		System::Int32 SettlementID;                                                                     ///结算编号
		System::Double PreSettlementPrice;                                                              ///昨结算
		System::Double PreClosePrice;                                                                   ///昨收盘
		System::Double PreOpeninterest;                                                                 ///昨持仓量
		System::Double PreDelta;                                                                        ///昨虚实度
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataStaticField                                                ///行情静态属性
	{
	public:
		System::Double OpenPrice;                                                                       ///今开盘
		System::Double HighestPrice;                                                                    ///最高价
		System::Double LowestPrice;                                                                     ///最低价
		System::Double ClosePrice;                                                                      ///今收盘
		System::Double UpperLimitPrice;                                                                 ///涨停板价
		System::Double LowerLimitPrice;                                                                 ///跌停板价
		System::Double SettlementPrice;                                                                 ///今结算
		System::Double CurrDelta;                                                                       ///今虚实度
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataLastMatchField                                             ///行情最新成交属性
	{
	public:
		System::Double LastPrice;                                                                       ///最新价
		System::Int32 Volume;                                                                           ///数量
		System::Double Turnover;                                                                        ///成交金额
		System::Double Openinterest;                                                                    ///持仓量
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBestPriceField                                             ///行情最优价属性
	{
	public:
		System::Double BidPrice1;                                                                       ///申买价一
		System::Int32 BidVolume1;                                                                       ///申买量一
		System::Double AskPrice1;                                                                       ///申卖价一
		System::Int32 AskVolume1;                                                                       ///申卖量一
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBid23Field                                                 ///行情申买二、三属性
	{
	public:
		System::Double BidPrice2;																		///申买价二
		System::Int32 BidVolume2;                                                                       ///申买量二
		System::Double BidPrice3;                                                                       ///申买价三
		System::Int32 BidVolume3;                                                                       ///申买量三
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataAsk23Field                                                 ///行情申卖二、三属性
	{
	public:
		System::Double AskPrice2;                                                                       ///申卖价二
		System::Int32 AskVolume2;                                                                       ///申卖量二
		System::Double AskPrice3;                                                                       ///申卖价三
		System::Int32 AskVolume3;                                                                       ///申卖量三
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataBid45Field                                                 ///行情申买四、五属性
	{
	public:
		System::Double BidPrice4;                                                                       ///申买价四
		System::Int32 BidVolume4;                                                                       ///申买量四
		System::Double BidPrice5;                                                                       ///申买价五
		System::Int32 BidVolume5;                                                                       ///申买量五
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataAsk45Field                                                 ///行情申卖四、五属性
	{
	public:
		System::Double AskPrice4;                                                                       ///申卖价四
		System::Int32 AskVolume4;                                                                       ///申卖量四
		System::Double AskPrice5;                                                                       ///申卖价五
		System::Int32 AskVolume5;                                                                       ///申卖量五
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataUpdateTimeField                                            ///行情更新时间属性
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ UpdateTime;                         ///最后修改时间
		System::Int32 UpdateMillisec;                                                                   ///最后修改毫秒
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcDepthMarketDataField                                                 ///深度行情
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ SettlementGroupID;                  ///结算组代码
		System::Int32 SettlementID;                                                                     ///结算编号
		System::Double PreSettlementPrice;                                                              ///昨结算
		System::Double PreClosePrice;                                                                   ///昨收盘
		System::Double PreOpeninterest;																	///昨持仓量
		System::Double PreDelta;                                                                        ///昨虚实度
		System::Double OpenPrice;                                                                       ///今开盘
		System::Double HighestPrice;																	///最高价
		System::Double LowestPrice;                                                                     ///最低价
		System::Double ClosePrice;                                                                      ///今收盘
		System::Double UpperLimitPrice;                                                                 ///涨停板价
		System::Double LowerLimitPrice;                                                                 ///跌停板价
		System::Double SettlementPrice;                                                                 ///今结算
		System::Double CurrDelta;                                                                       ///今虚实度
		System::Double LastPrice;                                                                       ///最新价
		System::Int32 Volume;                                                                           ///数量
		System::Double Turnover;                                                                        ///成交金额
		System::Double Openinterest;                                                                    ///持仓量
		System::Double BidPrice1;                                                                       ///申买价一
		System::Int32 BidVolume1;                                                                       ///申买量一
		System::Double AskPrice1;                                                                       ///申卖价一
		System::Int32 AskVolume1;                                                                       ///申卖量一
		System::Double BidPrice2;                                                                       ///申买价二
		System::Int32 BidVolume2;                                                                       ///申买量二
		System::Double BidPrice3;                                                                       ///申买价三
		System::Int32 BidVolume3;                                                                       ///申买量三
		System::Double AskPrice2;                                                                       ///申卖价二
		System::Int32 AskVolume2;                                                                       ///申卖量二
		System::Double AskPrice3;                                                                       ///申卖价三
		System::Int32 AskVolume3;                                                                       ///申卖量三
		System::Double BidPrice4;                                                                       ///申买价四
		System::Int32 BidVolume4;                                                                       ///申买量四
		System::Double BidPrice5;                                                                       ///申买价五
		System::Int32 BidVolume5;                                                                       ///申买量五
		System::Double AskPrice4;                                                                       ///申卖价四
		System::Int32 AskVolume4;                                                                       ///申卖量四
		System::Double AskPrice5;                                                                       ///申卖价五
		System::Int32 AskVolume5;                                                                       ///申卖量五
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ UpdateTime;                         ///最后修改时间
		System::Int32 UpdateMillisec;                                                                   ///最后修改毫秒
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcSpecificInstrumentField                                              ///订阅合约的相关信息
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcShmDepthMarketDataField                                              ///共享内存行情查询
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 21)]String^ IPAddress;                         ///IP地址
		System::Int32 TopicID;                                                                          ///订阅号
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcQryMarketDataField                                                   ///实时行情查询请求
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///产品代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataField                                                      ///实时行情查询应答
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ TradingDay;                         ///交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^ InstrumentID;                      ///合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^ ProductID;                         ///品种代码
		System::Double OpenPrice;                                                                       ///今开盘
		System::Double AskPrice1;                                                                       ///申卖价一
		System::Int32 AskVolume1;                                                                       ///申卖量一
		System::Double BidPrice1;                                                                       ///申买价一
		System::Int32 Bidvolume1;                                                                       ///申买量一
		System::Double HighestPrice;                                                                    ///最高价
		System::Double LowestPrice;                                                                     ///最低价
		System::Double LastPrice;                                                                       ///最新价
		System::Int32 Volume;                                                                           ///数量
		System::Double TurnOver;                                                                        ///成交金额
		System::Double LowerLimitPrice;                                                                 ///跌停板价
		System::Double UpperLimitPrice;                                                                 ///涨停板价
		System::Int32 Openinterest;                                                                     ///持仓量
		System::Double PreClosePrice;                                                                   ///昨收盘
		System::Int32 Preinterest;																		///昨持仓量
		System::Double PreSettlementPrice;                                                              ///昨结算
		System::Double SettlementPrice;                                                                 ///今结算
		System::Int32 Millisec;                                                                         ///最后修改毫秒
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 9)]String^ UpdateTime;                         ///最后修改时间
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcMarketDataExchangeIDField                                            ///交易所代码
	{
	public:
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 11)]String^ ExchangeID;                        ///交易所代码
	};

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRCQdpFtdcTopicSearchField                                                     ///TOPIC查询
	{
	public:
		System::Int32 TopicID;                                                                          ///订阅号
	};
}