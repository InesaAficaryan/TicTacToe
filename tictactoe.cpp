#include <iostream>
#include <vector>

#include "tictactoe.h"
#include "node.cpp"

Move findBestMove(std::vector<std::vector<char>> field)
{
	Node* board = new Node(field, INT_MIN);
	int bestValue = INT_MIN;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			// Checking if cell is empty.
			if (board->board[i][j] == '-')
			{
				// Making the move.
				board->board[i][j] = 'x';
				int moveValue = board->minimax(0, false);

				//Removing the move.
				board->board[i][j] = '-';

				// If the value of the current move is
				// more than the best value, then update it.
				if (moveValue > bestValue)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestValue = moveValue;
				}

			}
		}
	}
	return bestMove;
}

bool winX(std::vector<std::vector<char>> board)
{
	// Checking for rows for x victory.
	for (int i = 0; i < 3; ++i)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'x')
			return true;

	// Checking for columns for x victory.
	for (int i = 0; i < 3; ++i)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'x')
			return true;

	// Checking for Diagonals for x victory.
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'x')
		return true;

	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'x')
		return true;
	return false;
}

bool winO(std::vector<std::vector<char>> board)
{
	// Checking for rows for o victory.
	for (int i = 0; i < 3; ++i)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'o')
			return true;

	// Checking for columns for o victory.
	for (int i = 0; i < 3; ++i)
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'o')
			return true;

	// Checking for Diagonals for o victory.
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'o')
		return true;

	else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'o')
		return true;
	return false;
}


