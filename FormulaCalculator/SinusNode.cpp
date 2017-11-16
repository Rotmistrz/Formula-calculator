#include "stdafx.h"
#include "SinusNode.h"

const std::string SinusNode::SYMBOL = "sin";

SinusNode::SinusNode() { // moze dodac potomka w konstruktorze a w bezarametrowym domyslny
}


SinusNode::~SinusNode() {
}

int SinusNode::declaredChildrenAmount() {
	return 1;
}

double SinusNode::calculateValue(VariablesCollection* variables) {
	int childrenLength = childrenAmount();

	if (childrenLength == 0) {
		return createDefaultChild()->calculateValue(variables);
	}

	return sin(children[0]->calculateValue(variables));
}

Node* SinusNode::createDefaultChild() {
	return new ConstantNode(0);
}

std::string SinusNode::toString() {
	return SinusNode::SYMBOL;
}

Node* SinusNode::clone() {
	SinusNode* node = new SinusNode();
	node->children = cloneChildren();

	return node;
}