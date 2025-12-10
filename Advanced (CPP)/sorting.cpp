#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctype.h>
#include <string>

template<class T>
void print(const T & value) {
	std::cout << value << " ";
}

char t(char c) {
	if (isdigit(c))
		c += 'A';
	return tolower(c);
}

std::string toLower(const std::string & v) {
	std::string ret(v);
	transform(ret.begin(), ret.end(), ret.begin(), t);
	return ret;
}

bool ascending_caseinsensitive(const std::string & a, const std::string & b) {
	return toLower(a) < toLower(b);
}

int main() {
	std::vector <std::string> v1 = { "A0", "a1", "a0", "a2", "a3", "A4", "aA", "Ab", "AB", "b4" };
	std::vector <std::string> v2(v1);
	std::cout << int('A') << " " << int('a') << " "  << int('0') << std::endl << std::endl;
	std::cout << "Source collection:n";
	std::cout << "v1: "; 
	for_each(v1.begin(), v1.end(), print<std::string>); std::cout << std::endl;

	std::cout << "Sorting in ascending order:n";
	std::cout << "Normal sort:n";
	sort(v1.begin(), v1.end());
	std::cout << "v1: "; for_each(v1.begin(), v1.end(), print<std::string>); std::cout << std::endl;
	std::cout << "Stable sort:n";
	stable_sort(v2.begin(), v2.end(), ascending_caseinsensitive);
	std::cout << "v2: "; for_each(v2.begin(), v2.end(), print<std::string>); std::cout << std::endl << std::endl;

	return 0;
}
