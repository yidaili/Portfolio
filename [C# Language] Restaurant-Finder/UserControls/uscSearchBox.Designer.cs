namespace UserControls
{
    partial class uscSearchBox
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.ckb한식 = new System.Windows.Forms.CheckBox();
            this.ckb패밀리레스토랑 = new System.Windows.Forms.CheckBox();
            this.ckb채식전문점 = new System.Windows.Forms.CheckBox();
            this.ckb카페전통찻집 = new System.Windows.Forms.CheckBox();
            this.ckb서양식 = new System.Windows.Forms.CheckBox();
            this.ckb일식 = new System.Windows.Forms.CheckBox();
            this.ckb이색음식점 = new System.Windows.Forms.CheckBox();
            this.ckb아시아식 = new System.Windows.Forms.CheckBox();
            this.ckb중식 = new System.Windows.Forms.CheckBox();
            this.btnSearch = new System.Windows.Forms.Button();
            this.txbKeyword = new System.Windows.Forms.TextBox();
            this.cbbCity = new System.Windows.Forms.ComboBox();
            this.bdsCity = new System.Windows.Forms.BindingSource(this.components);
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.bdsCity)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.ckb한식);
            this.groupBox1.Controls.Add(this.ckb패밀리레스토랑);
            this.groupBox1.Controls.Add(this.ckb채식전문점);
            this.groupBox1.Controls.Add(this.ckb카페전통찻집);
            this.groupBox1.Controls.Add(this.ckb서양식);
            this.groupBox1.Controls.Add(this.ckb일식);
            this.groupBox1.Controls.Add(this.ckb이색음식점);
            this.groupBox1.Controls.Add(this.ckb아시아식);
            this.groupBox1.Controls.Add(this.ckb중식);
            this.groupBox1.Controls.Add(this.btnSearch);
            this.groupBox1.Controls.Add(this.txbKeyword);
            this.groupBox1.Controls.Add(this.cbbCity);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(706, 115);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "검색 조건";
            // 
            // ckb한식
            // 
            this.ckb한식.AutoSize = true;
            this.ckb한식.Location = new System.Drawing.Point(101, 69);
            this.ckb한식.Name = "ckb한식";
            this.ckb한식.Size = new System.Drawing.Size(48, 16);
            this.ckb한식.TabIndex = 6;
            this.ckb한식.Tag = "6";
            this.ckb한식.Text = "한식";
            this.ckb한식.UseVisualStyleBackColor = true;
            // 
            // ckb패밀리레스토랑
            // 
            this.ckb패밀리레스토랑.AutoSize = true;
            this.ckb패밀리레스토랑.Location = new System.Drawing.Point(299, 91);
            this.ckb패밀리레스토랑.Name = "ckb패밀리레스토랑";
            this.ckb패밀리레스토랑.Size = new System.Drawing.Size(108, 16);
            this.ckb패밀리레스토랑.TabIndex = 5;
            this.ckb패밀리레스토랑.Tag = "5";
            this.ckb패밀리레스토랑.Text = "패밀리레스토랑";
            this.ckb패밀리레스토랑.UseVisualStyleBackColor = true;
            // 
            // ckb채식전문점
            // 
            this.ckb채식전문점.AutoSize = true;
            this.ckb채식전문점.Location = new System.Drawing.Point(101, 91);
            this.ckb채식전문점.Name = "ckb채식전문점";
            this.ckb채식전문점.Size = new System.Drawing.Size(84, 16);
            this.ckb채식전문점.TabIndex = 5;
            this.ckb채식전문점.Tag = "7";
            this.ckb채식전문점.Text = "채식전문점";
            this.ckb채식전문점.UseVisualStyleBackColor = true;
            // 
            // ckb카페전통찻집
            // 
            this.ckb카페전통찻집.AutoSize = true;
            this.ckb카페전통찻집.Location = new System.Drawing.Point(191, 91);
            this.ckb카페전통찻집.Name = "ckb카페전통찻집";
            this.ckb카페전통찻집.Size = new System.Drawing.Size(102, 16);
            this.ckb카페전통찻집.TabIndex = 5;
            this.ckb카페전통찻집.Tag = "8";
            this.ckb카페전통찻집.Text = "카페/전통찻집";
            this.ckb카페전통찻집.UseVisualStyleBackColor = true;
            // 
            // ckb서양식
            // 
            this.ckb서양식.AutoSize = true;
            this.ckb서양식.Location = new System.Drawing.Point(266, 69);
            this.ckb서양식.Name = "ckb서양식";
            this.ckb서양식.Size = new System.Drawing.Size(60, 16);
            this.ckb서양식.TabIndex = 5;
            this.ckb서양식.Tag = "4";
            this.ckb서양식.Text = "서양식";
            this.ckb서양식.UseVisualStyleBackColor = true;
            // 
            // ckb일식
            // 
            this.ckb일식.AutoSize = true;
            this.ckb일식.Location = new System.Drawing.Point(211, 69);
            this.ckb일식.Name = "ckb일식";
            this.ckb일식.Size = new System.Drawing.Size(48, 16);
            this.ckb일식.TabIndex = 5;
            this.ckb일식.Tag = "3";
            this.ckb일식.Text = "일식";
            this.ckb일식.UseVisualStyleBackColor = true;
            // 
            // ckb이색음식점
            // 
            this.ckb이색음식점.AutoSize = true;
            this.ckb이색음식점.Location = new System.Drawing.Point(412, 69);
            this.ckb이색음식점.Name = "ckb이색음식점";
            this.ckb이색음식점.Size = new System.Drawing.Size(84, 16);
            this.ckb이색음식점.TabIndex = 5;
            this.ckb이색음식점.Tag = "7";
            this.ckb이색음식점.Text = "이색음식점";
            this.ckb이색음식점.UseVisualStyleBackColor = true;
            // 
            // ckb아시아식
            // 
            this.ckb아시아식.AutoSize = true;
            this.ckb아시아식.Location = new System.Drawing.Point(333, 69);
            this.ckb아시아식.Name = "ckb아시아식";
            this.ckb아시아식.Size = new System.Drawing.Size(72, 16);
            this.ckb아시아식.TabIndex = 5;
            this.ckb아시아식.Tag = "2";
            this.ckb아시아식.Text = "아시아식";
            this.ckb아시아식.UseVisualStyleBackColor = true;
            // 
            // ckb중식
            // 
            this.ckb중식.AutoSize = true;
            this.ckb중식.Location = new System.Drawing.Point(156, 69);
            this.ckb중식.Name = "ckb중식";
            this.ckb중식.Size = new System.Drawing.Size(48, 16);
            this.ckb중식.TabIndex = 5;
            this.ckb중식.Tag = "9";
            this.ckb중식.Text = "중식";
            this.ckb중식.UseVisualStyleBackColor = true;
            // 
            // btnSearch
            // 
            this.btnSearch.Location = new System.Drawing.Point(465, 28);
            this.btnSearch.Name = "btnSearch";
            this.btnSearch.Size = new System.Drawing.Size(99, 23);
            this.btnSearch.TabIndex = 4;
            this.btnSearch.Text = "검색";
            this.btnSearch.UseVisualStyleBackColor = true;
            this.btnSearch.Click += new System.EventHandler(this.BtnSearch_Click);
            // 
            // txbKeyword
            // 
            this.txbKeyword.Location = new System.Drawing.Point(292, 30);
            this.txbKeyword.Name = "txbKeyword";
            this.txbKeyword.Size = new System.Drawing.Size(148, 21);
            this.txbKeyword.TabIndex = 3;
            // 
            // cbbCity
            // 
            this.cbbCity.DataSource = this.bdsCity;
            this.cbbCity.DisplayMember = "Name";
            this.cbbCity.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbbCity.FormattingEnabled = true;
            this.cbbCity.Location = new System.Drawing.Point(98, 32);
            this.cbbCity.Name = "cbbCity";
            this.cbbCity.Size = new System.Drawing.Size(111, 20);
            this.cbbCity.TabIndex = 2;
            this.cbbCity.ValueMember = "CityId";
            // 
            // bdsCity
            // 
            this.bdsCity.DataSource = typeof(RestaurantDB.ResultFormat.CityListFormat);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(233, 35);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 1;
            this.label3.Text = "키워드 : ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 65);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(69, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "음식 종류 : ";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(19, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "시/군/구 : ";
            // 
            // uscSearchBox
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.groupBox1);
            this.Name = "uscSearchBox";
            this.Size = new System.Drawing.Size(706, 115);
            this.Load += new System.EventHandler(this.UscSearchBox_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.bdsCity)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.CheckBox ckb한식;
        private System.Windows.Forms.CheckBox ckb패밀리레스토랑;
        private System.Windows.Forms.CheckBox ckb채식전문점;
        private System.Windows.Forms.CheckBox ckb카페전통찻집;
        private System.Windows.Forms.CheckBox ckb서양식;
        private System.Windows.Forms.CheckBox ckb일식;
        private System.Windows.Forms.CheckBox ckb이색음식점;
        private System.Windows.Forms.CheckBox ckb아시아식;
        private System.Windows.Forms.CheckBox ckb중식;
        private System.Windows.Forms.Button btnSearch;
        private System.Windows.Forms.TextBox txbKeyword;
        private System.Windows.Forms.ComboBox cbbCity;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.BindingSource bdsCity;
    }
}
