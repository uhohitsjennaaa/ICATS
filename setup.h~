/*
This is the setup class declaration. This class serves as a sort of hub to the rest of the classes by implementing the SDL graphics to display #ICATS and using functions such as goal() and possession() that require information from multiple objects or classes, as opposed to passing variables or reinstantiating objects unnecessarily.
*/

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
		//private helper functions
		void window(); //create SDL window
		void renderer(); //create the SDL renderer
		string background(); //get string of background image name
		int isOnPlatform(SDL_Rect*); //checks if object is on a platform
		int getKeyIn(); //reads user input from keyboard
		void updateAll(); //update all objects
		void goal(); //determine if a goal has been made
		void possession(); //determine player possession
		void rerender(); //render updated textures
		void score(); //displays score on window
		
		SDL_Window* wind; //window
		SDL_Renderer* rend; //renderer

		SDL_Rect* bRect; //ball rect
		SDL_Rect* p1Rect; //player 1 rect
		SDL_Rect* p2Rect; //player 2 rect
		
		SDL_Texture* bg; //background texture
		SDL_Texture* p1Text; //player 1 image texture
		SDL_Texture* p2Text; //player 2 image texture
		SDL_Texture* bText; //ball image texture
		vector<SDL_Texture*> n; //numbers for scoring
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
