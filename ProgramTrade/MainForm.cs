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
using System.Collections.ObjectModel;

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

        public IEnumerable<PositionDetail> Positions
        {
            set
            {
                Action<IEnumerable<PositionDetail>> set = (source) => { ; };
                if(InvokeRequired)
                {
                    Invoke(set, new object[] { value });
                }
                else
                {
                    set(value);
                }
            }
        }

        public IEnumerable<OrderDetail> Orders
        {
            set
            {
                Action<IEnumerable<OrderDetail>> set = (source) => { ; };
                if (InvokeRequired)
                {
                    Invoke(set, new object[] { value });
                }
                else
                {
                    set(value);
                }
            }
        }

        public string OrderInstrumentID
        {
            get
            {
                return txtInstrumentID.Text;
            }
        }

        public Direction OrderDirection
        {
            get
            {
                if(rdoBuy.Checked)
                {
                    return Direction.Buy;
                }
                else
                {
                    return Direction.Sell;
                }
            }
        }

        public Operation OrderOperation
        {
            get
            {
                if(rdoOpen.Checked)
                {
                    return Operation.Open;
                }
                else
                {
                    return Operation.Close;
                }
            }
        }

        public double OrderPrice
        {
            get
            {
                try
                {
                    return double.Parse(numPrice.Value.ToString());
                }
                catch(Exception)
                {
                    // deal exception
                }
                return 0;
            }
            set
            {
                numPrice.Value = decimal.Parse(value.ToString());
            }
        }

        public int OrderVolume
        {
            get
            {
                try
                {
                    return int.Parse(numVolume.Value.ToString());
                }
                catch(Exception)
                {
                    // deal excetion
                }
                return 0;
            }
            set
            {
                numVolume.Value = value;
            }
        }

        public string ErrorMsg
        {
            set
            {
                Action<string> msg = (s) => { MessageBox.Show(s); };
                if(InvokeRequired)
                {
                    Invoke(msg, new object[] { value });
                }
                else
                {
                    msg(value);
                }
            }
        }

        public IEnumerable<MarketDetail> Markets
        {
            set
            {
                Action<IEnumerable<MarketDetail>> set = (source) => { ; };
                if (InvokeRequired)
                {
                    Invoke(set, new object[] { value });
                }
                else
                {
                    set(value);
                }
            }
        }

        public event EventHandler ViewLoad;
        public event EventHandler MarketViewDoubleClick;
        public event EventHandler ViewClosing;
        public event EventHandler<MouseEventArgs> PositionViewDoubleClick;
        public event EventHandler SubmitOrder;
        public event EventHandler EmbeddedOrder;
        public event EventHandler ViewShown;

        #region Class Functions
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            ViewLoad?.Invoke(sender, e);
        }

        private void btnAddOrderList_Click(object sender, EventArgs e)
        {
            SubmitOrder?.Invoke(this, e);
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

        private void MainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            ViewClosing?.Invoke(sender, e);
        }
        #endregion

        private void dgvwPositions_CellFormatting(object sender, DataGridViewCellFormattingEventArgs e)
        {
            if (e.ColumnIndex == 2)
            {
                /*if (e.Value != null && e.Value.ToString() == "Sell")
                {
                    DataGridViewCellStyle style = e.CellStyle;
                    style.ForeColor = System.Drawing.Color.Green;
                    style.Alignment = DataGridViewContentAlignment.MiddleRight;
                    e.CellStyle = style;
                    e.FormattingApplied = true;
                }*/
            }
        }

        private void dgvwPositions_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            PositionViewDoubleClick?.Invoke(dgvwPositions.SelectedRows, e);
        }

        private void MainForm_Shown(object sender, EventArgs e)
        {
            ViewShown?.Invoke(sender, e);
        }
    }
}
