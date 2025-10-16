#include <iostream>

bool is_leap(int year) {
    if (year % 400 == 0) return true;
    else if (year % 4 == 0 && year % 100 != 0) return true;
    return false;
}

int main(void) {

	for(int yy = 1896; yy < 2001; yy++) 
		std::cout << yy << " -> " << is_leap(yy) << std::endl;
	return 0;
}