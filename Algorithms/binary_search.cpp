#include <iostream>
#include <vector>

// find the target vals idx in the sorted vector
// if the item isnt in the vector, return -1
int binary_search(std::vector<int> vals, int target) {
    int min = 0;
    int max = vals.size() - 1;
    while (min <= max) {
        // find the dividing item
        int mid = (min + max) / 2;

        // see if we need to search the left or right half
        if (target < vals[mid]) max = mid - 1;
        else if (target > vals[mid]) min = mid + 1;
        else return mid;
    }

    // if we get here, the target is not in the vector
    return -1;
}

int main(void) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::cout << "idx of the target (-1 == not found): " <<  binary_search(arr, 3);
    return 0;
}