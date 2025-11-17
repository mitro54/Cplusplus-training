#include <iostream>
#include <string>

class IPAddress {
public:
    IPAddress(int ip) { this->ip = ip; }
    virtual void print() { std::cout << ip; }
    int ip;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(IPAddress ip) { checkIP(ip) ? isCorrect = true : isCorrect = false; }
    bool isCorrect = false;
};

bool checkIP(IPAddress ip) {

}

int main(void) {
    int ip1, ip2, ip3;
    std::cout << "enter an ip address to check if its correct: ";
    std::cin >> ip1;
    std::cin >> ip2;
    std::cin >> ip3;

    IPAddress ip_1(ip1);
    IPAddressChecked ip_2(ip2);
    IPAddressChecked ip_3(ip3);
    return 0;
}