#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(int n1, int n2, int n3, int n4) : matrix{{n1, n2}, {n3, n4}} {}
    void operator >> (int v);
private:
    std::vector<std::vector<int>> matrix;
};

int main(void) {
    int val1, val2, val3, val4;
    std::cin >> val1;
    std::cin >> val2;
    std::cin >> val3;
    std::cin >> val4;
    Matrix m(val1, val2, val3, val4);

    return 0;
}