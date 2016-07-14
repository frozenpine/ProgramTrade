using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ProgramTradeApi;

namespace ProgramTrade
{
    public interface IMarketView
    {
        event EventHandler MarketViewDoubleClick;

        IEnumerable<MarketDetail> Markets { set; }
    }
}
