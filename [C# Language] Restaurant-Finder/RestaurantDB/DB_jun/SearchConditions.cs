using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantDB.DB_jun
{
    public class SearchConditions
    {
        private static SearchConditions _condition = null;

        private SearchConditions()
        {
            FoodTypeIds = new List<int>();
            KeyWord = null;
            CityId = 0;
            StateId = 0;
        }

        public static SearchConditions Condition
        {
            get
            {
                if(_condition == null)
                {
                    _condition = new SearchConditions();
                }

                return _condition;
            }
         }

        public int StateId { get; set; }
        public List<int> FoodTypeIds { get; set; }
        public string KeyWord { get; set; }
        public int CityId { get; set; }
    }

}
