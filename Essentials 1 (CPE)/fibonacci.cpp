#include <iostream>

int main(void) {
    int cycles;
    unsigned long long prev_num = 1, curr_num = 1, total = prev_num + curr_num;
    std::cout << "Provide index of the wanted fibonacci num: ";
    std::cin >> cycles;

    if (cycles <= 0) {
        std::cout << 0;
        return 0;
    }

    for (int i = 0; i < cycles - 2; i++) {
        if (cycles < 2) break;
        prev_num = curr_num;
        curr_num = total;
        total = prev_num + curr_num;
    }
    std::cout << curr_num;
    return 0;
}