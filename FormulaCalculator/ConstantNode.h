#pragma once
#include "Node.h"
class ConstantNode :
	public Node {
public:
	ConstantNode(int value);
	~ConstantNode();

	double calculateValue(VariablesCollection* variables);
	Node* createDescendants(StringParser* parser, VariablesArray* variables);

	NodeType getNodeType();

	std::string toString();

	StringParser* getFormula(StringParser* parser);

	Node* clone();

	Node* addNode(Node* node, VariablesArray* variables);

	VariablesArray* createVariablesArray(VariablesArray* variables);

	Node* find(int currentLevel, int level);
private:
	int value;
};