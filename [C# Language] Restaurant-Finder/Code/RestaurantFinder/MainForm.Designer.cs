namespace RestaurantFinder
{
    partial class MainForm
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
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.기능ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.예약내역확인ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.종료XToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.정보ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.버전ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.uscResultGrid1 = new UserControls.uscResultGrid();
            this.uscSearchBox1 = new UserControls.uscSearchBox();
            this.ucsChooseLocation1 = new UserControls.ucsChooseLocation();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.기능ToolStripMenuItem,
            this.정보ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1003, 24);
            this.menuStrip1.TabIndex = 2;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 기능ToolStripMenuItem
            // 
            this.기능ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.예약내역확인ToolStripMenuItem,
            this.종료XToolStripMenuItem});
            this.기능ToolStripMenuItem.Name = "기능ToolStripMenuItem";
            this.기능ToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.기능ToolStripMenuItem.Text = "기능";
            // 
            // 예약내역확인ToolStripMenuItem
            // 
            this.예약내역확인ToolStripMenuItem.Name = "예약내역확인ToolStripMenuItem";
            this.예약내역확인ToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.예약내역확인ToolStripMenuItem.Text = "예약 내역 확인";
            this.예약내역확인ToolStripMenuItem.Click += new System.EventHandler(this.예약내역확인ToolStripMenuItem_Click);
            // 
            // 종료XToolStripMenuItem
            // 
            this.종료XToolStripMenuItem.Name = "종료XToolStripMenuItem";
            this.종료XToolStripMenuItem.Size = new System.Drawing.Size(154, 22);
            this.종료XToolStripMenuItem.Text = "종료(&X)";
            this.종료XToolStripMenuItem.Click += new System.EventHandler(this.종료XToolStripMenuItem_Click);
            // 
            // 정보ToolStripMenuItem
            // 
            this.정보ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.버전ToolStripMenuItem});
            this.정보ToolStripMenuItem.Name = "정보ToolStripMenuItem";
            this.정보ToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.정보ToolStripMenuItem.Text = "정보";
            // 
            // 버전ToolStripMenuItem
            // 
            this.버전ToolStripMenuItem.Name = "버전ToolStripMenuItem";
            this.버전ToolStripMenuItem.Size = new System.Drawing.Size(98, 22);
            this.버전ToolStripMenuItem.Text = "버전";
            // 
            // uscResultGrid1
            // 
            this.uscResultGrid1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.uscResultGrid1.Location = new System.Drawing.Point(426, 151);
            this.uscResultGrid1.Name = "uscResultGrid1";
            this.uscResultGrid1.Size = new System.Drawing.Size(577, 386);
            this.uscResultGrid1.TabIndex = 1;
            this.uscResultGrid1.CellDoubleClickedHandler += new System.Action<object, string>(this.UscResultGrid1_CellDoubleClickedHandler_1);
            // 
            // uscSearchBox1
            // 
            this.uscSearchBox1.AutoSize = true;
            this.uscSearchBox1.Location = new System.Drawing.Point(426, 27);
            this.uscSearchBox1.Name = "uscSearchBox1";
            this.uscSearchBox1.Padding = new System.Windows.Forms.Padding(0, 24, 0, 0);
            this.uscSearchBox1.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.uscSearchBox1.Size = new System.Drawing.Size(709, 118);
            this.uscSearchBox1.TabIndex = 0;
            this.uscSearchBox1.SearchButtonHandler += new System.Action<object>(this.UscSearchBox1_SearchButtonHandler);
            // 
            // ucsChooseLocation1
            // 
            this.ucsChooseLocation1.buttons = null;
            this.ucsChooseLocation1.Location = new System.Drawing.Point(-1, 1);
            this.ucsChooseLocation1.Maps = null;
            this.ucsChooseLocation1.Name = "ucsChooseLocation1";
            this.ucsChooseLocation1.Padding = new System.Windows.Forms.Padding(0, 24, 0, 0);
            this.ucsChooseLocation1.Size = new System.Drawing.Size(421, 536);
            this.ucsChooseLocation1.TabIndex = 0;
            this.ucsChooseLocation1.OnClickEventHandler += new System.Action<object>(this.UcsChooseLocation1_OnClickEventHandler);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1003, 549);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.uscResultGrid1);
            this.Controls.Add(this.uscSearchBox1);
            this.Controls.Add(this.ucsChooseLocation1);
            this.MainMenuStrip = this.menuStrip1;
            this.MinimumSize = new System.Drawing.Size(1019, 587);
            this.Name = "MainForm";
            this.Text = "음식점 찾기";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.MainForm_KeyDown);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private UserControls.ucsChooseLocation ucsChooseLocation1;

        private UserControls.uscSearchBox uscSearchBox1;
        private UserControls.uscResultGrid uscResultGrid1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 기능ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 예약내역확인ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 종료XToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 정보ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 버전ToolStripMenuItem;
    }
}