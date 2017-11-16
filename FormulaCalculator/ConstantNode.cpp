#include "stdafx.h"
#include "ConstantNode.h"


ConstantNode::ConstantNode(int value) : value(value) {
}


ConstantNode::~ConstantNode() {
}

std::string ConstantNode::toString() {
	return std::to_string(value);
}

NodeType ConstantNode::getNodeType() {
	return NODE_TYPE_CONSTANT;
}

double ConstantNode::calculateValue(VariablesCollection* variables) {
	return value;
}

Node* ConstantNode::createDescendants(StringParser* parser, VariablesArray* variables) {
	return this;
}

StringParser* ConstantNode::getFormula(StringParser* parser) {
	return parser->add(toString());
}

Node* ConstantNode::clone() {
	ConstantNode* node = new ConstantNode(value);

	return node;
}

Node* ConstantNode::addNode(Node* node, VariablesArray* variables) {
	return node;
}

Node* ConstantNode::find(int currentLevel, int level) {
	if (currentLevel == level) {
		return this;
	} else {
		return nullptr;
	}
}

VariablesArray* ConstantNode::createVariablesArray(VariablesArray* variables) {
	return variables;
}