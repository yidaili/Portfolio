using System;
using System.Collections.Generic;
using System.Linq;
using System.Data.Entity;
using System.Text;
using System.Threading.Tasks;

namespace RestaurantDB.DB_jun
{
    public class ReservationData : EntityData<Reservation>
    {
        public List<Reservation> GetReservationList(string phoneNumber)
        {
            using (RestaurantEntities context = new RestaurantEntities())
            {
                var query = from x in context.Reservations
                            where(x.PhoneNumber == phoneNumber)
                            select new
                            {
                                Reservation = x,
                                StoreName = x.Store.Name,
                            };

                var list = query.ToList();

                foreach (var x in list)
                {
                    x.Reservation.StoreName = x.StoreName;
                }

                return list.ConvertAll(x => x.Reservation);
            }
        }

        public bool InsertOrUpdate(Reservation reservation)
        {
            using(RestaurantEntities context = new RestaurantEntities())
            {
                context.Entry(reservation).State =
                    reservation.ReservationId != 0 ? EntityState.Modified : EntityState.Added;
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
