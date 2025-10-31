#include <iostream>
#include <vector>
#include <string>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved = 0);
  void printStatus() const;

  // getters
  int getCapacity() const { return capacity; };
  int getReserved() const { return reserved; };
  int getId() const { return id; }
  int getCapacityPercentage() const;

  // setters
  void setCapacity(int capacity) { this->capacity = capacity; };
  void setReserved(int reserved) { this->reserved = reserved; };

private:
  int id;
  int capacity;
  int reserved;
};

int FlightBooking::getCapacityPercentage() const {
  return (100 * reserved) / capacity;
}

void FlightBooking::printStatus() const {
  // format: Flight id_n : res_n/cap_n (x%) seats reserved.
  std::cout << "Flight " << id << " : " << reserved << '/' << capacity
  << " (" << getCapacityPercentage() << "%) seats reserved.";
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
  this->id = id;
  this->capacity = (capacity > 1) ? capacity : 1;
  this->reserved = (reserved > 0) ? reserved : 0;
  int init_percentage = (100 * this->reserved) / this->capacity;
  if (init_percentage > 105) this->reserved = (this->capacity * 105) / 100;
}

int main() {
  std::vector<FlightBooking> bookings;

  while (true) {
    int id, amount;
    std::string command;
    if (bookings.size() == 0)
      std::cout << "No flights in the system\n"
      << "Commands: 'create/add/cancel n n', 'delete n' 'exit/quit'\n";
    else {
      for (FlightBooking& booking : bookings) {
        booking.printStatus();
        std::cout << std::endl;
      }
    }
    
    std::getline(std::cin, command);

    // define the first part of command as 'action' to improve readability
    std::string action = command.substr(0, command.find(' '));

    // handle user input
    if (command.find(' ') != std::string::npos) {
      try {
        // str to int, substr starting of the first found space + 1 to second found space
        id = std::stoi(command.substr(command.find(' ') + 1, command.size() - command.find(' ', command.find(' '))));
        if (action != "delete")
          // str to int, substr starting of the second found space to the rest of the str
          amount = std::stoi(command.substr(command.find(' ', command.find(' ') + 1)));
      } catch (...) {
        std::cout << "In 'command n n', n has to be a number!\n";
        std::cout << "Commands: 'create/add/cancel flight_n seats_n', 'delete flight_n', 'quit' or 'exit'\n\n";
        continue;
      }

      // create
      if (action == "create") {
        FlightBooking booking(id, amount);
        bookings.push_back(booking);

      // add
      } else if (action == "add") {
        for (FlightBooking& booking : bookings) {
          if (booking.getId() == id) {
            int new_flight_res = booking.getReserved() + amount;
            if (100 * new_flight_res / booking.getCapacity() > 105)
              std::cout << "Cannot perform this operation.\n";
            else {
              booking.setReserved(new_flight_res);
            }
          }
        }

      // cancel
      } else if (action == "cancel") {
        for (FlightBooking& booking : bookings)
          if (id == booking.getId()) {
            int new_flight_res = booking.getReserved() - amount;
            if (new_flight_res < 0)
              std::cout << "Cannot perform this operation.\n";
            else {
              booking.setReserved(new_flight_res);
            }
          }

      // delete
      } else if (action == "delete") {
        for (int i = 0; i < bookings.size(); i++) {
          if (bookings[i].getId() == id) {
            bookings.erase(bookings.begin() + i);
            break;
          }
        }
      }
  } // exit
    if (command == "quit" || command == "exit") break;
  }

  return 0;
}