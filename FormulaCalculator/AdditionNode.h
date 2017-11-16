#pragma once

#include "stdafx.h"

class AdditionNode :
	public OperationNode {
public:
	const static std::string SYMBOL;

	AdditionNode();
	~AdditionNode();

	double calculateValue(VariablesCollection* variables);

	Node* createDefaultChild();

	int declaredChildrenAmount();

	std::string toString();

	Node* clone();
};

