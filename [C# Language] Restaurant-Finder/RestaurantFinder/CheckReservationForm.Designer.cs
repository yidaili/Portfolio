namespace RestaurantFinder
{
    partial class CheckReservationForm
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
            this.uscReservationCheckBox1 = new UserControls.uscReservationCheckBox();
            this.uscCheckReservationGrid1 = new UserControls.uscCheckReservationGrid();
            this.SuspendLayout();
            // 
            // uscReservationCheckBox1
            // 
            this.uscReservationCheckBox1.Dock = System.Windows.Forms.DockStyle.Top;
            this.uscReservationCheckBox1.Location = new System.Drawing.Point(0, 0);
            this.uscReservationCheckBox1.Name = "uscReservationCheckBox1";
            this.uscReservationCheckBox1.Size = new System.Drawing.Size(490, 77);
            this.uscReservationCheckBox1.TabIndex = 0;
            this.uscReservationCheckBox1.CheckReservation += new System.Action<object, string>(this.UscReservationCheckBox1_CheckReservation);
            // 
            // uscCheckReservationGrid1
            // 
            this.uscCheckReservationGrid1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.uscCheckReservationGrid1.Location = new System.Drawing.Point(0, 77);
            this.uscCheckReservationGrid1.Name = "uscCheckReservationGrid1";
            this.uscCheckReservationGrid1.Size = new System.Drawing.Size(490, 342);
            this.uscCheckReservationGrid1.TabIndex = 1;
            this.uscCheckReservationGrid1.OnReservationUpdate += new System.Action<object, RestaurantDB.Reservation>(this.UscCheckReservationGrid1_OnReservationUpdate);
            // 
            // CheckReservationForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(490, 419);
            this.Controls.Add(this.uscCheckReservationGrid1);
            this.Controls.Add(this.uscReservationCheckBox1);
            this.Name = "CheckReservationForm";
            this.Text = "예약 확인";
            this.ResumeLayout(false);

        }

        #endregion

        private UserControls.uscReservationCheckBox uscReservationCheckBox1;
        private UserControls.uscCheckReservationGrid uscCheckReservationGrid1;
    }
}