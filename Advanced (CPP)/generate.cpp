#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//  Tn = n(n + 1) / 2
struct Triangulate {
    int n;
    Triangulate(int start_n = 1) : n(start_n) {};
    int operator() () {
    int result = (n * (n + 1)) / 2;
    n++;
    return result;
  }
};

int main() {
	std::vector<int> resultsSmall(6);
	int count;
	std::cin >> count;
	std::vector<int> results(count);

	std::generate(resultsSmall.begin(), resultsSmall.end(), Triangulate());
	std::generate_n(results.begin(), count, Triangulate());

    for (int i : resultsSmall) std::cout << i << ' ';
    std::cout << '\n';
    for (int i : results) std::cout << i << ' ';
	
	return 0;
}