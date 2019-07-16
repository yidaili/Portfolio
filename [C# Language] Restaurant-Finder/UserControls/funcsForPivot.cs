using RestaurantDB;
using RestaurantDB.DB_jun;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UserControls
{
    public partial class uscResultGrid
    {
        public void PivotTable()
        {
            if (!DesignMode)
            {
                DataTable dataTable = new DataTable();
                
                RestaurantEntities context = new RestaurantEntities();

                var foodTypes = context.FoodTypes.Select(x => x.Name).ToList();
                var query = from x in context.Stores
                            where x.StateId == SearchConditions.Condition.StateId                       //시.도 필터
                            group x by x.City.Name into nameGroup
                            select new
                            {
                                Name = nameGroup.Key,
                                Values = from foodType in foodTypes
                                         join ng in nameGroup
                                         on foodType equals ng.FoodType.Name into foodTypeGroup
                                         select new
                                         {
                                             Column = foodType,
                                             Value = foodTypeGroup.Any() ? foodTypeGroup.Count().ToString() : "0"
                                         }
                            };

                dataTable.Columns.Add("음식 통계");
                foreach (var foodType in foodTypes)
                {
                    dataTable.Columns.Add(foodType);
                }

                foreach (var key in query)
                {
                    var row = dataTable.NewRow();
                    var items = key.Values.Select(v => v.Value).ToList();
                    items.Insert(0, key.Name);
                    row.ItemArray = items.ToArray();
                    dataTable.Rows.Add(row);
                }
                context.Dispose();
                gridResult.Columns.Clear();
                gridResult.DataSource = dataTable;
            }
        }
    }
}
