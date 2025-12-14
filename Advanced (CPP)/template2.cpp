#include <iostream>
#include <fstream>
#include <vector>

template<class T> int signum(T value) {
	if (value < 0)
		return -1;
	if (value > 0)
		return 1;
	return 0;
}

class Point {
private:
	int x, y;
public:
	Point() :x(0), y(0) { }
	Point(int x, int y) :x(x), y(y) {}
	int getX() const { return x; }
	int getY() const { return y; }
};

int signum(Point value) {
	if (signum(value.getX())< 0 && signum(value.getY())< 0)
			return -1;
	if (signum(value.getX())> 0 && signum(value.getY())> 0)
		return 1;
	return 0;
}

int main() {
	
	int valuei = -5;
	std::vector <Point> points = { { -1, 2 },{ -3, -5 },{ 2, 2 } };

	std::cout << "Value: " << valuei << " sgn: " << signum(valuei) << std::endl;
	for (auto point: points)
		std::cout << "Point: " << point.getX() << ", " << point.getY() << " sgn:" << signum(point) << std::endl;

	return 0;
}
