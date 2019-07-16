using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using RestaurantDB.DB_jun;
using RestaurantDB;

namespace UserControls
{
    public partial class uscCheckReservationGrid : UserControl
    {
        public uscCheckReservationGrid()
        {
            InitializeComponent();
        }

        public void SearchedReservation(string phoneNumber)
        {
            if (!DesignMode)
            {
                var list = DB.Reservation.GetReservationList(phoneNumber);
                bdsCheckReservation.DataSource = list;
            }
        }


        private void DataGridView1_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            Reservation reservation = dataGridView1.CurrentRow.DataBoundItem as Reservation;

            ReservationUpdate(reservation);
        }

        #region ReservationUpdateEvent
        public event Action<object, Reservation> OnReservationUpdate;
        protected virtual void ReservationUpdate(Reservation e)
        {
            if (OnReservationUpdate != null)
                OnReservationUpdate(this, e);
        }
        private Reservation ReservationUpdate()
        {
            Reservation args = new Reservation();
            ReservationUpdate(args);

            return args;
        }
        #endregion

        private void DataGridView1_KeyDown(object sender, KeyEventArgs e)
        {
            Reservation reservation = dataGridView1.CurrentRow.DataBoundItem as Reservation;
            if (reservation != null && e.KeyCode == Keys.Delete)
                if (MessageBox.Show("삭제하시겠습니까?", "", MessageBoxButtons.YesNo) == DialogResult.Yes)
                    DB.Reservation.Delete(reservation);
        }
    }
}
