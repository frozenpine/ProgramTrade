using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using CLRXspeedApi;

namespace ProgramTradeApi
{
    internal sealed class XMduserApi : IMarketApi
    {
        private CLRDFITCMduserApi clrXspeedMdApi;
        private CLRDFITCMduserSpi clrXspeedMdSpi;

        private static int requestID;
        private static int localOrderID;

        private static int RequestID
        {
            get { return requestID++; }
            set { requestID = value; }
        }
        public static int LocalOrderID
        {
            get { return localOrderID++; }
            set { localOrderID = value; }
        }
        public string FrontServers { get; private set; }
        public string AccountID { get; private set; }

        private string Password { get;  set; }
        public int SessionID { get; private set; }
        public short CompanyID { get; private set; }

        private bool released;

        public XMduserApi()
        {
            requestID = 0;
            clrXspeedMdApi = new CLRDFITCMduserApi();
            clrXspeedMdSpi = new XMduserSpi();
        }

        public void Dispose()
        {
            if (!released) Release();
        }

        public int Init(Initiator init)
        {
            if (init != null)
            {
                FrontServers = init.Server.ConnString;
                return clrXspeedMdApi.Init(FrontServers, clrXspeedMdSpi);
            }
            else
            {
                return -2;
            }
        }

        public void Release()
        {
            clrXspeedMdApi.Release();
            released = true;
        }

        public int RequestUserLogin(string AccountID, string Password)
        {
            CLRDFITCUserLoginField login = new CLRDFITCUserLoginField();
            login.accountID = AccountID;
            login.passwd = Password;
            login.lRequestID = RequestID;
            this.AccountID = AccountID;
            this.Password = Password;
            return clrXspeedMdApi.ReqUserLogin(login);
        }

        public int RequestUserLogout()
        {
            throw new NotImplementedException();
        }

        public int SubMarketData(HashSet<string> Instruments)
        {
            return clrXspeedMdApi.SubscribeMarketData(Instruments.ToArray(), RequestID);
        }

        public int UnSubMarketData(HashSet<string> Instruments)
        {
            return clrXspeedMdApi.UnSubscribeMarketData(Instruments.ToArray(), RequestID);
        }
    }
}
