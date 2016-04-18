namespace ProgramTradeModules
{
    partial class MarketViewer
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

        #region 组件设计器生成的代码

        /// <summary> 
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.panlMarketDetail = new System.Windows.Forms.Panel();
            this.splitter = new System.Windows.Forms.Splitter();
            this.panlMarketList = new System.Windows.Forms.Panel();
            this.gdvwMarket = new System.Windows.Forms.DataGridView();
            this.panlMarketList.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gdvwMarket)).BeginInit();
            this.SuspendLayout();
            // 
            // panlMarketDetail
            // 
            this.panlMarketDetail.AutoSize = true;
            this.panlMarketDetail.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panlMarketDetail.Dock = System.Windows.Forms.DockStyle.Left;
            this.panlMarketDetail.Location = new System.Drawing.Point(0, 0);
            this.panlMarketDetail.MinimumSize = new System.Drawing.Size(155, 0);
            this.panlMarketDetail.Name = "panlMarketDetail";
            this.panlMarketDetail.Size = new System.Drawing.Size(155, 317);
            this.panlMarketDetail.TabIndex = 2;
            // 
            // splitter
            // 
            this.splitter.Location = new System.Drawing.Point(155, 0);
            this.splitter.MinSize = 3;
            this.splitter.Name = "splitter";
            this.splitter.Size = new System.Drawing.Size(3, 317);
            this.splitter.TabIndex = 3;
            this.splitter.TabStop = false;
            // 
            // panlMarketList
            // 
            this.panlMarketList.AutoSize = true;
            this.panlMarketList.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.panlMarketList.Controls.Add(this.gdvwMarket);
            this.panlMarketList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panlMarketList.Location = new System.Drawing.Point(158, 0);
            this.panlMarketList.Name = "panlMarketList";
            this.panlMarketList.Size = new System.Drawing.Size(625, 317);
            this.panlMarketList.TabIndex = 4;
            // 
            // gdvwMarket
            // 
            this.gdvwMarket.AllowUserToAddRows = false;
            this.gdvwMarket.AllowUserToDeleteRows = false;
            this.gdvwMarket.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gdvwMarket.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gdvwMarket.Location = new System.Drawing.Point(0, 0);
            this.gdvwMarket.Name = "gdvwMarket";
            this.gdvwMarket.ReadOnly = true;
            this.gdvwMarket.RowTemplate.Height = 23;
            this.gdvwMarket.Size = new System.Drawing.Size(625, 317);
            this.gdvwMarket.TabIndex = 2;
            // 
            // MarketViewer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panlMarketList);
            this.Controls.Add(this.splitter);
            this.Controls.Add(this.panlMarketDetail);
            this.Name = "MarketViewer";
            this.Size = new System.Drawing.Size(783, 317);
            this.panlMarketList.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gdvwMarket)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Panel panlMarketDetail;
        private System.Windows.Forms.Splitter splitter;
        private System.Windows.Forms.Panel panlMarketList;
        private System.Windows.Forms.DataGridView gdvwMarket;
    }
}
