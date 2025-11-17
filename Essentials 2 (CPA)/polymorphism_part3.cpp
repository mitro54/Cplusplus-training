#include <iostream>
#include <string>

class IPAddress {
public:
    IPAddress(int ip) { this->ip = ip; }
    IPAddress(const IPAddress &source) { ip = source.ip; }
    virtual void print() { std::cout << ip; }
protected:
    int ip;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(int ip) : IPAddress(ip) { if (checkIP(ip)) isCorrect = true; };
    IPAddressChecked(const IPAddressChecked &source) : IPAddress(ip) { ip = source.ip; } // wrong atm
    bool isCorrect = false;
    void print() {
        std::cout << ip << " - ";
        if (isCorrect) std::cout << "Correct";
        else std::cout << "Not Correct";
    }
};

bool checkIP(int ip) {

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