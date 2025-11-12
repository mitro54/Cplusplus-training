#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Point2D {
public:
  Point2D(double x, double y);
  // getters
  double get_x() const { return x; };
  double get_y() const { return y; };

private:
  double x;
  double y;
};

class Line2D {
public:
  // getters
  double get_y() { return y_intercept; }
  double get_slope() { return slope; }
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  void toString();
  void contains(Line2D other);
private:
  double slope;
  double y_intercept;
};

Point2D::Point2D(double x, double y) {
  this->x = x;
  this->y = y;
}

Line2D::Line2D(double slope, double y_intercept) {
  this->slope = slope;
  this->y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB) {
  double a = (pointB.get_y() - pointA.get_y()) / (pointB.get_x() - pointA.get_x());
  double b = (pointB.get_y() - (a * pointB.get_x()));
  this->slope = a;
  this->y_intercept = b;
}

void Line2D::toString() {
  std::string sign = (y_intercept >= 0) ? "+ " : "- ";
  std::cout << "y = " << slope << "x " << sign;
  std::cout << fabs(y_intercept);
}

void Line2D::contains(Line2D other) {
  if (this->get_y() == other.get_y() && this->get_slope() == other.get_slope())
    std::cout << "collinear";
  else std::cout << "not collinear";
}

int main(void) {
  std::string input1, input2, point;
  double x1, x2, x3, y1, y2, y3;
  std::cout << "Input two sets of x,y coordinates separated by a comma.\n";
  std::getline(std::cin, input1);
  std::getline(std::cin, input2);
  std::getline(std::cin, point);

  if (input1.find(',') != std::string::npos) {
      x1 = std::stod(input1.substr(0, input1.find(',')));
      x2 = std::stod(input2.substr(0, input2.find(',')));
      x3 = std::stod(point.substr(0, point.find(',')));
      y1 = std::stod(input1.substr(input1.find(',') + 1));
      y2 = std::stod(input2.substr(input2.find(',') + 1));
      y3 = std::stod(point.substr(point.find(',') + 1));
      Point2D p1(x1, y1);
      Point2D p2(x2, y2);
      Point2D p3(x3, y3);
      Line2D line1(p1, p2);
      Line2D line2(p1, p3);
      line1.contains(line2);
  }

  return 0;
}