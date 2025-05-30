#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include "Table.h"
#include <string>

class QueryProcessor {
public:
	void execute(const std::string& command, Table& table);
};
#endif // !QUERYPROCESSOR_H
