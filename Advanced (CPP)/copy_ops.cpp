#include <iostream>
#include <vector>
#include <algorithm>

void print(const int & value) {
	std::cout << value << " ";
}

int main() {
	std::vector<int> v1 = {5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
	std::vector<int> v2(10);
	std::vector<int> v3(10);
	unsigned start_value;
	std::cin >> start_value;
	unsigned stop_value;
	std::cin >> stop_value;

	// code

	for_each(v1.begin(), v1.end(), print); std::cout << '\n';
	for_each(v2.begin(), v2.end(), print); std::cout << '\n';
	for_each(v3.begin(), v3.end(), print); std::cout << '\n';
	return 0;							  
}