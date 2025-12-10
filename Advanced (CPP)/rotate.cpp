#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    // rotate the rotated vector to match the values vector.
	std::vector<int> values = { 8, 1, 5, 6, 7 };
	std::vector<int> rotated = {5, 6, 7, 8, 1};

    std::vector < int >::iterator it = rotated.begin();
    advance(it, 3);
    rotate(rotated.begin(), it, rotated.end());
    // another solution:
    // rotate(rotated.begin(), rotated.begin() + 3, rotated.end());

  
	if (rotated== values) std::cout << "You did it" << '\n';
	else std::cout << "Try again" << '\n';
	return 0;
}