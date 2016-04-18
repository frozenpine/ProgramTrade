using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ProgramTradeModules
{
    public partial class MarketViewer : UserControl
    {
        public MarketViewer()
        {
            InitializeComponent();
        }

        public void ChangViewSide()
        {
            if (DockStyle.Left == panlMarketDetail.Dock)
            {
                panlMarketDetail.Dock = splitter.Dock = DockStyle.Right;
            }
            else
            {
                panlMarketDetail.Dock = splitter.Dock = DockStyle.Left;
            }
        }
    }
}
