#include <iostream>
#include <string>

std::string ip_checker(std::string ip) {
    int count = 0;
    std::string tester = "0123456789.";
    for (int i = 0; i < ip.length(); i++) {
        if (tester.find(ip[i]) == std::string::npos)
            return "Only digits and dots allowed";

        if (ip[i] == '.') count++;
    }

    if (count != 3) {
        std::cout << count;
        return "Incorrect parts count";
    }

    return "ok";
}

int main(void) {
    std::string ip;
    std::cout << "insert IP: ";
    std::cin >> ip;
    std::cout << ip_checker(ip);
    return 0;
}