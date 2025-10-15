#include <iostream>

int main(void) {

	int matrix[10][10] = { };

    int *p = (int *)matrix;

    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            
            int *q = p + (x * 10 + y);
            *q = (x + 1) * (y + 1);
        }
    }

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			std::cout.width(4);
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}