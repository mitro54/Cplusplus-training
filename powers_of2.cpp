#include <iostream>

int main(void) {
    unsigned long long num = 1;
    int power, i;
    std::cout << "Give n: ";
    std::cin >> power;
    if (power < 64 && power >= 0) {
        for (i = 0; i < power; i++) {
            num *= 2;
        }
        std::cout << "the n-th power of two value is: " << num;        
    } else {
        std::cout << "Make sure you only use numbers of range 0-63";
    }
    return 0;
}