namespace RestaurantFinder
{
    partial class ReservationForm
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnCancel = new System.Windows.Forms.Button();
            this.btnMadeReservation = new System.Windows.Forms.Button();
            this.ReservationOn = new System.Windows.Forms.DateTimePicker();
            this.label6 = new System.Windows.Forms.Label();
            this.txbNumberOfPeople = new System.Windows.Forms.TextBox();
            this.txbPhoneNumber = new System.Windows.Forms.TextBox();
            this.txbReservationName = new System.Windows.Forms.TextBox();
            this.txbStoreName = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnCancel);
            this.groupBox1.Controls.Add(this.btnMadeReservation);
            this.groupBox1.Controls.Add(this.ReservationOn);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.txbNumberOfPeople);
            this.groupBox1.Controls.Add(this.txbPhoneNumber);
            this.groupBox1.Controls.Add(this.txbReservationName);
            this.groupBox1.Controls.Add(this.txbStoreName);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Location = new System.Drawing.Point(5, 5);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(334, 280);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "식당 예약";
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(235, 225);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(75, 23);
            this.btnCancel.TabIndex = 12;
            this.btnCancel.Text = "취소";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.BtnCancel_Click);
            // 
            // btnMadeReservation
            // 
            this.btnMadeReservation.Location = new System.Drawing.Point(141, 225);
            this.btnMadeReservation.Name = "btnMadeReservation";
            this.btnMadeReservation.Size = new System.Drawing.Size(75, 23);
            this.btnMadeReservation.TabIndex = 11;
            this.btnMadeReservation.Text = "확인";
            this.btnMadeReservation.UseVisualStyleBackColor = true;
            this.btnMadeReservation.Click += new System.EventHandler(this.BtnMadeReservation_Click);
            // 
            // ReservationOn
            // 
            this.ReservationOn.Location = new System.Drawing.Point(90, 136);
            this.ReservationOn.Name = "ReservationOn";
            this.ReservationOn.Size = new System.Drawing.Size(200, 21);
            this.ReservationOn.TabIndex = 10;
            this.ReservationOn.Value = new System.DateTime(2019, 6, 24, 0, 0, 0, 0);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(293, 178);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(17, 12);
            this.label6.TabIndex = 9;
            this.label6.Text = "명";
            // 
            // txbNumberOfPeople
            // 
            this.txbNumberOfPeople.Location = new System.Drawing.Point(90, 175);
            this.txbNumberOfPeople.Name = "txbNumberOfPeople";
            this.txbNumberOfPeople.Size = new System.Drawing.Size(197, 21);
            this.txbNumberOfPeople.TabIndex = 8;
            // 
            // txbPhoneNumber
            // 
            this.txbPhoneNumber.Location = new System.Drawing.Point(90, 103);
            this.txbPhoneNumber.Name = "txbPhoneNumber";
            this.txbPhoneNumber.Size = new System.Drawing.Size(197, 21);
            this.txbPhoneNumber.TabIndex = 7;
            // 
            // txbReservationName
            // 
            this.txbReservationName.Location = new System.Drawing.Point(90, 67);
            this.txbReservationName.Name = "txbReservationName";
            this.txbReservationName.Size = new System.Drawing.Size(197, 21);
            this.txbReservationName.TabIndex = 6;
            // 
            // txbStoreName
            // 
            this.txbStoreName.Location = new System.Drawing.Point(90, 31);
            this.txbStoreName.Name = "txbStoreName";
            this.txbStoreName.ReadOnly = true;
            this.txbStoreName.Size = new System.Drawing.Size(197, 21);
            this.txbStoreName.TabIndex = 5;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(23, 178);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(61, 12);
            this.label5.TabIndex = 4;
            this.label5.Text = "예약인원 :";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(23, 142);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(61, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "예약일시 :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(23, 106);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(61, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "전화번호 :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(23, 70);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(61, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "예약자명 :";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(35, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "식당명 :";
            // 
            // ReservationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(344, 290);
            this.Controls.Add(this.groupBox1);
            this.Name = "ReservationForm";
            this.Padding = new System.Windows.Forms.Padding(5);
            this.Text = "ReservationForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox txbNumberOfPeople;
        private System.Windows.Forms.TextBox txbPhoneNumber;
        private System.Windows.Forms.TextBox txbReservationName;
        private System.Windows.Forms.TextBox txbStoreName;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.DateTimePicker ReservationOn;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.Button btnMadeReservation;
    }
}