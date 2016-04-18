namespace ProgramTradeModules
{
    partial class OrderViewer
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
            this.gdvwOrders = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.gdvwOrders)).BeginInit();
            this.SuspendLayout();
            // 
            // gdvwOrders
            // 
            this.gdvwOrders.AllowUserToResizeRows = false;
            this.gdvwOrders.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.AllCells;
            this.gdvwOrders.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gdvwOrders.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gdvwOrders.Location = new System.Drawing.Point(0, 0);
            this.gdvwOrders.Name = "gdvwOrders";
            this.gdvwOrders.RowHeadersWidth = 20;
            this.gdvwOrders.RowTemplate.Height = 23;
            this.gdvwOrders.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.gdvwOrders.Size = new System.Drawing.Size(695, 349);
            this.gdvwOrders.TabIndex = 0;
            this.gdvwOrders.CellDoubleClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gdvwOrders_CellDoubleClick);
            // 
            // OrderViewer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.gdvwOrders);
            this.Name = "OrderViewer";
            this.Size = new System.Drawing.Size(695, 349);
            this.BackColorChanged += new System.EventHandler(this.OrderViewer_BackColorChanged);
            ((System.ComponentModel.ISupportInitialize)(this.gdvwOrders)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView gdvwOrders;
    }
}
