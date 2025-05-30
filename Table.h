#ifndef TABLE_H
#define TABLE_H

#include "Record.h"
#include <vector>
#include <string>
#include <functional>

class Table {
private:
	std::vector<Record> records;

public:
	void loadFromCSV(const std::string& filename);
	void saveToCSV(const std::string& filename);
	void insertRecord(const Record& record);
	void deleteRecord(const std::string& date);
	void printAll() const;
	std::vector<Record> filter(std::function<bool(const Record&)> condition) const;
};
#endif // !TABLE_H
