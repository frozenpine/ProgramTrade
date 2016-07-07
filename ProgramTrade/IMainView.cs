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
        bool ViewVisable { get; set; }

        event EventHandler ViewLoad;
        event EventHandler ViewClosing;
    }
}
