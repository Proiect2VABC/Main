/*
 * locations_source.cpp
 *
 *  Created on: May 15, 2016
 *      Author: rocco
 */

#include "locations.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <locale>
#include <iomanip>
#include <sstream>
#include <string.h>

location::location(entry* new_entry) {
	data = new_entry;

	next = NULL;
	prev = NULL;
}

void location::set_name(string name) {
	location_name = name;
}

void location::print(int nr) {
	cout << "Location number " << nr << " called " << location_name
			<< " with the following data:\n";
	data->print();
}

location::location(entry* new_entry, string nume) {
	this->data = new_entry;
	this->location_name = nume;

	next = NULL;
	prev = NULL;
}

void location::show() {
	fstream file("temp");
	char browser[10] = "firefox";
	char google[50] = " https://www.google.ro/maps/dir//";
	char zoom[4] = "20z";
	char* link;
	char* open_b;

	//string lat_temp = static_cast<ostringstream*>( &(ostringstream() << data->latitude) )->str();
	//string longi_temp = static_cast<ostringstream*>( &(ostringstream() << data->longitude) )->str();

	link = new char[strlen(std::to_string(data->latitude).c_str()) * 2 + strlen(std::to_string(data->latitude).c_str()) * 2 + strlen(google)
			+ strlen(zoom) + 10];
	open_b = new char[strlen(link) + strlen(browser) + 10];

	link = strcat(google, std::to_string(data->latitude).c_str());
	link = strcat(link, ",");
	link = strcat(link, std::to_string(data->longitude).c_str());
	link = strcat(link, "/@");
	link = strcat(link, std::to_string(data->latitude).c_str());
	link = strcat(link, ",");
	link = strcat(link, std::to_string(data->longitude).c_str());
	link = strcat(link, ",");
	link = strcat(link, zoom);

	open_b = strcat(browser, link);

	cout << link << "\n";

	system(open_b);

	link = NULL;
	open_b = NULL;
}

