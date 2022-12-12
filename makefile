main: main.cpp Board.cpp ComputerPlayer.cpp Game.cpp HumanPlayer.cpp Player.cpp RandomPlayer.cpp
	g++ -std=c++17 main.cpp Board.cpp  ComputerPlayer.cpp  Game.cpp HumanPlayer.cpp Player.cpp RandomPlayer.cpp -o main

clean:
	rm *.exe