#pragma once
#include "OperationNode.h"
class SinusNode :
	public OperationNode {
public:
	static const std::string SYMBOL;

	SinusNode();
	~SinusNode();

	int declaredChildrenAmount();

	double calculateValue(VariablesCollection* variables);

	Node* createDefaultChild();

	std::string toString();

	Node* clone();
};

