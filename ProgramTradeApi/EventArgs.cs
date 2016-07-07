using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CLRQdpApi;
using System.Collections.Concurrent;

namespace ProgramTradeApi
{
    /// <summary>
    /// 返回应答模组
    /// </summary>
    internal enum RspSpiModules
    {
        /// <summary>
        /// 交易前置连接应答
        /// </summary>
        TdFrontConnected,

        /// <summary>
        /// 心跳超时应答
        /// </summary>
        HeartBeatWarning,

        /// <summary>
        /// 前置断开应答
        /// </summary>
        FrontDisconnected,

        /// <summary>
        /// 应答错误
        /// </summary>
        RspError,

        /// <summary>
        /// 用户登录应答
        /// </summary>
        UserLogin,

        /// <summary>
        /// 持仓查询应答
        /// </summary>
        QryPosition,

        /// <summary>
        /// 委托查询应答
        /// </summary>
        QryOrders,

        /// <summary>
        /// 撤单应答
        /// </summary>
        CancelOrder,

        /// <summary>
        /// 全部撤单应答
        /// </summary>
        CancelAll,

        /// <summary>
        /// 交易所合约查询应答
        /// </summary>
        QryExchangInstruments,

        /// <summary>
        /// 委托录入应答
        /// </summary>
        OrderInsert,

        /// <summary>
        /// 委托回报应答
        /// </summary>
        OrderReturn,

        /// <summary>
        /// 成交回报
        /// </summary>
        OrderDeal
    }

    #region EventArgs
    public class RspEventArgs : EventArgs
    {
        /// <summary>
        /// 回报对应的请求报文号
        /// </summary>
        public int RequestID { get; set; }
        /// <summary>
        /// 回报错误代码
        /// </summary>
        public int ErrorID { get; set; }
        /// <summary>
        /// 回报消息
        /// </summary>
        public string Message { get; set; }
        /// <summary>
        /// 是否为最后一个同类型回报
        /// </summary>
        public bool IsLast { get; set; }
    }
    public sealed class TypedRspEventArgs<T1,T2> : RspEventArgs
    {
        /// <summary>
        /// 回报报文数据
        /// </summary>
        public T1 Data { get; set; }
        /// <summary>
        /// 回报错误数据
        /// </summary>
        public T2 Error { get; set; }
        
    }
    #endregion

    internal static class ProgramTradeEvents
    {
        #region RspInfoHandler
        internal static Dictionary<RspSpiModules, EventHandler<RspEventArgs>> RspEventHandler = new Dictionary<RspSpiModules, EventHandler<RspEventArgs>>(Enum.GetNames(typeof(RspSpiModules)).Length);
        internal static void AddRspHandler(RspSpiModules system, EventHandler<RspEventArgs> evt)
        {
            if (RspEventHandler.ContainsKey(system))
            {
                RspEventHandler[system] += evt;
            }
            else
            {
                RspEventHandler.Add(system, evt);
            }
        }
        internal static void RemoveRspHandler(RspSpiModules system, EventHandler<RspEventArgs> evt)
        {
            if (RspEventHandler.ContainsKey(system))
            {
                RspEventHandler[system] -= evt;
            }
        }
        #endregion

        /*#region RspUserLoginHandler
        public static EventHandler<RspUserLoginEventArgs> RspUserLoginHandler;
        public static void AddRspUserLoginHandler(EventHandler<RspUserLoginEventArgs> evt)
        {
            RspUserLoginHandler += evt;
        }
        public static void RemoveRspUserLoginHander(EventHandler<RspUserLoginEventArgs> evt)
        {
            RspUserLoginHandler -= evt;
        }
        #endregion

        #region RspUserLogoutHandler
        public static EventHandler<RspUserLogoutEventArgs> RspUserLogoutHandler;
        public static void AddRspUserLogoutHandler(EventHandler<RspUserLogoutEventArgs> evt)
        {
            RspUserLogoutHandler += evt;
        }
        public static void RemoveRspUserLogoutHandler(EventHandler<RspUserLogoutEventArgs> evt)
        {
            RspUserLogoutHandler -= evt;
        }
        #endregion

        #region RspOrderInsertHandler
        public static EventHandler<RspOrderInsertEventArgs> RspOrderInsertHandler;
        public static void AddRspOrderInsertHandler(EventHandler<RspOrderInsertEventArgs> evt)
        {
            RspOrderInsertHandler += evt;
        }
        public static void RemoveRspOrderInsertHandler(EventHandler<RspOrderInsertEventArgs> evt)
        {
            RspOrderInsertHandler -= evt;
        }
        #endregion

        #region RspUserPasswordUpdateHandler
        public static EventHandler<RspUserPasswordUpdateEventArgs> RspUserPasswordUpdateHandler;
        public static void AddRspUserPasswordUpdateHandler(EventHandler<RspUserPasswordUpdateEventArgs> evt)
        {
            RspUserPasswordUpdateHandler += evt;
        }
        public static void RemoveRspUserPasswordUpdateHandler(EventHandler<RspUserPasswordUpdateEventArgs> evt)
        {
            RspUserPasswordUpdateHandler -= evt;
        }
        #endregion

        #region RspOrderActionHandler
        public static EventHandler<RspOrderActionEventArgs> RspOrderActionHandler;
        public static void AddRspOrderActionHandler(EventHandler<RspOrderActionEventArgs> evt)
        {
            RspOrderActionHandler += evt;
        }
        public static void RemoveRspOrderActionHandler(EventHandler<RspOrderActionEventArgs> evt)
        {
            RspOrderActionHandler -= evt;
        }
        #endregion

        #region RspQryUserInvestorHandler
        public static EventHandler<RspQryUserInvestorEventArgs> RspQryUserInvestorHandler;
        public static void AddRspQryUserInvestorHandler(EventHandler<RspQryUserInvestorEventArgs> evt)
        {
            RspQryUserInvestorHandler += evt;
        }
        public static void RemoveRspQryUserInvestorHandler(EventHandler<RspQryUserInvestorEventArgs> evt)
        {
            RspQryUserInvestorHandler -= evt;
        }
        #endregion

        #region ErrRtnOrderInsertHandler
        public static EventHandler<ErrRtnOrderInsertEventArgs> ErrRtnOrderInsertHandler;
        public static void AddErrRtnOrderInsertHandler(EventHandler<ErrRtnOrderInsertEventArgs> evt)
        {
            ErrRtnOrderInsertHandler += evt;
        }
        public static void RemoveErrRtnOrderInsertHandler(EventHandler<ErrRtnOrderInsertEventArgs> evt)
        {
            ErrRtnOrderInsertHandler -= evt;
        }
        #endregion

        #region RtnInstrumentStatusHandler
        public static EventHandler<RtnInstrumentStatusEventArgs> RtnInstrumentStatusHandler;
        public static void AddRtnInstrumentStatusHandler(EventHandler<RtnInstrumentStatusEventArgs> evt)
        {
            RtnInstrumentStatusHandler += evt;
        }
        public static void RemoveRtnInstrumentStatusHandler(EventHandler<RtnInstrumentStatusEventArgs> evt)
        {
            RtnInstrumentStatusHandler -= evt;
        }
        #endregion

        #region RspQryInvestorAccountHandler
        public static EventHandler<RspQryInvestorAccountEventArgs> RspQryInvestorAccountHandler;
        public static void AddRspQryInvestorAccountHandler(EventHandler<RspQryInvestorAccountEventArgs> evt)
        {
            RspQryInvestorAccountHandler += evt;
        }
        public static void RemoveRspQryInvestorAccountHandler(EventHandler<RspQryInvestorAccountEventArgs> evt)
        {
            RspQryInvestorAccountHandler -= evt;
        }
        #endregion

        #region RtnTradeHandler
        public static EventHandler<RtnTradeEventArgs> RtnTradeHandler;
        public static void AddRtnTradeHandler(EventHandler<RtnTradeEventArgs> evt)
        {
            RtnTradeHandler += evt;
        }
        public static void RemoveRtnTradeHandler(EventHandler<RtnTradeEventArgs> evt)
        {
            RtnTradeHandler -= evt;
        }
        #endregion

        #region RtnOrderHandler
        public static EventHandler<RtnOrderEventArgs> RtnOrderHandler;
        public static void AddRtnOrderHandler(EventHandler<RtnOrderEventArgs> evt)
        {
            RtnOrderHandler += evt;
        }
        public static void RemoveOrderHandler(EventHandler<RtnOrderEventArgs> evt)
        {
            RtnOrderHandler -= evt;
        }
        #endregion

        #region ErrRtnOrderActionHandler
        public static EventHandler<ErrRtnOrderActionEventArgs> ErrRtnOrderActionHandler;
        public static void AddErrRtnOrderActionHandler(EventHandler<ErrRtnOrderActionEventArgs> evt)
        {
            ErrRtnOrderActionHandler += evt;
        }
        public static void RemoveErrRtnOrderActionHandler(EventHandler<ErrRtnOrderActionEventArgs> evt)
        {
            ErrRtnOrderActionHandler -= evt;
        }
        #endregion

        #region RtnMessageNotifyHandler
        public static EventHandler<RtnMessageNotifyEventArgs> RtnMessageNotifyHandler;
        public static void AddRtnMessageNotifyHandler(EventHandler<RtnMessageNotifyEventArgs> evt)
        {
            RtnMessageNotifyHandler += evt;
        }
        public static void RemoveRtnMessageNotifyHandler(EventHandler<RtnMessageNotifyEventArgs> evt)
        {
            RtnMessageNotifyHandler -= evt;
        }
        #endregion

        #region RspQryOrderHandler
        public static EventHandler<RspQryOrderEventArgs> RspQryOrderHandler;
        public static void AddRspQryOrderHandler(EventHandler<RspQryOrderEventArgs> evt)
        {
            RspQryOrderHandler += evt;
        }
        public static void RemoveRspQryOrderHandler(EventHandler<RspQryOrderEventArgs> evt)
        {
            RspQryOrderHandler -= evt;
        }
        #endregion

        #region RspQryTradeHandler
        public static EventHandler<RspQryTradeEventArgs> RspQryTradeHandler;
        public static void AddRspQryTradeHandler(EventHandler<RspQryTradeEventArgs> evt)
        {
            RspQryTradeHandler += evt;
        }
        public static void RemoveRspQryTradeHandler(EventHandler<RspQryTradeEventArgs> evt)
        {
            RspQryTradeHandler -= evt;
        }
        #endregion

        #region RspSubMarketDataHandler
        public static EventHandler<RspSubMarketDataEventArgs> RspSubMarketDataHandler;
        public static void AddRspSubMarketDataHandler(EventHandler<RspSubMarketDataEventArgs> evt)
        {
            RspSubMarketDataHandler += evt;
        }
        public static void RemoveRspSubMarketDataHandler(EventHandler<RspSubMarketDataEventArgs> evt)
        {
            RspSubMarketDataHandler -= evt;
        }
        #endregion

        #region RspSubscribeTopicHandler
        public static EventHandler<RspSubscribeTopicEventArgs> RspSubscribeTopicHandler;
        public static void AddRspSubscribeTopicHandler(EventHandler<RspSubscribeTopicEventArgs> evt)
        {
            RspSubscribeTopicHandler += evt;
        }
        public static void RemoveRspSubscribeTopicHandler(EventHandler<RspSubscribeTopicEventArgs> evt)
        {
            RspSubscribeTopicHandler -= evt;
        }
        #endregion

        #region RspQryTopicHandler
        public static EventHandler<RspQryTopicEventArgs> RspQryTopicHandler;
        public static void AddRspQryTopicHandler(EventHandler<RspQryTopicEventArgs> evt)
        {
            RspQryTopicHandler += evt;
        }
        public static void RemoveRspQryTopicHandler(EventHandler<RspQryTopicEventArgs> evt)
        {
            RspQryTopicHandler -= evt;
        }
        #endregion

        #region RtnDepthMarketDataHandler
        public static EventHandler<RtnDepthMarketDataEventArgs> RtnDepthMarketDataHandler;
        public static void AddRtnDepthMarketDataHandler(EventHandler<RtnDepthMarketDataEventArgs> evt)
        {
            RtnDepthMarketDataHandler += evt;
        }
        public static void RemoveRtnDepthMarketDataHandler(EventHandler<RtnDepthMarketDataEventArgs> evt)
        {
            RtnDepthMarketDataHandler -= evt;
        }
        #endregion*/
    }
}
