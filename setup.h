#ifndef SETUP_H
#define SETUP_H

#include "playField.h"
#include "player.h"
#include "ball.h"
using namespace std;

class setup{
	public:
		setup(); //constructor
		~setup(); //destructor for clearing SDL objects
		int start(); //create background surface and render textures
		int play(); //record player input and update window
	private:
// 		void makeFieldSurf();
		string background(); //get string of background image name
		void renderer(); //create the SDL renderer
		void window(); //create SDL window
		void goal(); //determine if a goal has been made
		void possession(); //determine player possession
		
		SDL_Window* wind; //window
		SDL_Renderer* rend; //renderer
// 		SDL_Surface* surf;
		SDL_Rect* bRect; //ball rect
		SDL_Rect* p1Rect; //player 1 rect
		SDL_Rect* p2Rect; //player to rect
		
		SDL_Texture* bg; //background texture
		SDL_Texture* p1Text; //player 1 image texture
		SDL_Texture* p2Text; //player 2 image texture
		SDL_Texture* bText; //ball image texture
		SDL_Event event; //SDL keypress variable
		const Uint8 *keys; //record key inputs
		
		//instantiate objects
		player p1; //player 1
		player p2; //player 2
		ball b; //ball
		playField arena; //create field
		v2 vField; //field 2d vector
};

#endif