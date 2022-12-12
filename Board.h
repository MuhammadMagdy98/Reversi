#ifndef BOARD_H
#define BOARD_H
#include <vector>


enum class Piece {LIGHT = 1, DARK = 0, EMPTY = -1, BORDER = 2};

class Cell {
public:
    int x, y;
};

typedef int Move;

class Board {
    public:
    static const int BOARD_SIZE = 64;
    Piece board[BOARD_SIZE];
    std::vector<Cell> darkMoves;
    std::vector<Cell> lightMoves;
    std::vector<int> updateCells;
    bool black_turn;
    Board();

    void reset();
    void display();
    void makeMove(Piece piece, Move mv);

    bool isLegal(Piece piece, Move mv);
    Piece getWinner() const;

    Piece getPlayer() const;

    void genMoves();

    int numMoves();

    Move getMove(int, int) const;

    Cell getCoordinates(int) const;

    Piece getOppositeColor(Piece piece) const;

};

#endif // BOARD_H
