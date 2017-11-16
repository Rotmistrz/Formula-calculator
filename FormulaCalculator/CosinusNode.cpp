#include "stdafx.h"
#include "CosinusNode.h"

const std::string CosinusNode::SYMBOL = "cos";

CosinusNode::CosinusNode() {
}


CosinusNode::~CosinusNode() {
}

int CosinusNode::declaredChildrenAmount() {
	return 1;
}

double CosinusNode::calculateValue(VariablesCollection* variables) {
	int childrenLength = childrenAmount();

	if (childrenLength == 0) {
		return createDefaultChild()->calculateValue(variables);
	}

	return cos(children[0]->calculateValue(variables));
}

Node* CosinusNode::createDefaultChild() {
	return new ConstantNode(0);
}

std::string CosinusNode::toString() {
	return CosinusNode::SYMBOL;
}

Node* CosinusNode::clone() {
	CosinusNode* node = new CosinusNode();
	node->children = cloneChildren();

	return node;
}