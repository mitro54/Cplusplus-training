// sivu 124
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
    Node* top_sentinel;
    Node* bottom_sentinel;

public:
    LinkedListQueue() {
        top_sentinel = new Node(0);
        bottom_sentinel = new Node(0);
        top_sentinel->next = bottom_sentinel;
        top_sentinel->prev = nullptr;
        bottom_sentinel->prev = top_sentinel;
        bottom_sentinel->next = nullptr;
    }

    // pushes node to the queue
    void enqueue(int new_value) {
        // make a cell to hold the new value
        Node* new_cell = new Node(new_value);
        // add the new cell to the linked list
        new_cell->next = top_sentinel->next;
        new_cell->prev = top_sentinel;
        top_sentinel->next->prev = new_cell;
        top_sentinel->next = new_cell;
    }

    // removes the node from queue
    int dequeue() {
        // make sure there is a n item to dequeue
        if (bottom_sentinel->prev == top_sentinel) throw std::runtime_error("queue is empty");
        // get the bottom cells value
        Node* bottom = bottom_sentinel->prev;
        int result = bottom->value;
        // remove the bottom cell from the linked list
        bottom_sentinel->prev = bottom->prev;
        bottom_sentinel->prev->next = bottom_sentinel;
        delete bottom;
        return result;
    }

    // prints the queue
    void print() const {
        std::cout << "Queue: ";
        for (Node* current = top_sentinel->next; current != bottom_sentinel; current = current->next)
            std::cout << current->value << ' ';
        std::cout << '\n';
    }
};

// testing setup
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
}