all: main

main: main.cpp
	g++ main.cpp -lSDL2 -w -o main
	
clean:
	rm *.o main