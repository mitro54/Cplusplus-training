#include <iostream>

// variables to manage the queue
int arr[5] = {};
int next = 0, last = 0;

void enqueue(int val) {
    // make sure there is room to add an item
    int length = sizeof(arr) / sizeof(arr[0]);
    if ((next + 1) % length == last) throw std::runtime_error("queue is full");

    arr[next] = val;
    next = (next + 1) % length;
}

int main(void) {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < length; i++)
    std::cout << arr[i] << ' ';
}