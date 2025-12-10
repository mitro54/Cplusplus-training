#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
std::vector<int> values = { 1, 5, 6, 7, 8 };
std::vector<int> reversed(values.size());
std::vector<int> checked(values.size());

for (auto i = 0; i<reversed.size(); i++) std::cin >> reversed[i];

reverse_copy(reversed.begin(), reversed.end(), checked.begin());

if (checked == values) std::cout << "Palindrome" << '\n';
else std::cout << "Not palindrome" << '\n';
return 0;
}
