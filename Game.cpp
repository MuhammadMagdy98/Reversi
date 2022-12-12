#include "Game.h"
#include "Board.h"
#include <iostream>
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"

Game::Game()
{
    playerOne = nullptr;
    playerTwo = nullptr;
    board.reset();
}

Game::~Game()
{
    delete playerOne;
    delete playerTwo;
}

void Game::selectPlayer() {
    std::cout << "Select the first player Human or Computer, Enter H for human or C for computer\n";
    std::string choice1;
    std::cin >> choice1;
    if (tolower(choice1[0]) == 'c') {

       RandomPlayer *randomPlayer = new RandomPlayer(Piece::DARK);

       playerOne = randomPlayer;
    } else {
       HumanPlayer *humanPlayer;
       std::cout << "Please enter your name:\n";
       std::string name;
       std::cin >> name;
       humanPlayer = new HumanPlayer(name, Piece::DARK);
       playerOne = humanPlayer;
    }


    std::cout << "Select the second player Human or Computer, Enter H for human or C for computer\n";
    std::string choice2;
    std::cin >> choice2;
    if (tolower(choice2[0]) == 'c') {

       RandomPlayer *randomPlayer = new RandomPlayer(Piece::LIGHT);

       playerTwo = randomPlayer;
    } else {
       HumanPlayer *humanPlayer;
       std::cout << "Please enter your name:\n";
       std::string name;
       std::cin >> name;
       humanPlayer = new HumanPlayer(name, Piece::LIGHT);

       playerTwo = humanPlayer;

    }


}
void Game::play() {
        bool turn = true;
        board.reset();
        std::cout << "Notice dark = @, Light = O\n";
        while (isRunning()) {
            board.display();
            board.genMoves();
            if (turn) {

                playerOne->makeMove(board);

            } else {
                 playerTwo->makeMove(board);

            }
            turn = !turn;
        }
        board.display();
        std::cout << "Game is over\n";
        announceWinner();
}

bool Game::isRunning() {
	return board.numMoves() > 0;
}

Player* Game::nextPlayer() const {
    return (playerOneTurn ? playerOne : playerTwo);
}

void Game::announceWinner() {
    switch(board.getWinner()) {
    case Piece::DARK:
        std::cout << playerOne->playerName << " wins\n";
        break;
    case Piece::LIGHT:
        std::cout << playerTwo->playerName << " wins\n";
        break;
    default:
        std::cout << "Tie\n";
    }
}
