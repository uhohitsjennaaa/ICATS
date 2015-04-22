//Jenna Wilson, April 19, 2015

//driver function

#include "setup.h"
using namespace std;

int main(){
	SDL_Window* wind;
	SDL_Renderer* rend; 
	SDL_Event event; //SDL keypress variable
	
	setup game;
	wind=game.window();
	rend=game.renderer();
	
	int quit = 0;
	
	const Uint8 *keys = SDL_GetKeyboardState(NULL);
	float tempX1;
	float tempX2;

	while(!quit)
		while(SDL_PollEvent(&event))
			//quit if user presses escape
			if(/*event.key.keysym.sym == */ keys[SDL_SCANCODE_ESCAPE]) quit = 1;
// 			if(keys[SDL_SCANCODE_D]) P1.moveRight(); //p1 move right
// 			else if(keys[SDL_SCANCODE_A]) P1.moveLeft();
// 						
// 			if(keys[SDL_SCANCODE_J]) P2.moveLeft(); //p2 move left
// 			else if(keys[SDL_SCANCODE_L]) P2.moveRight();

}