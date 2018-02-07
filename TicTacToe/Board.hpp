/*********************************************************************
** Author: Kenny Ngo
** Date: 03/08/17
** Description: Board class specification file.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

enum State {X_WON, O_WON, DRAW, UNFINISHED};

class Board
{
	private:
		char board[3][3];
	public:
		Board();
		~Board();
		bool makeMove(int, int, char);
		State gameState();
		void print();
};
#endif