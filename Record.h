#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <sstream>

class Record {
public:
	std::string date;
	float temperature;
	float humidity;
	float rainfall;

	Record() = default;
	Record(const std::string& line);
	std::string toCSV() const;
	void print() const;
};

#endif