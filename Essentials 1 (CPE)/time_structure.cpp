#include <iostream>

int main(void) {
    struct TIME {
    int hh, mm;
    } day;
    int add_time, add_minutes;

    std::cout << "Hours: ";
    std::cin >> day.hh;
    std::cout << "\nMinutes: ";
    std::cin >> day.mm;
    std::cout << "\nAdd minutes to time: ";
    std::cin >> add_minutes;

    for (int i = 0; i < add_minutes; i++) {
        day.mm += 1;
        if (day.mm > 59) {
            day.mm = 0;
            day.hh += 1;
        }
        if (day.hh > 23) day.hh = 0;
    }
    
    if (day.mm < 10) std::cout << day.hh << ':' << '0' << day.mm;
    else std::cout << day.hh << ':' << day.mm;
    return 0;
}