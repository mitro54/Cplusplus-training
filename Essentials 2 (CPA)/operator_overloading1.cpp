#include <iostream>
#include <vector>

class Matrix {
public:
    int n1, n2, n3, n4;
    friend std::istream& operator >> (std::istream& in, Matrix& m);
};

std::istream& operator >> (std::istream& in, Matrix& m) {
    std::cout << "enter 4 nums: ";
    in >> m.n1 >> m.n2 >> m.n3 >> m.n4;
    return in;
};

int main(void) {
    Matrix m;
    std::cin >> m;

    return 0;
}