#include <iostream>
#include <vector>

int main() {
	std::vector<int> v1, v2;
    int max_val;
    std::cout << "enter max value: ";
    std::cin >> max_val;
    std::cout << std::endl;
    if (max_val % 2 != 0) max_val++;
    for (int i = 1; i <= max_val; i++)
        (i % 2 == 0) ? v2.push_back(i) : v1.push_back(i);

    for (std::vector<int>::const_iterator it1 = v1.begin(); it1 != v1.end(); it1++) {
        for (std::vector<int>::const_iterator it2 = v2.begin(); it2 != v2.end(); it2++) {
            std::cout << *it1 + *it2 << ' ';
        }
        std::cout << std::endl;
    }

    // reverses the previous output
    for (std::vector<int>::reverse_iterator it1 = v1.rbegin(); it1 != v1.rend(); it1++) {
        for (std::vector<int>::reverse_iterator it2 = v2.rbegin(); it2 != v2.rend(); it2++) {
            std::cout << *it1 + *it2 << ' ';
        }
        std::cout << std::endl;
    }

	return 0;
}