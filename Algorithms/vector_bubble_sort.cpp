#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& array) {
    int aux;
    bool swap;
    do {
        swap = false;
        for (int i = 0; i < array.size() - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap = true;
                aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
            }
        }
    } while (swap);
}

int main(void) {
    std::vector<int> arr = {4, 3, 5, 1, 2};
    bubble_sort(arr);
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";
}