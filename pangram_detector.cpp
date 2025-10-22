#include <iostream>
#include <string>

int main(void) {
    std::string input, tester = "abcdefghijklmnopqrstuvwxyz";
    int arr[26] = {};
    bool is_a_pangram = true;
    std::cout << "Input a sentence: ";
    getline(std::cin, input);

    for (int i = 0; i < input.size(); i++) {
        int is_included = tester.find(tolower(input[i]));
        if (is_included != std::string::npos) {
            arr[is_included] += 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0) {
            is_a_pangram = false;
        }
    }

    is_a_pangram ? std::cout << "Pangram" : std::cout << "Not pangram";
    for (int i = 0; i < 26; i++) {
        std::cout << "\n" << tester[i] << '-' << arr[i];
    }

    return 0;
}