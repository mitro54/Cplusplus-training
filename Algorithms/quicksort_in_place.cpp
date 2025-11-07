#include <iostream>
#include <vector>

void quicksort(std::vector<int>& arr, int start, int end) {
    // if the list has no more than one element, its sorted
    if (start >= end) return;

    // use the first item as the dividing item
    int divider = arr[start];

    // move items < divider to the front of the array and items >= divider to the end of the arr
    int lo = start, hi = end;
    while (true) {
        // search the array from back to front starting at "hi"
        // to find the last item where value < "divider"
        // move that item into the hole, the hole is now where that item was
        while(arr[hi] >= divider) {
            hi = hi - 1;
            if (hi <= lo) break;
        }
        // if the left and right pieces have met in the middle, == done.
        // put the divider here and break out of the outer while loop
        if (hi <= lo) {
        arr[lo] = divider;
        break;
        }

    // move the value we found to the lower half
    arr[lo] = arr[hi];

    // search the array from front to back starting at "lo"
    // to find the first item where value >= "divider"
    // move that item into the hole, the hole is now where that item was
    lo = lo + 1;
    while (arr[lo] < divider) {
        lo = lo + 1;
        if (lo >= hi) break;
    }
    if (lo >= hi) {
        // The left and right pieces have met in the middle
        // so we're done. Put the divider here, and
        // break out of the outer While loop.
        lo = hi;
        arr[hi] = divider;
        break;
    }
    // move the values we found to the upper half
    arr[hi] = arr[lo];
}
    // recursively sort the two halves
    quicksort(arr, start, lo - 1);
    quicksort(arr, lo + 1, end);
}

// overload to simplify the call
void quicksort(std::vector<int>& a) {
    if (!a.empty())
        quicksort(a, 0, a.size() - 1);
}

int main() {
    std::vector<int> arr{4, 2, 6, 1, 1, 2, 7, 0, 2, 4, 5, 3, 10, 12, 38, 29, 37, 11, 9, 37, 34, 11, 23};
    quicksort(arr);
    for (int num : arr) std::cout << num << ' ';
    std::cout << '\n';
}