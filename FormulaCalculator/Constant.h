#pragma once
#include "Node.h"
class Constant :
	public Node {
public:
	Constant(int value);
	~Constant();

	double calculateValue();
private:
	int value;
};

