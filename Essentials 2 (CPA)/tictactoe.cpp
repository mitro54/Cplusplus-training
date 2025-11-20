#include <iostream>
#include <string>

class Gameboard {
public:
    Gameboard() {};
    void getBoard();
    void setMove();
private:
    std::string board[9] = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};
};

void Gameboard::getBoard() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) std::cout << '\n';
        std::cout << board[i] << ' ';
    }
}

int main(void) {
    Gameboard board;
    board.getBoard();
    return 0;
}