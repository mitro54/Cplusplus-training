#include <iostream>
#include <set>
#include <functional>
 
template <class T> void print(T start, T end) {
    for (; start != end; ++start) {
        std::cout << *start << " ";
    }
}
  
int main() {
std::set <double, std::greater<double>> valuesA = { -1.1, 2.9, -2.3, 2.71 };
std::set <double, std::greater<double>> valuesB = { -3.14, 2.71, -3.88, 2.19 };

double value;
std::cin >> value;

if (valuesA.count(value) == 0) std::cout << "Not found";
else {
    print(valuesA.find(value), valuesA.end());
}

std::cout << std::endl;

if (valuesB.count(value) == 0) std::cout << "Not found";
else {
    print(valuesB.find(value), valuesB.end());
}

return 0;
}