/*
 * entries_source.cpp
 *
 *  Created on: May 15, 2016
 *      Author: rocco
 */

#include "entry.h"
#include "entries_list.h"

entry::entry(string name, float lat, float lon, int time) {
	device_name = name;
	latitude = lat;
	longitude = lon;
	this->time = time;

	next = NULL;
	prev = NULL;
}

void entry::print() {
	int minutes = time % 100;
	int hours = time / 100;
	cout << "Device: " << device_name << " Latitude: " << latitude
			<< " Longitude: " << longitude << " Time: " << hours << ":"
			<< minutes << "\n";
	return;
}

entries_list::entries_list() {
	first = NULL;
	last = NULL;

	number_of_entries = 0;
}

void entries_list::read_from_file(string filename) {
	string name;
	float lat;
	float lon;
	int time;
	entry* n;
	string buffer;

	ifstream file(filename.c_str());

	if (file.is_open()) {
		while (file >> name >> lat >> lon >> time) {

			n = new entry(name, lat, lon, time);
			add(n);
			entries_q.push_back(n);
			number_of_entries++;

		}
	} else {
		cout << "Probleme grave dom' profesor.\n";
	}
}

void entries_list::add(entry* n) {
	if (!first) {
		first = n;
		last = n;
		number_of_entries++;
		return;
	}

	last->next = n;
	n->prev = last;
	n->next = NULL;
	last = n;

	number_of_entries++;

}

void entries_list::print() {
	entry* temp = first;
	int number = number_of_entries;

	if (temp == NULL) {
		cout << "List is empty.\n";
		return;
	}

	while (temp != NULL) {
		temp->print();
		temp = temp->next;
	}
}

void entries_list::check_first() {
	cout << first->device_name << "\n";
}

void entries_list::save(string filename) {
	ofstream file(filename.c_str());
	entry* temp = first;

	while (temp) {
//		filename << temp->device_name << " " << temp->latitude << " " << temp->longitude << " " << temp->time/100
//				<< " " << temp->time%100;
		temp = temp->next;
	}

}

void entries_list::print_device(string name) {
	entry* temp = first;
	int number = number_of_entries;

	if (temp == NULL) {
		cout << "List is empty.\n";
		return;
	}

	while (temp != NULL) {
		if (!strcmp(temp->device_name.c_str(),name.c_str()))
			temp->print();
		temp = temp->next;
	}

}

void entries_list::print_time_interval(int start, int end)
{
	entry* temp = first;
	int number = number_of_entries;

	if (temp == NULL) {
		cout << "List is empty.\n";
		return;
	}

	while (temp != NULL) {
		if ((temp->time >= start) && (temp->time <= end))
			temp->print();
		temp = temp->next;
	}

}


