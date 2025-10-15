#include <iostream>

int main(void) {
	int matrix[10][10] = { };
	int (*p)[10] = matrix;

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
			std::cout.width(4);
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}