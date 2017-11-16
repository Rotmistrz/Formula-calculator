#pragma once

#include "stdafx.h"

class VariablesArray {
public:
	VariablesArray();
	~VariablesArray();

	int size();

	bool contains(std::string name);

	VariablesArray* remove(std::string str);
	VariablesArray* add(std::string name);

	VariablesArray* clear();
	VariablesArray* first();
	VariablesArray* last();
	VariablesArray* next();
	VariablesArray* previous();
	std::string current();
	bool hasNext();
	bool hasPrevious();

	VariablesCollection*& bindValues(std::vector<int> values);

private:
	int currentPosition;

	std::vector<std::string> variables;
};

