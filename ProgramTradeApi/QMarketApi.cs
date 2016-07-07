using CLRQdpApi;
using System.Diagnostics;
using System.Threading;
using System;

namespace ProgramTradeApi
{
    /// <summary>
    /// QDP行情API C#封装
    /// </summary>
    internal sealed class QMarketApi
    {
        #region Class Members & Properties
        private CLRCQdpFtdcMduserApi clrMduserApi;
        private CLRCQdpFtdcMduserSpi clrMduserSpi;

        private static int requestID;

        private bool Disposed = false;

        /// <summary>
        /// API请求ID号属性
        /// 每次获取RequestID后自增长
        /// </summary>
        public static int RequestID
        {
            get { return requestID++; }
            private set { requestID = value; }
        }

        /// <summary>
        /// 登录用户ID
        /// </summary>
        public string UserID { get; private set; }

        /// <summary>
        /// 登录用户密码
        /// </summary>
        public string UserPwd { get; set; }

        /// <summary>
        /// 接入商ID号属性
        /// </summary>
        public string BrokerID { get; private set; }

        /// <summary>
        /// 投资者账号ID属性
        /// </summary>
        public string InvestorID { get; private set; }

        /// <summary>
        /// 前置服务器连接字符串属性
        /// </summary>
        public string FrontServer { get; private set; }

        /// <summary>
        /// 用户是否已登录属性
        /// </summary>
        public bool IsLogin { get; private set; }
        
        /// <summary>
        /// 前置服务器是否已连接属性
        /// </summary>
        public bool IsConnected { get; private set; }
        #endregion

        /// <summary>
        /// MarketApi构造函数
        /// 初始化RequestID为0
        /// 需在构造函数中注册需要侦听的MarketSpi事件的处理函数
        /// </summary>
        /// <param name="FlowPath">Flow文件存储路径</param>
        public QMarketApi(bool Logging = true)
        {
            requestID = 0;
            /*ProgramTradeEvents.AddRspHandler(RspSpiModules.FrontConnected, FrontConnectedHandler);
            ProgramTradeEvents.AddRspUserLoginHandler(UserLoginHandler);
            ProgramTradeEvents.AddRspUserLogoutHandler(UserLogoutHandler);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.FrontDisconnected, FrontDisconnecedHandler);*/
            clrMduserApi = new CLRCQdpFtdcMduserApi(@"Flow\");
            clrMduserSpi = new QMarketSpi();
            clrMduserApi.RegisterSpi(clrMduserSpi);
            if(Logging)
            {
                //do something here
            }
        }

        ~QMarketApi()
        {
            if (!Disposed)
            {
                //do something here
                Disposed = true;
            }
        }

        #region Api Functions
        /// <summary>
        /// SubscribeTopics 注册行情前置服务器地址，并设置订阅主题
        /// </summary>
        /// <param name="resumeType">订阅流传输方式</param>
        /// <param name="topicID">订阅主题号</param>
        /// <param name="frontServer">前置服务器地址及端口</param>
        public void SubscribeTopics(CLRQDP_TE_RESUME_TYPE resumeType,int[] topicIDs,FrontServers frontServer)
        {
            if (null != frontServer)
            {
                //this.FrontServer = @"tcp://{ip}:{port}".Replace("{ip}", frontServer.TradeServer).Replace("{port}", frontServer.MarketPort);
                clrMduserApi.RegisterFront(FrontServer);
                foreach (var id in topicIDs)
                {
                    clrMduserApi.SubscribeMarketDataTopic(id, resumeType);
                }
                clrMduserApi.Init();
            }
        }

        public void UserLogin(CLRCQdpFtdcReqUserLoginField user)
        {
            clrMduserApi.ReqUserLogin(user, RequestID);
        }
        #endregion

        #region EventHandlers
        private void FrontConnectedHandler(object sender,RspEventArgs e)
        {
            if (sender is QMarketSpi/* && 0 == e.Error*/)
            {
                IsConnected = true;
                if (IsLogin)
                {
                    UserLogin(new CLRCQdpFtdcReqUserLoginField { BrokerID = this.BrokerID, UserID = this.UserID, Password = this.UserPwd });
                }
            }
        }

        /*private void UserLoginHandler(object sender,RspUserLoginEventArgs e)
        {
            if (sender is QMarketSpi && 0 == e.RspInfo.ErrorID)
            {
                UserID = e.RspUserLoin.UserID;
                BrokerID = e.RspUserLoin.BrokerID;
                
                IsLogin = true;
            }
        }

        private void UserLogoutHandler(object sender, RspUserLogoutEventArgs e)
        {
            if (sender is QMarketSpi && 0 == e.RspInfo.ErrorID)
            {
                IsLogin = false;
            }
        }*/

        private void FrontDisconnecedHandler(object sender,RspEventArgs e)
        {
            if(sender is QMarketSpi)
            {
                IsConnected = false;
                if ((int)CLRQDP_FTFAIL_REASON.NORMAL_DISCONN == (int)e.ErrorID)
#if DEBUG
                    Debug.WriteLine("Disconnect Front Server Normally.\r\nCurrent ThreadID：{0},Thread Called By TradeApi->DisconnectFront", Thread.CurrentThread.ManagedThreadId);
#endif
            }
        }

        public void SubMarketData(string[] InstrumentIDs)
        {
            clrMduserApi.SubMarketData(InstrumentIDs);
        }
        #endregion
    }
}
