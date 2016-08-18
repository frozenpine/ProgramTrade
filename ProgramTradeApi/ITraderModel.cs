using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgramTradeApi
{
    public interface ITraderModel:IDisposable
    {
        ITradeApi ITradeApi { get; }
        IMarketApi IMarketApi { get; }

        Brokers Brokers { get; }
        PositionList Positions { get; }
        OrderList Orders { get; }
        MarketList Markets { get; }

        bool IsTradeConnected { get; }
        bool IsMarketConnected { get; }
        bool IsTradeLogined { get; }
        bool IsMarketLogined { get; }

        event EventHandler<RspEventArgs> eventFrontConnected;
        event EventHandler<RspEventArgs> eventUserLogined;
        event EventHandler eventOrderChanged;
        event EventHandler eventPositionChanged;
        event EventHandler eventMarketChanged;

        void CreateTradeApi(BrokerType type);
        void CreateMarketApi(BrokerType type);

        Brokers CreateBrokersFromConf(string path="");
        MarketList CreateMarketsFromConf(string path = "");
    }
}
