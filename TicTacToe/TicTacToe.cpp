/*********************************************************************
** Author: Kenny Ngo
** Date: 03/01/17
** Description: TicTacToe class function implementation file.
*********************************************************************/

#include <iostream>
#include "TicTacToe.hpp"
#include "Board.hpp"

TicTacToe::TicTacToe(char xOrO) //constructor
{
	currentMove = xOrO;
}

TicTacToe::~TicTacToe() //destructor
{

}

void TicTacToe::play() //returns name of Board
{
	State state = board.gameState();
	while(state == UNFINISHED)
	{
		board.print();
		char x, y;
		std::cout << "Player " << currentMove << ": please enter your move." << std::endl;
		std::cin >> x >> y;
		if (board.makeMove(x, y, currentMove))
		{
			if (currentMove == 'x')
				currentMove = 'o';
			else
				currentMove = 'x';
		}
		else
			std::cout << "That square is already taken." << std::endl;
		state = board.gameState();
	}
	if (state == X_WON)
		std::cout << "X has won!" << std::endl;
	else if (state == O_WON)
		std::cout << "O has won!" << std::endl;
	else
		std::cout << "This ends in a draw." << std::endl;
}

int main()
{
	char xOrO;
	std::cout << "Which player should go first, x or o?" << std::endl;
	std::cin >> xOrO;
	TicTacToe game(xOrO);
	game.play();
	return 0;
}