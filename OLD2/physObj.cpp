/*
This is the member function definition for the class physObj.  Many of these functions are mathematical manipulations to determine movement, including functions to check for bounds and platforms.
*/

#include "physObj.h"

#include <cmath>
using namespace std;

physObj::physObj(){
	//set initial velocities
	xVel = 0;
	yVel = 0;
	xAcc = 0;
	yAcc = .5;
	maxXVel = 8;
	maxYVel = 8;
	dTime = 1;
	
	width = S_WIDTH;
	height = S_HEIGHT;
	windMult = TILE_SIZE;
	thickness = B_THICKNESS;
	border = windMult*thickness;
	
	mins = border-1;
}

physObj::~physObj(){
	SDL_FreeSurface(objSurf);
}

void physObj::setPos(float x,float y){
	if(x <= mins){
		xVel*=bFactor;
		xPos = mins+xVel*(dTime)+.1*(xAcc)*(dTime*dTime);
	}else if(x >= maxX){
		xVel*=bFactor;
		xPos = maxX+xVel*(dTime)+.1*(xAcc)*(dTime*dTime);
	}else xPos=x;

	if(y <= mins){
		yVel*=bFactor;
		yPos = mins+yVel*(dTime)+.1*(yAcc)*(dTime*dTime);
	}else if(y >= maxY){
		yVel*=bFactor;
		yPos = maxY+yVel*(dTime)+.1*(yAcc)*(dTime*dTime);
	}else if(y==yPlat && yVel>0){
		yVel*=bFactor;
		yPos = y+yVel*(dTime)+.1*(yAcc)*(dTime*dTime);
	}else yPos=y;
}

void physObj::setVel(float x,float y){
	if(x < -maxXVel) xVel = -maxXVel;
	else if(x > maxXVel) xVel = maxXVel;
	else xVel = x;

	if(y < -maxYVel) yVel = -maxYVel;
	else if(y > maxYVel) yVel = maxYVel;
	else yVel = y;
}

SDL_Rect* physObj::update(v2* field){
	float tmpX,tmpY,tmpVx,tmpVy;
	yPlat=isOnPlatform(*field);

	tmpVx = xVel+xAcc*dTime;
	tmpVy = yVel+yAcc*dTime;
	
	setVel(tmpVx,tmpVy);
	
	tmpX = xPos+xVel*(dTime)+.1*(xAcc)*(dTime*dTime);
	tmpY = yPos+yVel*(dTime)+.5*(yAcc)*(dTime*dTime);
	
	if(yPlat>0 && yVel>0) setPos(tmpX,yPlat);
	else setPos(tmpX,tmpY);
	
	objRect.x=xPos;
	objRect.y=yPos;

	return &objRect;
}

SDL_Surface* physObj::getSurf(){
	return objSurf;
}

string physObj::getImgFile(){
	return s;
}

float physObj::getV(){
	return xVel;
}

int physObj::distance(float x,float y){
	if(x>xPos-TILE_SIZE && x<xPos+objWidth && y>=yPos-1 && y<yPos+objHeight) return 1;
	return 0;
}

int physObj::isOnPlatform(v2 field){
	int x=floor(xPos/TILE_SIZE);
	int y=floor((yPos+objHeight)/TILE_SIZE);
	for(int i=x;i<=x+1;i++) //check for platform under object		
		if(x>0 && x<S_WIDTH/TILE_SIZE-2 && yVel>=0 && field[y][i]=='#') return TILE_SIZE*floor(yPos/TILE_SIZE);
	return 0;
}
