/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: Game specification file
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "Room.hpp"
#include "Player.hpp"

class Game {

private:
	Room* start;
	Player* player;

public:
	Game();
	~Game();
	void build();
	void play();
	void pickDoor();
};

#endif
