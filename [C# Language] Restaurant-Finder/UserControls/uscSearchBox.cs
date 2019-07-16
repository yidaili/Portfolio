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
    public partial class uscSearchBox : UserControl
    {
        public uscSearchBox()
        {
            InitializeComponent();
        }

        private void UscSearchBox_Load(object sender, EventArgs e)
        {
            InitCityCbb();
        }

        public void InitCityCbb()
        {
            if (!DesignMode || SearchConditions.Condition.StateId != 0)
                bdsCity.DataSource = DB.City.GetAllCitiesIn(SearchConditions.Condition.StateId);
        }

        private void BtnSearch_Click(object sender, EventArgs e)
        {
            SearchConditions.Condition.FoodTypeIds.Clear();

            foreach (var item in Controls[0].Controls)
            {
                if (item.GetType() == typeof(CheckBox) && (item as CheckBox).Checked)
                    SearchConditions.Condition.FoodTypeIds.Add(int.Parse((item as CheckBox).Tag.ToString()));
            }

            SearchConditions.Condition.CityId = (int)cbbCity.SelectedValue;

            if (txbKeyword.Text != "")
                SearchConditions.Condition.KeyWord = txbKeyword.Text;
            else
                SearchConditions.Condition.KeyWord = null;

            OnSearchButtonClicked();
        }

        #region SearchButtonClicked
        public event Action<object> SearchButtonHandler;
        protected virtual void OnSearchButtonClicked()
        {
            if (SearchButtonHandler != null)
                SearchButtonHandler(this);
        }
        #endregion
    }
}
