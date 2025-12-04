#include <iostream>
#include <map>
#include <string>

int main() {
	std::map<std::string, std::string> capitals = { 
		{"China", "Beijing"}, 
		{"India", "New Delhi"}, 
		{"Japan", "Tokyo" },
		{"Philippines", "Manila" },
		{"Poland", "Warsaw" },
		{"Egypt", "Cairo" },
		{"Indonesia", "Jakarta" },
		{"Democratic Republic of the Congo", "Kinshasa" },
		{"South Korea", "Seoul" },
		{"Bangladesh", "Dhaka" },
		{"Iceland", "Reykjavík" }
	};
    std::map<std::string, std::string>::iterator it;
	std::string s;
	getline(std::cin, s);

    it = capitals.find(s);
    if (it != capitals.end()) {
        std::cout << "The capital of the " << it->first << " is " << it->second << '\n';
    } else {
        std::cout << "No such country in the list.";
    }
	return 0;
}