#include <iostream>

class Square {
  public:
    Square(double side);
    double get_side() { return side; }
    void set_side(double side);
  private:
    double side;
};

Square::Square(double side) {
  this->side = side;
}

void Square::set_side(double side) {
  if (side < 0) return;
  this->side = side;
}

void print(Square* square) {
  std::cout << "Square: side=" << square->get_side() << " area=" << square->get_side() * square->get_side() << std::endl;
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