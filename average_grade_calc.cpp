#include <iostream>

int main(void) {
    int courses, grade_count, **arr;
    std::cout << "Enter number of total courses: ";
    std::cin >> courses;
    arr = new int *[courses];

    for (int i = 0; i < courses; i++) {
        // usage: num of grades followed by num1 num2 num3 ... example: 3 2 2 1
        std::cout << "\nEnter course #" << i + 1 << " grades: ";
        std::cin >> grade_count;
        arr[i] = new int[grade_count];
        int counts[grade_count];
        
        for (int k = 0; k < grade_count; k++)
            counts[k] = grade_count;

        for (int c = 0; c < counts[i]; c++)
            std::cin >> arr[i][c];

        std::cout << "entered: ";
        for (int j = 0; j < counts[i]; j++) {
            std::cout << arr[i][j] << " ";
        }
    }
        for (int i = 0; i < courses; i++)
            delete[] arr[i];
        delete[] arr;

    return 0;
}