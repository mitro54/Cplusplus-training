#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct AddVectors {
    int operator() (int a, int b) {
    return a + b;
  }
};

struct SubtractVectors {
    int operator() (int a, int b) {
    return a - b;
  }
};

int main() {
	std::vector<int> values = { 6, 5, 7, 3, 4, 6, 5, 7, 3, 4 };
    std::vector<int> v1(10), v2(10), v3(10), v4(10);

	std::fill(v1.begin(), v1.end(), 3);
	std::fill(v2.begin(), v2.end(), 2);

    int input;
    std::cin >> input;

    std::fill_n(values.begin(), input, 5);
    std::transform(values.begin(), values.end(), v1.begin(), v3.begin(), AddVectors()); 
    std::transform(values.begin(), values.end(), v2.begin(), v4.begin(), SubtractVectors());

    for (int val : v3) std::cout << val << ' ';
	std::cout << '\n';
    for (int val : v4) std::cout << val << ' ';

	return 0;
}