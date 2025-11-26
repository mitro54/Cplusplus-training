#include <iostream>
#include <string>

class Gameboard {
public:
    Gameboard() {};
    void getBoard();
    void setMove(int idx);
    void setTurn() { turn++; }
private:
    int turn = 1;
    std::string board[9] = {"_", "_", "_", "_", "_", "_", "_", "_", "_"};
};

void Gameboard::getBoard() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) std::cout << std::endl;
        std::cout << board[i] << ' ';
    }
}

void Gameboard::setMove(int idx) {
    if (idx > 8 || idx < 0) std::cout << "invalid idx";
    else {
        turn % 2 == 0 ? board[idx] = 'O' : board[idx] = 'X';
        setTurn();
    }
}

int main(void) {
    Gameboard board;
    board.getBoard();
    std::string input;

    while (true) {
        std::cout << std::endl << std::endl;
        std::cin >> input;
        if (!std::cin) break;
        if (input == "q") break;

        try {
            board.setMove(std::stoi(input));
            board.getBoard();
        } catch (...) {
            std::cout << "enter a number 0-8 or q.\n";
        }
    }
    return 0;
}