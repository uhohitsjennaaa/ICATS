//Jenna Wilson, April 19, 2015

//Opens an SDL window with an image; based on lazyfoo tutorial
//to compile: g++ SDLtest.cpp -lSDL2 -o test

#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int w=600; //set screen width
const int h=400; //set screen height

int main(){
	SDL_Window* win=NULL;
	
	SDL_Surface* surf=NULL;
	SDL_Surface* tmp=NULL;

	if(SDL_Init(SDL_INIT_VIDEO)<0){ //initialize SDL
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}else{ //create window
		win=SDL_CreateWindow("SDL Tutorial",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,w,h,SDL_WINDOW_SHOWN);
		if(win==NULL){
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		}else{
			surf=SDL_GetWindowSurface(win); //get surface
			tmp=SDL_LoadBMP("b1.bmp"); //get picture
			if(tmp==NULL){
				SDL_FillRect(surf,NULL,SDL_MapRGB(surf->format,0,0,0)); //fill black
				cout << "Background could not be loaded! SDL_Error: " << SDL_GetError() << endl;
			}else{
				SDL_BlitSurface(tmp,NULL,surf,NULL);
			}
			SDL_UpdateWindowSurface(win); //update surface
		}
	}
	
	SDL_Delay(5000);
	
    SDL_FreeSurface(surf);  
    SDL_FreeSurface(tmp);  
    SDL_DestroyWindow(win);
	SDL_Quit(); //quit SDL
}