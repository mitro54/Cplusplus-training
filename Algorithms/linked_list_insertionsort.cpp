#include <iostream>

// the cell, contains data and a pointer to the next cell
class Node {
public:
    int value;
    Node *next;
    Node(int v) : value(v), next(nullptr) {}
};

// singly LinkedList that contains only the methods to test insertion sorting
class LinkedList {
private:
    Node *sentinel;

public:
    LinkedList() {
        sentinel = new Node(0);
        sentinel->next = nullptr;
    }


    // adds nodes to the end of list
    void append(int value) {
        Node *current = sentinel;
        while (current->next) current = current->next;
        current->next = new Node(value);
    }

    // prints the list
    void print() const {
        for (Node *current = sentinel->next; current; current = current->next)
            std::cout << current->value << " ";
        std::cout << "\n";
    }


    // use insertionsort to sort the list
    void insertion_sort() {
        // make a new sentinel for the sorted list
        Node *sorted_sentinel = new Node(0);
        sorted_sentinel->next = nullptr;

        // skip this lists sentinel, start with the first real node
        Node *input = sentinel->next;

        // repeat until all nodes are inserted into sorted list
        while (input != nullptr) {
            Node *next_cell = input;
            input = input->next;

            // find where to insert in sorted list
            Node *after_me = sorted_sentinel;
            while (after_me->next != nullptr &&
                   after_me->next->value < next_cell->value) {
                after_me = after_me->next;
            }

            // insert into sorted list
            next_cell->next = after_me->next;
            after_me->next = next_cell;
        }

        // replace old sentinel with new one
        sentinel->next = nullptr;
        delete sentinel;
        sentinel = sorted_sentinel;
    }
};

int main(void) {
    // testing setup
    LinkedList list;
    list.append(4);
    list.append(5);
    list.append(8);
    list.append(10);
    list.append(1);
    std::cout << "before sorting: ";
    list.print();

    list.insertion_sort();
    std::cout << "after sorting:  ";
    list.print();
}