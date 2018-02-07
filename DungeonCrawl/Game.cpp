/*********************************************************************
** Author: Kenny Ngo
** Date: 06/13/17
** Description: Game implementation file
*********************************************************************/
#include "Game.hpp"
#include "RegularRoom.hpp"
#include "LightRoom.hpp"
#include "TrapRoom.hpp"


Game::Game()
{
	start = new LightRoom();
	player = new Player(start);
}

Game::~Game()
{
	delete start;
	delete player;
}

void Game::build()
{
	Room* mid = new LightRoom();
	Room* knife = new RegularRoom();
	Room* trap1 = new TrapRoom();
	Room* mini = new RegularRoom();
	Room* trap2 = new TrapRoom();
	Room* gun = new RegularRoom();
	Room* boss = new RegularRoom();
	Room* end = new RegularRoom();
	start->setDoor("north", mid);
	mid->setDoor("west", knife);
	mid->setDoor("north", boss);
	mid->setDoor("east", mini);
	mid->setDoor("south", start);
	knife->setDoor("east", mid);
	knife->setDoor("north", trap1);
	trap1->setDoor("south", knife);
	mini->setDoor("west", mid);
	mini->setDoor("east", gun);
	mini->setDoor("south", trap2);
	gun->setDoor("west", mini);
	trap2->setDoor("west", mini);
	boss->setDoor("south", mid);
	boss->setDoor("north", end);
	end->setDoor("south", boss);
	knife->setTool("Knife");
	gun->setTool("Gun");
	gun->setKey(true);
	mini->setMini(true);
	boss->setBoss(true);
	end->setWin(true);
	mid->setAction(true);
	knife->setAction(true);
	mini->setAction(true);
	gun->setAction(true);
	boss->setAction(true);
}

void Game::play()
{
	while (!player->current->getWin() && player->getHealth() > 0)
	{
		std::cout << "Player's current location is " << player->current->getType() << std::endl;
		player->current->analyze();
		if (!player->current->getAction())
			pickDoor();
		else
		{
			if (player->current->getType() == "RegularRoom")
			{
				player->setWeapon(player->current->findTool());
				if (player->current->getMini() && player->getWeapon(0))
				{
					std::cout << "You cut down the miniboss. He is no more!" << std::endl;
					player->current->setMini(false);
					std::cout << "The miniboss drops a key!" << std::endl;
					player->setKey(true);
					pickDoor();
				}
				else if (player->current->getMini() && !player->getWeapon(0))
				{
					std::cout << "The miniboss punches you back into the previous room." << std::endl;
					std::cout << "You lost a point of health in the process." << std::endl;
					player->loseHealth();
					player->setCurrent(player->current->getWest());
				}
				else if (player->current->getBoss() && player->getWeapon(1))
				{
					std::cout << "You shoot the boss between the eyes." << std::endl;
					player->current->setBoss(false);
					std::cout << "He is no more, go forth/North!" << std::endl;
					pickDoor();
				}
				else if (player->current->getBoss() && !player->getWeapon(1))
				{
					std::cout << "The boss punches you back into the previous room." << std::endl;
					std::cout << "You lost a point of health in the process." << std::endl;
					player->loseHealth();
					player->setCurrent(player->current->getSouth());
				}
			}
			else if (player->current->getType() == "TrapRoom")
			{
				player->loseHealth();
				pickDoor();
			}
			else if (player->current->getType() == "LightRoom")
			{
				if (player->current->getLights())
					player->setLight(true);
				pickDoor();
			}
			else
				pickDoor();
			player->current->setAction(false);
		}
	}
	if (player->getHealth() <= 0)
		std::cout << "Oh man, you died!" << std::endl;
	else
	{
		std::cout << "Congrats, you found a door leading outside." << std::endl;
		std::cout << "You survived the dungeon!" << std::endl;
	}

}

void Game::pickDoor()
{
	if (player->current->getDoorCount() > 1)
	{
		char choice;
		bool valid = false;
		std::cout << "Which door would you like to pick? (N, W, S, or E)" << std::endl;
		std::cin >> choice;

		//valid input check
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		while (!valid)
		{
			switch (choice)
			{
				case 'N':
				{
					if (player->current->getDoor("north"))
					{
						// if (player->current->getNorth()->getBoss() && !player->getKey())
						// {	
						// 	std::cout << "That door is locked. You need a key!";
						// 	std::cin.clear();
						// 	std::cin.ignore(10000, '\n');
						// 	break;
						// }
						// else if (player->current->getNorth()->getBoss() && player->getKey())
						// {	
						// 	std::cout << "You unlocked it with your key!" << std::endl;
						// 	player->setCurrent(player->current->getNorth());
						// 	valid = true;
						// }
						// else
						// {
							player->setCurrent(player->current->getNorth());
							valid = true;
						//}
					}
				}break;

				case 'W':
				{
					if (player->current->getDoor("west"))
					{
						player->setCurrent(player->current->getWest());
						valid = true;
					}
				}break;

				case 'S':
				{
					if (player->current->getDoor("south"))
					{
						player->setCurrent(player->current->getSouth());
						valid = true;
					}
				}break;

				case 'E':
				{
					if (player->current->getDoor("east"))
					{
						player->setCurrent(player->current->getEast());
						valid = true;
					}
				}break;

				default:
				{
					std::cout << "Invalid input, choose again." << "\n";
				}break;
			}
		}
	}
	else
	{
		std::cout << "There is only one door, enter it? (y/n)" << std::endl;
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
					if (player->current->getDoor("north"))
						player->setCurrent(player->current->getNorth());
					else if (player->current->getDoor("west"))
						player->setCurrent(player->current->getWest());
					else if (player->current->getDoor("south"))
						player->setCurrent(player->current->getSouth());
					else
						player->setCurrent(player->current->getEast());
					valid = true;
				}break;

				case 'n':
				{
					std::cout << "You should probably choose y, there's nowhere else to go!" << std::endl;
				}break;

				default:
				{
					std::cout << "Invalid input, choose again." << "\n";
				}break;
			}
			std::cin.clear();
		}
	}
}