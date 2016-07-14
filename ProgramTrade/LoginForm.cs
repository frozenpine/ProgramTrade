using ProgramTradeApi;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;
using System.Threading;

namespace ProgramTrade
{
    public partial class LoginForm : Form, ILoginView
    {
        public LoginForm()
        {
            InitializeComponent();
            ActiveControl = btnLogin;
        }

        public event EventHandler LoginStart;
        public event EventHandler BrokerSelectionChange;
        public event EventHandler<FormClosingEventArgs> Quit;
        public event EventHandler SaveLoginUser;
        public event EventHandler SaveLoginInfo;
        public event EventHandler FormLoaded;

        Action<TextBox, string> SetLogin = (txtbox, str) =>
            {
                txtbox.Text = str;
            };
        Action<Label, string> SetMsg = (lb, msg) =>
            {
                lb.Text = msg;
                lb.Visible = true;
            };
        Action<Button, Label, bool> SetFrontState = (btn, lb, b) =>
            {
                btn.Enabled = b;
                if (b)
                    lb.ForeColor = Color.Green;
                else
                    lb.ForeColor = Color.Red;
            };
        Action<ComboBox, string> SetBrokerSelection = (cmb, str) =>
           {
               cmb.SelectedItem = str;
           };

        IEnumerable<string> ILoginView.Brokers
        {
            set
            {
                BindingSource bind = new BindingSource();
                bind.DataSource = value;
                cmbTradeFrontSvr.DataSource = bind;
            }
        }

        public string SelectedBroker
        {
            get
            {
                return cmbTradeFrontSvr.SelectedItem.ToString();
            }

            set
            {
                if (InvokeRequired)
                {
                    Invoke(SetBrokerSelection, new object[] { cmbTradeFrontSvr, value });
                }
                else
                    SetBrokerSelection(cmbTradeFrontSvr, value);
            }
        }

        public string Username
        {
            get
            {
                return txtUserID.Text;
            }

            set
            {
                if (InvokeRequired)
                {
                    Invoke(SetLogin, new object[] { txtUserID, value });
                }
                else
                {
                    SetLogin(txtUserID, value);
                }
            }
        }

        public string Password
        {
            get
            {
                return txtPassword.Text;
            }
            set
            {
                if (InvokeRequired)
                {
                    Invoke(SetLogin, new object[] { txtPassword, value });
                }
                else
                {
                    SetLogin(txtPassword, value);
                }
            }
        }

        public string TradeFrontMsg
        {
            set
            {
                if (InvokeRequired)
                {
                    Invoke(SetMsg, new object[] { lbTdFront, value });
                }
                else
                {
                    SetMsg(lbTdFront, value);
                }
            }
        }

        public string MarketFrontMsg
        {
            set
            {
                if (InvokeRequired)
                {
                    Invoke(SetMsg, new object[] { lbMdFront, value });
                }
                else
                {
                    SetMsg(lbMdFront, value);
                }
            }
        }

        public string InvalidMsg
        {
            set
            {

                if (InvokeRequired)
                {
                    Invoke(SetMsg, new object[] { lbValidateMsg, value });
                }
                else
                {
                    SetMsg(lbValidateMsg, value);
                }
            }
        }

        public bool TdFrontConnected
        {
            set
            {
                if (InvokeRequired)
                {
                    Invoke(SetFrontState, new object[] { btnLogin, lbTdFront, value });
                }
                else
                {
                    SetFrontState(btnLogin, lbTdFront, value);
                }
            }
        }

        public bool MdFrontConnected
        {
            set
            {
                if (InvokeRequired)
                {
                    Invoke(SetFrontState, new object[] { btnLogin, lbMdFront, value });
                }
                else
                {
                    SetFrontState(btnLogin, lbMdFront, value);
                }
            }
        }

        public bool UsernameInvalid
        {
            set
            {
                lbValidateMsg.ForeColor = Color.Red;
                lbValidateMsg.Visible = value;
            }
        }

        public bool PasswordInvalid
        {
            set
            {
                lbValidateMsg.ForeColor = Color.Red;
                lbValidateMsg.Visible = value;
            }
        }

        public bool ViewVisible
        {
            set
            {
                if (value)
                {
                    this.ShowDialog();
                }
                else
                {
                    Action closefrm = () => { this.Close(); };
                    if (InvokeRequired)
                    {
                        Invoke(closefrm);
                    }
                    else
                    {
                        closefrm();
                    }
                }
            }
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            LoginStart?.Invoke(sender, e);
        }

        private void cmbTradeFrontSvr_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (cmbTradeFrontSvr.SelectedIndex >= 0)
            {
                SelectedBroker = cmbTradeFrontSvr.SelectedText;
                BrokerSelectionChange?.Invoke(sender, e);
            }
        }

        private void LoginForm_Load(object sender, EventArgs e)
        {
            FormLoaded?.Invoke(sender, e);
            cmbTradeFrontSvr.SelectedIndex = -1;
        }

        private void txtPassword_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode==Keys.C && e.Alt)
            {
                this.DialogResult = DialogResult.OK;
            }
        }

        private void LoginForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            Quit?.Invoke(sender, e);
        }
    }
}
