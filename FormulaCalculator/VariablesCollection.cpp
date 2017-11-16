#include "stdafx.h"
#include "VariablesCollection.h"


VariablesCollection::VariablesCollection() {
	variables = std::vector<Variable*>();
}


VariablesCollection::~VariablesCollection() {
	for (Variable* var : variables) {
		delete var;
	}
}

int VariablesCollection::size() {
	return variables.size();
}

bool VariablesCollection::contains(Variable* variable) {
	if (std::find(variables.begin(), variables.end(), variable) != variables.end()) {
		return true;
	} else {
		return false;
	}
}

VariablesCollection* VariablesCollection::add(Variable* variable) {
	if (!contains(variable)) {
		variables.push_back(variable);
	}

	return this;
}

Variable* VariablesCollection::get(std::string name) {
	for (Variable* var : variables) {
		if (var->name == name) {
			return var;
		}
	}

	return new NoSuchVariable();
}