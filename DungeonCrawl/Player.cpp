/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: Player implementation file
*********************************************************************/
#include "Player.hpp"
#include "RegularRoom.hpp"
#include "LightRoom.hpp"
#include "Room.hpp"


Player::Player(Room* s)
{
	key = false;
	light = false;
	health = 4;
	current = s;
}

Player::~Player()
{

}

int Player::getHealth()
{
	return health;
}

void Player::loseHealth()
{
	health--;
}

bool Player::getKey()
{
	return key;
}

void Player::setKey(bool k)
{
	key = k;
}

bool Player::getLight()
{
	return light;
}

void Player::setLight(bool l)
{
	light = l;
}

void Player::setCurrent(Room* r)
{
	current = r;
}

bool Player::getWeapon(int i)
{
	if (bag[i].length() > 0)
		return true;
	return false;
}

void Player::setWeapon(int i)
{
	if (i == 1)
		bag[0] = "Knife";
	else if (i == 2)
		bag[1] = "Gun";
}