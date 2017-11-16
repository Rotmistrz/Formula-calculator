#include "stdafx.h"
#include "VariablesArray.h"


VariablesArray::VariablesArray() {
}


VariablesArray::~VariablesArray() {
}

int VariablesArray::size() {
	return variables.size();
}

bool VariablesArray::contains(std::string name) {
	if (std::find(variables.begin(), variables.end(), name) != variables.end()) {
		return true;
	} else {
		return false;
	}
}

VariablesArray* VariablesArray::clear() {
	variables.clear();

	first();

	return this;
}

VariablesArray* VariablesArray::add(std::string name) {
	if (!contains(name)) {
		variables.push_back(name);
	}

	return this;
}

VariablesArray* VariablesArray::first() {
	currentPosition = 0;

	return this;
}

VariablesArray* VariablesArray::last() {
	currentPosition = size() - 1;

	return this;
}

VariablesArray* VariablesArray::next() {
	currentPosition++;

	return this;
}

VariablesArray* VariablesArray::previous() {
	currentPosition--;

	return this;
}

std::string VariablesArray::current() {
	return variables[currentPosition];
}

bool VariablesArray::hasNext() {
	return (currentPosition < size()) ? true : false;
}

bool VariablesArray::hasPrevious() {
	return (currentPosition > 0) ? true : false;
}

VariablesCollection*& VariablesArray::bindValues(std::vector<int> values) {
	VariablesCollection* collection = new VariablesCollection();

	first();

	for (int value : values) {
		if (hasNext()) {
			collection->add(new Variable(current(), value));
			next();
		} else {
			return collection;
		}
	}

	return collection;
}

VariablesArray* VariablesArray::remove(std::string str) {
	first();

	while (hasNext()) {
		if (current() == str) {
			variables.erase(std::remove(variables.begin(), variables.end(), current()), variables.end());
		
			return this;
		}
	}

	first();

	return this;
}