using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgramTradeApi
{
    public interface ITradeApi:IDisposable
    {
        /// <summary>
        /// 前置初始化请求
        /// </summary>
        /// <param name="init">初始化参数</param>
        /// <returns>请求返回</returns>
        int Init(Initiator init);
        /// <summary>
        /// 用户登录请求
        /// </summary>
        /// <param name="AccountID">登录账号</param>
        /// <param name="Password">登录密码</param>
        /// <returns>请求返回</returns>
        int RequestUserLogin(string AccountID, string Password);
        /// <summary>
        /// 用户登出请求
        /// </summary>
        /// <returns>请求返回</returns>
        int RequestUserLogout();
        /// <summary>
        /// 用户持仓查询请求
        /// </summary>
        /// <returns>请求返回</returns>
        int RequestUserPosition();
        /// <summary>
        /// 交易所合约查询请求
        /// </summary>
        /// <param name="exchangeID">交易所代码</param>
        /// <param name="insType">合约类型</param>
        /// <returns>请求返回</returns>
        int RequestExchangeInstruments(ExchangeID exchangeID,InstrumentType insType);
        /// <summary>
        /// 委托查询请求
        /// </summary>
        /// <param name="Instruments">需要查询委托的合约号集合，如果为null，则查询全部委托</param>
        /// <returns>正常返回null，如返回非null，则为失败查询所请求的合约号集合</returns>
        HashSet<string> RequestQueryOrders(HashSet<string> Instruments = null);
        /// <summary>
        /// 撤单请求
        /// </summary>
        /// <param name="Orders">需撤单的委托</param>
        /// <returns>正常返回null，如返回非null，则为失败撤单所操作的委托号集合</returns>
        HashSet<int> CancelInstruments(HashSet<CancelOrder> Orders);
        /// <summary>
        /// 报单请求
        /// </summary>
        /// <param name="InsertOrders">报单集合</param>
        /// <returns>正常返回null，如返回非null，则为失败报单所操作的合约号集合</returns>
        HashSet<string> RequestInsertOrder(HashSet<InsertOrder> InsertOrders);

        void Release();
    }
}
