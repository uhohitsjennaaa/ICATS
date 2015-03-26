#include<iostream>
#include"SDL/SDL.h"
#include "ball.h"
#include "phys_obj.h"
using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL;

int main(){
  int quit = 0;
  
  Ball test();
  
  test.show();
}
