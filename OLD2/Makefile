CXX = g++
FLAGS = -lSDL2 -lSDL2_image -o

HEADER = constants.h setup.h physObj.h ball.h player.h playField.h
CPP = setup.cpp physObj.cpp ball.cpp player.cpp playField.cpp
MAIN = main.cpp
OUTPUT = main

all: run

run : $(OUTPUT)

$(OUTPUT) : $(MAIN) $(HEADER)
	$(CXX) $(MAIN) $(CPP) $(FLAGS) $(OUTPUT)

clean :
	rm -f *.o