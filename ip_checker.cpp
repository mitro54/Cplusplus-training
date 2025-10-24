#include <iostream>
#include <string>

std::string ip_checker(std::string ip) {
    int count = 0;
    for (int i = 0; i < ip.length(); i++) {
       if (ip.find('.') != std::string::npos) count++;
    }
    if (count < 4) {
        return;
    }
    return;
}

int main(void) {
    std::string ip;
    std::cout << "insert IP: ";
    std::cin >> ip;
    ip_checker(ip);
    return 0;
}