#include <iostream>
#include <string>
#include <cmath>

class Point2D {
public:
  Point2D(double x, double y);
  double distanceTo(Point2D that);
  double toDouble();
  std::string toString();
private:
  double x;
  double y;
};

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}


int main(void) {
    std::string input1, input2;
    std::cout << "Give 2 points in x,y coordinates twice to calculate the distance between the points\n";
    std::getline(std::cin, input1);
    std::getline(std::cin, input2);
    return 0;
}