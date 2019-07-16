using RestaurantDB.DB_jun;
using RestaurantDB.ResultFormat;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantDB.Data
{
    public class CityData : EntityData<City>
    {
        public List<CityListFormat> GetAllCitiesIn(int stateId)
        {
            using(RestaurantEntities context = new RestaurantEntities())
            {
                var query = from x in context.Stores
                            where x.StateId == stateId
                            select new CityListFormat
                            {
                                CityId = x.CityId,
                                Name = x.City.Name
                            };

                
                return query.Distinct().ToList();
            }
        }
    }
}
