#include <iostream>

int main(void) {

	int matrix[10][10] = { };

    int *p = (int *)matrix;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            
            int *q = p + (y * 10 + x);
            *q = (y + 1) * (x + 1);
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