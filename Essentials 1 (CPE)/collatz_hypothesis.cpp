#include <iostream>

int main(void) {
    int c0, counter = 0;
    std::cout << "Enter a non-zero integer number: ";
    std::cin >> c0;
    if (c0 > 0) {
        while (c0 != 1) {
            counter++;
            if (c0 % 2 == 0) {
                c0 /= 2;
            } else {
                c0 = (c0 * 3) + 1;
            }
            std::cout << c0 << std::endl;
        }
    } else {
        std::cout << "Make sure you enter non-zero integer number.";
    }
    std::cout << "steps = " << counter;
    return 0;
}