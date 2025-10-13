#include <iostream>

int main(void) {
// Prints time between start time and end time
    struct TIME {
    int hh, mm;
    };

    TIME start, end, day;
    int start_minutes, end_minutes, minutes_left;

    std::cout << "Start time hh mm: ";
    std::cin >> start.hh >> start.mm;
    std::cout << "\nEnd time hh mm: ";
    std::cin >> end.hh >> end.mm;

    start_minutes = (start.hh * 60) + start.mm;
    end_minutes = (end.hh * 60) + end.mm;

    // make sure end time is bigger than start time
    if (end_minutes > start_minutes) {
        minutes_left = end_minutes - start_minutes;

        for (int i = 0; i < minutes_left + 1; i++) {
            day.mm += 1;
            if (day.mm > 59) {
                day.mm = 0;
                day.hh += 1;
            }
            if (day.hh > 23) day.hh = 0;
        }
        
        if (day.mm < 10) std::cout << day.hh << ':' << '0' << day.mm;
        else std::cout << day.hh << ':' << day.mm;

    } else std::cout << "Bad data - sorry!";

    return 0;
}