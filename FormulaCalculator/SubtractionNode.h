#pragma once
#include "OperationNode.h"
class SubtractionNode :
	public OperationNode {
public:
	static const std::string SYMBOL;

	SubtractionNode();
	~SubtractionNode();

	int declaredChildrenAmount();

	double calculateValue(VariablesCollection* variables);

	Node* createDefaultChild();

	std::string toString();

	Node* clone();
};

