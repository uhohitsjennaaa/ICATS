//Jenna Wilson, April 19, 2015

//driver function

#include "setup.h"
#include "ball.h"
#include "player.h"
using namespace std;

int main(){
	SDL_Window* wind;
	SDL_Renderer* rend;
	SDL_Texture* p1Text;
	SDL_Texture* p2Text;
	SDL_Texture* bText;
	SDL_Surface* tmp;
	SDL_Event event; //SDL keypress variable
	
	//instantiate objects
	player p1(1),p2(2);
	ball b();
	
	setup game;
	wind=game.window();
	rend=game.renderer();
	p1Text=SDL_CreateTextureFromSurface(rend,p1.getSurf());
	p2Text=SDL_CreateTextureFromSurface(rend,p2.getSurf());
	bText=SDL_CreateTextureFromSurface(rend,b.getSurf());
	
	int quit = 0;
	
	const Uint8 *keys = SDL_GetKeyboardState(NULL);

	while(!quit)
		while(SDL_PollEvent(&event)){
			//quit if user presses escape
			if(keys[SDL_SCANCODE_ESCAPE]) quit = 1; 
/*			
			//player 1
			if(keys[SDL_SCANCODE_J]) //-xAcc
			if(keys[SDL_SCANCODE_L]) //xAcc++;
			if(keys[SDL_SCANCODE_I]) p1.jump();
			if(keys[SDL_SCANCODE_K]){
				if(keys[SDL_SCANCODE_J]) //toss l
				else if(keys[SDL_SCANCODE_L]) //toss r
			} //end if(keys[SDL_SCANCODE_J])

			//player 2
			if(keys[SDL_SCANCODE_D]) //xVel++;
			if(keys[SDL_SCANCODE_A]) //xVel--;
			if(keys[SDL_SCANCODE_W]) p1.jump();
			if(keys[SDL_SCANCODE_S]){
				if(keys[SDL_SCANCODE_A]) //toss
				else if(keys[SDL_SCANCODE_D]) //toss
			} //end if(keys[SDL_SCANCODE_S])
*/
			SDL_RenderCopy(rend,p1Text,NULL,&p1.update());
			SDL_RenderCopy(rend,p2Text,NULL,&p2.update());
			SDL_RenderCopy(rend,bText,NULL,&b.update());

			SDL_RenderPresent(rend);
		} //end while(SDL_PollEvent(&event))

	SDL_DestroyTexture(p1Text);
	SDL_DestroyTexture(p2Text);
	SDL_DestroyTexture(bText);
	SDL_FreeSurface(tmp);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(wind);
	SDL_Quit(); //quit SDL
}

/*
[jwilso27@student02 FundCompFinal]$ make
g++ main.cpp setup.cpp ball.cpp player.cpp -lSDL2 -o main
main.cpp: In function ‘int main()’:
main.cpp:28:44: error: request for member ‘getSurf’ in ‘b’, which is of non-class type ‘ball()’
  bText=SDL_CreateTextureFromSurface(rend,b.getSurf());
                                            ^
main.cpp:57:47: error: taking address of temporary [-fpermissive]
    SDL_RenderCopy(rend,p1Text,NULL,&p1.update());
                                               ^
main.cpp:58:47: error: taking address of temporary [-fpermissive]
    SDL_RenderCopy(rend,p2Text,NULL,&p2.update());
                                               ^
main.cpp:59:38: error: request for member ‘update’ in ‘b’, which is of non-class type ‘ball()’
    SDL_RenderCopy(rend,bText,NULL,&b.update());
                                      ^
setup.cpp: In member function ‘SDL_Renderer* setup::renderer()’:
setup.cpp:31:87: error: invalid use of non-static member function
  ren=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
                                                                                       ^
setup.cpp: In member function ‘void setup::makeFieldSurf()’:
setup.cpp:81:8: error: request for member ‘setField’ in ‘arena’, which is of non-class type ‘playField()’
  arena.setField();
        ^
setup.cpp:82:18: error: request for member ‘getField’ in ‘arena’, which is of non-class type ‘playField()’
  v2 vField=arena.getField();
                  ^
make: *** [main] Error 1

*/