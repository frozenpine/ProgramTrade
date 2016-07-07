using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CLRXspeedApi;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace ProgramTradeApi
{
    internal sealed class XTradeSpi : CLRDFITCTraderSpi
    {
        protected override void OnFrontConnected()
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.TdFrontConnected) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.TdFrontConnected])
            {
                TypedRspEventArgs<object, object> evt = new TypedRspEventArgs<object, object> { RequestID = -1, ErrorID = 0, Message = "交易前置连接成功", Data = null, Error = null, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.TdFrontConnected].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnFrontDisconnected(int nReason)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspArbitrageInstrument(CLRDFITCAbiInstrumentRtnField AbiInstrumentData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspBillConfirm(CLRDFITCBillConfirmRspField BillConfirm, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspCancelAllOrder(CLRDFITCCancelAllOrderRspField RspCancelAllOrderData, CLRDFITCErrorRtnField ErrorInfo)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.CancelAll) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.CancelAll])
            {
                TypedRspEventArgs<CLRDFITCCancelAllOrderRspField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCCancelAllOrderRspField, CLRDFITCErrorRtnField> { RequestID = RspCancelAllOrderData.lRequestID, ErrorID = ErrorInfo.nErrorID, Message = ErrorInfo.errorMsg, Data = RspCancelAllOrderData, Error = ErrorInfo, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.CancelAll].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspCancelOrder(CLRDFITCOrderRspDataRtnField RspOrderCancel, CLRDFITCErrorRtnField ErrorInfo)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.CancelOrder) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.CancelOrder])
            {
                TypedRspEventArgs<CLRDFITCOrderRspDataRtnField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCOrderRspDataRtnField, CLRDFITCErrorRtnField> { RequestID = RspOrderCancel.lRequestID, ErrorID = ErrorInfo.nErrorID, Message = ErrorInfo.errorMsg, Data = RspOrderCancel, Error = ErrorInfo, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.CancelOrder].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspConfirmProductInfo(CLRDFITCProductRtnField RspProductData)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspCustomerCapital(CLRDFITCCapitalInfoRtnField CapitalInfo, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspEquityComputMode(CLRDFITCEquityComputModeRtnField EquityComputMode)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspExtCancelOrder(CLRDFITCExtOrderRspDataField OrderCancelRsp, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspExtInsertOrder(CLRDFITCExtOrderRspDataField OrderRsp, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspForQuote(CLRDFITCForQuoteRspField RspForQuoteData, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspFromBankToFutureByFuture(CLRDFITCTransferRspField RspTransfer, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspFromFutureToBankByFuture(CLRDFITCTransferRspField RspTransfer, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspInsertOrder(CLRDFITCOrderRspDataRtnField RspOrder, CLRDFITCErrorRtnField ErrorInfo)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.OrderInsert) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.OrderInsert])
            {
                TypedRspEventArgs<CLRDFITCOrderRspDataRtnField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCOrderRspDataRtnField, CLRDFITCErrorRtnField> { RequestID = RspOrder.lRequestID, ErrorID = ErrorInfo.nErrorID, Message = ErrorInfo.errorMsg, Data = RspOrder, Error = ErrorInfo, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.OrderInsert].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspQryBill(CLRDFITCQryBillRtnField QryBill, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryDepthMarketData(CLRDFITCDepthMarketDataField DepthMarketData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryExchangeInstrument(CLRDFITCExchangeInstrumentRtnField InstrumentData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.QryExchangInstruments) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.QryExchangInstruments])
            {
                TypedRspEventArgs<CLRDFITCExchangeInstrumentRtnField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCExchangeInstrumentRtnField, CLRDFITCErrorRtnField> { RequestID = InstrumentData.lRequestID, ErrorID = ErrorInfo.nErrorID, Message = ErrorInfo.errorMsg, Data = InstrumentData, Error = ErrorInfo, IsLast = bIsLast };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.QryExchangInstruments].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspQryExchangeRate(CLRDFITCExchangeRateField ExchangeRate, CLRDFITCErrorRtnField RspInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryExchangeStatus(CLRDFITCExchangeStatusRspField RspExchangeStatusData)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryForQuote(CLRDFITCQryForQuoteRtnField QryForQuoteData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryMatchInfo(CLRDFITCMatchedRtnField MatchData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryOrderInfo(CLRDFITCOrderCommRtnField OrderData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.QryOrders) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.QryOrders])
            {
                TypedRspEventArgs<CLRDFITCOrderCommRtnField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCOrderCommRtnField, CLRDFITCErrorRtnField> { RequestID = OrderData.lRequestID, ErrorID = ErrorInfo.nErrorID, Message = ErrorInfo.errorMsg, Data = OrderData, Error = ErrorInfo, IsLast = bIsLast };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.QryOrders].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspQryPosition(CLRDFITCPositionInfoRtnField PositionInfo, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.QryPosition) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.QryPosition])
            {
                TypedRspEventArgs<CLRDFITCPositionInfoRtnField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCPositionInfoRtnField, CLRDFITCErrorRtnField> { RequestID = PositionInfo.lRequestID, ErrorID = ErrorInfo.nErrorID, Message = ErrorInfo.errorMsg, Data = PositionInfo, Error = ErrorInfo, IsLast = bIsLast };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.QryPosition].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspQryPositionDetail(CLRDFITCPositionDetailRtnField PositionDetail, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryPricesTrigger(CLRDFITCQryPricesTriggerField QryPricesTriggerRspData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryQuoteNotice(CLRDFITCQryQuoteNoticeRtnField QryQuoteNoticeData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryQuoteOrderInfo(CLRDFITCQuoteOrderRtnField QuoteOrderData, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQrySpecifyInstrument(CLRDFITCInstrumentRtnField Instrument, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryTradeCode(CLRDFITCQryTradeCodeRtnField TradeCode, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryTransferBank(CLRDFITCTransferBankRspField TransferBank, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQryTransferSerial(CLRDFITCTransferSerialRspField TransferSerial, CLRDFITCErrorRtnField ErrorInfo, bool bIsLast)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQuoteCancel(CLRDFITCQuoteRspField RspQuoteCancel, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspQuoteInsert(CLRDFITCQuoteRspField RspQuote, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspResetPassword(CLRDFITCResetPwdRspField ResetPassword, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspTradingDay(CLRDFITCTradingDayRtnField TradingDayRtnData)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspUserLogin(CLRDFITCUserLoginInfoRtnField RspUserLogin, CLRDFITCErrorRtnField ErrorInfo)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.UserLogin) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.UserLogin])
            {
                TypedRspEventArgs<CLRDFITCUserLoginInfoRtnField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCUserLoginInfoRtnField, CLRDFITCErrorRtnField> { RequestID = RspUserLogin.lRequestID, ErrorID = ErrorInfo.nErrorID, Message = ErrorInfo.errorMsg, Data = RspUserLogin, Error = ErrorInfo, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.UserLogin].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspUserLogout(CLRDFITCUserLogoutInfoRtnField RspUserLogout, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnCancelOrder(CLRDFITCOrderCanceledRtnField RtnCancelOrderData)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.CancelOrder) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.CancelOrder])
            {
                TypedRspEventArgs<CLRDFITCOrderCanceledRtnField, object> evt = new TypedRspEventArgs<CLRDFITCOrderCanceledRtnField, object> { RequestID = -1, ErrorID = 0, Message = RtnCancelOrderData.statusMsg, Data = RtnCancelOrderData, Error = null, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.CancelOrder].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRtnErrorMsg(CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnExchangeStatus(CLRDFITCExchangeStatusRtnField RtnExchangeStatusData)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnForQuote(CLRDFITCForQuoteRtnField RtnForQuote)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnForQuoteRsp(CLRDFITCQuoteSubscribeRtnField ForQuoteRspData)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnFromBankToFutureByFuture(CLRDFITCTransferRtnField RtnTransfer, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnFromFutureToBankByFuture(CLRDFITCTransferRtnField RtnTransfer, CLRDFITCErrorRtnField ErrorInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnMatchedInfo(CLRDFITCMatchRtnField RtnMatchData)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.OrderDeal) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.OrderDeal])
            {
                TypedRspEventArgs<CLRDFITCMatchRtnField, object> evt = new TypedRspEventArgs<CLRDFITCMatchRtnField, object> { RequestID = -1, ErrorID = 0, Message = RtnMatchData.matchedTime, Data = RtnMatchData, Error = null, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.OrderDeal].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRtnOrder(CLRDFITCOrderRtnField RtnOrderData)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.OrderReturn) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.OrderReturn])
            {
                TypedRspEventArgs<CLRDFITCOrderRtnField, object> evt = new TypedRspEventArgs<CLRDFITCOrderRtnField, object> { RequestID = -1, ErrorID = 0, Message = RtnOrderData.statusMsg, Data = RtnOrderData, Error = null, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.OrderReturn].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRtnPricesTrigger(CLRDFITCPricesTriggerRtnField OrderRtn)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnQuoteCancel(CLRDFITCQuoteCanceledRtnField RtnQuoteCanceled)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnQuoteInsert(CLRDFITCQuoteRtnField RtnQuote)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnQuoteMatchedInfo(CLRDFITCQuoteMatchRtnField RtnQuoteMatched)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnRepealFromFutureToBankByBank(CLRDFITCRepealRtnField RspRepeal)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnTradingNotice(CLRDFITCTradingNoticeInfoField TradingNoticeInfo)
        {
            throw new NotImplementedException();
        }
    }
}
