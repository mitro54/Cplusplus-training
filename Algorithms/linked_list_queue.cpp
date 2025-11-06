#include <iostream>
#include <vector>
#include <stdexcept>

// the cell, contains data and a pointer to the next cell
class Node {
public:
    int value;
    Node *next;
    Node *prev;
    Node(int v) : value(v), next(nullptr), prev(nullptr) {}
};

// doubly LinkedList that contains only the necessary methods to create queues and dequeues
class LinkedListQueue {
private:
    Node *sentinel;

public:
    LinkedListQueue() {
        sentinel = new Node(0);
        sentinel->next = nullptr;
        sentinel->prev = nullptr;
    }

    // pushes node to the queue
    void enqueue(int value) {
        Node *new_cell = new Node(value);
        new_cell->next = sentinel->next;
        new_cell->prev = sentinel;

        if (sentinel->next)
            sentinel->next->prev = new_cell;
        else
            sentinel->prev = new_cell;

        sentinel->next = new_cell;
        if (!sentinel->prev) sentinel->prev = new_cell;
    }

    // removes the node from queue
    int dequeue() {
        // make sure there is an item to dequeue
        if (sentinel->prev == nullptr) throw std::runtime_error("queue is empty");
        // get the bottom cells value
        Node *bottom = sentinel->prev;
        int result = bottom->value;
        Node *new_bottom = bottom->prev;
        // remove the bottom cell from the linked list
        if (new_bottom == sentinel) {
            sentinel->next = nullptr;
            sentinel->prev = nullptr;
        } else {
            new_bottom->next = nullptr;
            sentinel->prev = new_bottom;
        }

        delete bottom;
        return result;
    }

    // prints the queue
    void print() const {
        std::cout << "Queue: ";
        for (Node *cur = sentinel->next; cur; cur = cur->next)
            std::cout << cur->value << ' ';
        std::cout << '\n';
    }
};

int main(void) {
    LinkedListQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';
    std::cout << q.dequeue() << '\n';
    q.print();
    return 0;
}