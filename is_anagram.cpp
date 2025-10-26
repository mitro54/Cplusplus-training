#include <iostream>
#include <string>

int main(void) {
    bool is_anagram = true; 
    std::string words, word1, word2;
    std::cout << "Provide 2 words separated by a space: ";
    std::getline(std::cin, words);
    for (int i = 0; i < words.length(); i++) {
        if (words[i] == ' ') {
            word1 = words.substr(0, i);
            word2 = words.substr(i + 1, words.length() - i);
        }
    }
    for (int i = 0; i < word1.length(); i++) {
        if (word2.find(word1[i]) == std::string::npos) is_anagram = false;
    }
    for (int i = 0; i < word2.length(); i++) {
        if (word1.find(word2[i]) == std::string::npos) is_anagram = false;
    }
    if (is_anagram)
        std::cout << "anagrams";
    else
        std::cout << "not anagrams";
    return 0;
}