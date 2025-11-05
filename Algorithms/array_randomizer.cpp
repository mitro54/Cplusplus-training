#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

void RandomizeArray(std::vector<std::string>& arr) {
    int max_i = arr.size() - 1;
    for (int i = 0; i < max_i; i++) {
        // pick the item for position i in the array
        int random_num = i + (rand() % (max_i - i + 1));
        int j = random_num;
        // swaps the values of arr[i] and arr[j]
        arr[i].swap(arr[j]);
    }
}

int main(void) {
// testing setup
std::vector<std::string> array = {"one", "two", "three", "four", "five"};
RandomizeArray(array);
for (const auto& str : array)
    std::cout << str << " ";
}