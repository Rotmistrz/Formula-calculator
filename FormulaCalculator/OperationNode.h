#pragma once

#include "stdafx.h"

class OperationNode :
	public Node {
public:
	OperationNode();
	virtual ~OperationNode();

	NodeType getNodeType();

	OperationNode* addChild(Node* node);

	int childrenAmount();

	virtual Node* createDefaultChild() = 0;

	virtual int declaredChildrenAmount() = 0;

	Node* createDescendants(StringParser* parser, VariablesArray* variables);

	virtual StringParser* getFormula(StringParser* parser);

	virtual std::vector<Node*> cloneChildren();

	virtual Node* addNode(Node* node, VariablesArray* variables);

	Node* find(int currentLevel, int level);

	virtual VariablesArray* createVariablesArray(VariablesArray* variables);
protected:
	std::vector<Node*> children;
};

