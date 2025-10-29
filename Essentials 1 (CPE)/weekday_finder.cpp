#include <iostream>

int main(void) {
    int dd, mm, yy;

    std::cout << "Give date in three parts to find out what weekday was on that date.\n";

    std::cout << "Day: ";
    std::cin >> dd;

    std::cout << "Month: ";
    std::cin >> mm;

    std::cout << "Year: ";
    std::cin >> yy;

    // Zeller's congruence
    mm -= 2;
    if (mm <= 0) {
        mm += 12;
        yy -= 1;
    }
    mm = (mm *= 83) / 32;
    mm += dd;
    mm += yy;
    mm += (yy / 4);
    mm -= (yy / 100);
    mm += (yy / 400);
    mm %= 7;

    std::cout << "0: Sunday, 1: Monday, 2: Tuesday, 3: Wednesday, 4: Thursday, 5: Friday, 6: Saturday\n";
    std::cout << "Weekday on the given date: " << mm;
    return 0;
}