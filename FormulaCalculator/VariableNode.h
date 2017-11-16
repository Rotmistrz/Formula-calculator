#pragma once
#include "Node.h"
class VariableNode :
	public Node {
public:
	VariableNode(std::string name);
	~VariableNode();

	NodeType getNodeType();

	double calculateValue(VariablesCollection* variables);
	Node* createDescendants(StringParser* parser, VariablesArray* variables);
	
	std::string toString();
	StringParser* getFormula(StringParser* parser);

	Node* clone();

	Node* addNode(Node* node, VariablesArray* variables);

	VariablesArray* createVariablesArray(VariablesArray* variables);

	Node* find(int currentLevel, int level);
private:
	std::string name;
};

