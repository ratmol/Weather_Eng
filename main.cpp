#include "Table.h"
#include "QueryProcessor.h"
#include <iostream>
#include <string>
#include <algorithm> // For std::isspace

// Helper function to trim leading and trailing whitespace from a string
std::string trim(const std::string& s) {
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) ++start;

    auto end = s.end();
    do {
        --end;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

// Entry point of the mini database engine
int main() {
    Table table;
    QueryProcessor processor;
    std::string command;

    std::cout << "Mini Weather DB Engine\n";
    std::cout << "Commands:\n"
        << "  LOAD filename\n"
        << "  SAVE filename\n"
        << "  SELECT *\n"
        << "  SELECT WHERE temperature > 20.0\n"
        << "  INSERT YYYY-MM-DD,temp,humidity,rainfall\n"
        << "  DELETE YYYY-MM-DD\n"
        << "  EXIT\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        command = trim(command);  // Remove extra spaces

        if (command == "EXIT") {
            break; // Exit the program
        }
        else if (command.rfind("LOAD ", 0) == 0) {
            std::string filename = trim(command.substr(5));
            table.loadFromCSV(filename);
            std::cout << "Data loaded from " << filename << ".\n";
        }
        else if (command.rfind("SAVE ", 0) == 0) {
            std::string filename = trim(command.substr(5));
            table.saveToCSV(filename);
            std::cout << "Data saved to " << filename << ".\n";
        }
        else {
            processor.execute(command, table); // Handle SELECT, INSERT, DELETE
        }
    }

    return 0;
}
