#include <iostream>
#include <cmath>

int main(void) {
    int msys;
    float m, ft, in;

    std::cout << "Which system are you converting to?\n1 for metric, 2 for imperial: ";
    std::cin >> msys;

    // metric
    if (msys == 1) {
        std::cout << "Enter measurement in 2 parts.. first ft... : ";
        std::cin >> ft;
        std::cout << "... and inches: ";
        std::cin >> in;

        float total_in = (ft * 12) + in;
        std::cout << "Measurement in meters: " << total_in * .0254 << "m";

    // imperial
    } else if (msys == 2) {
        std::cout << "Enter measurement in meters: ";
        std::cin >> m;

        float total_in = m / .0254;
        ft = floor(total_in / 12);
        in = total_in - (ft * 12);

        std::cout << "Measurement in ft and inches: " << ft << "'" << in << "\"";

    } else {
        std::cout << "Unrecognized system, select 1 or 2";
    }


    return 0;
}