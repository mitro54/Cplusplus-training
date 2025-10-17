#include <iostream>

int main(void) {
  int * numbers, how_many_numbers;
  int aux;
  bool swapped;

  std::cout << "How many numbers are you going to sort? ";
  std::cin >> how_many_numbers;
  if (how_many_numbers <= 0 || how_many_numbers > 1000000) {
    std::cout << "Are you kidding?";
    return 1;
  }
  numbers = new int[how_many_numbers];
  for (int i = 0; i < how_many_numbers; i++) {
    std::cout << "\nEnter the number #" << i + 1 << ": ";
    std::cin >> numbers[i];
  }
  do {
    swapped = false;
    for (int i = 0; i < how_many_numbers - 1; i++)
      if (numbers[i] > numbers[i + 1]) {
        swapped = true;
        aux = numbers[i];
        numbers[i] = numbers[i + 1];
        numbers[i + 1] = aux;
      }
  } while (swapped);
  std::cout << std::endl << "The sorted array:\n";
  for (int i = 0; i < how_many_numbers; i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;
  delete[] numbers;
  return 0;
}