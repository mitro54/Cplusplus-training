#include <iostream>

struct Date {
    int day;
    int month;
    int year;
};

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

int day_of_year(Date date) {
    int day_count = 0;
    day_count += date.day;
    for (int i = 1; i < date.month; i++) {
        day_count += month_length(date.year, i);
    }
    return day_count;
}

int main(void) {

	Date d;
	std::cout << "Enter day, month, year: ";
	std::cin >> d.day >> d.month >> d.year;
	std::cout << day_of_year(d) << std::endl;
	return 0;
}