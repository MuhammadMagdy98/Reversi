#include "RandomPlayer.h"
#include "Board.h"
#include <random>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

RandomPlayer::RandomPlayer(Piece pc) : ComputerPlayer(pc) {
    piece = pc;
}
void RandomPlayer::makeMove(Board &board) {
    std::cout << playerName << " turn\n";
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    Move move;
    int randomIndex = 0;

    if (piece == Piece::DARK) {
        if (board.darkMoves.size() == 0) return;
        uniform_int_distribution<int> dis(0, (int) board.darkMoves.size() - 1);
        randomIndex = dis(rng);
        Cell twoDimensionMove = board.darkMoves[randomIndex];

        move = board.getMove(twoDimensionMove.x, twoDimensionMove.y);
    } else {
        if (board.lightMoves.size() == 0) return;
        uniform_int_distribution<int> dis(0, (int) board.lightMoves.size() - 1);
        randomIndex = dis(rng);
        Cell twoDimensionMove = board.lightMoves[randomIndex];
        move = board.getMove(twoDimensionMove.x, twoDimensionMove.y);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    board.makeMove(piece, move);
}
