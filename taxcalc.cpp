#include <iostream>

int main(void) {
    float tax, gross, net, taxval;
    std::cout << "Enter a gross price: ";
    std::cin >> gross;
    std::cout << "Enter a tax rate: ";
    std::cin >> tax;

    if (gross > 0 && tax <= 100 && tax >= 0) {
        net = gross / (1 + (tax / 100));
        taxval = gross - net;   
        std::cout << "Net price: " << net << std::endl;
        std::cout << "Tax value: " << taxval << std::endl;   
    } else {
        std::cout << "Price must be over 0 and tax rate between 0-100";
    }

    return 0;
}