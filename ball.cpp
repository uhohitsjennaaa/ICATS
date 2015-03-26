#include <iostream>
#include "Ball.h"
#include "SDL/SDL.h"
using namespace std;

Ball::Ball():PhysicalObject(){
  radius=5;
  xVel=0;
  yVel=0;
  return;
}

void Ball::handle_input(){
  if(event.type == SDL_KEYDOWN){ //if a key was pressed
    switch(event.key.keysym.sym){
    case SDLK_UP: yVel -= radius/2; break;
    case SDLK_DOWN: yVel += radius/2; break;
    case SDLK_LEFT: xVel -= radius/2; break;
    case SDLK_RIGHT: yVel += radius/2; break;
    }
  }
  else if(event.type == SDL_KEYUP)
  {
    switch(event.key.keysym.sym){
    case SDLK_UP: yVel += radius/2; break;
    case SDLK_DOWN: yVel -= radius/2; break;
    case SDLK_LEFT: xVel += radius/2; break;
    case SDLK_RIGHT: xVel -= radius/2; break;
    }
  }
}

void Ball::show(){
  apply_surface(x,y,dot,screen);
}

void Ball::move(void){
  positionX+=xVel;
  
  if(positionX<0 || positionX+radius>SCREEN_WIDTH)
    positionX-=xVel;
  
  positionY+=yVel;

  if(positionY<0 || positionY+radius>SCREEN_HEIGHT)
    positionY-=yVel;
}
