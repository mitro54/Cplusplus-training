#include <iostream>
#include <string>

class StringValidator {
public:
    virtual ~StringValidator() {};
    virtual bool isValid(std::string input) = 0;
};

class ExactValidator : public StringValidator {
public:
    ExactValidator(std::string password): pass(password) {}
    virtual bool isValid(std::string input);
private:
    std::string pass;
};

bool ExactValidator::isValid(std::string input) {
    return (input == pass);
}

class DummyValidator : public StringValidator {
public:
    virtual bool isValid(std::string input);
};

bool DummyValidator::isValid(std::string input) {
    return true;
}

void printValid(StringValidator &validator, std::string input) {
    std::cout << "The string '" << input << "' is "
              << (validator.isValid(input) ? "valid" : "invalid") << "\n";
}

int main() {
    DummyValidator dummy;
    printValid(dummy, "hello");
    std::cout << std::endl;

    ExactValidator exact("secret");
    printValid(exact, "hello");
    printValid(exact, "secret");
    return 0;
}