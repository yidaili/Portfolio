using RestaurantDB.DB_jun;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantDB.Data
{
    public class StateData : EntityData<State>
    {
        public int FindFirstStateId(string text)
        {
            using (RestaurantEntities context = new RestaurantEntities())
            {
                var query = from x in context.States
                            where x.Name.Contains(text)
                            select x.StateId;

                return query.FirstOrDefault();
            }
        }
    }
}
