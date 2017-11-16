#include "stdafx.h"
#include "Node.h"

Node::Node() {
}


Node::~Node() {
}

Node* Node::createFromString(std::string str) {
	std::regex constantPattern = std::regex("^[0-9]+$");

	std::regex operationPattern = std::regex("^([" + SubtractionNode::SYMBOL + AdditionNode::SYMBOL + MultiplicationNode::SYMBOL + DivisionNode::SYMBOL + "]+(.*)*|" + CosinusNode::SYMBOL + "|" + SinusNode::SYMBOL + ")$");

	Node* node;

	if (regex_match(str, operationPattern)) {
		std::cout << "This is operation " << str << std::endl;

		if (str == SinusNode::SYMBOL) {
			node = new SinusNode();
		} else if (str == CosinusNode::SYMBOL) {
			node = new CosinusNode();
		} else {
			str = str.substr(0, 1);

			if (str == AdditionNode::SYMBOL) {
				node = new AdditionNode();
			} else if (str == SubtractionNode::SYMBOL) {
				node = new SubtractionNode();
			} else if (str == MultiplicationNode::SYMBOL) {
				node = new MultiplicationNode();
			} else if (str == DivisionNode::SYMBOL) {
				node = new DivisionNode();
			} else {
				node = new ConstantNode(0);
			}
		}
	} else if (regex_match(str, constantPattern)) {
		std::cout << "This is constant " << str << std::endl;

		node = new ConstantNode(strToInt(str));
	} else {
		std::regex pattern = std::regex("[^0-9a-zA-Z]");

		str = regex_replace(str, pattern, "");

		if (!str.empty() && !regex_match(str, constantPattern)) {
			std::cout << "This is variable " << str << std::endl;
		
			node = new VariableNode(str);
		} else {
			std::cout << "Wrong variable name " << str << std::endl;
			std::cout << "Created default constant 0." << std::endl;

			node = new ConstantNode(0);
		}
	}

	return node;
}