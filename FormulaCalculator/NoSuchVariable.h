#pragma once
#include "Variable.h"
class NoSuchVariable :
	public Variable {
public:
	NoSuchVariable();
	~NoSuchVariable();

	bool isUndefined();
};

