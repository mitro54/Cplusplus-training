#include <iostream>
#include <iomanip>

int main(void) {
    double result = 1.0;
    long i, j, denom = 3;
    bool flipper = false;
    std::cout << "How many iterations?: ";
    std::cin >> i;

    for (j = 2; j <= i; j++) {
        if (j == 2) {
        result -= 1.0 / denom;
        flipper = true;                  
        } else {
            denom += 2;
            if (flipper) {
                result += 1.0 / denom;
            } else {
                result -= 1.0 / denom;   
            }
            flipper = !flipper;
        }
    }
    // maximum of 15 precise decimals due to double type limitations
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Pi = " << 4.0 * result;
    return 0;
}