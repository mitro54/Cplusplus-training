#include <iostream>
#include <vector>

int main() {
	std::vector<int> v1;
	std::vector<int> v2;
    int max_val = 5;
    std::cout << "enter max value: ";
    // std::cin >> max_val;
    if (max_val % 2 != 0) max_val++;
    for (int i = 1; i <= max_val; i++)
        (i % 2 == 0) ? v2.push_back(i) : v1.push_back(i);

    // test
    for (int n : v2) std::cout << '\n' << n;
	return 0;
}