#include <iostream>

int main(void) {
    unsigned long num;
    int count = 0;
    std::cout << "Input any number: ";
    std::cin >> num;
    for (int i = 0; i < 32; i++) {
        count += (num & 1);
        num >>= 1;
    }
    std::cout << "Found " << count << " set bits (1's) from the inputs binary.";
    return 0;
}