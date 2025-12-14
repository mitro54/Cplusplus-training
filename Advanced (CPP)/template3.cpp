#include <iostream>

template<typename T> class Point {
public:
    T x;
    T y;
    Point(T x_val, T y_val) : x(x_val), y(y_val) {}
    void add_point(const Point<T>& other) {
        x += other.x;
        y += other.y;
    }
};

int main() {
    Point<int> p1(1, 1);
    Point<double> p2(2.1, 2.3);
    std::cout << "P1: " << p1.x << ":" << p1.y << std::endl;
    std::cout << "P2: " << p2.x << ":" << p2.y << std::endl;
    Point<int> p3(1, 1);
    p1.add_point(p3);
    std::cout << "P1: " << p1.x << ":" << p1.y << std::endl;
    return 0;
}
