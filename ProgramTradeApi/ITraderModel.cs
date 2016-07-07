using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgramTradeApi
{
    public interface ITraderModel:IDisposable
    {
        ITradeApi TradeApi { get; }
        IMarketApi MarketApi { get; }

        Brokers Brokers { get; }
        PositionList Positions { get; }
        OrderList Orders { get; }
        MarketList MarketDatas { get; }

        bool IsTradeConnected { get; }
        bool IsMarketConnected { get; }
        bool IsTradeLogined { get; }
        bool IsMarketLogined { get; }

        event EventHandler<RspEventArgs> eventTdFrontConnected;
        event EventHandler<RspEventArgs> eventTdUserLogined;
        //event EventHandler eventOrderInserted;
        event EventHandler eventPositionChanged;

        void CreateTradeApi(BrokerType type);
        void CreateMarketApi(BrokerType type);
    }
}
