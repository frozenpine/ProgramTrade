using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using CLRQdpApi;
using CLRXspeedApi;
using System.Runtime.CompilerServices;

namespace ProgramTradeApi
{
    public sealed class TraderModel : ITraderModel,IDisposable
    {
        public IMarketApi MarketApi { get; private set; }
        public ITradeApi TradeApi { get; private set; }

        public Brokers Brokers { get; private set; }
        public PositionList Positions { get; private set; }
        public OrderList Orders { get; private set; }
        public MarketList Markets { get; private set; }

        public bool IsTradeConnected { get; private set; }

        public bool IsMarketConnected { get; private set; }

        public bool IsTradeLogined { get; private set; }

        public bool IsMarketLogined { get; private set; }

        public event EventHandler<RspEventArgs> eventFrontConnected;
        public event EventHandler<RspEventArgs> eventUserLogined;
        public event EventHandler eventPositionChanged;
        public event EventHandler eventOrderChanged;
        public event EventHandler eventMarketChanged;

        public TraderModel()
        {
            Brokers = new Brokers();
            Brokers.Add("XSpeed测试服务器群", new FrontServers(BrokerType.XSpeed));
            Brokers.Add("QDP测试服务器群", new FrontServers(BrokerType.QDP));
            Brokers["XSpeed测试服务器群"].Add(new FrontServer("XSpeed交易前置测试", "203.187.171.250", 10910, ServerType.TradeFrontSvr));
            Brokers["XSpeed测试服务器群"].Add(new FrontServer("XSpeed行情前置测试", "203.187.171.250", 10915, ServerType.MarketFrontSvr));
            Brokers["QDP测试服务器群"].Add(new FrontServer("QDP交易前置内网测试", "192.168.89.6", 30005, ServerType.TradeFrontSvr));

            Positions = new PositionList();
            Orders = new OrderList();
            Markets = CreateMarkets();

            IsTradeConnected = IsTradeLogined = false;
            IsMarketConnected = IsMarketLogined = false;
        }

        public void CreateTradeApi(BrokerType type)
        {
            switch(type)
            {
                case BrokerType.XSpeed:
                    TradeApi = new XTradeApi();
                    break;
                case BrokerType.QDP:
                    TradeApi = new QTradeApi();
                    break;
                default:
                    throw new NotImplementedException();
            }

            ProgramTradeEvents.AddRspHandler(RspSpiModules.FrontConnected, OnFrontConnected);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.UserLogin, OnUserLogin);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.QryPosition, OnRspQryPosition);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.QryOrders, OnRspQryOrder);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.OrderDeal, OnOrderDeal);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.RtnOrder, OnOrderReturn);
        }

        public void CreateMarketApi(BrokerType type)
        {
            switch (type)
            {
                case BrokerType.XSpeed:
                    MarketApi = new XMduserApi();
                    break;
                case BrokerType.QDP:
                    //MarketApi = 
                    break;
                default:
                    throw new NotImplementedException();
            }
            ProgramTradeEvents.AddRspHandler(RspSpiModules.RtnMarket, OnMarketDataReturn);
        }

        public void Dispose()
        {
            if (TradeApi != null)
            {
                TradeApi.Dispose();
            }
            if (MarketApi != null)
            {
                MarketApi.Dispose();
            }
        }

        private MarketList CreateMarkets()
        {
            MarketList list = new MarketList();
            list.TryAdd("a1607", MarketDetail.CreateMarketDetail("大连", "a1607", "黄大豆1号"));
            list.TryAdd("a1609", MarketDetail.CreateMarketDetail("大连", "a1609", "黄大豆1号"));
            list.TryAdd("a1611", MarketDetail.CreateMarketDetail("大连", "a1611", "黄大豆1号"));
            return list;
        }

        #region RspEventArgs Handlers
        private void OnFrontConnected(object sender, RspEventArgs e)
        {
            switch (sender.ToString())
            {
                case "ProgramTradeApi.XTradeSpi":
                    if (e.ErrorID == 0)
                    {
                        IsTradeConnected = true;
                    }
                    else
                    {
                        IsTradeConnected = false;
                    }
                    eventFrontConnected?.Invoke(sender, e);
                    break;
                case "ProgramTradeApi.XMduserSpi":
                    if (e.ErrorID == 0)
                    {
                        IsMarketConnected = true;
                    }
                    else
                    {
                        IsMarketConnected = false;
                    }
                    eventFrontConnected?.Invoke(sender, e);
                    break;
            }
        }
        private void OnUserLogin(object sender, RspEventArgs e)
        {
            switch (sender.ToString())
            {
                case "ProgramTradeApi.XTradeSpi":
                    if (e.ErrorID == 0)
                    {
                        IsTradeLogined = true;
                        TradeApi.RequestUserPosition();
                        TradeApi.RequestQueryOrders();
                    }
                    else
                    {
                        IsTradeLogined = false;
                    }
                    eventUserLogined?.Invoke(sender, e);
                    break;
                case "ProgramTradeApi.XMduserSpi":
                    if (e.ErrorID == 0)
                    {
                        IsMarketLogined = true;
                        HashSet<string> instruments = new HashSet<string>() { "a1607", "a1609", "a1611" };
                        MarketApi.SubMarketData(instruments); 
                    }
                    else
                    {
                        IsMarketLogined = false;
                    }
                    eventUserLogined?.Invoke(sender, e);
                    break;
            }
        }
        private void OnRspQryPosition(object sender,RspEventArgs e)
        {
            switch (sender.ToString())
            {
                    case "ProgramTradeApi.XTradeSpi":
                    if (e.ErrorID == 0)
                    {
                        var pos = PositionDetail.CreateDetail((e as TypedRspEventArgs<CLRDFITCPositionInfoRtnField, CLRDFITCErrorRtnField>).Data);
                        if (pos.InstrumentID != "")
                        {
                            Positions.AddOrUpdate(pos.InstrumentID + pos.Direction, pos, (k, v) => v);
                            if (e.IsLast)
                            {
                                eventPositionChanged?.Invoke(this, null);
                            }
                        }
                    }
                    else
                    {
                        var err = (e as TypedRspEventArgs<CLRDFITCPositionInfoRtnField, CLRDFITCErrorRtnField>).Error;
                    }
                    break;
            }
        }
        private void OnRspQryOrder(object sender,RspEventArgs e)
        {
            switch (sender.ToString())
            {
                case "ProgramTradeApi.XTradeSpi":
                    if (e.ErrorID == 0)
                    {
                        var odr = OrderDetail.CreateDetail((e as TypedRspEventArgs<CLRDFITCOrderCommRtnField, CLRDFITCErrorRtnField>).Data);
                        if (odr.OrderSysID > 0)
                        {
                            Orders.AddOrUpdate(odr.OrderSysID, odr, (k, v) => v);
                            if (e.IsLast)
                            {
                                eventOrderChanged?.Invoke(this, null);
                            }
                        }
                    }
                    else
                    {
                        var err = (e as TypedRspEventArgs<CLRDFITCOrderCommRtnField, CLRDFITCErrorRtnField>).Error;
                    }
                    break;
            }
        }
        private void OnOrderReturn(object sender,RspEventArgs e)
        {
            switch(sender.ToString())
            {
                case "ProgramTradeApi.XTradeSpi":
                    var odr = OrderDetail.CreateDetail((e as TypedRspEventArgs<CLRDFITCOrderRtnField, object>).Data);
                    Orders.AddOrUpdate(odr.OrderSysID, odr, (k, v) => odr);
                    eventOrderChanged?.Invoke(this, null);
                    break;
            }
        }
        private void OnOrderDeal(object sender,RspEventArgs e)
        {
            switch(sender.ToString())
            {
                case "ProgramTradeApi.XTradeSpi":
                    PositionDetail odr = PositionDetail.CreateDetail((e as TypedRspEventArgs<CLRDFITCMatchRtnField, object>).Data);
                    try
                    {
                        Positions.AddOrUpdate(odr.InstrumentID + odr.Direction, odr, (k, v) => { return v += odr; });
                        eventPositionChanged?.Invoke(this, null);
                    }
                    catch(Exception)
                    {
                        //deal exception
                    }
                    break;
            }
        }
        private void OnMarketDataReturn(object sender,RspEventArgs e)
        {
            switch(sender.ToString())
            {
                case "ProgramTradeApi.XMduserSpi":
                    MarketDetail market = MarketDetail.CreateMarketDetail((e as TypedRspEventArgs<CLRDFITCDepthMarketDataField, object>).Data);
                    Markets.AddOrUpdate(market.InstrumentID, market, (k, v) => { market.InstrumentName = v.InstrumentName; return market; });
                    //eventMarketChanged?.Invoke(this, null);
                    break;
            }
        }
        #endregion
    }
}
