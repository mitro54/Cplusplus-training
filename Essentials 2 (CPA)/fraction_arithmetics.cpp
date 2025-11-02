#include <iostream>
#include <string>
#include <cmath>
#include <numeric>

class Fraction {
public:
  Fraction(int numerator, int denominator);
  std::string toString();
  void display();
  void displayMixed();
  Fraction plus(Fraction that);
  Fraction minus(Fraction that);
  Fraction times(Fraction that);
  Fraction by(Fraction that);
private:
  int numerator;
  int denominator;
  void reduce();
};

Fraction::Fraction(int numerator, int denominator) {
  this->numerator = numerator;
  this->denominator = denominator;
  reduce();
}

void Fraction::reduce() {
  int g = std::gcd(std::abs(numerator), std::abs(denominator));
  if (g == 0) {
    denominator = 1;
    return;
  }
  numerator /= g;
  denominator /= g;
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
}

std::string Fraction::toString() {
  if (denominator == 1) return std::to_string(numerator);
  return std::to_string(numerator) + "/" + std::to_string(denominator);
}

void Fraction::display() {
  std::cout << toString();
}

void Fraction::displayMixed() {
  int n = numerator, d = denominator;
  int whole = n / d;
  int rem = std::abs(n) % d;

  if (rem == 0) {
    std::cout << whole;
    return;
  }
  if (std::abs(n) < d) {
    display();
    return;
  }
  std::cout << whole << " " << rem << "/" << d;
}

Fraction Fraction::plus(Fraction that) {
  int num = this->numerator * that.denominator + that.numerator * this->denominator;
  int den = this->denominator * that.denominator;
  return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that) {
  int num = this->numerator * that.denominator - that.numerator * this->denominator;
  int den = this->denominator * that.denominator;
  return Fraction(num, den);
}

Fraction Fraction::times(Fraction that) {
  int num = this->numerator * that.numerator;
  int den = this->denominator * that.denominator;
  return Fraction(num, den);
}

Fraction Fraction::by(Fraction that) {
  int num = this->numerator * that.denominator;
  int den = this->denominator * that.numerator;
  return Fraction(num, den);
}

int main(void) {
  int num1, den1, num2, den2;
  std::string input1, input2;

  std::getline(std::cin, input1);
  std::getline(std::cin, input2);

  auto s1 = input1;
  auto s2 = input2;
  num1 = std::stoi(s1.substr(0, s1.find('/')));
  den1 = std::stoi(s1.substr(s1.find('/') + 1));

  num2 = std::stoi(s2.substr(0, s2.find('/')));
  den2 = std::stoi(s2.substr(s2.find('/') + 1));

  Fraction f1(num1, den1);
  Fraction f2(num2, den2);

  Fraction sum  = f1.plus(f2);
  Fraction diff = f1.minus(f2);
  Fraction prod = f1.times(f2);
  Fraction quot = f1.by(f2);

  // format: a/b + c/d = mixed
  f1.display(); std::cout << " + "; f2.display(); std::cout << " = "; sum.displayMixed();  std::cout << "\n";
  f1.display(); std::cout << " - "; f2.display(); std::cout << " = "; diff.displayMixed(); std::cout << "\n";
  f1.display(); std::cout << " * "; f2.display(); std::cout << " = "; prod.displayMixed(); std::cout << "\n";
  f1.display(); std::cout << " / "; f2.display(); std::cout << " = "; quot.displayMixed(); std::cout << "\n";

  return 0;
}