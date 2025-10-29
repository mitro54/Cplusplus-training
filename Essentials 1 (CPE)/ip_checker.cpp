#include <iostream>
#include <string>

std::string ip_checker(std::string ip) {
    int count = 0;
    std::string tester = "0123456789.", num;

    for (int i = 0; i < ip.length(); i++) {
        if (tester.find(ip[i]) == std::string::npos)
            return "Only digits and dots allowed";

        num.push_back(ip[i]);

        if (num.length() > 4)
            return "Too many characters in a part";
        else if (std::stoi(num) > 255)
            return "Too big a value of a part";
        
        if (ip[i] == '.') {
            count++;
            num = "";
        }
    }

    if (count != 3) {
        std::cout << count;
        return "Incorrect parts count";
    }

    return "Correct IP";
}

int main(void) {
    std::string ip;
    std::cout << "Insert IP: ";
    std::cin >> ip;
    std::cout << ip_checker(ip);
    return 0;
}