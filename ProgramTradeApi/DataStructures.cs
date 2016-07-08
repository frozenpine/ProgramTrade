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
            Delay = ip.DelayTest();
        }

        public long RefreshDelay()
        {
            Delay = ip.DelayTest();
            return Delay;
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
            FrontServer result = this.FirstOrDefault<FrontServer>();
            long delay = result.Delay;
            foreach(var svr in this)
            {
                if (svr != result)
                {
                    long dly = svr.Delay;
                    if (dly > 0 && dly < delay)
                    {
                        delay = dly;
                        result = svr;
                    }
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
        InsFailed,
        Inserted,
        InsNoFirmed,
        InsConfirmed,
        InsInQueen,
        PartialDealed,
        AllDealed
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

    public class PositionDetail : INotifyPropertyChanged
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

        Direction direction;
        public Direction Direction
        {
            get { return direction; }
            set
            {
                direction = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Direction"));
            }
        }

        double positionPrice;
        public double PositionPrice
        {
            get { return positionPrice; }
            set
            {
                positionPrice = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("PositionPrice"));
            }
        }

        int volume;
        public int Volume
        {
            get { return volume; }
            set
            {
                volume = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Volume"));
            }
        }

        Flag flag;
        public Flag Flag
        {
            get { return flag; }
            set
            {
                flag = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs("Flag"));
            }
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
            result.Volume = pos.positionAmount;
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
            result.PositionPrice = pos.insertPrice;
            result.Volume = pos.orderAmount;
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
            lpos.PositionPrice = (lpos.PositionPrice * lpos.Volume + rpos.PositionPrice * rpos.Volume) / (lpos.Volume += rpos.Volume);
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

        /*public static OrderDetail CreateDetail(CLRCQdpFtdcInputOrderField ord)
        {
            OrderDetail result = new OrderDetail();

            return result;
        }*/
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
            return result;
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }
    public class OrderList : ConcurrentDictionary<int, OrderDetail>
    {
        public OrderList this[ExchangeID exchange]
        {
            get
            {
                return (OrderList)this.Where(item => item.Value.ExchangeID == exchange);         
            }
        }
    }
}
