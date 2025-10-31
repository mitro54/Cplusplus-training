#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();

  // getters
  int getCapacity() { return capacity; };
  int getReserved() { return reserved; };
  int getCapacityPercentage();

  // setters
  void setCapacity(int capacity) { this->capacity = capacity; };
  void setReserved(int reserved) { this->reserved = reserved; };

private:
  int id;
  int capacity;
  int reserved;
};

int FlightBooking::getCapacityPercentage() {
  return (100 * reserved) / capacity;
}

void FlightBooking::printStatus() {
  // format: Flight id_n : res_n/cap_n (x%) seats reserved.
  std::cout << "Flight " << id << " : " << reserved << '/' << capacity
  << " (" << getCapacityPercentage() << "%) seats reserved.";
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
  this->id = id;
  int init_percentage = (100 * reserved) / capacity;
  if (init_percentage > 105) reserved = (capacity * 105) / 100;
  this->capacity = (capacity > 0) ? capacity : 0;
  this->reserved = (reserved > 0) ? reserved : 0;
}

int main() {
  int reserved = 0, capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  booking.printStatus();
  std::cout << "\nCommands: 'add n', 'cancel n', 'quit'\n";

  while (true) {
    std::string command;
    std::getline(std::cin, command);

    // handle user input
    if (command.find(' ') != std::string::npos) {
      try {
      int val = std::stoi(command.substr(command.find(' ') + 1));
      } catch (...) { 
        std::cout << "In 'command n', n has to be a number!\n";
        booking.printStatus();
        std::cout << "\nCommands: 'add n', 'cancel n', 'quit'\n";
        continue; 
      }

      if (command.substr(0, command.find(' ')) == "add") {
        std::cout << command.substr(command.find(' ') + 1);
      }
      else if (command.substr(0, command.find(' ')) == "cancel") {
        std::cout << command.substr(command.find(' ') + 1);
      }
    }
    if (command == "quit") break;
  }

  return 0;
}