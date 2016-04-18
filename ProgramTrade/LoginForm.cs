using CLRQdpApi;
using ProgramTradeApi;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;

namespace ProgramTrade
{
    public partial class LoginForm : Form
    {
        private Dictionary<string, FrontServer> FrontServers = new Dictionary<string, FrontServer>();

        private TradeApi tradeApi;
        private MarketApi marketApi;

        public LoginForm(TradeApi tradeApi, MarketApi marketApi)
        {
            FrontServers.Add(@"QDP-INSIDE", new FrontServer(@"192.168.89.6", @"30005", @"30007" ));
            FrontServers.Add(@"QDP-OUTSIDE", new FrontServer (@"140.206.63.35", @"30005", @"30007" ));
            InitializeComponent();
            this.ActiveControl = btnLogin;
            bsFrontServer.DataSource = FrontServers;
            
            this.tradeApi = tradeApi;
            this.marketApi = marketApi;

            ProgramTradeEvents.AddRspHandler(RspSpiModules.FrontConnected, this.OnFrontServerConnected);
            ProgramTradeEvents.AddRspUserLoginHandler(this.OnRspUserLoginEvent);
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            lbTdFront.Visible = lbMdFront.Visible = false;
            CLRCQdpFtdcReqUserLoginField User = new CLRCQdpFtdcReqUserLoginField();
            User.BrokerID = "guofu";
            User.UserID = txtUserID.Text;
            User.Password = txtPassword.Text;

            if (tradeApi.IsConnected && marketApi.IsConnected)
            {
                tradeApi.UserLogin(User);
                marketApi.UserLogin(User);
            }
            else
            {
                lbTdFront.ForeColor = lbMdFront.ForeColor = Color.Red;
                lbTdFront.Text = "交易前置未连接！";
                lbMdFront.Text = "行情前置未连接！";
            }
        }

        private Action<RspEventArgs, Label> UpdateLoginInfo = (evt, lb) =>
        {
            if (0 == evt.ErrorID)
            {
                lb.Text = string.Format(evt.Message);
                lb.ForeColor = Color.Green;
            }
            else
            {
                lb.Text = string.Format("ErrorMsg：{0}", evt.Message);
                lb.ForeColor = Color.Red;
            }
            lb.Visible = true;
        };

        private void OnFrontServerConnected(object sender,RspEventArgs e)
        {
            if (this.InvokeRequired)
            {
                tmrFrontServer.Stop();
                switch (sender.GetType().Name)
                {
                    case "TradeSpi":
                        lbTdFront.Invoke(UpdateLoginInfo, new object[] { e, lbTdFront });
                        break;
                    case "MarketSpi":
                        lbMdFront.Invoke(UpdateLoginInfo, new object[] { e, lbMdFront });
                        break;
                    default:
                        break;
                }
            }
        }

        private void OnRspUserLoginEvent(object sender, RspUserLoginEventArgs e)
        {
            if (this.InvokeRequired)
            {
                switch(sender.GetType().ToString())
                {
                    case "TradeSpi":
                        lbTdFront.Invoke(UpdateLoginInfo, new object[] { e, lbTdFront });
                        break;
                    case "MarketSpi":
                        lbMdFront.Invoke(UpdateLoginInfo, new object[] { e, lbMdFront });
                        break;
                    default:break;
                }
                if (0==e.RspInfo.ErrorID)
                {
                    tradeApi.UserPwd = marketApi.UserPwd = this.txtPassword.Text;
                    this.DialogResult = DialogResult.OK;
                }
            }
        }

        private void cmbTradeFrontSvr_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmbTradeFrontSvr.SelectedIndex >= 0)
            {
                tradeApi.SubscribeTopics(CLRQDP_TE_RESUME_TYPE.QDP_TERT_QUICK, cmbTradeFrontSvr.SelectedValue as FrontServer);
                marketApi.SubscribeTopics(CLRQDP_TE_RESUME_TYPE.QDP_TERT_QUICK, 100, cmbTradeFrontSvr.SelectedValue as FrontServer);
                tmrFrontServer.Start();
            }
        }

        private void LoginForm_Load(object sender, EventArgs e)
        {
            cmbTradeFrontSvr.SelectedIndex = -1;
        }

        private void cmbTradeFrontSvr_DropDown(object sender, EventArgs e)
        {
            lbTdFront.Visible = lbMdFront.Visible = false;
        }

        private void tmFrontServer_Tick(object sender, EventArgs e)
        {
            tmrFrontServer.Stop();
            lbTdFront.Text = string.Format("交易前置连接超时！");
            lbTdFront.ForeColor = Color.Red;
            lbTdFront.Visible = true;
            lbMdFront.Text = string.Format("行情前置连接超时！");
            lbMdFront.ForeColor = Color.Red;
            lbMdFront.Visible = true;
        }

        private void txtPassword_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode==Keys.C && e.Alt)
            {
                this.DialogResult = DialogResult.OK;
            }
        }
    }
}
