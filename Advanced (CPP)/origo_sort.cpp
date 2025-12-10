#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Point {
private:
	int x, y;
public:
	Point(int x, int y):x(x), y(y){}
	double get_distance_from(int other_x, int other_y) const {
		int diff_x = x - other_x;
		int diff_y = y - other_y;
		double distance = sqrt(diff_x * diff_x + diff_y * diff_y);
		return distance;
	}
	friend void print(const Point &value);

};

void print(const Point & value) {
	std::cout << value.x << " " << value.y << '\n';
}

bool ascending_compare(const Point &lhs, const Point &rhs) {
	return lhs.get_distance_from(0, 0) < rhs.get_distance_from(0,0);
}

int main() {
	std::vector <Point> points = { {1, 2}, {3, 5}, {2, 2} };
	for_each(points.begin(), points.end(), print); std::cout << '\n';

	stable_sort(points.begin(), points.end(), ascending_compare);
	for_each(points.begin(), points.end(), print); std::cout << '\n';

	return 0;
}