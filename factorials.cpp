#include <iostream>

int main(void) {
    unsigned long long total = 1;
    int len;
    std::cout << "Provide a num: ";
    std::cin >> len;
    for (int i = 1; i < len + 1; i++) total *= i;
    std::cout << total;
    return 0;
}