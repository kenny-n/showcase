/*********************************************************************
** Author: Kenny Ngo
** Date: 03/08/17
** Description: TicTacToe class specification file.
*********************************************************************/

#include "Board.hpp"
#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

class TicTacToe
{
	private:
		Board board;
		char currentMove;
	public:
		TicTacToe(char);
		~TicTacToe();
		void play();
};
#endif