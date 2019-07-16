using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using UserControls.Properties;
using System.Globalization;
using System.Collections;
using RestaurantDB.DB_jun;
using RestaurantDB;

namespace UserControls
{
    public partial class ucsChooseLocation : UserControl
    {
        public ucsChooseLocation()
        {
            InitializeComponent();
        }
        public List<Button> buttons { get; set; }
        public List<MapsData> Maps { get; set; }
        public void BitmapNButtonsInit()
        {
            buttons = new List<Button>();

            foreach (var item in Controls)
            {
                if (item.GetType() == typeof(Button))
                    buttons.Add(item as Button);
            }
        }

        private void UcsChooseLocation_Load(object sender, EventArgs e)
        {
            if (!DesignMode)
            {
                BitmapNButtonsInit();
                buttons.ForEach(x => x.MouseEnter += OnMouseEnter);
                buttons.ForEach(x => x.MouseLeave += OnMouseLeave);
                buttons.ForEach(x => x.Click += OnButtonClick);

                pictureBox.Image = Resources.전국지도;

                Maps = Resources.ResourceManager
                           .GetResourceSet(CultureInfo.CurrentCulture, true, true)
                           .Cast<DictionaryEntry>()
                           .Where(x => x.Value.GetType() == typeof(Bitmap))
                           .Select(x => new MapsData
                           {
                               Name = x.Key.ToString(),
                               Image = (Bitmap)x.Value
                           })
                           .ToList();
            }
        }

        private void OnMouseEnter(object sender, EventArgs e)
        {
            Button button = sender as Button;

            foreach (var map in Maps)
            {
                if (map.Name == button.Text)
                    pictureBox.Image = map.Image;
            }
        }

        private void OnMouseLeave(object sender, EventArgs e)
        {
            pictureBox.Image = Resources.전국지도;
        }

        private bool buttonWasClicked = false;

        private void OnButtonClick(object sender, EventArgs e)
        {
            Button button = sender as Button;

            buttonWasClicked = true;

            foreach (var map in Maps)
            {
                if (button.Text == map.Name && buttonWasClicked)
                {
                    pictureBox.Image = map.Image;
                    buttons.ForEach(x => x.MouseEnter -= OnMouseEnter);
                    buttons.ForEach(x => x.MouseLeave -= OnMouseLeave);
                }
            }

            SearchConditions.Condition.StateId = DB.State.FindFirstStateId(button.Text);

            _OnClick();
        }

        private void PictureBox_Click(object sender, EventArgs e)
        {
            pictureBox.Image = Resources.전국지도;
            buttons.ForEach(x => x.MouseEnter += OnMouseEnter);
            buttons.ForEach(x => x.MouseLeave += OnMouseLeave);
        }


        #region OnClickEvent
        public event Action<object> OnClickEventHandler;
        protected virtual void _OnClick()
        {
            if (OnClickEventHandler != null)
                OnClickEventHandler(this);
        }
        #endregion
    }



}
