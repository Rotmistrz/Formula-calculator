#include "stdafx.h"
#include "Constant.h"


Constant::Constant(int value) : value(value) {
}

Constant::~Constant() {
}

double Constant::calculateValue() {
	return value;
}