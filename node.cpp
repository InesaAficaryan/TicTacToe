#include <iostream>
#include <vector>
#include <climits>

class Node {
public:
	std::vector<std::vector<char>> board;
	int value;

	Node(std::vector<std::vector<char>> board, int value)
	{
		this->value = value;

		this->board.resize(3, std::vector<char>(3));
		board.resize(3, std::vector<char>(3));
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				this->board[i][j] = board[i][j];
	}


	// This function copied the board in new vector and returned it
	std::vector<std::vector<char>> copied()
	{
		std::vector<std::vector<char>> copied(3, std::vector<char>(3));

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				copied[i][j] = this->board[i][j];
		return copied;
	}


	int getValueOfStep()
	{
		// Checking for rows for X or O victory.
		for (int i = 0; i < 3; ++i)
		{
			if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2])
			{
				if (this->board[i][0] == 'x')
					return +10;
				else if (this->board[i][0] == 'o')
					return -10;
			}
		}

		// Checking for columns for X or O victory.
		for (int i = 0; i < 3; ++i)
		{
			if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i])
			{
				if (this->board[0][i] == 'x')
					return +10;
				else if (this->board[0][i] == 'o')
					return -10;
			}
		}

		// Checking for Diagonals for X or O victory.
		if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2])
		{
			if (this->board[0][0] == 'x')
				return +10;
			else if (this->board[0][0] == 'o')
				return -10;

		}
		if (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0])
		{
			if (this->board[0][2] == 'x')
				return +10;
			else if (this->board[0][2] == 'o')
				return -10;
		}

		// else if none of them have won then return 0.
		return 0;
	}

	// This function returns true if the board is full, and false otherwise
	bool isFull(std::vector<std::vector<char>> board)
	{
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[i][j] == '-')
					return true;
		return false;

	}

	int minimax(int depth, bool isMax)
	{
		std::vector<std::vector<char>> board = copied();
		Node* child = new Node(board, getValueOfStep());

		if (child->value == 10)
			return child->value;
		if (child->value == -10)
			return child->value;

		// if the board is full and 
		// there is no winner then it is draw.
		if (child->isFull(child->board))
			return 0;

		if (isMax)
		{
			int best = INT_MIN;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					// Checking if cell is empty.
					if (child->board[i][j] == '-')
					{
						// Making the move.
						child->board[i][j] = 'x';

						// Calling minimax and choosing max value.
						best = std::max(best, minimax(depth + 1, !isMax));

						// Remvoing the move.
						child->board[i][j] = '-';
					}
				}
			}

			return best;
		}

		// If this minimizer's move
		else
		{
			int best = INT_MAX;
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					// Checking if cell is empy.
					if (child->board[i][j] == '-')
					{
						// Making the move.
						child->board[i][j] = 'o';

						// Calling minimax and choosing the min value.
						best = std::min(best, minimax(depth + 1, !isMax));

						// Removing the move.
						child->board[i][j] = '-';
					}
				}
			}
			return best;
		}
	}
};
