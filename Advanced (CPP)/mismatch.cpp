#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	std::vector<int> original_values = { 210, 314, 202, 110, 211, 302, 358, 229, 260, 411, 412, 311, 373, 483 };
	std::vector<int> noisy_values =    { 211, 324, 203, 113, 227, 320, 340, 210, 239, 411, 412, 333, 371, 501 };
	int diff = 15;
	
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p1 = std::mismatch(
		original_values.begin(), original_values.end(), noisy_values.begin());
    for (; p1.first != original_values.end() && p1.second != noisy_values.end(); ++p1.first, ++p1.second) {
		if (std::abs(*p1.first - *p1.second) > diff) {
			std::cout << "First difference greater than " << diff << " is found: " << *p1.first << " - " << *p1.second << '\n';
			diff++;
		}
	}
	return 0;
}