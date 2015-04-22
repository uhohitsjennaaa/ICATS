#include "physObj.h"
using namespace std;

physObj::physObj(){
	//set initial velocities
	xVel = 0;
	yVel = 0;
	xAcc = 0;
	yAcc = 0.2;
	maxVel = 10;
	maxAcc = 20;
	dTime = 1;
	
	objHeight = 0;
	objWidth = 0;
	n=0;
	
	width = S_WIDTH;
	height = S_HEIGHT;
	windMult = TILE_SIZE;
	
	minX = windMult+objWidth;
	maxX = S_WIDTH-minX;
	minY = windMult+objHeight;
	maxY = S_HEIGHT-minY;
	
	objSurf=NULL;
	objRect.w = objWidth;
	objRect.h = objHeight;
}

physObj::~physObj(){
		SDL_FreeSurface(pSurf);
}

/*void physObj()::move(){
	xVel += xAcc*dTime;
	if(xVel < -maxVel) xVel = -maxVel;
	else if(xVel > maxVel) xVel = maxVel;
	xPos = xPos+xVel*(dTime)+.1*(xAcc)*(dTime*dTime);

	yVel += yAcc*dTime;
	if(yVel < -maxVel) yVel = -maxVel;
	else if(yVel > maxVel) yVel = maxVel;
	yPos = yPos + yVel*(dTime)+.1*(yAcc)*(dTime*dTime);
}*/

void physObj()::setPos(float x,float y){
	if(x < minX) xPos = minX;
	else if(x > maxX) xPos = maxX;
	else xPos = x;
	
	if(y < minY) yPos = minY;
	else if(y > maxY) yPos = maxY;
	else yPos = y;
}

void physObj()::setVel(float x,float y){
	if(x < -maxVel) xVel = -maxVel;
	else if(x > maxVel) xVel = maxVel;
	else xVel = x;
	
	if(y < -maxVel) yVel = -maxVel;
	else if(y > maxVel) yVel = maxVel;
	else xVel = y;
}

void physObj()::setAcc(float x,float y){
	if(x < -maxAcc) xAcc = -maxAcc;
	else if(x > maxAcc) xVel = maxAcc;
	else xAcc = x;
	
	if(y < -maxAcc) yAcc = -maxAcc;
	else if(y > maxAcc) yVel = maxAcc;
	else yAcc = y;
}

SDL_Rect physObj()::update(){
	float tmpX,tmpY,tmpVx,tmpVy,tmpAx,tmpAy;
	
	tmpVx = xVel+xAcc*dTime;
	tmpVy = yVel+yAcc*dTime;
	
	setVel(tmpVx,tmpVy);
	
	tmpX = xPos+xVel*(dTime)+.1*(xAcc)*(dTime*dTime);
	tmpY = yPos + yVel*(dTime)+.1*(yAcc)*(dTime*dTime);
	
	setPos(tmpX,tmpY);
	
	objRect.x=xPos;
	objRect.y=yPos;
	
	return objRect;
}

SDL_Surface *physObj()::getSurf(){
	return objSurf;
}