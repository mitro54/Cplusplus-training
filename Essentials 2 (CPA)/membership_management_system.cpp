#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Membership {
public:
  Membership(int id, std::string name, int valid_for = 0);
  void printStatus() const;

  // getters
  int getId() const { return id; }
  int getValidity() const { return valid_for; }
  std::string getName() const { return name; }

  // setters
  void setValidity(int valid_for) { this->valid_for = valid_for; }
  void setName(std::string name) { this->name = name; }

private:
  int id;
  int valid_for;
  std::string name;
};

Membership::Membership(int id, std::string name, int valid_for) {
  this->id = (id > 0) ? id : 1;
  this->valid_for = (valid_for < 0) ? 0 : valid_for;
  this->name = name;
}

void Membership::printStatus() const {
  std::cout << "Member " << id << " : " << name << ", subscription valid for " 
  << valid_for << " months\n"; 
}

int main(void) {
  std::vector<Membership> members;

  // main program loop
  while (true) {
    int id, amount;
    std::string cmd, action, name;
    std::cout << "Commands: create/extend id len, delete/cancel id, quit\n\n";

    if (members.size() == 0)
      std::cout << "No members in the system\n";
    else {
      for (auto& member : members)
        member.printStatus();
    }

    // get the input, use istringstream, then parse input to action
    std::getline(std::cin, cmd);
    if (cmd.empty()) continue;

    std::istringstream iss(cmd);
    iss >> action;
    if (action == "quit") break;
    iss >> id;

    try {
      if (action == "create") {
        std::getline(iss, name);
        name = name.substr(1);

        bool exists = false;
        for (auto& member : members) if (member.getId() == id) { exists = true; break; }
        if (exists) {std::cout << "A member with that id already exists!\n\n"; continue; }

        Membership member(id, name);
        members.push_back(member);

      } else if (action == "extend") {
          iss >> amount;
          for (auto& member : members) {
            if (member.getId() == id) {
              member.setValidity(member.getValidity() + amount);
              break;
            }
        }

      } else if (action == "cancel") {
        for (auto& member : members) {
          if (member.getId() == id) {
            member.setValidity(0);
            break;
          }
        }

      } else if (action == "delete") {
          for (int i = 0; i < members.size(); i++) {
            if (members[i].getId() == id) {
              members.erase(members.begin() + i);
              break;
            }
          }
        }

      } catch (...) { std::cout << "Unable to perform this operation.\n"; }
    }
  return 0;
}