#include "stdafx.h"
#include "StringParser.h"


StringParser::StringParser() : currentPosition(0) {
	items = std::vector<std::string>();
}

StringParser::StringParser(std::vector<std::string> items) : currentPosition(0), items(items) {
}


StringParser::~StringParser() {
}

char StringParser::separator = ' ';

StringParser* StringParser::add(std::string str) {
	items.push_back(str);

	return this;
}

StringParser* StringParser::createFromString(std::string& str) {
	//std::cout << "trim" << std::endl;
	str = trim(str);

	//std::cout << "split" << std::endl;
	return new StringParser(split(str, separator));
}

StringParser* StringParser::first() {
	currentPosition = 0;

	return this;
}

StringParser* StringParser::next() {
	currentPosition++;

	return this;
}

StringParser* StringParser::previous() {
	currentPosition--;

	return this;
}

std::string StringParser::current() {
	return items[currentPosition];
}

bool StringParser::hasNext() {
	return (currentPosition < items.size()) ? true : false;
}

std::string StringParser::toString() {
	int position = currentPosition;
	
	first();

	std::string result = "";

	while (hasNext()) {
		result += current();

		next();

		if (hasNext()) {
			result += " ";
		}
	}

	currentPosition = position;

	return result;
}