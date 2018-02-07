Final: main.o Game.o Player.o Room.o RegularRoom.o LightRoom.o TrapRoom.o
	g++ main.o Game.o Player.o Room.o RegularRoom.o LightRoom.o TrapRoom.o -o Final

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.hpp Game.cpp
	g++ -c Game.cpp

Player.o: Player.hpp Player.cpp
	g++ -std=c++11 -c Player.cpp

Room.o: Room.hpp Room.cpp
	g++ -c Room.cpp

RegularRoom.o: RegularRoom.hpp RegularRoom.cpp
	g++ -c RegularRoom.cpp

LightRoom.o: LightRoom.hpp LightRoom.cpp
	g++ -c LightRoom.cpp

TrapRoom.o: TrapRoom.hpp TrapRoom.cpp
	g++ -c TrapRoom.cpp

clean:
	rm *.o
	rm Final
