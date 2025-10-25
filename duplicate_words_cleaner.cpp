#include <string>
#include <iostream>

int main() {
    int start, end;
    std::string sentence, curr_word, prev_word;
    std::cout << "Input sentence: ";
    std::getline(std::cin, sentence);

    for (int i = 0; i < sentence.length(); i++) {
        start = sentence.find(' ');
        for (int j = start; j < sentence.length(); j++) {
            if (sentence[j] == ' ') {
                end = j;
                prev_word = sentence[start, end];
                std::cout << prev_word;
                i = j;
                break;
            }
        }
    }

    // std::cout << sentence;
}