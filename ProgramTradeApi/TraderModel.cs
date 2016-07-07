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

        //Brokers brokers = new Brokers();
        public Brokers Brokers { get; private set; }

        //PositionList positions = new PositionList();
        public PositionList Positions { get; private set; }

        //OrderList orders = new OrderList();
        public OrderList Orders { get; private set; }

        public MarketList MarketDatas { get; private set; }

        public bool IsTradeConnected { get; private set; }

        public bool IsMarketConnected { get; private set; }

        public bool IsTradeLogined { get; private set; }

        public bool IsMarketLogined { get; private set; }

        public event EventHandler<RspEventArgs> eventTdFrontConnected;
        public event EventHandler<RspEventArgs> eventTdUserLogined;
        public event EventHandler eventPositionChanged;

        //public event EventHandler eventOrderInserted;

        public TraderModel()
        {
            Brokers = new Brokers();
            Brokers.Add("XSpeed测试服务器群", new FrontServers(BrokerType.XSpeed));
            Brokers.Add("QDP测试服务器群", new FrontServers(BrokerType.QDP));
            Brokers["XSpeed测试服务器群"].Add(new FrontServer("XSpeed交易前置测试", "203.187.171.250", 10910, ServerType.TradeFrontSvr));
            Brokers["QDP测试服务器群"].Add(new FrontServer("QDP交易前置内网测试", "192.168.89.6", 30005, ServerType.TradeFrontSvr));

            Positions = new PositionList();

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

            ProgramTradeEvents.AddRspHandler(RspSpiModules.TdFrontConnected, OnTradeFrontConnected);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.UserLogin, OnTdUserLogined);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.QryPosition, OnRspQryPosition);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.QryOrders, OnRspQryOrder);
            ProgramTradeEvents.AddRspHandler(RspSpiModules.OrderDeal, OnOrderDeal);
        }

        public void CreateMarketApi(BrokerType type)
        {
            throw new NotImplementedException();
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

        #region RspEventArgs Handlers
        private void OnTradeFrontConnected(object sender,RspEventArgs e)
        {
            if (e.ErrorID == 0)
            {
                IsTradeConnected = true;
            }
            else
            {
                IsTradeConnected = false;
            }
            eventTdFrontConnected?.Invoke(sender, e);
        }
        private void OnTdUserLogined(object sender,RspEventArgs e)
        {
            if (e.ErrorID == 0)
            {
                IsTradeLogined = true;
            }
            else
            {
                IsTradeLogined = false;
            }
            eventTdUserLogined?.Invoke(sender, e);
        }
        private void OnRspQryPosition(object sender,RspEventArgs e)
        {
            switch (sender.ToString())
            {
                               case "ProgramTradeApi.XTradeSpi":
                    if (e.ErrorID == 0)
                    {
                        var pos = (e as TypedRspEventArgs<CLRDFITCPositionInfoRtnField, CLRDFITCErrorRtnField>).Data;
                        if (pos.instrumentID != "")
                        {
                            Positions.AddOrUpdate(pos.instrumentID, new PositionDetail(pos), (k, v) => v);
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
                        var odr = (e as TypedRspEventArgs<CLRDFITCOrderCommRtnField, CLRDFITCErrorRtnField>).Data;
                        if (odr.spdOrderID > 0)
                        {
                            Orders.AddOrUpdate(odr.spdOrderID, new OrderDetail(odr), (k, v) => v);
                            if(e.IsLast)
                            {
                                // shoot event
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
        private void OnOrderDeal(object sender,RspEventArgs e)
        {
            switch(sender.ToString())
            {
                case "ProgramTradeApi.XTradeSpi":
                    PositionDetail odr = new PositionDetail((e as TypedRspEventArgs<CLRDFITCMatchRtnField, object>).Data);
                    if(Positions.ContainsKey(odr.InstrumentID) && Positions[odr.InstrumentID].Direction==odr.Direction)
                    {
                        Positions[odr.InstrumentID] += odr;
                    }
                    else
                    {
                        Positions.TryAdd(odr.InstrumentID, odr);
                    }
                    break;
            }
        }
        #endregion
    }
}
