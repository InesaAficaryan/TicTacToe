#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

#include <iostream>
#include <vector>

struct Move {
	int row;
	int col;
};

// This function returns the best possible move for the player
Move findBestMove(std::vector<std::vector<char>> field);

// This function returns true when computer win otherwise false.
bool winX(std::vector<std::vector<char>> board);

// This function returns true if O wins and false otherwise.
bool winO(std::vector<std::vector<char>> board);

#endif
