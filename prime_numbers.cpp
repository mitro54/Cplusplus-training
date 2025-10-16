#include <iostream>

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int main(void) {
	for(int i = 0; i <= 151; i++)
		if(is_prime(i))
			std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}