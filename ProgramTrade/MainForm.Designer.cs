using ProgramTradeApi;
using CLRQdpApi;
using CLRXspeedApi;

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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle4 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle5 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle6 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle7 = new System.Windows.Forms.DataGridViewCellStyle();
            this.splitMain = new System.Windows.Forms.SplitContainer();
            this.tabExchange = new System.Windows.Forms.TabControl();
            this.contmenuTabExchange = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.切换显示ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tabPageAll = new System.Windows.Forms.TabPage();
            this.splitMarket = new System.Windows.Forms.SplitContainer();
            this.dgvwMarket = new System.Windows.Forms.DataGridView();
            this.marketsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tabPageDCE = new System.Windows.Forms.TabPage();
            this.tabPageSHFE = new System.Windows.Forms.TabPage();
            this.tabPageCFFE = new System.Windows.Forms.TabPage();
            this.tabPageZCE = new System.Windows.Forms.TabPage();
            this.tabUserDefine = new System.Windows.Forms.TabPage();
            this.tbpanlOrderInfo = new System.Windows.Forms.TableLayoutPanel();
            this.tabOrders = new System.Windows.Forms.TabControl();
            this.tabPageAllOrders = new System.Windows.Forms.TabPage();
            this.dgvwOrders = new System.Windows.Forms.DataGridView();
            this.dataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.orderStatusDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.instrumentIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn6 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.matchedPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.directionDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.operationDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.volumeDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.matchedVolumeDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn5 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.exchangeIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn2 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn4 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.flagDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ordersBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tabPageHisOrders = new System.Windows.Forms.TabPage();
            this.dgvwPositions = new System.Windows.Forms.DataGridView();
            this.posExchangeID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.posInstrumentID = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.posDirection = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.posVolumeAll = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.posPositionPrice = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.posVolumeToday = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.posVolumeYestoday = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.posFlag = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.positionsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tabPageCodes = new System.Windows.Forms.TabPage();
            this.dgvwInstruments = new System.Windows.Forms.DataGridView();
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
            this.延时测试ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.panlMain = new System.Windows.Forms.Panel();
            this.dataGridViewTextBoxColumn7 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn8 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn9 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn10 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn11 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn12 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.dataGridViewTextBoxColumn13 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.instrumentIDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.instrumentNameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.latestPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.openPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.highestPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.lowestPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.volumeDataGridViewTextBoxColumn3 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.closePriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.exchangeIDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.topLimitPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.bottomLimitPriceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            ((System.ComponentModel.ISupportInitialize)(this.splitMain)).BeginInit();
            this.splitMain.Panel1.SuspendLayout();
            this.splitMain.Panel2.SuspendLayout();
            this.splitMain.SuspendLayout();
            this.tabExchange.SuspendLayout();
            this.contmenuTabExchange.SuspendLayout();
            this.tabPageAll.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitMarket)).BeginInit();
            this.splitMarket.Panel2.SuspendLayout();
            this.splitMarket.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvwMarket)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.marketsBindingSource)).BeginInit();
            this.tbpanlOrderInfo.SuspendLayout();
            this.tabOrders.SuspendLayout();
            this.tabPageAllOrders.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvwOrders)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.ordersBindingSource)).BeginInit();
            this.tabPageHisOrders.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvwPositions)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.positionsBindingSource)).BeginInit();
            this.tabPageCodes.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvwInstruments)).BeginInit();
            this.flpnelInfo.SuspendLayout();
            this.flpanlOrder.SuspendLayout();
            this.tbpanlOrder.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numPrice)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numVolume)).BeginInit();
            this.tbpanlOpenClose.SuspendLayout();
            this.tbpanlBuySell.SuspendLayout();
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
            this.tabExchange.Controls.Add(this.tabPageAll);
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
            // tabPageAll
            // 
            resources.ApplyResources(this.tabPageAll, "tabPageAll");
            this.tabPageAll.Controls.Add(this.splitMarket);
            this.tabPageAll.Name = "tabPageAll";
            this.tabPageAll.UseVisualStyleBackColor = true;
            // 
            // splitMarket
            // 
            resources.ApplyResources(this.splitMarket, "splitMarket");
            this.splitMarket.Name = "splitMarket";
            // 
            // splitMarket.Panel2
            // 
            this.splitMarket.Panel2.Controls.Add(this.dgvwMarket);
            // 
            // dgvwMarket
            // 
            this.dgvwMarket.AllowUserToAddRows = false;
            this.dgvwMarket.AllowUserToDeleteRows = false;
            this.dgvwMarket.AllowUserToOrderColumns = true;
            this.dgvwMarket.AutoGenerateColumns = false;
            this.dgvwMarket.BackgroundColor = System.Drawing.SystemColors.WindowText;
            this.dgvwMarket.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.instrumentIDDataGridViewTextBoxColumn1,
            this.instrumentNameDataGridViewTextBoxColumn,
            this.latestPriceDataGridViewTextBoxColumn,
            this.openPriceDataGridViewTextBoxColumn,
            this.highestPriceDataGridViewTextBoxColumn,
            this.lowestPriceDataGridViewTextBoxColumn,
            this.volumeDataGridViewTextBoxColumn3,
            this.closePriceDataGridViewTextBoxColumn,
            this.exchangeIDDataGridViewTextBoxColumn1,
            this.topLimitPriceDataGridViewTextBoxColumn,
            this.bottomLimitPriceDataGridViewTextBoxColumn});
            this.dgvwMarket.DataSource = this.marketsBindingSource;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.InfoText;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.ControlLightLight;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dgvwMarket.DefaultCellStyle = dataGridViewCellStyle1;
            resources.ApplyResources(this.dgvwMarket, "dgvwMarket");
            this.dgvwMarket.Name = "dgvwMarket";
            this.dgvwMarket.ReadOnly = true;
            this.dgvwMarket.RowTemplate.Height = 23;
            this.dgvwMarket.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            // 
            // marketsBindingSource
            // 
            this.marketsBindingSource.AllowNew = true;
            this.marketsBindingSource.DataSource = typeof(ProgramTradeApi.MarketDetail);
            this.marketsBindingSource.Sort = "";
            // 
            // tabPageDCE
            // 
            resources.ApplyResources(this.tabPageDCE, "tabPageDCE");
            this.tabPageDCE.Name = "tabPageDCE";
            this.tabPageDCE.UseVisualStyleBackColor = true;
            // 
            // tabPageSHFE
            // 
            resources.ApplyResources(this.tabPageSHFE, "tabPageSHFE");
            this.tabPageSHFE.Name = "tabPageSHFE";
            this.tabPageSHFE.UseVisualStyleBackColor = true;
            // 
            // tabPageCFFE
            // 
            resources.ApplyResources(this.tabPageCFFE, "tabPageCFFE");
            this.tabPageCFFE.Name = "tabPageCFFE";
            this.tabPageCFFE.UseVisualStyleBackColor = true;
            // 
            // tabPageZCE
            // 
            resources.ApplyResources(this.tabPageZCE, "tabPageZCE");
            this.tabPageZCE.Name = "tabPageZCE";
            this.tabPageZCE.UseVisualStyleBackColor = true;
            // 
            // tabUserDefine
            // 
            resources.ApplyResources(this.tabUserDefine, "tabUserDefine");
            this.tabUserDefine.Name = "tabUserDefine";
            this.tabUserDefine.UseVisualStyleBackColor = true;
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
            this.tabOrders.Controls.Add(this.tabPageAllOrders);
            this.tabOrders.Controls.Add(this.tabPageHisOrders);
            this.tabOrders.Controls.Add(this.tabPageCodes);
            resources.ApplyResources(this.tabOrders, "tabOrders");
            this.tabOrders.Name = "tabOrders";
            this.tabOrders.SelectedIndex = 0;
            // 
            // tabPageAllOrders
            // 
            this.tabPageAllOrders.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
            this.tabPageAllOrders.Controls.Add(this.dgvwOrders);
            resources.ApplyResources(this.tabPageAllOrders, "tabPageAllOrders");
            this.tabPageAllOrders.Name = "tabPageAllOrders";
            // 
            // dgvwOrders
            // 
            this.dgvwOrders.AllowUserToAddRows = false;
            this.dgvwOrders.AllowUserToDeleteRows = false;
            this.dgvwOrders.AllowUserToOrderColumns = true;
            this.dgvwOrders.AutoGenerateColumns = false;
            this.dgvwOrders.CausesValidation = false;
            this.dgvwOrders.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.dataGridViewTextBoxColumn1,
            this.orderStatusDataGridViewTextBoxColumn,
            this.instrumentIDDataGridViewTextBoxColumn,
            this.dataGridViewTextBoxColumn6,
            this.matchedPriceDataGridViewTextBoxColumn,
            this.directionDataGridViewTextBoxColumn,
            this.operationDataGridViewTextBoxColumn,
            this.volumeDataGridViewTextBoxColumn,
            this.matchedVolumeDataGridViewTextBoxColumn,
            this.dataGridViewTextBoxColumn5,
            this.exchangeIDDataGridViewTextBoxColumn,
            this.dataGridViewTextBoxColumn3,
            this.dataGridViewTextBoxColumn2,
            this.dataGridViewTextBoxColumn4,
            this.flagDataGridViewTextBoxColumn});
            this.dgvwOrders.DataSource = this.ordersBindingSource;
            resources.ApplyResources(this.dgvwOrders, "dgvwOrders");
            this.dgvwOrders.Name = "dgvwOrders";
            this.dgvwOrders.ReadOnly = true;
            this.dgvwOrders.RowTemplate.Height = 23;
            this.dgvwOrders.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            // 
            // dataGridViewTextBoxColumn1
            // 
            this.dataGridViewTextBoxColumn1.DataPropertyName = "OrderSysID";
            resources.ApplyResources(this.dataGridViewTextBoxColumn1, "dataGridViewTextBoxColumn1");
            this.dataGridViewTextBoxColumn1.Name = "dataGridViewTextBoxColumn1";
            this.dataGridViewTextBoxColumn1.ReadOnly = true;
            // 
            // orderStatusDataGridViewTextBoxColumn
            // 
            this.orderStatusDataGridViewTextBoxColumn.DataPropertyName = "OrderStatus";
            resources.ApplyResources(this.orderStatusDataGridViewTextBoxColumn, "orderStatusDataGridViewTextBoxColumn");
            this.orderStatusDataGridViewTextBoxColumn.Name = "orderStatusDataGridViewTextBoxColumn";
            this.orderStatusDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // instrumentIDDataGridViewTextBoxColumn
            // 
            this.instrumentIDDataGridViewTextBoxColumn.DataPropertyName = "InstrumentID";
            resources.ApplyResources(this.instrumentIDDataGridViewTextBoxColumn, "instrumentIDDataGridViewTextBoxColumn");
            this.instrumentIDDataGridViewTextBoxColumn.Name = "instrumentIDDataGridViewTextBoxColumn";
            this.instrumentIDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn6
            // 
            this.dataGridViewTextBoxColumn6.DataPropertyName = "LimitPrice";
            resources.ApplyResources(this.dataGridViewTextBoxColumn6, "dataGridViewTextBoxColumn6");
            this.dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            this.dataGridViewTextBoxColumn6.ReadOnly = true;
            // 
            // matchedPriceDataGridViewTextBoxColumn
            // 
            this.matchedPriceDataGridViewTextBoxColumn.DataPropertyName = "MatchedPrice";
            resources.ApplyResources(this.matchedPriceDataGridViewTextBoxColumn, "matchedPriceDataGridViewTextBoxColumn");
            this.matchedPriceDataGridViewTextBoxColumn.Name = "matchedPriceDataGridViewTextBoxColumn";
            this.matchedPriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // directionDataGridViewTextBoxColumn
            // 
            this.directionDataGridViewTextBoxColumn.DataPropertyName = "Direction";
            resources.ApplyResources(this.directionDataGridViewTextBoxColumn, "directionDataGridViewTextBoxColumn");
            this.directionDataGridViewTextBoxColumn.Name = "directionDataGridViewTextBoxColumn";
            this.directionDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // operationDataGridViewTextBoxColumn
            // 
            this.operationDataGridViewTextBoxColumn.DataPropertyName = "Operation";
            resources.ApplyResources(this.operationDataGridViewTextBoxColumn, "operationDataGridViewTextBoxColumn");
            this.operationDataGridViewTextBoxColumn.Name = "operationDataGridViewTextBoxColumn";
            this.operationDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // volumeDataGridViewTextBoxColumn
            // 
            this.volumeDataGridViewTextBoxColumn.DataPropertyName = "Volume";
            resources.ApplyResources(this.volumeDataGridViewTextBoxColumn, "volumeDataGridViewTextBoxColumn");
            this.volumeDataGridViewTextBoxColumn.Name = "volumeDataGridViewTextBoxColumn";
            this.volumeDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // matchedVolumeDataGridViewTextBoxColumn
            // 
            this.matchedVolumeDataGridViewTextBoxColumn.DataPropertyName = "MatchedVolume";
            resources.ApplyResources(this.matchedVolumeDataGridViewTextBoxColumn, "matchedVolumeDataGridViewTextBoxColumn");
            this.matchedVolumeDataGridViewTextBoxColumn.Name = "matchedVolumeDataGridViewTextBoxColumn";
            this.matchedVolumeDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn5
            // 
            this.dataGridViewTextBoxColumn5.DataPropertyName = "OrderType";
            resources.ApplyResources(this.dataGridViewTextBoxColumn5, "dataGridViewTextBoxColumn5");
            this.dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            this.dataGridViewTextBoxColumn5.ReadOnly = true;
            // 
            // exchangeIDDataGridViewTextBoxColumn
            // 
            this.exchangeIDDataGridViewTextBoxColumn.DataPropertyName = "ExchangeID";
            resources.ApplyResources(this.exchangeIDDataGridViewTextBoxColumn, "exchangeIDDataGridViewTextBoxColumn");
            this.exchangeIDDataGridViewTextBoxColumn.Name = "exchangeIDDataGridViewTextBoxColumn";
            this.exchangeIDDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn3
            // 
            this.dataGridViewTextBoxColumn3.DataPropertyName = "UserID";
            resources.ApplyResources(this.dataGridViewTextBoxColumn3, "dataGridViewTextBoxColumn3");
            this.dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            this.dataGridViewTextBoxColumn3.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn2
            // 
            this.dataGridViewTextBoxColumn2.DataPropertyName = "InvestorID";
            resources.ApplyResources(this.dataGridViewTextBoxColumn2, "dataGridViewTextBoxColumn2");
            this.dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            this.dataGridViewTextBoxColumn2.ReadOnly = true;
            // 
            // dataGridViewTextBoxColumn4
            // 
            this.dataGridViewTextBoxColumn4.DataPropertyName = "OrderLocalID";
            resources.ApplyResources(this.dataGridViewTextBoxColumn4, "dataGridViewTextBoxColumn4");
            this.dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            this.dataGridViewTextBoxColumn4.ReadOnly = true;
            // 
            // flagDataGridViewTextBoxColumn
            // 
            this.flagDataGridViewTextBoxColumn.DataPropertyName = "Flag";
            resources.ApplyResources(this.flagDataGridViewTextBoxColumn, "flagDataGridViewTextBoxColumn");
            this.flagDataGridViewTextBoxColumn.Name = "flagDataGridViewTextBoxColumn";
            this.flagDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // ordersBindingSource
            // 
            this.ordersBindingSource.AllowNew = true;
            this.ordersBindingSource.DataSource = typeof(ProgramTradeApi.OrderDetail);
            // 
            // tabPageHisOrders
            // 
            this.tabPageHisOrders.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.tabPageHisOrders.Controls.Add(this.dgvwPositions);
            resources.ApplyResources(this.tabPageHisOrders, "tabPageHisOrders");
            this.tabPageHisOrders.Name = "tabPageHisOrders";
            // 
            // dgvwPositions
            // 
            this.dgvwPositions.AllowUserToAddRows = false;
            this.dgvwPositions.AllowUserToDeleteRows = false;
            this.dgvwPositions.AllowUserToOrderColumns = true;
            this.dgvwPositions.AutoGenerateColumns = false;
            this.dgvwPositions.CausesValidation = false;
            this.dgvwPositions.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.posExchangeID,
            this.posInstrumentID,
            this.posDirection,
            this.posVolumeAll,
            this.posPositionPrice,
            this.posVolumeToday,
            this.posVolumeYestoday,
            this.posFlag});
            this.dgvwPositions.DataSource = this.positionsBindingSource;
            resources.ApplyResources(this.dgvwPositions, "dgvwPositions");
            this.dgvwPositions.Name = "dgvwPositions";
            this.dgvwPositions.ReadOnly = true;
            this.dgvwPositions.RowTemplate.Height = 23;
            this.dgvwPositions.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvwPositions.CellFormatting += new System.Windows.Forms.DataGridViewCellFormattingEventHandler(this.dgvwPositions_CellFormatting);
            this.dgvwPositions.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.dgvwPositions_MouseDoubleClick);
            // 
            // posExchangeID
            // 
            this.posExchangeID.DataPropertyName = "ExchangeID";
            resources.ApplyResources(this.posExchangeID, "posExchangeID");
            this.posExchangeID.Name = "posExchangeID";
            this.posExchangeID.ReadOnly = true;
            // 
            // posInstrumentID
            // 
            this.posInstrumentID.DataPropertyName = "InstrumentID";
            resources.ApplyResources(this.posInstrumentID, "posInstrumentID");
            this.posInstrumentID.Name = "posInstrumentID";
            this.posInstrumentID.ReadOnly = true;
            // 
            // posDirection
            // 
            this.posDirection.DataPropertyName = "Direction";
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle2.ForeColor = System.Drawing.Color.Red;
            this.posDirection.DefaultCellStyle = dataGridViewCellStyle2;
            resources.ApplyResources(this.posDirection, "posDirection");
            this.posDirection.Name = "posDirection";
            this.posDirection.ReadOnly = true;
            // 
            // posVolumeAll
            // 
            this.posVolumeAll.DataPropertyName = "VolumeAll";
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
            this.posVolumeAll.DefaultCellStyle = dataGridViewCellStyle3;
            resources.ApplyResources(this.posVolumeAll, "posVolumeAll");
            this.posVolumeAll.Name = "posVolumeAll";
            this.posVolumeAll.ReadOnly = true;
            // 
            // posPositionPrice
            // 
            this.posPositionPrice.DataPropertyName = "PositionPrice";
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
            this.posPositionPrice.DefaultCellStyle = dataGridViewCellStyle4;
            resources.ApplyResources(this.posPositionPrice, "posPositionPrice");
            this.posPositionPrice.Name = "posPositionPrice";
            this.posPositionPrice.ReadOnly = true;
            // 
            // posVolumeToday
            // 
            this.posVolumeToday.DataPropertyName = "VolumeToday";
            dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
            this.posVolumeToday.DefaultCellStyle = dataGridViewCellStyle5;
            resources.ApplyResources(this.posVolumeToday, "posVolumeToday");
            this.posVolumeToday.Name = "posVolumeToday";
            this.posVolumeToday.ReadOnly = true;
            // 
            // posVolumeYestoday
            // 
            this.posVolumeYestoday.DataPropertyName = "VolumeYestoday";
            dataGridViewCellStyle6.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleRight;
            this.posVolumeYestoday.DefaultCellStyle = dataGridViewCellStyle6;
            resources.ApplyResources(this.posVolumeYestoday, "posVolumeYestoday");
            this.posVolumeYestoday.Name = "posVolumeYestoday";
            this.posVolumeYestoday.ReadOnly = true;
            // 
            // posFlag
            // 
            this.posFlag.DataPropertyName = "Flag";
            resources.ApplyResources(this.posFlag, "posFlag");
            this.posFlag.Name = "posFlag";
            this.posFlag.ReadOnly = true;
            // 
            // positionsBindingSource
            // 
            this.positionsBindingSource.AllowNew = true;
            this.positionsBindingSource.DataSource = typeof(ProgramTradeApi.PositionDetail);
            // 
            // tabPageCodes
            // 
            this.tabPageCodes.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(192)))), ((int)(((byte)(255)))));
            this.tabPageCodes.Controls.Add(this.dgvwInstruments);
            resources.ApplyResources(this.tabPageCodes, "tabPageCodes");
            this.tabPageCodes.Name = "tabPageCodes";
            // 
            // dgvwInstruments
            // 
            resources.ApplyResources(this.dgvwInstruments, "dgvwInstruments");
            this.dgvwInstruments.Name = "dgvwInstruments";
            this.dgvwInstruments.ReadOnly = true;
            this.dgvwInstruments.RowTemplate.Height = 23;
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
            // 
            // 帮助ToolStripMenuItem
            // 
            this.帮助ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.关于ToolStripMenuItem,
            this.延时测试ToolStripMenuItem});
            this.帮助ToolStripMenuItem.Name = "帮助ToolStripMenuItem";
            resources.ApplyResources(this.帮助ToolStripMenuItem, "帮助ToolStripMenuItem");
            // 
            // 关于ToolStripMenuItem
            // 
            this.关于ToolStripMenuItem.Name = "关于ToolStripMenuItem";
            resources.ApplyResources(this.关于ToolStripMenuItem, "关于ToolStripMenuItem");
            // 
            // 延时测试ToolStripMenuItem
            // 
            this.延时测试ToolStripMenuItem.Name = "延时测试ToolStripMenuItem";
            resources.ApplyResources(this.延时测试ToolStripMenuItem, "延时测试ToolStripMenuItem");
            // 
            // panlMain
            // 
            this.panlMain.Controls.Add(this.splitMain);
            resources.ApplyResources(this.panlMain, "panlMain");
            this.panlMain.Name = "panlMain";
            // 
            // dataGridViewTextBoxColumn7
            // 
            this.dataGridViewTextBoxColumn7.DataPropertyName = "ExchangeID";
            resources.ApplyResources(this.dataGridViewTextBoxColumn7, "dataGridViewTextBoxColumn7");
            this.dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
            // 
            // dataGridViewTextBoxColumn8
            // 
            this.dataGridViewTextBoxColumn8.DataPropertyName = "OrderType";
            resources.ApplyResources(this.dataGridViewTextBoxColumn8, "dataGridViewTextBoxColumn8");
            this.dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
            // 
            // dataGridViewTextBoxColumn9
            // 
            this.dataGridViewTextBoxColumn9.DataPropertyName = "Direction";
            resources.ApplyResources(this.dataGridViewTextBoxColumn9, "dataGridViewTextBoxColumn9");
            this.dataGridViewTextBoxColumn9.Name = "dataGridViewTextBoxColumn9";
            // 
            // dataGridViewTextBoxColumn10
            // 
            this.dataGridViewTextBoxColumn10.DataPropertyName = "Flag";
            resources.ApplyResources(this.dataGridViewTextBoxColumn10, "dataGridViewTextBoxColumn10");
            this.dataGridViewTextBoxColumn10.Name = "dataGridViewTextBoxColumn10";
            // 
            // dataGridViewTextBoxColumn11
            // 
            this.dataGridViewTextBoxColumn11.DataPropertyName = "ExchangeID";
            resources.ApplyResources(this.dataGridViewTextBoxColumn11, "dataGridViewTextBoxColumn11");
            this.dataGridViewTextBoxColumn11.Name = "dataGridViewTextBoxColumn11";
            // 
            // dataGridViewTextBoxColumn12
            // 
            this.dataGridViewTextBoxColumn12.DataPropertyName = "Direction";
            dataGridViewCellStyle7.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleLeft;
            dataGridViewCellStyle7.ForeColor = System.Drawing.Color.Red;
            this.dataGridViewTextBoxColumn12.DefaultCellStyle = dataGridViewCellStyle7;
            resources.ApplyResources(this.dataGridViewTextBoxColumn12, "dataGridViewTextBoxColumn12");
            this.dataGridViewTextBoxColumn12.Name = "dataGridViewTextBoxColumn12";
            // 
            // dataGridViewTextBoxColumn13
            // 
            this.dataGridViewTextBoxColumn13.DataPropertyName = "Flag";
            resources.ApplyResources(this.dataGridViewTextBoxColumn13, "dataGridViewTextBoxColumn13");
            this.dataGridViewTextBoxColumn13.Name = "dataGridViewTextBoxColumn13";
            // 
            // instrumentIDDataGridViewTextBoxColumn1
            // 
            this.instrumentIDDataGridViewTextBoxColumn1.DataPropertyName = "InstrumentID";
            resources.ApplyResources(this.instrumentIDDataGridViewTextBoxColumn1, "instrumentIDDataGridViewTextBoxColumn1");
            this.instrumentIDDataGridViewTextBoxColumn1.Name = "instrumentIDDataGridViewTextBoxColumn1";
            this.instrumentIDDataGridViewTextBoxColumn1.ReadOnly = true;
            // 
            // instrumentNameDataGridViewTextBoxColumn
            // 
            this.instrumentNameDataGridViewTextBoxColumn.DataPropertyName = "InstrumentName";
            resources.ApplyResources(this.instrumentNameDataGridViewTextBoxColumn, "instrumentNameDataGridViewTextBoxColumn");
            this.instrumentNameDataGridViewTextBoxColumn.Name = "instrumentNameDataGridViewTextBoxColumn";
            this.instrumentNameDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // latestPriceDataGridViewTextBoxColumn
            // 
            this.latestPriceDataGridViewTextBoxColumn.DataPropertyName = "LatestPrice";
            resources.ApplyResources(this.latestPriceDataGridViewTextBoxColumn, "latestPriceDataGridViewTextBoxColumn");
            this.latestPriceDataGridViewTextBoxColumn.Name = "latestPriceDataGridViewTextBoxColumn";
            this.latestPriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // openPriceDataGridViewTextBoxColumn
            // 
            this.openPriceDataGridViewTextBoxColumn.DataPropertyName = "OpenPrice";
            resources.ApplyResources(this.openPriceDataGridViewTextBoxColumn, "openPriceDataGridViewTextBoxColumn");
            this.openPriceDataGridViewTextBoxColumn.Name = "openPriceDataGridViewTextBoxColumn";
            this.openPriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // highestPriceDataGridViewTextBoxColumn
            // 
            this.highestPriceDataGridViewTextBoxColumn.DataPropertyName = "HighestPrice";
            resources.ApplyResources(this.highestPriceDataGridViewTextBoxColumn, "highestPriceDataGridViewTextBoxColumn");
            this.highestPriceDataGridViewTextBoxColumn.Name = "highestPriceDataGridViewTextBoxColumn";
            this.highestPriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // lowestPriceDataGridViewTextBoxColumn
            // 
            this.lowestPriceDataGridViewTextBoxColumn.DataPropertyName = "LowestPrice";
            resources.ApplyResources(this.lowestPriceDataGridViewTextBoxColumn, "lowestPriceDataGridViewTextBoxColumn");
            this.lowestPriceDataGridViewTextBoxColumn.Name = "lowestPriceDataGridViewTextBoxColumn";
            this.lowestPriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // volumeDataGridViewTextBoxColumn3
            // 
            this.volumeDataGridViewTextBoxColumn3.DataPropertyName = "Volume";
            resources.ApplyResources(this.volumeDataGridViewTextBoxColumn3, "volumeDataGridViewTextBoxColumn3");
            this.volumeDataGridViewTextBoxColumn3.Name = "volumeDataGridViewTextBoxColumn3";
            this.volumeDataGridViewTextBoxColumn3.ReadOnly = true;
            // 
            // closePriceDataGridViewTextBoxColumn
            // 
            this.closePriceDataGridViewTextBoxColumn.DataPropertyName = "ClosePrice";
            resources.ApplyResources(this.closePriceDataGridViewTextBoxColumn, "closePriceDataGridViewTextBoxColumn");
            this.closePriceDataGridViewTextBoxColumn.Name = "closePriceDataGridViewTextBoxColumn";
            this.closePriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // exchangeIDDataGridViewTextBoxColumn1
            // 
            this.exchangeIDDataGridViewTextBoxColumn1.DataPropertyName = "ExchangeID";
            resources.ApplyResources(this.exchangeIDDataGridViewTextBoxColumn1, "exchangeIDDataGridViewTextBoxColumn1");
            this.exchangeIDDataGridViewTextBoxColumn1.Name = "exchangeIDDataGridViewTextBoxColumn1";
            this.exchangeIDDataGridViewTextBoxColumn1.ReadOnly = true;
            // 
            // topLimitPriceDataGridViewTextBoxColumn
            // 
            this.topLimitPriceDataGridViewTextBoxColumn.DataPropertyName = "TopLimitPrice";
            resources.ApplyResources(this.topLimitPriceDataGridViewTextBoxColumn, "topLimitPriceDataGridViewTextBoxColumn");
            this.topLimitPriceDataGridViewTextBoxColumn.Name = "topLimitPriceDataGridViewTextBoxColumn";
            this.topLimitPriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // bottomLimitPriceDataGridViewTextBoxColumn
            // 
            this.bottomLimitPriceDataGridViewTextBoxColumn.DataPropertyName = "BottomLimitPrice";
            resources.ApplyResources(this.bottomLimitPriceDataGridViewTextBoxColumn, "bottomLimitPriceDataGridViewTextBoxColumn");
            this.bottomLimitPriceDataGridViewTextBoxColumn.Name = "bottomLimitPriceDataGridViewTextBoxColumn";
            this.bottomLimitPriceDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // MainForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoValidate = System.Windows.Forms.AutoValidate.Disable;
            this.Controls.Add(this.panlMain);
            this.Controls.Add(this.menuMain);
            this.Controls.Add(this.statusStrip);
            this.DoubleBuffered = true;
            this.MainMenuStrip = this.menuMain;
            this.Name = "MainForm";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainForm_FormClosing);
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.splitMain.Panel1.ResumeLayout(false);
            this.splitMain.Panel2.ResumeLayout(false);
            this.splitMain.Panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.splitMain)).EndInit();
            this.splitMain.ResumeLayout(false);
            this.tabExchange.ResumeLayout(false);
            this.contmenuTabExchange.ResumeLayout(false);
            this.tabPageAll.ResumeLayout(false);
            this.splitMarket.Panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.splitMarket)).EndInit();
            this.splitMarket.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvwMarket)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.marketsBindingSource)).EndInit();
            this.tbpanlOrderInfo.ResumeLayout(false);
            this.tbpanlOrderInfo.PerformLayout();
            this.tabOrders.ResumeLayout(false);
            this.tabPageAllOrders.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvwOrders)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.ordersBindingSource)).EndInit();
            this.tabPageHisOrders.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvwPositions)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.positionsBindingSource)).EndInit();
            this.tabPageCodes.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvwInstruments)).EndInit();
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
        private System.Windows.Forms.ContextMenuStrip contmenuTabExchange;
        private System.Windows.Forms.ToolStripMenuItem 切换显示ToolStripMenuItem;
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
        private System.Windows.Forms.ToolStripMenuItem 设置ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 开市自动单设置ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 延时测试ToolStripMenuItem;
        private System.Windows.Forms.SplitContainer splitMain;
        private System.Windows.Forms.TabControl tabExchange;
        private System.Windows.Forms.TabPage tabPageDCE;
        private System.Windows.Forms.TabPage tabPageSHFE;
        private System.Windows.Forms.TabPage tabPageCFFE;
        private System.Windows.Forms.TabPage tabPageZCE;
        private System.Windows.Forms.TabPage tabUserDefine;
        private System.Windows.Forms.TableLayoutPanel tbpanlOrderInfo;
        private System.Windows.Forms.TabControl tabOrders;
        private System.Windows.Forms.TabPage tabPageAllOrders;
        private System.Windows.Forms.TabPage tabPageHisOrders;
        private System.Windows.Forms.TabPage tabPageCodes;
        private System.Windows.Forms.FlowLayoutPanel flpnelInfo;
        private System.Windows.Forms.Label lbAccountInfo;
        private System.Windows.Forms.Label lbRightText;
        private System.Windows.Forms.Label lbRight;
        private System.Windows.Forms.Label lbAvailableText;
        private System.Windows.Forms.Label lbAvailable;
        private System.Windows.Forms.FlowLayoutPanel flpanlOrder;
        private System.Windows.Forms.TableLayoutPanel tbpanlOrder;
        private System.Windows.Forms.Label lbInstrument;
        private System.Windows.Forms.Label lbDirection;
        private System.Windows.Forms.Label lbAction;
        private System.Windows.Forms.Label lbPrice;
        private System.Windows.Forms.Label lbVolume;
        private System.Windows.Forms.TextBox txtInstrumentID;
        private System.Windows.Forms.NumericUpDown numPrice;
        private System.Windows.Forms.NumericUpDown numVolume;
        private System.Windows.Forms.TableLayoutPanel tbpanlOpenClose;
        private System.Windows.Forms.RadioButton rdoOpen;
        private System.Windows.Forms.RadioButton rdoClose;
        private System.Windows.Forms.TableLayoutPanel tbpanlBuySell;
        private System.Windows.Forms.RadioButton rdoBuy;
        private System.Windows.Forms.RadioButton rdoSell;
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
        private System.Windows.Forms.Panel panlMain;
        private System.Windows.Forms.TabPage tabPageAll;
        private System.Windows.Forms.DataGridView dgvwOrders;
        private System.Windows.Forms.DataGridView dgvwInstruments;
        private System.Windows.Forms.SplitContainer splitMarket;
        private System.Windows.Forms.DataGridView dgvwMarket;
        private System.Windows.Forms.BindingSource positionsBindingSource;
        private System.Windows.Forms.BindingSource marketsBindingSource;
        private System.Windows.Forms.BindingSource ordersBindingSource;
        private System.Windows.Forms.DataGridViewTextBoxColumn exchangeIDDataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn orderSysIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn instrumentIDDataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn directionDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn limitPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn volumeDataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn orderTypeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn flagDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn userIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn orderLocalIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn investorIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn volumeDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn7;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn8;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn9;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn10;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn11;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn12;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn13;
        private System.Windows.Forms.DataGridViewTextBoxColumn posExchangeID;
        private System.Windows.Forms.DataGridViewTextBoxColumn posInstrumentID;
        private System.Windows.Forms.DataGridViewTextBoxColumn posDirection;
        private System.Windows.Forms.DataGridViewTextBoxColumn posVolumeAll;
        private System.Windows.Forms.DataGridViewTextBoxColumn posPositionPrice;
        private System.Windows.Forms.DataGridViewTextBoxColumn posVolumeToday;
        private System.Windows.Forms.DataGridViewTextBoxColumn posVolumeYestoday;
        private System.Windows.Forms.DataGridViewTextBoxColumn posFlag;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn orderStatusDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn instrumentIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private System.Windows.Forms.DataGridViewTextBoxColumn matchedPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn directionDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn operationDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn volumeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn matchedVolumeDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private System.Windows.Forms.DataGridViewTextBoxColumn exchangeIDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private System.Windows.Forms.DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private System.Windows.Forms.DataGridViewTextBoxColumn flagDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridView dgvwPositions;
        private System.Windows.Forms.DataGridViewTextBoxColumn instrumentIDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn instrumentNameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn latestPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn openPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn highestPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn lowestPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn volumeDataGridViewTextBoxColumn3;
        private System.Windows.Forms.DataGridViewTextBoxColumn closePriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn exchangeIDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn topLimitPriceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn bottomLimitPriceDataGridViewTextBoxColumn;
    }
}

