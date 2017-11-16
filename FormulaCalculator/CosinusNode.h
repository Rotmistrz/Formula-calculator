#pragma once
#include "OperationNode.h"
class CosinusNode :
	public OperationNode {
public:
	static const std::string SYMBOL;

	CosinusNode();
	~CosinusNode();

	int declaredChildrenAmount();

	double calculateValue(VariablesCollection* variables);

	Node* createDefaultChild();

	std::string toString();

	Node* clone();
};