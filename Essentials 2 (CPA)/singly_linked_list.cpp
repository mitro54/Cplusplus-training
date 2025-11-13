#include <iostream>

class Node {
public:
  Node(int val);
  ~Node();
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {}

Node::~Node() {}

class List {
public:
  List();
  ~List();
  void push_front(int value);
  bool pop_front(int &value);
  int size();
private:
  Node* head;
  int len = 0;
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
  len++;
  std::cout << "pushed " << value << " size: " << len << "\n";
}

bool List::pop_front(int &value) {
  if (!head) return false;
  Node* current = head;
  head = current->next;
  value = current->value;
  delete current;
  len--;
  std::cout << "popped " << value << " size: " << len << "\n";
  return true;
}

int List::size() {
  return len;
}

int main() {
  List list;
  list.push_front(0);
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  std::cout << std::endl;

  int value = 0;
  while (list.pop_front(value)) {}
  return 0;
}