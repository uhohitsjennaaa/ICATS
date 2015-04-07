//Jenna Wilson, April 6, 2015

//Opens an SDL window; based on lazyfoo tutorial
//to compile: g++ SDLtest.cpp -lSDL2 -o test

#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH=1000;
const int SCREEN_HEIGHT=600;

int main(int argc,char* args[])
{
	SDL_Window* win=NULL;
	
	SDL_Surface* surf=NULL;

	if(SDL_Init(SDL_INIT_VIDEO)<0){ //initialize SDL
		printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
	}else{ //create window
		win=SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if(win==NULL){
			printf("Window could not be created! SDL_Error: %s\n",SDL_GetError());
		}else{
			surf=SDL_GetWindowSurface(win); //get surface
			SDL_FillRect(surf,NULL,SDL_MapRGB(surf->format,255,0,0)); //fill red
			SDL_UpdateWindowSurface(win); //update surface
			SDL_Delay(2000); //delay 2 secs
		}
	}

	SDL_DestroyWindow(win); //close window
	SDL_Quit(); //quit SDL
}