#include "stdafx.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;

namespace Rails {

	train::train(int number, station^ dispatch, station^ arrival) : 
		number(number),
		station_dispatch(dispatch), 
		station_arrival(arrival) 
	{
		carriages = gcnew List<carriage_base^>();
	}
	train::train(train% instance) : 
		number(instance.number),
		carriages(instance.carriages),
		station_dispatch(instance.station_dispatch), 
		station_arrival(instance.station_arrival), 
		time_dispatch(instance.time_dispatch),
		time_arrival(instance.time_arrival)
	{ 
	}

	int train::get_number() {
		return number;
	}
	List<carriage_base^>^ train::get_carriages() {
		return carriages;
	}
	station^ train::get_stantion_dispatch() {
		return station_dispatch;
	}
	station^ train::get_stantion_arrival() {
		return station_arrival;
	}
	int train::get_time_dispatch() {
		return time_dispatch;
	}
	int train::get_time_arrival() {
		return time_arrival;
	}

	int train::get_cost(int price) {
		return get_distance() * price;
	}
	int train::get_distance() {
		return int(::sqrt(::pow(double(station_dispatch->get_x() - station_arrival->get_x()), 2.0) + ::pow(double(station_dispatch->get_y() - station_arrival->get_y()), 2.0)));
	}

	void train::set_number(int value) {
		number = value;
	}
	void train::set_carriages(List<carriage_base^>^ value) {
		carriages = value;
	}
	void train::set_stantion_dispatch(station^ value) {
		station_dispatch = value;
	}
	void train::set_stantion_arrival(station^ value) {
		station_arrival = value;
	}
	void train::set_time_dispatch(int value) {
		time_dispatch = value;
	}
	void train::set_time_arrival(int value) {
		time_arrival = value;
	}

}