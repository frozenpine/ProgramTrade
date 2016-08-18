using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Collections.Concurrent;
using CLRXspeedApi;
using CLRQdpApi;
using System.ComponentModel;
using System.Collections.Specialized;

namespace ProgramTradeApi
{
    #region Brokers & Fronts
    public class Initiator
    {
        public bool ReqLogging { get; private set; }
        public bool RspLogging { get; private set; }
        public FrontServer Server { get; private set; }
        public Initiator(FrontServer svr, bool reqLogging = true, bool rspLogging = true)
        {
            Server = svr;
            ReqLogging = reqLogging;
            RspLogging = rspLogging;
        }
    }
    
    public enum BrokerType
    {
        QDP,
        XSpeed,
        CTP
    }

    public enum ServerType
    {
        TradeFrontSvr,
        MarketFrontSvr,
        QuickMarket
    }

    public class FrontServer
    {
        private TCPIP ip = new TCPIP();

        /// <summary>
        /// 服务器描述
        /// </summary>
        public string ServerName { get { return ip.IPv4Description; } }
        /// <summary>
        /// 服务器地址
        /// </summary>
        public string ServerIP { get { return ip.IPv4Address; } }
        /// <summary>
        /// 服务器端口
        /// </summary>
        public int ServerPort { get { return ip.Port; } }
        /// <summary>
        /// 服务器类型
        /// </summary>
        public ServerType ServerType { get; private set; }
        
        /// <summary>
        /// 服务器连接字串
        /// </summary>
        public string ConnString
        {
            get
            {
                if (ServerType != ServerType.QuickMarket)
                {
                    return "tcp://{ip}:{port}".Replace("{ip}", ServerIP).Replace("{port}", ServerPort.ToString());
                }
                else
                {
                    return "udp://{ip}:{port}".Replace("{ip}", ServerIP).Replace("{port}", ServerPort.ToString());
                }
            }
        }
        /// <summary>
        /// 服务器延时，以计时器tick周期数表示
        /// </summary>
        public long Delay { get; private set; }

        public bool Selected { get; set; }

        public FrontServer(string svrName, string svrIP,int svrPort,ServerType svrType)
        {
            ip.IPv4Address = svrIP;
            ip.Port = svrPort;
            ip.IPv4Description = svrName;
            ServerType = svrType;
            Delay = /*ip.DelayTest()*/-1;
        }

        public void GetDelay()
        {
            Delay = ip.DelayTest();
        }
    }

    public class FrontServers : HashSet<FrontServer>
    {
        public BrokerType BrokerType { get; private set; }
        public FrontServers this[ServerType svrType]
        {
            get
            {
                FrontServers result = new FrontServers(this.BrokerType);
                foreach (var svr in this)
                {
                    if (svr.ServerType == svrType)
                        result.Add(svr);
                }
                return result;
            }
        }

        public FrontServers(BrokerType type)
        {
            BrokerType = type;
        }
        public FrontServer Fastiest()
        {
            FrontServer result = this.FirstOrDefault();
            foreach(var svr in this)
            {
                svr.GetDelay();
                if(svr==result)
                {
                    result = svr;
                }
                else if(svr.Delay<result.Delay)
                {
                    result = svr;
                }
            }
            if (result.Delay > 0)
                return result;
            else
                throw new SocketException();
        }
    }

    public class Brokers : Dictionary<string, FrontServers>
    {
        public string SelectBroker { get; set; }
        public Brokers this[BrokerType type]
        {
            get
            {
                Brokers result = new Brokers();
                foreach (var brk in this)
                {
                    if (brk.Value.BrokerType == type)
                        result.Add(brk.Key, brk.Value);
                }
                return result;
            }
        }
        public FrontServers Current
        {
            get
            {
                return this[SelectBroker];
            }
        }
        public FrontServer SelectTradeFront
        {
            get
            {
                return this[SelectBroker][ServerType.TradeFrontSvr].Fastiest();
            }
        }
        public FrontServer SelectMarketFront
        {
            get
            {
                return this[SelectBroker][ServerType.MarketFrontSvr].Fastiest();
            }
        }
    }
    #endregion
    
    public enum Direction
    {
        /// <summary>
        /// 买入
        /// </summary>
        Buy,
        /// <summary>
        /// 卖出
        /// </summary>
        Sell
    }

    public enum Operation
    {
        /// <summary>
        /// 开仓
        /// </summary>
        Open,
        /// <summary>
        /// 平仓
        /// </summary>
        Close,
        /// <summary>
        /// 平今
        /// </summary>
        CloseToday
    }

    public enum Flag
    {
        /// <summary>
        /// 投机
        /// </summary>
        Speculator,
        /// <summary>
        /// 套保
        /// </summary>
        Hedge,
        /// <summary>
        /// 套利
        /// </summary>
        Arbitrage
    }

    public enum ExchangeID
    {
        /// <summary>
        /// 大商所
        /// </summary>
        DCE,
        /// <summary>
        /// 郑商所
        /// </summary>
        CZCE,
        /// <summary>
        /// 上期所
        /// </summary>
        SHFE,
        /// <summary>
        /// 中金所
        /// </summary>
        CFFEX,
        /// <summary>
        /// 上能所
        /// </summary>
        INE
    }

    public enum InstrumentType
    {
        /// <summary>
        /// 期货合约
        /// </summary>
        Futures,
        /// <summary>
        /// 期权合约
        /// </summary>
        Options
    }

    public enum OrderType
    {
        /// <summary>
        /// 市价单
        /// </summary>
        MarketPrice,
        /// <summary>
        /// 限价单
        /// </summary>
        LimitPrice
    }

    public enum OrderState
    {
        Error,
        Placed,
        Triggered,
        Canceling,
        Queuening,
        PartialDealed,
        PartialCaneled,
        AllDealed,
        AllCanceled
    }

    public class InsertOrder
    {
        public ExchangeID ExchangeID { get; set; }
        public string InstrumentID { get; set; }
        public int OrderLocalID { get; set; }
        public double InsertPrice { get; set; }
        public int OrderAmount { get; set; }
        public Direction BuySell { get; set; }
        public Operation OpenClose { get; set; }
        public Flag Flag { get; set; }
        public OrderType OrderType { get; set; }
        public OrderState OrderState { get; set; }
    }

    public class CancelOrder
    {
        public ExchangeID ExchangeID { get; set; }
        public string InstrumentID { get; set; }
        public int OrderID { get; set; }
    }

    public class InstrumentDetail : INotifyPropertyChanged
    {
        ExchangeID exchangeID;
        public ExchangeID ExchangeID
        {
            get { return exchangeID; }
            set
            {
                exchangeID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("ExchangeID"));
            }
        }

        string instrumentID;
        public string InstrumentID
        {
            get { return instrumentID; }
            set
            {
                instrumentID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("InstrumentID"));
            }
        }


        public event PropertyChangedEventHandler PropertyChanged;
    }

    public class PositionDetail : INotifyPropertyChanged
    {
        ExchangeID exchangeID;
        public ExchangeID ExchangeID
        {
            get { return exchangeID; }
            set { exchangeID = value; /*PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("ExchangeID"));*/ }
        }

        string instrumentID;
        public string InstrumentID
        {
            get { return instrumentID; }
            set
            {
                if (instrumentID != value)
                {
                    instrumentID = value;
                    PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("InstrumentID"));
                }
            }
        }

        Direction direction;
        public Direction Direction
        {
            get { return direction; }
            set { direction = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Direction")); }
        }

        double positionPrice;
        public double PositionPrice
        {
            get { return positionPrice; }
            set { positionPrice = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("PositionPrice")); }
        }

        int volumeAll;
        public int VolumeAll
        {
            get { return volumeAll; }
            set { volumeAll = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Volume")); }
        }

        int volumeToday;
        public int VolumeToday
        {
            get { return volumeToday; }
            set { volumeToday = value;PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("VolumeToday")); }
        }

        public int VolumeYestoday
        {
            get { return volumeAll - volumeToday; }
        }

        Flag flag;
        public Flag Flag
        {
            get { return flag; }
            set { flag = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Flag")); }
        }

        public static PositionDetail CreateDetail(CLRDFITCPositionInfoRtnField pos)
        {
            PositionDetail result = new PositionDetail();
            switch(pos.exchangeID)
            {
                case "DCE":
                    result.ExchangeID = ExchangeID.DCE;
                    break;
                case "CZCE":
                    result.ExchangeID = ExchangeID.CZCE;
                    break;
                case "SHFE":
                    result.ExchangeID = ExchangeID.SHFE;
                    break;
                case "CFFEX":
                    result.ExchangeID = ExchangeID.CFFEX;
                    break;
                case "INE":
                    result.ExchangeID = ExchangeID.INE;
                    break;
            }
            result.InstrumentID = pos.instrumentID;
            switch (pos.buySellType)
            {
                case (short)CLRDFITCBuySellType.SPD_BUY:
                    result.Direction = Direction.Buy;
                    break;
                case (short)CLRDFITCBuySellType.SPD_SELL:
                    result.Direction = Direction.Sell;
                    break;
            }
            result.PositionPrice = pos.positionAvgPrice;
            result.VolumeAll = pos.positionAmount;
            switch (pos.speculator)
            {
                case (int)CLRDFITCSpeculatorType.SPD_SPECULATOR:
                    result.Flag = Flag.Speculator;
                    break;
                case (int)CLRDFITCSpeculatorType.SPD_HEDGE:
                    result.Flag = Flag.Hedge;
                    break;
                case (int)CLRDFITCSpeculatorType.SPD_ARBITRAGE:
                    result.Flag = Flag.Arbitrage;
                    break;
            }
            return result;
        }
        public static PositionDetail CreateDetail(CLRDFITCMatchRtnField pos)
        {
            PositionDetail result = new PositionDetail();
            switch (pos.exchangeID)
            {
                case "DCE":
                    result.ExchangeID = ExchangeID.DCE;
                    break;
                case "CZCE":
                    result.ExchangeID = ExchangeID.CZCE;
                    break;
                case "SHFE":
                    result.ExchangeID = ExchangeID.SHFE;
                    break;
                case "CFFEX":
                    result.ExchangeID = ExchangeID.CFFEX;
                    break;
                case "INE":
                    result.ExchangeID = ExchangeID.INE;
                    break;
            }
            result.InstrumentID = pos.instrumentID;
            switch (pos.buySellType)
            {
                case (short)CLRDFITCBuySellType.SPD_BUY:
                    result.Direction = Direction.Buy;
                    break;
                case (short)CLRDFITCBuySellType.SPD_SELL:
                    result.Direction = Direction.Sell;
                    break;
            }
            result.PositionPrice = pos.matchedPrice;
            result.VolumeAll = pos.matchedAmount;
            switch (pos.speculator)
            {
                case (int)CLRDFITCSpeculatorType.SPD_SPECULATOR:
                    result.Flag = Flag.Speculator;
                    break;
                case (int)CLRDFITCSpeculatorType.SPD_HEDGE:
                    result.Flag = Flag.Hedge;
                    break;
                case (int)CLRDFITCSpeculatorType.SPD_ARBITRAGE:
                    result.Flag = Flag.Arbitrage;
                    break;
            }
            return result;
        }

        public static PositionDetail operator +(PositionDetail lpos, PositionDetail rpos)
        {
            lpos.PositionPrice = (lpos.PositionPrice * lpos.VolumeAll + rpos.PositionPrice * rpos.VolumeAll) / (lpos.VolumeAll += rpos.VolumeAll);
            return lpos;
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
    public class PositionList : ConcurrentDictionary<string, PositionDetail>
    {
        public PositionList this[ExchangeID exchange]
        {
            get
            {
                /*PositionList result = new PositionList();
                foreach (var list in this)
                {
                    if (list.Value.ExchangeID == exchange)
                    {
                        result.TryAdd(list.Key, list.Value);
                    }
                }
                return result;*/
                return (PositionList)this.Where(item => item.Value.ExchangeID == exchange);
            }
        }
    }

    public class MarketDetail : INotifyPropertyChanged
    {
        /// <summary>
        /// 交易所代码
        /// </summary>
        ExchangeID exchangeID;
        public ExchangeID ExchangeID
        {
            get { return exchangeID; }
            private set
            {
                exchangeID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("ExchangeID"));
            }
        }
        /// <summary>
        /// 合约代码
        /// </summary>
        string instrumentID;
        public string InstrumentID
        {
            get { return instrumentID; }
            private set
            {
                instrumentID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("InstrumentID"));
            }
        }
        /// <summary>
        /// 合约名
        /// </summary>
        string instrumentName;
        public string InstrumentName
        {
            get { return instrumentName; }
            set { instrumentName = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("InstrumentName")); }
        }
        /// <summary>
        /// 最新价
        /// </summary>
        double lastPrice;
        public double LatestPrice
        {
            get { return lastPrice; }
            private set
            {
                lastPrice = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("LatestPrice"));
            }
        }
        /// <summary>
        /// 开盘价
        /// </summary>
        double openPrice;
        public double OpenPrice
        {
            get { return openPrice; }
            private set
            {
                openPrice = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("OpenPrice"));
            }
        }
        /// <summary>
        /// 最高价
        /// </summary>
        double highestPrice;
        public double HighestPrice
        {
            get { return highestPrice; }
            private set
            {
                highestPrice = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("HighestPrice"));
            }
        }
        /// <summary>
        /// 最低价
        /// </summary>
        double lowestPrice;
        public double LowestPrice
        {
            get { return lowestPrice; }
            private set
            {
                lowestPrice = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("LowestPrice"));
            }
        }
        /// <summary>
        /// 收盘价
        /// </summary>
        double closePrice;
        public double ClosePrice
        {
            get { return closePrice; }
            private set
            {
                closePrice = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("ClosePrice"));
            }
        }
        /// <summary>
        /// 成交数量
        /// </summary>
        int volume;
        public int Volume
        {
            get { return volume; }
            private set
            {
                volume = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Volume"));
            }
        }

        double topLimitPrice;
        public double TopLimitPrice
        {
            get { return topLimitPrice; }
            private set { topLimitPrice = value;PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("TopLimitPrice")); }
        }

        double bottomLimitPrice;
        public double BottomLimitPrice
        {
            get { return bottomLimitPrice; }
            private set { bottomLimitPrice = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("BottomLimitPrice")); }
        }

        public static MarketDetail CreateMarketDetail(CLRDFITCDepthMarketDataField market)
        {
            MarketDetail result = new MarketDetail();
            switch (market.exchangeID)
            {
                case "DCE":
                    result.ExchangeID = ExchangeID.DCE;
                    break;
                case "CZCE":
                    result.ExchangeID = ExchangeID.CZCE;
                    break;
                case "SHFE":
                    result.ExchangeID = ExchangeID.SHFE;
                    break;
                case "CFFEX":
                    result.ExchangeID = ExchangeID.CFFEX;
                    break;
                case "INE":
                    result.ExchangeID = ExchangeID.INE;
                    break;
            }
            result.InstrumentID = market.instrumentID;
            result.LatestPrice = market.lastPrice;
            result.OpenPrice = market.openPrice;
            result.HighestPrice = market.highestPrice;
            result.LowestPrice = market.lowestPrice;
            result.ClosePrice = market.closePrice;
            result.Volume = market.Volume;
            result.TopLimitPrice = market.upperLimitPrice;
            result.BottomLimitPrice = market.lowerLimitPrice;
            return result;
        }
        public static MarketDetail CreateMarketDetail(string exchange, string instrument, string name)
        {
            MarketDetail result = new MarketDetail();
            switch (exchange)
            {
                case "大连":
                    result.ExchangeID = ExchangeID.DCE;
                    break;
                case "上海":
                    result.ExchangeID = ExchangeID.SHFE;
                    break;
                case "中金":
                    result.ExchangeID = ExchangeID.CFFEX;
                    break;
                case "郑州":
                    result.ExchangeID = ExchangeID.CZCE;
                    break;
            }
            result.InstrumentID = instrument;
            result.InstrumentName = name;
            return result;
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
    public class MarketList:ConcurrentDictionary<string,MarketDetail>
    {
        public MarketList this[ExchangeID exchange]
        {
            get
            {
                return (MarketList)this.Where(item => item.Value.ExchangeID == exchange);
            }
        }
    }

    public class OrderDetail:INotifyPropertyChanged
    {
        ExchangeID exchangID;
        public ExchangeID ExchangeID
        {
            get { return exchangID; }
            private set
            {
                exchangID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("ExchangeID"));
            }
        }

        int orderSysID;
        public int OrderSysID
        {
            get { return orderSysID; }
            private set
            {
                orderSysID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("OrderSysID"));
            }
        }

        string investorID;
        public string InvestorID
        {
            get { return investorID; }
            private set
            {
                investorID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("InvestorID"));
            }
        }

        string userID;
        public string UserID
        {
            get { return userID; }
            private set
            {
                userID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("UserID"));
            }
        }

        string instrumentID;
        public string InstrumentID
        {
            get { return instrumentID; }
            private set
            {
                instrumentID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("InstrumentID"));
            }
        }

        string orderLocalID;
        public string OrderLocalID
        {
            get { return orderLocalID; }
            private set
            {
                orderLocalID = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("OrderLocalID"));
            }
        }

        OrderType orderType;
        public OrderType OrderType
        {
            get { return orderType; }
            private set
            {
                orderType = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("OrderType"));
            }
        }

        OrderState orderStatus;
        public OrderState OrderStatus
        {
            get { return orderStatus; }
            set { orderStatus = value;PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("OrderStatus")); }
        }

        Direction direction;
        public Direction Direction
        {
            get { return direction; }
            private set
            {
                direction = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Direction"));
            }
        }

        Operation operation;
        public Operation Operation
        {
            get { return operation; }
            set { operation = value;PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Operation")); }
        }

        Flag flag;
        public Flag Flag
        {
            get { return flag; }
            private set
            {
                flag = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Flag"));
            }
        }

        double limitPrice;
        public double LimitPrice
        {
            get { return limitPrice; }
            private set
            {
                limitPrice = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("LimitPrice"));
            }
        }

        double matchedPrice;
        public double MatchedPrice
        {
            get { return matchedPrice; }
            set { matchedPrice = value;PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("MatchedPrice")); }
        }

        int volume;
        public int Volume
        {
            get { return volume; }
            private set
            {
                volume = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Volume"));
            }
        }

        int matchedVolume;
        public int MatchedVolume
        {
            get { return matchedVolume; }
            set { matchedVolume = value; PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("MatchedVolume")); }
        }

        public DateTime TradingDay { get; set; }

        public static OrderDetail CreateDetail(CLRDFITCOrderCommRtnField order)
        {
            OrderDetail result = new OrderDetail();
            result.OrderSysID = order.spdOrderID;
            switch(order.exchangeID)
            {
                case "DCE":
                    result.ExchangeID = ExchangeID.DCE;
                    break;
                case "CZCE":
                    result.ExchangeID = ExchangeID.CZCE;
                    break;
                case "CFFEX":
                    result.ExchangeID = ExchangeID.CFFEX;
                    break;
                case "SHFE":
                    result.ExchangeID = ExchangeID.SHFE;
                    break;
            }
            result.InstrumentID = order.instrumentID;
            switch(order.openClose)
            {
                case (int)CLRDFITCOpenCloseType.SPD_OPEN:
                    result.Operation = Operation.Open;
                    break;
                case (int)CLRDFITCOpenCloseType.SPD_CLOSE:
                    result.Operation = Operation.Close;
                    break;
            }
            switch(order.buySellType)
            {
                case (short)CLRDFITCBuySellType.SPD_BUY:
                    result.Direction = Direction.Buy;
                    break;
                case (short)CLRDFITCBuySellType.SPD_SELL:
                    result.Direction = Direction.Sell;
                    break;
            }
            result.LimitPrice = order.insertPrice;
            result.Volume = order.orderAmount;
            result.MatchedPrice = order.matchedPrice;
            result.MatchedVolume = order.matchedAmount;
            switch(order.orderStatus)
            {
                case (short)CLRDFITCOrderAnswerStatusType.SPD_CANCELED:
                    result.OrderStatus = OrderState.AllCanceled;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_FILLED:
                    result.OrderStatus = OrderState.AllDealed;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_IN_QUEUE:
                    result.OrderStatus = OrderState.Queuening;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_PARTIAL:
                    result.OrderStatus = OrderState.PartialDealed;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_PARTIAL_CANCELED:
                    result.OrderStatus = OrderState.PartialCaneled;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_IN_CANCELING:
                    result.OrderStatus = OrderState.Canceling;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_ERROR:
                    result.OrderStatus = OrderState.Error;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_PLACED:
                    result.OrderStatus = OrderState.Placed;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_TRIGGERED:
                    result.OrderStatus = OrderState.Triggered;
                    break;
            }
            return result;
        }
        public static OrderDetail CreateDetail(CLRDFITCOrderRtnField order)
        {
            OrderDetail result = new OrderDetail();
            result.OrderSysID = order.spdOrderID;
            switch (order.exchangeID)
            {
                case "DCE":
                    result.ExchangeID = ExchangeID.DCE;
                    break;
                case "CZCE":
                    result.ExchangeID = ExchangeID.CZCE;
                    break;
                case "CFFEX":
                    result.ExchangeID = ExchangeID.CFFEX;
                    break;
                case "SHFE":
                    result.ExchangeID = ExchangeID.SHFE;
                    break;
            }
            result.InstrumentID = order.instrumentID;
            switch (order.openCloseType)
            {
                case (int)CLRDFITCOpenCloseType.SPD_OPEN:
                    result.Operation = Operation.Open;
                    break;
                case (int)CLRDFITCOpenCloseType.SPD_CLOSE:
                    result.Operation = Operation.Close;
                    break;
            }
            switch (order.buySellType)
            {
                case (short)CLRDFITCBuySellType.SPD_BUY:
                    result.Direction = Direction.Buy;
                    break;
                case (short)CLRDFITCBuySellType.SPD_SELL:
                    result.Direction = Direction.Sell;
                    break;
            }
            result.LimitPrice = order.insertPrice;
            result.Volume = order.orderAmount;
            switch (order.orderStatus)
            {
                case (short)CLRDFITCOrderAnswerStatusType.SPD_CANCELED:
                    result.OrderStatus = OrderState.AllCanceled;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_FILLED:
                    result.OrderStatus = OrderState.AllDealed;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_IN_QUEUE:
                    result.OrderStatus = OrderState.Queuening;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_PARTIAL:
                    result.OrderStatus = OrderState.PartialDealed;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_PARTIAL_CANCELED:
                    result.OrderStatus = OrderState.PartialCaneled;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_IN_CANCELING:
                    result.OrderStatus = OrderState.Canceling;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_ERROR:
                    result.OrderStatus = OrderState.Error;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_PLACED:
                    result.OrderStatus = OrderState.Placed;
                    break;
                case (short)CLRDFITCOrderAnswerStatusType.SPD_TRIGGERED:
                    result.OrderStatus = OrderState.Triggered;
                    break;
            }
            return result;
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
    public class OrderList : ConcurrentDictionary<int, OrderDetail>,INotifyPropertyChanged,INotifyCollectionChanged
    {
        public OrderList this[ExchangeID exchange]
        {
            get
            {
                return (OrderList)this.Where(item => item.Value.ExchangeID == exchange);         
            }
        }

        public event NotifyCollectionChangedEventHandler CollectionChanged;
        public event PropertyChangedEventHandler PropertyChanged;
    }
}
