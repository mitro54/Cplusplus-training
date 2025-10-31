#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();

  // getters
  int getCapacity() { return capacity; };
  int getReserved() { return reserved; };
  int getId() { return id; }
  int getCapacityPercentage();

  // setters
  void setCapacity(int capacity) { this->capacity = capacity; };
  void setReserved(int reserved) { this->reserved = reserved; };
  void setId(int id) { this->id = id;}

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
  std::cout << "No flights in the system\n";
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;

  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;

  FlightBooking booking(1, capacity, reserved);

  booking.printStatus();
  std::cout << "\nCommands: 'add n', 'cancel n', 'quit'\n";

  while (true) {
    int val1, val2;
    std::string command;
    std::getline(std::cin, command);

    // handle user input  
    if (command.find(' ') != std::string::npos) {
      try {
        // str to int, substr starting of the first found space + 1 to second found space
        val1 = std::stoi(command.substr(command.find(' ') + 1, command.find(' ', command.find(' '))));
        // str to int, substr starting of the second found space to the rest of the str
        val2 = std::stoi(command.substr(command.find(' ', command.find(' ') + 1)));
        std::cout << val1 << val2;
      } catch (...) {
        std::cout << "In 'command n n', n has to be a number!\n";
        booking.printStatus();
        std::cout << "\nCommands: 'create/add/cancel flight_n seats_n', 'delete flight_n', 'quit' or 'exit'\n";
        continue; 
      }

      // create
      if (command.substr(0, command.find(' ')) == "create") {
        int new_flight_res = booking.getReserved() + val1;
        if (100 * new_flight_res / booking.getCapacity() > 105)
          std::cout << "Cannot perform this operation.\n";
        else {
          booking.setReserved(new_flight_res);
          booking.printStatus();
          std::cout << std::endl;
        }

      // add
      } else if (command.substr(0, command.find(' ')) == "add") {
        int new_flight_res = booking.getReserved() + val1;
        if (100 * new_flight_res / booking.getCapacity() > 105)
          std::cout << "Cannot perform this operation.\n";
        else {
          booking.setReserved(new_flight_res);
          booking.printStatus();
          std::cout << std::endl;
        } 

      // cancel
      } else if (command.substr(0, command.find(' ')) == "cancel") {
        int new_flight_res = booking.getReserved() - val1;
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