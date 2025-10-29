#include <iostream>

class Square {
  public:
    Square(double side);
    double get_side() { return side; }
    double get_area();
    void set_side(double side);
  private:
    double side;
    double area;
    bool side_changed;
};

Square::Square(double side) {
  this->side = side;
  this->area = side * side;
  this->side_changed = false;
}

void Square::set_side(double side) {
  if (side < 0) return;
  this->side = side;
  side_changed = true;
}

double Square::get_area(void) {
  if (side_changed) {
    area = side * side;
    side_changed = false;
  }
  return area;
}

void print(Square* square) {
  std::cout << "Square: side=" << square->get_side() << " area=" << square->get_area()<< std::endl;
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