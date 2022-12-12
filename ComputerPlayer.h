#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "Player.h"

class ComputerPlayer : public Player
{
    public:
        ComputerPlayer(Piece piece);
        static char currentPlayerSuffix;
        virtual void makeMove(Board &board) = 0;
};

#endif // COMPUTERPLAYER_H
