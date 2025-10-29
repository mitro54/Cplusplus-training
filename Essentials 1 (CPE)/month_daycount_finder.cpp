#include <iostream>

bool is_leap(int year) {
    if (year % 400 == 0) return true;
    else if (year % 4 == 0 && year % 100 != 0) return true;
    return false;
}

int month_length(int year, int month) {
    if (year > 0 && month > 0) {
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (is_leap(year)) months[1] = 29;
        return months[month - 1];
    }
}

int main(void) {

	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			std::cout << month_length(yr,mo) << " ";
		std::cout << std::endl;
	}
	return 0;
}