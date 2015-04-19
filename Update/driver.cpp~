//Driver file for program, includes sdl inner workings, reads keypresses, and displays.


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include "texture_handler.h"
#include "field.h"
#include "player.h"
#include <iostream>
using namespace std;

//Size of window and background pieces
const int S_WIDTH = 600;
const int S_HEIGHT = 400;
const int TILE_SIZE = 10;
const int P_WIDTH = 15;
const int P_HEIGHT = 30;

int main(){
	//initialize SDL	
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}

	//Create the window, handle error
	SDL_Window *window = SDL_CreateWindow("Hello World!", 100, 100, S_WIDTH, S_HEIGHT, SDL_WINDOW_SHOWN);
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

	//get image resources
	string bg_image = "images/bg.bmp";
	string bg_tiles = "images/tile.bmp";
	string goal1_tile = "images/goal1.bmp";
	string goal2_tile = "images/goal2.bmp";
	string figure1 = "images/dude1_small.bmp";
	string figure2 = "images/dude2_small.bmp";

	//Create texture for background, and goals
	SDL_Texture *bg = IMG_LoadTexture(ren, bg_image.c_str());
	SDL_Texture *field = IMG_LoadTexture(ren, bg_tiles.c_str());
	SDL_Texture *goal1 = IMG_LoadTexture(ren, goal1_tile.c_str());
	SDL_Texture *goal2 = IMG_LoadTexture(ren, goal2_tile.c_str());
	SDL_Texture *player1 = IMG_LoadTexture(ren, figure1.c_str());
	SDL_Texture *player2 = IMG_LoadTexture(ren, figure2.c_str());


	//Initialize playing field
	playField arena;
	
	//create premade arena
	arena.makeField1();

	//Create pixel field arena
	arena.pixels();
		
	//Determine how many tiles we'll need to fill the screen
	int xTiles = S_WIDTH / TILE_SIZE;
	int yTiles = S_HEIGHT / TILE_SIZE;

	
	//SDL keypress variable
	SDL_Event event;

	int quit = 0;

	//initial player positions
	int p1_x = 2*TILE_SIZE;
	int p1_y = S_HEIGHT-2*TILE_SIZE-P_HEIGHT;

	int p2_x = S_WIDTH-2*TILE_SIZE;
	int p2_y = S_HEIGHT-2*TILE_SIZE-P_HEIGHT;

	//Instantiate player handlers
	player P1(p1_x, p1_y);
	player P2(p2_x, p2_y);
	
	const Uint8 *keys = SDL_GetKeyboardState(NULL);

	while(!quit){
		//Clear screen
		renderTexture(bg,ren,0,0,S_WIDTH,S_HEIGHT);

		//Handle keyboard inputs
		while(SDL_PollEvent(&event)){
			//quit if user presses escape
			if(/*event.key.keysym.sym == */ keys[SDL_SCANCODE_ESCAPE]){
				quit = 1;
			}
			//p1 move right
			if(keys[SDL_SCANCODE_D]){
				P1.moveRight();
			}else if(keys[SDL_SCANCODE_A]){
				P1.moveLeft();
			}

			//p2 move left
			if(keys[SDL_SCANCODE_J]){
				P2.moveLeft();			
			}else if(keys[SDL_SCANCODE_L]){
				P2.moveRight();
			}
		}	
		//When players don't move 
		P1.noMove();
		P2.noMove();

		//Draw the tiles by using the vector fields
		for (int iRow = 0; iRow < S_HEIGHT / 10; iRow++){
			for(int iCol = 0; iCol < S_WIDTH / 10; iCol++){
				if(arena.vField[iRow][iCol] == '#'){
					renderTexture(field,ren,iCol*TILE_SIZE,iRow*TILE_SIZE,TILE_SIZE,TILE_SIZE);
				}else if(arena.vField[iRow][iCol] == '$'){
					renderTexture(goal1,ren,iCol*TILE_SIZE,iRow*TILE_SIZE,TILE_SIZE,TILE_SIZE);
				}else if(arena.vField[iRow][iCol] == '%'){
					renderTexture(goal2,ren,iCol*TILE_SIZE,iRow*TILE_SIZE,TILE_SIZE,TILE_SIZE);
				}
			}
		}
		//Draw players
		renderTexture(player1,ren,P1.getxPos(),p1_y,P_WIDTH,P_HEIGHT);
		renderTexture(player2,ren,P2.getxPos(),p2_y,P_WIDTH,P_HEIGHT);

		//Finish up
		SDL_RenderPresent(ren);
	}

	SDL_DestroyTexture(field);
	SDL_DestroyTexture(goal1);
	SDL_DestroyTexture(goal2);
	SDL_DestroyTexture(player1);
	SDL_DestroyTexture(player2);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
	


