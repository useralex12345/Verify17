#pragma once

#include "classes.h"

namespace Rails {

	// перечисление типов вагонов
	public enum class carriage_type : int {
		SEAT, // сидячий
		RESERVED, // плацкарт
		COUPE, // купе
		POSTAL, // почтовый
		CAFE, // буфет
		RESTARAUNT // ресторан
	};

	// базовый класс вагона
	public ref class carriage_base {
	private:
		carriage_type type; // тип вагона
		int number; // номер вагона

	public:
		carriage_base(int number);
		carriage_base(carriage_base% instance);

		virtual int  get_number(); // возвращает номер вагона
		virtual carriage_type get_type(); // возвращает тип вагона
		virtual void set_number(int value); // устанавливает номер вагона
		virtual void set_type(carriage_type value); // устанавливает тип вагона
	};

	// класс пассажирского вагона
	public ref class passenger_carriage : public carriage_base {
	private:
		int places; // количество мест
		int buyed; // количество купленных мест
		int price; // цена за билет
		bool television; // есть ли телевизор
		bool telephony; // есть ли телефонная связь

	public:
		passenger_carriage(int number, int places, int price);
		passenger_carriage(passenger_carriage% instance);

		virtual int get_places(); // возвращает количество мест
		virtual int get_buyed(); // возвращает количество купленных мест
		virtual int get_price(); // возвращает цену билета
		virtual int get_has_television(); // возвращает есть ли телевизор
		virtual int get_has_telephony(); // возвращает есть ли телефонная связь

		virtual void set_places(int value); // устанавливает количество мест
		virtual void set_buyed(int value); // устанавливает количество купленных мест
		virtual void set_price(int value); // устанавливает цену билета
		virtual void set_has_television(bool value); // устанавливает есть ли телевизор
		virtual void set_has_telephony(bool value);  // устанавливает есть ли телефонная связь
	};

	// класс сидячего вагона
	public ref class seat_carriage : public passenger_carriage {
	public:
		seat_carriage(int number);
		seat_carriage(seat_carriage% instance);
	};

	// класс плацкартного вагона
	public ref class reserved_carriage : public passenger_carriage {
	public:
		reserved_carriage(int number);
		reserved_carriage(reserved_carriage% instance);
	};

	// класс купейного вагона
	public ref class coupe_carriage : public passenger_carriage {
	public:
		coupe_carriage(int number);
		coupe_carriage(coupe_carriage% instance);
	};

	// класс служебного вагона
	public ref class service_carriage : public carriage_base {
	public:
		service_carriage(int number);
		service_carriage(service_carriage% instance);
	};

	// класс почтового вагона
	public ref class postal_carriage : public service_carriage {
	public:
		postal_carriage(int number);
		postal_carriage(postal_carriage% instance);
	};

	// класс вагона-буфета
	public ref class cafe_carriage : public service_carriage {
	public:
		cafe_carriage(int number);
		cafe_carriage(cafe_carriage% instance);
	};

	// класс вагона-ресторана
	public ref class restaraunt_carriage : public service_carriage {
	public:
		restaraunt_carriage(int number);
		restaraunt_carriage(restaraunt_carriage% instance);
	};

}