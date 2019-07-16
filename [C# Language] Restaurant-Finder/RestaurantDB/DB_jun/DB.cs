using RestaurantDB.Data;


namespace RestaurantDB.DB_jun
{
    
    public class DB
    {
        static DB()
        {
            Reservation = new ReservationData();
            State = new StateData();
            City = new CityData();
            Store = new StoreData();
        }

        public static ReservationData Reservation { get; }
        public static StateData State { get; }
        public static CityData City { get; }
        public static StoreData Store { get; }
    }
}
