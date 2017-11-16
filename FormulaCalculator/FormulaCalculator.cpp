// FormulaCalculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	std::string line;
	std::vector<std::string> commandParts;
	std::vector<std::string> list;

	int commandId = 0;

	StringParser* parser = nullptr;

	std::string command;
	std::string formula;
	int arg0, arg1, arg2, arg3;

	Tree* tree = nullptr;

	VariablesCollection* variablesCollection = nullptr;

	std::regex oneParameterPattern = std::regex("^" + PRINT + "|" + VARS + "|" + EXIT + "$");
	std::regex manyParametersPattern = std::regex("^" + COMP + "( [0-9]+)*$");
	std::regex manyParametersPattern02 = std::regex("^(" + ENTER + "|" + JOIN + ") (.)+$");
	std::regex oneArgumentPattern = std::regex("^" + RESET_ROOT + " [0-9]+$");

	do {
		std::cout << std::endl << std::endl;

		/**std::cout << std::endl << std::endl << MVEC + " <len> <def> - creates new vector";
		std::cout << std::endl << LEN + " <len> - changes vector's length";
		std::cout << std::endl << DEF + " <off> <val> - sets the value";
		std::cout << std::endl << DEF2 + " <off0> <val0> <off1> <val1> - sets two values";
		std::cout << std::endl << DEL + " - clear all the pointers";**/
		std::cout << std::endl << COMP + " <var0 <var1> ... <varN> - bind variables with values and calculate the result";
		std::cout << std::endl << JOIN + " <formula> - join to the current tree";
		std::cout << std::endl << RESET_ROOT + " <level> - resets root";
		std::cout << std::endl << PRINT + " - prints the current tree";
		std::cout << std::endl << VARS + " - prints declared vars";
		std::cout << std::endl << EXIT + " - ends the program";
		std::cout << std::endl << std::endl << "Your command: ";

		std::getline(std::cin, line);

		if (regex_match(line, oneParameterPattern)) {
			if (line == EXIT) {
				commandId = -1;
			} else if (line == PRINT) {
				if (parser) {
					delete parser;

					parser = nullptr;
				}

				if (tree) {
					parser = tree->getFormula();

					std::cout << parser->toString();
				} else {
					std::cout << std::endl;
				}
			} else if (line == VARS) {
				if (tree) {
					VariablesArray* variables;

					variables = tree->getVariables();

					variables->first();

					while (variables->hasNext()) {
						std::cout << variables->current() << " ";

						variables->next();
					}

					variables->first();
				}
			}
		} else if (regex_match(line, manyParametersPattern)) {
			if (tree) {
				commandParts = split(line, ' ');

				command = commandParts[0];

				commandParts.erase(commandParts.begin());

				VariablesArray* variables;

				variables = tree->getVariables();

				if (commandParts.size() != variables->size()) {
					std::cout << "There was put wrong amount of variables.";
				} else {
					std::vector<int> values = std::vector<int>();

					std::cout << "VariablesArray size: " << variables->size() << std::endl;
					std::cout << "CommandParts size: " << commandParts.size() << std::endl;

					for (std::string stringValue : commandParts) {
						values.push_back(strToInt(stringValue));
					}

					variablesCollection = variables->bindValues(values);

					std::cout << "VC size: " << variablesCollection->size() << std::endl;

					std::cout << tree->calculate(variablesCollection);

					delete variablesCollection;

					variablesCollection = nullptr;
				}
			} else {
				std::cout << "There's no declared tree.";
			}
		} else if (regex_match(line, manyParametersPattern02)) {
			if (parser) {
				delete parser;

				parser = nullptr;
			}

			std::size_t found = line.find(" ");
			
			command = line.substr(0, found);

			int commandLen = command.size();

			formula = line.substr(commandLen);

			if (command == ENTER) {
				if (tree) {
					delete tree;

					tree = nullptr;
				}

				tree = Tree::createFromString(formula);

				std::cout << std::endl;
			} else if(command == JOIN) {
				Tree* newTree = Tree::createFromString(formula);

				if (tree) {
					tree->join(newTree);
				} else {
					tree = newTree;
				}
			}
		} else if (regex_match(line, oneArgumentPattern)) {
			commandParts = split(line, ' ');

			arg0 = strToInt(commandParts[1]);

			if (tree) {
				tree->resetRoot(arg0);
			} else {
				std::cout << "Tree is not defined. You cannot reset root.";
			}
		} else {
			std::cout << "Wrong command.";
			std::cout << std::endl;
		}
	} while (commandId != -1);

	if (tree) {
		delete tree;
	}

	if (parser) {
		delete parser;
	}

    return 0;
}

