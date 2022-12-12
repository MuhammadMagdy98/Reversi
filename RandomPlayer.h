#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include "ComputerPlayer.h"

class RandomPlayer : public ComputerPlayer
{
    public:
    RandomPlayer(Piece piece);
    Piece piece;
    void makeMove(Board &board);
};

#endif // RANDOMPLAYER_H
