#include "ComputerPlayer.h"
#include <string>
char ComputerPlayer::currentPlayerSuffix = 'A';
ComputerPlayer::ComputerPlayer(Piece pc) : Player(std::string("Computer ") + currentPlayerSuffix, pc) {
    ComputerPlayer::currentPlayerSuffix++;
    piece = pc;
}
