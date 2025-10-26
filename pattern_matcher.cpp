#include <iostream>
#include <string>

int main(void) {
    std::string pattern, sample, newstr, nums = "0123456789", chars = "abcdefghijklmnopqrstuvwxyz";
    std::string punct = ".,=~><|!@#$%^&*()-_+{}[]:\\/\"'";
    std::cout << "A pattern detector\n"
            << "D for digit, A for english character,"
            << " any special char for that specific char, ? for any character.\n"
            << "For example, DAD? would match a pattern of: digit, alphabet, digit, any char.\nEnter pattern: ";
    std::getline(std::cin, pattern);

    std::cout << "Enter a sample text to find the pattern from: ";
    std::getline(std::cin, sample);

    for (int i = 0; i < sample.length(); i++) {
        for (int j = 0; j < pattern.length(); j++) {
            if (pattern[j] == '?') {
                newstr.push_back(sample[i]);
                break;

            } else if (pattern[j] == 'D') {
                if (nums.find(sample[i]) != std::string::npos) {
                    newstr.push_back(sample[i]);
                    break;
                };

            } else if (pattern[j] == 'A') {
                if (chars.find(sample[i]) != std::string::npos) {
                    newstr.push_back(sample[i]);
                    break;
                } else newstr.erase();

            } else if (punct.find(sample[i]) != std::string::npos) {
                newstr.push_back(sample[i]);
                break;
            }
        }
        if (newstr.length() == pattern.length()) {
            std::cout << newstr << "\n";
            newstr.erase();
        }
    }

    return 0;
}