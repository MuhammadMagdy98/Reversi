#include "HumanPlayer.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
HumanPlayer::HumanPlayer(const std::string &playerName, Piece piece) : Player(playerName, piece) {

}

void HumanPlayer::makeMove(Board &board) {
    std::cout << playerName << " turn\n";
    std::cout << "enter row and column you want to play\n";
    int row, col;
    std::cin >> row >> col;

    // 0-based
    row--;
    col--;
    Move move = board.getMove(row, col);

    board.makeMove(piece, move);
}
