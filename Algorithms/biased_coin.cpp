#include <iostream>
#include <cstdlib>
#include <ctime>

// Flip the biased coin
// If the result is {Heads, Tails}, return Heads.
// If the result is {Tails, Heads}, return Tails.
// If the result is something else, start over.

// Simulated biased coin
// Returns 1 for Heads, 0 for Tails
int biased_coin() {
    // Example bias: 70% Heads
    return (std::rand() % 10) < 7 ? 1 : 0;
}

// If there's a biased coin, this algorithm will produce a fair coin flip
int fair_roll() {
    while (true) {
        int flip1 = biased_coin();
        int flip2 = biased_coin();

        // Heads = 1, Tails = 0
        if (flip1 == 1 && flip2 == 0) return 1; // HT → Heads
        if (flip1 == 0 && flip2 == 1) return 0; // TH → Tails

        // Otherwise (HH or TT), repeat
    }
}

int main() {
    std::srand(std::time(nullptr));

    // Test: run fair_roll many times
    int heads = 0, tails = 0;
    for (int i = 0; i < 10000; i++) {
        if (fair_roll() == 1)
            heads++;
        else
            tails++;
    }

    std::cout << "Heads: " << heads << "\n";
    std::cout << "Tails: " << tails << "\n";

    return 0;
}
