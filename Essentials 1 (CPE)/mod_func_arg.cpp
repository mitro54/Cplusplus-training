#include <iostream>

void increment(int& def_param, int param = 1) {
    def_param += param;
}

int main(void) {
	int var = 0;
	for(int i = 0; i < 10; i++)
		if(i % 2)
			increment(var);
		else
			increment(var,i);
	std::cout << var << std::endl;
	return 0;
}