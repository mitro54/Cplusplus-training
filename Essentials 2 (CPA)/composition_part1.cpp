#include <iostream>
#include <string>
#include <vector>

class IPAddress {
public:
    IPAddress(std::string ip) { this->ip = ip; }
    std::string ip;
    void print() { std::cout << std::endl << ip; }
};

class Network {
private:
    std::vector<IPAddress> arr;
public:
    void addIp(IPAddress ip) { arr.push_back(ip); }
    void print() { for (IPAddress& ip : arr) ip.print(); }
};

int main(void) {
    Network net1, net2;
    IPAddress ip1("123.123.123.123"),
              ip2("123.123.123.124"),
              ip3("123.123.123.125"),
              ip4("123.123.123.126"),
              ip5("123.123.123.127");
    
    net1.addIp(ip1);
    net1.addIp(ip2);
    net1.addIp(ip3);

    net2.addIp(ip3);
    net2.addIp(ip4);
    net2.addIp(ip5);

    std::cout << "Network 1:\n";
    net1.print();

    std::cout << "\nNetwork 2:\n";
    net2.print();
    return 0;
}