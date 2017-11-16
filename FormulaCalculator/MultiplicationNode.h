#pragma once
#include "OperationNode.h"
class MultiplicationNode :
	public OperationNode {
public:
	const static std::string SYMBOL;

	MultiplicationNode();
	~MultiplicationNode();

	int declaredChildrenAmount();

	double calculateValue(VariablesCollection* variables);

	Node* createDefaultChild();

	std::string toString();

	Node* clone();
};

