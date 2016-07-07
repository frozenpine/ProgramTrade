using CLRQdpApi;
using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace ProgramTradeApi
{
    internal sealed class QMarketSpi : CLRCQdpFtdcMduserSpi
    {
        protected override void OnFrontConnected()
        {
            /*if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.TdFrontConnected) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.TdFrontConnected])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.TdFrontConnected].GetInvocationList(), handler =>
                 {
                     (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { ErrorID = 0, Message = "行情前置连接成功！" }, null, null);
                 });
            }*/
        }
        protected override void OnFrontDisconnected(int nReason)
        {
            /*if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.FrontDisconnected) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontDisconnected])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontDisconnected].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { ErrorID = nReason, Message = "连接断开原因：" + Enum.GetName(typeof(CLRQDP_FTFAIL_REASON), (CLRQDP_FTFAIL_REASON)nReason) }, null, null);
                });
            }*/
        }
        protected override void OnHeartBeatWarning(int nTimeLapse)
        {
            /*if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.HeartBeatWarning) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.HeartBeatWarning])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.HeartBeatWarning].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { ErrorID = (int)CLRQDP_FTFAIL_REASON.RCV_HTB_TMOUT, Message = "心跳超时" + nTimeLapse + "秒！" }, null, null);
                });
            }*/
        }
        protected override void OnPackageStart(int nTopicID, int nSequenceNo)
        { }
        protected override void OnPackageEnd(int nTopicID, int nSequenceNo)
        { }
        protected override void OnMultiHeartbeat(string CurrTime, string MultiCastIP)
        { }
        protected override void UdpMarketData(CLRCQdpFtdcDepthMarketDataField qmdata)
        { }
        protected override void OnRspError(CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            /*if(ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.RspError) && null!=ProgramTradeEvents.RspEventHandler[RspSpiModules.RspError])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.RspError].GetInvocationList(), handler =>
                 {
                     (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { ErrorID = RspInfo.ErrorID, Message = RspInfo.ErrorMsg, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                 });
            }*/
        }
        protected override void OnRspUserLogin(CLRCQdpFtdcRspUserLoginField RspUserLogin, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            /*if(null!=ProgramTradeEvents.RspUserLoginHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspUserLoginHandler.GetInvocationList(), handler=>
                {
                    (handler as EventHandler<RspUserLoginEventArgs>).BeginInvoke(this, new RspUserLoginEventArgs { RspUserLoin = RspUserLogin, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }
        protected override void OnRspUserLogout(CLRCQdpFtdcRspUserLogoutField RspUserLogout, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            /*if(null!=ProgramTradeEvents.RspUserLogoutHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspUserLogoutHandler.GetInvocationList(), handler=>
                {
                    (handler as EventHandler<RspUserLogoutEventArgs>).BeginInvoke(this, new RspUserLogoutEventArgs { RspUserLogout = RspUserLogout, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }
        protected override void OnRspSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            /*if (null != ProgramTradeEvents.RspSubscribeTopicHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspSubscribeTopicHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspSubscribeTopicEventArgs>).BeginInvoke(this, new RspSubscribeTopicEventArgs { Dissemination = Dissemination, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }
        protected override void OnRspQryTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            /*if (null != ProgramTradeEvents.RspQryTopicHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspQryTopicHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspQryTopicEventArgs>).BeginInvoke(this, new RspQryTopicEventArgs { Dissemination = Dissemination, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }
        protected override void OnRtnDepthMarketData(CLRCQdpFtdcDepthMarketDataField DepthMarketData)
        {
            /*if (null != ProgramTradeEvents.RtnDepthMarketDataHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RtnDepthMarketDataHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RtnDepthMarketDataEventArgs>).BeginInvoke(this, new RtnDepthMarketDataEventArgs { DepthMarketData = DepthMarketData }, null, null);
                });
            }*/
        }
        protected override void OnRspSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, /*CLRCQdpFtdcRspInfoField RspInfo,*/ int nRequestID, bool bIsLast)
        {
            /*if(null!=ProgramTradeEvents.RspSubMarketDataHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspSubMarketDataHandler.GetInvocationList(), handler =>
                 {
                     (handler as EventHandler<RspSubMarketDataEventArgs>).BeginInvoke(this, new RspSubMarketDataEventArgs { SpecificInstrument = SpecificInstrument, /*RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                 });
            }*/
        }
        protected override void OnRspUnSubMarketData(CLRCQdpFtdcSpecificInstrumentField SpecificInstrument, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        { }
    }
}
