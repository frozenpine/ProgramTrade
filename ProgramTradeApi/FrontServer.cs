namespace ProgramTradeApi
{
    public class FrontServer
    {
        public string TradeServer { get; private set; }
        public string MarketServer { get; private set; }
        public string TradePort { get; private set; }
        public string MarketPort { get; private set; }

        public FrontServer(string trade,string tdport,string mdport,string market="")
        {
            TradeServer = trade;
            TradePort = tdport;
            MarketPort = mdport;
            if(market=="")
            {
                MarketServer = trade;
            }
            else
            {
                MarketServer = market;
            }
        }
    }
}
