#include <iostream>

class Point2D {
public:
  Point2D(double x, double y);
  std::string toString();
private:
  double x;
  double y;
};

class Line2D {
public:
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  std::string toString();
private:
  double slope;
  double y_intercept;
};
