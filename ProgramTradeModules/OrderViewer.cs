using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;
using System.Threading;
using System.Threading.Tasks;
using System.Diagnostics;
using CLRQdpApi;

namespace ProgramTradeModules
{

    public partial class OrderViewer : UserControl
    {
        public EventHandler<OrderViewerDbClickEventArgs> OrderViewerDbClickHandler;

        public object DataSource
        {
            get { return gdvwOrders.DataSource; }
            set { gdvwOrders.DataSource = value; }
        }

        public OrderViewer()
        {
            InitializeComponent();
        }

        private void OrderViewer_BackColorChanged(object sender, EventArgs e)
        {
            gdvwOrders.BackgroundColor = this.BackColor;
        }

        private void gdvwOrders_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            OrderViewerDbClickHandler(this, new OrderViewerDbClickEventArgs(gdvwOrders.Rows[e.RowIndex].Cells["本地报单号"].Value.ToString()));
        }
    }

    public class OrderViewerDbClickEventArgs : EventArgs
    {
        public int LocalOrderID { get; private set; }
        public OrderViewerDbClickEventArgs(string id)
        {
            LocalOrderID = int.Parse(id);
        }
    }

    public class OrderList
    {
        public CLRCQdpFtdcInputOrderField InputOrder { get; set; }
        public bool IsOpenOrder { get; set; }
        public string OrderStatus { get; set; }
    }

    public class OrderBindingSource : BindingSource
    {
        public new object DataSource
        {
            get { return base.DataSource; }
            set
            {
                Action<object> AddFields = (object item) =>
                  {
                      var names = from f in item.GetType().GetFields() select f.Name;
                      foreach(var name in names)
                      {
                          base.Add(name);
                      }
                  };
                AddFields(value);
            }
        }
    }
}
