#include <iostream>
#include <string>

class Fraction {
public:
  Fraction(int numerator, int denominator);
  std::string toString();
  double toDouble();
  // the functions below do not change the object
  // on which they are called, they produce a new object
  Fraction plus(Fraction that);
  Fraction minus(Fraction that);
  Fraction times(Fraction that);
  Fraction by(Fraction that);
private:
  int numerator;
  int denominator;
  void reduce();
};

Fraction Fraction::times(Fraction that) {
  int num = this->numerator * that.denominator;
  int den = this->denominator * that.denominator;
  Fraction result(num, den);
  // could call result.reduce()
  // or use it just before it is necessary
  return result;

// other Frac methods here
}

int main(void) {
  std::string input1, input2;
  std::cout << "Input 2 fraction numbers to perform arithmetics to, format: '3 / 7'\n";
  std::getline(std::cin, input1);
  std::getline(std::cin, input2);
  return 0;
}