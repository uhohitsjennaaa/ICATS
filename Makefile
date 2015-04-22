all: main

player: player.cpp physObj.cpp
	g++ player.cpp physObj.cpp -lSDL2 -o main

ball: ball.cpp physObj.cpp
	g++ ball.cpp physObj.cpp -lSDL2 -o main

setup: setup.cpp playField.cpp
	g++ setup.cpp playField.cpp -lSDL2 -o main

main: main.cpp setup.cpp ball.cpp player.cpp
	g++ main.cpp setup.cpp ball.cpp player.cpp -lSDL2 -o main
	
clean:
	rm *.o main