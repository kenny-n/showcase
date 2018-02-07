/*********************************************************************
** Author: Kenny Ngo
** Date: 03/01/17
** Description: Board class function implementation file.
*********************************************************************/

#include <iostream>
#include "Board.hpp"

Board::Board() //constructor
{
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '.';
        }
    }
}

Board::~Board() //destructor
{

}

bool Board::makeMove(int x, int y, char player) //returns true if Board spot is unoccupied
{
	if (board[x][y] != '.')
		return false;
	else
	{
		board[x][y] = player;
		return true;
	}
}

State Board::gameState() //returns state of game
{
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
    	if (board[0][0] == 'x')
        	return X_WON;
        else if (board[0][0] == 'o')
        	return O_WON;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
    	if (board[0][2] == 'x')
    		return X_WON;
    	else if (board[0][2] == 'o')
        	return O_WON;
    }
	for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
        	if (board[i][0] == 'x')
            	return X_WON;
            else if (board[i][0] == 'o')
            	return O_WON;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
        	if (board[0][i] == 'x')
            	return X_WON;
            else if (board[0][i] == 'o')
            	return O_WON;
        }
    }
    for (int j = 0; j < 3; j++)
    {
    	for (int k = 0; k < 3; k++)
    	{
    		if (board[j][k] == '.')
    			return UNFINISHED;
    	}
    }
	return DRAW;
}

void Board::print()
{
	std::cout << "  " << "0" << " " << "1" << " " << "2" << std::endl;
    for (int i = 0; i < 3; i++)
    {
    	std::cout << i << " " << board[i][0] << " " << board[i][1] << " " << board[i][2] << std::endl;
    }
}