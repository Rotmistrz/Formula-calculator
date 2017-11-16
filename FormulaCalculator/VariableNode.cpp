#include "stdafx.h"
#include "VariableNode.h"

VariableNode::VariableNode(std::string name) : name(name) {
}


VariableNode::~VariableNode() {
}

Node* VariableNode::clone() {
	VariableNode* node = new VariableNode(name);

	return node;
}

std::string VariableNode::toString() {
	return name;
}

NodeType VariableNode::getNodeType() {
	return NODE_TYPE_VARIABLE;
}

double VariableNode::calculateValue(VariablesCollection* variables) {
	Variable* var = variables->get(name);

	return var->getValue();
}

Node* VariableNode::createDescendants(StringParser* parser, VariablesArray* variables) {
	variables->add(toString());
	
	return this;
}

StringParser* VariableNode::getFormula(StringParser* parser) {
	return parser->add(toString());
}

Node* VariableNode::addNode(Node* node, VariablesArray* variables) {
	variables->remove(name);

	return node;
}

Node* VariableNode::find(int currentLevel, int level) {
	if (currentLevel == level) {
		return this;
	} else {
		return nullptr;
	}
}

VariablesArray* VariableNode::createVariablesArray(VariablesArray* variables) {
	variables->add(name);
	
	return variables;
}