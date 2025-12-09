#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Counter {
    int n;
    Counter() : n(1) {};
    int operator() () {
    return n++;
  }
};

bool isThreeIncluded(int n) {
	n = std::abs(n);
	while (n > 0) {
		int digit = n % 10;
		if (digit == 3) return true;
		n /= 10;
	}
	return false;
}

struct FilterThree {
  bool operator () (const int &a) {
    if (a % 3 == 0) return true;
	if (isThreeIncluded(a)) return true;
	return false;
  }
};

int main() {
	std::vector<int> results;
	int count;
	std::cin >> count;
	results.resize(count);
	
	std::generate(results.begin(), results.end(), Counter());
	auto new_end = std::remove_if(results.begin(), results.end(), FilterThree());
	results.erase(new_end, results.end());

	for (int i : results) std::cout << i << ' ';

	
	return 0;
}