#include <iostream>

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

// testing setup
int main(void) {
    LinkedListStack list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    std::cout << "current stack: ";
    list.print();

    std::cout << "pop: " << list.pop() << "\n";
    list.print();
}