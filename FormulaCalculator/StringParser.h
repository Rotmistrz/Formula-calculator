#pragma once

#include "stdafx.h"

class StringParser {
public:
	StringParser();
	StringParser(std::vector<std::string> items);
	~StringParser();

	StringParser* first();
	StringParser* next();
	StringParser* previous();
	std::string current();
	bool hasNext();

	StringParser* add(std::string str);

	std::string toString();

	static StringParser* createFromString(std::string& str);
private:
	static char separator;

	int currentPosition;
	std::vector<std::string> items;
};

