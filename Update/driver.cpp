//Driver file for program, includes sdl inner workings, reads keypresses, and displays.
// g++ driver.cpp field.cpp -lSDL2 -lSDL2_image

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>
#include "texture_handler.h"
#include "field.h"
#include "phys_obj.h"
#include "player.h"
#include "ball.h"
#include "constants.h"
#include <iostream>
using namespace std;

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
	string figure1 = "images/littleorangeleftcat.bmp";
	//string figure2 = "images/littlewhiterightcat.bmp";
	//.string figure1 = "images/dude1_small.bmp";
	string figure2 = "images/dude1_small.bmp";
	string ball_img = "images/ball.png";

	//Create texture for background, and goals
	SDL_Texture *bg = IMG_LoadTexture(ren, bg_image.c_str());
	SDL_Texture *field = IMG_LoadTexture(ren, bg_tiles.c_str());
	SDL_Texture *goal1 = IMG_LoadTexture(ren, goal1_tile.c_str());
	SDL_Texture *goal2 = IMG_LoadTexture(ren, goal2_tile.c_str());
	SDL_Texture *player1 = IMG_LoadTexture(ren, figure1.c_str());
	SDL_Texture *player2 = IMG_LoadTexture(ren, figure2.c_str());
	SDL_Texture *ball_tex = IMG_LoadTexture(ren, ball_img.c_str());


	//Initialize playing field
	playField arena;
	
	//create premade arena
	arena.makeField2();

	//Determine how many tiles we'll need to fill the screen
	int xTiles = S_WIDTH / TILE_SIZE;
	int yTiles = S_HEIGHT / TILE_SIZE;

	
	//SDL keypress variable
	SDL_Event event;

	int quit = 0;

	//initial player positions
	int p1_x = 5*TILE_SIZE;
	int p1_y = S_HEIGHT-2*TILE_SIZE-P_HEIGHT;

	int p2_x = S_WIDTH-2*TILE_SIZE;
	int p2_y = S_HEIGHT-2*TILE_SIZE-P_HEIGHT;

	//Instantiate player handlers
	//player P1(p1_x, p1_y, arena);
	player P1(p1_x, p1_y, arena);  
	PhysObj * pP1 = &P1;
	player P2(p2_x, p2_y, arena);
	PhysObj * pP2 = &P2;
	ball ball(200,200,arena);
	PhysObj * pBall = &ball;

	//Instantiate ball handler

	while(!quit){
		//Clear screen
		renderTexture(bg,ren,0,0,S_WIDTH,S_HEIGHT);
		
		//Get keys
		const Uint8 *keys = SDL_GetKeyboardState(NULL);

		//Handle keyboard inputs
		SDL_PollEvent(&event);
		
		//quit if user presses escape
		if(keys[SDL_SCANCODE_ESCAPE]){
			quit = 1;
		}

		//Player 1 controls
		//Right movement (D)
		if(keys[SDL_SCANCODE_D]){
			P1.moveRight();
		//Left movement (A)
		}else if(keys[SDL_SCANCODE_A]){
			P1.moveLeft();
		}
		//Jump (M)
		if(keys[SDL_SCANCODE_W]){
			P1.jump();
		}
		//If left and throw
		if(keys[SDL_SCANCODE_A] && keys[SDL_SCANCODE_S]){
			ball.throwLeft(1);
		}
		//If throw right
		if(keys[SDL_SCANCODE_D] && keys[SDL_SCANCODE_S]){
			ball.throwRight(1);
		}
		//P1 latency, no movement updater. 
		//User basically controls 1/2 frames 
		P1.noMove();


		//Player 1 controls
		//Right movement (J)
		if(keys[SDL_SCANCODE_J]){
			P2.moveLeft();			
		}
		//Left movement (L)
		if(keys[SDL_SCANCODE_L]){
			P2.moveRight();
		}
		//Jump (I)
		if(keys[SDL_SCANCODE_I]){
			P2.jump();
		}
		//If left and throw
		if(keys[SDL_SCANCODE_J] && keys[SDL_SCANCODE_K]){
			ball.throwLeft(2);
		}
		//If throw right
		if(keys[SDL_SCANCODE_L] && keys[SDL_SCANCODE_K]){
			ball.throwRight(2);
		}
		//P2 latency, no movement updater. 
		P2.noMove();

		//Check bounds of players
		/*P1.checkxBounds();
		P2.checkxBounds();
		P1.checkyBounds();
		P2.checkyBounds();*/
		
		//Ball movement
		ball.Update(P1.getxPos(), P1.getyPos(), P2.getxPos(), P2.getyPos());

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
		renderTexture(player1,ren,P1.getxPos(),P1.getyPos(),P_WIDTH,P_HEIGHT);
		renderTexture(player2,ren,P2.getxPos(),P2.getyPos(),P_WIDTH,P_HEIGHT);

		//Draw Ball
		renderTexture(ball_tex,ren,ball.getxPos(),ball.getyPos(),10,10);

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
	


