using ProgramTradeApi;
using CLRQdpApi;
using CLRXspeedApi;
using System;
using System.Collections.Generic;
using System.Data;
using System.Collections;
using System.Diagnostics;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace ProgramTrade
{
    public partial class MainForm : Form, IMainView
    {
        public bool ViewVisable
        {
            get { return this.Visible; }
            set
            {
                if(value)
                {
                    this.Show();
                }
                else
                {
                    this.Close();
                }
            }
        }

        public IEnumerable<PositionDetail> Position
        {
            get
            {
                return positionsBindingSource.Cast<PositionDetail>();
            }
            set
            {
                positionsBindingSource.DataSource = value;
            }
        }

        public event EventHandler ViewLoad;
        public event EventHandler MarketViewDoubleClick;
        public event EventHandler ViewClosing;
        public event EventHandler PositionViewDoubleClick;

        #region Class Functions
        public MainForm()
        {
            InitializeComponent();    }

        /*private void SetInstrumentsDataSource()
        {
            if (File.Exists(@"Instrument.csv"))
            {
                Instruments = File.ReadAllLines(@"Instrument.csv", System.Text.Encoding.Default).ToList();
                gdvwCodes.DataSource = (from l in Instruments.AsParallel().AsOrdered()
                                        let col = l.Split(new[] { ',', ' ' }, StringSplitOptions.None)
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
            else if(Instruments.Count>0)
            {
                gdvwCodes.DataSource = (from l in Instruments.AsParallel().AsOrdered()
                                        let col = l.Split(new[] { ',' }, StringSplitOptions.None)
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
        }*/

        /*private void SetOrderListDataSource()
        {
            odvwOpenOrders.DataSource = dicOrderLists.AsParallel().AsOrdered().Where(i => i.Value.IsOpenOrder).Select(v =>
                new
                {
                    本地报单号 = v.Key,
                    合约号 = v.Value.InstrumentID,
                    买卖 = Enum.Parse(typeof(CLRQDP_FTDC_D), v.Value.Direction.ToString()),
                    开平 = Enum.Parse(typeof(CLRQDP_FTDC_OF), v.Value.OffsetFlag.ToString()),
                    价格 = v.Value.LimitPrice,
                    数量 = v.Value.Volume,
                    订单状态 = v.Value.OrderStatus
                }).ToArray();
            odvwAllOrders.DataSource = dicOrderLists.AsParallel().AsOrdered().Select(v =>
                new
                {
                    本地报单号 = v.Key,
                    合约号 = v.Value.InstrumentID,
                    买卖 = Enum.Parse(typeof(CLRQDP_FTDC_D), v.Value.Direction.ToString()),
                    开平 = Enum.Parse(typeof(CLRQDP_FTDC_OF), v.Value.OffsetFlag.ToString()),
                    价格 = v.Value.LimitPrice,
                    数量 = v.Value.Volume,
                    订单状态 = v.Value.OrderStatus
                }).ToArray();
        }*/

        private void MainForm_Load(object sender, EventArgs e)
        {
            ViewLoad?.Invoke(sender, e);
        }

        private void btnAddOrderList_Click(object sender, EventArgs e)
        {
            //CLRCQdpFtdcInputOrderField inputOrder = new CLRCQdpFtdcInputOrderField();
            //int requestID = QTradeApi.RequestID;

            //inputOrder.BrokerID = tradeApi.BrokerID;
            //inputOrder.ExchangeID = lbExchange.Text/*"CZCE"*/;
            //inputOrder.InvestorID = tradeApi.InvestorID;
            //inputOrder.UserID = tradeApi.UserID;
            //inputOrder.InstrumentID = txtInstrumentID.Text/*"WH507"*/;
            /*inputOrder.UserOrderLocalID = requestID.ToString();
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

            OrderItem list = new OrderItem(inputOrder, ((sender as Button).Name == "btnAddOpenOrder"), "等待开市报单");
            dicOrderLists.Add(requestID, list);

            if((sender as Button).Name == "btnAddOpenOrder")
            {
                tabOrders.SelectedTab = tabOrders.TabPages["tabPageOpenOrders"];
            }
            else
            {
                tabOrders.SelectedTab = tabOrders.TabPages["tabPageAllOrders"];
            }

            SetOrderListDataSource();*/
        }

        private void 切换显示ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (tabExchange.SelectedTab.HasChildren)
            {
                /*MarketViewer view = tabExchange.SelectedTab.Controls[0] as MarketViewer;
                if (null != view)
                {
                    view.ChangViewSide();
                }*/
            }
        }

        /*private void btnParellel_Click(object sender, EventArgs e)
        {
            Parallel.ForEach(dicOrderLists.Values, item =>
             {
#if DEBUG
                Debug.WriteLine("Current ThreadID：{0},Thread Called by MainForm->btnParellel_Click\r\nCurrent OrderID：{1}", Thread.CurrentThread.ManagedThreadId,item.UserOrderLocalID);
#endif
                 //tradeApi.SubmitOrder(item.GetInputOrder());
            });
        }*/

        /*private void gdvwCodes_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
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
        }*/

        /*private void 开市自动单设置ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenOrderConfig config = new OpenOrderConfig();
            config.ShowDialog(this);
        }*/

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            ViewClosing?.Invoke(sender, e);
        }
        #endregion
    }
}
