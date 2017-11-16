#include "stdafx.h"
#include "AdditionNode.h"

const std::string AdditionNode::SYMBOL = "+";

AdditionNode::AdditionNode() {
}

AdditionNode::~AdditionNode() {

}

int AdditionNode::declaredChildrenAmount() {
	return 2;
}

double AdditionNode::calculateValue(VariablesCollection* variables) {
	double sum = 0;

	for (Node* child : children) {
		sum += child->calculateValue(variables);
	}

	return sum;
}

Node* AdditionNode::createDefaultChild() {
	return new ConstantNode(0);
}

std::string AdditionNode::toString() {
	return AdditionNode::SYMBOL;
}

Node* AdditionNode::clone() {
	AdditionNode* node = new AdditionNode();
	node->children = cloneChildren();

	return node;
}