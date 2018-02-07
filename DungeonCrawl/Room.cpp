/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: Room implementation file
*********************************************************************/
#include "Room.hpp"

Room::Room()
{
	tool = "";
	doorCount = 0;
	north = NULL;
	west = NULL;
	south = NULL;
	east = NULL;
	lights = false;
	type = "";
	miniboss = false;
	boss = false;
	win = false;
	action = false;
}

Room::~Room()
{

}

void Room::setDoor(std::string direction, Room* nextRoom)
{
	doorCount++;
	if (direction == "north")
		north = nextRoom;
	else if (direction == "west")
		west = nextRoom;
	else if (direction == "south")
		south = nextRoom;
	else
	{
		east = nextRoom;
	}	
}

bool Room::getDoor(std::string direction)
{
	if (direction == "north")
	{
		if (north != NULL)
		{
			
			return true;
		}
	}
	else if (direction == "west")
	{
		if (west != NULL)
		{
			return true;
		}
	}
	else if (direction == "south")
	{
		if (south != NULL)
		{
			return true;
		}
	}
	else
	{
		if (east != NULL)
		{
			return true;
		}
	}
	std::cout << "Invalid door, please try again." << std::endl;
	return false;
}

Room* Room::getNorth()
{
	return north;
}

Room* Room::getWest()
{
	return west;
}

Room* Room::getSouth()
{
	return south;
}

Room* Room::getEast()
{
	return east;
}

int Room::getDoorCount()
{
	return doorCount;
}

std::string Room::getType()
{
	return type;
}

void Room::doors()
{
	if (lights)
	{
		if (doorCount == 1)
			std::cout << "Looking around, you see a single door." << std::endl;
		else
			std::cout << "It looks like there are " << doorCount << " doors." << std::endl;
		if (north != NULL)
			std::cout << "A Northern door, marked with the letter \'N\'." << std::endl;
		if (west != NULL)
			std::cout << "A Western door, marked with the letter \'W\'." << std::endl;
		if (south != NULL)
			std::cout << "A Southern door, marked with the letter \'S\'." << std::endl;
		if (east != NULL)
			std::cout << "An Eastern door, marked with the letter \'E\'." << std::endl;
	}
	else
	{
		if (doorCount == 1)
			std::cout << "Feeling around, you feel a single door." << std::endl;
		else
			std::cout << "Can't see much, maybe there's a light switch somewhere..." << std::endl;
	}

}

void Room::setKey(bool k)
{
	key = k;
}

bool Room::getKey()
{
	return key;
}

void Room::setTool(std::string t)
{
	tool = t;
}

std::string Room::getTool()
{
	return tool;
}

void Room::setMini(bool m)
{
	miniboss = m;
}
bool Room::getMini()
{
	return miniboss;
}

void Room::setBoss(bool b)
{
	boss = b;
}

bool Room::getBoss()
{
	return boss;
}

void Room::setWin(bool w)
{
	win = w;
}

bool Room::getWin()
{
	return win;
}

void Room::setAction(bool a)
{
	action = a;
}

bool Room::getAction()
{
	return action;
}

int Room::findTool()
{
	return 0;
}	

bool Room::getLights()
{
	return lights;
}