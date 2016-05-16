/*
 * entries_list.h
 *
 *  Created on: Apr 21, 2016
 *      Author: andrei
 */

#ifndef ENTRIES_LIST_H_
#define ENTRIES_LIST_H_

#include "entry.h"
#include "locations.h"
#include <stdio.h>
#include <cstring>

class entries_list {
	friend class entry;

	entry* first;
	entry* last;
	int number_of_entries;

	location* first_location;
	location* last_location;
	int number_of_locations;

	std::vector<entry*> entries_q;

public:
	entries_list();
	void add(entry*);
	void print();
	void read_from_file(string filename);
	void check_first();
	void save(string filename);
	void print_device(string name);
	void print_time_interval(int start, int end);

};



#endif /* ENTRIES_LIST_H_ */
