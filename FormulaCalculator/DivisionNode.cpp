#include "stdafx.h"
#include "DivisionNode.h"

const std::string DivisionNode::SYMBOL = "/";

DivisionNode::DivisionNode() {
}


DivisionNode::~DivisionNode() {
}

int DivisionNode::declaredChildrenAmount() {
	return 2;
}

double DivisionNode::calculateValue(VariablesCollection* variables) {
	int childrenLength = childrenAmount();

	if (childrenLength == 0) {
		return createDefaultChild()->calculateValue(variables);
	}

	double division = children[0]->calculateValue(variables);

	for (int i = 1; i < childrenLength; i++) {
		division /= children[i]->calculateValue(variables);
	}

	return division;
}

Node* DivisionNode::createDefaultChild() {
	return new ConstantNode(1);
}

std::string DivisionNode::toString() {
	return DivisionNode::SYMBOL;
}

Node* DivisionNode::clone() {
	DivisionNode* node = new DivisionNode();
	node->children = cloneChildren();

	return node;
}