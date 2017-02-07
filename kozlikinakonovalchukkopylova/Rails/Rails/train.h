#pragma once

#include "classes.h"
#include "carriage.h"
#include "station.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

namespace Rails {

	// класс поезда
	public ref class train {
	private:
		int number; // номер поезда

		List<carriage_base^>^ carriages; // контейнер с данными о вагонах

		station^ station_dispatch; // станция отправления
		station^ station_arrival; // станция прибытия

		int time_dispatch; // время отправления (в минутах, считая от полуночи)
		int time_arrival; // время прибытия (в минутах, считая от полуночи)

	public:
		train(int number, station^ dispatch, station^ arrival);
		train(train% instance);

		virtual int get_number(); // возвращает номер поезда
		virtual List<carriage_base^>^ get_carriages(); // возвращает контейнер с данными о вагонах
		virtual station^ get_stantion_dispatch(); // возвращает станцию отправления
		virtual station^ get_stantion_arrival(); // возвращает станцию прибытия
		virtual int get_time_dispatch(); // возвращает время отправления
		virtual int get_time_arrival(); // возвращает время прибытия

		virtual int get_cost(int price); // возвращает стоимость поездки (длина пути * цену)
		virtual int get_distance(); // возвращает длину пути

		virtual void set_number(int value); // устанавливает номер поезда
		virtual void set_carriages(List<carriage_base^>^ value); // устанавливает контейнер с данными о вагонах
		virtual void set_stantion_dispatch(station^ value); // устанавливает станцию отправления
		virtual void set_stantion_arrival(station^ value); // устанавливает станцию прибытия
		virtual void set_time_dispatch(int value); // устанавливает время отправления
		virtual void set_time_arrival(int value); // устанавливает время прибытия
	};

}