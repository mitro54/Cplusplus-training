#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct AddVectors {
    int operator() (int a, int b) {
    return a + b;
  }
};

struct MultiplyVectors {
    int operator() (int a, int b) {
    return a * b;
  }
};

int main() {
	std::vector<int> valuesA = { 1, 5, 2, 6, 3 };
	std::vector<int> valuesB = { 2, 3, 1, 3, 4 };
	std::vector<int> valuesC = { 2, 1, 5, 2, 1 };
	std::vector<int> results(valuesA.size());
	int value;
	std::cin >> value;

    // result = A + B * C + value

    // B * C
    std::transform(valuesB.begin(), valuesB.end(), valuesC.begin(), results.begin(), MultiplyVectors());
    
    // A + result
    std::transform(results.begin(), results.end(), valuesA.begin(), results.begin(), AddVectors());

    // result + value for each
    for (int n : results) std::cout << n + value << " ";

	return 0;
}