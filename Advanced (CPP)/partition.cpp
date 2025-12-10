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

struct Check
{
	bool operator()(const int & lhs) const {
		if (lhs % 3 == 0) return true;
		if (std::to_string(lhs).find("3") != std::string::npos) return true;
		return false;
	}
};


int main() {
	std::vector<int> results(40);
	generate(results.begin(), results.end(), Generate());
	auto partDivisor = partition(results.begin(), results.end(), Check());
	for (auto it = results.begin(); it != results.end(); ++it) {
		if (it == partDivisor) std::cout << '\n';
		std::cout << *it << " ";
	}

	return 0;
}