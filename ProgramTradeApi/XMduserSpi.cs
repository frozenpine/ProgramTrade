using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CLRXspeedApi;
using System.Threading.Tasks;

namespace ProgramTradeApi
{
    internal sealed class XMduserSpi : CLRDFITCMduserSpi
    {
        protected override void OnCustomMarketData(CLRDFITCCustomMarketDataField MarketDataField)
        {
            throw new NotImplementedException();
        }

        protected override void OnFrontConnected()
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.FrontConnected) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontConnected])
            {
                TypedRspEventArgs<object, object> evt = new TypedRspEventArgs<object, object> { RequestID = -1, ErrorID = 0, Message = "行情前置连接成功", Data = null, Error = null, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontConnected].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnFrontDisconnected(int nReason)
        {
            throw new NotImplementedException();
        }

        protected override void OnMarketData(CLRDFITCDepthMarketDataField MarketDataField)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.RtnMarket) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.RtnMarket])
            {
                TypedRspEventArgs<CLRDFITCDepthMarketDataField, object> evt = new TypedRspEventArgs<CLRDFITCDepthMarketDataField, object> { RequestID = 0, ErrorID = 0, Message = MarketDataField.instrumentID, Data = MarketDataField, Error = null, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.RtnMarket].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspError(CLRDFITCErrorRtnField RspInfo)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.RspError) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.RspError])
            {
                TypedRspEventArgs<CLRDFITCErrorRtnField, object> evt = new TypedRspEventArgs<CLRDFITCErrorRtnField, object> { RequestID = RspInfo.requestID, ErrorID = RspInfo.nErrorID, Message = RspInfo.errorMsg, Data = RspInfo, Error = null, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.RspError].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspSubForQuoteRsp(CLRDFITCSpecificInstrumentField SpecificInstrument, CLRDFITCErrorRtnField RspInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspSubMarketData(CLRDFITCSpecificInstrumentField SpecificInstrument, CLRDFITCErrorRtnField RspInfo)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.SubMarket) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.SubMarket])
            {
                TypedRspEventArgs<CLRDFITCSpecificInstrumentField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCSpecificInstrumentField, CLRDFITCErrorRtnField> { RequestID = SpecificInstrument.lRequestID, ErrorID = RspInfo.nErrorID, Message = RspInfo.errorMsg, Data = SpecificInstrument, Error = RspInfo, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.SubMarket].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspTradingDay(CLRDFITCTradingDayRtnField TradingDayRtnData)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspUnSubForQuoteRsp(CLRDFITCSpecificInstrumentField SpecificInstrument, CLRDFITCErrorRtnField RspInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspUnSubMarketData(CLRDFITCSpecificInstrumentField SpecificInstrument, CLRDFITCErrorRtnField RspInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRspUserLogin(CLRDFITCUserLoginInfoRtnField RspUserLogin, CLRDFITCErrorRtnField RspInfo)
        {
            if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.UserLogin) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.UserLogin])
            {
                TypedRspEventArgs<CLRDFITCUserLoginInfoRtnField, CLRDFITCErrorRtnField> evt = new TypedRspEventArgs<CLRDFITCUserLoginInfoRtnField, CLRDFITCErrorRtnField> { RequestID = RspUserLogin.lRequestID, ErrorID = RspInfo.nErrorID, Message = RspInfo.errorMsg, Data = RspUserLogin, Error = RspInfo, IsLast = true };
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.UserLogin].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, evt, null, null);
                });
            }
        }

        protected override void OnRspUserLogout(CLRDFITCUserLogoutInfoRtnField RspUsrLogout, CLRDFITCErrorRtnField RspInfo)
        {
            throw new NotImplementedException();
        }

        protected override void OnRtnForQuoteRsp(CLRDFITCQuoteSubscribeRtnField ForQuoteField)
        {
            throw new NotImplementedException();
        }
    }
}
