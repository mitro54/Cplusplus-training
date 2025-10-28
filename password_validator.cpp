#include <string>
#include <iostream>

int main() {
    // must be atleast 8 chars long, 1 upper and lowercase letter, 1 digit, 1 special char
    std::string password;
    std::cout << "Password validator!\n";
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);

    int d = 0, a = 0, p = 0, l = 0;
    for (int i = 0; i < password.length(); i++) {
        if (isdigit(password[i])) d++;
        if (isalpha(password[i])) a++;
        if (ispunct(password[i])) p++;
        if (password.length() > 8) l++;
        // isdigit(char), isalpha(char) ispunct(char)
    }
    if (l == 0) std::cout << "The password must be 8 characters long\n";
    if (d == 0) std::cout << "The password must have at least one digit\n";
    if (a == 0) std::cout << "The password must have at least one upper case letter\n"; // doesnt work yet
    if (p == 0) std::cout << "The password must have at least one special character\n";

    return 0;
}