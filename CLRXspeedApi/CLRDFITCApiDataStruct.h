#pragma once
#include <stdio.h>
#include <math.h>
#include "DFITCApistruct.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace CLRXspeedApi
{
	////////////////////////////////////////////////////////////
	///DFITCInstrumentTypeType:合约类型数据类型
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCInstrumentType
	{
		COMM_TYPE = 0,														//期货合约
		OPT_TYPE = 1														//期权合约
	};

	////////////////////////////////////////////////////////////
	///DFITCOrderAnswerStatusType:委托回报状态类型
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOrderAnswerStatusType :short
	{
		SPD_CANCELED = 1,													///全部撤单
		SPD_FILLED = 2,														///全部成交
		SPD_IN_QUEUE = 3,													///未成交还在队列中
		SPD_PARTIAL = 4,													///部分成交还在队列中
		SPD_PARTIAL_CANCELED = 5,											///部分撤单
		SPD_IN_CANCELING = 6,												///撤单中
		SPD_ERROR = 7,														///错误(废单错误)
		SPD_PLACED = 8,														///未成交不在队列中it
		SPD_TRIGGERED = 10													///柜台已接收，但尚未到交易所
	};

	////////////////////////////////////////////////////////////
	///DFITCSpeculatorType:投保类型
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCSpeculatorType
	{
		///投机
		SPD_SPECULATOR = 0,
		///套保
		SPD_HEDGE = 1,
		///套利
		SPD_ARBITRAGE = 2
	};

	////////////////////////////////////////////////////////////
	///DFITCBuySellTypeType:买卖数据类型
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCBuySellType :short
	{
		///买
		SPD_BUY = 1,
		///卖
		SPD_SELL = 2
	};

	////////////////////////////////////////////////////////////
	///DFITCOpenCloseTypeType：开平标志数据类型
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOpenCloseType
	{
		///开仓
		SPD_OPEN = 1,
		///平仓
		SPD_CLOSE = 2,
		///平今
		SPD_CLOSETODAY = 4,
		///期权执行
		SPD_EXECUTE = 6,
		///期权放弃
		SPD_GIVEUP = 7,
		///期权履约
		SPD_PERFORM = 8,
		///询价
		SPD_OPTQRYPRICE = 9,
		///强平
		SPD_FORCECLOSE = 12,
		///强平今
		SPD_FORCECLOSETODAY = 14
	};

	////////////////////////////////////////////////////////////
	///DFITCOrderType:报单类型
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOrderType
	{
		///限价委托
		LIMITORDER = 1,
		///市价委托
		MKORDER = 2,
		///套利委托
		ARBITRAGE = 4,
		///展期互换委托
		EXTENSION = 8,
		///限价止盈委托
		PROFIT_LIMITORDER = 32,
		///市价止盈委托
		PROFIT_MKORDER = 34,
		///限价止损委托
		LOSS_LIMITORDER = 48,
		///市价止损委托
		LOSS_MKORDER = 50
	};

	////////////////////////////////////////////////////////////
	///DFITCAccountLoginResultType:资金账户登录结果
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCAccountLoginResultType
	{
		///登录成功
		LOGIN_SUCCESS = 0,
		///登录失败
		LOGIN_FAILED = 1,
		///已退出
		LOGIN_QUIT = 2,
		///未操作
		LOGIN_NOT_OPERATE = 9
	};

	////////////////////////////////////////////////////////////
	///DFITCAccountLogoutResultType:资金帐号登出结果
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCAccountLogoutResultType
	{
		///登出成功
		LOGOUT_SUCCESS = 0,
		///登出失败
		LOGOUT_FAILED = 1
	};

	////////////////////////////////////////////////////////////
	///DFITCOrderPropertyType:订单属性
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCOrderPropertyType :char
	{
		///无订单属性
		SP_NON = '0',
		///FAK设置
		SP_FAK = '1',
		///FOK设置
		SP_FOK = '2',
		///市价任意价
		SP_ANYPRICE = '3',
		///市价任意价转限价
		SP_ANYPRICE_TO_MKORDER = '4',
		///五档市价
		SP_FIVELEVELPRICE = '5',
		///五档市价转限价
		SP_FIVELEVELPRICE_TO_LIMIT = '6',
		///最优价
		SP_BESTPRICE = '7',
		///最优价转限价
		SP_BESTPRICE_TO_LIMIT = '8'
	};

	////////////////////////////////////////////////////////////
	///DFITCInsertType:委托类别
	////////////////////////////////////////////////////////////
	public enum class CLRDFITCInsertType
	{
		///普通委托单
		BASIC_ORDER = 0x0001,
		///自动单
		AUTO_ORDER = 0x0002
	};

	///心跳包

	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTimeOutField
	{
		DFITCRequestIDType												lRequestID;                   //请求ID
	};

	///请求报单数据类型(基本报单)
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCInsertOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^    accountID;          //资金账户
		DFITCLocalOrderIDType											localOrderID;		//本地委托号, 由API使用者维护，在同一个会话中不能重复
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^    instrumentID;       //合约代码, 支持目前国内期货交易所的所有合约，包括大商所/郑商所的套利合约
		DFITCPriceType													insertPrice;        //报单价格, 当报单类型为市价时，该字段不起作用
		DFITCAmountType													orderAmount;        //报单数量
		DFITCBuySellTypeType											buySellType;        //买卖标志
		DFITCOpenCloseTypeType											openCloseType;      //开平标志
		DFITCSpeculatorType												speculator;         //投保类型, 支持投机、套利、套保
		DFITCInsertType													insertType;         //自动单类别(默认为普通订单)
		DFITCOrderTypeType												orderType;          //报单类型, 支持限价 、市价；上期所合约不支持市价
		DFITCOrderPropertyType											orderProperty;      //报单附加属性, 支持None、FAK、FOK
		DFITCInstrumentTypeType											instrumentType;     //合约类型, 可选值：期货、期权
		DFITCAmountType													minMatchAmount;     //最小成交量
		DFITCReservedType												reservedType2;      //预留字段2
		DFITCRequestIDType												lRequestID;         //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^    customCategory;     //自定义类别
		DFITCPriceType													profitLossPrice;    //止盈止损价格        
	};


	///撤单数据类型
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCSessionIDType                  sessionID;                    //会话ID
	};


	///委托响应类型
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderRspDataRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCPriceType                      fee;                          //手续费,该字段仅供下单时使用
		DFITCPriceType                      margin;                       //冻结保证金,该字段仅供下单时使用
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码 
		DFITCSessionIDType                  sessionID;                    //会话ID  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所  
		DFITCBuySellTypeType                buySellType;                  //买卖    
		DFITCOpenCloseTypeType              openCloseType;                //开平
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCSpeculatorType                 speculator;                   //投资类别
		DFITCPriceType                      insertPrice;                  //委托价
		DFITCPriceType                      profitLossPrice;              //止盈止损价格
		DFITCAmountType                     minMatchAmount;               //最小成交量
		DFITCAmountType                     orderAmount;                  //委托数量
		DFITCInsertType                     insertType;                   //自动单类别
		DFITCOrderTypeType                  orderType;                    //订单类型	
		DFITCOrderPropertyType              orderProperty;                //订单属性
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
	};



	///查询资金数据类型
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCapitalField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
	};


	///查询持仓数据类型
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCIsReturnRealizedPNLType        retRealizedPNL;               //是否返回未持仓合约的平仓盈亏
	};


	///交易所合约
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeInstrumentField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所编码
		DFITCInstrumentTypeType             instrumentType;               //合约类型
	};


	///用户登录数据类型
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLoginField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     passwd;                       //密码
		DFITCCompanyIDType                  companyID;                    //厂商ID
	};


	///用户退出类型
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLogoutField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号ID
		DFITCSessionIDType                  sessionID;                    //会话ID
	};


	///委托回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //报单编号
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
		DFITCSessionIDType                  sessionID;                    //会话ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       SuspendTime;                  //挂起时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所 
		DFITCBuySellTypeType                buySellType;                  //买卖
		DFITCOpenCloseTypeType              openCloseType;                //开平
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCSpeculatorType                 speculator;                   //投资类别
		DFITCPriceType                      insertPrice;                  //委托价
		DFITCPriceType                      profitLossPrice;              //止盈止损价格
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCAmountType                     cancelAmount;                 //撤单数量
		DFITCAmountType                     orderAmount;                  //委托数量
		DFITCInsertType                     insertType;                   //自动单类别
		DFITCOrderTypeType                  orderType;                    //报单类型
		DFITCSPDOrderIDType                 extSpdOrderID;                //条件单编号
		DFITCReservedType                   reservedType2;                //预留字段2	
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCOrderPropertyType              orderProperty;                //订单属性	
		DFITCAmountType                     minMatchAmount;               //最小成交量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               statusMsg;                    //状态信息
		DFITCExtOrderType                   extOrderType;                 //条件单类型
	};


	///成交回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //报单编号(交易所报单编号)
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchID;                      //成交编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCBuySellTypeType                buySellType;                  //买卖
		DFITCOpenCloseTypeType              openCloseType;                //开平标志
		DFITCPriceType                      matchedPrice;                 //成交价格
		DFITCAmountType                     orderAmount;                  //委托数量
		DFITCAmountType                     matchedAmount;                //成交数量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedTime;                  //成交时间
		DFITCPriceType                      insertPrice;                  //报价
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCMatchType                      matchType;                    //成交类型
		DFITCSpeculatorType                 speculator;                   //投保
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		DFITCFeeType                        fee;                          //手续费
		DFITCSessionIDType                  sessionID;                    //会话标识
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCOrderAnswerStatusType          orderStatus;                  //申报结果
		DFITCPriceType                      margin;                       //开仓为保证金,平仓为解冻保证金
		DFITCPriceType                      frozenCapita;                 //成交解冻委托冻结的资金
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^             adjustmentInfo;               //组合或对锁的保证金调整信息,格式:[合约代码,买卖标志,投资类别,调整金额;] 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCPriceType                      turnover;                     //成交金额
		DFITCOrderTypeType                  orderType;                    //报单类型
		DFITCInsertType                     insertType;                   //自动单类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		DFITCProfitLossType                 dateCloseProfitLoss;          //盯市平仓盈亏
	};


	///撤单回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderCanceledRtnField
	{
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //报单编号  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码     
		DFITCPriceType                      insertPrice;                  //报单价格  
		DFITCBuySellTypeType                buySellType;                  //买卖类型
		DFITCOpenCloseTypeType              openCloseType;                //开平标志
		DFITCAmountType                     cancelAmount;                 //撤单数量
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCSpeculatorType                 speculator;                   //投保
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       canceledTime;                 //撤单时间
		DFITCSessionIDType                  sessionID;                    //会话标识
		DFITCOrderAnswerStatusType          orderStatus;                  //申报结果
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCAmountType                     orderAmount;                  //委托数量   
		DFITCPriceType                      margin;                       //保证金
		DFITCPriceType                      fee;                          //手续费
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCPriceType                      profitLossPrice;              //止盈止损价格
		DFITCAmountType                     minMatchAmount;               //最小成交量
		DFITCInsertType                     insertType;                   //自动单类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               statusMsg;                    //状态信息
		DFITCOrderPropertyType              orderProperty;                //报单附加属性
	};


	///错误信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCErrorRtnField
	{
		DFITCRequestIDType                  requestID;                    //请求ID
		DFITCSessionIDType                  sessionID;                    //会话标识
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCErrorIDType                    nErrorID;                     //错误ID
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                     //错误信息
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
	};


	///返回资金信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCapitalInfoRtnField
	{
		DFITCRequestIDType                  requestID;                    //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号
		DFITCEquityType                     preEquity;                    //上日权益
		DFITCEquityType                     todayEquity;                  //当日客户权益
		DFITCProfitLossType                 closeProfitLoss;              //平仓盈亏
		DFITCProfitLossType                 positionProfitLoss;           //持仓盈亏
		DFITCProfitLossType                 frozenMargin;                 //冻结资金
		DFITCProfitLossType                 margin;                       //持仓保证金
		DFITCProfitLossType                 fee;                          //当日手续费
		DFITCProfitLossType                 available;                    //可用资金
		DFITCProfitLossType                 withdraw;                     //可取资金
		DFITCRiskDegreeType                 riskDegree;                   //风险度
		DFITCPremiumType                    todayPremiumIncome;           //本日权利金收入
		DFITCPremiumType                    todayPremiumPay;              //本日权利金付出
		DFITCPremiumType                    yesterdayPremium;             //昨权利金收付
		DFITCMarketValueType                optMarketValue;               //期权市值
		DFITCProfitLossType                 floatProfitLoss;              //浮动盈亏
		DFITCProfitLossType                 totFundOut;                   //总出金
		DFITCProfitLossType                 totFundIn;                    //总入金
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currencyID;                   //币种代码
		DFITCProfitLossType                 mortgage;                     //质押金额
		DFITCProfitLossType                 fundMortgageIn;               //货币质入金额
		DFITCProfitLossType                 fundMortgageOut;              //货币质出金额
		DFITCProfitLossType                 fundMortgageAvailable;        //货币质押余额
	};


	///返回持仓信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionInfoRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约号
		DFITCBuySellTypeType                buySellType;                  //买卖
		DFITCPriceType                      openAvgPrice;                 //开仓均价
		DFITCPriceType                      positionAvgPrice;             //持仓均价
		DFITCAmountType                     positionAmount;               //持仓量
		DFITCAmountType                     totalAvaiAmount;              //总可用
		DFITCAmountType                     todayAvaiAmount;              //今可用
		DFITCAmountType                     lastAvaiAmount;               //昨可用
		DFITCAmountType                     todayAmount;                  //今仓
		DFITCAmountType                     lastAmount;                   //昨仓
		DFITCAmountType                     tradingAmount;                //平今挂单量
		DFITCProfitLossType                 datePositionProfitLoss;       //盯市持仓盈亏
		DFITCProfitLossType                 dateCloseProfitLoss;          //(盯市)平仓盈亏
		DFITCProfitLossType                 dPremium;                     //权利金
		DFITCProfitLossType                 floatProfitLoss;              //浮动盈亏
		DFITCProfitLossType                 dMargin;                      //占用保证金
		DFITCSpeculatorType                 speculator;                   //投保类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		DFITCPriceType                      preSettlementPrice;           //昨结算价
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCAmountType                     yesterdayTradingAmount;       //平昨挂单量
		DFITCProfitLossType                 optionValue;                  //期权市值
	};


	///用户登录返回信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLoginInfoRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号ID
		DFITCAccountLoginResultType         loginResult;                  //登录结果
		DFITCLocalOrderIDType               initLocalOrderID;             //初始本地委托号
		DFITCSessionIDType                  sessionID;                    //sessionID(会话ID)
		DFITCErrorIDType                    nErrorID;                     //错误ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                     //错误信息
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       DCEtime;                      //大商所时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       SHFETime;                     //上期所时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       CFFEXTime;                    //中金所时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       CZCETime;                     //郑商所时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       INETime;                      //上能所时间
	};


	///用户退出返回信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCUserLogoutInfoRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		DFITCAccountLogoutResultType        logoutResult;                 //退出结果
		DFITCErrorIDType                    nErrorID;                     //错误ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                     //错误信息
	};


	///套利合约查询
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCAbiInstrumentField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所代码
	};


	///套利合约返回信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCAbiInstrumentRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^             instrumentName;               //合约名称
		DFITCPriceType                      upperLimitPrice;              //涨停板价
		DFITCPriceType                      lowerLimitPrice;              //跌停板价        
		DFITCPriceType                      priceTick;                    //最小变动价位
	};


	///指定的合约
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCSpecificInstrumentField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCSpeculatorType                 speculator;                   //投保类型
	};


	//****************期权扩展行情合约回报定义*************************
	///指定的合约信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCSpecificInstrumentFieldEX
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^                 FunctionID;                   //功能ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		DFITCInstrumentTypeType             instrumentType;               //合约类型
	};
	//*****************************************

	///行情订阅返回信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCActiveContractField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1024)]String^             activeContract;               //有效合约
	};


	///交易所合约返回信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeInstrumentRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^                VarietyName;                  //品种名称
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCAmountType                     orderTopLimit;                //限价委托上限
		DFITCAmountType                     mktOrderTopLimit;             //市价委托上限
		DFITCPriceType                      contractMultiplier;           //合约乘数
		DFITCPriceType                      minPriceFluctuation;          //最小变动价位
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 12)]String^         instrumentMaturity;           //合约最后交易日
		DFITCPriceType                      upperLimitPrice;              //涨停板价
		DFITCPriceType                      lowerLimitPrice;              //跌停板价
		DFITCPriceType                      preClosePrice;                //昨收盘
		DFITCPriceType                      preSettlementPrice;           //昨结算价
		DFITCPriceType                      settlementPrice;              //结算价
		DFITCAmountType                     preOpenInterest;              //昨持仓量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 31)]String^           instrumentPrefix;             //合约前缀
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 12)]String^    instrumentExpiration;         //合约到期日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               underlying;                   //期权对应的标的合约代码
		DFITCOptionTypeType                 optionType;                   //期权类型
		DFITCPriceType                      strikePrice;                  //执行价格
		DFITCRiskDegreeType                 exchangeRiskDegree;           //交易所期权最低保障风险系数
		DFITCPriceType                      minMargin;                    //单位（手）期权合约最小保证金
		DFITCAmountType                     tradeSize;                    //期权开仓单位
	};


	///委托查询数据结构
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态(暂不支持)
		DFITCOrderTypeType                  orderType;                    //报单类型(暂不支持)
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		DFITCSessionIDType                  sessionID;                    //会话ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
	};


	///成交查询数据结构
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCOrderTypeType                  orderType;                    //报单类型(暂不支持)
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
	};


	///委托查询响应数据结构
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCOrderCommRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCBuySellTypeType                buySellType;                  //买卖
		DFITCOpenCloseTypeType              openClose;                    //开平标志
		DFITCPriceType                      insertPrice;                  //委托价
		DFITCAmountType                     orderAmount;                  //委托数量
		DFITCPriceType                      matchedPrice;                 //成交价格
		DFITCAmountType                     matchedAmount;                //成交数量
		DFITCAmountType                     cancelAmount;                 //撤单数量
		DFITCInsertType                     insertType;                   //自动单类别
		DFITCSpeculatorType                 speculator;                   //投保
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       commTime;                     //委托时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       submitTime;                   //申报时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                  operStation;                  //委托地址
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //客户号
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCSessionIDType                  sessionId;                    //会话ID
		DFITCReservedType                   reservedType2;                //预留字段2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCPriceType                      margin;                       //保证金
		DFITCPriceType                      fee;                          //手续费
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		DFITCPriceType                      profitLossPrice;              //止损止盈价
		DFITCOrderTypeType                  orderType;                    //报单类别
		DFITCOrderPropertyType              orderProperty;                //订单属性
	};


	///成交查询数据响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchedRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCBuySellTypeType                buySellType;                  //买卖
		DFITCOpenCloseTypeType              openClose;                    //开平
		DFITCPriceType                      matchedPrice;                 //成交价格
		DFITCAmountType                     matchedAmount;                //成交数量
		DFITCPriceType                      matchedMort;                  //成交金额
		DFITCSpeculatorType                 speculator;                   //投保类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedTime;                  //成交时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchedID;                    //成交编号
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		DFITCMatchType                      matchType;                    //成交类型
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCSessionIDType                  sessionId;                    //会话ID
		DFITCReservedType                   reservedType2;                //预留字段2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCPriceType                      fee;                          //手续费
		DFITCOrderTypeType                  orderType;                    //报单类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //报单编号
	};


	///返回合约信息数据结构
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCInstrumentRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCRatioType                      longMarginRatio;              //多头保证金率
		DFITCRatioType                      shortMarginRatio;             //空头保证金率
		DFITCPriceType                      longMarginRatioByVolume;      //多头保证金费(定额)
		DFITCPriceType                      shortMarginRatioByVolume;     //空头保证金费(定额)
		DFITCRatioType                      openFeeVolRatio;              //开仓手续费 按手数计算
		DFITCRatioType                      closeFeeVolRatio;             //平仓手续费 按手数计算
		DFITCRatioType                      closeTodayFeeVolRatio;        //平今手续费 按手数计算
		DFITCRatioType                      openFeeAmtRatio;              //开仓手续费率 按金额计算
		DFITCRatioType                      closeFeeAmtRatio;             //平仓手续费率 按金额计算
		DFITCRatioType                      closeTodayFeeAmtRatio;        //平今手续费率 按金额计算
		DFITCAmountType                     orderTopLimit;                //限价委托上限
		DFITCPriceType                      contractMultiplier;           //合约乘数
		DFITCPriceType                      minimumPriceChange;           //最小变动价位
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 12)]String^         instrumentMaturity;           //合约最后交易日
		DFITCComputeModeType                computeMode;                  //计算方式             
		DFITCPriceType                      atMoneyNorm;                  //平值按定额
		DFITCPriceType                      upperLimitPrice;              //涨停板价
		DFITCPriceType                      lowerLimitPrice;              //跌停板价
		DFITCPriceType                      preClosePrice;                //昨收盘
		DFITCPriceType                      preSettlementPrice;           //昨结算价
		DFITCPriceType                      settlementPrice;              //结算价
		DFITCAmountType                     preOpenInterest;              //昨持仓量
		DFITCRatioType                      optExecRatio;                 //期权：行权按比例 期货：交割按比例
		DFITCRatioType                      optExecRatioPerVol;           //期权：行权按定额 期货：交割按定额
	};


	///深度行情
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCDepthMarketDataField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       tradingDay;                   //交易日
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               exchangeInstID;               //合约在交易所的代码
		DFITCPriceType                      lastPrice;                    //最新价
		DFITCPriceType                      preSettlementPrice;           //上次结算价
		DFITCPriceType                      preClosePrice;                //昨收盘
		DFITCAmountType                     preOpenInterest;              //昨持仓量
		DFITCPriceType                      openPrice;                    //今开盘
		DFITCPriceType                      highestPrice;                 //最高价
		DFITCPriceType                      lowestPrice;                  //最低价
		DFITCAmountType                     Volume;                       //成交数量
		DFITCPriceType                      turnover;                     //成交金额
		DFITCAmountType                     openInterest;                 //持仓量
		DFITCPriceType                      closePrice;                   //今收盘
		DFITCPriceType                      settlementPrice;              //本次结算价
		DFITCPriceType                      upperLimitPrice;              //涨停板价
		DFITCPriceType                      lowerLimitPrice;              //跌停板价
		DFITCDeltaType                      preDelta;                     //昨虚实度
		DFITCDeltaType                      currDelta;                    //今虚实度
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       UpdateTime;                   //最后修改时间
		DFITCMilliSecType                   UpdateMillisec;               //最后修改毫秒
		DFITCPriceType                      BidPrice1;                    //申买价一
		DFITCVolumeType                     BidVolume1;                   //申买量一
		DFITCPriceType                      AskPrice1;                    //申卖价一
		DFITCVolumeType                     AskVolume1;                   //申卖量一
		DFITCPriceType                      BidPrice2;                    //申买价二
		DFITCVolumeType                     BidVolume2;                   //申买量二
		DFITCPriceType                      AskPrice2;                    //申卖价二
		DFITCVolumeType                     AskVolume2;                   //申卖量二
		DFITCPriceType                      BidPrice3;                    //申买价三
		DFITCVolumeType                     BidVolume3;                   //申买量三
		DFITCPriceType                      AskPrice3;                    //申卖价三
		DFITCVolumeType                     AskVolume3;                   //申卖量三
		DFITCPriceType                      BidPrice4;                    //申买价四
		DFITCVolumeType                     BidVolume4;                   //申买量四
		DFITCPriceType                      AskPrice4;                    //申卖价四
		DFITCVolumeType                     AskVolume4;                   //申卖量四
		DFITCPriceType                      BidPrice5;                    //申买价五
		DFITCVolumeType                     BidVolume5;                   //申买量五
		DFITCPriceType                      AskPrice5;                    //申卖价五
		DFITCVolumeType                     AskVolume5;                   //申卖量五
		DFITCPriceType                      AveragePrice;                 //当日均价
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       XSpeedTime;                   //柜台系统时间
	};

	///********************************期权扩展行情************************************


	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMarketDataFieldEx
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 16)]String^                FunctionID;                    //功能号   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                      tradingDay;                    //日期 2014-04-01   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                      UpdateTime;                    //时间 11:01:29
		DFITCMilliSecType                  UpdateMillisec;                //毫秒 000 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^              instrumentID;                  //期权合约编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 128)]String^             ExtMarketData;                 //扩展行情数据	
	};
	///********************************************************************************


	//自定义组合行情
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCustomMarketDataField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		DFITCVolumeType                     bidVolume1;                   //买一量
		DFITCPriceType                      bidPrice1;                    //买一价(挂价价差)
		DFITCVolumeType                     askVolume1;                   //卖一量
		DFITCPriceType                      askPrice1;                    //卖一价(对价价差)
		DFITCPriceType                      lastPrice;                    //最新价价差
	};

	///查询持仓明细
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionDetailField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCInstrumentTypeType             instrumentType;               //合约类型
	};


	///查询持仓明细响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPositionDetailRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约号
		DFITCBuySellTypeType                buySellType;                  //买卖
		DFITCPriceType                      openPrice;                    //开仓价
		DFITCAmountType                     volume;                       //手数
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchID;                      //成交编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedDate;                  //成交日期
		DFITCProfitLossType                 datePositionProfitLoss;       //盯市持仓盈亏
		DFITCProfitLossType                 dateCloseProfitLoss;          //盯市平仓盈亏
		DFITCProfitLossType                 floatProfitLoss;              //浮动盈亏
		DFITCProfitLossType                 dMargin;                      //占用保证金
		DFITCSpeculatorType                 speculator;                   //投保类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		DFITCPriceType                      preSettlementPrice;           //昨结算价
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		DFITCAmountType                     closeOrderVol;                //平仓委托数量
		DFITCAmountType                     closeMatchVol;                //平仓成交数量
		DFITCPositionDateType               positionDateType;             //持仓日期类型
	};


	///用户事件通知信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTradingNoticeInfoField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       SendTime;                     //发送时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 501)]String^                    FieldContent;                 //消息正文
		DFITCNoticeType                     noticeType;                   //消息类型
	};


	///合约交易状态通知信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCInstrumentStatusField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 ExchangeID;                   //交易所代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               InstrumentID;                 //合约代码
		DFITCInstrumentStatusType           InstrumentStatus;             //合约交易状态
		DFITCTradingSegmentSNType           TradingSegmentSN;             //交易阶段编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       EnterTime;                    //进入本状态时间
		DFITCInstStatusEnterReasonType      EnterReason;                  //进入本状态原因
	};


	///用户密码修改
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCResetPwdField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     oldpasswd;                    //旧密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     newpasswd;                    //新密码
	};


	///用户密码修改返回信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCResetPwdRspField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		DFITCExecStateType                  execState;                    //状态标志
	};


	///账单确认
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCBillConfirmField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金帐号ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       date;                         //确认日期  格式：yyyy.mm.dd
		DFITCConfirmMarkType                confirmFlag;                  //确认标志
	};


	///账单确认响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCBillConfirmRspField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		DFITCExecStateType                  execState;                    //状态标志
	};


	///交易编码查询
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTradeCodeField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
	};


	///交易编码查询响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTradeCodeRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeCode;                 //交易所编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码 
		DFITCClientStatusType               clientStatus;                 //交易编码状态
		DFITCSpeculatorType                 clientIDType;                 //交易编码类型
	};


	///浮盈浮亏是否计算到权益中
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCEquityComputModeRtnField
	{
		DFITCCapControlModeType             capConMode;                   //资金控制方式,该方式需要用户按位判断,可能为多种组合
		DFITCPriceNoteType                  priceNote;                    //标的期货价格说明
	};


	///查询账单
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryBillField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       date;                         //查询日期   格式：yyyy.mm.dd
	};


	///查询账单响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryBillRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 1024)]String^                    message;                      //返回信息
	};


	///厂商ID确认请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProductField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                  productID;                    //产品编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^           vendorID;                     //软件供应商编号 
	};


	///厂商ID确认响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProductRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                  productID;                    //产品编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^           vendorID;                     //软件供应商
		DFITCProductOnlineCountType         productOnlineCount;           //产品在线数量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 20)]String^                 brokerInfoName;               //期货公司名称
		DFITCFrontIDType                    frontID;                      //前置机ID
	};


	///查询交易日请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTradingDayField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
	};


	///交易日请求响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTradingDayRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       date;                         //交易日
	};


	///询价通知订阅请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteSubscribeField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
	};

	///询价通知订阅响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteSubscribeRspField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCExecStateType                  subscribeFlag;                //订阅状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
	};

	///询价通知退订请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteUnSubscribeField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
	};

	///询价通知退订响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteUnSubscribeRspField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCExecStateType                  subscribeFlag;                //退订状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
	};

	///询价通知订阅回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteSubscribeRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //询价编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCSourceType                     source;                       //来源
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       quoteTime;                    //询价时间
	};

	///询价通知查询请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryQuoteNoticeField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
	};

	///询价通知查询响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryQuoteNoticeRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //询价编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCSourceType                     source;                       //来源
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       quoteTime;                    //询价时间
	};

	///做市商报单请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteInsertField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		DFITCInsertType                     insertType;                   //自动单类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //询价编号
		DFITCInstrumentTypeType             instrumentType;               //合约类型 
		DFITCAmountType                     bOrderAmount;                 //报单数量（买）
		DFITCAmountType                     sOrderAmount;                 //报单数量（卖）
		DFITCPriceType                      bInsertPrice;                 //委托价格（买）         
		DFITCPriceType                      sInsertPrice;                 //委托价格（卖）          
		DFITCOpenCloseTypeType              bOpenCloseType;               //开平标志（买）  
		DFITCOpenCloseTypeType              sOpenCloseType;               //开平标志（卖）
		DFITCSpeculatorType                 bSpeculator;                  //投资类别（买）       
		DFITCSpeculatorType                 sSpeculator;                  //投资类别（卖）          
		DFITCStayTimeType                   stayTime;                     //停留时间，仅支持郑州。其它情况可设置为0 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
	};



	///做市商报单响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteRspField
	{
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号              
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号                
		DFITCRequestIDType                  lRequestID;                   //请求ID                    
		DFITCPriceType                      fee;                          //手续费(仅报价使用)            
		DFITCPriceType                      margin;                       //保证金(仅报价使用)
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       orderTime;                    //委托时间(仅报价使用)  
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //询价编号
		DFITCSessionIDType                  sessionID;                    //会话ID 
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
	};


	///做市商报单回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //交易所                   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                      //交易编码  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 orderSysID;                    //报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                  //合约代码                   
		DFITCLocalOrderIDType               localOrderID;                  //本地委托号                
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                   seatCode;                      //席位代码                  
		DFITCOpenCloseTypeType              bOpenCloseType;                //开平标志（买）          
		DFITCOpenCloseTypeType              sOpenCloseType;                //开平标志（卖）             
		DFITCSpeculatorType                 speculator;                    //投资类别                       
		DFITCAmountType                     bOrderAmount;                  //委托数量（买）            
		DFITCAmountType                     sOrderAmount;                  //委托数量（卖）           
		DFITCPriceType                      bInsertPrice;                  //委托价  （买）               
		DFITCPriceType                      sInsertPrice;                  //委托价  （卖）               
		DFITCSPDOrderIDType                 spdOrderID;                    //柜台委托号                               
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //资金账号                     
		DFITCInstrumentTypeType             instrumentType;                //合约类型                  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       suspendTime;                   //挂单时间                               
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^               entrusTeller;                  //委托柜员  
		DFITCOrderAnswerStatusType          orderStatus;                   //委托状态 
		DFITCSessionIDType                  sessionID;                     //会话ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                       //询价编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               errorMsg;                      //错误信息
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;                //自定义类别
	};



	///做市商撤单回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteCanceledRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //交易所                   
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                      //交易编码  
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 orderSysID;                    //报单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                  //合约代码                   
		DFITCLocalOrderIDType               localOrderID;                  //本地委托号                
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                   seatCode;                      //席位代码                  
		DFITCOpenCloseTypeType              bOpenCloseType;                //开平标志（买）          
		DFITCOpenCloseTypeType              sOpenCloseType;                //开平标志（卖）             
		DFITCSpeculatorType                 speculator;                    //投资类别                       
		DFITCSPDOrderIDType                 spdOrderID;                    //柜台委托号                               
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //资金账号                     
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^               entrusTeller;                  //委托柜员       
		DFITCOrderAnswerStatusType          orderStatus;                   //委托状态 
		DFITCAmountType                     cancelAmount;                  //撤单数量                              
		DFITCPriceType                      fee;                           //解冻手续费                  
		DFITCPriceType                      margin;                        //解冻保证金 
		DFITCSessionIDType                  sessionID;                     //会话ID
		DFITCBuySellTypeType                buySellType;                   //买卖标志
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                       //询价编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       canceledTime;                  //撤单时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;                //自定义类别
	};



	///做市商成交回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteMatchRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   clientID;                     //交易编码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                   seatCode;                     //席位代码
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		DFITCOpenCloseTypeType              openCloseType;                //开平标志
		DFITCSpeculatorType                 speculator;                   //投资类别  
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^                 OrderSysID;                   //报单编号(交易所报单编号)
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                    matchID;                      //成交编号
		DFITCAmountType                     matchedAmount;                //成交数量
		DFITCPriceType                      matchedPrice;                 //成交价格
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCPriceType                      turnover;                     //成交金额
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^               entrusTeller;                 //委托柜员
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       matchedTime;                  //成交时间
		DFITCFeeType                        fee;                          //手续费
		DFITCPriceType                      insertPrice;                  //委托价格
		DFITCAmountType                     orderAmount;                  //委托数量
		DFITCOrderAnswerStatusType          orderStatus;                  //申报结果
		DFITCPriceType                      margin;                       //开仓为保证金,平仓为解冻保证金
		DFITCBuySellTypeType                buySellType;                  //买卖
		DFITCAmountType                     closeTodayAmount;             //平今数量
		DFITCPriceType                      closePrice;                   //平仓金额
		DFITCPriceType                      closeTodayPrice;              //平今金额
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^             adjustmentInfo;               //组合或对锁的保证金调整信息,格式:[合约代码,买卖标志,投资类别,调整金额;] 
		DFITCPriceType                      frozenCapita;                 //成交解冻委托冻结的资金
		DFITCProfitLossType                 dateCloseProfitLoss;          //盯市平仓盈亏
		DFITCInstrumentTypeType             instrumentType;               //合约类型
		DFITCSessionIDType                  sessionID;                    //会话标识
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 128)]String^          largeMarginDirect;            //大边保证金方向
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //询价编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
	};


	///批量撤单请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelAllOrderField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所编码(目前只支持大商所)
	};

	///批量撤单响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelAllOrderRspField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
	};

	///询价请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCForQuoteField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
	};

	///询价请求响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCForQuoteRspField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       commTime;                     //委托时间
	};

	///询价回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCForQuoteRtnField
	{
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCSessionIDType                  sessionID;                    //会话ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
	};

	///做市商报价委托查询
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteOrderField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
	};

	///做市商报价查询响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQuoteOrderRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCPriceType                      margin;                       //保证金
		DFITCPriceType                      fee;                          //手续费
		DFITCLocalOrderIDType               localOrderID;                 //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       commTime;                     //委托时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       submitTime;                   //申报时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所ID
		DFITCAmountType                     bOrderAmount;                 //委托数量（买）
		DFITCAmountType                     bMatchedAmount;               //成交数量（买）
		DFITCAmountType                     bCancelAmount;                //撤单数量（买）
		DFITCPriceType                      bInsertPrice;                 //委托价格（买）
		DFITCPriceType                      bMatchedPrice;                //成交价格（买）
		DFITCOpenCloseTypeType              bOpenCloseType;               //开平标志（买）
		DFITCAmountType                     sOrderAmount;                 //委托数量（卖）
		DFITCAmountType                     sMatchedAmount;               //成交数量（卖）
		DFITCAmountType                     sCancelAmount;                //撤单数量（卖）
		DFITCPriceType                      sInsertPrice;                 //委托价格（卖）
		DFITCPriceType                      sMatchedPrice;                //成交价格（卖）
		DFITCOpenCloseTypeType              sOpenCloseType;               //开平标志（卖）
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^                  operStation;                  //操作站点
		DFITCSessionIDType                  sessionID;                    //会话ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 33)]String^                    quoteID;                      //询价编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 32)]String^             customCategory;               //自定义类别
	};

	///查询转账银行
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTransferBankField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		DFITCRequestIDType                  lRequestID;                    //请求ID
	};

	///转帐银行响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferBankRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //客户号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //银行账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currency;                      //币种
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       registDate;                    //登记日期
		DFITCRequestIDType                  lRequestID;                    //请求ID
	};

	///查询转账流水
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryTransferSerialField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //银行账号
		DFITCRequestIDType                  lRequestID;                    //请求ID
	};

	///转账流水响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferSerialRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //资金账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //银行账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currency;                      //币种代码
		DFITCApplyNumberType                applyNum;                      //申请号
		DFITCTransferType                   type;                          //转账业务类别
		DFITCPriceType                      tradeAmount;                   //转账金额
		DFITCPriceType                      curFutAccountFund;             //本次资金余额
		DFITCSerialType                     bankSerialNum;                 //银行流水号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                 reqTransferTime;               //发起转账时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                 dealTransferTime;              //转账成功时间
		DFITCProcResultType                 procResult;                    //转账处理结果
		DFITCRequestIDType                  lRequestID;                    //请求ID
	};

	///资金转账请求信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCReqTransferField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //银行账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     bankPassword;                  //银行密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //投资者账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                     password;                      //期货密码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   currency;                      //币种代码
		DFITCPriceType                      tradeAmount;                   //转账金额
		DFITCRequestIDType                  lRequestID;                    //请求ID
	};

	///资金转账响应信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //银行账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //投资者账号
		DFITCPriceType                      tradeAmount;                   //转账金额
		DFITCApplyNumberType                applyNumber;                   //转账申请号
		DFITCRequestIDType                  lRequestID;                    //请求ID
	};

	///资金转账通知信息
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCTransferRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //投资者账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //银行账号
		DFITCTransferType                   type;                          //转账类别
		DFITCPriceType                      tradeAmount;                   //转账金额
		DFITCSerialType                     bankSerialNum;                 //银行流水号
		DFITCApplyNumberType                applyNumber;                   //转账申请号
		DFITCSessionIDType                  sessionID;                     //会话ID
	};

	///银行或主席发起出金冲正通知
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCRepealRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                     //投资者账号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                     bankID;                        //银行代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 41)]String^                bankAccount;                   //银行账号
		DFITCTransferType                   type;                          //转账类别
		DFITCPriceType                      tradeAmount;                   //转账金额
		DFITCSerialType                     bankSerialNum;                 //银行流水号
		DFITCSerialType                     repealSerial;                  //被冲正流水号
	};

	///交易状态查询请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryExchangeStatusField
	{
		DFITCRequestIDType                  lRequestID;                    //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //交易所编码
	};

	///交易所状态查询响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeStatusRspField
	{
		DFITCRequestIDType                  lRequestID;                    //请求ID
		DFITCExchangeStatusType             exchangeStatus;                //交易所状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                    //交易所编码
	};

	///交易所状态通知
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeStatusRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		DFITCExchangeStatusType             exchangeStatus;               //交易所状态
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 256)]String^                       enterTime;                    //进入本状态时间
		DFITCInstStatusEnterReasonType      enterReason;                  //进入本状态原因
	};

	///行情查询请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryDepthMarketDataField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
	};

	///查询询价请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryForQuoteField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账户ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
	};

	///查询询价响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryForQuoteRtnField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                  accountID;                    //资金账号
		DFITCSPDOrderIDType                 spdOrderID;                   //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^               instrumentID;                 //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 8)]String^                 exchangeID;                   //交易所
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                       SuspendTime;                  //挂起时间
		DFITCOrderAnswerStatusType          orderStatus;                  //委托状态
	};

	///查询汇率
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryExchangeRateField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   fromCurrencyID;               //源币种
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   toCurrencyID;                 //目标币种
	};

	///查询汇率响应
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExchangeRateField
	{
		DFITCRequestIDType                  lRequestID;                   //请求ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   fromCurrencyID;               //源币种
		DFITCCurrencyUnitType               fromCurrencyUnit;             //源币种单位数量
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 4)]String^                   toCurrencyID;                 //目标币种
		DFITCExchangeRateType               exchangeRate;                 //汇率
	};

	///行情触发请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPricesTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		DFITCPriceType                  insertPrice;        //委托价格
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCExtOrderPriceTypeType      orderType;          //条件单报单类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCCompareFlagType            compareFlag;        //比较标志(价格)
		DFITCPriceType                  comparePrice;       //触发价格(触发条件为行情价格大于或小于等于触发价格)
		DFITCPriceReferenceType         priceReference;     //价格参照
		DFITCBreakDownTimesType         breakDownTimes;     //击穿次数
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //有效日期(yyyy.mm.dd,暂不支持)
		DFITCFrozenTypeType             frozentype;         //是否冻结资金类型
		DFITCInstrumentTypeType         instrumentType;     //合约类型
		DFITCAmountType                 limitAmount;        //数量限制
		DFITCCompareFlagType            qtyCmpFlag;         //比较标志(数量)
		DFITCTriggerType                triggerType;        //触发类型	
		DFITCBreakDownTypeType          breakDownType;      //击穿属性			
	};

	///行情触发单修改请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPricesTriggerModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号		
		DFITCPriceType                  comparePrice;       //触发价格
		DFITCBreakDownTimesType         breakDownTimes;     //击穿次数
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //有效日期(yyyy.mm.dd)
	};

	///成交触发请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		DFITCPriceType                  insertPrice;        //委托价格
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType; 	    //开平标志
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           trigInstrumentID;   //触发合约代码
		DFITCPriceType                  trigInsertPrice;    //委托价格
		DFITCAmountType                 trigOrderAmount;    //委托数量
		DFITCSpeculatorType             trigSpeculator;     //投保类型
		DFITCBuySellTypeType            trigBuySellType;    //买卖标志
		DFITCOpenCloseTypeType          trigOpenCloseType;  //开平标志
		DFITCFrozenTypeType             frozentype;         //冻结类型
	};

	///成交触发修改
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCMatchTriggerModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           trigInstrumentID;   //触发合约代码
		DFITCPriceType                  trigInsertPrice;    //委托价格
		DFITCAmountType                 trigOrderAmount;    //委托数量
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
	};

	///止损止盈单请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)] 
	public value struct CLRDFITCProfitLossField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		DFITCPriceType                  insertPrice;        //委托价格
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCPriceType                  comparePriceFall;   //下跌触发价差
		DFITCPriceType                  insertPriceFall;    //下跌委托价差
		DFITCAddPriceTimesType          addPriceTimesFall;  //下跌追价次数
		DFITCOrderTypeType              orderTypeFall;      //下跌报单类型
		DFITCPriceType                  comparePriceRise;   //上涨触发价差
		DFITCPriceType                  insertPriceRise;    //上涨委托价差
		DFITCAddPriceTimesType          addPriceTimesRise;  //上涨追价次数
		DFITCOrderTypeType              orderTypeRise;      //上涨报单类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //有效日期
	};

	///止损止盈修改请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProfitLossModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		DFITCPriceType                  comparePriceFall;   //下跌触发价差
		DFITCPriceType                  insertPriceFall;    //下跌委托价差
		DFITCAddPriceTimesType          addPriceTimesFall;  //下跌追价次数
		DFITCPriceType                  comparePriceRise;   //上涨触发价差
		DFITCPriceType                  insertPriceRise;    //上涨委托价差
		DFITCAddPriceTimesType          addPriceTimesRise;  //上涨追价次数
	};

	///组合触发报单请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)] 
	public value struct CLRDFITCArbitrageField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码1
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID2;      //合约代码2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //有效日期
		DFITCPriceType                  insertPrice;        //偏离板价
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCPriceType                  insertPrice2;       //偏离板价2
		DFITCAmountType                 orderAmount2;       //委托数量2
		DFITCSpeculatorType             speculator2;        //投保类型2
		DFITCBuySellTypeType            buySellType2;       //买卖标志2
		DFITCOpenCloseTypeType          openCloseType2;     //开平标志2
		DFITCPriceType                  priceMargin;        //价差
		DFITCMinEntryType               minEntry;           //最小报单类型
		DFITCSplitContinueType          splitContinue;      //单腿是否继续
		DFITCPriceType                  deviatePrice;       //偏离板价
		DFITCArbitrageTypeType          arbitrageType;      //套利类型
	};

	///组合触发单修改请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCArbitrageModifyField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		DFITCPriceType                  insertPrice;        //偏离板价1
		DFITCPriceType                  insertPrice2;       //偏离板价2
		DFITCPriceType                  priceMargin;        //价差
		DFITCMinEntryType               minEntry;           //最小报单类型
		DFITCSplitContinueType          splitContinue;      //单腿是否继续
		DFITCPriceType                  deviatePrice;       //偏离板价
	};

	///条件单查询请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryExtOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号(暂不支持)
		DFITCExtOrderType               extOrderType;       //条件单类型
	};

	///条件单撤单请求
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCCancelExtOrderField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		DFITCExtOrderType               extOrderType;       //条件单类型
	};


	///行情触发单回报
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCPricesTriggerRtnField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		DFITCPriceType                  insertPrice;        //委托价格
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCExtOrderPriceTypeType      extOrderPriceType;  //条件单报单类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCCompareFlagType            compareFlag;        //比较标志
		DFITCPriceType                  comparePrice;       //触发价格
		DFITCPriceReferenceType         priceReference;     //价格参照
		DFITCBreakDownTimesType         breakDownTimes;     //击穿次数
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //修改时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //委托时间
		DFITCSPDOrderIDType             spdOrderID;         //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //撤单时间
		DFITCFrozenTypeType             frozentype;         //冻结类型
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		DFITCProfitLossType             frozenMargin;       //冻结资金
		DFITCAmountType                 frozenAmount;       //冻结数量
		DFITCOrderAnswerStatusType      orderStatus;        //委托状态
		DFITCSessionIDType              sessionID;          //会话ID
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           statusMsg;          //状态信息
		DFITCAmountType                 limitAmount;        //数量限制
		DFITCCompareFlagType            qtyCmpFlag;         //比较标志(数量)
		DFITCTriggerType                triggerType;        //触发类型	
		DFITCBreakDownTypeType          breakDownType;      //击穿属性	
		DFITCExtOrderTriggerStatusType  orderTriggerStatus; //条件单触发状态
	};


	///查询行情触发委托
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryPricesTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		DFITCPriceType                  insertPrice;        //委托价格
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCOrderTypeType              orderType;          //报单类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCCompareFlagType            compareFlag;        //比较标志
		DFITCPriceType                  comparePrice;       //触发价格
		DFITCPriceReferenceType         priceReference;     //价格参照
		DFITCBreakDownTimesType         breakDownTimes;     //击穿次数
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //有效日期
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //修改时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //委托时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commdate;           //委托日期
		DFITCSPDOrderIDType             spdOrderID;         //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //撤单时间
		DFITCFrozenTypeType             frozentype;         //冻结类型
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		DFITCExtOrderType               extOrderType;       //条件单类型
		DFITCProfitLossType             frozenMargin;       //冻结资金
		DFITCAmountType                 frozenAmount;       //冻结数量
		DFITCOrderAnswerStatusType      orderStatus;        //委托状态
		DFITCExtOrderTriggerStatusType  orderTriggerStatus; //条件单触发状态
		DFITCAmountType                 limitAmount;        //数量限制
		DFITCCompareFlagType            qtyCmpFlag;         //比较标志(数量)
		DFITCTriggerType                triggerType;        //触发类型	
		DFITCBreakDownTypeType          breakDownType;      //击穿属性	

	};



	///查询成交触发委托
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCQryMatchTriggerField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCPriceType                  insertPrice;        //委托价格
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCAmountType                 matchedAmount;      //成交数量
		DFITCAmountType                 cancelAmount;       //撤单数量
		DFITCSPDOrderIDType             spdOrderID;         //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           trigInstrumentID;   //合约代码
		DFITCBuySellTypeType            trigBuySellType;    //买卖标志
		DFITCOpenCloseTypeType          trigOpenCloseType;  //开平标志
		DFITCSpeculatorType             trigSpeculator;     //投保类型
		DFITCPriceType                  trigInsertPrice;    //委托价格
		DFITCAmountType                 trigOrderAmount;    //委托数量 
		DFITCSPDOrderIDType             trigSpdOrderID;     //柜台委托号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commdate;           //委托日期
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //委托时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //撤单时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //修改时间
		DFITCOrderTypeType              orderType;          //报单类型
		DFITCProfitLossType             frozenMargin;       //冻结资金
		DFITCAmountType                 frozenAmount;       //冻结数量
		DFITCCompareFlagType            compareFlag;        //比较标志
		DFITCPriceType                  comparePrice;       //触发价格
		DFITCPriceReferenceType         priceReference;     //价格参照
		DFITCBreakDownTimesType         breakDownTimes;     //击穿次数
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //有效日期
		DFITCSPDOrderIDType             trigExtSpdOrderID;  //条件单编号
		DFITCExtOrderType               extOrderType;       //条件单类型
		DFITCOrderAnswerStatusType      orderStatus;        //委托状态
	};

	///查询止损止盈触犯委托
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCProfitLossRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             spdOrderID;         //柜台委托号
		DFITCSPDOrderIDType             trigSpdOrderID;     //柜台委托号
		DFITCSPDOrderIDType             trigExtSpdOrderID;  //条件单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		DFITCPriceType                  insertPrice;        //委托价格
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCPriceType                  comparePriceFall;   //下跌触发价差
		DFITCPriceType                  insertPriceFall;    //下跌委托价差
		DFITCAddPriceTimesType          addPriceTimesFall;  //下跌追价次数
		DFITCOrderTypeType              orderTypeFall;      //下跌报单类型
		DFITCPriceType                  comparePriceRise;   //上涨触发价差
		DFITCPriceType                  insertPriceRise;    //上涨委托价差
		DFITCAddPriceTimesType          addPriceTimesRise;  //上涨追价次数
		DFITCOrderTypeType              orderTypeRise;      //上涨报单类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   validate;           //有效日期
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //委托时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   canceledTime;       //撤单时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //修改时间
		DFITCOrderAnswerStatusType      orderStatus;        //委托状态
	};

	///查询套利触发触发委托
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCArbitrageRspField
	{
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
		DFITCRequestIDType              lRequestID;         //请求ID 
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID;       //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID2;      //合约代码
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 64)]String^           instrumentID3;      //合约代码
		DFITCPriceType                  insertPrice;        //偏离板价
		DFITCAmountType                 orderAmount;        //委托数量
		DFITCSpeculatorType             speculator;         //投保类型
		DFITCBuySellTypeType            buySellType;        //买卖标志
		DFITCOpenCloseTypeType          openCloseType;      //开平标志
		DFITCPriceType                  insertPrice2;       //偏离板价2
		DFITCAmountType                 orderAmount2;       //委托数量2
		DFITCSpeculatorType             speculator2;        //投保类型2
		DFITCBuySellTypeType            buySellType2;       //买卖标志2
		DFITCOpenCloseTypeType          openCloseType2;     //开平标志2
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   modifiedtime;       //修改时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commTime;           //委托时间
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^                   commdate;           //委托日期
		DFITCPriceType                  priceMargin;        //价差
		DFITCArbitrageTypeType          arbitrageType;      //套利类型
		DFITCMinEntryType               minEntry;           //最小报单类型
		DFITCSplitContinueType          splitContinue;      //单腿是否继续
		DFITCPriceType                  deviatePrice;       //偏离板价
		DFITCOrderAnswerStatusType      orderStatus;        //委托状态
	};


	///条件单委托响应类型
	[StructLayout(LayoutKind::Sequential, CharSet = CharSet::Ansi)]
	public value struct CLRDFITCExtOrderRspDataField
	{
		DFITCLocalOrderIDType           localOrderID;       //本地委托号
		DFITCSPDOrderIDType             spdOrderID;         //柜台委托号
		DFITCSPDOrderIDType             extSpdOrderID;      //条件单编号
		DFITCOrderAnswerStatusType      orderStatus;        //委托状态
		DFITCRequestIDType              lRequestID;         //请求ID
		DFITCPriceType                  frozenMargin;       //冻结资金(仅下单使用)
		DFITCExtOrderType               extOrderType;       //条件单类型
		[MarshalAs(UnmanagedType::ByValTStr, SizeConst = 13)]String^              accountID;          //资金账户
	};
}