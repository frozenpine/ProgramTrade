using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ProgramTradeApi;
using CLRQdpApi;
using CLRXspeedApi;

namespace ProgramTrade
{
    public interface IMainView : IDisposable, IMarketView, IPositionView, IOrderView
    {
        event EventHandler ViewLoad;
        event EventHandler ViewShown;
        event EventHandler ViewClosing;

        bool ViewVisable { get; set; }
        string ErrorMsg { set; }


        #region Orders
        event EventHandler SubmitOrder;
        event EventHandler EmbeddedOrder;

        string OrderInstrumentID { get; }
        Direction OrderDirection { get; }
        Operation OrderOperation { get; }
        double OrderPrice { get; set; }
        int OrderVolume { get; set; }
        #endregion
    }
}
