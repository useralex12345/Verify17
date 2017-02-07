#include "stdafx.h"

namespace Rails {

	int TELEVISION_COST          = 1;
	int TELEPHONY_COST           = 1;
	int SEAT_CARRIAGE_COST       = 1;
	int RESERVED_CARRIAGE_COST   = 2;
	int COUPE_CARRIAGE_COST      = 4;
	int SEAT_CARRIAGE_PLACES     = 60;
	int RESERVED_CARRIAGE_PLACES = 60;
	int COUPE_CARRIAGE_PLACES    = 40;

	carriage_base::carriage_base(int number) : number(number) {
	}
	carriage_base::carriage_base(carriage_base% instance) : number(instance.number) {
	}

	int  carriage_base::get_number() {
		return number;
	}
	carriage_type carriage_base::get_type() {
		return type;
	}

	void carriage_base::set_number(int value) {
		number = value;
	}
	void carriage_base::set_type(carriage_type value) {
		type = value;
	}

	passenger_carriage::passenger_carriage(int number, int places, int price) : carriage_base(number), places(places), buyed(0), price(price) {
	}
	passenger_carriage::passenger_carriage(passenger_carriage% instance) : carriage_base(instance), places(instance.places), buyed(instance.buyed), price(instance.price) {
	}

	int passenger_carriage::get_places() { return places; }
	int passenger_carriage::get_buyed() { return buyed; }
	int passenger_carriage::get_price() { return price + (television ? TELEVISION_COST : 0) + (telephony ? TELEPHONY_COST : 0); }
	int passenger_carriage::get_has_television() { return television; }
	int passenger_carriage::get_has_telephony() { return telephony; }

	void passenger_carriage::set_price(int value) { price = value; }
	void passenger_carriage::set_buyed(int value) { buyed = value; }
	void passenger_carriage::set_places(int value) { places = value; }
	void passenger_carriage::set_has_television(bool value) { television = value; }
	void passenger_carriage::set_has_telephony(bool value) { telephony = value; }

	seat_carriage::seat_carriage(int number) : passenger_carriage(number, SEAT_CARRIAGE_PLACES, SEAT_CARRIAGE_COST) { 
		set_type(carriage_type::SEAT);
	}
	seat_carriage::seat_carriage(seat_carriage% instance) : passenger_carriage(instance) { 
		set_type(carriage_type::SEAT);
	}

	reserved_carriage::reserved_carriage(int number) : passenger_carriage(number, RESERVED_CARRIAGE_PLACES, RESERVED_CARRIAGE_COST) { 
		set_type(carriage_type::RESERVED);
	}
	reserved_carriage::reserved_carriage(reserved_carriage% instance) : passenger_carriage(instance) { 
		set_type(carriage_type::RESERVED);
	}

	coupe_carriage::coupe_carriage(int number) : passenger_carriage(number, COUPE_CARRIAGE_PLACES, COUPE_CARRIAGE_COST) { 
		set_type(carriage_type::COUPE);
	}
	coupe_carriage::coupe_carriage(coupe_carriage% instance) : passenger_carriage(instance) { 
		set_type(carriage_type::COUPE);
	}

	service_carriage::service_carriage(int number) : carriage_base(number) { }
	service_carriage::service_carriage(service_carriage% instance) : carriage_base(instance) { }

	postal_carriage::postal_carriage(int number) : service_carriage(number) { 
		set_type(carriage_type::POSTAL);
	}
	postal_carriage::postal_carriage(postal_carriage% instance) : service_carriage(instance) { 
		set_type(carriage_type::POSTAL);
	}

	cafe_carriage::cafe_carriage(int number) : service_carriage(number) { 
		set_type(carriage_type::CAFE);
	}
	cafe_carriage::cafe_carriage(cafe_carriage% instance) : service_carriage(instance) { 
		set_type(carriage_type::CAFE);
	}

	restaraunt_carriage::restaraunt_carriage(int number) : service_carriage(number) { 
		set_type(carriage_type::RESTARAUNT);
	}
	restaraunt_carriage::restaraunt_carriage(restaraunt_carriage% instance) : service_carriage(instance) { 
		set_type(carriage_type::RESTARAUNT);
	}

}