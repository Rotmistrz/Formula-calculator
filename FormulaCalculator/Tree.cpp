#include "stdafx.h"
#include "Tree.h"

Tree::Tree() : root(nullptr) {
	variables = new VariablesArray();
}

Tree::Tree(Tree &tree) {
	variables = new VariablesArray();

	VariablesArray* currentVariables = tree.getVariables();

	currentVariables->first();

	while (currentVariables->hasNext()) {
		variables->add(currentVariables->current());

		currentVariables->next();
	}

	root = tree.root->clone();
}

Tree::Tree(Node* root, VariablesArray* variables) : root(root), variables(variables) {
}


Tree::~Tree() {
	delete variables;
	delete root;
}

Tree* Tree::setRoot(Node* newRoot) {
	root = newRoot;

	return this;
}

double Tree::calculate(VariablesCollection* variables) {
	return root->calculateValue(variables);
}

Tree* Tree::createFromString(std::string formula) {
	StringParser* parser = StringParser::createFromString(formula);
	VariablesArray* variables = new VariablesArray();

	Node* root;

	Tree* tree;

	if (parser->hasNext()) {
		root = Node::createFromString(parser->current());

		root->createDescendants(parser->next(), variables);

		tree = new Tree(root, variables);
	} else {
		tree = new Tree();
	}

	return tree;
}

Tree* Tree::join(Tree* tree) {
	root = root->addNode(tree->root, variables);

	return this;
}

VariablesArray* Tree::getVariables() {
	return variables;
}

StringParser*& Tree::getFormula() {
	StringParser* parser = new StringParser();

	if (root) {
		parser = root->getFormula(parser);
	}

	return parser;
}

Tree Tree::operator+(Tree tree) {
	root = root->addNode(tree.root, variables);

	return *this;
}

Tree Tree::operator=(Tree tree) {
	Node* root = tree.root->clone();

	VariablesArray* vars = new VariablesArray();

	VariablesArray* thatVariables = tree.getVariables();

	thatVariables->first();

	while (thatVariables->hasNext()) {
		vars->add(thatVariables->current());
	}

	thatVariables->first();

	Tree newTree = Tree(tree.root->clone(), vars);

	return newTree;
}

Tree* Tree::resetVariables() {
	if (variables) {
		delete variables;
	}
	
	variables = new VariablesArray();

	variables = root->createVariablesArray(variables);

	return this;
}

bool Tree::resetRoot(int level) {
	Node* found = root->find(0, level);
	Node* newRoot = nullptr;

	if (found) {
		newRoot = found->clone();

		delete root;

		root = newRoot;

		resetVariables();

		return true;
	} else {
		return false;
	}
}