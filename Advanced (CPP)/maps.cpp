#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {
    std::map<std::string, int> variables_map = { {"x", 0}, {"y", 1}, {"z", 2}, { "xx", 3 },{ "xy", 4 },{ "xz", 5 } };
	std::vector<int> values = { 9, 6, 5, 7, 3, 2};
	std::string variable_name;
	std::cin >> variable_name;

    int tmp_addr = -1;
	for (const auto& [key, addr] : variables_map) {
        std::cout << "Variable: " << key << " at address: " << addr << " has value: "<< values[addr] << '\n';
        if (variable_name == key) {
            tmp_addr = addr;
        }
    }
    if (tmp_addr != -1) std::cout << "\nVariable: " << variable_name 
                             << " at address: " << tmp_addr 
                             << " has value: "<< values[tmp_addr] << '\n';

    else std::cout << "\nVariable: " << variable_name << " doesn't exist.";

	return 0;
}