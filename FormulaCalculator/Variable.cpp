#include "stdafx.h"
#include "Variable.h"

Variable::Variable() : name(""), value(0) {
}

Variable::Variable(std::string name, int value) : name(name), value(value) {
}


Variable::~Variable() {
}

std::string Variable::getName() {
	return name;
}

int Variable::getValue() {
	return value;
}

bool Variable::isUndefined() {
	return false;
}