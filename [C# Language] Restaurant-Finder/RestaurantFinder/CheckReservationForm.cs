using RestaurantDB;
using RestaurantDB.DB_jun;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RestaurantFinder
{
    public partial class CheckReservationForm : Form
    {
        public CheckReservationForm()
        {
            InitializeComponent();
        }

        private void UscReservationCheckBox1_CheckReservation(object arg1, string arg2)
        {
            uscCheckReservationGrid1.SearchedReservation(arg2);
            uscCheckReservationGrid1.Refresh();
        }

        private void UscCheckReservationGrid1_OnReservationUpdate(object arg1, Reservation reservation)
        {
            ReservationForm reservationForm = new ReservationForm();
            reservationForm.UpdateMode(reservation);
            reservationForm.Show();
        }
    }
}
