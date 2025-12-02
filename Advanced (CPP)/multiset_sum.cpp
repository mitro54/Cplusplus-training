#include <iostream>
#include <set>

template <class T> void sum(T start, T end, float min, float max) {
    float sum = *start;
    for (; start != end; ++start) {
        if (*start >= min && *start <= max) sum += *start;
    }
    sum += *start;
    std::cout << sum;
}
int main() {
	std::multiset <double> valuesA = { 1.1, 2.3, 2.7, 2.9, 3.5 };
	std::multiset <double> valuesB = { 2.5, 2.7, 3.14, 3.5, 3.5, 4.5 };
	double start_value = 1.1, stop_value = 2.9;
	//std::cin >> start_value;
	//std::cin >> stop_value;
	
    //
    if (start_value < stop_value) {
        if (valuesA.count(start_value) == 0 && valuesA.count(stop_value) == 0
            && valuesB.count(start_value) == 0 && valuesB.count(stop_value) == 0) std::cout << "Not found\nNot found";
        // for whatever reason the task instructions declare a rule that valuesA is the main set to look values from
        else if (valuesA.count(start_value) != 0 || valuesA.count(stop_value) != 0) {
            sum(valuesA.begin(), valuesA.end(), start_value, stop_value);
            std::cout << std::endl;
            sum(valuesB.begin(), valuesB.end(), start_value, stop_value);
        }
        else {
            // ... resulting in only counting total sum range from valuesB
            std::cout << "Not found\n";
            sum(valuesB.begin(), valuesB.end(), start_value, stop_value);
        }
    }
	return 0;
}