#include <iostream>
#include <set>

int main() {
	std::set<int> s1, s2;
	unsigned start_val = 1;
	//std::cin >> start_val;
	unsigned stop_val = 3;
	//std::cin >> stop_val;
    for (unsigned i = start_val; i <= stop_val; i++)
        (i % 2 == 0) ? s2.insert(i) : s1.insert(i);
    for (unsigned i = start_val; i <= stop_val; i++)
        (i % 2 == 0) ? s1.insert(i) : s2.insert(i);
        
	for (auto x1 : s1) {
		for (auto x2 : s2) {
			std::cout << x1 + x2 << " ";
		}
		std::cout << std::endl;
	}

	for (std::set<int>::reverse_iterator it1 = s1.rbegin(), it2 = s2.rbegin(); it1 != s1.rend(); ++it1, ++it2) {
		std::cout << *it1 + *it2 << " ";
	}
	std::cout << std::endl;

	for (auto it1 = s1.rbegin(), it2 = s2.rbegin(); it1 != s1.rend(); ++it1, ++it2) {
		std::cout << *it1 + *it2 << " ";
	}
	std::cout << std::endl;

	return 0;
}