/*
 * entry.h
 *
 *  Created on: Apr 21, 2016
 *      Author: andrei
 */

#ifndef ENTRY_H_
#define ENTRY_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class entry {
	friend class entries_list;
	string device_name;
	float latitude;
	float longitude;
	int time;

	entry *next;
	entry *prev;

	void print();

public:
	entry(string, float, float, int);
};



#endif /* ENTRY_H_ */
