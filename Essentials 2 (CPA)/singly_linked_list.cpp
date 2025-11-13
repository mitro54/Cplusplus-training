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
  void push_back(int value);
  bool pop_front(int &value);
  bool pop_back(int &value);
  int size();
private:
  Node* head;
  Node* tail;
  int len = 0;
};

List::List() : head(nullptr), tail(nullptr) {}

List::~List() {
  while (head != nullptr) {
    Node* next = head;
    head = head->next;
    delete next;
  }
}

void List::push_front(int value) {
  Node* new_head = new Node(value);
  if (len == 0) tail = new_head;
  new_head->next = head;
  head=new_head;
  len++;
  std::cout << "pushed " << value << " to front, size: " << len << "\n";
}

void List::push_back(int value) {
  Node* new_tail = new Node(value);
  new_tail->next = nullptr;
  if (!head) {
    head = new_tail;
    tail = new_tail;
  } else {
    tail->next = new_tail;
    tail = new_tail;
  }
  len++;
  std::cout << "pushed " << value << " to back, size: " << len << "\n";
}

bool List::pop_front(int &value) {
  if (!head) return false;
  Node* current = head;
  head = current->next;
  value = current->value;
  delete current;
  len--;
  std::cout << "popped " << value << " from front, size: " << len << "\n";
  return true;
}

bool List::pop_back(int &value) {
  if (!head) return false;

  if (head == tail) {
    value = head->value;
    delete head;
    head = tail = nullptr;
    len--;
    std::cout << "popped " << value << " from back, size: " << len << "\n";
    return true;
  }

  Node* prev = head;
  while (prev->next != tail) {
    prev = prev->next;
  }

  value = tail->value;
  delete tail;
  tail = prev;
  tail->next = nullptr;
  len--;
  std::cout << "popped " << value << " from back, size: " << len << "\n";
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
  std::cout << std::endl;
  list.push_back(0);
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  std::cout << std::endl;
  while (list.pop_back(value)) {}
  return 0;
}