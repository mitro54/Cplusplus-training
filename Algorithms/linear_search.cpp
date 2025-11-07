#include <iostream>
#include <vector>

// find the target items index in the sorted array
// if the item isnt in the array, return -1
int linear_search(std::vector<int> vals, int target) {
    for (int i = 0; i <= vals.size(); i++) {
        // see if this is the target
        if (vals[i] == target) return i;
        // see if we have passed where the target would be
        if (vals[i] > target) return -1;
    }
    // if we get here, the target is not in the vector
    return -1;
}

int main(void) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::cout << "idx of the target (-1 == not found): " <<  linear_search(arr, 3);
    return 0;
}