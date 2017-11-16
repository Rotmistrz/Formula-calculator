#include "stdafx.h"
#include "SubtractionNode.h"

const std::string SubtractionNode::SYMBOL = "-";

SubtractionNode::SubtractionNode() {
}


SubtractionNode::~SubtractionNode() {
}

int SubtractionNode::declaredChildrenAmount() {
	return 2;
}

double SubtractionNode::calculateValue(VariablesCollection* variables) {
	int childrenLength = childrenAmount();

	if (childrenLength == 0) {
		return createDefaultChild()->calculateValue(variables);
	}

	double difference = children[0]->calculateValue(variables);

	for (int i = 1; i < childrenLength; i++) {
		difference -= children[i]->calculateValue(variables);
	}

	return difference;
}

Node* SubtractionNode::createDefaultChild() {
	return new ConstantNode(0);
}

std::string SubtractionNode::toString() {
	return SubtractionNode::SYMBOL;
}

Node* SubtractionNode::clone() {
	SubtractionNode* node = new SubtractionNode();
	node->children = cloneChildren();

	return node;
}