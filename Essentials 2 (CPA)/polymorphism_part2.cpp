#include <iostream>
#include <string>

class Piece {
public:
  virtual bool isMovePossible(std::string from, std::string to) { return false; }
protected:
  static bool isNumberInRange(int number) {
    return number <= '8' && number >= '1';
  }

  static bool isLetterInRange(char letter) {
    return letter <= 'h' && letter >= 'a';
  }
};

class King : public Piece {
public:
  bool isMovePossible(std::string from, std::string to);
};

bool King::isMovePossible(std::string from, std::string to) {
  bool is_possible = false;
  if (from.length() == 2 && to.length() == 2) {
    char letter_from = from[0];
    char number_from = from[1];
    char letter_to = to[0];
    char number_to = to[1];
    if (abs(letter_from - letter_to) == abs(number_from - number_to)) {
      if (isNumberInRange(number_from) && isLetterInRange(letter_from))
        if (isNumberInRange(number_to) && isLetterInRange(letter_to))
          is_possible = true;
        }
      }
      return is_possible;
    }

class Man : public Piece {
public:
  bool isMovePossible(std::string from, std::string to);
};

bool Man::isMovePossible(std::string from, std::string to) {
  bool is_possible = false;
  if (from.length() == 2 && to.length() == 2) {
    char letter_from = from[0];
    char number_from = from[1];
    char letter_to = to[0];
    char number_to = to[1];
    if (abs(letter_from - letter_to) == abs(number_from - number_to) && abs(number_from - number_to) == 1) {
      if (isNumberInRange(number_from) && isLetterInRange(letter_from))
        if (isNumberInRange(number_to) && isLetterInRange(letter_to))
          is_possible = true;
        }
      }
      return is_possible;
    }

int main(void) {
	Piece *pieces[3];
	pieces[0] = new Man();
	pieces[1] = new King();
	pieces[2] = new Man();
	std::cout.setf(std::ios::boolalpha);
	std::cout << pieces[0]->isMovePossible("b1", "c2") << "\n";
	std::cout << pieces[1]->isMovePossible("b1", "d3") << "\n";
	std::cout << pieces[2]->isMovePossible("b1", "d3") << "\n";
	return 0;
}