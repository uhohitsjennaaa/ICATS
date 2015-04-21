//Jenna Wilson, April 19, 2015

//driver function

#include "setup.h"
using namespace std;

int main(){
	SDL_Window* wind; 
	SDL_Event event; //SDL keypress variable
	
	setup game;
	wind=game.window();
	
	int quit = 0;
	
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	float tempX1;
	float tempX2;

	while(!quit)
		while(SDL_PollEvent(&event))
			//quit if user presses escape
			if(/*event.key.keysym.sym == */ keys[SDL_SCANCODE_ESCAPE]) quit = 1;
}