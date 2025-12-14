#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>

template <class T> void print(T start, T end) {
	for (; start != end; ++start) {
		std::cout << *start << " ";
	}
}

int main() {
	std::vector<int> v1 = { 3, 4, 5, 4, 4, 5, 3, 4 };
	std::vector<int> v2 = { 3, 3, 2, 1, 5, 6, 9, 4 };
	std::vector<int> resultsEqual(v1.size());
	std::vector<int> resultsLess(v1.size());
	std::vector<int> resultsGreater(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), resultsEqual.begin(), std::equal_to<int>());
	transform(v1.begin(), v1.end(), v2.begin(), resultsLess.begin(), std::less <int>());
	transform(v1.begin(), v1.end(), v2.begin(), resultsGreater.begin(), std::greater<int>());
	print(v1.begin(), v1.end()); std::cout << std::endl;
	print(v2.begin(), v2.end()); std::cout << std::endl;
	print(resultsEqual.begin(), resultsEqual.end()); std::cout << std::endl;
	print(resultsLess.begin(), resultsLess.end()); std::cout << std::endl;
	print(resultsGreater.begin(), resultsGreater.end()); std::cout << std::endl;
	return 0;
}
