#ifndef GAME_H
#define GAME_H


#include "Board.h"
#include "Player.h"
#include <iostream>
class Game {
    public:
    Player *playerOne, *playerTwo;
    Board board;
    bool playerOneTurn;

    Game();
    ~Game();
    void selectPlayer();

    Player* nextPlayer() const;

    bool isRunning();

    void play();

    void announceWinner();

};



#endif // GAME_H
