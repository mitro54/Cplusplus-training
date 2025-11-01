#include <iostream>
#include <string>

class Fraction {
public:
  Fraction(int numerator, int denominator);
  std::string toString();
  double toDouble();
private:
  int numerator;
  int denominator;
};

// Fraction methods and constructor definition comes here

int main(void) {
  int num, deno;
  std::string input;
  std::cout << "Input a fraction in format numerator / denominator, e.g. 3 / 7\n";
  std::getline(std::cin, input);

  // parse input, set num, deno

  Fraction fraction(num, deno);
  std::cout << fraction.toString() << " is " << fraction.toDouble() << "in decimal\n";
  return 0;
}