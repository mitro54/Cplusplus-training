#include <iostream>
// move the top n disks from peg from_peg to peg to_peg
// using other_peg to hold disks temporarily as needed

void tower_of_hanoi(char from_peg, char to_peg, char other_peg, int n) {
    // recursively move the top n - 1 disks from from_peg to other_peg
    if (n > 1) tower_of_hanoi(from_peg, other_peg, to_peg, n - 1);
    // move the last disk from from_peg to to_peg
    std::cout << "Move disk " << n << " from " << from_peg
              << " to " << to_peg << std::endl;

    // recursively move the top n - 1 disks back from other_peg to to_peg
    if (n > 1)
        tower_of_hanoi(other_peg, to_peg, from_peg, n - 1);
}

int main() {
    int n = 3;
    tower_of_hanoi('A', 'C', 'B', n);
    return 0;
}