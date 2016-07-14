using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ProgramTradeApi;

namespace ProgramTrade
{
    public interface IOrderView
    {
        IEnumerable<OrderDetail> Orders { set; }
    }
}
