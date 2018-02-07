/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: LightRoom specification file
*********************************************************************/

#ifndef LIGHTROOM_HPP
#define LIGHTROOM_HPP

#include "Room.hpp"

class LightRoom: public Room {

protected:

public:
	LightRoom();
	void analyze();
};

#endif