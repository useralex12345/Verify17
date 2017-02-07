#pragma once

#include <cmath>
#include <cstdlib>
#include "station.h"

using namespace System;

namespace Rails {

	// константы, использующиеся при генерации пассажиров
	const int PERC_TELEVISION = 5; // процент требующих телевизор
	const int PERC_TELEPHONY  = 5; // процент требующих телефонную связь
	const int PERC_CAFE       = 20; // процент требующих вагон-буфет
	const int PERC_RESTARAUNT = 10; // процент требующих вагон-ресторан

	// класс, который генерирует станции, поезда и пассажиров и хранит информацию о них
	public ref class manager {
	public:
		List<station^>^ stations; // список станций

		static manager^ instance = gcnew manager(); // статический указатель на текущий экземпляр класса

	public:
		manager() {
			generate_stations();
			generate_trains();
			generate_passengers();
		}

	private:
		// генерирует станции
		void generate_stations() {
			array<String^>^ names = {
				L"Барнаул",
				L"Томск",
				L"Новосибирск",
				L"Москва",
				L"Екатеринбург",
				L"Челябинск",
				L"Абакан",
				L"Красноярск",
				L"Владивосток",
				L"Бийск",
				L"Мурманск",
				L"Астрахань",
				L"Анапа",
				L"Нальчик",
				L"Самара",
				L"Санкт-Петербург",
				L"Арзамас",
				L"Орел",
				L"Липецк",
				L"Магадан",
				L"Курган"
			};

			stations = gcnew List<station^>();

			for(int i = 0; i < names->Length; ++i) {
				stations->Insert(stations->Count, gcnew station(names[i], rand() % 7000, rand() % 3000));
			}
		}
		// генерирует поезда
		void generate_trains() {
			for(int i = 0; i < stations->Count; ++i) {
				int num_trains = 1 + rand() % 10;

				for(int j = 0; j < num_trains; ++j) {
					station^ target = stations[i];

					while(target == stations[i]) {
						target = stations[rand() % stations->Count];
					}

					train^ new_train = gcnew train(rand() % 1000, stations[i], target);
					new_train->set_time_dispatch(rand() % 1440);
					new_train->set_time_arrival(rand() % 1440);

					//

					int num_carriages = 1 + rand() % 20;
					for(int k = 0; k < num_carriages; ++k) {
						switch(rand() % 2) {
						case 0:
							{
								passenger_carriage^ new_carriage = nullptr;
								switch(rand() % 3) {
								case 0:
									new_carriage = gcnew seat_carriage(k + 1);
									new_carriage->set_has_television((rand() % 2) > 0);
									new_carriage->set_has_telephony((rand() % 2) > 0);
									new_train->get_carriages()->Insert(k, new_carriage);
									break;
								case 1:
									new_carriage = gcnew reserved_carriage(k + 1);
									new_carriage->set_has_television((rand() % 2) > 0);
									new_carriage->set_has_telephony((rand() % 2) > 0);
									new_train->get_carriages()->Insert(k, new_carriage);
									break;
								case 2:
									new_carriage = gcnew coupe_carriage(k + 1);
									new_carriage->set_has_television((rand() % 2) > 0);
									new_carriage->set_has_telephony((rand() % 2) > 0);
									new_train->get_carriages()->Insert(k, new_carriage);
									break;
								}
							}
							break;
						case 1:
							{
								switch(rand() % 3) {
								case 0:
									new_train->get_carriages()->Insert(k, gcnew postal_carriage(k + 1));
									break;
								case 1:
									new_train->get_carriages()->Insert(k, gcnew cafe_carriage(k + 1));
									break;
								case 2:
									new_train->get_carriages()->Insert(k, gcnew restaraunt_carriage(k + 1));
									break;
								}
							}
							break;
						}
					}

					stations[i]->get_trains()->Insert(0, new_train);
				}
			}
		}
		// генерирует пассажиров
		void generate_passengers() {
			for(int i = 0; i < stations->Count; ++i) {
				int num_passengers = rand() % 5000;

				station^ target_station = stations[i];
				for(int j = 0; j < num_passengers; ++j) {
					train^ target_train = target_station->get_trains()[rand() % target_station->get_trains()->Count];

					carriage_type target_type;
					switch(rand() % 3) {
					case 0:
						target_type = carriage_type::SEAT;
						break;
					case 1:
						target_type = carriage_type::RESERVED;
						break;
					case 2:
						target_type = carriage_type::COUPE;
						break;
					}

					bool need_television = (rand() % 100) < PERC_TELEVISION;
					bool need_telephony  = (rand() % 100) < PERC_TELEPHONY;
					bool need_cafe       = (rand() % 100) < PERC_CAFE;
					bool need_restaraunt = (rand() % 100) < PERC_RESTARAUNT;

					bool has_cafe       = false;
					bool has_restaraunt = false;

					for(int k = 0; k < target_train->get_carriages()->Count; ++k) {
						if(target_train->get_carriages()[k]->get_type() == carriage_type::CAFE) {
							has_cafe = true;
						}
						if(target_train->get_carriages()[k]->get_type() == carriage_type::RESTARAUNT) {
							has_restaraunt = true;
						}
					}

					if((!need_cafe || has_cafe) && (!need_restaraunt || has_restaraunt)) {
						List<passenger_carriage^>^ carriages = gcnew List<passenger_carriage^>();

						for(int k = 0; k < target_train->get_carriages()->Count; ++k) {
							if(target_train->get_carriages()[k]->get_type() == target_type) {
								passenger_carriage^ target_carriage = dynamic_cast<passenger_carriage^>(target_train->get_carriages()[k]);

								if(target_carriage->get_buyed() < target_carriage->get_places()) {
									if((!need_television || target_carriage->get_has_television()) && (!need_telephony || target_carriage->get_has_telephony())) {
										carriages->Add(target_carriage);	
									}
								}
							}
						}

						if(carriages->Count > 0) {
							if(need_television || need_telephony || need_cafe || need_restaraunt) {
								target_station->set_specials(target_station->get_specials() + 1);
							}
							carriages[0]->set_buyed(carriages[0]->get_buyed() + 1);
						}
						else {
							target_station->set_denied(target_station->get_denied() + 1);
						}
					}
					else {
						target_station->set_denied(target_station->get_denied() + 1);
					}
				}
			}
		}
	};

}