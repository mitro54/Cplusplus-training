#include <iostream>
#include <string>
#include <cmath>
#include <numeric>

class Fraction {
public:
  Fraction(int numerator, int denominator);
  std::string toString();
  double toDouble();
  void display();
  void displayMixed();
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

double Fraction::toDouble() {
  return double(numerator) / denominator;
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

  // format: a/b < c/d
  f1.displayMixed();
  if (f1.toDouble() > f2.toDouble())
    std::cout << " > ";
  else
    std::cout << " < "; 
  f2.displayMixed();

  return 0;
}