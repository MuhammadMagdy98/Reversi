#include "Player.h"
#include "Board.h"
#include <string>

Player::Player(const std::string &name, Piece pc) {
	playerName = name;
	piece = pc;
}

Piece Player::getPiece() const {
	return piece;
}
