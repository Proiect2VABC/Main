/*
 * locations.h
 *
 *  Created on: May 10, 2016
 *      Author: andrei
 */

#ifndef LOCATIONS_H_
#define LOCATIONS_H_

#include "entry.h"

class location {
	friend class entries_list;
	friend class devices;
	entry* data;

	string location_name = "not_set";

	location *next;
	location *prev;

	void set_name(string);
	void print(int nr);
	void show();

public:
	location(entry*);
	location(entry*, string name);

};

#endif /* LOCATIONS_H_ */
