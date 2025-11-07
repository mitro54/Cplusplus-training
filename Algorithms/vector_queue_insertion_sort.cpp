// sivu 127
#include <iostream>
#include <vector>

std::vector<int> arr = {};

void enqueue(int val) {
    arr.push_back(val);
    int i = arr.size() - 2;
    // shift values right
    while (i >= 0 && arr[i] > val) {
        arr[i + 1] = arr[i];
        i--;
    }
    // place value at the correct spot
    arr[i + 1] = val;
}

int main(void) {
    enqueue(2);
    enqueue(1);
    enqueue(23);
    enqueue(4);
    enqueue(12);
    for (int i = 0; i < arr.size(); i++)
    std::cout << arr[i] << ' ';
    return 0;
}