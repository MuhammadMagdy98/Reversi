#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "Player.h"
#include "Board.h"
#include <string>
class HumanPlayer : public Player {
   public:
       HumanPlayer(const std::string &playerName, Piece piece);
       void makeMove(Board &board);
};

#endif // HUMANPLAYER_H
