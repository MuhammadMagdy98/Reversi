#include "Board.h"

#include <iostream>
#include <vector>



Board::Board() {
    reset();
}
void Board::reset() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = Piece::EMPTY;
    }
    board[27] = Piece::DARK;
    board[28] = Piece::LIGHT;
    board[35] = Piece::LIGHT;
    board[36] = Piece::DARK;
}

void Board::display() {
    std::cout << "    ";
    for (int i = 1; i <= 8; i++)
        std::cout << i << "    ";
    std::cout << std::endl;
    for (int i = 0; i < BOARD_SIZE; i++) {

        if (i % 8 == 0) {
            std::cout << std::endl;
            std::cout << i / 8 + 1 << "   ";
        }
        Piece piece = board[i];
        switch(piece) {
            case Piece::EMPTY:
                std::cout << "X    ";
                break;
            case Piece::DARK:
                std::cout << "@    ";
                break;
            case Piece::LIGHT:
                std::cout << "O    ";
                break;
            default:
                break;
        }
    }
    std::cout << std::endl;
}

Move Board::getMove(int row, int col) const {
    // convert 2d index to 1d index, [8 is the width of the board]

    return row * 8 + col;
}

int Board::numMoves() {
    int num_of_moves = 0;
    darkMoves.clear();
    lightMoves.clear();
    for (int i = 0; i < BOARD_SIZE; i++) {
        Cell current = getCoordinates(i);
        if (isLegal(Piece::DARK, i)) {
            darkMoves.push_back(current);
            num_of_moves++;
        }
        if (isLegal(Piece::LIGHT, i)) {
            lightMoves.push_back(current);
            num_of_moves++;
        }
    }

    return num_of_moves;

}

Piece Board::getPlayer() const {
    return (black_turn ? Piece::DARK : Piece::LIGHT);
}

Piece Board::getWinner() const {
    int countDark = 0, countLight = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        switch(board[i]) {
        case Piece::DARK:
            countDark++;
            break;
        case Piece::LIGHT:
            countLight++;
            break;
        default:
            break;
        }
    }
    if (countDark > countLight) {
        return Piece::DARK;
    }
    if (countLight > countDark) {
        return Piece::LIGHT;
    }
    // tie
    return Piece::EMPTY;

}

bool Board::isLegal(Piece piece, Move move) {
    // moves should be inside board and in empty cells
    if (move < 0 || move >= BOARD_SIZE || board[move] != Piece::EMPTY)
        return false;

    Cell currentPosition = getCoordinates(move);
    for (int deltaRow = -1; deltaRow < 2; deltaRow++) {
        for (int deltaCol = -1; deltaCol < 2; deltaCol++) {
            if (deltaRow == 0 && deltaCol == 0) continue;
            std::vector<int> cells = {getMove(currentPosition.x, currentPosition.y)};
            int currentRow = currentPosition.x + deltaRow;
            int currentCol = currentPosition.y + deltaCol;

            bool atLeastOneOpposite = false;
            while (currentRow >= 0 && currentCol < 8 && currentCol >= 0 && currentCol < 8
                   && board[getMove(currentRow, currentCol)] == getOppositeColor(piece)) {
                cells.push_back(getMove(currentRow, currentCol));
                currentRow += deltaRow;
                currentCol += deltaCol;
                atLeastOneOpposite = true;

            }

            if (currentRow >= 0 && currentRow < 8 && currentCol >= 0 && currentCol < 8
                && board[getMove(currentRow, currentCol)] == piece && atLeastOneOpposite) {
                 // now move is valid, update the board

                updateCells = cells;
                return true;
            }
        }
    }
    return false;
}

void Board::makeMove(Piece piece, Move move) {

    if (isLegal(piece, move)) {
        for (auto x : updateCells) {
            board[x] = piece;
        }
    }
}

void Board::genMoves() {
    std::cout << "possible dark moves ";
    for (int i = 0; i < darkMoves.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << darkMoves[i].x + 1 << " " << darkMoves[i].y + 1;
    }
    std::cout << "\npossible light moves ";
    for (int i = 0; i < lightMoves.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << lightMoves[i].x + 1 << " " << lightMoves[i].y + 1;
    }
    std::cout << "\n";
}

Cell Board::getCoordinates(int index) const {
    return {index / 8, index % 8};
}

Piece Board::getOppositeColor(Piece piece) const {
    Piece pc;
    switch(piece) {
    case Piece::LIGHT:
        pc = Piece::DARK;
        break;
    case Piece::DARK:
        pc =  Piece::LIGHT;
        break;
    default:
        pc = Piece::BORDER;
    }
    return pc;
}




