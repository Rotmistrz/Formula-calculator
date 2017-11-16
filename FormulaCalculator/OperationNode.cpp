#include "stdafx.h"
#include "OperationNode.h"

OperationNode::OperationNode() {
	children = std::vector<Node*>();
}

OperationNode::~OperationNode() {
	for (Node* child : children) {
		delete child;
	}
}

NodeType OperationNode::getNodeType() {
	return NODE_TYPE_OPERATION;
}

int OperationNode::childrenAmount() {
	return children.size();
}

OperationNode* OperationNode::addChild(Node* node) {
	children.push_back(node);

	return this;
}

Node* OperationNode::createDescendants(StringParser* parser, VariablesArray* variables) {
	int amount = declaredChildrenAmount();
	
	for (int i = 0; i < amount; i++) {
		Node* child;

		if (parser->hasNext()) {
			child = Node::createFromString(parser->current());

			parser->next();

			child->createDescendants(parser, variables);
		} else {
			child = createDefaultChild();

			std::cout << std::endl << "There was lacking element. Filled with " + child->toString();
		}

		addChild(child);
	}

	return this;
}

StringParser* OperationNode::getFormula(StringParser* parser) {
	parser->add(toString());

	for (Node* child : children) {
		parser = child->getFormula(parser);
	}

	return parser;
}

std::vector<Node*> OperationNode::cloneChildren() {
	std::vector<Node*> clonedChildren = std::vector<Node*>();

	for (Node* child : children) {
		clonedChildren.push_back(child->clone());
	}

	return clonedChildren;
}

Node* OperationNode::addNode(Node * node, VariablesArray* variables) {
	if (childrenAmount() == 0) {
		return node;
	} else {
		NodeType type = children[0]->getNodeType();
		if (type == NODE_TYPE_CONSTANT || type == NODE_TYPE_VARIABLE) {
			children[0] = children[0]->addNode(node, variables);
		} else {
			children[0]->addNode(node, variables);
		}
	}

	return this;
}

Node* OperationNode::find(int currentLevel, int level) {
	if (currentLevel == level) {
		return this;
	}
	
	Node* node = nullptr;

	for (Node* child : children) {
		node = child->find(currentLevel + 1, level);

		if (node) {
			return node;
		}
	}

	return node;
}

VariablesArray* OperationNode::createVariablesArray(VariablesArray* variables) {
	for (Node* child : children) {
		variables = child->createVariablesArray(variables);
	}

	return variables;
}