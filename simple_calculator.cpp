#include <iostream>

double calculator(int choice, double num1, double num2) {
    if (num2 == 0 && choice == 4) {
        return 0;
    }

    switch (choice) {
        case 1: return num1 + num2;
        case 2: return num1 - num2;
        case 3: return num1 * num2;
        case 4: return num1 / num2;
    }
}

int main(void) {
    double num1, num2;
    int choice;
    std::cout << "MENU:\n";
    std::cout << "0 - exit\n";
    std::cout << "1 - addition\n";
    std::cout << "2 - subtraction\n";
    std::cout << "3 - multiplication\n";
    std::cout << "4 - division\n";

    while (true) {
        std::cout <<  "\nChoose action: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
            std::cout << "Provide a number for addition: ";
            std::cin >> num1;
            std::cout << "Provide another number for addition: ";
            std::cin >> num2;
            std::cout << "Result is: " << calculator(choice, num1, num2) << "\n";
            break;

            case 2:
            std::cout << "Provide two numbers for subtraction: ";
            std::cin >> num1;
            std::cout << "Provide another number for subtraction: ";
            std::cin >> num2;
            std::cout << "Result is: " << calculator(choice, num1, num2) << "\n";
            break;

            case 3:
            std::cout << "Provide two numbers for multiplication: ";
            std::cin >> num1;
            std::cout << "Provide another number for multiplication: ";
            std::cin >> num2;
            std::cout << "Result is: " << calculator(choice, num1, num2) << "\n";
            break;

            case 4: 
            std::cout << "Provide two numbers for division: ";
            std::cin >> num1;
            std::cout << "Provide another number for division: ";
            std::cin >> num2;
            std::cout << "Result is: " << calculator(choice, num1, num2) << "\n";
            break;
        }
        if (choice == 0) break;
    }
    return 0;
}