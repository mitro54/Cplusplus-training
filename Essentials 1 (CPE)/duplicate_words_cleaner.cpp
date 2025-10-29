#include <string>
#include <iostream>

int main() {
    int start = 0, end, word_finder;
    std::string sentence, word;
    std::cout << "Input sentence: ";
    std::getline(std::cin, sentence);

    while ((end = sentence.find(' ', start)) != std::string::npos) {
            word = sentence.substr(start, end - start);
            word_finder = sentence.find(word, end);
            if (sentence.find(word, end) != std::string::npos)
                sentence.erase(word_finder, word_finder - start);
            start = end + 1;
        }
    std::cout << sentence;
}