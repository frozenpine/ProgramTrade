using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgramTradeApi
{
    public interface IMarketApi:IDisposable
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
        int SubMarketData(HashSet<string> Instruments);
        int UnSubMarketData(HashSet<string> Instruments);
        void Release();
    }
}
