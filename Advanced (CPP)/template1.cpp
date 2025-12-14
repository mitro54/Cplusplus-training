#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

template<class T> int signum(T value) {
	if (value < 0)
		return -1;
	if (value > 0)
		return 1;
	return 0;
}

template<class T> std::string toString(T value) {
	stringstream s;
	s << value;
	return s.str();
}


int main() {	
	int valuei;
	double valued;
	std::cin >> valuei;
	std::cin >> valued;
	std::cout << signum(valuei) << std::endl;
	std::cout << signum(valued) << std::endl;
	std::cout << toString(valuei) << std::endl;
	std::cout << toString(valued) << std::endl;
	return 0;
}