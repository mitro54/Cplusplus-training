#include <string>
#include <iostream>

int main() {
    std::string sentence;
    // std::cout << "Text formatter. * for uppercase, _for spacing.\n";
    // std::cout << "Examples: *word* will be WORD, _word_ will be w o r d\n";
    // std::cout << "Enter a text: ";
    // std::getline(std::cin, sentence);
    sentence = "Testing testing, *big day_* coming soon";

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == '*') {
            if (sentence.find('*', i + 1) == std::string::npos) {
                sentence.erase(sentence.find('*'), 1);
            }
            else for (int j = i + 1; j < sentence.length(); j++) {
                if (sentence[j] == '_') {
                    if (sentence.find('_', j + 1) != std::string::npos) {
                        sentence.erase(sentence.find('*'), 1);
                        sentence.erase(sentence.find('*'), 1);
                        break;
                    } else {
                        sentence.erase(j, 1);
                        j = i;
                    }

                } else if (sentence[j] == '*') {
                    std::string newstr = sentence.substr(i + 1, j - (i + 1));
                    for (char &c : newstr) c = toupper(c);
                    sentence.erase(i, j + 1 - i);
                    sentence.insert(i, newstr);
                    break;
                }
            }
        }
    }

    std::cout << sentence << "\n";
}