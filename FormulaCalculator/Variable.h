#pragma once

#include "stdafx.h"

class Variable {
	friend class VariablesCollection;

public:
	Variable();
	Variable(std::string name, int value);
	~Variable();

	bool isUndefined();

	std::string getName();
	int getValue();

protected:
	std::string name;
	int value;
};

