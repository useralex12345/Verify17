#pragma once

#include "classes.h"
#include "train.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

namespace Rails {

	public ref class station {
	private:
		String^ name; // название станции
		int x, y; // координаты станции
		int specials; // количество пассажиров, требующих доп. оборудование
		int denied; // количество пассажиров, которым было отказано в покупке билета
		List<train^>^ trains; // контейнер с данными о поездах, отправляющихся со станции
	public:
		station(String^ name, int x, int y);
		station(station% instance);

		virtual String^ get_name(); // возвращает название станции
		virtual int get_x(); // возвращает координату X станции
		virtual int get_y(); // возвращает координату Y станции
		virtual List<train^>^ get_trains(); // возвращает контейнер с данными о поездах
		virtual int get_denied(); // возвращает количество пассажиров, которым было отказано в покупке билета
		virtual int get_specials(); // возвращает количество пассажиров, требующих доп. оборудование

		virtual void set_name(String^ name); // устанавливает название станции
		virtual void set_x(int value); // устанавливает координату X станции
		virtual void set_y(int value); // устанавливает координату Y станции
		virtual void set_trains(List<train^>^ value); // устанавливает контейнер с данными о поездах
		virtual void set_denied(int value); // устанавливает количество пассажиров, которым было отказано в покупке билета
		virtual void set_specials(int value); // устанавливает количество пассажиров, требующих доп. оборудование
	};

}