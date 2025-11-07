#include <iostream>
#include <vector>

void mergesort(std::vector<int>& vals, std::vector<int>& scratch, int start, int end) {
    // if the array contains only one item, it is already sorted, also makes sure start is smaller than end
    if (start >= end) return;
    
    // break the array into left and right halves
    int midpoint = (start + end) / 2;

    // call mergesort to sort the two halves
    mergesort(vals, scratch, start, midpoint);
    mergesort(vals, scratch, midpoint + 1, end);

    // merge the two sorted halves
    int l_idx = start;
    int r_idx = midpoint + 1;
    int scratch_idx = l_idx;
    while ((l_idx <= midpoint) && (r_idx <= end)) {
        if (vals[l_idx] <= vals[r_idx]) {
            scratch[scratch_idx] = vals[l_idx];
            l_idx += 1;
        } else {
            scratch[scratch_idx] = vals[r_idx];
            r_idx += 1;
        }
        scratch_idx += 1;
    }
    
    // finish copying whichever half is not empty
    for (int i = l_idx; i <= midpoint; i++) {
        scratch[scratch_idx] = vals[i];
        scratch_idx += 1;
    }
    for (int i = r_idx; i <= end; i++) {
        scratch[scratch_idx] = vals[i];
        scratch_idx += 1;
    }

    // copy the values back into the original values array
    for (int i = start; i <= end; i++) {
        vals[i] = scratch[i];
    }
}

int main() {
    std::vector<int> vals = {5, 2, 10, 23, 34, 22, 13, 27, 15, 24, 8, 4, 11, 7, 9, 1, 5, 6, 3};
    std::vector<int> scratch(vals.size());

    std::cout << "Before: ";
    for (int v : vals) std::cout << v << ' ';
    std::cout << '\n';

    mergesort(vals, scratch, 0, vals.size() - 1);

    std::cout << "After:  ";
    for (int v : vals) std::cout << v << ' ';
    std::cout << '\n';

    return 0;
}