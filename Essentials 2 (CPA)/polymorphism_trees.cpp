#include <iostream>
#include <string>

class BaseClass {
public:
  virtual void draw() { std::cout << "Nothing to draw"; }
};

class Tree1 : public BaseClass {
public:
  void draw() { std::cout << "\nDrawing 1:\n" << " /\\\n" << "//\\\\"; };
};

class Tree2 : public BaseClass {
public:
  void draw() { std::cout << "\nDrawing 2:\n" << " /\\\n" << "/**\\"; };
};

class Tree3 : public BaseClass {
public:
  void draw() { std::cout << "\nDrawing 3:\n" << " /\\\n" << "/++\\"; };
};

int main(void) {
  BaseClass* arr[3];
  arr[0] = new Tree1;
  arr[1] = new Tree2;
  arr[2] = new Tree3;

  for (int i = 0; i < 3; i++) {
    arr[i]->draw();
  }

  return 0;
}