#include <iostream>

int main(void) {
    unsigned short value;
    int left = 15, right = 0;
    bool is_palindrome = true;
    std::cout << "Input a number: ";
    std::cin >> value;

    while (left > right) {
        int bitleft = (value >> left) & 1;
        int bitright = (value >> right) & 1;

        if (bitleft != bitright) {
            is_palindrome = false;
            break;
        }
        --left;
        ++right;
    }

    if (is_palindrome) std::cout << value << " is a bitwise palindrome"; 
    else std::cout << value << " is not a bitwise palindrome";
    return 0;
}