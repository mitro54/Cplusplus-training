#include <iostream>
#include <cmath>

void increment(int& def_n, int n = 1) {
    def_n += n;
}

void increment(float& def_n, double n = 1.0) {
    def_n += n;
}

int main(void) {

	int int_var = 0;
	float float_var = 1.5;

	for(int i = 0; i < 10; i++)
		if(i % 2) {
			increment(int_var);
			increment(float_var, sqrt(int_var));
		}
		else {
			increment(int_var,i);
			increment(float_var);
		}
	std::cout << int_var * float_var << std::endl;
	return 0;
}