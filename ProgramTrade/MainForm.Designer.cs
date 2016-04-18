using ProgramTradeApi;

namespace ProgramTrade
{
    partial class MainForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                ProgramTradeEvents.RemoveRspOrderInsertHandler(OrderInsertHandler);
#if DEBUG
                t.Flush();
#endif
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.splitMain = new System.Windows.Forms.SplitContainer();
            this.tabExchange = new System.Windows.Forms.TabControl();
            this.contmenuTabExchange = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.切换显示ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabPageDCE = new System.Windows.Forms.TabPage();
            this.mdvwDCE = new ProgramTradeModules.MarketViewer();
            this.tabPageSHFE = new System.Windows.Forms.TabPage();
            this.mdvwSHFE = new ProgramTradeModules.MarketViewer();
            this.tabPageCFFE = new System.Windows.Forms.TabPage();
            this.mdvwCFFE = new ProgramTradeModules.MarketViewer();
            this.tabPageZCE = new System.Windows.Forms.TabPage();
            this.mdvwZCE = new ProgramTradeModules.MarketViewer();
            this.tabUserDefine = new System.Windows.Forms.TabPage();
            this.mdvwCustom = new ProgramTradeModules.MarketViewer();
            this.tbpanlOrderInfo = new System.Windows.Forms.TableLayoutPanel();
            this.tabOrders = new System.Windows.Forms.TabControl();
            this.tabPageOpenOrders = new System.Windows.Forms.TabPage();
            this.odvwOpenOrders = new ProgramTradeModules.OrderViewer();
            this.tabPageAllOrders = new System.Windows.Forms.TabPage();
            this.odvwAllOrders = new ProgramTradeModules.OrderViewer();
            this.tabPageHisOrders = new System.Windows.Forms.TabPage();
            this.odvwHisOrders = new ProgramTradeModules.OrderViewer();
            this.tabPageCodes = new System.Windows.Forms.TabPage();
            this.gdvwCodes = new System.Windows.Forms.DataGridView();
            this.flpnelInfo = new System.Windows.Forms.FlowLayoutPanel();
            this.lbAccountInfo = new System.Windows.Forms.Label();
            this.lbRightText = new System.Windows.Forms.Label();
            this.lbRight = new System.Windows.Forms.Label();
            this.lbAvailableText = new System.Windows.Forms.Label();
            this.lbAvailable = new System.Windows.Forms.Label();
            this.flpanlOrder = new System.Windows.Forms.FlowLayoutPanel();
            this.tbpanlOrder = new System.Windows.Forms.TableLayoutPanel();
            this.lbInstrument = new System.Windows.Forms.Label();
            this.lbDirection = new System.Windows.Forms.Label();
            this.lbAction = new System.Windows.Forms.Label();
            this.lbPrice = new System.Windows.Forms.Label();
            this.lbVolume = new System.Windows.Forms.Label();
            this.txtInstrumentID = new System.Windows.Forms.TextBox();
            this.numPrice = new System.Windows.Forms.NumericUpDown();
            this.numVolume = new System.Windows.Forms.NumericUpDown();
            this.tbpanlOpenClose = new System.Windows.Forms.TableLayoutPanel();
            this.rdoOpen = new System.Windows.Forms.RadioButton();
            this.rdoClose = new System.Windows.Forms.RadioButton();
            this.tbpanlBuySell = new System.Windows.Forms.TableLayoutPanel();
            this.rdoBuy = new System.Windows.Forms.RadioButton();
            this.rdoSell = new System.Windows.Forms.RadioButton();
            this.tbInstrumentInfo = new System.Windows.Forms.TableLayoutPanel();
            this.lbInstrumentName = new System.Windows.Forms.Label();
            this.lbExchange = new System.Windows.Forms.Label();
            this.tbpanlSubOrder = new System.Windows.Forms.TableLayoutPanel();
            this.btnAddOpenOrder = new System.Windows.Forms.Button();
            this.btnAddOrder = new System.Windows.Forms.Button();
            this.tbpanlInstrumentInfo = new System.Windows.Forms.TableLayoutPanel();
            this.lbBuyPrice = new System.Windows.Forms.Label();
            this.lbSellPrice = new System.Windows.Forms.Label();
            this.lbSellVolume = new System.Windows.Forms.Label();
            this.lbBuyVolume = new System.Windows.Forms.Label();
            this.lbTop = new System.Windows.Forms.Label();
            this.lbBottom = new System.Windows.Forms.Label();
            this.lbOpen = new System.Windows.Forms.Label();
            this.lbClose = new System.Windows.Forms.Label();
            this.btnParellel = new System.Windows.Forms.Button();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.strplbTradeFrontSvr = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripSplitButton1 = new System.Windows.Forms.ToolStripSplitButton();
            this.striplbMarketFrontSvr = new System.Windows.Forms.ToolStripStatusLabel();
            this.menuMain = new System.Windows.Forms.MenuStrip();
            this.用户ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.修改密码ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.退出登录ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.设置ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.开市自动单设置ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.帮助ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.关于ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.panlMain = new System.Windows.Forms.Panel();
            ((System.ComponentModel.ISupportInitialize)(this.splitMain)).BeginInit();
            this.splitMain.Panel1.SuspendLayout();
            this.splitMain.Panel2.SuspendLayout();
            this.splitMain.SuspendLayout();
            this.tabExchange.SuspendLayout();
            this.contmenuTabExchange.SuspendLayout();
            this.tabPageDCE.SuspendLayout();
            this.tabPageSHFE.SuspendLayout();
            this.tabPageCFFE.SuspendLayout();
            this.tabPageZCE.SuspendLayout();
            this.tabUserDefine.SuspendLayout();
            this.tbpanlOrderInfo.SuspendLayout();
            this.tabOrders.SuspendLayout();
            this.tabPageOpenOrders.SuspendLayout();
            this.tabPageAllOrders.SuspendLayout();
            this.tabPageHisOrders.SuspendLayout();
            this.tabPageCodes.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gdvwCodes)).BeginInit();
            this.flpnelInfo.SuspendLayout();
            this.flpanlOrder.SuspendLayout();
            this.tbpanlOrder.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numPrice)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numVolume)).BeginInit();
            this.tbpanlOpenClose.SuspendLayout();
            this.tbpanlBuySell.SuspendLayout();
            this.tbInstrumentInfo.SuspendLayout();
            this.tbpanlSubOrder.SuspendLayout();
            this.tbpanlInstrumentInfo.SuspendLayout();
            this.statusStrip.SuspendLayout();
            this.menuMain.SuspendLayout();
            this.panlMain.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitMain
            // 
            resources.ApplyResources(this.splitMain, "splitMain");
            this.splitMain.Name = "splitMain";
            // 
            // splitMain.Panel1
            // 
            this.splitMain.Panel1.Controls.Add(this.tabExchange);
            resources.ApplyResources(this.splitMain.Panel1, "splitMain.Panel1");
            // 
            // splitMain.Panel2
            // 
            this.splitMain.Panel2.Controls.Add(this.tbpanlOrderInfo);
            // 
            // tabExchange
            // 
            resources.ApplyResources(this.tabExchange, "tabExchange");
            this.tabExchange.ContextMenuStrip = this.contmenuTabExchange;
            this.tabExchange.Controls.Add(this.tabPageDCE);
            this.tabExchange.Controls.Add(this.tabPageSHFE);
            this.tabExchange.Controls.Add(this.tabPageCFFE);
            this.tabExchange.Controls.Add(this.tabPageZCE);
            this.tabExchange.Controls.Add(this.tabUserDefine);
            this.tabExchange.Multiline = true;
            this.tabExchange.Name = "tabExchange";
            this.tabExchange.SelectedIndex = 0;
            // 
            // contmenuTabExchange
            // 
            this.contmenuTabExchange.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.切换显示ToolStripMenuItem});
            this.contmenuTabExchange.Name = "contextMenuStrip1";
            resources.ApplyResources(this.contmenuTabExchange, "contmenuTabExchange");
            // 
            // 切换显示ToolStripMenuItem
            // 
            this.切换显示ToolStripMenuItem.Name = "切换显示ToolStripMenuItem";
            resources.ApplyResources(this.切换显示ToolStripMenuItem, "切换显示ToolStripMenuItem");
            this.切换显示ToolStripMenuItem.Click += new System.EventHandler(this.切换显示ToolStripMenuItem_Click);
            // 
            // tabPageDCE
            // 
            this.tabPageDCE.Controls.Add(this.mdvwDCE);
            resources.ApplyResources(this.tabPageDCE, "tabPageDCE");
            this.tabPageDCE.Name = "tabPageDCE";
            this.tabPageDCE.UseVisualStyleBackColor = true;
            // 
            // mdvwDCE
            // 
            resources.ApplyResources(this.mdvwDCE, "mdvwDCE");
            this.mdvwDCE.Name = "mdvwDCE";
            // 
            // tabPageSHFE
            // 
            this.tabPageSHFE.Controls.Add(this.mdvwSHFE);
            resources.ApplyResources(this.tabPageSHFE, "tabPageSHFE");
            this.tabPageSHFE.Name = "tabPageSHFE";
            this.tabPageSHFE.UseVisualStyleBackColor = true;
            // 
            // mdvwSHFE
            // 
            resources.ApplyResources(this.mdvwSHFE, "mdvwSHFE");
            this.mdvwSHFE.Name = "mdvwSHFE";
            // 
            // tabPageCFFE
            // 
            this.tabPageCFFE.Controls.Add(this.mdvwCFFE);
            resources.ApplyResources(this.tabPageCFFE, "tabPageCFFE");
            this.tabPageCFFE.Name = "tabPageCFFE";
            this.tabPageCFFE.UseVisualStyleBackColor = true;
            // 
            // mdvwCFFE
            // 
            resources.ApplyResources(this.mdvwCFFE, "mdvwCFFE");
            this.mdvwCFFE.Name = "mdvwCFFE";
            // 
            // tabPageZCE
            // 
            this.tabPageZCE.Controls.Add(this.mdvwZCE);
            resources.ApplyResources(this.tabPageZCE, "tabPageZCE");
            this.tabPageZCE.Name = "tabPageZCE";
            this.tabPageZCE.UseVisualStyleBackColor = true;
            // 
            // mdvwZCE
            // 
            resources.ApplyResources(this.mdvwZCE, "mdvwZCE");
            this.mdvwZCE.Name = "mdvwZCE";
            // 
            // tabUserDefine
            // 
            this.tabUserDefine.Controls.Add(this.mdvwCustom);
            resources.ApplyResources(this.tabUserDefine, "tabUserDefine");
            this.tabUserDefine.Name = "tabUserDefine";
            this.tabUserDefine.UseVisualStyleBackColor = true;
            // 
            // mdvwCustom
            // 
            resources.ApplyResources(this.mdvwCustom, "mdvwCustom");
            this.mdvwCustom.Name = "mdvwCustom";
            // 
            // tbpanlOrderInfo
            // 
            resources.ApplyResources(this.tbpanlOrderInfo, "tbpanlOrderInfo");
            this.tbpanlOrderInfo.Controls.Add(this.tabOrders, 0, 1);
            this.tbpanlOrderInfo.Controls.Add(this.flpnelInfo, 0, 0);
            this.tbpanlOrderInfo.Controls.Add(this.flpanlOrder, 1, 1);
            this.tbpanlOrderInfo.Name = "tbpanlOrderInfo";
            // 
            // tabOrders
            // 
            this.tabOrders.Controls.Add(this.tabPageOpenOrders);
            this.tabOrders.Controls.Add(this.tabPageAllOrders);
            this.tabOrders.Controls.Add(this.tabPageHisOrders);
            this.tabOrders.Controls.Add(this.tabPageCodes);
            resources.ApplyResources(this.tabOrders, "tabOrders");
            this.tabOrders.Name = "tabOrders";
            this.tabOrders.SelectedIndex = 0;
            // 
            // tabPageOpenOrders
            // 
            this.tabPageOpenOrders.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.tabPageOpenOrders.Controls.Add(this.odvwOpenOrders);
            resources.ApplyResources(this.tabPageOpenOrders, "tabPageOpenOrders");
            this.tabPageOpenOrders.Name = "tabPageOpenOrders";
            // 
            // odvwOpenOrders
            // 
            resources.ApplyResources(this.odvwOpenOrders, "odvwOpenOrders");
            this.odvwOpenOrders.DataSource = null;
            this.odvwOpenOrders.Name = "odvwOpenOrders";
            // 
            // tabPageAllOrders
            // 
            this.tabPageAllOrders.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.tabPageAllOrders.Controls.Add(this.odvwAllOrders);
            resources.ApplyResources(this.tabPageAllOrders, "tabPageAllOrders");
            this.tabPageAllOrders.Name = "tabPageAllOrders";
            // 
            // odvwAllOrders
            // 
            this.odvwAllOrders.DataSource = null;
            resources.ApplyResources(this.odvwAllOrders, "odvwAllOrders");
            this.odvwAllOrders.Name = "odvwAllOrders";
            // 
            // tabPageHisOrders
            // 
            this.tabPageHisOrders.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.tabPageHisOrders.Controls.Add(this.odvwHisOrders);
            resources.ApplyResources(this.tabPageHisOrders, "tabPageHisOrders");
            this.tabPageHisOrders.Name = "tabPageHisOrders";
            // 
            // odvwHisOrders
            // 
            this.odvwHisOrders.DataSource = null;
            resources.ApplyResources(this.odvwHisOrders, "odvwHisOrders");
            this.odvwHisOrders.Name = "odvwHisOrders";
            // 
            // tabPageCodes
            // 
            this.tabPageCodes.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.tabPageCodes.Controls.Add(this.gdvwCodes);
            resources.ApplyResources(this.tabPageCodes, "tabPageCodes");
            this.tabPageCodes.Name = "tabPageCodes";
            // 
            // gdvwCodes
            // 
            this.gdvwCodes.AllowUserToResizeRows = false;
            this.gdvwCodes.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCellsExceptHeaders;
            this.gdvwCodes.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            resources.ApplyResources(this.gdvwCodes, "gdvwCodes");
            this.gdvwCodes.Name = "gdvwCodes";
            this.gdvwCodes.RowTemplate.Height = 23;
            this.gdvwCodes.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gdvwCodes.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gdvwCodes_CellDoubleClick);
            // 
            // flpnelInfo
            // 
            resources.ApplyResources(this.flpnelInfo, "flpnelInfo");
            this.tbpanlOrderInfo.SetColumnSpan(this.flpnelInfo, 2);
            this.flpnelInfo.Controls.Add(this.lbAccountInfo);
            this.flpnelInfo.Controls.Add(this.lbRightText);
            this.flpnelInfo.Controls.Add(this.lbRight);
            this.flpnelInfo.Controls.Add(this.lbAvailableText);
            this.flpnelInfo.Controls.Add(this.lbAvailable);
            this.flpnelInfo.Name = "flpnelInfo";
            // 
            // lbAccountInfo
            // 
            resources.ApplyResources(this.lbAccountInfo, "lbAccountInfo");
            this.lbAccountInfo.Name = "lbAccountInfo";
            // 
            // lbRightText
            // 
            resources.ApplyResources(this.lbRightText, "lbRightText");
            this.lbRightText.Name = "lbRightText";
            // 
            // lbRight
            // 
            resources.ApplyResources(this.lbRight, "lbRight");
            this.lbRight.ForeColor = System.Drawing.Color.OrangeRed;
            this.lbRight.Name = "lbRight";
            // 
            // lbAvailableText
            // 
            resources.ApplyResources(this.lbAvailableText, "lbAvailableText");
            this.lbAvailableText.Name = "lbAvailableText";
            // 
            // lbAvailable
            // 
            resources.ApplyResources(this.lbAvailable, "lbAvailable");
            this.lbAvailable.ForeColor = System.Drawing.Color.DodgerBlue;
            this.lbAvailable.Name = "lbAvailable";
            // 
            // flpanlOrder
            // 
            resources.ApplyResources(this.flpanlOrder, "flpanlOrder");
            this.flpanlOrder.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.flpanlOrder.Controls.Add(this.tbpanlOrder);
            this.flpanlOrder.Controls.Add(this.tbpanlSubOrder);
            this.flpanlOrder.Controls.Add(this.tbpanlInstrumentInfo);
            this.flpanlOrder.Controls.Add(this.btnParellel);
            this.flpanlOrder.Name = "flpanlOrder";
            // 
            // tbpanlOrder
            // 
            resources.ApplyResources(this.tbpanlOrder, "tbpanlOrder");
            this.tbpanlOrder.Controls.Add(this.lbInstrument, 0, 1);
            this.tbpanlOrder.Controls.Add(this.lbDirection, 0, 2);
            this.tbpanlOrder.Controls.Add(this.lbAction, 0, 3);
            this.tbpanlOrder.Controls.Add(this.lbPrice, 0, 4);
            this.tbpanlOrder.Controls.Add(this.lbVolume, 0, 5);
            this.tbpanlOrder.Controls.Add(this.txtInstrumentID, 1, 1);
            this.tbpanlOrder.Controls.Add(this.numPrice, 1, 4);
            this.tbpanlOrder.Controls.Add(this.numVolume, 1, 5);
            this.tbpanlOrder.Controls.Add(this.tbpanlOpenClose, 1, 3);
            this.tbpanlOrder.Controls.Add(this.tbpanlBuySell, 1, 2);
            this.tbpanlOrder.Controls.Add(this.tbInstrumentInfo, 0, 0);
            this.tbpanlOrder.Name = "tbpanlOrder";
            // 
            // lbInstrument
            // 
            resources.ApplyResources(this.lbInstrument, "lbInstrument");
            this.lbInstrument.Name = "lbInstrument";
            // 
            // lbDirection
            // 
            resources.ApplyResources(this.lbDirection, "lbDirection");
            this.lbDirection.Name = "lbDirection";
            // 
            // lbAction
            // 
            resources.ApplyResources(this.lbAction, "lbAction");
            this.lbAction.Name = "lbAction";
            // 
            // lbPrice
            // 
            resources.ApplyResources(this.lbPrice, "lbPrice");
            this.lbPrice.Name = "lbPrice";
            // 
            // lbVolume
            // 
            resources.ApplyResources(this.lbVolume, "lbVolume");
            this.lbVolume.Name = "lbVolume";
            // 
            // txtInstrumentID
            // 
            resources.ApplyResources(this.txtInstrumentID, "txtInstrumentID");
            this.txtInstrumentID.Name = "txtInstrumentID";
            // 
            // numPrice
            // 
            resources.ApplyResources(this.numPrice, "numPrice");
            this.numPrice.DecimalPlaces = 2;
            this.numPrice.Increment = new decimal(new int[] {
            5,
            0,
            0,
            131072});
            this.numPrice.Maximum = new decimal(new int[] {
            9999999,
            0,
            0,
            0});
            this.numPrice.Name = "numPrice";
            // 
            // numVolume
            // 
            resources.ApplyResources(this.numVolume, "numVolume");
            this.numVolume.Maximum = new decimal(new int[] {
            999999,
            0,
            0,
            0});
            this.numVolume.Name = "numVolume";
            // 
            // tbpanlOpenClose
            // 
            resources.ApplyResources(this.tbpanlOpenClose, "tbpanlOpenClose");
            this.tbpanlOpenClose.Controls.Add(this.rdoOpen, 0, 0);
            this.tbpanlOpenClose.Controls.Add(this.rdoClose, 1, 0);
            this.tbpanlOpenClose.Name = "tbpanlOpenClose";
            // 
            // rdoOpen
            // 
            resources.ApplyResources(this.rdoOpen, "rdoOpen");
            this.rdoOpen.Checked = true;
            this.rdoOpen.Name = "rdoOpen";
            this.rdoOpen.TabStop = true;
            this.rdoOpen.UseVisualStyleBackColor = true;
            // 
            // rdoClose
            // 
            resources.ApplyResources(this.rdoClose, "rdoClose");
            this.rdoClose.Name = "rdoClose";
            this.rdoClose.UseVisualStyleBackColor = true;
            // 
            // tbpanlBuySell
            // 
            resources.ApplyResources(this.tbpanlBuySell, "tbpanlBuySell");
            this.tbpanlBuySell.Controls.Add(this.rdoBuy, 0, 0);
            this.tbpanlBuySell.Controls.Add(this.rdoSell, 1, 0);
            this.tbpanlBuySell.Name = "tbpanlBuySell";
            // 
            // rdoBuy
            // 
            resources.ApplyResources(this.rdoBuy, "rdoBuy");
            this.rdoBuy.Checked = true;
            this.rdoBuy.Name = "rdoBuy";
            this.rdoBuy.TabStop = true;
            this.rdoBuy.UseVisualStyleBackColor = true;
            // 
            // rdoSell
            // 
            resources.ApplyResources(this.rdoSell, "rdoSell");
            this.rdoSell.Name = "rdoSell";
            this.rdoSell.UseVisualStyleBackColor = true;
            // 
            // tbInstrumentInfo
            // 
            resources.ApplyResources(this.tbInstrumentInfo, "tbInstrumentInfo");
            this.tbpanlOrder.SetColumnSpan(this.tbInstrumentInfo, 2);
            this.tbInstrumentInfo.Controls.Add(this.lbInstrumentName, 1, 0);
            this.tbInstrumentInfo.Controls.Add(this.lbExchange, 0, 0);
            this.tbInstrumentInfo.Name = "tbInstrumentInfo";
            // 
            // lbInstrumentName
            // 
            resources.ApplyResources(this.lbInstrumentName, "lbInstrumentName");
            this.lbInstrumentName.Name = "lbInstrumentName";
            // 
            // lbExchange
            // 
            resources.ApplyResources(this.lbExchange, "lbExchange");
            this.lbExchange.Name = "lbExchange";
            // 
            // tbpanlSubOrder
            // 
            resources.ApplyResources(this.tbpanlSubOrder, "tbpanlSubOrder");
            this.tbpanlSubOrder.Controls.Add(this.btnAddOpenOrder, 0, 0);
            this.tbpanlSubOrder.Controls.Add(this.btnAddOrder, 1, 0);
            this.tbpanlSubOrder.Name = "tbpanlSubOrder";
            // 
            // btnAddOpenOrder
            // 
            resources.ApplyResources(this.btnAddOpenOrder, "btnAddOpenOrder");
            this.btnAddOpenOrder.Name = "btnAddOpenOrder";
            this.btnAddOpenOrder.UseVisualStyleBackColor = true;
            this.btnAddOpenOrder.Click += new System.EventHandler(this.btnAddOrderList_Click);
            // 
            // btnAddOrder
            // 
            resources.ApplyResources(this.btnAddOrder, "btnAddOrder");
            this.btnAddOrder.Name = "btnAddOrder";
            this.btnAddOrder.UseVisualStyleBackColor = true;
            this.btnAddOrder.Click += new System.EventHandler(this.btnAddOrderList_Click);
            // 
            // tbpanlInstrumentInfo
            // 
            resources.ApplyResources(this.tbpanlInstrumentInfo, "tbpanlInstrumentInfo");
            this.tbpanlInstrumentInfo.Controls.Add(this.lbBuyPrice, 0, 0);
            this.tbpanlInstrumentInfo.Controls.Add(this.lbSellPrice, 2, 0);
            this.tbpanlInstrumentInfo.Controls.Add(this.lbSellVolume, 2, 1);
            this.tbpanlInstrumentInfo.Controls.Add(this.lbBuyVolume, 0, 1);
            this.tbpanlInstrumentInfo.Controls.Add(this.lbTop, 0, 2);
            this.tbpanlInstrumentInfo.Controls.Add(this.lbBottom, 2, 2);
            this.tbpanlInstrumentInfo.Controls.Add(this.lbOpen, 0, 3);
            this.tbpanlInstrumentInfo.Controls.Add(this.lbClose, 2, 3);
            this.tbpanlInstrumentInfo.Name = "tbpanlInstrumentInfo";
            // 
            // lbBuyPrice
            // 
            resources.ApplyResources(this.lbBuyPrice, "lbBuyPrice");
            this.lbBuyPrice.Name = "lbBuyPrice";
            // 
            // lbSellPrice
            // 
            resources.ApplyResources(this.lbSellPrice, "lbSellPrice");
            this.lbSellPrice.Name = "lbSellPrice";
            // 
            // lbSellVolume
            // 
            resources.ApplyResources(this.lbSellVolume, "lbSellVolume");
            this.lbSellVolume.Name = "lbSellVolume";
            // 
            // lbBuyVolume
            // 
            resources.ApplyResources(this.lbBuyVolume, "lbBuyVolume");
            this.lbBuyVolume.Name = "lbBuyVolume";
            // 
            // lbTop
            // 
            resources.ApplyResources(this.lbTop, "lbTop");
            this.lbTop.Name = "lbTop";
            // 
            // lbBottom
            // 
            resources.ApplyResources(this.lbBottom, "lbBottom");
            this.lbBottom.Name = "lbBottom";
            // 
            // lbOpen
            // 
            resources.ApplyResources(this.lbOpen, "lbOpen");
            this.lbOpen.Name = "lbOpen";
            // 
            // lbClose
            // 
            resources.ApplyResources(this.lbClose, "lbClose");
            this.lbClose.Name = "lbClose";
            // 
            // btnParellel
            // 
            resources.ApplyResources(this.btnParellel, "btnParellel");
            this.btnParellel.Name = "btnParellel";
            this.btnParellel.UseVisualStyleBackColor = true;
            this.btnParellel.Click += new System.EventHandler(this.btnParellel_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.strplbTradeFrontSvr,
            this.toolStripSplitButton1,
            this.striplbMarketFrontSvr});
            resources.ApplyResources(this.statusStrip, "statusStrip");
            this.statusStrip.Name = "statusStrip";
            // 
            // strplbTradeFrontSvr
            // 
            this.strplbTradeFrontSvr.Name = "strplbTradeFrontSvr";
            resources.ApplyResources(this.strplbTradeFrontSvr, "strplbTradeFrontSvr");
            // 
            // toolStripSplitButton1
            // 
            this.toolStripSplitButton1.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
            this.toolStripSplitButton1.Name = "toolStripSplitButton1";
            resources.ApplyResources(this.toolStripSplitButton1, "toolStripSplitButton1");
            // 
            // striplbMarketFrontSvr
            // 
            this.striplbMarketFrontSvr.Name = "striplbMarketFrontSvr";
            resources.ApplyResources(this.striplbMarketFrontSvr, "striplbMarketFrontSvr");
            // 
            // menuMain
            // 
            this.menuMain.GripMargin = new System.Windows.Forms.Padding(2);
            this.menuMain.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.用户ToolStripMenuItem,
            this.设置ToolStripMenuItem,
            this.帮助ToolStripMenuItem});
            resources.ApplyResources(this.menuMain, "menuMain");
            this.menuMain.Name = "menuMain";
            this.menuMain.ShowItemToolTips = true;
            // 
            // 用户ToolStripMenuItem
            // 
            this.用户ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.修改密码ToolStripMenuItem,
            this.退出登录ToolStripMenuItem});
            this.用户ToolStripMenuItem.Name = "用户ToolStripMenuItem";
            resources.ApplyResources(this.用户ToolStripMenuItem, "用户ToolStripMenuItem");
            // 
            // 修改密码ToolStripMenuItem
            // 
            this.修改密码ToolStripMenuItem.Name = "修改密码ToolStripMenuItem";
            resources.ApplyResources(this.修改密码ToolStripMenuItem, "修改密码ToolStripMenuItem");
            // 
            // 退出登录ToolStripMenuItem
            // 
            this.退出登录ToolStripMenuItem.Name = "退出登录ToolStripMenuItem";
            resources.ApplyResources(this.退出登录ToolStripMenuItem, "退出登录ToolStripMenuItem");
            // 
            // 设置ToolStripMenuItem
            // 
            this.设置ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.开市自动单设置ToolStripMenuItem});
            this.设置ToolStripMenuItem.Name = "设置ToolStripMenuItem";
            resources.ApplyResources(this.设置ToolStripMenuItem, "设置ToolStripMenuItem");
            // 
            // 开市自动单设置ToolStripMenuItem
            // 
            this.开市自动单设置ToolStripMenuItem.Name = "开市自动单设置ToolStripMenuItem";
            resources.ApplyResources(this.开市自动单设置ToolStripMenuItem, "开市自动单设置ToolStripMenuItem");
            this.开市自动单设置ToolStripMenuItem.Click += new System.EventHandler(this.开市自动单设置ToolStripMenuItem_Click);
            // 
            // 帮助ToolStripMenuItem
            // 
            this.帮助ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.关于ToolStripMenuItem});
            this.帮助ToolStripMenuItem.Name = "帮助ToolStripMenuItem";
            resources.ApplyResources(this.帮助ToolStripMenuItem, "帮助ToolStripMenuItem");
            // 
            // 关于ToolStripMenuItem
            // 
            this.关于ToolStripMenuItem.Name = "关于ToolStripMenuItem";
            resources.ApplyResources(this.关于ToolStripMenuItem, "关于ToolStripMenuItem");
            // 
            // panlMain
            // 
            this.panlMain.Controls.Add(this.splitMain);
            resources.ApplyResources(this.panlMain, "panlMain");
            this.panlMain.Name = "panlMain";
            // 
            // MainForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panlMain);
            this.Controls.Add(this.menuMain);
            this.Controls.Add(this.statusStrip);
            this.DoubleBuffered = true;
            this.Name = "MainForm";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.splitMain.Panel1.ResumeLayout(false);
            this.splitMain.Panel2.ResumeLayout(false);
            this.splitMain.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitMain)).EndInit();
            this.splitMain.ResumeLayout(false);
            this.tabExchange.ResumeLayout(false);
            this.contmenuTabExchange.ResumeLayout(false);
            this.tabPageDCE.ResumeLayout(false);
            this.tabPageSHFE.ResumeLayout(false);
            this.tabPageCFFE.ResumeLayout(false);
            this.tabPageZCE.ResumeLayout(false);
            this.tabUserDefine.ResumeLayout(false);
            this.tbpanlOrderInfo.ResumeLayout(false);
            this.tbpanlOrderInfo.PerformLayout();
            this.tabOrders.ResumeLayout(false);
            this.tabPageOpenOrders.ResumeLayout(false);
            this.tabPageOpenOrders.PerformLayout();
            this.tabPageAllOrders.ResumeLayout(false);
            this.tabPageHisOrders.ResumeLayout(false);
            this.tabPageCodes.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gdvwCodes)).EndInit();
            this.flpnelInfo.ResumeLayout(false);
            this.flpnelInfo.PerformLayout();
            this.flpanlOrder.ResumeLayout(false);
            this.flpanlOrder.PerformLayout();
            this.tbpanlOrder.ResumeLayout(false);
            this.tbpanlOrder.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numPrice)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numVolume)).EndInit();
            this.tbpanlOpenClose.ResumeLayout(false);
            this.tbpanlOpenClose.PerformLayout();
            this.tbpanlBuySell.ResumeLayout(false);
            this.tbpanlBuySell.PerformLayout();
            this.tbInstrumentInfo.ResumeLayout(false);
            this.tbInstrumentInfo.PerformLayout();
            this.tbpanlSubOrder.ResumeLayout(false);
            this.tbpanlInstrumentInfo.ResumeLayout(false);
            this.tbpanlInstrumentInfo.PerformLayout();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.menuMain.ResumeLayout(false);
            this.menuMain.PerformLayout();
            this.panlMain.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.SplitContainer splitMain;
        private System.Windows.Forms.TableLayoutPanel tbpanlOrderInfo;
        private System.Windows.Forms.FlowLayoutPanel flpnelInfo;
        private System.Windows.Forms.Label lbAccountInfo;
        private System.Windows.Forms.Label lbRightText;
        private System.Windows.Forms.Label lbRight;
        private System.Windows.Forms.Label lbAvailableText;
        private System.Windows.Forms.Label lbAvailable;
        private System.Windows.Forms.TableLayoutPanel tbpanlOrder;
        private System.Windows.Forms.Label lbInstrument;
        private System.Windows.Forms.Label lbDirection;
        private System.Windows.Forms.Label lbAction;
        private System.Windows.Forms.Label lbPrice;
        private System.Windows.Forms.Label lbVolume;
        private System.Windows.Forms.TextBox txtInstrumentID;
        private System.Windows.Forms.NumericUpDown numPrice;
        private System.Windows.Forms.NumericUpDown numVolume;
        private System.Windows.Forms.FlowLayoutPanel flpanlOrder;
        private System.Windows.Forms.TableLayoutPanel tbpanlSubOrder;
        private System.Windows.Forms.Button btnAddOpenOrder;
        private System.Windows.Forms.Button btnAddOrder;
        private System.Windows.Forms.TableLayoutPanel tbpanlInstrumentInfo;
        private System.Windows.Forms.Label lbBuyPrice;
        private System.Windows.Forms.Label lbSellPrice;
        private System.Windows.Forms.Label lbSellVolume;
        private System.Windows.Forms.Label lbBuyVolume;
        private System.Windows.Forms.Label lbTop;
        private System.Windows.Forms.Label lbBottom;
        private System.Windows.Forms.Label lbOpen;
        private System.Windows.Forms.Label lbClose;
        private System.Windows.Forms.TabControl tabExchange;
        private System.Windows.Forms.TabPage tabPageDCE;
        private System.Windows.Forms.TabPage tabPageSHFE;
        private System.Windows.Forms.TabPage tabPageCFFE;
        private System.Windows.Forms.TabPage tabPageZCE;
        private System.Windows.Forms.TabPage tabUserDefine;
        private ProgramTradeModules.MarketViewer mdvwDCE;
        private System.Windows.Forms.ContextMenuStrip contmenuTabExchange;
        private System.Windows.Forms.ToolStripMenuItem 切换显示ToolStripMenuItem;
        private System.Windows.Forms.Button btnParellel;
        private ProgramTradeModules.MarketViewer mdvwSHFE;
        private ProgramTradeModules.MarketViewer mdvwCFFE;
        private ProgramTradeModules.MarketViewer mdvwZCE;
        private ProgramTradeModules.MarketViewer mdvwCustom;
        private System.Windows.Forms.RadioButton rdoSell;
        private System.Windows.Forms.TableLayoutPanel tbpanlBuySell;
        private System.Windows.Forms.RadioButton rdoBuy;
        private System.Windows.Forms.TableLayoutPanel tbpanlOpenClose;
        private System.Windows.Forms.RadioButton rdoOpen;
        private System.Windows.Forms.RadioButton rdoClose;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel strplbTradeFrontSvr;
        private System.Windows.Forms.ToolStripSplitButton toolStripSplitButton1;
        private System.Windows.Forms.ToolStripStatusLabel striplbMarketFrontSvr;
        private System.Windows.Forms.MenuStrip menuMain;
        private System.Windows.Forms.ToolStripMenuItem 用户ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 修改密码ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 退出登录ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 帮助ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 关于ToolStripMenuItem;
        private System.Windows.Forms.Panel panlMain;
        private System.Windows.Forms.TabControl tabOrders;
        private System.Windows.Forms.TabPage tabPageOpenOrders;
        private ProgramTradeModules.OrderViewer odvwOpenOrders;
        private System.Windows.Forms.TabPage tabPageAllOrders;
        private ProgramTradeModules.OrderViewer odvwAllOrders;
        private System.Windows.Forms.TabPage tabPageHisOrders;
        private ProgramTradeModules.OrderViewer odvwHisOrders;
        private System.Windows.Forms.TabPage tabPageCodes;
        private System.Windows.Forms.DataGridView gdvwCodes;
        private System.Windows.Forms.TableLayoutPanel tbInstrumentInfo;
        private System.Windows.Forms.Label lbInstrumentName;
        private System.Windows.Forms.Label lbExchange;
        private System.Windows.Forms.ToolStripMenuItem 设置ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 开市自动单设置ToolStripMenuItem;
    }
}

