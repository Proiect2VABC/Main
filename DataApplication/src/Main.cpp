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

	while(1)
	{
		cout << "Please enter the command:";
		cin >> command;
		command_execute(command);
		command.clear();
	}





	return 0;
}

void command_execute(string command)
{
	if(!strcmp(command.c_str(),"help"))
	{
		cout << "Commands\n";
		cout << "print -> prints all the devices stored in app\n";
		cout << "pdevice 'device_name'-> prints all the data stored under the device name given\n";
		cout << "ptime 'time_start' 'time_stop'-> prints all the data stored in the interval given\n";
		cout << "exit -> guess what it does\n";
		return;
	}

	if(!strcmp(command.c_str(), "print"))
	{
		new_list.print();
		return;
	}

	if(!strcmp(command.c_str(), "pdevice"))
	{
		string d_n;
		cin >> d_n;
		new_list.print_device(d_n);
		return;
	}

	if(!strcmp(command.c_str(), "ptime"))
	{
		int time_s, time_e;
		cin >> time_s;
		cin >> time_e;
		new_list.print_time_interval(time_s, time_e);
		return;
	}

	if(!strcmp(command.c_str(), "exit"))
	{
		exit(0);
	}

	if(!strcmp(command.c_str(), "refresh"))
	{
		new_list.read_from_file(filename);
		return;
	}
	cout << "Invalid command!";
	return;
}
