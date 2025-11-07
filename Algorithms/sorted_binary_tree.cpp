#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}

    // add a node to this nodes sorted subtree
    void AddNode(int new_value) {
        // see if this value is smaller than ours
        if (new_value < value) {
            // the new value is smaller, add it to the left subtree
            if (left == nullptr)
                left = new Node(new_value);
            else
                left->AddNode(new_value);
        }
        else {
            // the new value is not smaller, add it to the right subtree
            if (right == nullptr)
                right = new Node(new_value);
            else
                right->AddNode(new_value);
        }
    }

    // find a node with a given target value
    Node* FindNode(int target) {
        // if we've found the target value, return this node
        if (target == value) return this;

        // see if the desired value is in the left or right subtree
        if (target < value) {
            // search the left subtree
            if (left == nullptr) return nullptr;
            return left->FindNode(target);
        }
        else {
            // search the right subtree
            if (right == nullptr) return nullptr;
            return right->FindNode(target);
        }
    }
};

class BinaryTree {
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    // insert a value into the tree
    void insert(int value) {
        if (root == nullptr)
            root = new Node(value);
        else
            root->AddNode(value);
    }

    // find a value in the tree
    Node* find(int target) {
        if (root == nullptr) return nullptr;
        return root->FindNode(target);
    }

    // print inorder
    void print() const {
        print_rec(root);
        std::cout << "\n";
    }

private:
    void print_rec(Node* node) const {
        if (!node) return;
        print_rec(node->left);
        std::cout << node->value << " ";
        print_rec(node->right);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(1);
    tree.insert(3);
    tree.print();

    Node *found = tree.find(3);
    if (found)
        std::cout << "Found: " << found->value << "\n";
    else
        std::cout << "Not found\n";
    return 0;
}
