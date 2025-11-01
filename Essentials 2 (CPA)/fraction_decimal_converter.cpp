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
  std::string fracstr;

  if (fabs(numerator) >= fabs(denominator)) {
    int count = 0, new_num = numerator;
    for (int i = fabs(denominator); i <= fabs(numerator); i += fabs(denominator)) {
      count++;
    }
    // this runs only if numerator > denominator
    if (count > 0) {
      if (numerator > 0 && denominator > 0)
        new_num -= (denominator * count);
      else if (numerator < 0 && denominator < 0)
        new_num -= (denominator * count);
      else {
        fracstr += "-";
        new_num -= (-denominator * count);
      }
      fracstr += std::to_string(count);
    }
    // returns whole if it evens out, otherwise returns whole + fracs
    if (new_num == 0) return fracstr;
    return fracstr + " " + std::to_string(int(fabs(new_num))) + '/' + std::to_string(int(fabs(denominator)));

  // if only fracs,  it returns fracs
  } else {
      if (numerator < 0 && denominator > 0) fracstr += "-";
      else if (numerator > 0 && denominator < 0) fracstr += "-";
    return fracstr + std::to_string(int(fabs(numerator))) + '/' + std::to_string(int(fabs(denominator)));
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