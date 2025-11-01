#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Fraction {
public:
  Fraction(int numerator, int denominator);
  std::string toString();
  double toDouble();
private:
  int numerator;
  int denominator;
};

Fraction::Fraction(int num, int deno) {
  this->numerator = num;
  this->denominator = deno;
}

std::string Fraction::toString() {
  if (numerator >= denominator) {}
  else {
    return std::to_string(numerator) + '/' + std::to_string(denominator);
  }
}

double Fraction::toDouble() {
  return double(numerator) / denominator;
}

int main(void) {
  int num, deno;
  std::string input;
  std::cout << "Input a fraction in format numerator / denominator, e.g. 3 / 7\n";
  std::getline(std::cin, input);
  num = std::stoi(input.substr(0, input.find('/')));
  deno = std::stoi(input.substr(input.find('/') + 1));

  Fraction fraction(num, deno);
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  std::cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal\n";
  return 0;
}