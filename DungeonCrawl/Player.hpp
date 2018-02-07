/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: Player specification file
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <cstdlib>
#include "Room.hpp"

class Player {

private:
	std::string bag[2];
	bool key;
	bool light;
	int health;

public:
	Room* current;
	Player(Room*);
	~Player();
	int getHealth();
	void loseHealth();
	bool getKey();
	void setKey(bool);
	bool getLight();
	void setLight(bool);
	void setCurrent(Room*);
	bool getWeapon(int);
	void setWeapon(int);
};

#endif
