all: main

main: main.cpp
	g++ main.cpp -lSDL2 -o main
	
clean:
	rm *.o main