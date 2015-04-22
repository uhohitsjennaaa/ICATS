#ifndef SETUP_H
#define SETUP_H

#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "constants.h"
using namespace std;

class setup{
	public:
		setup();
		~setup();
		SDL_Renderer* renderer();
		SDL_Window* window();
	private:
		string background();
		void makeFieldSurf();
		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_Surface* surf;
		SDL_Surface* field;
		string imPath;
		string bgPath;
		string imExt;
		string bg;
};

#endif