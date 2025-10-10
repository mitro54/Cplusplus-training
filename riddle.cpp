#include <iostream>
// Task is: Imagine square shaped helix made of blocks, each block is numbered.
// This programs  purpose is to find the bottom right squares number,
// No matter the square size. Side length has to be odd.
// Center is 1, then goes up for 2, then right for 3, then down 4, etc, making a helix.

// Odd version of finding the square, then square - (side + side + 2)

int main(void) {
    int len, r;
    std::cout << "Provide a length of the helix: ";
    std::cin >> len;
    r = len * len - (len + len - 2);
    std::cout << r;
    return 0;
}