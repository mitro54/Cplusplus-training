#include <iostream>

// the cell, contains data and a pointer to the next cell
class Node {
public:
    int value;
    Node *next;

    Node(const int& val) : value(val), next(nullptr) {}
};

// contains the singly linked list class and its methods
class LinkedList {
private:
    Node* top; // exists only to showcase that i did use top before switching to sentinel (task related)
    Node *sentinel;
    
public:
    LinkedList() : top(nullptr) {
        sentinel = new Node(0);
        sentinel->next = nullptr;
    }

    // adds nodes to the end of list
    void append(const int& value) {
        Node *newNode = new Node(value);
        if (!top) {
            top = newNode;
            sentinel->next = top;
            return;
        }

        Node *current = top;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // adds nodes to the start of list
    void prepend(const int& value) {
        Node *newNode = new Node(value);
        newNode->next = sentinel->next;
        sentinel->next = newNode;
    }

    // inserts new node after position of the cell after_me
    void insert(Node* after_me, const int& value) {
        if (!after_me) return; 
        Node *newNode = new Node(value);
        newNode->next = after_me->next;
        after_me->next = newNode;
    }

    // deletes the node after the position of the cell after_me
    void delete_after(Node* after_me) {
        if (!after_me || !after_me->next) return; // nothing to delete
        Node* doomed = after_me->next;
        after_me->next = doomed->next;
        delete doomed;
    }

    // destroys the whole list but not sentinel
    void destroy() {
        Node *current = sentinel->next;
        sentinel->next = nullptr;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    // iterates over and prints the list
    void print() const {
        Node *current = sentinel->next;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    // iterates over and returns the target from the list, returns nullptr if not found
    Node* find_cell(int target) const {
        Node *current = sentinel->next;
        while (current != nullptr) {
            if (current->value == target) return current;
            current = current->next;
        }
        // if we get this far, the target is not in the list
        return nullptr;
    }

    // iterates over and returns the targets before idx from the list, returns -1 if not found
    int find_cell_before(int target) const {
        Node *current = sentinel;
        // if the list is empty, the target value isn't present
        if (current == nullptr) return -1;
        // switching to sentinel also messed this logic up, so its simulated
        int idx = -1;
        while (current->next != nullptr) {
            if (current->next->value == target) return idx;
            current = current->next;
            idx++;
        }
        // if we get this far, the target is not in the list
        return -1;
    }

    // better version of find_cell_before
    int find_cell_before_v2(int target) const {
        Node *current = sentinel;
        int idx = 0;

        while (current->next != nullptr) {
            if (current->next->value == target) return idx;
            current = current->next;
            idx++;
        }
        // if we get this far, the target is not in the list
        return -1;
    }

};

int main(void) {

// testing setup
LinkedList list;
list.append(2);
list.append(3);
list.append(5);
list.print();

list.prepend(1);
list.append(6);
list.print();

if (Node* n = list.find_cell(2))
    std::cout << "findCell(2): " << n->value << "\n";
else
    std::cout << "findCell(2): not found\n";

// this returns -1 if 1 is searched
std::cout << "findCellBefore: " << list.find_cell_before(1) << "\n";;

// but the improved version uses dummy, so it correctly returns the idx of 1
std::cout << "findCellBefore (improved): " << list.find_cell_before_v2(1) << "\n";;

std::cout << "insertion: ";
Node* pos = list.find_cell(3);
if (pos != nullptr)
    list.insert(pos, 4);
    list.print();

std::cout << "delete after 5 (should remove 6): ";
if (Node* delete_pos = list.find_cell(5))
    list.delete_after(delete_pos);
list.print();

std::cout << "destroy list: (it will be empty so nothing prints after this)";
list.destroy();
list.print();
return 0;
}