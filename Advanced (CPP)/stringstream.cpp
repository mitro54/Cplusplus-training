#include <iostream>
#include <string>
#include <sstream>

int main() {
	std::string line;
	getline(std::cin, line);
	std::stringstream s(line);
	std::string token;
	while(getline(s, token, ':'))
			std::cout << token << std::endl;
	return 0;
}