#ifndef SETUP_H
#define SETUP_H

#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
using namespace std;

class setup{
	public:
		setup();
		~setup();
	private:
		string background();
		void makeFieldSurf();
		SDL_Window* win;
		SDL_Surface* surf;
		SDL_Surface* field;
		string imPath;
		string bgPath;
		string imExt;
};

#endif