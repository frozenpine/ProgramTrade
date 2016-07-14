using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Collections;
using CLRXspeedApi;

namespace ProgramTradeApi
{
    internal sealed class XTradeApi : ITradeApi
    {
        private CLRDFITCTraderApi clrXspeedTradeApi;
        private CLRDFITCTraderSpi clrXspeedTradeSpi;

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

        private string Password { get; set; }
        public int SessionID { get; private set; }
        public short CompanyID { get; private set; }

        private bool released;

        public XTradeApi()
        {
            requestID = 0;
            clrXspeedTradeApi = new CLRDFITCTraderApi();
            clrXspeedTradeSpi = new XTradeSpi();
        }

        #region PrivatFunctions
        private void Transformer(InsertOrder odr,ref CLRDFITCInsertOrderField order)
        {
            order.accountID = AccountID;
            order.lRequestID = RequestID;
            order.localOrderID = LocalOrderID;
            order.instrumentID = odr.InstrumentID;
            order.insertPrice = odr.InsertPrice;
            order.orderAmount = odr.OrderAmount;
            switch(odr.BuySell)
            {
                case Direction.Buy:
                    order.buySellType = (short)CLRDFITCBuySellType.SPD_BUY;
                    break;
                case Direction.Sell:
                    order.buySellType = (short)CLRDFITCBuySellType.SPD_SELL;
                    break;
            }
            switch(odr.OpenClose)
            {
                case Operation.Open:
                    order.openCloseType = (int)CLRDFITCOpenCloseType.SPD_OPEN;
                    break;
                case Operation.Close:
                    order.openCloseType = (int)CLRDFITCOpenCloseType.SPD_CLOSE;
                    break;
                case Operation.CloseToday:
                    order.openCloseType = (int)CLRDFITCOpenCloseType.SPD_CLOSETODAY;
                    break;
            }
            switch(odr.Flag)
            {
                case Flag.Speculator:
                    order.speculator = (int)CLRDFITCSpeculatorType.SPD_SPECULATOR;
                    break;
                case Flag.Hedge:
                    order.speculator = (int)CLRDFITCSpeculatorType.SPD_HEDGE;
                    break;
                case Flag.Arbitrage:
                    order.speculator = (int)CLRDFITCSpeculatorType.SPD_ARBITRAGE;
                    break;
            }
            switch(odr.OrderType)
            {
                case OrderType.MarketPrice:
                    order.orderType = (int)CLRDFITCOrderType.MKORDER;
                    break;
                case OrderType.LimitPrice:
                    order.orderType = (int)CLRDFITCOrderType.LIMITORDER;
                    break;
            }
            order.insertType = (int)CLRDFITCInsertType.BASIC_ORDER;
            order.instrumentType = (int)CLRDFITCInstrumentType.COMM_TYPE;
        }
        #endregion

        public int Init(Initiator init)
        {
            if (null != init)
            {
                this.FrontServers = init.Server.ConnString;
                return clrXspeedTradeApi.Init(FrontServers, clrXspeedTradeSpi);
            }
            else
            {
                return -2;
            }
        }

        public int RequestUserLogin(string AccountID, string Password)
        {
            CLRDFITCUserLoginField UserLoginData = new CLRDFITCUserLoginField();
            UserLoginData.lRequestID = RequestID;
            UserLoginData.accountID = AccountID;
            UserLoginData.passwd = Password;
            //UserLoginData.companyID = CompanyID;
            this.AccountID = AccountID;
            this.Password = Password;
            return clrXspeedTradeApi.ReqUserLogin(UserLoginData);
        }

        public int RequestUserLogout()
        {
            CLRDFITCUserLogoutField UserLogoutData = new CLRDFITCUserLogoutField();
            UserLogoutData.lRequestID = RequestID;
            UserLogoutData.accountID = AccountID;
            UserLogoutData.sessionID = SessionID;
            return clrXspeedTradeApi.ReqUserLogout(UserLogoutData);
        }

        public int RequestUserPosition()
        {
            CLRDFITCPositionField PositionData = new CLRDFITCPositionField();
            PositionData.accountID = AccountID;
            PositionData.lRequestID = RequestID;
            PositionData.instrumentType = (int)CLRDFITCInstrumentType.COMM_TYPE;
            return clrXspeedTradeApi.ReqQryPosition(PositionData);
        }

        public HashSet<int> CancelInstruments(HashSet<CancelOrder> Orders=null)
        {
            HashSet<int> results = new HashSet<int>();
            if (null == Orders)
            {
                CLRDFITCCancelAllOrderField cancelall = new CLRDFITCCancelAllOrderField();
                cancelall.accountID = AccountID;
                cancelall.lRequestID = requestID;
                cancelall.exchangeID = "DCE";
                if (0 != clrXspeedTradeApi.ReqCancelAllOrder(cancelall))
                {
                    results.Add(-1);
                }
            }
            else if (Orders.Count > 0)
            {
                CLRDFITCCancelOrderField cancel = new CLRDFITCCancelOrderField();
                foreach (var odr in Orders)
                {
                    cancel.accountID = AccountID;
                    cancel.lRequestID = RequestID;
                    cancel.spdOrderID = odr.OrderID;
                    cancel.instrumentID = odr.InstrumentID;
                    if (0 != clrXspeedTradeApi.ReqCancelOrder(cancel))
                    {
                        results.Add(odr.OrderID);
                    }
                }
            }
            if (results.Count > 0)
                return results;
            else
                return null;
        }

        public HashSet<string> RequestQueryOrders(HashSet<string> Instruments = null)
        {
            HashSet<string> results = new HashSet<string>();
            CLRDFITCOrderField odr = new CLRDFITCOrderField();
            if (null == Instruments)
            {
                odr.accountID = AccountID;
                odr.lRequestID = RequestID;
                odr.instrumentType = (int)CLRDFITCInstrumentType.COMM_TYPE;
                if (0 != clrXspeedTradeApi.ReqQryOrderInfo(odr))
                {
                    results.Add("查询委托信息失败！");
                }
            }
            else if (Instruments.Count > 0)
            {
                foreach (var instrument in Instruments)
                {
                    odr.accountID = AccountID;
                    odr.instrumentID = instrument;
                    odr.lRequestID = RequestID;
                    odr.instrumentType = (int)CLRDFITCInstrumentType.COMM_TYPE;
                    if (0 != clrXspeedTradeApi.ReqQryOrderInfo(odr))
                    {
                        results.Add(instrument);
                    }
                }
            }
            if (results.Count > 0)
                return results;
            else
                return null;
        }

        public HashSet<string> RequestInsertOrder(HashSet<InsertOrder> InsertOrders)
        {
            HashSet<String> result = new HashSet<String>();
            if (null != InsertOrders)
            {
                CLRDFITCInsertOrderField order = new CLRDFITCInsertOrderField();
                foreach (var odr in InsertOrders)
                {
                    Transformer(odr, ref order);
                    clrXspeedTradeApi.ReqInsertOrder(order);
                }
            }
            if (result.Count > 0)
                return result;
            else
                return null;
        }

        public int RequestExchangeInstruments(ExchangeID exchangeID, InstrumentType insType)
        {
            CLRDFITCExchangeInstrumentField reqext = new CLRDFITCExchangeInstrumentField();
            reqext.accountID = AccountID;
            reqext.lRequestID = RequestID;
            reqext.exchangeID = exchangeID.ToString();
            switch (insType)
            {
                case InstrumentType.Futures:
                    reqext.instrumentType = (int)CLRDFITCInstrumentType.COMM_TYPE;
                    break;
                case InstrumentType.Options:
                    reqext.instrumentType = (int)CLRDFITCInstrumentType.OPT_TYPE;
                    break;
                default:
                    return -1;
            }
            return clrXspeedTradeApi.ReqQryExchangeInstrument(reqext);
        }

        public void Release()
        {
            clrXspeedTradeApi.Release();
            released = true;
        }

        public void Dispose()
        {
            if (!released) Release();
        }

        public HashSet<ExchangeID> RequestExchangeStatus(HashSet<ExchangeID> exchanges=null)
        {
            HashSet<ExchangeID> result = new HashSet<ExchangeID>();
            foreach (var exchange in exchanges)
            {
                CLRDFITCQryExchangeStatusField status = new CLRDFITCQryExchangeStatusField();
                status.lRequestID = RequestID;
                status.exchangeID = exchange.ToString();
                if(clrXspeedTradeApi.ReqQryExchangeStatus(status)!=0)
                {
                    result.Add(exchange);
                }
            }
            if (result.Count > 0)
                return result;
            else
                return null;
        }
    }
}
