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
        /// 前置连接应答
        /// </summary>
        FrontConnected,

        /// <summary>
        /// 心跳超时应答
        /// </summary>
        HeartBeatWarning,

        /// <summary>
        /// 前置断开应答
        /// </summary>
        FrontDisconnected,

        /// <summary>
        /// 交易所状态通知
        /// </summary>
        ExchangeStatus,

        /// <summary>
        /// 应答错误
        /// </summary>
        RspError,

        /// <summary>
        /// 用户登录应答
        /// </summary>
        UserLogin,

        /// <summary>
        /// 行情订阅应答
        /// </summary>
        SubMarket,

        /// <summary>
        /// 行情回报
        /// </summary>
        RtnMarket,

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
        /// 委托回报
        /// </summary>
        RtnOrder,

        /// <summary>
        /// 成交回报
        /// </summary>
        OrderDeal
    }

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

    internal static class ProgramTradeEvents
    {
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
    }
}
