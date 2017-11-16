#pragma once
#include "OperationNode.h"
class DivisionNode :
	public OperationNode {
public:
	static const std::string SYMBOL;

	DivisionNode();
	~DivisionNode();

	double calculateValue(VariablesCollection* variables);

	Node* createDefaultChild();

	int declaredChildrenAmount();

	std::string toString();

	Node* clone();
};

