/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: Room specification file
*********************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>

class Room {

protected:
	std::string tool;
	int doorCount;
	Room* north;
	Room* west;
	Room* south;
	Room* east;
	bool lights;
	bool key;
	std::string type;
	bool miniboss;
	bool boss;
	bool win;
	bool action;


public:
	Room();
	~Room();
	void setDoor(std::string, Room*);
	bool getDoor(std::string);
	Room* getNorth();
	Room* getWest();
	Room* getSouth();
	Room* getEast();
	int getDoorCount();
	std::string getType();
	virtual void analyze() = 0;
	void doors();
	void setKey(bool);
	bool getKey();
	void setTool(std::string);
	std::string getTool();
	void setMini(bool);
	bool getMini();
	void setBoss(bool);
	bool getBoss();
	void setWin(bool);
	bool getWin();
	void setAction(bool);
	bool getAction();
	virtual int findTool();
	virtual bool getLights();
};

#endif
