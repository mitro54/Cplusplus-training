#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    std::vector<Node*> buckets; // each bucket is top of a linked list

    int hash(int key) const {
        return key % buckets.size();
    }

public:
    HashTable(int bucket_count) : buckets(bucket_count, nullptr) {}

    // insert key if not already present
    void insert(int key) {
        int i = hash(key);
        Node* head = buckets[i];

        // check for duplicate
        for (Node *curr = head; curr != nullptr; curr = curr->next) {
            if (curr->key == key) return; // already present
        }

        // insert at front
        Node *new_node = new Node(key);
        new_node->next = head;
        buckets[i] = new_node;
    }

    // find key, returns true if found
    bool contains(int key) const {
        int i = hash(key);
        for (Node *curr = buckets[i]; curr != nullptr; curr = curr->next) {
            if (curr->key == key) return true;
        }
        return false;
    }

    // remove key
    void remove(int key) {
        int i = hash(key);
        Node* curr = buckets[i];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev) prev->next = curr->next;
                else buckets[i] = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    // print structure of the table
    void print() const {
        for (int i = 0; i < buckets.size(); ++i) {
            std::cout << i << ": ";
            for (Node *curr = buckets[i]; curr; curr = curr->next)
                std::cout << curr->key << " -> ";
            std::cout << "NULL\n";
        }
    }
};

int main() {
    HashTable h(10);
    h.insert(220);
    h.insert(391);
    h.insert(122);
    h.insert(543);
    h.insert(364);
    h.insert(435);
    h.insert(606);
    h.insert(617);
    h.insert(989);
    h.insert(489);
    h.print();
}