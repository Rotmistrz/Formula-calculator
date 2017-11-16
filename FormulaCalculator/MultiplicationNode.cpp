#include "stdafx.h"
#include "MultiplicationNode.h"

const std::string MultiplicationNode::SYMBOL = "*";

MultiplicationNode::MultiplicationNode() {
}


MultiplicationNode::~MultiplicationNode() {
}

int MultiplicationNode::declaredChildrenAmount() {
	return 2;
}

double MultiplicationNode::calculateValue(VariablesCollection* variables) {
	int childrenLength = childrenAmount();

	double product = 1;

	for (int i = 0; i < childrenLength; i++) {
		product *= children[i]->calculateValue(variables);
	}

	return product;
}

Node* MultiplicationNode::createDefaultChild() {
	return new ConstantNode(1);
}

std::string MultiplicationNode::toString() {
	return MultiplicationNode::SYMBOL;
}

Node* MultiplicationNode::clone() {
	MultiplicationNode* node = new MultiplicationNode();
	node->children = cloneChildren();

	return node;
}