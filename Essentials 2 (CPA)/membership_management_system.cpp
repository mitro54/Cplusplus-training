#include <iostream>
#include <string>

class Membership {
public:
  Membership(int id, int valid_for, std::string name);
  void printStatus() const;

  // getters
  int getId() const { return id; }
  int getValidity() const { return valid_for; }
  std::string getName() const { return name; }

  // setters
  void setValidity(int id) { this->id = id; }
  void setName(std::string name) { this->name = name; }

private:
  int id;
  int valid_for;
  std::string name;
};

Membership::Membership(int id, int valid_for, std::string name) {
  this->id = id;
  this->valid_for = valid_for;
  this->name = name;
}

void Membership::printStatus() const {
  std::cout << "Member " << id << " : " << name << ", subscription valid for " 
  << valid_for << (valid_for == 1) ? " month" : " months"; 
}

int main(void) {
  return 0;
}