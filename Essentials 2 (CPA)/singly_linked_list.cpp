#include <iostream>

class Node {
public:
  Node(int val);
  ~Node();
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {
  std::cout << "+Node" << std::endl;
}

Node::~Node() {
  std::cout << "-Node" << std::endl;
}

class List {
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
private:
  Node* head;
};

List::List() : head(nullptr) {}

List::~List() {
  while (head != nullptr) {
    Node* next = head;
    head = head->next;
    delete next;
  }
}

void List::push_front(int value) {
  Node* new_head = new Node(value);
  new_head->next = head;
  head=new_head;
}

bool List::pop_front(int &value) {
  if (!head) return false;
  Node* current = head;
  head = current->next;
  value = current->value;
  delete current;
  return true;
}

int main() {
  List list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  int value = 0;
  while (list.pop_front(value))
  {
    std::cout << value << std::endl;
  }
  return 0;
}