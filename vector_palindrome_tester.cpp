#include <iostream>

int main(void) {
    // Modify vectors values here to test it out
    int vector[] = {1, 7, 3, 2, 2, 3, 7, 1};
	bool is_palindrome = true;
	int n = sizeof(vector) / sizeof(vector[0]);

    for (int i = 0; i < n; i++) {
        if (vector[i] == vector[n - i - 1]) continue;
        else {
            is_palindrome = false; 
            break;
        }
    }

	if(is_palindrome)
		std::cout << "It's a palindrome";
	else
		std::cout << "It isn't a palindrome";

    return 0;
}