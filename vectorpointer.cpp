#include <iostream>

int main(void) {

	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);

    int *p = vector;
    int max = *p;

    for (int i = 0; i < n; i++) {
        if (*p > max) max = *p;
        p++;
    }
    std::cout << max;

	return 0;
}