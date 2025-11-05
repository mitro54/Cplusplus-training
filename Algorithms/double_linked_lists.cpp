#include <iostream>

// the cell, contains data and a pointers to the next and previous cell
class Node {
public:
    int value;
    Node *prev;
    Node *next;

    Node(const int& val) : value(val), next(nullptr), prev(nullptr) {}
};

// contains the double linked list class and its methods
class DoubleLinkedList {
private:
    Node *sentinel;
    
public:
    DoubleLinkedList() {
        sentinel = new Node(0);
        sentinel->next = nullptr;
        sentinel->prev = nullptr;
    }

    // adds nodes to the end of list
    void append(int value) {
        Node *current = sentinel;

        while (current->next) current = current->next;

        Node *n = new Node(value);
        current->next = n;
        n->prev = current;
    }


    // adds nodes to the start of list
    void prepend(int value) {
        Node *n = new Node(value);
        n->next = sentinel->next;
        n->prev = sentinel;

        if (sentinel->next) sentinel->next->prev = n;
        sentinel->next = n;
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

    // inserts new node after position of the cell after_me
    void insert(Node* after_me, int value) {
        if (!after_me) return;
        Node *n = new Node(value);
        n->next = after_me->next;
        n->prev = after_me;
        if (after_me->next) after_me->prev = n;
        after_me->next = n;
    }

    // inserts a new node so that the list remains sorted in non decreasing order
    void insert_sorted(int value) {
        // walk from sentinel until the next node is >= value (or end)
        Node* prev = sentinel;
        while (prev->next != nullptr && prev->next->value < value) {
            prev = prev->next;
        }
        // insert new node after prev
        Node* n = new Node(value);
        n->next = prev->next;
        prev->next = n;
        if (n->next) n->next->prev = n;
        n->prev = prev;
    }

    // inserts a new cell into the linked list, revised
    void insert_sorted_v2(int value) {
        Node* prev = sentinel;
        // find the cell before where the new value belongs
        while (prev->next != nullptr && prev->next->value < value) {
            prev = prev->next;
        }
        // insert new node after prev
        Node* n = new Node(value);
        n->next = prev->next;
        prev->next = n;
        if (n->next) n->next->prev = n;
        n->prev = prev;
    }

    // deletes the node after the position of the cell after_me
    void delete_after(Node* after_me) {
        if (!after_me || !after_me->next) return; // nothing to delete
        Node* doomed = after_me->next;
        Node* next = doomed->next;
        after_me->next = next;
        if (next) next-> prev = after_me;

        delete doomed;
    }

    // destroys the whole list but not sentinel
    void destroy() {
        Node *current = sentinel->next;
        sentinel->next = nullptr;
        while (current) {
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
};

int main(void) {
    // testing setup
    DoubleLinkedList list;
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

    list.insert_sorted(4);
    list.insert_sorted(3);
    list.insert_sorted(6);
    list.insert_sorted(7);
    list.insert_sorted(7);
    std::cout << "sorted insertion: ";
    list.print();
    list.destroy();

    list.insert_sorted_v2(5);
    list.insert_sorted_v2(7);
    list.insert_sorted_v2(3);
    list.insert_sorted_v2(1);
    list.insert_sorted_v2(12);
    std::cout << "sorted insertion (improved): ";
    list.print();
}