#include <iostream>
#include <vector>

#include "tictactoe.h"
#include "node.cpp"

int main()
{
	std::vector<std::vector<char>> field;
	Node* board = new Node(field, 0);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			board->board[i][j] = '-';

	std::cout << "The game starting! ";
	std::cout << "First step is mine" << std::endl;

	while (board->isFull(board->board))
	{
		Move bestMove = findBestMove(board->board);
		board->board[bestMove.row][bestMove.col] = 'x';
		std::cout << "My step is:" << std::endl;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
				std::cout << board->board[i][j] << " ";
			std::cout << std::endl;
		}
		if (winX(board->board)) {
			std::cout << "I win!!!";
			break;
		}

		int row, col;
		std::cout << "Enter your cordinates: row = ";
		std::cin >> row;
		std::cout << ", col = ";
		std::cin >> col;

		while (row > 2 || row < 0 || col < 0 || col > 2 || board->board[row][col] != '-')
		{
			std::cout << "You can choose only : row - 0, 1, 2... \ncol - 0, 1, 2... \nAnd the cell you choose should be empty!\n";
			std::cout << "Enter you cordinates again: row = ";
			std::cin >> row;
			std::cout << ", col = ";
			std::cin >> col;
		}


		board->board[row][col] = 'o';
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
				std::cout << board->board[i][j] << " ";
			std::cout << std::endl;
		}

		if (winO(board->board)) {
			std::cout << "You win (((";
			break;
		}
	}
}
