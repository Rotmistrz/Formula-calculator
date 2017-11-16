#include "stdafx.h"

std::vector<std::string> split(std::string str, char separator) {
	std::vector<std::string> result = std::vector<std::string>();

	std::string::size_type i = 0;
	std::string::size_type j = str.find(separator);

	if (j == std::string::npos) {
		result.push_back(str.substr(i));

		return result;
	}

	while (j != std::string::npos) {
		result.push_back(str.substr(i, j - i));
		i = ++j;
		j = str.find(separator, j);

		if (j == std::string::npos) {
			result.push_back(str.substr(i, str.length()));
		}
	}

	return result;
}

int strToInt(std::string str) {
	std::stringstream ss;
	int temp;
	ss << str;
	ss >> temp;

	return temp;
}

std::string& trim(std::string& str) {
	//std::cout << "Przygtowanie wzorca na spacje w srodku" << std::endl;
	std::regex multispacePattern = std::regex("( ){2,}");

	//std::cout << "Usuwane spacje w srodku" << std::endl;
	str = std::regex_replace(str, multispacePattern, " ");

	int len = str.size();

	std::size_t found = str.find(" ");

	if (found == 0) {
		str = str.substr(1);
	}

	len = str.size();

	found = str.rfind(" ");
	
	if (found == len - 1) {
		str = str.substr(0, len - 1);
	}

	return str;
}

/** old trim
std::string& trim(std::string& str) {
	std::regex multispacePattern = std::regex("( ){2,}");

	str = std::regex_replace(str, multispacePattern, " ");

	std::regex spaceBeginPattern = std::regex("^ (.*)+");

	str = std::regex_replace(str, spaceBeginPattern, "$1");

	std::regex spaceEndPattern = std::regex("^(.*)+ $");

	str = std::regex_replace(str, spaceEndPattern, "$1");

	return str;
}**/