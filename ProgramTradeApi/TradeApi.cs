using CLRQdpApi;
using System.Diagnostics;
using System.Threading;
using System;

namespace ProgramTradeApi
{
    /// <summary>
    /// QDP交易API C#封装
    /// </summary>
    public class TradeApi : CLRCQdpFtdcTraderApi, IDisposable
    {
        #region Class Member & Properties
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
        /// 数据中心ID号
        /// </summary>
        public int DataCenterID { get; private set; }

        /// <summary>
        /// 交易日属性
        /// </summary>
        public string TradingDay { get; private set; }

        /// <summary>
        /// 本地最大报单号属性
        /// </summary>
        public int MaxLocalOrderID { get; private set; }

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
        /// TradeApi构造函数
        /// 初始化RequestID为0
        /// 需在构造函数中注册需要侦听的TradeSpi事件的处理函数
        /// </summary>
        /// <param name="FlowPath">Flow文件存储路径</param>
        public TradeApi(string FlowPath = "") : base(FlowPath)
        {
            requestID = 0;
            ProgramTradeEvents.AddRspHandler(RspSpiModules.FrontConnected, FrontServerConnectedHandler);
            ProgramTradeEvents.AddRspUserLoginHandler(UserLoginHandler);
            ProgramTradeEvents.AddRspQryUserInvestorHandler(QryUserInvestorHandler);
            ProgramTradeEvents.AddRspUserLogoutHandler(UserLogoutHandler);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.FrontDisconnected, FrontServerDisconnectedHandler);
        }

        ~TradeApi()
        {
            Dispose(true);
        }

        protected override void Dispose(bool A_0)
        {
            if (!Disposed)
            {
                Release();
                Disposed = true;
            }
            base.Dispose(A_0);
        }

        #region Api Functions
        /// <summary>
        /// 注册前置服务器地址，并订阅数据流
        /// </summary>
        /// <param name="nResumeType">数据流订阅方式</param>
        /// <param name="frontServer">前置服务器地址、端口</param>
        /// <param name="isSubPrivate">是否订阅私有流</param>
        public void SubscribeTopics(CLRQDP_TE_RESUME_TYPE nResumeType, FrontServer frontServer/*,bool isSubPrivate=false*/)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread Called by TradeApi->SubscribeTopics", Thread.CurrentThread.ManagedThreadId);
#endif
            if (null != frontServer)
            {
                this.FrontServer = @"tcp://{ip}:{port}".Replace("{ip}", frontServer.TradeServer).Replace("{port}", frontServer.TradePort);
                base.SubscribePrivateTopic(nResumeType);
                base.SubscribePublicTopic(nResumeType);
                base.SubscribeUserTopic(nResumeType);
                base.RegisterFront(this.FrontServer);
                base.Init();
                //base.SetHeartbeatTimeout(3);
            }
        }

        /// <summary>
        /// 用户登录请求
        /// </summary>
        /// <param name="reqUserLogin">用户登录提交数据</param>
        public void UserLogin(CLRCQdpFtdcReqUserLoginField reqUserLogin)
        {
            base.ReqUserLogin(reqUserLogin, RequestID);
        }

        /// <summary>
        /// 提交订单
        /// </summary>
        /// <param name="ord">订单内容</param>
        public void SubmitOrder(CLRCQdpFtdcInputOrderField ord)
        {
            if (IsConnected)
            {
                this.ReqOrderInsert(ord, RequestID);
            }
        }

        /// <summary>
        /// 注销并清理API接口
        /// </summary>
        new public void Release()
        {
            if (IsConnected)
            {
                if (IsLogin)
                {
                    UserLogout();
                }
                Thread tr = new Thread(new ThreadStart(delegate { base.Join(); }));
                tr.IsBackground = true;
                tr.Start();
                base.Release();
            }
            else
            {
                base.Release();
            }
        }

        /// <summary>
        /// 用户登出请求
        /// </summary>
        public void UserLogout()
        {
            CLRCQdpFtdcRspUserLogoutField usrLogout = new CLRCQdpFtdcRspUserLogoutField();
            usrLogout.BrokerID = BrokerID;
            usrLogout.UserID = UserID;
            base.ReqUserLogout(usrLogout, RequestID);
        }

        public void ReqOrderAction(CLRCQdpFtdcOrderActionField OrderAction)
        {
            base.ReqOrderAction(OrderAction, RequestID);
        }
        #endregion

        #region EventHandlers
        /// <summary>
        /// 前置服务器连接事件的响应处理
        /// </summary>
        /// <param name="sender">前置服务器连接事件的发送者：TradeApi/MarketApi</param>
        /// <param name="e">前置服务器连接事件的返回参数</param>
        private void FrontServerConnectedHandler(object sender, RspEventArgs e)
        {
            if (sender is TradeSpi && 0 == e.ErrorID)
            {
                IsConnected = true;
                if(IsLogin)
                {
                    UserLogin(new CLRCQdpFtdcReqUserLoginField { UserID = this.UserID, Password = this.UserPwd, BrokerID = this.BrokerID });
                }
            }
        }

        /// <summary>
        /// 用户登录事件的响应处理
        /// </summary>
        /// <param name="sender">用户登录事件的发送者：TradeApi/MarketApi</param>
        /// <param name="e">用户登录事件的返回参数</param>
        private void UserLoginHandler(object sender, RspUserLoginEventArgs e)
        {
#if DEBUG
            Debug.WriteLine("Current ThreadID：{0},Thread Called by TradeApi->SetUserInfo", Thread.CurrentThread.ManagedThreadId);
#endif
            if (sender is TradeSpi && 0 == e.RspInfo.ErrorID)
            {
                UserID = e.RspUserLoin.UserID;
                BrokerID = e.RspUserLoin.BrokerID;
                DataCenterID = e.RspUserLoin.DataCenterID;
                TradingDay = e.RspUserLoin.TradingDay;
                int i;
                if(int.TryParse(e.RspUserLoin.MaxOrderLocalID, out i))
                {
                    MaxLocalOrderID = i;
                }

                IsLogin = true;
                base.ReqQryUserInvestor(new CLRCQdpFtdcQryUserInvestorField { BrokerID = BrokerID, UserID = UserID }, RequestID);
            }
        }

        /// <summary>
        /// FrontServerDisconnectedHandler 前置服务器连接断开事件的响应处理
        /// </summary>
        /// <param name="sender">前置服务器连接断开事件的发送者：TradeApi/MarketApi</param>
        /// <param name="e">前置服务器连接断开事件的返回参数</param>
        private void FrontServerDisconnectedHandler(object sender, RspEventArgs e)
        {
            if (sender is TradeSpi)
            {
                IsConnected = false;
                if((int)CLRQDP_FTFAIL_REASON.NORMAL_DISCONN == e.ErrorID)
#if DEBUG
                    Debug.WriteLine("Disconnect Front Server Normally.\r\nCurrent ThreadID：{0},Thread Called By TradeApi->DisconnectFront", Thread.CurrentThread.ManagedThreadId);
#endif
            }
        }

        private void QryUserInvestorHandler(object sender, RspQryUserInvestorEventArgs e)
        {
            if (sender is TradeApi && 0 == e.RspInfo.ErrorID)
            {
                InvestorID = e.RspUserInvestor.InvestorID;
            }
        }

        private void UserLogoutHandler(object sender,RspUserLogoutEventArgs e)
        {
            if (sender is TradeApi && 0 == e.RspInfo.ErrorID)
            {
                IsLogin = false;
            }
        }
        #endregion
    }
}
