#include <iostream>

int main(void) {
    int msys;
    float m, ft, in;

    std::cout << "Which system are you converting to?\n1 for metric, 2 for imperial: ";
    std::cin >> msys;
    if (msys == 1) {
        // metric
    } else if (msys == 2) {
        // imperial
    } else {
        std::cout << "unrecognized system, select 1 or 2";
    }

    return 0;
}