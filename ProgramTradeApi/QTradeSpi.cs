using CLRQdpApi;
using System;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;

namespace ProgramTradeApi
{
    /// <summary>
    /// QDP交易请求回调API C#封装
    /// </summary>
    internal sealed class QTradeSpi : CLRCQdpFtdcTraderSpi
    {
        /// <summary>
        /// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
        /// </summary>
        protected override void OnFrontConnected()
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread Called By TradeSpi->OnFrontConnected", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.FrontConnected) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontConnected])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontConnected].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { Error = 0, Message = "交易前置连接成功！" }, null, null);
                });
            }*/
        }

        /// <summary>
        /// 心跳超时警告
        /// 当长时间未收到报文时，该方法被调用。
        /// </summary>
        /// <param name="nTimeLapse">距上次收到心跳的超时时间</param>
        protected override void OnHeartBeatWarning(int nTimeLapse)
        {
#if DEBUG
            Debug.WriteLine("心跳超时" + nTimeLapse + "秒！");
#endif
            /*if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.HeartBeatWarning) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.HeartBeatWarning])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.HeartBeatWarning].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { Error = (int)CLRQDP_FTFAIL_REASON.RCV_HTB_TMOUT, Message = "心跳超时" + nTimeLapse + "秒！" }, null, null);
                });
            }*/
        }

        /// <summary>
        /// 当客户端与交易后台通信连接断开时，该方法被调用
        /// 当发生这个情况后，API会自动重新连接，客户端可不做处理。
        /// </summary>
		/// <param name="nReason">错误原因</param>
        /// 0x1001 网络读失败
		/// 0x1002 网络写失败
		/// 0x2001 接收心跳超时
		/// 0x2002 发送心跳失败
		/// 0x2003 收到错误报文
        protected override void OnFrontDisconnected(int nReason)
        {
#if DEBUG
            Debug.WriteLine("连接断开原因：" + Enum.GetName(typeof(CLRQDP_FTFAIL_REASON), (CLRQDP_FTFAIL_REASON)nReason));
#endif
            /*if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.FrontDisconnected) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontDisconnected])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.FrontDisconnected].GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { Error = nReason, Message = "连接断开原因：" + Enum.GetName(typeof(CLRQDP_FTFAIL_REASON), (CLRQDP_FTFAIL_REASON)nReason) }, null, null);
                });
            }*/
        }

        /// <summary>
        /// 用户登录应答
        /// </summary>
        /// <param name="RspUserLogin">已登录用户信息</param>
        /// <param name="RspInfo">登录应答信息</param>
        /// <param name="nRequestID">应答对应的请求ID</param>
        /// <param name="bIsLast">是否为最后一个应答报文</param>
        protected override void OnRspUserLogin(CLRCQdpFtdcRspUserLoginField RspUserLogin, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread Called By TradeSpi->OnRspUserLogin", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspUserLoginHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspUserLoginHandler.GetInvocationList(), handler =>
                    {
                        (handler as EventHandler<RspUserLoginEventArgs>).BeginInvoke(this, new RspUserLoginEventArgs { RspUserLoin = RspUserLogin, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }

        /*/// <summary>
        /// 报文回调开始通知
        /// 当API收到一个报文后，首先调用本方法，然后是各数据域的回调，最后是报文回调结束通知。
        /// </summary>
		/// <param name="nTopicID">主题代码（如私有流、公共流、行情流等）</param>
		/// <param name="nSequenceNo">报文序号</param>
		protected override void OnPackageStart(int nTopicID, int nSequenceNo)
        {
            ;
        }*/

        /*/// <summary>
        /// 报文回调结束通知
        /// 当API收到一个报文后，首先调用报文回调开始通知，然后是各数据域的回调，最后调用本方法。
        /// </summary>
		/// <param name="nTopicID">主题代码（如私有流、公共流、行情流等）</param>
		/// <param name="nSequenceNo">报文序号</param>
		protected override void OnPackageEnd(int nTopicID, int nSequenceNo)
        {
            ;
        }*/

        /// <summary>
        /// 错误应答
        /// </summary>
        /// <param name="RspInfo">错误应答信息</param>
        /// <param name="nRequestID">应答对应的请求ID</param>
        /// <param name="bIsLast">是否为最后一个应答报文</param>
		protected override void OnRspError(CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread Called By TradeSpi->OnRspError", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (ProgramTradeEvents.RspEventHandler.ContainsKey(RspSpiModules.RspError) && null != ProgramTradeEvents.RspEventHandler[RspSpiModules.RspError])
            {
                Parallel.ForEach(ProgramTradeEvents.RspEventHandler[RspSpiModules.RspError].GetInvocationList(), handler =>
                 {
                     (handler as EventHandler<RspEventArgs>).BeginInvoke(this, new RspEventArgs { Error = RspInfo.ErrorID, Message = RspInfo.ErrorMsg, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                 });
            }*/
        }

        /// <summary>
        /// 用户退出应答
        /// </summary>
        /// <param name="RspUserLogout">登出用户信息</param>
        /// <param name="RspInfo">登出应答信息</param>
        /// <param name="nRequestID">应答对应的请求号</param>
        /// <param name="bIsLast">是否最后一个应答报文</param>
		protected override void OnRspUserLogout(CLRCQdpFtdcRspUserLogoutField RspUserLogout, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRspUserLogout called", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspUserLogoutHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspUserLogoutHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspUserLogoutEventArgs>).BeginInvoke(this, new RspUserLogoutEventArgs { RspUserLogout = RspUserLogout, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }

        /// <summary>
        /// 用户密码修改应答
        /// </summary>
        /// <param name="UserPasswordUpdate">修改密码用户信息</param>
        /// <param name="RspInfo">修改应答信息</param>
        /// <param name="nRequestID">应答对应的请求ID</param>
        /// <param name="bIsLast">是否最后一个应答报文</param>
		protected override void OnRspUserPasswordUpdate(CLRCQdpFtdcUserPasswordUpdateField UserPasswordUpdate, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRspUserPasswordUpdate", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspUserPasswordUpdateHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspUserPasswordUpdateHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspUserPasswordUpdateEventArgs>).BeginInvoke(this, new RspUserPasswordUpdateEventArgs { UserPasswordUpdate = UserPasswordUpdate, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }

        /// <summary>
        /// 报单录入应答
        /// </summary>
        /// <param name="InputOrder">录入报单信息</param>
        /// <param name="RspInfo">录入应答信息</param>
        /// <param name="nRequestID">应答对应的请求ID</param>
        /// <param name="bIsLast">是否最后一个应答报文</param>
		protected override void OnRspOrderInsert(CLRCQdpFtdcInputOrderField InputOrder, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRspOrderInsert", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspOrderInsertHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspOrderInsertHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspOrderInsertEventArgs>).BeginInvoke(this, new RspOrderInsertEventArgs { InputOrder = InputOrder, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }

        ///报单操作应答
		protected override void OnRspOrderAction(CLRCQdpFtdcOrderActionField OrderAction, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnErrRtnOrderInsert", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if(null!=ProgramTradeEvents.RspOrderActionHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspOrderActionHandler.GetInvocationList(), handler =>
                 {
                     (handler as EventHandler<RspOrderActionEventArgs>).BeginInvoke(this, new RspOrderActionEventArgs
                     {
                         OrderAction = OrderAction,
                         RspInfo = RspInfo,
                         RequestID = nRequestID,
                         IsLast = bIsLast
                     }, null, null);
                 });
            }*/
        }

        ///数据流回退通知
		protected override void OnRtnFlowMessageCancel(CLRCQdpFtdcFlowMessageCancelField FlowMessageCancel)
        {
            ;
        }

        ///成交回报
		protected override void OnRtnTrade(CLRCQdpFtdcTradeField Trade)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRtnTrade", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RtnTradeHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RtnTradeHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RtnTradeEventArgs>).BeginInvoke(this, new RtnTradeEventArgs { Trade = Trade }, null, null);
                });
            }*/
        }

        ///报单回报
		protected override void OnRtnOrder(CLRCQdpFtdcOrderField Order)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRtnOrder", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RtnOrderHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RtnOrderHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RtnOrderEventArgs>).BeginInvoke(this, new RtnOrderEventArgs { Order = Order }, null, null);
                });
            }*/
        }

        ///报单录入错误回报
		protected override void OnErrRtnOrderInsert(CLRCQdpFtdcInputOrderField InputOrder, CLRCQdpFtdcRspInfoField RspInfo)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnErrRtnOrderInsert", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.ErrRtnOrderInsertHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.ErrRtnOrderInsertHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<ErrRtnOrderInsertEventArgs>).BeginInvoke(this, new ErrRtnOrderInsertEventArgs { InputOrder = InputOrder, RspInfo = RspInfo }, null, null);
                });
            }*/
        }

        ///报单操作错误回报
		protected override void OnErrRtnOrderAction(CLRCQdpFtdcOrderActionField OrderAction, CLRCQdpFtdcRspInfoField RspInfo)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnErrRtnOrderAction", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.ErrRtnOrderActionHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.ErrRtnOrderActionHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<ErrRtnOrderActionEventArgs>).BeginInvoke(this, new ErrRtnOrderActionEventArgs { OrderAction = OrderAction, RspInfo = RspInfo }, null, null);
                });
            }*/
        }

        ///合约交易状态通知
		protected override void OnRtnInstrumentStatus(CLRCQdpFtdcInstrumentStatusField InstrumentStatus)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRtnInstrumentStatus", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RtnInstrumentStatusHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RtnInstrumentStatusHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RtnInstrumentStatusEventArgs>).BeginInvoke(this, new RtnInstrumentStatusEventArgs { InstrumentStatus = InstrumentStatus }, null, null);
                });
            }*/
        }

        ///账户出入金回报
		protected override void OnRtnInvestorAccountDeposit(CLRCQdpFtdcInvestorAccountDepositResField InvestorAccountDepositRes)
        {
            ;
        }

        ///QDP警告消息通知
		protected override void OnRtnMessageNotify(CLRCQdpFtdcMessageNotifyInfoField MessageNotifyInfo)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRtnMessageNotify", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RtnMessageNotifyHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RtnMessageNotifyHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RtnMessageNotifyEventArgs>).BeginInvoke(this, new RtnMessageNotifyEventArgs { MessageNotifyInfo = MessageNotifyInfo }, null, null);
                });
            }*/
        }

        ///报单查询应答
		protected override void OnRspQryOrder(CLRCQdpFtdcOrderField Order, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRspQryOrder", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspQryOrderHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspQryOrderHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspQryOrderEventArgs>).BeginInvoke(this, new RspQryOrderEventArgs { Order = Order, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }

        ///成交单查询应答
		protected override void OnRspQryTrade(CLRCQdpFtdcTradeField Trade, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRspQryTrade", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspQryTradeHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspQryTradeHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspQryTradeEventArgs>).BeginInvoke(this, new RspQryTradeEventArgs { Trade = Trade, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }

        ///可用投资者账户查询应答
		protected override void OnRspQryUserInvestor(CLRCQdpFtdcRspUserInvestorField RspUserInvestor, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRspQryUserInvestor", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspQryUserInvestorHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspQryUserInvestorHandler.GetInvocationList(), handler =>
                 {
                     (handler as EventHandler<RspQryUserInvestorEventArgs>).BeginInvoke(this, new RspQryUserInvestorEventArgs { RspUserInvestor = RspUserInvestor, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                 });
            }*/
        }

        ///投资者资金账户查询应答
		protected override void OnRspQryInvestorAccount(CLRCQdpFtdcRspInvestorAccountField RspInvestorAccount, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread called by TradeSpi->OnRspQryInvestorAccount", Thread.CurrentThread.ManagedThreadId);
#endif
            /*if (null != ProgramTradeEvents.RspQryInvestorAccountHandler)
            {
                Parallel.ForEach(ProgramTradeEvents.RspQryInvestorAccountHandler.GetInvocationList(), handler =>
                {
                    (handler as EventHandler<RspQryInvestorAccountEventArgs>).BeginInvoke(this, new RspQryInvestorAccountEventArgs { RspInvestorAccount = RspInvestorAccount, RspInfo = RspInfo, RequestID = nRequestID, IsLast = bIsLast }, null, null);
                });
            }*/
        }

        ///合约查询应答
		protected override void OnRspQryInstrument(CLRCQdpFtdcRspInstrumentField RspInstrument, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///交易所查询应答
		protected override void OnRspQryExchange(CLRCQdpFtdcRspExchangeField RspExchange, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///投资者持仓查询应答
		protected override void OnRspQryInvestorPosition(CLRCQdpFtdcRspInvestorPositionField RspInvestorPosition, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///订阅主题应答
		protected override void OnRspSubscribeTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///主题查询应答
		protected override void OnRspQryTopic(CLRCQdpFtdcDisseminationField Dissemination, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///投资者手续费率查询应答
		protected override void OnRspQryInvestorFee(CLRCQdpFtdcInvestorFeeField InvestorFee, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///投资者保证金率查询应答
		protected override void OnRspQryInvestorMargin(CLRCQdpFtdcInvestorMarginField InvestorMargin, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///交易所时间偏差查询应答
		protected override void OnRspQryExchangeDiffTime(CLRCQdpFtdcRspExchangeDiffTimeField RspExchangeDiffTime, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }

        ///实时行情查询应答
		protected override void OnRspQryMarketData(CLRCQdpFtdcMarketDataField MarketData, CLRCQdpFtdcRspInfoField RspInfo, int nRequestID, bool bIsLast)
        {
            ;
        }
    }
}
