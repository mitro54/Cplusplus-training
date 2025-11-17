#include <iostream>
#include <string>

class IPAddress {
public:
    IPAddress(std::string ip) { this->ip = ip; }
    IPAddress(const IPAddress &source) { ip = source.ip; }
    virtual void print() { std::cout << ip << '\n'; }
protected:
    std::string ip;
};

class IPAddressChecked : public IPAddress {
public:
    IPAddressChecked(std::string ip) : IPAddress(ip) { if (checkIP(ip)) isCorrect = true; };
    IPAddressChecked(const IPAddressChecked &source) : IPAddress(ip) { ip = source.ip; }
    bool isCorrect = false;
    void print() {
        std::cout << ip << " - ";
        if (isCorrect) std::cout << "Correct\n";
        else std::cout << "Not Correct\n";
    }
    bool checkIP(std::string ip);
};

bool IPAddressChecked::checkIP(std::string ip) {
    int count = 0;
    std::string tester = "0123456789.", num;

    for (int i = 0; i < ip.length(); i++) {
        if (tester.find(ip[i]) == std::string::npos)
            return false;

        num.push_back(ip[i]);

        if (num.length() > 4)
            return false;
        else if (std::stoi(num) > 255)
            return false;
        
        if (ip[i] == '.') {
            count++;
            num = "";
        }
    }

    if (count != 3) return false;

    return true;
}

int main(void) {
    std::string ip1, ip2, ip3;
    std::cout << "enter 3 ip addresses\n";
    std::cin >> ip1;
    std::cin >> ip2;
    std::cin >> ip3;

    IPAddress ip_1(ip1);
    IPAddressChecked ip_2(ip2);
    IPAddressChecked ip_3(ip3);
    std::cout << std::endl << "results:\n";
    ip_1.print();
    ip_2.print();
    ip_3.print();

    return 0;
}