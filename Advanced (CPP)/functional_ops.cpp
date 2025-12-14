#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
#include <numeric>

template <class T>
void print(T start, T end) {
    for (; start != end; ++start) {
        std::cout << *start << " ";
    }
}

void print_student_data(const std::vector<double>& studentGrades, const std::vector<double>& weighted) {
    print(studentGrades.begin(), studentGrades.end());
    std::cout << std::endl;
    print(weighted.begin(), weighted.end());
    std::cout << std::endl;
    double sum = std::accumulate(weighted.begin(), weighted.end(), 0.0);
    std::cout << "Sum of weighted: " << sum << std::endl;
    std::cout << "Average: " << sum / weighted.size() << std::endl;
}

int main() {
    std::vector<double> student1Grades = { 3, 4, 5, 4, 4.5, 5, 3.5, 4 };
    std::vector<double> student2Grades = { 5, 4.5, 5, 4.5, 3, 3, 3.5, 5 };
    std::vector<double> gradesWeights = { 0.05, 0.15, 0.1, 0.2, 0.05, 0.3, 0.1, 0.05 };
    std::vector<double> weighted1(8);
    std::vector<double> weighted2(8);

    transform(student1Grades.begin(), student1Grades.end(), gradesWeights.begin(), weighted1.begin(), std::multiplies<double>());
    transform(student2Grades.begin(), student2Grades.end(), gradesWeights.begin(), weighted2.begin(), std::multiplies<double>());

    std::cout << "Student 1:" << std::endl;
    print_student_data(student1Grades, weighted1);
    std::cout << std::endl;

    std::cout << "Student 2:" << std::endl;
    print_student_data(student2Grades, weighted2);
    std::cout << std::endl;

    return 0;
}
