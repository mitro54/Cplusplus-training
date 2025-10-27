#include <string>
#include <iostream>

int main() {
    // must be atleast 8 chars long, 1 upper and lowercase letter, 1 digit, 1 special char
    std::string password;
    std::cout << "Password validator!\n";
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);

    for (int i = 0; i < password.length(); i++) {
        if (isdigit(password[i])) std::cout << "yes";
        // isdigit(char), isalpha(char) is_punct(char)
    }

    return 0;
}