using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CLRQdpApi;

namespace ProgramTradeApi
{
    /// <summary>
    /// 仅返回RspInfo应答的API模组
    /// </summary>
    public enum RspSpiModules
    {
        /// <summary>
        /// 前置服务器已连接应答模组
        /// </summary>
        FrontConnected,

        /// <summary>
        /// 心跳超时应答模组
        /// </summary>
        HeartBeatWarning,

        /// <summary>
        /// 前置服务器断开连接应答模组
        /// </summary>
        FrontDisconnected,

        /// <summary>
        /// 应答错误模组
        /// </summary>
        RspError
    }
    public class RspEventArgs : EventArgs
    {
        /// <summary>
        /// RspInfo应答消息
        /// </summary>
        public string Message { get; set; }

        /// <summary>
        /// RspInfo应答ID
        /// </summary>
        public int ErrorID { get; set; }

        /// <summary>
        /// RspInfo应答对应的请求ID
        /// </summary>
        public int RequestID { get; set; }

        /// <summary>
        /// 是否为最后一个应答报文
        /// </summary>
        public bool IsLast { get; set; }
    }
    public class RspUserLoginEventArgs : EventArgs
    {
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public CLRCQdpFtdcRspUserLoginField RspUserLoin { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspUserLogoutEventArgs : EventArgs
    {
        public CLRCQdpFtdcRspUserLogoutField RspUserLogout { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspOrderInsertEventArgs : EventArgs
    {
        public CLRCQdpFtdcInputOrderField InputOrder { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspUserPasswordUpdateEventArgs : EventArgs
    {
        public CLRCQdpFtdcUserPasswordUpdateField UserPasswordUpdate { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspOrderActionEventArgs : EventArgs
    {
        public CLRCQdpFtdcOrderActionField OrderAction { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspQryUserInvestorEventArgs : EventArgs
    {
        public CLRCQdpFtdcRspUserInvestorField RspUserInvestor { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class ErrRtnOrderInsertEventArgs : EventArgs
    {
        public CLRCQdpFtdcInputOrderField InputOrder { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
    }
    public class RtnInstrumentStatusEventArgs : EventArgs
    {
        public CLRCQdpFtdcInstrumentStatusField InstrumentStatus { get; set; }
    }
    public class RspQryInvestorAccountEventArgs : EventArgs
    {
        public CLRCQdpFtdcRspInvestorAccountField RspInvestorAccount { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RtnTradeEventArgs : EventArgs
    {
        public CLRCQdpFtdcTradeField Trade { get; set; }
    }
    public class RtnOrderEventArgs : EventArgs
    {
        public CLRCQdpFtdcOrderField Order { get; set; }
    }
    public class ErrRtnOrderActionEventArgs : EventArgs
    {
        public CLRCQdpFtdcOrderActionField OrderAction { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
    }
    public class RtnMessageNotifyEventArgs : EventArgs
    {
        public CLRCQdpFtdcMessageNotifyInfoField MessageNotifyInfo { get; set; }
    }
    public class RspQryOrderEventArgs : EventArgs
    {
        public CLRCQdpFtdcOrderField Order { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspQryTradeEventArgs : EventArgs
    {
        public CLRCQdpFtdcTradeField Trade { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspSubMarketDataEventArgs : EventArgs
    {
        public CLRCQdpFtdcSpecificInstrumentField SpecificInstrument { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspSubscribeTopicEventArgs : EventArgs
    {
        public CLRCQdpFtdcDisseminationField Dissemination { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public class RspQryTopicEventArgs : EventArgs
    {
        public CLRCQdpFtdcDisseminationField Dissemination { get; set; }
        public CLRCQdpFtdcRspInfoField RspInfo { get; set; }
        public int RequestID { get; set; }
        public bool IsLast { get; set; }
    }
    public static class ProgramTradeEvents
    {
        #region RspInfoHandler
        public static Dictionary<RspSpiModules, EventHandler<RspEventArgs>> RspEventHandler = new Dictionary<RspSpiModules, EventHandler<RspEventArgs>>(Enum.GetNames(typeof(RspSpiModules)).Length);
        public static void AddRspHandler(RspSpiModules system, EventHandler<RspEventArgs> evt)
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
        public static void RemoveRspHandler(RspSpiModules system, EventHandler<RspEventArgs> evt)
        {
            if (RspEventHandler.ContainsKey(system))
            {
                RspEventHandler[system] -= evt;
            }
        }
        #endregion

        #region RspUserLoginHandler
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
    }
}
