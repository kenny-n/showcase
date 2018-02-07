/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: LightRoom implementation file
*********************************************************************/
#include "Room.hpp"
#include "LightRoom.hpp"

LightRoom::LightRoom() : Room()
{
	lights = false;
	type = "LightRoom";
}

void LightRoom::analyze()
{
	if (!lights)
	{
		std::cout << "Feeling around the walls, you feel a lever, pull it? (y/n)" << std::endl;
		char choice;
		bool valid = false;

		while (!valid)
		{
			std::cin >> choice;

			//valid input check
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}

			switch (choice)
			{
				case 'y':
				{
					lights = true;
					valid = true;
					std::cout << "The lights come on and you can see!" << std::endl;
				}break;

				case 'n':
				{
					std::cout << "You should probably choose 'y', you can't see a thing!" << std::endl;
				}break;

				default:
				{
					std::cout << "Invalid input, choose again." << "\n";
				}break;
			}
			std::cin.clear();
		}
	}
	doors();
}