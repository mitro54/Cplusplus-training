#include <iostream>
#include <string>

std::string whitespace_cleaner(std::string str) {
    int start, end;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            start = i;
            for (int j = i; j < str.length(); j++) {
                if (str[j] != ' ') {
                    end = str[j];
                    i = j;
                    std::cout << start << " " << end - start;
                    str.erase(start, end - start);
                }
            }
        }
    }
    return str;
}

int main(void) {
    std::string str;
    // std::cout << "Give a string: ";
    // std::getline(std::cin, str);
    std::cout << whitespace_cleaner("testing  testing");
    return 0;
}