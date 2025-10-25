#include <string>
#include <iostream>

int main() {
    int start = 0, start_inner = 0, end, end_inner;
    std::string stop_words, sentence, word;

    std::cout << "Give stop words separated by commas (w1,w2,w3...): ";
    std::getline(std::cin, stop_words);

    std::cout << "Give a sentence to clear stop words from: ";
    std::getline(std::cin, sentence);

    while ((end = stop_words.find(',', start)) != std::string::npos) {
        word = stop_words.substr(start, end - start);
        start = end + 1;
        while ((end_inner = sentence.find(' ' + word + ' ', start_inner)) != std::string::npos) {
            sentence.erase(end_inner, word.length() + 1);
            start_inner = end_inner + word.length();
        }
        start_inner = 0;
    }

    // runs the loop once more for the last word in stop_words
    word = stop_words.substr(start);
    while ((end_inner = sentence.find(word, 0)) != std::string::npos) {
        sentence.erase(end_inner, word.length() + 1);
        start_inner = end_inner + word.length();
    }


    std::cout << sentence << "\n";
}