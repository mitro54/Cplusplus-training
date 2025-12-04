#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int main() {
	std::vector<double> values = 
		{ 2.1, 3.14, 2.2, 1.1, 2.11, 3.2, 3.6, 2.5, 2.6, 4.11, 4.12, 3.11, 3.73, 4.83};
	unsigned start_value;
	std::cin >> start_value;
	unsigned stop_value;
	std::cin >> stop_value;

    auto it = std::count_if(values.begin(), values.end(),
    [start_value, stop_value](double x) { return x >= start_value && x <= stop_value; });

    std::cout << it << " elements are in the given range.";

	return 0;
}