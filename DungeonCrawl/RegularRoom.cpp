/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: RegularRoom implementation file
*********************************************************************/
#include "Room.hpp"
#include "RegularRoom.hpp"

RegularRoom::RegularRoom() : Room()
{
	type = "RegularRoom";
	lights = true;
}

void RegularRoom::analyze()
{
	std::cout << "Let's scan the room for anything..." << std::endl;
	if (miniboss)
		std::cout << "Oh no, it's the dungeon's mini boss!" << std::endl;
	if (boss)
		std::cout << "Oh no, it's the dungeon's boss!" << std::endl;
	if (!lights)
		std::cout << "Feeling around the walls, you don't find a light switch." << std::endl;
	else
	{
		if (findTool() == 1)
			std::cout << "You find a knife!" << std::endl;	
		else if (findTool() == 2)
			std::cout << "You find a gun!" << std::endl;	
		else
			std::cout << "You see nothing." << std::endl;
	}
	doors();
}

int RegularRoom::findTool()
{
	if (tool.length() > 0)
	{
		if (tool == "Knife")
			return 1;
		else if (tool == "Gun")
			return 2;
	}
	return 0;
}