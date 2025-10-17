#include <iostream>

int main(void) {
  int numbers[5];
  int aux;
  bool swap;
  
  // asks the user to enter 5 values 
  for (int i = 0; i < 5; i++) {
    std::cout << std::endl << "Enter value #" << i + 1 << ": ";
    std::cin >> numbers[i];
  }

  // sort the array 
  do {
    swap = false;
    for (int i = 0; i < 4; i++) {
      if (numbers[i] > numbers[i + 1]) {
        swap = true;
        aux = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = aux;
      }
    }
  } while (swap);

  // print the results
  std::cout << std::endl << "Sorted: " << std::endl;
  for (int i = 0; i < 5; i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;
  return 0;
}