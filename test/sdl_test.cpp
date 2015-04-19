#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture_ld.h"
#include <iostream>
using namespace std;

const int s_width = 600;
const int s_height = 400;
const int TILE_SIZE = 10;

int main(){
	//initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}

	//Create the window, handle error
	SDL_Window *window = SDL_CreateWindow("Hello World!", 100, 100, s_width, s_height, SDL_WINDOW_SHOWN);
	if (window == NULL){
		cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	//create a renderer and handle error
	SDL_Renderer *ren = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL){
		SDL_DestroyWindow(window);
		cout << "SDL_CreateRenderer Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

	string filename = "tile.bmp";

	SDL_Texture *background = IMG_LoadTexture(ren, filename.c_str());

	//Determine how many tiles we'll need to fill the screen
	int xTiles = s_width / TILE_SIZE;
	int yTiles = s_height / TILE_SIZE;

	//Draw the tiles by calculating their positions
	for (int i = 0; i < xTiles * yTiles; ++i){
		int x = i % xTiles;
		int y = i / xTiles;
		renderTexture(background,ren,x*TILE_SIZE,y*TILE_SIZE,TILE_SIZE,TILE_SIZE);
	}

	SDL_RenderPresent(ren);
	SDL_Delay(5000);
	SDL_DestroyTexture(background);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();

}
