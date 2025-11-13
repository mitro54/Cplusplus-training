#include <iostream>

class Node {
public:
  Node(int val);
  ~Node();
  int value;
  Node* next;
  Node* prev;
};

Node::Node(int val) : value(val), next(nullptr), prev(nullptr) {}

Node::~Node() {}

class List {
public:
  List();
  List(List &other);
  ~List();
  void push_front(int value);
  void push_back(int value);
  bool pop_front(int &value);
  bool pop_back(int &value);
  void insert_at(int index, int value);
  void remove_at(int index);
  int at(int index);
  int size();
private:
  Node* head;
  Node* tail;
  int len = 0;
};

List::List() : head(nullptr), tail(nullptr) {}

List::List(List &other) : List() {
  Node* n = other.head;
  while (n != nullptr) {
    push_back(n->value);
    n = n->next;
  }
}

List::~List() {
  while (head != nullptr) {
    Node* next = head->next;
    delete head;
    head = next;
  }
}


void List::push_front(int value) {
  Node* new_head = new Node(value);

  new_head->next = head;
  new_head->prev = nullptr;

  if (head != nullptr) {
    head->prev = new_head;
  } else {
    tail = new_head;
  }

  head = new_head;
  len++;
  std::cout << "pushed " << value << " to front, size: " << len << "\n";
}

void List::push_back(int value) {
  Node* new_tail = new Node(value);
  new_tail->next = nullptr;
  new_tail->prev = tail;

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

  Node* old_head = head;
  value = old_head->value;

  head = old_head->next;
  if (head != nullptr) {
    head->prev = nullptr;
  } else {
    tail = nullptr;
  }

  delete old_head;
  len--;
  std::cout << "popped " << value << " from front, size: " << len << "\n";
  return true;
}

bool List::pop_back(int &value) {
  if (!tail) return false;

  Node* old_tail = tail;
  value = old_tail->value;

  tail = old_tail->prev;
  if (tail != nullptr) {
    tail->next = nullptr;
  } else {
    head = nullptr;
  }

  delete old_tail;
  len--;
  std::cout << "popped " << value << " from back, size: " << len << "\n";
  return true;
}


int List::size() {
  return len;
}

int List::at(int index) {
  if (index < 0 || index >= len) {
    return -1;
  }
  Node* current = head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }
  return current->value;
}


void List::insert_at(int index, int value) {
  if (index < 0 || index > len) return;

  if (index == 0) {
    push_front(value);
    return;
  }
  if (index == len) {
    push_back(value);
    return;
  }

  Node* current = head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }

  Node* new_node = new Node(value);

  new_node->next = current;
  new_node->prev = current->prev;

  current->prev->next = new_node;
  current->prev = new_node;

  len++;
}

void List::remove_at(int index) {
  if (index < 0 || index >= len || head == nullptr) return;

  if (index == 0) {
    int dummy;
    pop_front(dummy);
    return;
  }
  if (index == len - 1) {
    int dummy;
    pop_back(dummy);
    return;
  }

  Node* current = head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }

  current->prev->next = current->next;
  current->next->prev = current->prev;

  delete current;
  len--;
}


void print_list(List &list) {
  for (int i = 0; i < list.size(); i++)
    std::cout << "list[" << i << "] == " << list.at(i) << std::endl;
}

int main() {
  List list;
  for (int i = 0; i < 4; i++)
    list.push_front(i);
  std::cout << std::endl;

  int value = 0;
  while (list.pop_front(value)) {}
  std::cout << std::endl;

  for (int i = 0; i < 4; i++)
    list.push_back(i);
  std::cout << std::endl;

  while (list.pop_back(value)) {}

  for (int i = 0; i < 4; i++)
    list.push_back(i);
  print_list(list);
  std::cout << "\n" << "found num 2 at idx: " << list.at(2) << "\n";

  list.insert_at(2, 23);
  print_list(list);
  std::cout << "\n";

  list.remove_at(2);
  print_list(list);

  std::cout << "copy: \n";
  List list2(list);
  print_list(list2);
  return 0;
}