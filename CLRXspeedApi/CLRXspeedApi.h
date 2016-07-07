// CLRXspeedApi.h

#pragma once
#pragma comment(lib,"DFITCMdApi.lib")
#pragma comment(lib,"DFITCTraderApi.lib")

#pragma managed

#include <stdio.h>
#include <windows.h>
#include <string>
#include <gcroot.h>
#include <msclr/auto_gcroot.h>
#include "DFITCTraderApi.h"
#include "DFITCMdApi.h"
#include "CLRDFITCApiDataStruct.h"

using namespace System;
using namespace Collections;
using namespace Threading;
using namespace Tasks;
using namespace Runtime::InteropServices;

namespace CLRXspeedApi {

	public ref class CLRDFITCTraderSpi abstract
	{
	public:
		CLRDFITCTraderSpi();
		~CLRDFITCTraderSpi();
		DFITCXSPEEDAPI::DFITCTraderSpi* m_pNativeSpi;
	protected:
		/* 网络连接正常响应:当客户端与交易后台需建立起通信连接时（还未登录前），客户端API会自动检测与前置机之间的连接，
		* 当网络可用，将自动建立连接，并调用该方法通知客户端， 客户端可以在实现该方法时，重新使用资金账号进行登录。
		*（该方法是在Api和前置机建立连接后被调用，该调用仅仅是说明tcp连接已经建立成功。用户需要自行登录才能进行后续的业务操作。
		*  登录失败则此方法不会被调用。）
		*/
		virtual void OnFrontConnected() = 0;

		/**
		* 网络连接不正常响应：当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		* @param  nReason:错误原因。
		*        0x1001 网络读失败
		*        0x1002 网络写失败
		*        0x2001 接收心跳超时
		*        0x2002 发送心跳失败
		*        0x2003 收到错误报文
		*/
		virtual void OnFrontDisconnected(int nReason) = 0;

		/**
		* 登陆请求响应:当用户发出登录请求后，前置机返回响应时此方法会被调用，通知用户登录是否成功。
		* @param pUserLoginInfoRtn:用户登录信息结构地址。
		* @param pErrorInfo:若登录失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspUserLogin(CLRDFITCUserLoginInfoRtnField  RspUserLogin, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 登出请求响应:当用户发出退出请求后，前置机返回响应此方法会被调用，通知用户退出状态。
		* @param pUserLogoutInfoRtn:返回用户退出信息结构地址。
		* @param pErrorInfo:若登出失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspUserLogout(CLRDFITCUserLogoutInfoRtnField  RspUserLogout, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 期货委托报单响应:当用户录入报单后，前置返回响应时该方法会被调用。
		* @param pOrderRtn:返回用户下单信息结构地址。
		* @param pErrorInfo:若报单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspInsertOrder(CLRDFITCOrderRspDataRtnField  RspOrder, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 期货委托撤单响应:当用户撤单后，前置返回响应是该方法会被调用。
		* @param pOrderCanceledRtn:返回撤单响应信息结构地址。
		* @param pErrorInfo:若撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspCancelOrder(CLRDFITCOrderRspDataRtnField  RspOrderCancel, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 错误回报
		* @param pErrorInfo:错误信息的结构地址。
		*/
		virtual void OnRtnErrorMsg(CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 成交回报:当委托成功交易后此方法会被调用。
		* @param pRtnMatchData:指向成交回报的结构的指针。
		*/
		virtual void OnRtnMatchedInfo(CLRDFITCMatchRtnField  RtnMatchData) = 0;

		/**
		* 委托回报:下单委托成功后，此方法会被调用。
		* @param pRtnOrderData:指向委托回报地址的指针。
		*/
		virtual void OnRtnOrder(CLRDFITCOrderRtnField  RtnOrderData) = 0;

		/**
		* 撤单回报:当撤单成功后该方法会被调用。
		* @param pCancelOrderData:指向撤单回报结构的地址，该结构体包含被撤单合约的相关信息。
		*/
		virtual void OnRtnCancelOrder(CLRDFITCOrderCanceledRtnField  RtnCancelOrderData) = 0;

		/**
		* 查询当日委托响应:当用户发出委托查询后，该方法会被调用。
		* @param pRtnOrderData:指向委托回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryOrderInfo(CLRDFITCOrderCommRtnField  OrderData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 查询当日成交响应:当用户发出成交查询后该方法会被调用。
		* @param pRtnMatchData:指向成交回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryMatchInfo(CLRDFITCMatchedRtnField  MatchData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 持仓查询响应:当用户发出持仓查询指令后，前置返回响应时该方法会被调用。
		* @param pPositionInfoRtn:返回持仓信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryPosition(CLRDFITCPositionInfoRtnField  PositionInfo, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 客户资金查询响应:当用户发出资金查询指令后，前置返回响应时该方法会被调用。
		* @param pCapitalInfoRtn:返回资金信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspCustomerCapital(CLRDFITCCapitalInfoRtnField  CapitalInfo, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 交易所合约查询响应:当用户发出合约查询指令后，前置返回响应时该方法会被调用。
		* @param pInstrumentData:返回合约信息结构的地址。
		* @param pErrorInfo:错误信息结构，如果查询发生错误，则返回错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryExchangeInstrument(CLRDFITCExchangeInstrumentRtnField  InstrumentData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 套利合约查询响应:当用户发出套利合约查询指令后，前置返回响应时该方法会被调用。
		* @param pAbiInstrumentData:返回套利合约信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspArbitrageInstrument(CLRDFITCAbiInstrumentRtnField  AbiInstrumentData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 查询指定合约响应:当用户发出指定合约查询指令后，前置返回响应时该方法会被调用。
		* @param pInstrument:返回指定合约信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQrySpecifyInstrument(CLRDFITCInstrumentRtnField  Instrument, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 查询持仓明细响应:当用户发出查询持仓明细后，前置返回响应时该方法会被调用。
		* @param pPositionDetailRtn:返回持仓明细结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryPositionDetail(CLRDFITCPositionDetailRtnField  PositionDetail, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 交易通知响应:用于接收XSPEED柜台手动发送通知，即支持指定客户，也支持系统广播。
		* @param pTradingNoticeInfo: 返回用户事件通知结构的地址。
		*/
		virtual void OnRtnTradingNotice(CLRDFITCTradingNoticeInfoField  TradingNoticeInfo) = 0;

		/**
		* 密码修改响应:用于修改资金账户登录密码。
		* @param pResetPassword: 返回密码修改结构的地址。
		* @param pErrorInfo:若修改密码失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspResetPassword(CLRDFITCResetPwdRspField  ResetPassword, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 交易编码查询响应:返回交易编码信息
		* @param pTradeCode: 返回交易编码查询结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryTradeCode(CLRDFITCQryTradeCodeRtnField  TradeCode, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 账单确认响应:用于接收客户账单确认状态。
		* @param pBillConfirm: 返回账单确认结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspBillConfirm(CLRDFITCBillConfirmRspField  BillConfirm, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 查询客户权益计算方式响应:返回客户权益计算的方式
		* @param pEquityComputMode: 返回客户权益计算方式结构的地址。
		*/
		virtual void OnRspEquityComputMode(CLRDFITCEquityComputModeRtnField  EquityComputMode) = 0;

		/**
		* 客户结算账单查询响应:返回账单信息
		* @param pQryBill: 返回客户结算账单查询结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryBill(CLRDFITCQryBillRtnField QryBill, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 厂商ID确认响应:用于接收厂商信息。
		* @param pProductRtnData: 返回厂商ID确认响应结构的地址。
		*/
		virtual void OnRspConfirmProductInfo(CLRDFITCProductRtnField  RspProductData) = 0;


		/**
		* 交易日确认响应:用于接收交易日信息。
		* @param DFITCTradingDayRtnField: 返回交易日请求确认响应结构的地址。
		*/
		virtual void OnRspTradingDay(CLRDFITCTradingDayRtnField  TradingDayRtnData) = 0;

		/**
		* 做市商报单响应
		* @param pRspQuoteData:指向做市商报单响应地址的指针。
		* @param pErrorInfo:若报价失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspQuoteInsert(CLRDFITCQuoteRspField  RspQuote, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 做市商报单回报
		* @param pRtnQuoteData:指向做市商报单回报地址的指针。
		*/
		virtual void OnRtnQuoteInsert(CLRDFITCQuoteRtnField  RtnQuote) = 0;

		/**
		* 做市商撤单响应
		* @param pRspQuoteCanceledData:指向做市商撤单响应地址的指针。
		* @param pErrorInfo:若撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspQuoteCancel(CLRDFITCQuoteRspField  RspQuoteCancel, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 做市商撤单回报
		* @param pRtnQuoteCanceledData:指向做市商撤单回报地址的指针。
		*/
		virtual void OnRtnQuoteCancel(CLRDFITCQuoteCanceledRtnField  RtnQuoteCanceled) = 0;

		/**
		* 做市商成交回报
		* @param pRtnQuoteMatchedData:指向做市商成交回报地址的指针。
		*/
		virtual void OnRtnQuoteMatchedInfo(CLRDFITCQuoteMatchRtnField  RtnQuoteMatched) = 0;

		/**
		* 做市商询价通知，无需订阅，做市商客户自动收到询价通知
		* @param pForQuoteRspData:指向询价通知回报地址的指针。
		*/
		virtual void OnRtnForQuoteRsp(CLRDFITCQuoteSubscribeRtnField  ForQuoteRspData) = 0;

		/**
		* 做市商批量撤单响应
		* @param pRspStripCancelOrderData:指向批量撤单响应地址的指针。
		* @param pErrorInfo:若批量撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspCancelAllOrder(CLRDFITCCancelAllOrderRspField RspCancelAllOrderData, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 询价通知查询响应
		* @param pRtnQryQuoteNoticeData:查询询价通知回报结构地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryQuoteNotice(CLRDFITCQryQuoteNoticeRtnField  QryQuoteNoticeData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 询价响应
		* @param pRspForQuoteData:询价请求响应结构地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspForQuote(CLRDFITCForQuoteRspField  RspForQuoteData, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 询价回报
		* @param pRtnForQuoteData:询价回报结构地址。
		*/
		virtual void OnRtnForQuote(CLRDFITCForQuoteRtnField  RtnForQuote) = 0;

		/**
		* 查询当日报价委托响应
		* @param pRtnQuoteOrderData:指向报价查询回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryQuoteOrderInfo(CLRDFITCQuoteOrderRtnField  QuoteOrderData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 询价委托查询响应
		* @param pRtnQryForQuoteData:指向询价委托查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryForQuote(CLRDFITCQryForQuoteRtnField  QryForQuoteData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 查询转帐银行响应
		* @param pTransferBank:指向查询转帐银行回报地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryTransferBank(CLRDFITCTransferBankRspField  TransferBank, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 查询转帐流水响应
		* @param pTransferSerial:指向查询转帐流水回报地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryTransferSerial(CLRDFITCTransferSerialRspField  TransferSerial, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 期货发起银行资金转期货应答
		* @param pRspTransfer:指向期货发起银行资金转期货应答地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspFromBankToFutureByFuture(CLRDFITCTransferRspField  RspTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 期货发起期货资金转银行应答
		* @param pRspTransfer:指向期货发起期货资金转银行应答地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspFromFutureToBankByFuture(CLRDFITCTransferRspField  RspTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 期货发起银行资金转期货通知
		* @param pRtnTransfer:指向期货发起银行资金转期货通知地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRtnFromBankToFutureByFuture(CLRDFITCTransferRtnField  RtnTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 期货发起期货资金转银行通知
		* @param pRtnTransfer:指向期货发起期货资金转银行通知地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRtnFromFutureToBankByFuture(CLRDFITCTransferRtnField  RtnTransfer, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 银行发起冲正期货转银行通知
		* @param pRspRepeal:指向期货发起期货资金转银行冲正通知地址的指针。
		*/
		virtual void OnRtnRepealFromFutureToBankByBank(CLRDFITCRepealRtnField  RspRepeal) = 0;

		/**
		* 交易所状态查询响应
		* @param pRspExchangeStatusData:指向交易所状态查询响应地址的指针。
		*/
		virtual void OnRspQryExchangeStatus(CLRDFITCExchangeStatusRspField  RspExchangeStatusData) = 0;

		/**
		* 交易所状态通知
		* @param pRtnExchangeStatusData:指向交易所状态通知地址的指针。
		*/
		virtual void OnRtnExchangeStatus(CLRDFITCExchangeStatusRtnField  RtnExchangeStatusData) = 0;

		/**
		* 行情查询响应
		* @param pDepthMarketData:指向行情查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryDepthMarketData(CLRDFITCDepthMarketDataField  DepthMarketData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 汇率查询响应
		* @param pExchangeRate:指向汇率查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryExchangeRate(CLRDFITCExchangeRateField ExchangeRate, CLRDFITCErrorRtnField RspInfo, bool bIsLast) = 0;

		/**
		* 行情触发查询响应:当用户发出行情触发查询指令后，前置返回响应时该方法会被调用。
		* @param pQryPricesTriggerRspData:返回行情查询信息结构的地址。
		* @param pErrorInfo:错误信息结构，如果行情触发发生错误，则返回错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryPricesTrigger(CLRDFITCQryPricesTriggerField QryPricesTriggerRspData, CLRDFITCErrorRtnField  ErrorInfo, bool bIsLast) = 0;

		/**
		* 条件单委托报单响应:当用户录入报单后，前置返回响应时该方法会被调用。
		* @param pOrderRsp:返回用户下单信息结构地址。
		* @param pErrorInfo:若请求失败，返回错误信息地址。
		*/
		virtual void OnRspExtInsertOrder(CLRDFITCExtOrderRspDataField  OrderRsp, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 条件单委托撤单响应:当用户撤单后，前置返回响应是该方法会被调用。
		* @param pOrderCancelRsp:返回撤单响应信息结构地址。
		* @param pErrorInfo:若请求失败，返回错误信息地址。
		*/
		virtual void OnRspExtCancelOrder(CLRDFITCExtOrderRspDataField  OrderCancelRsp, CLRDFITCErrorRtnField  ErrorInfo) = 0;

		/**
		* 条件单委托回报:当用户录入报单并被触发后该方法会被调用。
		* @param pOrderRtn:返回用户下单信息结构地址。
		*/
		virtual void OnRtnPricesTrigger(CLRDFITCPricesTriggerRtnField  OrderRtn) = 0;

	internal:
		/* 网络连接正常响应:当客户端与交易后台需建立起通信连接时（还未登录前），客户端API会自动检测与前置机之间的连接，
		* 当网络可用，将自动建立连接，并调用该方法通知客户端， 客户端可以在实现该方法时，重新使用资金账号进行登录。
		*（该方法是在Api和前置机建立连接后被调用，该调用仅仅是说明tcp连接已经建立成功。用户需要自行登录才能进行后续的业务操作。
		*  登录失败则此方法不会被调用。）
		*/
		void callOnFrontConnected();

		/**
		* 网络连接不正常响应：当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		* @param  nReason:错误原因。
		*        0x1001 网络读失败
		*        0x1002 网络写失败
		*        0x2001 接收心跳超时
		*        0x2002 发送心跳失败
		*        0x2003 收到错误报文
		*/
		void callOnFrontDisconnected(int nReason);
		/**
		* 登陆请求响应:当用户发出登录请求后，前置机返回响应时此方法会被调用，通知用户登录是否成功。
		* @param pUserLoginInfoRtn:用户登录信息结构地址。
		* @param pErrorInfo:若登录失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspUserLogin(struct DFITCUserLoginInfoRtnField * pRspUserLogin, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 登出请求响应:当用户发出退出请求后，前置机返回响应此方法会被调用，通知用户退出状态。
		* @param pUserLogoutInfoRtn:返回用户退出信息结构地址。
		* @param pErrorInfo:若登出失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspUserLogout(struct DFITCUserLogoutInfoRtnField * pRspUserLogout, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 期货委托报单响应:当用户录入报单后，前置返回响应时该方法会被调用。
		* @param pOrderRtn:返回用户下单信息结构地址。
		* @param pErrorInfo:若报单失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspInsertOrder(struct DFITCOrderRspDataRtnField * pRspOrder, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 期货委托撤单响应:当用户撤单后，前置返回响应是该方法会被调用。
		* @param pOrderCanceledRtn:返回撤单响应信息结构地址。
		* @param pErrorInfo:若撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspCancelOrder(struct DFITCOrderRspDataRtnField * pRspOrderCancel, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 错误回报
		* @param pErrorInfo:错误信息的结构地址。
		*/
		void callOnRtnErrorMsg(struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 成交回报:当委托成功交易后此方法会被调用。
		* @param pRtnMatchData:指向成交回报的结构的指针。
		*/
		void callOnRtnMatchedInfo(struct DFITCMatchRtnField * pRtnMatchData);

		/**
		* 委托回报:下单委托成功后，此方法会被调用。
		* @param pRtnOrderData:指向委托回报地址的指针。
		*/
		void callOnRtnOrder(struct DFITCOrderRtnField * pRtnOrderData);

		/**
		* 撤单回报:当撤单成功后该方法会被调用。
		* @param pCancelOrderData:指向撤单回报结构的地址，该结构体包含被撤单合约的相关信息。
		*/
		void callOnRtnCancelOrder(struct DFITCOrderCanceledRtnField * pRtnCancelOrderData);

		/**
		* 查询当日委托响应:当用户发出委托查询后，该方法会被调用。
		* @param pRtnOrderData:指向委托回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryOrderInfo(struct DFITCOrderCommRtnField * pOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 查询当日成交响应:当用户发出成交查询后该方法会被调用。
		* @param pRtnMatchData:指向成交回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryMatchInfo(struct DFITCMatchedRtnField * pMatchData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 持仓查询响应:当用户发出持仓查询指令后，前置返回响应时该方法会被调用。
		* @param pPositionInfoRtn:返回持仓信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryPosition(struct DFITCPositionInfoRtnField * pPositionInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 客户资金查询响应:当用户发出资金查询指令后，前置返回响应时该方法会被调用。
		* @param pCapitalInfoRtn:返回资金信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspCustomerCapital(struct DFITCCapitalInfoRtnField * pCapitalInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 交易所合约查询响应:当用户发出合约查询指令后，前置返回响应时该方法会被调用。
		* @param pInstrumentData:返回合约信息结构的地址。
		* @param pErrorInfo:错误信息结构，如果查询发生错误，则返回错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryExchangeInstrument(struct DFITCExchangeInstrumentRtnField * pInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 套利合约查询响应:当用户发出套利合约查询指令后，前置返回响应时该方法会被调用。
		* @param pAbiInstrumentData:返回套利合约信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspArbitrageInstrument(struct DFITCAbiInstrumentRtnField * pAbiInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 查询指定合约响应:当用户发出指定合约查询指令后，前置返回响应时该方法会被调用。
		* @param pInstrument:返回指定合约信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQrySpecifyInstrument(struct DFITCInstrumentRtnField * pInstrument, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 查询持仓明细响应:当用户发出查询持仓明细后，前置返回响应时该方法会被调用。
		* @param pPositionDetailRtn:返回持仓明细结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryPositionDetail(struct DFITCPositionDetailRtnField * pPositionDetail, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 交易通知响应:用于接收XSPEED柜台手动发送通知，即支持指定客户，也支持系统广播。
		* @param pTradingNoticeInfo: 返回用户事件通知结构的地址。
		*/
		void callOnRtnTradingNotice(struct DFITCTradingNoticeInfoField * pTradingNoticeInfo);

		/**
		* 密码修改响应:用于修改资金账户登录密码。
		* @param pResetPassword: 返回密码修改结构的地址。
		* @param pErrorInfo:若修改密码失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspResetPassword(struct DFITCResetPwdRspField * pResetPassword, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 交易编码查询响应:返回交易编码信息
		* @param pTradeCode: 返回交易编码查询结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryTradeCode(struct DFITCQryTradeCodeRtnField * pTradeCode, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 账单确认响应:用于接收客户账单确认状态。
		* @param pBillConfirm: 返回账单确认结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspBillConfirm(struct DFITCBillConfirmRspField * pBillConfirm, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 查询客户权益计算方式响应:返回客户权益计算的方式
		* @param pEquityComputMode: 返回客户权益计算方式结构的地址。
		*/
		void callOnRspEquityComputMode(struct DFITCEquityComputModeRtnField * pEquityComputMode);

		/**
		* 客户结算账单查询响应:返回账单信息
		* @param pQryBill: 返回客户结算账单查询结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryBill(struct DFITCQryBillRtnField *pQryBill, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 厂商ID确认响应:用于接收厂商信息。
		* @param pProductRtnData: 返回厂商ID确认响应结构的地址。
		*/
		void callOnRspConfirmProductInfo(struct DFITCProductRtnField * pRspProductData);


		/**
		* 交易日确认响应:用于接收交易日信息。
		* @param DFITCTradingDayRtnField: 返回交易日请求确认响应结构的地址。
		*/
		void callOnRspTradingDay(struct DFITCTradingDayRtnField * pTradingDayRtnData);

		/**
		* 做市商报单响应
		* @param pRspQuoteData:指向做市商报单响应地址的指针。
		* @param pErrorInfo:若报价失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspQuoteInsert(struct DFITCQuoteRspField * pRspQuote, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 做市商报单回报
		* @param pRtnQuoteData:指向做市商报单回报地址的指针。
		*/
		void callOnRtnQuoteInsert(struct DFITCQuoteRtnField * pRtnQuote);

		/**
		* 做市商撤单响应
		* @param pRspQuoteCanceledData:指向做市商撤单响应地址的指针。
		* @param pErrorInfo:若撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspQuoteCancel(struct DFITCQuoteRspField * pRspQuoteCancel, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 做市商撤单回报
		* @param pRtnQuoteCanceledData:指向做市商撤单回报地址的指针。
		*/
		void callOnRtnQuoteCancel(struct DFITCQuoteCanceledRtnField * pRtnQuoteCanceled);

		/**
		* 做市商成交回报
		* @param pRtnQuoteMatchedData:指向做市商成交回报地址的指针。
		*/
		void callOnRtnQuoteMatchedInfo(struct DFITCQuoteMatchRtnField * pRtnQuoteMatched);

		/**
		* 做市商询价通知，无需订阅，做市商客户自动收到询价通知
		* @param pForQuoteRspData:指向询价通知回报地址的指针。
		*/
		void callOnRtnForQuoteRsp(struct DFITCQuoteSubscribeRtnField * pForQuoteRspData);

		/**
		* 做市商批量撤单响应
		* @param pRspStripCancelOrderData:指向批量撤单响应地址的指针。
		* @param pErrorInfo:若批量撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspCancelAllOrder(struct DFITCCancelAllOrderRspField *pRspCancelAllOrderData, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 询价通知查询响应
		* @param pRtnQryQuoteNoticeData:查询询价通知回报结构地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryQuoteNotice(struct DFITCQryQuoteNoticeRtnField * pQryQuoteNoticeData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 询价响应
		* @param pRspForQuoteData:询价请求响应结构地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspForQuote(struct DFITCForQuoteRspField * pRspForQuoteData, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 询价回报
		* @param pRtnForQuoteData:询价回报结构地址。
		*/
		void callOnRtnForQuote(struct DFITCForQuoteRtnField * pRtnForQuote);

		/**
		* 查询当日报价委托响应
		* @param pRtnQuoteOrderData:指向报价查询回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryQuoteOrderInfo(struct DFITCQuoteOrderRtnField * pQuoteOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 询价委托查询响应
		* @param pRtnQryForQuoteData:指向询价委托查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryForQuote(struct DFITCQryForQuoteRtnField * pQryForQuoteData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 查询转帐银行响应
		* @param pTransferBank:指向查询转帐银行回报地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryTransferBank(struct DFITCTransferBankRspField * pTransferBank, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 查询转帐流水响应
		* @param pTransferSerial:指向查询转帐流水回报地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryTransferSerial(struct DFITCTransferSerialRspField * pTransferSerial, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 期货发起银行资金转期货应答
		* @param pRspTransfer:指向期货发起银行资金转期货应答地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspFromBankToFutureByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 期货发起期货资金转银行应答
		* @param pRspTransfer:指向期货发起期货资金转银行应答地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRspFromFutureToBankByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 期货发起银行资金转期货通知
		* @param pRtnTransfer:指向期货发起银行资金转期货通知地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRtnFromBankToFutureByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 期货发起期货资金转银行通知
		* @param pRtnTransfer:指向期货发起期货资金转银行通知地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		void callOnRtnFromFutureToBankByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 银行发起冲正期货转银行通知
		* @param pRspRepeal:指向期货发起期货资金转银行冲正通知地址的指针。
		*/
		void callOnRtnRepealFromFutureToBankByBank(DFITCRepealRtnField * pRspRepeal);

		/**
		* 交易所状态查询响应
		* @param pRspExchangeStatusData:指向交易所状态查询响应地址的指针。
		*/
		void callOnRspQryExchangeStatus(struct DFITCExchangeStatusRspField * pRspExchangeStatusData);

		/**
		* 交易所状态通知
		* @param pRtnExchangeStatusData:指向交易所状态通知地址的指针。
		*/
		void callOnRtnExchangeStatus(struct DFITCExchangeStatusRtnField * pRtnExchangeStatusData);

		/**
		* 行情查询响应
		* @param pDepthMarketData:指向行情查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryDepthMarketData(struct DFITCDepthMarketDataField * pDepthMarketData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 汇率查询响应
		* @param pExchangeRate:指向汇率查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryExchangeRate(struct DFITCExchangeRateField *pExchangeRate, DFITCErrorRtnField *pRspInfo, bool bIsLast);

		/**
		* 行情触发查询响应:当用户发出行情触发查询指令后，前置返回响应时该方法会被调用。
		* @param pQryPricesTriggerRspData:返回行情查询信息结构的地址。
		* @param pErrorInfo:错误信息结构，如果行情触发发生错误，则返回错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		void callOnRspQryPricesTrigger(struct DFITCQryPricesTriggerField  *pQryPricesTriggerRspData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast);

		/**
		* 条件单委托报单响应:当用户录入报单后，前置返回响应时该方法会被调用。
		* @param pOrderRsp:返回用户下单信息结构地址。
		* @param pErrorInfo:若请求失败，返回错误信息地址。
		*/
		void callOnRspExtInsertOrder(struct DFITCExtOrderRspDataField * pOrderRsp, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 条件单委托撤单响应:当用户撤单后，前置返回响应是该方法会被调用。
		* @param pOrderCancelRsp:返回撤单响应信息结构地址。
		* @param pErrorInfo:若请求失败，返回错误信息地址。
		*/
		void callOnRspExtCancelOrder(struct DFITCExtOrderRspDataField * pOrderCancelRsp, struct DFITCErrorRtnField * pErrorInfo);

		/**
		* 条件单委托回报:当用户录入报单并被触发后该方法会被调用。
		* @param pOrderRtn:返回用户下单信息结构地址。
		*/
		void callOnRtnPricesTrigger(struct DFITCPricesTriggerRtnField * pOrderRtn);
	};

	class TradeSpiHandler : public DFITCXSPEEDAPI::DFITCTraderSpi
	{
	public:
		TradeSpiHandler(CLRDFITCTraderSpi ^owner) : m_owner(owner) {};
		~TradeSpiHandler() {};
		gcroot<CLRDFITCTraderSpi^> m_owner;
	public:
		/* 网络连接正常响应:当客户端与交易后台需建立起通信连接时（还未登录前），客户端API会自动检测与前置机之间的连接，
		* 当网络可用，将自动建立连接，并调用该方法通知客户端， 客户端可以在实现该方法时，重新使用资金账号进行登录。
		*（该方法是在Api和前置机建立连接后被调用，该调用仅仅是说明tcp连接已经建立成功。用户需要自行登录才能进行后续的业务操作。
		*  登录失败则此方法不会被调用。）
		*/
		virtual void OnFrontConnected() 
		{ 
			m_owner->callOnFrontConnected(); 
		}

		/**
		* 网络连接不正常响应：当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		* @param  nReason:错误原因。
		*        0x1001 网络读失败
		*        0x1002 网络写失败
		*        0x2001 接收心跳超时
		*        0x2002 发送心跳失败
		*        0x2003 收到错误报文
		*/
		virtual void OnFrontDisconnected(int nReason) 
		{ 
			m_owner->callOnFrontDisconnected(nReason); 
		}
		/**
		* 登陆请求响应:当用户发出登录请求后，前置机返回响应时此方法会被调用，通知用户登录是否成功。
		* @param pUserLoginInfoRtn:用户登录信息结构地址。
		* @param pErrorInfo:若登录失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspUserLogin(struct DFITCUserLoginInfoRtnField * pRspUserLogin, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspUserLogin(pRspUserLogin, pErrorInfo);
		}

		/**
		* 登出请求响应:当用户发出退出请求后，前置机返回响应此方法会被调用，通知用户退出状态。
		* @param pUserLogoutInfoRtn:返回用户退出信息结构地址。
		* @param pErrorInfo:若登出失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspUserLogout(struct DFITCUserLogoutInfoRtnField * pRspUserLogout, struct DFITCErrorRtnField * pErrorInfo) 
		{ 
			m_owner->callOnRspUserLogout(pRspUserLogout, pErrorInfo); 
		}

		/**
		* 期货委托报单响应:当用户录入报单后，前置返回响应时该方法会被调用。
		* @param pOrderRtn:返回用户下单信息结构地址。
		* @param pErrorInfo:若报单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspInsertOrder(struct DFITCOrderRspDataRtnField * pRspOrder, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspInsertOrder(pRspOrder, pErrorInfo);
		}

		/**
		* 期货委托撤单响应:当用户撤单后，前置返回响应是该方法会被调用。
		* @param pOrderCanceledRtn:返回撤单响应信息结构地址。
		* @param pErrorInfo:若撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspCancelOrder(struct DFITCOrderRspDataRtnField * pRspOrderCancel, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspCancelOrder(pRspOrderCancel, pErrorInfo);
		}

		/**
		* 错误回报
		* @param pErrorInfo:错误信息的结构地址。
		*/
		virtual void OnRtnErrorMsg(struct DFITCErrorRtnField * pErrorInfo) { m_owner->callOnRtnErrorMsg(pErrorInfo); }

		/**
		* 成交回报:当委托成功交易后此方法会被调用。
		* @param pRtnMatchData:指向成交回报的结构的指针。
		*/
		virtual void OnRtnMatchedInfo(struct DFITCMatchRtnField * pRtnMatchData) { m_owner->callOnRtnMatchedInfo(pRtnMatchData); }

		/**
		* 委托回报:下单委托成功后，此方法会被调用。
		* @param pRtnOrderData:指向委托回报地址的指针。
		*/
		virtual void OnRtnOrder(struct DFITCOrderRtnField * pRtnOrderData) { m_owner->callOnRtnOrder(pRtnOrderData); }

		/**
		* 撤单回报:当撤单成功后该方法会被调用。
		* @param pCancelOrderData:指向撤单回报结构的地址，该结构体包含被撤单合约的相关信息。
		*/
		virtual void OnRtnCancelOrder(struct DFITCOrderCanceledRtnField * pRtnCancelOrderData) 
		{ 
			m_owner->callOnRtnCancelOrder(pRtnCancelOrderData); 
		}

		/**
		* 查询当日委托响应:当用户发出委托查询后，该方法会被调用。
		* @param pRtnOrderData:指向委托回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryOrderInfo(struct DFITCOrderCommRtnField * pOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryOrderInfo(pOrderData, pErrorInfo, bIsLast);
		}

		/**
		* 查询当日成交响应:当用户发出成交查询后该方法会被调用。
		* @param pRtnMatchData:指向成交回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryMatchInfo(struct DFITCMatchedRtnField * pMatchData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryMatchInfo(pMatchData, pErrorInfo, bIsLast);
		}

		/**
		* 持仓查询响应:当用户发出持仓查询指令后，前置返回响应时该方法会被调用。
		* @param pPositionInfoRtn:返回持仓信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryPosition(struct DFITCPositionInfoRtnField * pPositionInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryPosition(pPositionInfo, pErrorInfo, bIsLast);
		}

		/**
		* 客户资金查询响应:当用户发出资金查询指令后，前置返回响应时该方法会被调用。
		* @param pCapitalInfoRtn:返回资金信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspCustomerCapital(struct DFITCCapitalInfoRtnField * pCapitalInfo, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspCustomerCapital(pCapitalInfo, pErrorInfo, bIsLast);
		}

		/**
		* 交易所合约查询响应:当用户发出合约查询指令后，前置返回响应时该方法会被调用。
		* @param pInstrumentData:返回合约信息结构的地址。
		* @param pErrorInfo:错误信息结构，如果查询发生错误，则返回错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryExchangeInstrument(struct DFITCExchangeInstrumentRtnField * pInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryExchangeInstrument(pInstrumentData, pErrorInfo, bIsLast);
		}

		/**
		* 套利合约查询响应:当用户发出套利合约查询指令后，前置返回响应时该方法会被调用。
		* @param pAbiInstrumentData:返回套利合约信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspArbitrageInstrument(struct DFITCAbiInstrumentRtnField * pAbiInstrumentData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspArbitrageInstrument(pAbiInstrumentData, pErrorInfo, bIsLast);
		}

		/**
		* 查询指定合约响应:当用户发出指定合约查询指令后，前置返回响应时该方法会被调用。
		* @param pInstrument:返回指定合约信息结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQrySpecifyInstrument(struct DFITCInstrumentRtnField * pInstrument, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQrySpecifyInstrument(pInstrument, pErrorInfo, bIsLast);
		}

		/**
		* 查询持仓明细响应:当用户发出查询持仓明细后，前置返回响应时该方法会被调用。
		* @param pPositionDetailRtn:返回持仓明细结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryPositionDetail(struct DFITCPositionDetailRtnField * pPositionDetail, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryPositionDetail(pPositionDetail, pErrorInfo, bIsLast);
		}

		/**
		* 交易通知响应:用于接收XSPEED柜台手动发送通知，即支持指定客户，也支持系统广播。
		* @param pTradingNoticeInfo: 返回用户事件通知结构的地址。
		*/
		virtual void OnRtnTradingNotice(struct DFITCTradingNoticeInfoField * pTradingNoticeInfo) 
		{ 
			m_owner->callOnRtnTradingNotice(pTradingNoticeInfo); 
		}

		/**
		* 密码修改响应:用于修改资金账户登录密码。
		* @param pResetPassword: 返回密码修改结构的地址。
		* @param pErrorInfo:若修改密码失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspResetPassword(struct DFITCResetPwdRspField * pResetPassword, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspResetPassword(pResetPassword, pErrorInfo);
		}

		/**
		* 交易编码查询响应:返回交易编码信息
		* @param pTradeCode: 返回交易编码查询结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryTradeCode(struct DFITCQryTradeCodeRtnField * pTradeCode, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryTradeCode(pTradeCode, pErrorInfo, bIsLast);
		}

		/**
		* 账单确认响应:用于接收客户账单确认状态。
		* @param pBillConfirm: 返回账单确认结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspBillConfirm(struct DFITCBillConfirmRspField * pBillConfirm, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspBillConfirm(pBillConfirm, pErrorInfo);
		}

		/**
		* 查询客户权益计算方式响应:返回客户权益计算的方式
		* @param pEquityComputMode: 返回客户权益计算方式结构的地址。
		*/
		virtual void OnRspEquityComputMode(struct DFITCEquityComputModeRtnField * pEquityComputMode) 
		{
			m_owner->callOnRspEquityComputMode(pEquityComputMode);
		}

		/**
		* 客户结算账单查询响应:返回账单信息
		* @param pQryBill: 返回客户结算账单查询结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryBill(struct DFITCQryBillRtnField *pQryBill, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryBill(pQryBill, pErrorInfo, bIsLast);
		}

		/**
		* 厂商ID确认响应:用于接收厂商信息。
		* @param pProductRtnData: 返回厂商ID确认响应结构的地址。
		*/
		virtual void OnRspConfirmProductInfo(struct DFITCProductRtnField * pRspProductData) 
		{
			m_owner->callOnRspConfirmProductInfo(pRspProductData);
		}


		/**
		* 交易日确认响应:用于接收交易日信息。
		* @param DFITCTradingDayRtnField: 返回交易日请求确认响应结构的地址。
		*/
		virtual void OnRspTradingDay(struct DFITCTradingDayRtnField * pTradingDayRtnData) 
		{
			m_owner->callOnRspTradingDay(pTradingDayRtnData);
		}

		/**
		* 做市商报单响应
		* @param pRspQuoteData:指向做市商报单响应地址的指针。
		* @param pErrorInfo:若报价失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspQuoteInsert(struct DFITCQuoteRspField * pRspQuote, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspQuoteInsert(pRspQuote, pErrorInfo);
		}

		/**
		* 做市商报单回报
		* @param pRtnQuoteData:指向做市商报单回报地址的指针。
		*/
		virtual void OnRtnQuoteInsert(struct DFITCQuoteRtnField * pRtnQuote) 
		{
			m_owner->callOnRtnQuoteInsert(pRtnQuote);
		}

		/**
		* 做市商撤单响应
		* @param pRspQuoteCanceledData:指向做市商撤单响应地址的指针。
		* @param pErrorInfo:若撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspQuoteCancel(struct DFITCQuoteRspField * pRspQuoteCancel, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspQuoteCancel(pRspQuoteCancel, pErrorInfo);
		}

		/**
		* 做市商撤单回报
		* @param pRtnQuoteCanceledData:指向做市商撤单回报地址的指针。
		*/
		virtual void OnRtnQuoteCancel(struct DFITCQuoteCanceledRtnField * pRtnQuoteCanceled) 
		{
			m_owner->callOnRtnQuoteCancel(pRtnQuoteCanceled);
		}

		/**
		* 做市商成交回报
		* @param pRtnQuoteMatchedData:指向做市商成交回报地址的指针。
		*/
		virtual void OnRtnQuoteMatchedInfo(struct DFITCQuoteMatchRtnField * pRtnQuoteMatched) 
		{
			m_owner->callOnRtnQuoteMatchedInfo(pRtnQuoteMatched);
		}

		/**
		* 做市商询价通知，无需订阅，做市商客户自动收到询价通知
		* @param pForQuoteRspData:指向询价通知回报地址的指针。
		*/
		virtual void OnRtnForQuoteRsp(struct DFITCQuoteSubscribeRtnField * pForQuoteRspData) 
		{
			m_owner->callOnRtnForQuoteRsp(pForQuoteRspData);
		}

		/**
		* 做市商批量撤单响应
		* @param pRspStripCancelOrderData:指向批量撤单响应地址的指针。
		* @param pErrorInfo:若批量撤单失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspCancelAllOrder(struct DFITCCancelAllOrderRspField *pRspCancelAllOrderData, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspCancelAllOrder(pRspCancelAllOrderData, pErrorInfo);
		}

		/**
		* 询价通知查询响应
		* @param pRtnQryQuoteNoticeData:查询询价通知回报结构地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryQuoteNotice(struct DFITCQryQuoteNoticeRtnField * pQryQuoteNoticeData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryQuoteNotice(pQryQuoteNoticeData, pErrorInfo, bIsLast);
		}

		/**
		* 询价响应
		* @param pRspForQuoteData:询价请求响应结构地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspForQuote(struct DFITCForQuoteRspField * pRspForQuoteData, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspForQuote(pRspForQuoteData, pErrorInfo);
		}

		/**
		* 询价回报
		* @param pRtnForQuoteData:询价回报结构地址。
		*/
		virtual void OnRtnForQuote(struct DFITCForQuoteRtnField * pRtnForQuote) 
		{
			m_owner->callOnRtnForQuote(pRtnForQuote);
		}

		/**
		* 查询当日报价委托响应
		* @param pRtnQuoteOrderData:指向报价查询回报结构的地址。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryQuoteOrderInfo(struct DFITCQuoteOrderRtnField * pQuoteOrderData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryQuoteOrderInfo(pQuoteOrderData, pErrorInfo, bIsLast);
		}

		/**
		* 询价委托查询响应
		* @param pRtnQryForQuoteData:指向询价委托查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryForQuote(struct DFITCQryForQuoteRtnField * pQryForQuoteData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryForQuote(pQryForQuoteData, pErrorInfo, bIsLast);
		}

		/**
		* 查询转帐银行响应
		* @param pTransferBank:指向查询转帐银行回报地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryTransferBank(struct DFITCTransferBankRspField * pTransferBank, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryTransferBank(pTransferBank, pErrorInfo, bIsLast);
		}

		/**
		* 查询转帐流水响应
		* @param pTransferSerial:指向查询转帐流水回报地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryTransferSerial(struct DFITCTransferSerialRspField * pTransferSerial, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryTransferSerial(pTransferSerial, pErrorInfo, bIsLast);
		}

		/**
		* 期货发起银行资金转期货应答
		* @param pRspTransfer:指向期货发起银行资金转期货应答地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspFromBankToFutureByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspFromBankToFutureByFuture(pRspTransfer, pErrorInfo);
		}

		/**
		* 期货发起期货资金转银行应答
		* @param pRspTransfer:指向期货发起期货资金转银行应答地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRspFromFutureToBankByFuture(struct DFITCTransferRspField * pRspTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspFromFutureToBankByFuture(pRspTransfer, pErrorInfo);
		}

		/**
		* 期货发起银行资金转期货通知
		* @param pRtnTransfer:指向期货发起银行资金转期货通知地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRtnFromBankToFutureByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRtnFromBankToFutureByFuture(pRtnTransfer, pErrorInfo);
		}

		/**
		* 期货发起期货资金转银行通知
		* @param pRtnTransfer:指向期货发起期货资金转银行通知地址的指针。
		* @param pErrorInfo:若转账失败，返回错误信息地址，该结构含有错误信息。
		*/
		virtual void OnRtnFromFutureToBankByFuture(DFITCTransferRtnField * pRtnTransfer, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRtnFromFutureToBankByFuture(pRtnTransfer, pErrorInfo);
		}

		/**
		* 银行发起冲正期货转银行通知
		* @param pRspRepeal:指向期货发起期货资金转银行冲正通知地址的指针。
		*/
		virtual void OnRtnRepealFromFutureToBankByBank(DFITCRepealRtnField * pRspRepeal) 
		{
			m_owner->callOnRtnRepealFromFutureToBankByBank(pRspRepeal);
		}

		/**
		* 交易所状态查询响应
		* @param pRspExchangeStatusData:指向交易所状态查询响应地址的指针。
		*/
		virtual void OnRspQryExchangeStatus(struct DFITCExchangeStatusRspField * pRspExchangeStatusData) 
		{
			m_owner->callOnRspQryExchangeStatus(pRspExchangeStatusData);
		}

		/**
		* 交易所状态通知
		* @param pRtnExchangeStatusData:指向交易所状态通知地址的指针。
		*/
		virtual void OnRtnExchangeStatus(struct DFITCExchangeStatusRtnField * pRtnExchangeStatusData) 
		{
			m_owner->callOnRtnExchangeStatus(pRtnExchangeStatusData);
		}

		/**
		* 行情查询响应
		* @param pDepthMarketData:指向行情查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryDepthMarketData(struct DFITCDepthMarketDataField * pDepthMarketData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryDepthMarketData(pDepthMarketData, pErrorInfo, bIsLast);
		}

		/**
		* 汇率查询响应
		* @param pExchangeRate:指向汇率查询响应地址的指针。
		* @param pErrorInfo:若查询失败，返回错误信息地址，该结构含有错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryExchangeRate(struct DFITCExchangeRateField *pExchangeRate, DFITCErrorRtnField *pRspInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryExchangeRate(pExchangeRate, pRspInfo, bIsLast);
		}

		/**
		* 行情触发查询响应:当用户发出行情触发查询指令后，前置返回响应时该方法会被调用。
		* @param pQryPricesTriggerRspData:返回行情查询信息结构的地址。
		* @param pErrorInfo:错误信息结构，如果行情触发发生错误，则返回错误信息。
		* @param bIsLast:表明是否是最后一条响应信息（0 -否   1 -是）。
		*/
		virtual void OnRspQryPricesTrigger(struct DFITCQryPricesTriggerField  *pQryPricesTriggerRspData, struct DFITCErrorRtnField * pErrorInfo, bool bIsLast) 
		{
			m_owner->callOnRspQryPricesTrigger(pQryPricesTriggerRspData, pErrorInfo, bIsLast);
		}

		/**
		* 条件单委托报单响应:当用户录入报单后，前置返回响应时该方法会被调用。
		* @param pOrderRsp:返回用户下单信息结构地址。
		* @param pErrorInfo:若请求失败，返回错误信息地址。
		*/
		virtual void OnRspExtInsertOrder(struct DFITCExtOrderRspDataField * pOrderRsp, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspExtInsertOrder(pOrderRsp, pErrorInfo);
		}

		/**
		* 条件单委托撤单响应:当用户撤单后，前置返回响应是该方法会被调用。
		* @param pOrderCancelRsp:返回撤单响应信息结构地址。
		* @param pErrorInfo:若请求失败，返回错误信息地址。
		*/
		virtual void OnRspExtCancelOrder(struct DFITCExtOrderRspDataField * pOrderCancelRsp, struct DFITCErrorRtnField * pErrorInfo) 
		{
			m_owner->callOnRspExtCancelOrder(pOrderCancelRsp, pErrorInfo);
		}

		/**
		* 条件单委托回报:当用户录入报单并被触发后该方法会被调用。
		* @param pOrderRtn:返回用户下单信息结构地址。
		*/
		virtual void OnRtnPricesTrigger(struct DFITCPricesTriggerRtnField * pOrderRtn) 
		{
			m_owner->callOnRtnPricesTrigger(pOrderRtn);
		}
	};

	public ref class CLRDFITCTraderApi
	{
	public:
		CLRDFITCTraderApi()
		{
			m_pNativeApi = DFITCXSPEEDAPI::DFITCTraderApi::CreateDFITCTraderApi();
		}
		~CLRDFITCTraderApi()
		{
			if (m_pNativeApi)
			{
				delete m_pNativeApi;
				m_pNativeApi = 0;
			}
		}
		/**
          * 删除接口对象本身，不再使用本接口对象时,调用该函数删除接口对象。
          */
         void Release(void);

         /**
          * 和服务器建立socket连接，并启动一个接收线程， 同时该方法注册一个回调函数集
          * @param pszFrontAddr:交易前置网络地址。
          *                     网络地址的格式为:"protocol://ipaddress:port",如"tcp://172.21.200.103:10910"
          *                     其中protocol的值为tcp格式。
          *                     ipaddress表示交易前置的IP,port表示交易前置的端口     
          * @param^ Spi:类DFITCTraderSpi对象实例
          * @return 0 - 初始化成功; -1 - 初始化失败。
          */
         int Init(String^ FrontAddr, CLRDFITCTraderSpi^ Spi);

         /**
          * 等待接口线程结束运行。
          * @return 线程退出代码。
          */
         int Join(void);

         /**
          * 用户发出登录请求
          * @param pUserLoginData:指向用户登录请求结构的地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */ 
         int ReqUserLogin(CLRDFITCUserLoginField^ UserLoginData);

         /**
          * 用户发出登出请求
          * @param pUserLogoutData:指向用户登录请出结构的地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */ 
         int ReqUserLogout(CLRDFITCUserLogoutField^ UserLogoutData);

         /**
          * 期货期权委托报单请求。
          * @param pInsertOrderData:用户请求报单信息结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqInsertOrder(CLRDFITCInsertOrderField^ InsertOrderData);

         /**
          * 期货期权撤单请求。
          * @param pCancelOrderData:用户请求撤单信息结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          * (如果提供柜台委托号(柜台委托号大于-1)，则只使用柜台委托号处理；只有当柜台委托号小于0时，才使用本地委托号进行撤单)
          */
         int ReqCancelOrder(CLRDFITCCancelOrderField^ CancelOrderData);

         /**
          * 持仓查询请求。
          * @param pPositionData:用户请求持仓信息结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          *（如果没有提供合约代码，则查询全部持仓信息。）
          */
         int ReqQryPosition(CLRDFITCPositionField^ PositionData);

         /**
          * 客户资金查询请求。
          * @param pCapitalData:请求资金查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryCustomerCapital(CLRDFITCCapitalField^ CapitalData);

         /**
          * 查询交易所合约列表（非套利）。
          * @param pExchangeInstrumentData:交易所合约查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryExchangeInstrument(CLRDFITCExchangeInstrumentField^ ExchangeInstrumentData);

         /**
          * 查询交易所套利合约列表。
          * @param pAbtriInstrumentData:交易所套利合约查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryArbitrageInstrument(CLRDFITCAbiInstrumentField^ AbtriInstrumentData);

         /**
          * 当日委托查询请求。
          * @param pOrderData:当日委托查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryOrderInfo(CLRDFITCOrderField^ OrderData);

         /**
          * 当日成交查询请求。
          * @param pMatchData:当日成交查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryMatchInfo(CLRDFITCMatchField^ MatchData);

         /**
          * 指定合约信息（合约保证金率，手续费率）查询请求。
          * @param pInstrument:指定合约查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQrySpecifyInstrument(CLRDFITCSpecificInstrumentField^ Instrument);

         /**
          * 持仓明细查询请求。
          * @param pPositionDetailData:持仓明细查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryPositionDetail(CLRDFITCPositionDetailField^ PositionDetailData);

         /**
          * 厂商ID确认请求。
          * @param pConfirmProductData:厂商ID确认结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败 -其它 -检测异常。
          */
         int ReqConfirmProductInfo(CLRDFITCProductField^ ConfirmProductData);

         /**
          * 密码修改请求
          * @param pResetPasswordData:密码修改结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqResetPassword (CLRDFITCResetPwdField^ ResetPasswordData);

         /**
          * 账单确认请求。
          * @param pBillConfirmData:账单确认结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqBillConfirm(CLRDFITCBillConfirmField^ BillConfirmData);

         /**
          * 交易编码查询请求。
          * @param pTradeCodeData:交易编码查询请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryTradeCode(CLRDFITCQryTradeCodeField^ TradeCodeData);

         /**
          * 查询客户权益计算方式请求。
          * @return 0 - 请求发送成功; -1 - 请求发送失败。
          */
         int ReqEquityComputMode();

         /**
          * 客户账单结算查询请求。
          * @param pQryBillData:客户账单结算请求结构地址。 
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryBill(CLRDFITCQryBillField^ QryBillData);

         /**
          * 交易日查询请求
          * @param pTradingDay:交易日查询请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败 -其它 -检测异常。
          */
         int ReqTradingDay(CLRDFITCTradingDayField^ TradingDay);

         /**
          * 询价通知查询请求
          * @param pQryQuoteNoticeData:查询询价通知请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryQuoteNotice(CLRDFITCQryQuoteNoticeField^ QryQuoteNoticeData);

         /**
          * 做市商报单请求
          * @param pQuoteInsertOrderData:做市商报单请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQuoteInsert(CLRDFITCQuoteInsertField^ QuoteInsertOrderData) ;

         /**
          * 做市商撤单请求
          * @param pQuoteCancelOrderData:做市商撤单请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQuoteCancel(CLRDFITCCancelOrderField^ QuoteCancelOrderData);  

         /**
          * 做市商批量撤单
          * @param pCancelAllOrderData:批量撤单请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqCancelAllOrder(CLRDFITCCancelAllOrderField^ CancelAllOrderData);

         /**
          * 询价请求
          * @param pForQuoteData:询价请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqForQuote(CLRDFITCForQuoteField^ ForQuoteData);

         /**
          * 询价委托查询请求
          * @param pQryForQuoteData:询价委托查询请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryForQuote(CLRDFITCQryForQuoteField^ QryForQuoteData);

         /**
          * 做市商报价委托查询
          * @param pQuoteOrderData:做市商报价委托查询结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryQuoteOrderInfo(CLRDFITCQuoteOrderField^ QuoteOrderData);

         /**
          * 查询转账银行
          * @param pQryTransferBank:查询转账银行请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryTransferBank(CLRDFITCQryTransferBankField^ QryTransferBank);

         /**
          * 查询转帐流水
          * @param pQryTransferSerial:查询转帐流水请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryTransferSerial(CLRDFITCQryTransferSerialField^ QryTransferSerial);

         /**
          * 期货发起银行资金转期货
          * @param pReqTransfer:银行资金转期货请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqFromBankToFutureByFuture(CLRDFITCReqTransferField^ ReqTransfer);

         /**
          * 期货发起期货资金转银行
          * @param pReqTransfer:期货资金转银行请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqFromFutureToBankByFuture(CLRDFITCReqTransferField^ ReqTransfer);

         /**
          * 交易所状态查询
          * @param pQryExchangeStatusData:交易所状态查询请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryExchangeStatus(CLRDFITCQryExchangeStatusField^ QryExchangeStatusData);

         /**
          * 行情查询请求
          * @param pQryDepthMarketData:行情查询请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryDepthMarketData(CLRDFITCQryDepthMarketDataField^ QryDepthMarketData);

         /**
          * 汇率查询请求
          * @param pQryExchangeRate:汇率查询请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryExchangeRate(CLRDFITCQryExchangeRateField^ QryExchangeRate);

         /**
          * 行情触发请求
          * @param pPricesTriggerData:行情触发请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqPricesTrigger(CLRDFITCPricesTriggerField^ PricesTriggerData);

         /**
          * 条件单查询请求
          * @param pQryEXOrderData:条件单查询请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
         int ReqQryExtOrder(CLRDFITCQryExtOrderField^ QryEXOrderData);

         /**
          * 条件单撤单请求
          * @param pCancelEXOrderData:条件单撤单请求结构地址。
          * @return 0 - 请求发送成功 -1 - 请求发送失败  -其它 -检测异常。
          */
		 int ReqCancelExtOrder(CLRDFITCCancelExtOrderField^ CancelEXOrderData);
	public:
		DFITCXSPEEDAPI::DFITCTraderApi *m_pNativeApi;
	};

}
