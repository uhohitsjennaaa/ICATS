all: main

main: main.cpp playField.cpp setup.cpp
	g++ main.cpp playField.cpp setup.cpp -lSDL2 -o main
	
clean:
	rm *.o main