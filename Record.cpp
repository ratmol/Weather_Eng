#include "Record.h"
#include<iostream>

Record::Record(const std::string& line) {
	std::stringstream ss(line);
	std::string token;

	std::getline(ss, date, ',');
	std::getline(ss, date, ',');
	temperature = std::stof(token);
	std::getline(ss, date, ',');
	humidity = std::stof(token);
	std::getline(ss, date, ',');
	rainfall = std::stof(token);
}

std::string Record::toCSV() const {
	std::stringstream ss;
	ss << date << "," << temperature << "," << humidity << "," << rainfall;
	return ss.str();
}

void Record::print() const {
	std::cout << date << " | Temp: " << temperature << " | Humidity: " << humidity << " | Rainfall: " << rainfall << "\n";
}