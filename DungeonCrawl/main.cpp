/*********************************************************************
** Author: Kenny Ngo
** Date: 05/14/17
** Description: Game test file, this runs the game.
*********************************************************************/
#include "Game.hpp"
#include "Player.hpp"
#include <stdio.h>
#include <time.h>

const double CLK_TCK = 1000.0;

void gameMenu()
{
	int choice;
	bool quit = false;

	std::cout << "Zegend of Lelda" << "\n";

	while (!quit)
	{
		std::cout << "1 - Play ZoL Game" << "\n";
		std::cout << "2 - Proper playthrough guide" << "\n";
		std::cout << "3 - Quit" << "\n";
		std::cout << "Enter your choice and press return: " << "\n";
		std::cin >> choice;

		//valid input check
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}

		switch (choice)
		{
			case 1:
			{
				Game* ZoL = new Game();
				ZoL->build();
				ZoL->play();
			}break;

			case 2:
			{
				std::cout << "Enter in this order when asked to: " <<std::endl;
				std::cout<< "y, y, y, W, E, E, E, y, W, N, N" << std::endl;
			}break;

			case 3:
			{
				std::cout << "See you again, bye." << std::endl;
				quit = true;
			}break;

			default:
			{
				std::cout << "Invalid input, choose again." << "\n";
			}break;
		}
	}
}

//Testing gameMenu()
int main()
{
	clock_t end_wait;
	end_wait = clock () + 600 * CLK_TCK ; //600 seconds = 10 minutes
	while (clock() < end_wait)
	{
		gameMenu();
	}
	return 0;
}