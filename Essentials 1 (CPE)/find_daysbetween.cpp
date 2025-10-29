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

int days_in_year(int year) {
    if (is_leap(year)) return 366;
    return 365;
}

int days_between(Date d1, Date d2) {
    if (d1.year > d2.year) return -1;
    else if (d1.year == d2.year && day_of_year(d1) > day_of_year(d2)) return -1;
    else if (d1.year == d2.year)
        return day_of_year(d2) - day_of_year(d1);

    int day_count = 0;
    day_count += (days_in_year(d1.year) - day_of_year(d1)) + day_of_year(d2);

    for (int y = d1.year + 1; y < d2.year; y++)
    day_count += days_in_year(y);

    return day_count;
}

int main(void) {

	Date since, to;
	std::cout << "Enter first date (d m y): ";
	std::cin >> since.day >> since.month >> since.year;
	std::cout << "Enter second date (d m y): ";
	std::cin >> to.day >> to.month >> to.year;
	std::cout << days_between(since, to) << std::endl;
	return 0;
}