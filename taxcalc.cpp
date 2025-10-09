#include <iostream>

int main(void) {
    float tax, gross, net, taxval;
    std::cout << "Enter a gross price: ";
    std::cin >> gross;
    std::cout << "Enter a tax rate: ";
    std::cin >> tax;

    net = gross / (1 + (tax / 100));
    taxval = gross - net;
    std::cout << "Net price: " << net << std::endl;
    std::cout << "Tax value: " << taxval << std::endl;

    return 0;
}