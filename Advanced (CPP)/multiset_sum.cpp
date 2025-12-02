#include <iostream>
#include <set>

template <class T> void print(T start, T end) {
    for (; start != end; ++start) {
        std::cout << *start << " ";
    }
}
int main() {
	
	std::multiset <double> valuesA = { 1.1, 2.3, 2.7, 2.9, 3.5 };
	std::multiset <double> valuesB = { 2.5, 2.7, 3.14, 3.5, 3.5, 4.5 };
	double start_value, stop_value;
	std::cin >> start_value;
	std::cin >> stop_value;
	
	// add code
	
	return 0;
}