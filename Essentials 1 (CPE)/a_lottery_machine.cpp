#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {

	int maxball, ballsno;

    std::cout << "Pseudorandom lottery machine V1.0\n";
	std::cout << "Max ball number? ";
	std::cin >> maxball;
	std::cout << "How many balls? ";
	std::cin >> ballsno;
    
    // prevent from entering less numbers than balls
    if (maxball < ballsno) return 1;
    
	srand(time(NULL));
    int *arr = new int[ballsno], counter = 0;

    // roll the numbers, making sure there are no duplicates,
    while (counter < ballsno) {
        int ball = rand() % maxball + 1;
        bool in_array = false;
        
        for (int j = 0; j < counter; j++) {
            if (ball == arr[j]) in_array = true;
        }

        if (in_array) {
            continue;
        } else {
            arr[counter] = ball;
            counter++;
        }
    }

    // sort the numbers using bubble sort
    int aux;
    bool swap;

    do {
        swap = false;
        for (int i = 0; i < ballsno - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap = true;
                aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
            }
        }
    } while (swap);

    for (int i = 0; i < ballsno; i++) {
    std::cout << arr[i] << " ";
    }

    // free up the memory, return
    delete[] arr;
    arr = nullptr;
	return 0;
}