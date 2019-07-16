using RestaurantDB;
using RestaurantDB.DB_jun;
using System;
using System.Windows.Forms;

namespace RestaurantFinder
{
    public partial class ReservationForm : Form
    {
        public int ReservationId { get; private set; }
        public ReservationForm(string storeName = null)
        {
            InitializeComponent();
            txbStoreName.Text = storeName;
        }

        public void UpdateMode(Reservation reservation)
        {
            txbStoreName.Text = reservation.StoreName;
            txbReservationName.Text = reservation.Name;
            txbPhoneNumber.Text = reservation.PhoneNumber;
            txbNumberOfPeople.Text = reservation.NumberOfPeople.ToString();
            ReservationOn.Value = reservation.ReservationOn;
            ReservationId = reservation.ReservationId;

            btnMadeReservation.Text = "변경";
        }

        private void BtnMadeReservation_Click(object sender, EventArgs e)
        {
            int NumOfPeople;

            if (string.IsNullOrEmpty(txbPhoneNumber.Text) == true)
            {
                MessageBox.Show("전화번호를 입력해주세요!", "경고", MessageBoxButtons.OK);
                return;
            }
            else if (int.TryParse(txbNumberOfPeople.Text, out NumOfPeople) == false)
            {
                MessageBox.Show("숫자만 입력하세요", "경고", MessageBoxButtons.OK);
                return;
            }


            Reservation reservation = new Reservation();


            reservation.ReservationId = ReservationId;
            reservation.StoreId = DB.Store.FindStoreId(txbStoreName.Text);
            reservation.Name = txbReservationName.Text;
            reservation.PhoneNumber = txbPhoneNumber.Text;
            reservation.ReservationOn = ReservationOn.Value;
            reservation.NumberOfPeople = NumOfPeople;


            if (DB.Reservation.InsertOrUpdate(reservation) == true)
            {
                if (MessageBox.Show("성공") == DialogResult.OK)
                    Dispose();
            }
            else
                MessageBox.Show("실패");
        }

        private void BtnCancel_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void ReservationForm_Load(object sender, EventArgs e)
        {
            ReservationOn.MinDate = DateTime.Now;
        }
    }
}
