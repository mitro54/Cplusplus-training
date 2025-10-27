#include <string>
#include <iostream>

int main() {
    std::string sentence;
    // std::cout << "Text formatter. * for uppercase, _for spacing.\n";
    // std::cout << "Examples: *word* will be WORD, _word_ will be w o r d\n";
    // std::cout << "Enter a text: ";
    // std::getline(std::cin, sentence);
    sentence = "Testing testing, *big day* coming soon";

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == '*') {
            if (sentence.find('*', i + 1) == std::string::npos) continue;
            else for (int j = i + 1; j < sentence.length(); j++) {
                if (sentence[j] == '_') {
                    sentence.erase(i, 1);
                    i = j - 1;
                    break;

                } else if (sentence[j] == '*') {
                    std::string newstr = sentence.substr(i + 1, j - (i + 1));
                    sentence.erase(i, j - i);
                    sentence.insert(i, newstr);
                    break;
                }
            }
        }
    }

    std::cout << sentence << "\n";
}