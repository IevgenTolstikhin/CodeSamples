CC = g++
CFLAGS  = -std=c++11 -g -Wall -lpthread

all: Bowling

Bowling: Utils.o Frame.o Game.o Player.o Lane.o Bowling.o
	$(CC) Utils.o Frame.o Game.o Player.o Lane.o Bowling.o -o Bowling

Utils.o: Utils.cpp
	$(CC) $(CFLAGS) -c Utils.cpp

Frame.o: Frame.cpp
	$(CC) $(CFLAGS) -c Frame.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

Player.o: Player.cpp
	$(CC) $(CFLAGS) -c Player.cpp

Lane.o: Lane.cpp
	$(CC) $(CFLAGS) -c Lane.cpp

Bowling.o: Bowling.cpp
	$(CC) $(CFLAGS) -c Bowling.cpp

clean:
	rm -rf *.o Bowling
