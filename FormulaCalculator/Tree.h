#pragma once

#include "stdafx.h"

class Tree {
public:
	Tree();
	Tree(Tree &tree);
	Tree(Node* root, VariablesArray* variables);
	~Tree();

	Tree operator+(Tree tree);
	Tree operator=(Tree tree);

	Tree* setRoot(Node* newRoot);
	double calculate(VariablesCollection* variables);
	VariablesArray* getVariables();
	StringParser*& getFormula();
	Tree* join(Tree* node);

	bool resetRoot(int level);
	Tree* resetVariables();

	static Tree* createFromString(std::string formula);
private:
	Node* root;
	VariablesArray* variables;
};

