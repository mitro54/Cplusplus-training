#include <iostream>
#include <string>

int main(void) {
    std::string pattern, sample, nums = "0123456789", chars = "abcdefghijklmnopqrstuvwxyz";
    std::cout << "A pattern detector\n"
            << "D for digit, A for english character,"
            << " any special char for that specific char, ? for any character.\n"
            << "For example, DAD? would match pattern digit, alphabet, digit, any char.\nEnter pattern: ";
    std::cin >> pattern;

    std::cout << "\nEnter a sample text to find the pattern from: ";
    std::getline(std::cin, sample);

    for (int i = 0; i < pattern.length(); i++) {
        if (pattern[i] == '?') continue;
    }

    return 0;
}