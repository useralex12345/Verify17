#include "stdafx.h"

namespace Rails {

	station::station(String^ name, int x, int y) : name(name), x(x), y(y), specials(0), denied(0) {
		trains = gcnew List<train^>();
	}
	station::station(station% instance) : name(instance.name), x(instance.x), y(instance.y), trains(instance.trains) {
	}

	String^ station::get_name() {
		return name;
	}
	int station::get_x() {
		return x;
	}
	int station::get_y() {
		return y;
	}
	List<train^>^ station::get_trains() {
		return trains;
	}
	int station::get_denied() {
		return denied;
	}
	int station::get_specials() {
		return specials;
	}

	void station::set_name(String^ value) {
		name = value;
	}

	void station::set_x(int value) {
		x = value;
	}
	void station::set_y(int value) {
		y = value;
	}
	void station::set_trains(List<train^>^ value) {
		trains = value;
	}
	void station::set_denied(int value) {
		denied = value;
	}
	void station::set_specials(int value) {
		specials = value;
	}

}