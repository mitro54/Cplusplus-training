#include <iostream>
// finds the minimal number of banknotes needed to deliver
// any amount of money to the client

int main(void) {
    int amount;
    int banknotes[5] = {50, 20, 10, 5, 1};
    std::cout << "Enter any amount you would like to withdraw: ";
    std::cin >> amount;
    
	for(int i = 0; i < 5; i++)
		while(amount >= banknotes[i]) {
			std::cout << banknotes[i] << ' ';
			amount -= banknotes[i];
		}
	std::cout << std::endl;
	return 0;
}