using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ProgramTradeApi;
using System.Threading;

namespace ProgramTrade
{
    class MainViewPresenter : IDisposable
    {
        public IMainView MainView { get; private set; }
        public ITraderModel Trader { get; private set; }

        public MainViewPresenter(IMainView mainFrm, ITraderModel trader)
        {
            MainView = mainFrm;
            Trader = trader;

            #region View Event
            MainView.ViewLoad += MainForm_FormLoad;
            MainView.SubmitOrder += MainView_SubmitOrder;
            MainView.PositionViewDoubleClick += MainView_PositionViewDoubleClick;
            #endregion

            #region Model Event
            Trader.eventPositionChanged += Trader_eventPositionChanged;
            Trader.eventOrderChanged += Trader_eventOrderChanged;
            #endregion
        }

        private void Trader_eventMarketChanged(object sender, EventArgs e)
        {
            MainView.Markets = Trader.Markets.Values.AsParallel().OrderBy(v => v.InstrumentID);
        }

        Func<Direction, Direction> ReverseDirection = (d) =>
        {
            if (d == Direction.Buy) return Direction.Sell;
            else return Direction.Buy;
        };

        private void MainView_PositionViewDoubleClick(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            System.Windows.Forms.DataGridViewRow row = (sender as System.Windows.Forms.DataGridViewSelectedRowCollection)[0];
            if (row != null)
            {
                //MainView.ErrorMsg = "Mouse position : " + e.Location.ToString() + "\r\n" + row.Cells["instrumentIDDataGridViewTextBoxColumn3"].ToString() + "\r\n" + "平仓方向：" + row.Cells["instrumentIDDataGridViewTextBoxColumn3"].Value + " " + ReverseDirection((Direction)row.Cells["directionDataGridViewTextBoxColumn2"].Value).ToString();
            }
        }

        private void MainView_SubmitOrder(object sender, EventArgs e)
        {
            if(ValidateOrder())
            {
                ;
            }
        }

        private bool ValidateOrder()
        {
            if(MainView.OrderInstrumentID == "" || MainView.OrderPrice <= 0 || MainView.OrderVolume <= 0)
            {
                MainView.ErrorMsg = "委托信息不完整！";
                return false;
            }
            else
            {
                switch(MainView.OrderOperation)
                {
                    case Operation.Open:
                        return false;
                    case Operation.Close:
                        if (Trader.Positions.ContainsKey(MainView.OrderInstrumentID + ReverseDirection(MainView.OrderDirection)))
                        {
                            if(MainView.OrderVolume > Trader.Positions[MainView.OrderInstrumentID + ReverseDirection(MainView.OrderDirection)].VolumeAll)
                            {
                                MainView.ErrorMsg = "可平手数不足！";
                                MainView.OrderVolume = Trader.Positions[MainView.OrderInstrumentID + ReverseDirection(MainView.OrderDirection)].VolumeAll;
                                return false;
                            }
                            return true;
                        }
                        else
                        {
                            MainView.ErrorMsg = "无可平仓位！";
                            return false;
                        }
                    case Operation.CloseToday:
                        if (Trader.Positions.ContainsKey(MainView.OrderInstrumentID + ReverseDirection(MainView.OrderDirection)))
                        {
                            if (MainView.OrderVolume > Trader.Positions[MainView.OrderInstrumentID + ReverseDirection(MainView.OrderDirection)].VolumeToday)
                            {
                                MainView.ErrorMsg = "可平手数不足！";
                                MainView.OrderVolume = Trader.Positions[MainView.OrderInstrumentID + ReverseDirection(MainView.OrderDirection)].VolumeToday;
                                return false;
                            }
                            return true;
                        }
                        else
                        {
                            MainView.ErrorMsg = "无可平仓位！";
                            return false;
                        }
                }
                return false;
            }
        }

        private void Trader_eventOrderChanged(object sender, EventArgs e)
        {
            //MainView.Orders = Trader.Orders.Values.AsParallel().OrderByDescending(v => v.OrderSysID);
        }

        private void Trader_eventPositionChanged(object sender, EventArgs e)
        {
            //MainView.Positions = Trader.Positions.Values.AsParallel().OrderBy(v => v.InstrumentID);
            //MainView.PositionCollection.Add(sender as PositionDetail);
        }

        private void MainForm_FormLoad(object sender, EventArgs e)
        {
            LoginViewPresenter login = new LoginViewPresenter(new LoginForm(), Trader);
            login.LoginView.ViewVisible = true;
            if (Trader.ITradeApi == null || !Trader.IsTradeLogined)
            {
                MainView.ViewVisable = false;
            }
            else
            {
                //MainView.Markets = Trader.Markets.Values.AsParallel().OrderBy(v => v.InstrumentID);
                //MainView.MarketDatasource = Trader.Markets.Values.AsParallel().OrderBy(v => v.InstrumentID).ToList();
                //System.ComponentModel.BindingList<MarketDetail> bind = new System.ComponentModel.BindingList<MarketDetail>(Trader.Markets.Values.AsParallel().OrderBy(v => v.InstrumentID).ToList());
                //MainView.MarketDatasource = bind;
                //MainView.PositionDataSource = PositionDetailList;
                //MainView.PositionCollection = new System.Collections.ObjectModel.ObservableCollection<PositionDetail>();
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
            Trader.eventOrderChanged -= Trader_eventOrderChanged;
            #endregion
        }
    }
}
