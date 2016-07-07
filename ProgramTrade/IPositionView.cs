﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ProgramTradeApi;
using System.Collections;
using CLRQdpApi;
using CLRXspeedApi;

namespace ProgramTrade
{
    public interface IPositionView
    {
        event EventHandler PositionViewDoubleClick;

        IEnumerable<PositionDetail> Position { get; set; }
    }
}
