#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    std::string filename = "Readme.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File error: couldn't open." << std::endl;
        return 1;
    }

    std::ofstream file_copy("copy.txt");
    if (!file_copy.is_open()) {
        std::cout << "File error: couldn't open." << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 1;
    while (getline(file, line)) {
        file_copy << lineNumber << ":" << line << std::endl;
        lineNumber++;
    }

    file.close();
    file_copy.close();

    std::ifstream file_display("copy.txt");
    if (!file_display.is_open()) {
        std::cout << "File error: couldn't open." << std::endl;
        return 1;
    }

    for (int j = 0; j < 3 && getline(file_display, line); ++j) {
        std::cout << line << std::endl;
    }

    file_display.close();
    return 0;
}
