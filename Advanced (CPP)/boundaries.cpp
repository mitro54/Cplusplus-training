#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Generate {
	int n;
	Generate() : n(0) {}
	int operator()() {
		n++;
		return n;
	}
};


int main() {
	std::vector<int> results(20);
	generate(results.begin(), results.end(), Generate());
	auto lower_it = lower_bound(results.begin(), results.end(), 5);
	auto upper_it = upper_bound(results.begin(), results.end(), 11);
	for (auto it = lower_it; it != upper_it; ++it)
		std::cout << *it << ' ';

	return 0;
}
