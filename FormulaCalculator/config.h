#pragma once

#include "stdafx.h"

const std::string RESET_ROOT = "resetroot";
const std::string ENTER = "enter";
const std::string JOIN = "join";
const std::string COMP = "comp";
const std::string PRINT = "print";
const std::string VARS = "vars";
const std::string EXIT = "exit";

enum NodeType {
	NODE_TYPE_CONSTANT,
	NODE_TYPE_VARIABLE,
	NODE_TYPE_OPERATION
};