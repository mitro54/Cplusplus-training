// sivu 117
#include <iostream>
#include <vector>

// the cell, contains data and a pointer to the next cell
class Node {
public:
    int value;
    Node *next;
    Node(int v) : value(v), next(nullptr) {}
};

// singly LinkedList that contains only the necessary methods to create a stack with push / pop methods
class LinkedListStack {
private:
    Node *sentinel;

public:
    LinkedListStack() {
        sentinel = new Node(0);
        sentinel->next = nullptr;
    }

    // pushes node to the linked list
    void push(int value) {
        // make a new cell to hold the new value
        Node *new_cell = new Node(value);
        // add the new cell to the linked list
        new_cell->next = sentinel->next;
        sentinel->next = new_cell;
    }

    // pops top cell from stack returning the value
    int pop() {
        // make sure there is an item to pop
        if (sentinel->next == nullptr) throw std::runtime_error("stack is already empty");
        // get the top cells value
        Node *top = sentinel->next;
        int result = top->value;
        // remove the top cell from the stack
        sentinel->next = top->next;
        delete top;

        return result;
    }

    // prints the stack
    void print() const {
        Node *current = sentinel->next;
        std::cout << "Stack: ";
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

};

void reverseArray(std::vector<int>& vals) {
LinkedListStack stack;
// push the values from the array onto the stack
for (int i = 0; i < vals.size(); i++) stack.push(vals[i]);
// pop the items off the stack into the array
for (int i = 0; i < vals.size(); i++) vals[i] = stack.pop();
}

// testing setup
int main(void) {
    std::vector<int> arr = {1, 2, 3, 4, 5};

    for (int i = 0; i < arr.size(); i++) std::cout << arr[i];
    std::cout << "\n";

    reverseArray(arr);

    for (int i = 0; i < arr.size(); i++) std::cout << arr[i];
}