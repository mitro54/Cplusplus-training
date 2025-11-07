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

// helpers for deletion
// Return pointer to the node with the minimum value in this subtree.
Node* find_min(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

// Recursively remove `target` from subtree rooted at `root`.
// Return the (possibly new) subtree root after deletion.
Node* remove_rec(Node* root, int target) {
    if (!root) return nullptr;

    if (target < root->value) {
        // Go left.
        root->left = remove_rec(root->left, target);
    } else if (target > root->value) {
        // Go right.
        root->right = remove_rec(root->right, target);
    } else {
        // Found the node to delete.

        // Case 1: no children (leaf)
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        // Case 2: one child (only right or only left)
        if (!root->left) {
            Node* r = root->right;
            delete root;
            return r;
        }
        if (!root->right) {
            Node* l = root->left;
            delete root;
            return l;
        }

        // Case 3: two children.
        // Find in-order successor (smallest in right subtree),
        // copy its value here, then delete the successor node.
        Node *succ = find_min(root->right);
        root->value = succ->value;
        root->right = remove_rec(root->right, succ->value);
    }
    return root;
}

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

    void erase(int target) {
        root = remove_rec(root, target);
    }

    void print() const { print_rec(root); std::cout << "\n"; }

    ~BinaryTree() { destroy(root); }

private:
    void print_rec(Node* node) const {
        if (!node) return;
        print_rec(node->left);
        std::cout << node->value << " ";
        print_rec(node->right);
    }

    void destroy(Node* n) {
        if (!n) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }
};

int main() {
    BinaryTree t;
    for (int v : {4, 2, 10, 1, 3, 7, 8, 6, 9, 5}) t.insert(v);
    t.print();

    t.erase(1);  t.print(); // delete leaf
    t.erase(7);  t.print(); // delete node with two children (8)
    t.erase(2);  t.print(); // delete node with one child (2 had left= null, right=3 after 1 removed)
    t.erase(42); t.print(); // deleting non-existent value = no change
    return 0;
}
