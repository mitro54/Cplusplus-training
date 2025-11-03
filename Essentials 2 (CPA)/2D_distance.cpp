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

double Point2D::distanceTo(Point2D that) {
  return std::hypot(x - that.x, y - that.y);
}


int main(void) {
    std::string input1, input2;
    double x1, x2, y1, y2;
    std::cout << "Give 2 points in x,y coordinates twice to calculate the distance between the points\n";
    std::getline(std::cin, input1);
    std::getline(std::cin, input2);

    if (input1.find(',') != std::string::npos) {
        x1 = std::stod(input1.substr(0, input1.find(',')));
        x2 = std::stod(input2.substr(0, input2.find(',')));
        y1 = std::stod(input1.substr(input1.find(',') + 1));
        y2 = std::stod(input2.substr(input2.find(',') + 1));
        Point2D p1(x1, y1);
        Point2D p2(x2, y2);
        std::cout << p1.distanceTo(p2);
    }

    return 0;
}