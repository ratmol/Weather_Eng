#include "Table.h"
#include <fstream>
#include <iostream>

void Table::loadFromCSV(const std::string& filename) {
	records.clear();
	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line)) {
		records.emplace_back(line);
	}
	file.close();
}

void Table::saveToCSV(const std::string& filename) {
	std::ofstream file(filename);
	for (const auto& record : records) {
		file << record.toCSV() << "\n";
	}
	file.close();
}

void Table::insertRecord(const Record& record) {
	records.push_back(record);
}

void Table::deleteRecord(const std::string& date) {
	records.erase(
		std::remove_if(records.begin(), records.end(), [&](const Record& r) {
			return r.date == date;
			}),
		records.end()
	);
}

std::vector<Record> Table::filter(std::function<bool(const Record&)> condition) const {
	std::vector<Record> result;
	for (const auto& r : records) {
		if (condition(r)) result.push_back(r);
	}
	return result;
}

void Table::printAll() const {
	for (const auto& r : records) 
		r.print();
}