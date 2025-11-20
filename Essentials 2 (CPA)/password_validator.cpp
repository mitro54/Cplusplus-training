#include <iostream>
#include <string>

class StringValidator {
public:
    virtual ~StringValidator() {};
    virtual bool isValid(std::string input) = 0;
};

class MinLengthValidator : public StringValidator {
public:
    MinLengthValidator(int input): len(input) {}
    virtual bool isValid(std::string input);
private:
    int len;
};

bool MinLengthValidator::isValid(std::string input) {
    return (input.size() >= len);
}

class MaxLengthValidator : public StringValidator {
public:
    MaxLengthValidator(int input): len(input) {}
    virtual bool isValid(std::string input);
private:
    int len;
};

bool MaxLengthValidator::isValid(std::string input) {
    return (input.size() <= len);
}

class PatternValidator : public StringValidator {
public:
    PatternValidator(std::string input): pattern(input) {}
    virtual bool isValid(std::string input);
private:
    std::string pattern;
};

bool PatternValidator::isValid(std::string sample) {
    std::string newstr, nums = "0123456789", chars = "abcdefghijklmnopqrstuvwxyz";
    std::string punct = " .,=~><|!@#$%^&*()-_+{}[]:\\/\"'";

    for (int i = 0; i < sample.length(); i++) {
        for (int j = 0; j < pattern.length(); j++) {
            if (pattern[j] == '?') {
                newstr.push_back(sample[i]);
                continue;

            } else if (pattern[j] == 'D') {
                if (nums.find(sample[i]) != std::string::npos) {
                    newstr.push_back(sample[i]);
                    break;
                } else newstr.erase();

            } else if (pattern[j] == 'A') {
                if (chars.find(tolower(sample[i])) != std::string::npos) {
                    newstr.push_back(sample[i]);
                    break;
                } else newstr.erase();

            } else if (punct.find(sample[i]) != std::string::npos) {
                newstr.push_back(sample[i]);
                break;
            } else newstr.erase();
        }
        if (newstr.length() == pattern.length()) {
            std::cout << newstr << " " << pattern;
            return true;
        }
    }
    return false;
}

void printValid(StringValidator &validator, std::string input) {
    std::cout << "The string '" << input << "' is "
              << (validator.isValid(input) ? "valid" : "invalid") << "\n";
}

int main() {
  std::cout << "MinLengthValidator" << std::endl;
  MinLengthValidator min(6);
  printValid(min, "hello");
  printValid(min, "welcome");
  std::cout << std::endl;

  std::cout << "MaxLengthValidator" << std::endl;
  MaxLengthValidator max(6);
  printValid(max, "hello");
  printValid(max, "welcome");
  std::cout << std::endl;

  std::cout << "PatternValidator" << std::endl;
  PatternValidator digit("D");
  printValid(digit, "there are 2 types of sentences in the world");
  printValid(digit, "valid and invalid ones");
  std::cout << std::endl;

  return 0;
}