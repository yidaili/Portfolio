using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantDB.DB_jun
{
    public class EntityData<T> where T : class
    {
        static EntityData()
        {

        }

        public List<T> GetAll()
        {
            using (RestaurantEntities context = new RestaurantEntities())
            {
                return context.Set<T>().ToList();
            }
        }

        public bool Insert(T reservation)
        {
            using (DbContext context = new RestaurantEntities())
            {

                context.Set<T>().Add(reservation);

                try
                {
                    context.SaveChanges();
                }
                catch (Exception e)
                {
                    if (e != null)
                        return false;
                }
                return true;
            }
        }

        public bool Update(T entity)
        {
            using(DbContext context = new RestaurantEntities())
            {
                context.Entry(entity).State = EntityState.Modified;

                try
                {
                    context.SaveChanges();
                }
                catch (Exception e)
                {

                    if (e != null)
                        return false;
                }

                return true;
            }
        }


        public bool Delete(T entity)
        {
            using(DbContext context = new RestaurantEntities())
            {
                context.Entry(entity).State = EntityState.Deleted;

                try
                {
                    context.SaveChanges();
                }
                catch (Exception e)
                {

                    if (e != null)
                        return false;
                }

                return true;
            }
        }

    }
}
