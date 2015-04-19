#include <iostream>
#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
using namespace std;
/*
 * Lesson 0: Test to make sure SDL is setup properly
 */
int main(int, char**){
	//Check if SDL workd
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		cout << "SDL_Init Error: " << SDL_GetError() << endl;
		return 1;
	}
	//create window pointer, error if it doesn't work
	SDL_Window *screen = SDL_CreateWindow("Field Test",100,100,600,400,SDL_WINDOW_SHOWN);
	if (screen == NULL){
		cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}
	
	//Create renderer
	SDL_Surface* surf = NULL;

	int SDL_FillRects(SDL_Surface*    dst,
                  const SDL_Rect* rects,
                  int             count,
                  Uint32          color)

	surf = SDL_GetWindowSurface(screen);

	SDL_FillRect(surf,NULL,SDL_MapRGB(surf->format, 0, 0, 0));

	SDL_UpdateWindowSurface(screen);

	SDL_Delay(5000);	

	SDL_Quit();
	return 0;
}
