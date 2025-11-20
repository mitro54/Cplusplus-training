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
    virtual bool isValid(std::string input) {}
private:
    int len;
};

bool MinLengthValidator::isValid(std::string input) {
    return (input.size() >= len);
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