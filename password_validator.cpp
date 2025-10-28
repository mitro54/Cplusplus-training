#include <string>
#include <iostream>

int main() {
    // must be atleast 8 chars long, 1 upper and lowercase letter, 1 digit, 1 special char
    std::string password;
    std::cout << "Password validator!\n";
    std::cout << "Enter a password: ";
    std::getline(std::cin, password);

    int d = 0, lc_a = 0, uc_a = 0, p = 0, l = 0;
    std::string ltr_case = "lower";
    for (int i = 0; i < password.length(); i++) {
        if (password.length() > 8) l++;
        if (isdigit(password[i])) d++;
        if (ispunct(password[i])) p++;
        if (isalpha(password[i])) {
            if (toupper(password[i]) == password[i]) uc_a++;
            if (tolower(password[i]) == password[i]) lc_a++;
        }
    }
    if (uc_a == 0) ltr_case = "upper";
    if (l == 0) std::cout << "The password must be 8 characters long\n";
    if (d == 0) std::cout << "The password must have at least one digit\n";
    if (lc_a == 0 || uc_a == 0) std::cout << "The password must have at least one " << ltr_case << " case letter\n"; // doesnt work yet
    if (p == 0) std::cout << "The password must have at least one special character\n";
    if (
        l != 0
        && d != 0
        && p != 0
        && lc_a != 0
        && uc_a != 0
        ) std::cout << "The password is valid";
    return 0;
}