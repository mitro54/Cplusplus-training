#include <iostream>
// reverses the vector1's contents to vector2
int main(void) {

	int vector1[7] = {4, 7, 2, 8, 1, 3, 0};
	int vector2[7];

	for (int i = 0; i < 7; i++) {
        vector2[i] = vector1[6 - i];
    }

	for(int i = 0; i < 7; i++)
		std::cout << vector2[i] << ' ';
	std::cout << std::endl;
	return 0;
}