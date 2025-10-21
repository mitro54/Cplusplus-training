#include <iostream>
#include <iomanip>

int main(void) {
    int courses, grade_count, **arr, loop_count;
    float total = 0;
    std::cout << "Enter number of total courses: ";
    std::cin >> courses;
    arr = new int *[courses];

    for (int i = 0; i < courses; i++) {
        // usage: num of grades followed by num1 num2 num3 ... example: 3 2 2 1
        std::cout << "\nEnter course #" << i + 1 << " grades: ";
        std::cin >> grade_count;
        arr[i] = new int[grade_count];
        int counts[grade_count];
        float loop_total = 0;
        loop_count = 0;
        
        for (int k = 0; k < grade_count; k++)
            counts[k] = grade_count;

        for (int c = 0; c < counts[i]; c++)
            std::cin >> arr[i][c];

        std::cout << "Course " << i + 1 << ": ";
        for (int j = 0; j < counts[i]; j++) {
            loop_total += arr[i][j];
            loop_count += 1;
        }
        total += (loop_total / loop_count);
        std::cout << "final " 
        << std::fixed << std::setprecision(2)
        << loop_total / loop_count
        << ", grades: ";

        for (int j = 0; j < counts[i]; j++) {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << "\nOverall final " << total / courses;

        for (int i = 0; i < courses; i++)
            delete[] arr[i];
        delete[] arr;

    return 0;
}