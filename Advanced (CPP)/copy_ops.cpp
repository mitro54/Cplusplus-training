#include <iostream>
#include <vector>
#include <algorithm>

void print(const int &value) {
	std::cout << value << " ";
}

int main() {
	std::vector<int> v1 = {5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
	std::vector<int> v2(10);
	std::vector<int> v3(10);

	unsigned start_value ;
	std::cin >> start_value;
	unsigned stop_value;
	std::cin >> stop_value;
	if (start_value > stop_value) {
        std::cout << "Stop value must be greater than or equal to start value.";
        return 1;
    }

    if (start_value > 9 || stop_value > 9) {
        std::cout << "Stop value and start value must be less than or equal 9";
        return 1;
    }

    for (int i = 0, j = start_value; j < stop_value; i++, j++) {
        v2[i] = v1[j];
    }

    std::copy(v1.begin() + start_value, v1.begin() + stop_value + 1, v3.begin());

	for_each(v1.begin(), v1.end(), print); std::cout << '\n';
	for_each(v2.begin(), v2.end(), print); std::cout << '\n';
	for_each(v3.begin(), v3.end(), print); std::cout << '\n';
	return 0;							  
}