using RestaurantDB.DB_jun;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantDB.Data
{
    public class StoreData : EntityData<Store>
    {

        public int FindStoreId(string storeName)
        {
            using(RestaurantEntities context = new RestaurantEntities())
            {
                var query = from x in context.Stores
                            where x.Name == storeName
                            select x.StoreId;

                return query.ToList().FirstOrDefault();
            }
        }

        public List<SearchResultData> GetSearchResult()
        {
            using(RestaurantEntities context = new RestaurantEntities())
            {
                var query = from x in context.Stores
                            select x;

                //고른 지역 확인 후 추려냄
                if (SearchConditions.Condition.StateId != 0)
                    query = from x in query
                            where x.StateId == SearchConditions.Condition.StateId
                            select x;

                //음식 타입 확인 후 추려냄
                if (SearchConditions.Condition.FoodTypeIds.Any())
                    query = from x in query
                            where SearchConditions.Condition.FoodTypeIds.Contains(x.FoodTypeId)
                            select x;

                //고른 구역 확인 후 추려냄
                if (SearchConditions.Condition.CityId != 0)
                    query = from x in query
                            where x.CityId == SearchConditions.Condition.CityId
                            select x;

                //키워드 입력 확인 후 추려냄
                if (SearchConditions.Condition.KeyWord != null)
                    query = from x in query
                            where x.Outline.Contains(SearchConditions.Condition.KeyWord)
                            select x;

                var resultQuery = from x in query
                                  select new SearchResultData
                                  {
                                      Name = x.Name,
                                      Outline = x.Outline
                                  };

                return resultQuery.ToList();
            }
        }
    }
}
