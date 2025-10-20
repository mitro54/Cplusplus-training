#include <iostream>

int main(void) {
    int courses, grade_count, **arr;
    std::cout << "Enter number of total courses: ";
    std::cin >> courses;

    for (int i = 0; i < courses; i++) {
        // usage: num of grades followed by num1 num2 num3 ... example: 3 2 2 1
        std::cout << "\nEnter course #" << i + 1 << " grades: ";
        std::cin >> grade_count;
        arr = new int *[courses];
        for (int r = 0; r < courses; r++) {
            arr[r] = new int[grade_count];
            for (int c = 0; c < grade_count; c++)
                std::cin >> arr[r][c];
        }

        std::cout << "entered: ";
        for (int i = 0; i < courses; i++) {
            for (int j = 0; j < grade_count; j++) {
                std::cout << arr[i][j] << " ";
            }
        }

        for (int i = 0; i < courses; i++)
            delete[] arr[i];
        delete[] arr;

    }
    return 0;
}