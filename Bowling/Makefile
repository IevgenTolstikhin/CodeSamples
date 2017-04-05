all: Bowling

Bowling: Utils.o Frame.o Game.o Player.o Lane.o Bowling.o
	g++ Utils.o Frame.o Game.o Player.o Lane.o Bowling.o -o Bowling

Utils.o: Utils.cpp
	g++ -std=c++11 -c Utils.cpp

Frame.o: Frame.cpp
	g++ -std=c++11 -c Frame.cpp

Game.o: Game.cpp
	g++ -std=c++11 -c Game.cpp

Player.o: Player.cpp
	g++ -std=c++11 -c Player.cpp

Lane.o: Lane.cpp
	g++ -std=c++11 -c Lane.cpp

Bowling.o: Bowling.cpp
	g++ -std=c++11 -c Bowling.cpp


clean:
	rm -rf *.o Bowling
