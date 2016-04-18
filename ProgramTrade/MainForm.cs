using CLRQdpApi;
using ProgramTradeApi;
using ProgramTradeModules;
using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ProgramTrade
{
    public partial class MainForm : Form
    {
        protected static TradeApi tradeApi = new TradeApi(@"flow\");

        protected static TradeSpi tradeSpi = new TradeSpi();

        protected static MarketApi marketApi = new MarketApi(@"flow\");

        protected static MarketSpi marketSpi = new MarketSpi();

        private Dictionary<int, OrderList> dicOrderLists = new Dictionary<int, OrderList>();

        private string[] Instruments;

#if DEBUG
        private TextWriterTraceListener t = new TextWriterTraceListener(@"syslog\debug.log");
#endif

        #region Class Functions
        public MainForm()
        {
            tradeApi.RegisterSpi(tradeSpi);
            marketApi.RegisterSpi(marketSpi);
            tradeApi.OpenRequestLog(@"Syslog\TradeReq.log");
            tradeApi.OpenResponseLog(@"Syslog\TradeRsp.log");

            ProgramTradeEvents.AddRspOrderInsertHandler(OrderInsertHandler);
            ProgramTradeEvents.AddErrRtnOrderInsertHandler(ErrRtnOrderHandler);
            ProgramTradeEvents.AddRspOrderActionHandler(OrderActionHandler);
            ProgramTradeEvents.AddRtnInstrumentStatusHandler(InstrumentStatusHandler);

#if DEBUG
            Debug.Listeners.Add(t);
#endif

            InitializeComponent();
            if (File.Exists(@"Instrument.csv"))
            {
                Instruments = File.ReadAllLines(@"Instrument.csv", System.Text.Encoding.Default);
                gdvwCodes.DataSource = (from l in Instruments.AsParallel().AsOrdered()
                                        let col = l.Split(new[] { ',', ' ' }, StringSplitOptions.RemoveEmptyEntries)
                                        select new
                                        {
                                            交易所 = col[0],
                                            合约号 = col[1],
                                            合约名称 = col[2],
                                            每手数量 = col[3],
                                            单价 = col[4],
                                            最大量 = col[5]
                                        }).ToArray();
            }
            else
            {
                MessageBox.Show("合约文件不存在！", "注意！", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            SetOrderListDataSource();

            odvwOpenOrders.OrderViewerDbClickHandler += OrderViewDbClick;
            odvwAllOrders.OrderViewerDbClickHandler += OrderViewDbClick;
        }

        private void SetOrderListDataSource()
        {
            odvwOpenOrders.DataSource = dicOrderLists.AsParallel().AsOrdered().Where(i => i.Value.IsOpenOrder).Select(v =>
                new
                {
                    本地报单号 = v.Key,
                    合约号 = v.Value.InputOrder.InstrumentID,
                    买卖 = Enum.Parse(typeof(CLRQDP_FTDC_D), v.Value.InputOrder.Direction.ToString()),
                    开平 = Enum.Parse(typeof(CLRQDP_FTDC_OF), v.Value.InputOrder.OffsetFlag.ToString()),
                    价格 = v.Value.InputOrder.LimitPrice,
                    数量 = v.Value.InputOrder.Volume,
                    订单状态 = v.Value.OrderStatus
                }).ToArray();
            odvwAllOrders.DataSource = dicOrderLists.AsParallel().AsOrdered().Select(v =>
                new
                {
                    本地报单号 = v.Key,
                    合约号 = v.Value.InputOrder.InstrumentID,
                    买卖 = Enum.Parse(typeof(CLRQDP_FTDC_D), v.Value.InputOrder.Direction.ToString()),
                    开平 = Enum.Parse(typeof(CLRQDP_FTDC_OF), v.Value.InputOrder.OffsetFlag.ToString()),
                    价格 = v.Value.InputOrder.LimitPrice,
                    数量 = v.Value.InputOrder.Volume,
                    订单状态 = v.Value.OrderStatus
                }).ToArray();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            LoginForm login = new LoginForm(tradeApi, marketApi);
            login.ShowDialog(this);
            if(DialogResult.Cancel==login.DialogResult)
            {
                this.Close();
            }
        }

        private void btnAddOrderList_Click(object sender, EventArgs e)
        {
            CLRCQdpFtdcInputOrderField inputOrder = new CLRCQdpFtdcInputOrderField();
            int requestID = TradeApi.RequestID;

            inputOrder.BrokerID = tradeApi.BrokerID;
            inputOrder.ExchangeID = lbExchange.Text/*"CZCE"*/;
            inputOrder.InvestorID = tradeApi.InvestorID;
            inputOrder.UserID = tradeApi.UserID;
            inputOrder.InstrumentID = txtInstrumentID.Text/*"WH507"*/;
            inputOrder.UserOrderLocalID = requestID.ToString();
            inputOrder.OrderPriceType = (char)CLRQDP_FTDC_OPT.LimitPrice;
            if (rdoBuy.Checked)
            {
                inputOrder.Direction= (char)CLRQDP_FTDC_D.Buy;
            }
            else
            {
                inputOrder.Direction = (char)CLRQDP_FTDC_D.Sell;
            }
            if (rdoOpen.Checked)
            {
                inputOrder.OffsetFlag = (char)CLRQDP_FTDC_OF.Open;
            }
            else
            {
                inputOrder.OffsetFlag = (char)CLRQDP_FTDC_OF.Close;
            }
            inputOrder.HedgeFlag = (char)CLRQDP_FTDC_CHF.Speculation;
            inputOrder.LimitPrice = double.Parse(numPrice.Value.ToString());
            inputOrder.Volume = int.Parse(numVolume.Value.ToString());
            inputOrder.TimeCondition = (char)CLRQDP_FTDC_TC.GFD;
            inputOrder.VolumeCondition = (char)CLRQDP_FTDC_VC.AV;
            inputOrder.ForceCloseReason = (char)CLRQDP_FTDC_FCR.NotForceClose;
            inputOrder.IsAutoSuspend = 0;

            OrderList list = new OrderList
            {
                InputOrder = inputOrder,
                IsOpenOrder = ((sender as Button).Name == "btnAddOpenOrder"),
                OrderStatus = "等待开市报单"
            };
            dicOrderLists.Add(requestID, list);

            if((sender as Button).Name == "btnAddOpenOrder")
            {
                tabOrders.SelectedTab = tabOrders.TabPages["tabPageOpenOrders"];
            }
            else
            {
                tabOrders.SelectedTab = tabOrders.TabPages["tabPageAllOrders"];
            }

            SetOrderListDataSource();
        }

        private void 切换显示ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (tabExchange.SelectedTab.HasChildren)
            {
                MarketViewer view = tabExchange.SelectedTab.Controls[0] as MarketViewer;
                if (null != view)
                {
                    view.ChangViewSide();
                }
            }
        }

        private void btnParellel_Click(object sender, EventArgs e)
        {
            Parallel.ForEach(dicOrderLists.Values, item =>
             {
#if DEBUG
                Debug.WriteLine("Current ThreadID：{0},Thread Called by MainForm->btnParellel_Click\r\nCurrent OrderID：{1}", Thread.CurrentThread.ManagedThreadId,item.InputOrder.UserOrderLocalID);
#endif
                 tradeApi.SubmitOrder(item.InputOrder);
            });
        }

        private void gdvwCodes_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            CLRCQdpFtdcQryInstrumentField qryInstrument = new CLRCQdpFtdcQryInstrumentField();

            txtInstrumentID.Text = gdvwCodes.Rows[e.RowIndex].Cells["合约号"].Value.ToString();
            qryInstrument.InstrumentID = txtInstrumentID.Text;

            numPrice.Increment = decimal.Parse(gdvwCodes.Rows[e.RowIndex].Cells["单价"].Value.ToString());

            numVolume.Increment = decimal.Parse(gdvwCodes.Rows[e.RowIndex].Cells["每手数量"].Value.ToString());

            numVolume.Maximum = decimal.Parse(gdvwCodes.Rows[e.RowIndex].Cells["最大量"].Value.ToString());

            switch (gdvwCodes.Rows[e.RowIndex].Cells["交易所"].Value.ToString())
            {
                case "大连":
                    lbExchange.Text = "DCE";
                    qryInstrument.ExchageID = "DCE";
                    break;
                case "郑州":
                    lbExchange.Text = "CZCE";
                    qryInstrument.ExchageID = "CZCE";
                    break;
                case "上海":
                    lbExchange.Text = "SHFE";
                    qryInstrument.ExchageID = "SHFE";
                    break;
                case "中金":
                    lbExchange.Text = "CFFEX";
                    qryInstrument.ExchageID = "CFFEX";
                    break;
                default:
                    break;
            }
            lbInstrumentName.Text = gdvwCodes.Rows[e.RowIndex].Cells["合约名称"].Value.ToString();

            //tradeApi.QueryInstrument(qryInstrument);
        }

        private void 开市自动单设置ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenOrderConfig config = new OpenOrderConfig();
            config.ShowDialog(this);
        }
        #endregion

        #region EventsHandlers
        private void OrderInsertHandler(object sender,RspOrderInsertEventArgs e)
        {
            int index;
            if (this.InvokeRequired && int.TryParse(e.InputOrder.UserOrderLocalID, out index))
            {
                dicOrderLists[index].InputOrder = e.InputOrder;
                dicOrderLists[index].OrderStatus = e.RspInfo.ErrorMsg;
                Action UpdateOrderView = () =>
                  {
                      SetOrderListDataSource();
                  };
                this.Invoke(UpdateOrderView);
            }
        }

        private void ErrRtnOrderHandler(object sender, ErrRtnOrderInsertEventArgs e)
        {
            int index;
            if (this.InvokeRequired && int.TryParse(e.InputOrder.UserOrderLocalID, out index))
            {
                dicOrderLists[index].InputOrder = e.InputOrder;
                dicOrderLists[index].OrderStatus = e.RspInfo.ErrorMsg;
                Action UpdateOrderView = () =>
                {
                    SetOrderListDataSource();
                };
                this.Invoke(UpdateOrderView);
            }
        }

        private void InstrumentStatusHandler(object sender,RtnInstrumentStatusEventArgs e)
        {
            //e.InstrumentStatus.
            ;
        }

        private void OrderViewDbClick(object sender, OrderViewerDbClickEventArgs e)
        {
            CLRCQdpFtdcOrderActionField ordAction = new CLRCQdpFtdcOrderActionField();
            CLRCQdpFtdcInputOrderField ord = dicOrderLists[e.LocalOrderID].InputOrder;
            
            ordAction.ExchangeID = ord.ExchangeID;
            ordAction.OrderSysID = ord.OrderSysID;
            ordAction.BrokerID = ord.BrokerID;
            ordAction.InvestorID = ord.InvestorID;
            ordAction.UserID = ord.UserID;
            ordAction.UserOrderActiconLocalID = TradeApi.RequestID.ToString();
            ordAction.UserOrderLocalID = ord.UserOrderLocalID;
            ordAction.ActionFlag = (char)CLRQDP_FTDC_AF.Delete;

            tradeApi.ReqOrderAction(ordAction);
        }

        private void OrderActionHandler(object sender, RspOrderActionEventArgs e)
        {
            int index;
            if (this.InvokeRequired && int.TryParse(e.OrderAction.UserOrderLocalID, out index))
            {
                dicOrderLists[index].OrderStatus = e.RspInfo.ErrorMsg;
                SetOrderListDataSource();
            }
        }
        #endregion
    }
}
