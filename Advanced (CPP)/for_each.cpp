#include <iostream>
#include <algorithm>
#include <vector>

void print_square(int &value) {
    std::cout << value * value << ' ';
}

int main() {
	std::vector<int>v1 = { 3, 5, 6, 8, 9 };
	for_each(v1.begin(), v1.end(), print_square);
    std::cout << std::endl;
	for_each(v1.rbegin(), v1.rend(), print_square);
	return 0;
}