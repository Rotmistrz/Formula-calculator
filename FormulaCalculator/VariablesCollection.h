#pragma once

#include "stdafx.h"

class VariablesCollection {
public:
	VariablesCollection();
	~VariablesCollection();

	int size();

	bool contains(Variable* variable);

	VariablesCollection* add(Variable* variable);

	Variable* get(std::string name);
private:
	std::vector<Variable*> variables;
};

