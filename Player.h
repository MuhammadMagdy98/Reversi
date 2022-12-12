#ifndef PLAYER_H
#define PLAYER_H


#include "Board.h"

#include <string>
class Player {
    public:
    std::string playerName;
    Piece piece;
    Player(const std::string &playerName, Piece piece);
    Piece getPiece() const;
    virtual void makeMove(Board &board) = 0;

};


#endif // PLAYER_H
