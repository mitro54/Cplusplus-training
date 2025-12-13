#include <iostream>

#include <vector>

#include <algorithm>

#include <iterator>

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
    double get_distance_from(int other_x, int other_y) const {
    int diff_x = x - other_x;
    int diff_y = y - other_y;
    double distance = sqrt(diff_x * diff_x + diff_y * diff y);
    return distance;
    }
    friend void print(const Point &value);
};

void print(const Point &value) {
    std::cout << value.x << ' ' << value.y << '\n';
}

bool asc_compare(const Point& lhs, const point& rhs) {
    return lhs.get_distance_from(0,0) < rhs.get_distance_from(0,0);
}

int main() {
    std::vector <Point> pointsA = { { 1, 2 },{ 3, 5 },{ 2, 2 } };
    std::vector <Point> pointsB = { { 3, 2 },{ 2, 1 },{ 4, 1 } };
    std::vector <Point> pointsClosest;
    
    std::stable_sort(pointsA.begin(), pointsA.end(), asc_compare);
    std::stable_sort(pointsB.begin(), pointsB.end(), asc_compare);
    pointsClosest.resize(4);
    std::merge(pointsA.begin(), pointsB.begin() + 2, pointsB.begin(), pointsB.begin() + 2, pointsClosest.begin(), asc_compare);
    std::for_each(pointsClosest.begin(), pointsClosest.end(), print);
    return 0;
}

