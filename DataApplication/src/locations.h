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
	entry* device;

	string location_name = "not_set";
	int visits;

	location *next;
	location *prev;


	void set_name(string);
	void print();

public:
	location(entry*);

};


#endif /* LOCATIONS_H_ */
