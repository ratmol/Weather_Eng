#include "Table.h"
#include "QueryProcessor.h"
#include <iostream>
#include <string>

int main() {
	Table table;
	QueryProcessor processor;
	std::string command;

	std::cout << "Mini Weather DB Engine\n";
	std::cout << "Commands: LOAD filename, Save filename, SELECT *< SELECT WHERE field or value, INSERT date, temp, humidity, rainfall, DELETE date.\n";


	while (true) {
		std::cout << "> ";
		std::getline(std::cin, command);

		if (command == "EXIT") break;
		else if (command.rfind("LOAD", 0) == 0) {
			std::string filename = command.substr(5);
			table.loadFromCSV(filename);
			std::cout << "Data loaded.\n";
		}
		else if (command.rfind("SAVE", 0) == 0) {
			std::string filename = command.substr(5);
			table.loadFromCSV(filename);
			std::cout << "Data saved.\n";
		}
		else {
			processor.execute(command, table);
		}
	}

	return 0;
}