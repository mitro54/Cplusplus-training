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

bool PatternValidator::isValid(std::string pattern) {
    int d = 0, lc_a = 0, uc_a = 0, p = 0, l = 0;
    for (int i = 0; i < pattern.length(); i++) {
        if (pattern.length() > 8) l++;
        if (isdigit(pattern[i])) d++;
        if (ispunct(pattern[i])) p++;
        if (isalpha(pattern[i])) {
            if (toupper(pattern[i]) == pattern[i]) uc_a++;
            if (tolower(pattern[i]) == pattern[i]) lc_a++;
        }
    }
    if (
        l != 0
        && d != 0
        && p != 0
        && lc_a != 0
        && uc_a != 0
        ) return true;
    else return false;
    }

class PasswordValidator : public StringValidator {
public:
    PasswordValidator(std::string pattern);
    bool isValid(std::string input);
private:
    MinLengthValidator min_validator;
    MaxLengthValidator max_validator;
    PatternValidator pattern_validator;
};

PasswordValidator::PasswordValidator(std::string pattern):
    min_validator(8), max_validator(32), pattern_validator(pattern) {}

bool PasswordValidator::isValid(std::string input) {
  return (min_validator.isValid(input) && max_validator.isValid(input) && pattern_validator.isValid(input));
}

void printValid(StringValidator &validator, std::string input) {
    std::cout << "The string '" << input << "' is "
              << (validator.isValid(input) ? "valid" : "invalid") << "\n";
}

int main() {
    std::string input = "Test@test111";
    PasswordValidator tester(input);
    printValid(tester, input);
    return 0;
}