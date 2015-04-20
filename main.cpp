//Jenna Wilson, April 19, 2015

//driver function

#include "playField.h"
#include "setup.h"
using namespace std;

int main(){
	setup game;
	
	//SDL keypress variable
	SDL_Event event;

	int quit = 0;
	
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	float tempX1;
	float tempX2;

	while(!quit)
		while(SDL_PollEvent(&event))
			//quit if user presses escape
			if(/*event.key.keysym.sym == */ keys[SDL_SCANCODE_ESCAPE]) quit = 1;
}