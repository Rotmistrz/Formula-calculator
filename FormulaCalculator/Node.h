#pragma once

#include "stdafx.h"

class Node {
public:
	Node();
	virtual ~Node();

	virtual double calculateValue(VariablesCollection* variables) = 0;
	virtual Node* createDescendants(StringParser* parser, VariablesArray* variables) = 0;
	virtual NodeType getNodeType() = 0;
	virtual std::string toString() = 0;
	virtual StringParser* getFormula(StringParser* parser) = 0;

	static Node* createFromString(std::string str);

	virtual VariablesArray* createVariablesArray(VariablesArray* variables) = 0;

	virtual Node* clone() = 0;

	virtual Node* find(int currentLevel, int level) = 0;

	virtual Node* addNode(Node* node, VariablesArray* variables) = 0;
};