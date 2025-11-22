#include <iostream>
#include <exception>
#include <stdexcept>

class AreaException:public std::runtime_error {
public:
	AreaException(const char * message): std::runtime_error(message){}
};

float square_area(float x) {
	if (!(x > 0))
		throw AreaException ("Your input is not valid, area cannot be negative.");
	float result = x * x;
	return result;
}

float rectangle_area(float a, float b) {
	if (!(a > 0))
		throw AreaException ("Your input is not valid, area cannot be negative.");
	float result = a * b;
	return result;
}

int main(void) {
	float a, b, r;
	std::cin >> a;
	std::cin >> b;
	try {
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		std::cout << rsquare << std::endl << rrectangle << std::endl;
	}
	catch (AreaException ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}