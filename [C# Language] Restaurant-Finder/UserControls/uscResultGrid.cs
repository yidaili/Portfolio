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
    public partial class uscResultGrid : UserControl
    {
        public uscResultGrid()
        {
            InitializeComponent();
        }

        public void Searched()
        {
            if(!DesignMode)
            {
                //추려낸 결과 소스로 이동
                gridResult.Columns.Clear();

                bdsResult.DataSource = DB.Store.GetSearchResult();
                gridResult.DataSource = bdsResult;
                gridResult.Refresh();
                label1.Text = $"총 {DB.Store.GetSearchResult().Count()}개의 검색 결과";
            }
        }

        //셀 더블클릭시 해당 셀의 정보를 핸들러에 넘겨줌
        private void GridResult_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            if (!DesignMode)
            {
                SearchResultData searchResultData = gridResult.CurrentRow.DataBoundItem as SearchResultData;
                if (searchResultData == null)
                    return;

                OnCellDoubleClickd(searchResultData.Name);
            }
        }

        //이벤트 정의
        #region CellDoubleClicked
        public event Action<object, string> CellDoubleClickedHandler;
        protected virtual void OnCellDoubleClickd(string e)
        {
            if (CellDoubleClickedHandler != null)
                CellDoubleClickedHandler(this, e);
        }
        #endregion
    }
}
