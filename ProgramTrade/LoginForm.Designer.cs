using ProgramTradeApi;

namespace ProgramTrade
{
    partial class LoginForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                ProgramTradeEvents.RemoveRspHandler(RspSpiModules.FrontConnected, this.OnFrontServerConnected);
                ProgramTradeEvents.RemoveRspUserLoginHander(this.OnRspUserLoginEvent);
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.picBanner = new System.Windows.Forms.PictureBox();
            this.panlFooter = new System.Windows.Forms.Panel();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.lbSplliter = new System.Windows.Forms.Label();
            this.btnQuit = new System.Windows.Forms.Button();
            this.btnComConfig = new System.Windows.Forms.Button();
            this.btnLogin = new System.Windows.Forms.Button();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.lbFrontServer = new System.Windows.Forms.Label();
            this.lbClientID = new System.Windows.Forms.Label();
            this.lbPassword = new System.Windows.Forms.Label();
            this.cmbTradeFrontSvr = new System.Windows.Forms.ComboBox();
            this.bsFrontServer = new System.Windows.Forms.BindingSource(this.components);
            this.txtUserID = new System.Windows.Forms.TextBox();
            this.txtPassword = new System.Windows.Forms.TextBox();
            this.chkSaveUserID = new System.Windows.Forms.CheckBox();
            this.btnSpeedTest = new System.Windows.Forms.Button();
            this.tbFrontSvrInfo = new System.Windows.Forms.TableLayoutPanel();
            this.lbTdFront = new System.Windows.Forms.Label();
            this.lbMdFront = new System.Windows.Forms.Label();
            this.tmrFrontServer = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.picBanner)).BeginInit();
            this.panlFooter.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.bsFrontServer)).BeginInit();
            this.tbFrontSvrInfo.SuspendLayout();
            this.SuspendLayout();
            // 
            // picBanner
            // 
            this.picBanner.Dock = System.Windows.Forms.DockStyle.Top;
            this.picBanner.Location = new System.Drawing.Point(0, 0);
            this.picBanner.Name = "picBanner";
            this.picBanner.Size = new System.Drawing.Size(387, 66);
            this.picBanner.TabIndex = 0;
            this.picBanner.TabStop = false;
            // 
            // panlFooter
            // 
            this.panlFooter.AutoSize = true;
            this.panlFooter.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panlFooter.Controls.Add(this.tableLayoutPanel1);
            this.panlFooter.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panlFooter.Location = new System.Drawing.Point(0, 169);
            this.panlFooter.Name = "panlFooter";
            this.panlFooter.Size = new System.Drawing.Size(387, 38);
            this.panlFooter.TabIndex = 1;
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 3;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.lbSplliter, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.btnQuit, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.btnComConfig, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.btnLogin, 0, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.Size = new System.Drawing.Size(387, 38);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // lbSplliter
            // 
            this.lbSplliter.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.lbSplliter.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.tableLayoutPanel1.SetColumnSpan(this.lbSplliter, 3);
            this.lbSplliter.Location = new System.Drawing.Point(20, 0);
            this.lbSplliter.Margin = new System.Windows.Forms.Padding(20, 0, 20, 0);
            this.lbSplliter.Name = "lbSplliter";
            this.lbSplliter.Size = new System.Drawing.Size(347, 2);
            this.lbSplliter.TabIndex = 0;
            // 
            // btnQuit
            // 
            this.btnQuit.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.btnQuit.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnQuit.Location = new System.Drawing.Point(245, 8);
            this.btnQuit.Name = "btnQuit";
            this.btnQuit.Size = new System.Drawing.Size(92, 23);
            this.btnQuit.TabIndex = 0;
            this.btnQuit.Text = "退出";
            this.btnQuit.UseVisualStyleBackColor = true;
            // 
            // btnComConfig
            // 
            this.btnComConfig.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btnComConfig.Location = new System.Drawing.Point(147, 8);
            this.btnComConfig.Name = "btnComConfig";
            this.btnComConfig.Size = new System.Drawing.Size(92, 23);
            this.btnComConfig.TabIndex = 0;
            this.btnComConfig.Text = "通讯设置";
            this.btnComConfig.UseVisualStyleBackColor = true;
            // 
            // btnLogin
            // 
            this.btnLogin.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.btnLogin.Location = new System.Drawing.Point(49, 8);
            this.btnLogin.Name = "btnLogin";
            this.btnLogin.Size = new System.Drawing.Size(92, 23);
            this.btnLogin.TabIndex = 0;
            this.btnLogin.Text = "登录";
            this.btnLogin.UseVisualStyleBackColor = true;
            this.btnLogin.Click += new System.EventHandler(this.btnLogin_Click);
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.AutoSize = true;
            this.tableLayoutPanel2.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.tableLayoutPanel2.ColumnCount = 3;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 160F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel2.Controls.Add(this.lbFrontServer, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.lbClientID, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.lbPassword, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.cmbTradeFrontSvr, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.txtUserID, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.txtPassword, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.chkSaveUserID, 2, 1);
            this.tableLayoutPanel2.Controls.Add(this.btnSpeedTest, 2, 0);
            this.tableLayoutPanel2.Controls.Add(this.tbFrontSvrInfo, 0, 3);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(0, 66);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 4;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(387, 102);
            this.tableLayoutPanel2.TabIndex = 2;
            // 
            // lbFrontServer
            // 
            this.lbFrontServer.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lbFrontServer.AutoSize = true;
            this.lbFrontServer.Location = new System.Drawing.Point(33, 8);
            this.lbFrontServer.Name = "lbFrontServer";
            this.lbFrontServer.Size = new System.Drawing.Size(77, 12);
            this.lbFrontServer.TabIndex = 0;
            this.lbFrontServer.Text = "选择接入地址";
            this.lbFrontServer.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lbClientID
            // 
            this.lbClientID.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lbClientID.AutoSize = true;
            this.lbClientID.Location = new System.Drawing.Point(69, 35);
            this.lbClientID.Name = "lbClientID";
            this.lbClientID.Size = new System.Drawing.Size(41, 12);
            this.lbClientID.TabIndex = 0;
            this.lbClientID.Text = "客户号";
            this.lbClientID.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // lbPassword
            // 
            this.lbPassword.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lbPassword.AutoSize = true;
            this.lbPassword.Location = new System.Drawing.Point(57, 62);
            this.lbPassword.Name = "lbPassword";
            this.lbPassword.Size = new System.Drawing.Size(53, 12);
            this.lbPassword.TabIndex = 0;
            this.lbPassword.Text = "登录密码";
            this.lbPassword.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // cmbTradeFrontSvr
            // 
            this.cmbTradeFrontSvr.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.cmbTradeFrontSvr.DataSource = this.bsFrontServer;
            this.cmbTradeFrontSvr.DisplayMember = "Key";
            this.cmbTradeFrontSvr.FormattingEnabled = true;
            this.cmbTradeFrontSvr.Location = new System.Drawing.Point(116, 4);
            this.cmbTradeFrontSvr.Name = "cmbTradeFrontSvr";
            this.cmbTradeFrontSvr.Size = new System.Drawing.Size(154, 20);
            this.cmbTradeFrontSvr.TabIndex = 1;
            this.cmbTradeFrontSvr.ValueMember = "Value";
            this.cmbTradeFrontSvr.DropDown += new System.EventHandler(this.cmbTradeFrontSvr_DropDown);
            this.cmbTradeFrontSvr.SelectedIndexChanged += new System.EventHandler(this.cmbTradeFrontSvr_SelectedIndexChanged);
            // 
            // txtUserID
            // 
            this.txtUserID.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.txtUserID.Location = new System.Drawing.Point(116, 31);
            this.txtUserID.Name = "txtUserID";
            this.txtUserID.Size = new System.Drawing.Size(154, 21);
            this.txtUserID.TabIndex = 2;
            // 
            // txtPassword
            // 
            this.txtPassword.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.txtPassword.Location = new System.Drawing.Point(116, 58);
            this.txtPassword.Name = "txtPassword";
            this.txtPassword.Size = new System.Drawing.Size(154, 21);
            this.txtPassword.TabIndex = 3;
            this.txtPassword.UseSystemPasswordChar = true;
            this.txtPassword.KeyDown += new System.Windows.Forms.KeyEventHandler(this.txtPassword_KeyDown);
            // 
            // chkSaveUserID
            // 
            this.chkSaveUserID.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.chkSaveUserID.AutoSize = true;
            this.chkSaveUserID.Location = new System.Drawing.Point(276, 33);
            this.chkSaveUserID.Name = "chkSaveUserID";
            this.chkSaveUserID.Size = new System.Drawing.Size(72, 16);
            this.chkSaveUserID.TabIndex = 0;
            this.chkSaveUserID.Text = "保存账号";
            this.chkSaveUserID.UseVisualStyleBackColor = true;
            // 
            // btnSpeedTest
            // 
            this.btnSpeedTest.AutoSize = true;
            this.btnSpeedTest.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.btnSpeedTest.FlatAppearance.BorderSize = 0;
            this.btnSpeedTest.Location = new System.Drawing.Point(276, 3);
            this.btnSpeedTest.Name = "btnSpeedTest";
            this.btnSpeedTest.Size = new System.Drawing.Size(39, 22);
            this.btnSpeedTest.TabIndex = 4;
            this.btnSpeedTest.Text = "测速";
            this.btnSpeedTest.UseVisualStyleBackColor = true;
            // 
            // tbFrontSvrInfo
            // 
            this.tbFrontSvrInfo.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.tbFrontSvrInfo.ColumnCount = 2;
            this.tableLayoutPanel2.SetColumnSpan(this.tbFrontSvrInfo, 3);
            this.tbFrontSvrInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tbFrontSvrInfo.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tbFrontSvrInfo.Controls.Add(this.lbTdFront, 0, 0);
            this.tbFrontSvrInfo.Controls.Add(this.lbMdFront, 1, 0);
            this.tbFrontSvrInfo.Location = new System.Drawing.Point(3, 85);
            this.tbFrontSvrInfo.Name = "tbFrontSvrInfo";
            this.tbFrontSvrInfo.Padding = new System.Windows.Forms.Padding(10, 0, 10, 0);
            this.tbFrontSvrInfo.RowCount = 1;
            this.tbFrontSvrInfo.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tbFrontSvrInfo.Size = new System.Drawing.Size(381, 14);
            this.tbFrontSvrInfo.TabIndex = 5;
            // 
            // lbTdFront
            // 
            this.lbTdFront.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.lbTdFront.AutoSize = true;
            this.lbTdFront.Location = new System.Drawing.Point(13, 1);
            this.lbTdFront.Name = "lbTdFront";
            this.lbTdFront.Size = new System.Drawing.Size(174, 12);
            this.lbTdFront.TabIndex = 0;
            this.lbTdFront.Text = "lbTdFront";
            this.lbTdFront.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lbTdFront.Visible = false;
            // 
            // lbMdFront
            // 
            this.lbMdFront.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.lbMdFront.AutoSize = true;
            this.lbMdFront.Location = new System.Drawing.Point(193, 1);
            this.lbMdFront.Name = "lbMdFront";
            this.lbMdFront.Size = new System.Drawing.Size(175, 12);
            this.lbMdFront.TabIndex = 0;
            this.lbMdFront.Text = "lbMdFront";
            this.lbMdFront.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lbMdFront.Visible = false;
            // 
            // tmrFrontServer
            // 
            this.tmrFrontServer.Interval = 5000;
            this.tmrFrontServer.Tick += new System.EventHandler(this.tmFrontServer_Tick);
            // 
            // LoginForm
            // 
            this.AcceptButton = this.btnLogin;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.btnQuit;
            this.ClientSize = new System.Drawing.Size(387, 207);
            this.Controls.Add(this.tableLayoutPanel2);
            this.Controls.Add(this.panlFooter);
            this.Controls.Add(this.picBanner);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "LoginForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "用户登录";
            this.TopMost = true;
            this.Load += new System.EventHandler(this.LoginForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.picBanner)).EndInit();
            this.panlFooter.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.bsFrontServer)).EndInit();
            this.tbFrontSvrInfo.ResumeLayout(false);
            this.tbFrontSvrInfo.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox picBanner;
        private System.Windows.Forms.Panel panlFooter;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label lbSplliter;
        private System.Windows.Forms.Button btnQuit;
        private System.Windows.Forms.Button btnComConfig;
        private System.Windows.Forms.Button btnLogin;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label lbFrontServer;
        private System.Windows.Forms.Label lbClientID;
        private System.Windows.Forms.Label lbPassword;
        private System.Windows.Forms.ComboBox cmbTradeFrontSvr;
        private System.Windows.Forms.TextBox txtUserID;
        private System.Windows.Forms.TextBox txtPassword;
        private System.Windows.Forms.CheckBox chkSaveUserID;
        private System.Windows.Forms.Button btnSpeedTest;
        private System.Windows.Forms.BindingSource bsFrontServer;
        private System.Windows.Forms.Timer tmrFrontServer;
        private System.Windows.Forms.TableLayoutPanel tbFrontSvrInfo;
        private System.Windows.Forms.Label lbTdFront;
        private System.Windows.Forms.Label lbMdFront;
    }
}