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

location::location(entry* new_entry) {
	data = new_entry;

	next = NULL;
	prev = NULL;
}

void location::set_name(string name) {
	location_name = name;
}

void location::print(int nr)
{
	cout << "Location number " << nr << " called " << location_name << " with the following data:\n";
	data->print();
}

location::location(entry* new_entry, string nume)
{
	this->data = new_entry;
	this->location_name = nume;

	next = NULL;
	prev = NULL;
}

void location::show()
{
	char browser[10] = "firefox";
	char google[50] = "https://www.google.ro/maps/dir//";
	string lat_temp = static_cast<ostringstream*>( &(ostringstream() << data->latitude) )->str();
	string longi_temp = static_cast<ostringstream*>( &(ostringstream() << data->longitude) )->str();
	char zoom[4] = "20z";
	char* link = new char[100];
	const char* lat = new char[lat_temp.length()+1];
	const char* longi = new char[lat_temp.length()+1];

	lat = lat_temp.c_str();
	longi = longi_temp.c_str();

	link = strcat(google,lat);
	link = strcat(link,",");
	link = strcat(link,longi);
	link = strcat(link,"/@");
	link = strcat(link,lat);
	link = strcat(link,",");
	link = strcat(link,longi);
	link = strcat(link,",");
	link = strcat(link,zoom);


	cout << link << "\n";

	link = NULL;
}

