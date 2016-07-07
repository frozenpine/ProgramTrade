using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ProgramTradeApi
{
    public interface IMarketApi:IDisposable
    {
        bool IsConnected { get; }

        void Release();
    }
}
