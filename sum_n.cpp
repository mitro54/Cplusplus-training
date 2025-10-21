#include <iostream>

int main(void) {
    // task requires precise results for N up to 100000
    long long int len, sum = 0;
    std::cout << "Enter value: ";
    std::cin >> len;
    if (len < 0) return 1;
    
    for (int i = 1; i <= len; i++) 
        sum += i;
    std::cout << sum;
    return 0;
}