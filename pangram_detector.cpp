#include <iostream>
#include <string>

int main(void) {
    std::string input, tester = "abcdefghijklmnopqrstuvwxyz";
    int arr[26] = {};
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
            std::cout << "Not a pangram";
            return 0;
        }
    }
    std::cout << "Pangram";
    return 0;
}