#include <iostream>
#include <cstdlib>
#include "entries_list.h"
using namespace std;

void command_execute(string command);

entries_list new_list;
string command;
string filename = "log";

int main() {

	new_list.read_from_file(filename);

	while (1) {
		cout << "Please enter the command:";
		cin >> command;
		command_execute(command);
		command.clear();
	}

	return 0;
}

void command_execute(string command) {
	if (!strcmp(command.c_str(), "help")) {
		cout << "Commands\n";
		cout << "print -> Prints all the devices stored in application.\n";
		cout
				<< "pdevice 'device_name'-> Prints all the data stored under the device name given.\n";
		cout
				<< "ptime 'time_start' 'time_stop'-> Prints all the data stored in the interval given.\n";
		cout
				<< "refresh -> Recreates the entries list. Always use after new data arrives.\n";
		cout
				<< "location 'number_of_entry' 'name_of_location' -> Creates a new location from the specified entry with given name.\n";
		cout << "show 'location_number' -> Prints the URL for Google Maps.\n";
		cout << "exit -> Exits the application safely.\n";
		return;
	}

	if (!strcmp(command.c_str(), "print")) {
		new_list.print();
		return;
	}

	if (!strcmp(command.c_str(), "plocations")) {
		new_list.print_locations();
		return;
	}

	if (!strcmp(command.c_str(), "pdevice")) {
		string d_n;
		cin >> d_n;
		new_list.print_device(d_n);
		return;
	}

	if (!strcmp(command.c_str(), "ptime")) {
		int time_s, time_e;
		cin >> time_s;
		cin >> time_e;
		new_list.print_time_interval(time_s, time_e);
		return;
	}

	if (!strcmp(command.c_str(), "exit")) {
		exit(0);
	}

	if (!strcmp(command.c_str(), "refresh")) {
		new_list.clean();
		new_list.read_from_file(filename);
		return;
	}

	if (!strcmp(command.c_str(), "show")) {
		int nr;
		cin >> nr;
		new_list.show(nr);
		return;
	}

	if (!strcmp(command.c_str(), "location")) {
		string nume;
		int crt;
		cin >> crt;
		cin >> nume;
		new_list.new_location(new_list.get_entry(crt), nume);

		return;
	}

	cout << "Invalid command!";
	return;

}
