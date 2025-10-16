#include <iostream>
#include <ctime>

struct Date {
	int year;
	int month;
	int day;
};

Date today(void) {
    Date today;
	time_t t = time(NULL);
    tm tl = *localtime(&t);
    today.year = tl.tm_year + 1900;
    today.month = tl.tm_mon + 1;
    today.day = tl.tm_mday;
    return today;
}

int main(void) {
	Date t = today();
	std::cout << t.year << "-" << t.month << "-" << t.day << std::endl;
	return 0;
}