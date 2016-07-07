using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ProgramTradeApi;

namespace ProgramTrade
{
    class MainViewPresenter : IDisposable
    {
        public IMainView MainView { get; private set; }
        public ITraderModel Trader { get; private set; }


        public MainViewPresenter(IMainView mainFrm,ITraderModel trader)
        {
            MainView = mainFrm;
            Trader = trader;

            #region View Event
            MainView.ViewLoad += MainForm_FormLoad;
            #endregion

            #region Model Event
            Trader.eventPositionChanged += Trader_eventPositionChanged;
            #endregion
        }

        private void Trader_eventPositionChanged(object sender, EventArgs e)
        {
            if (MainView.Position.Count() == 0)
            {
                MainView.Position = Trader.Positions.Values;
            }
        }

        private void MainForm_FormLoad(object sender, EventArgs e)
        {
            LoginViewPresenter login = new LoginViewPresenter(new LoginForm(), Trader);
            login.LoginView.ViewVisible = true;
            if (Trader.TradeApi == null || !Trader.IsTradeLogined)
            {
                MainView.ViewVisable = false;
            }
            else
            {
                Trader.TradeApi.RequestUserPosition();
                Trader.TradeApi.RequestQueryOrders();
            }
        }

        public void Dispose()
        {
            #region View Event
            MainView.ViewLoad -= MainForm_FormLoad;
            #endregion
            MainView.Dispose();

            #region Model Event
            Trader.eventPositionChanged -= Trader_eventPositionChanged;
            #endregion
        }
    }
}
