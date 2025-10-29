#include <iostream>
#include <iomanip>

int main(void) {
    double num = 1.;
    int power, i;
    std::cout << "Give n (precise to 50): ";
    std::cin >> power;
    for (i = 0; i < power; i++) {
        num /= 2.0;
    }
    std::cout << std::fixed << std::setprecision(20);
    std::cout << "the negative n-th power of two value is: " << num;
    return 0;
}