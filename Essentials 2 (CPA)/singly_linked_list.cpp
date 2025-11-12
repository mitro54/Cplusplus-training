#include <iostream>

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr) {
}

class List {
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
private:
  Node* head;
};

List::List() : head(nullptr) {
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