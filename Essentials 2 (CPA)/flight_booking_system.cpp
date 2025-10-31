#include <iostream>

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
private:
  int id;
  int capacity;
  int reserved;
};

void FlightBooking::printStatus() {
  // format: Flight id_n : res_n/cap_n (x%) seats reserved.
  std::cout << "Flight " << id << " : " << reserved << '/' << capacity
  << " (" << (100 * reserved) / capacity << "%) seats reserved.";
}

FlightBooking::FlightBooking(int id, int capacity, int reserved) {
  this->id = id;
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

  return 0;
}