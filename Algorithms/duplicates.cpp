#include <iostream>

bool ContainsDuplicates(int arr[], int length) {
    // Loop over all of the array's items
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++) {
            // See if these two items are duplicates
            if (i != j)
                if (arr[i] == arr[j]) return true;
        }
    // if we get to this point, there are no duplicates
    return false;
}

int main(void) {
// testing setup
int array[] = {1, 2, 3, 4, 5};
int length = sizeof(array) / sizeof(array[0]);
std::cout << ContainsDuplicates(array, length);
// if no duplicates are found, couts 0, meaning false, else couts 1, meaning true.
}