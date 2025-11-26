#include <vector>
#include <iostream>

int main() {
    double x, sum = 0;
    std::cin >> x;
    std::vector<double> v1 = {x, x + 5, x + 0.5, x + 2.3, x + 4.7};
    for (double num : v1)
        sum += num;
    std::cout << "sum: " << sum;
    std::cout << "\navg: " << sum / v1.size();
  
    return 0;
}