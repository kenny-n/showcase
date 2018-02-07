/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: TrapRoom implementation file
*********************************************************************/
#include "Room.hpp"
#include "TrapRoom.hpp"

TrapRoom::TrapRoom() : Room()
{
	type = "TrapRoom";
	lights = true;
}

void TrapRoom::analyze()
{
	std::cout << "Oh no, this room has a trap, you lost a point of health!" << std::endl;
	doors();
}
