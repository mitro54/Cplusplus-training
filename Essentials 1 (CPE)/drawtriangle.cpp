#include <iostream>

int main() {
    int size, height, asterisks, outspaces;
    std::cout << "Provide a size of the base for the triangle: ";
    if (!(std::cin >> size) || size < 1) {
        std::cout << "Only positive integers allowed.\n";
        return 0;
    }

    if (size % 2 == 0) --size;
    height = (size + 1) / 2;

    for (int row = 0; row < height; ++row) {
        asterisks = 2 * row + 1;
        outspaces = (size - asterisks) / 2;

        std::cout << ' ';
        for (int i = 0; i < outspaces; ++i) std::cout << ' ';
        for (int i = 0; i < asterisks; ++i) std::cout << '*';
        for (int i = 0; i < outspaces; ++i) std::cout << ' ';
        std::cout << " \n";
    }
    return 0;
}