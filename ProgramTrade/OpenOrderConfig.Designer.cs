namespace ProgramTrade
{
    partial class OpenOrderConfig
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(OpenOrderConfig));
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel2 = new System.Windows.Forms.Panel();
            this.gdvwDelayConfig = new System.Windows.Forms.DataGridView();
            this.Exchange = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.LocalTimeDelay = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ToQdpLinkDelay = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.QdpHandleDelay = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ToExchangLinkDelay = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.maskedTextBox1 = new System.Windows.Forms.MaskedTextBox();
            this.tableLayoutPanel1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.gdvwDelayConfig)).BeginInit();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            resources.ApplyResources(this.tableLayoutPanel1, "tableLayoutPanel1");
            this.tableLayoutPanel1.Controls.Add(this.label3, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.label4, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.label5, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.textBox4, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.textBox5, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.label8, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.label9, 2, 2);
            this.tableLayoutPanel1.Controls.Add(this.label6, 2, 3);
            this.tableLayoutPanel1.Controls.Add(this.label2, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.label7, 2, 0);
            this.tableLayoutPanel1.Controls.Add(this.textBox3, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.maskedTextBox1, 1, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // label3
            // 
            resources.ApplyResources(this.label3, "label3");
            this.label3.Name = "label3";
            // 
            // label4
            // 
            resources.ApplyResources(this.label4, "label4");
            this.label4.Name = "label4";
            // 
            // label5
            // 
            resources.ApplyResources(this.label5, "label5");
            this.label5.Name = "label5";
            // 
            // textBox3
            // 
            resources.ApplyResources(this.textBox3, "textBox3");
            this.textBox3.Name = "textBox3";
            // 
            // textBox4
            // 
            resources.ApplyResources(this.textBox4, "textBox4");
            this.textBox4.Name = "textBox4";
            // 
            // textBox5
            // 
            resources.ApplyResources(this.textBox5, "textBox5");
            this.textBox5.Name = "textBox5";
            // 
            // label7
            // 
            resources.ApplyResources(this.label7, "label7");
            this.label7.Name = "label7";
            // 
            // label8
            // 
            resources.ApplyResources(this.label8, "label8");
            this.label8.Name = "label8";
            // 
            // label9
            // 
            resources.ApplyResources(this.label9, "label9");
            this.label9.Name = "label9";
            // 
            // label6
            // 
            resources.ApplyResources(this.label6, "label6");
            this.label6.Name = "label6";
            // 
            // panel1
            // 
            resources.ApplyResources(this.panel1, "panel1");
            this.panel1.Controls.Add(this.tableLayoutPanel1);
            this.panel1.Name = "panel1";
            // 
            // panel2
            // 
            resources.ApplyResources(this.panel2, "panel2");
            this.panel2.Controls.Add(this.gdvwDelayConfig);
            this.panel2.Name = "panel2";
            // 
            // gdvwDelayConfig
            // 
            this.gdvwDelayConfig.AllowUserToAddRows = false;
            this.gdvwDelayConfig.AllowUserToDeleteRows = false;
            this.gdvwDelayConfig.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gdvwDelayConfig.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.Exchange,
            this.LocalTimeDelay,
            this.ToQdpLinkDelay,
            this.QdpHandleDelay,
            this.ToExchangLinkDelay});
            resources.ApplyResources(this.gdvwDelayConfig, "gdvwDelayConfig");
            this.gdvwDelayConfig.Name = "gdvwDelayConfig";
            this.gdvwDelayConfig.ReadOnly = true;
            this.gdvwDelayConfig.RowTemplate.Height = 23;
            this.gdvwDelayConfig.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            // 
            // Exchange
            // 
            this.Exchange.Frozen = true;
            resources.ApplyResources(this.Exchange, "Exchange");
            this.Exchange.Name = "Exchange";
            this.Exchange.ReadOnly = true;
            // 
            // LocalTimeDelay
            // 
            resources.ApplyResources(this.LocalTimeDelay, "LocalTimeDelay");
            this.LocalTimeDelay.Name = "LocalTimeDelay";
            this.LocalTimeDelay.ReadOnly = true;
            // 
            // ToQdpLinkDelay
            // 
            resources.ApplyResources(this.ToQdpLinkDelay, "ToQdpLinkDelay");
            this.ToQdpLinkDelay.Name = "ToQdpLinkDelay";
            this.ToQdpLinkDelay.ReadOnly = true;
            // 
            // QdpHandleDelay
            // 
            resources.ApplyResources(this.QdpHandleDelay, "QdpHandleDelay");
            this.QdpHandleDelay.Name = "QdpHandleDelay";
            this.QdpHandleDelay.ReadOnly = true;
            // 
            // ToExchangLinkDelay
            // 
            resources.ApplyResources(this.ToExchangLinkDelay, "ToExchangLinkDelay");
            this.ToExchangLinkDelay.Name = "ToExchangLinkDelay";
            this.ToExchangLinkDelay.ReadOnly = true;
            // 
            // maskedTextBox1
            // 
            resources.ApplyResources(this.maskedTextBox1, "maskedTextBox1");
            this.maskedTextBox1.Name = "maskedTextBox1";
            // 
            // OpenOrderConfig
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "OpenOrderConfig";
            this.ShowInTaskbar = false;
            this.TopMost = true;
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.gdvwDelayConfig)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.DataGridView gdvwDelayConfig;
        private System.Windows.Forms.DataGridViewTextBoxColumn Exchange;
        private System.Windows.Forms.DataGridViewTextBoxColumn LocalTimeDelay;
        private System.Windows.Forms.DataGridViewTextBoxColumn ToQdpLinkDelay;
        private System.Windows.Forms.DataGridViewTextBoxColumn QdpHandleDelay;
        private System.Windows.Forms.DataGridViewTextBoxColumn ToExchangLinkDelay;
        private System.Windows.Forms.MaskedTextBox maskedTextBox1;
    }
}