#include <iostream>

int main(void) {
    int year, a, b, c, d, e;
    std::cout << "Insert year to find date of Easter: ";
    std::cin >> year;

    // Gauss's Easter Algorithm
    a = year % 19;
    b = year % 4;
    c = year % 7;
    d = ((a * 19) + 24) % 30;
    e = ((2 * b) + (4 * c) + (6 * d) + 5) % 7;
    if (d + e < 10) {
        std::cout << "March " << d + e + 22;
    } else {
        std::cout << "April " << d + e - 9;
    }

    return 0;
}