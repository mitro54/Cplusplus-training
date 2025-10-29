#include <iostream>
#include <string>

class Square {
  public:
    Square(double side);
    double get_side() { return side; }
    double get_area() { return area; }
    void set_side(double new_side);
  private:
    double side;
    double area;
};

Square::Square(double side) {
  this->side = side;
  this->area = side * side;
}

void Square::set_side(double new_side) {
  if (new_side < 0) return;
  side = new_side;
  area = side * side;
}

void print(Square* square) {
  std::cout << "Square: side=" << square->get_side() << " area=" << square->get_area() << std::endl;
}

int main() {
  double side;
  std::cout << "Give side length: ";
  std::cin >> side;
  Square r(side);
  print(&r);
  std::cout << "Give a new side length: ";
  std::cin >> side;
  r.set_side(side);
  print(&r);
  return 0;
}