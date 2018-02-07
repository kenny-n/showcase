/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: RegularRoom specification file
*********************************************************************/

#ifndef REGULARROOM_HPP
#define REGULARROOM_HPP

#include "Room.hpp"

class RegularRoom: public Room {

protected:

public:
	RegularRoom();
	void analyze();
	int findTool();
};

#endif
