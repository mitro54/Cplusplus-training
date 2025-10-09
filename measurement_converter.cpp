#include <iostream>

int main(void) {
    int msys;
    float m, ft, in;

    std::cout << "Which system are you converting to?\n1 for metric, 2 for imperial: ";
    std::cin >> msys;
    if (msys == 1) {

        // metric
        std::cout << "Enter measurement in 2 parts.. first ft... : ";
        std::cin >> ft;
        std::cout << "... and inches: ";
        std::cin >> in;
        float total_in = (ft * 12) + in; 
        std::cout << "Measurement in meters: " << total_in * .0254 << "m";

    } else if (msys == 2) {
        // imperial
        std::cout << "Enter measurement in meters: ";
        std::cin >> m;
    } else {
        std::cout << "Unrecognized system, select 1 or 2";
    }


    return 0;
}