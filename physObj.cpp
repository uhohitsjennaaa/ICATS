#include "physObj.h"
#include <cmath>
using namespace std;

physObj::physObj(){
	//set initial velocities
	xVel = 0;
	yVel = 0;
	xAcc = 1;
	yAcc = .5;
	maxXVel = 8;
	maxYVel = 12;
// 	maxAcc = 5;
	dTime = 1;
	
	width = S_WIDTH;
	height = S_HEIGHT;
	windMult = TILE_SIZE;
	thickness = B_THICKNESS;
	border = windMult*thickness;
	
	mins = border;
}

physObj::~physObj(){
	SDL_FreeSurface(objSurf);
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
}

void physObj::setPos(float x,float y){
	if(x < mins) xPos = mins;
	else if(x > maxX) xPos = maxX;
	else xPos = x;
	
	if(y < mins) yPos = mins;
	else if(y > maxY) yPos = maxY;
	else yPos = y;
}
*/

void physObj::setVel(float x,float y){
	if(x < -maxXVel) xVel = -maxXVel;
	else if(x > maxXVel) xVel = maxXVel;
	else xVel = x;

	if(y < -maxYVel) yVel = -maxYVel;
	else if(y > maxYVel) yVel = maxYVel;
	else yVel = y;
}

/*
void physObj::setAcc(float x,float y){
	if(x < -maxAcc) xAcc = -maxAcc;
	else if(x > maxAcc) xVel = maxAcc;
	else xAcc = x;
	
	if(y < -maxAcc) yAcc = -maxAcc;
	else if(y > maxAcc) yVel = maxAcc;
	else yAcc = y;
}
*/

SDL_Rect* physObj::update(){
	float tmpX,tmpY,tmpVx,tmpVy;
	
	if(xVel==0) xAcc=0;
	else xAcc=.5;
	
	tmpVx = xVel+xAcc*dTime;
	tmpVy = yVel+yAcc*dTime;
	
	setVel(tmpVx,tmpVy);
	
	tmpX = xPos+xVel*(dTime)+.1*(xAcc)*(dTime*dTime);
	tmpY = yPos+yVel*(dTime)+.5*(yAcc)*(dTime*dTime);
	
	setPos(tmpX,tmpY);
	
	objRect.x=xPos;
	objRect.y=yPos;

	return &objRect;
}

SDL_Surface* physObj::getSurf(){
	return objSurf;
}

physObj& physObj::operator+=(int i){
	if(xAcc==0) xVel=i;
	else xVel+=i*xAcc*dTime;
	xPos+=xVel*(dTime)+.1*i*(xAcc)*(dTime*dTime);
	
	return (* this);
}

float physObj::getV(){
	return xVel;
}

int physObj::distance(float x,float y){
	if(sqrt(pow(xPos-x,2)+pow(yPos-y,2))<=TILE_SIZE+5) return 1;
// 	cout << xPos << "_" << x << "_" << xPos-x << "_" << TILE_SIZE+5 << endl;
	return 0;
}

/*
float physObj::getX(){
	return xPos;
}

float physObj::getY(){
	return yPos;
}
*/