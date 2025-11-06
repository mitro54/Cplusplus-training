#include <iostream>
#include <vector>

int findMinimum(const std::vector<int>& array) {
    int min = array[0];
    for (int i = 0; i < array.size(); i++)
        if (array[i] < min) min = array[i];
    return min;
};

int findMaximum(const std::vector<int>& array) {
    int max = array[0];
    for (int i = 0; i < array.size(); i++)
        if (array[i] > max) max = array[i];
    return max;
};

int findAverage(const std::vector<int>& array) {
    int total = 0;
    for (int i = 0; i < array.size(); i++)
        total += array[i];
    return total / array.size();
};

// only works if no duplicates
int findMedian(const std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        int num_smaller = 0;
        int num_larger = 0;
        for (int j = 0; j < array.size(); j++) {
            if (array[j] < array[i]) num_smaller += 1;
            if (array[j] > array[i]) num_larger += 1;
        }
        if (num_smaller == num_larger) return array[i];
    }
};

// testing setup
int main(void) {
std::vector<int> arr = {2, 3, 4, 5, 6};
std::cout << "min: " << findMinimum(arr) << "\n";
std::cout << "max: " << findMaximum(arr) << "\n";
std::cout << "avg: " << findAverage(arr) << "\n";
// only works if no duplicates
std::cout << "median: " << findMedian(arr) << "\n";
    return 0;
}