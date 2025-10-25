#include <string>
#include <iostream>

int main() {
    int start = 0, end;
    std::string sentence, from, to, word;

    std::cout << "Set a sentence: ";
    std::getline(std::cin, sentence);

    std::cout << "Give a word from the sentence you want to swap: ";
    std::getline(std::cin, from);

    std::cout << "Give a word to swap the first one to: ";
    std::getline(std::cin, to);

    // change all occurrences of 'from' into 'to' in the sentence
    while ((end = sentence.find(from, start)) != std::string::npos) {
        if (from == "") break;
        sentence.erase(end, from.length());
        sentence.insert(end, to);
        start = end + to.length();
    }

    std::cout << sentence << "\n";
}