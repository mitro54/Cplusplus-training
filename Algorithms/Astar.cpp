#include <iostream>
#include <vector>

struct Item {
    int x, y; // grid pos
    int f; // f = g + h, priority = smaller better
};

// priority queue as a sorted vector, ascends by f
std::vector<Item> open_list;

void enqueue(const Item& item) {
    open_list.push_back(item);
    int i = open_list.size() - 2;
    // shift items right while their f is larger than new f
    while (i >= 0 && open_list[i].f > item.f) {
        open_list[i + 1] = open_list[i];
        i--;
    }
    // place value at the correct spot
    open_list[i + 1] = item;
}

// pop the best from front
Item pop_front() {
    Item best = open_list.front();
    open_list.erase(open_list.begin());
    return best;
}