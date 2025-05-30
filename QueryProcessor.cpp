#include "QueryProcessor.h"
#include <iostream>
#include <sstream>

void QueryProcessor::execute(const std::string& command, Table& table) {
	std::stringstream ss(command);
	std::string keyword;
	ss >> keyword;

	if (keyword == "SELECT") {
		std::string where;
		ss >> where;
		if (where == "*") {
			table.printAll();
		}
		else if (where == "WHERE") {
			std::string field, op;
			float value;
			ss >> field >> op >> value;
			auto result = table.filter([&](const Record& r) {
				if (field == "temperature") {
					if (op == ">") return r.temperature > value;
					if (op == "<") return r.temperature < value;
					if (op == "==") return r.temperature == value;
				}
				return false;
				});
			for (const auto& r : result) r.print();
		}
	}
	else if (keyword == "INSERT") {
		std::string rest;
		std::getline(ss, rest);
		table.insertRecord(Record(rest));
		std::cout << "Record inserted.\n";
	}
	else if (keyword == "DELETE") {
		std::string date;
		ss >> date;
		table.deleteRecord(date);
		std::cout << "Record(s) deleted.\n";
	}
	else {
		std::cout << "Unknown command.\n";
	}
}