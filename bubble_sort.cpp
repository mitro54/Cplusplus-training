#include <iostream>

int main(void) {

    int array[5];
    int aux;
    bool swap;

    std::cout << "Enter 5 values to sort them out. \n";

    for (int i = 0; i < 5; i++) {
        std::cout << "Give value #" << i + 1 << ": ";
        std::cin >> array[i];
    }

    do {
        swap = false;
        for (int i = 0; i < 4; i++) {
            if (array[i] > array[i + 1]) {
                swap = true;
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
            }
        }
    } while (swap);

    for (int i = 0; i < 5; i++) {
    std::cout << array[i] << " ";
    }
    return 0;
}