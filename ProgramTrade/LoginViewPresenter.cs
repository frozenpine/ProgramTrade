using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ProgramTradeApi;
using System.Diagnostics;
using System.Threading;
using System.Net.Sockets;

namespace ProgramTrade
{
    class LoginViewPresenter : IDisposable
    {
        public ILoginView LoginView { get; private set; }
        public ITraderModel Trader { get; private set; }

        public LoginViewPresenter(ILoginView loginFrm,ITraderModel trader)
        {
            LoginView = loginFrm;
            Trader = trader;

            LoginView.LoginStart += LoginView_LoginStart;
            LoginView.BrokerSelectionChange += LoginView_BrokerSelectionChange;

            LoginView.Brokers = Trader.Brokers.Keys;
            LoginView.TdFrontConnected = false;
            LoginView.MdFrontConnected = false;
            LoginView.TradeFrontMsg = "请选择接入商";
            LoginView.MarketFrontMsg = "请选择接入商";

            Trader.eventFrontConnected += Trader_FrontConnected;
            Trader.eventUserLogined += Trader_UserLogined;
        }

        private void Trader_UserLogined(object sender, RspEventArgs e)
        {
            switch (sender.ToString())
            { 
                case "ProgramTradeApi.XTradeSpi":
                    if (e.ErrorID == 0)
                    {
                        LoginView.ViewVisible = false;
                    }
                    else
                    {
                        LoginView.InvalidMsg = "交易前置：" + e.Message;
                    }
                    break;
                case "ProgramTradeApi.XMduserSpi":
                    if (e.ErrorID == 0)
                    {
                        
                    }
                    else
                    {
                        LoginView.InvalidMsg = "行情前置：" + e.Message;
                    }
                    break;
            }
        }

        private void Trader_FrontConnected(object sender, RspEventArgs e)
        {
            switch (sender.ToString())
            {
                case "ProgramTradeApi.XTradeSpi":
                    if (e.ErrorID == 0)
                    {
                        LoginView.TdFrontConnected = true;
                        LoginView.Username = "000200001740";
                        LoginView.Password = "123";
                    }
                    else
                    {
                        LoginView.TdFrontConnected = false;
                    }
                    LoginView.TradeFrontMsg = e.Message;
                    break;
                case "ProgramTradeApi.XMduserSpi":
                    if (e.ErrorID == 0)
                    {
                        LoginView.MdFrontConnected = true;
                        //LoginView.Username = "000200001740";
                        //LoginView.Password = "123";
                    }
                    else
                    {
                        LoginView.MdFrontConnected = false;
                    }
                    LoginView.MarketFrontMsg = e.Message;
                    break;
            }
        }

        private void LoginView_BrokerSelectionChange(object sender, EventArgs e)
        {
            LoginView.Username = LoginView.Password = "";
            Trader.Brokers.SelectBroker = LoginView.SelectedBroker;
            Action trade = () =>
            {
                if (Trader.Brokers.Current[ServerType.TradeFrontSvr].Count > 0)
                {
                    try
                    {
                        LoginView.TradeFrontMsg = "正在连接交易前置";
                        LoginView.TdFrontConnected = false;
                        Trader.CreateTradeApi(Trader.Brokers.Current.BrokerType);
                        try
                        {
                            Trader.TradeApi.Init(new Initiator(Trader.Brokers.SelectTradeFront));
                        }
                        catch (SocketException err)
                        {
                            LoginView.TradeFrontMsg = "交易前置连接超时";
                            LoginView.TdFrontConnected = false;
                        }
                    }
                    catch (NotImplementedException err)
                    {
                        LoginView.TradeFrontMsg = Trader.Brokers.Current.BrokerType.ToString() + "接口未实现";
                        LoginView.TdFrontConnected = false;
                    }
                }
                else
                {
                    LoginView.TradeFrontMsg = "无交易前置服务器";
                    LoginView.TdFrontConnected = false;
                }
            };
            Action market = () =>
            {
                if (Trader.Brokers.Current[ServerType.MarketFrontSvr].Count > 0)
                {
                    try
                    {
                        LoginView.MarketFrontMsg = "正在连接行情前置";
                        LoginView.MdFrontConnected = false;
                        Trader.CreateMarketApi(Trader.Brokers.Current.BrokerType);
                        try
                        {
                            Trader.MarketApi.Init(new Initiator(Trader.Brokers.SelectMarketFront));
                        }
                        catch (SocketException err)
                        {
                            LoginView.MarketFrontMsg = "行情前置连接超时";
                            LoginView.MdFrontConnected = false;
                        }
                    }
                    catch(SocketException err)
                    {
                        LoginView.MarketFrontMsg = Trader.Brokers.Current.BrokerType.ToString() + "接口未实现";
                        LoginView.MdFrontConnected = false;
                    }
                }
                else
                {
                    LoginView.MarketFrontMsg = "无行情前置服务器";
                    LoginView.MdFrontConnected = false;
                }
            };
            ThreadStart tr1 = new ThreadStart(trade);
            ThreadStart tr2 = new ThreadStart(market);
            Thread trtrade = new Thread(tr1);
            Thread trmarket = new Thread(tr2);
            trtrade.IsBackground = true;
            trmarket.IsBackground = true;
            trtrade.Start();
            trmarket.Start();
        }

        private void LoginView_LoginStart(object sender, EventArgs e)
        {
            if (LoginView.Username == "")
            {
                LoginView.InvalidMsg = "请输入用户名！";
                LoginView.UsernameInvalid = true;
            }
            else if (LoginView.Password == "")
            {
                LoginView.InvalidMsg = "请输入密码！";
                LoginView.PasswordInvalid = true;
            }
            else
            {
                LoginView.UsernameInvalid = LoginView.PasswordInvalid = false;
                if (Trader.IsTradeConnected)
                {
                    Trader.TradeApi.RequestUserLogin(LoginView.Username, LoginView.Password);
                }
                if(Trader.IsMarketConnected)
                {
                    Trader.MarketApi.RequestUserLogin(LoginView.Username, LoginView.Password);
                }
            }
        }

        public void Dispose()
        {
            LoginView.LoginStart -= LoginView_LoginStart;
            LoginView.BrokerSelectionChange -= LoginView_BrokerSelectionChange;

            Trader.eventFrontConnected -= Trader_FrontConnected;
            Trader.eventUserLogined -= Trader_UserLogined;

            LoginView.Dispose();
        }
    }
}
