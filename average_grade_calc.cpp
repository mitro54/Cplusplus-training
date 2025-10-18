#include <iostream>

int main(void) {
    int courses, grade_count;
    std::cout << "Enter number of total courses: ";
    std::cin >> courses;

    for (int i = 0; i < courses; i++) {
        // usage: num of grades followed by num1 num2 num3 ... example: 3 2 2 1
        std::cout << "Enter course #" << i + 1 << " grades: ";
        std::cin >> grade_count;
        int *arr = new int[grade_count];
        for (int i = 0; i < grade_count; i++) {
            std::cin >> arr[i];
        }

        std::cout << "entered: ";
        for (int i = 0; i < grade_count; i++) {
            std::cout << arr[i] << " ";
        }

        delete[] arr;

    }
    return 0;
}