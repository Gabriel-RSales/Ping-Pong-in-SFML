LIBS=-lsfml-graphics -lsfml-window -lsfml-system
 
all: Ping-pong.exe

Ping-pong.exe: main.o Game.o Player.o Ball.o
	g++ main.o Game.o Player.o Ball.o -o Ping-pong.exe $(LIBS)

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

Ball.o: Ball.cpp Ball.h
	g++ -c Ball.cpp

clean: 
	del *.o *.exe&cls

start:
	cls&start Ping-pong.exe