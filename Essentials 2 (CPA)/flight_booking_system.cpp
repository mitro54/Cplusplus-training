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
  this->capacity = (capacity > 1) ? capacity : 1;
  this->reserved = (reserved > 1) ? reserved : 0;
  int init_percentage = (100 * this->reserved) / this->capacity;
  if (init_percentage > 105) this->reserved = (this->capacity * 105) / 100;
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
    int val;
    std::string command;
    std::getline(std::cin, command);

    // handle user input
    if (command.find(' ') != std::string::npos) {
      try {
      val = std::stoi(command.substr(command.find(' ') + 1));
      } catch (...) {
        std::cout << "In 'command n', n has to be a number!\n";
        booking.printStatus();
        std::cout << "\nCommands: 'add n', 'cancel n', 'quit' or 'exit'\n";
        continue; 
      }

      // add
      if (command.substr(0, command.find(' ')) == "add") {
        int new_flight_res = booking.getReserved() + val;
        if (100 * new_flight_res / booking.getCapacity() > 105)
          std::cout << "Cannot perform this operation.\n";
        else {
          booking.setReserved(new_flight_res);
          booking.printStatus();
          std::cout << std::endl;
        } 

      // cancel
      } else if (command.substr(0, command.find(' ')) == "cancel") {
        int new_flight_res = booking.getReserved() - val;
        if (new_flight_res < 0)
          std::cout << "Cannot perform this operation.\n";
        else {
          booking.setReserved(new_flight_res);
          booking.printStatus();
          std::cout << std::endl;
      }
    }
  } // exit
    if (command == "quit" || command == "exit") break;
  }

  return 0;
}