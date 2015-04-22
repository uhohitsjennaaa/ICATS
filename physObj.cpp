#include "physObj.h"

#include <cmath>

#include "constants.h"
using namespace std;

physObj::physObj(x,y,oH,oW){
	xPos = x;
	yPos = y;
	xVel = 0;
	yVel = 0;
	xAcc = 0.5;
	yAcc = 0.2;
	maxVel = 8;
	maxAcc = 20;
	
	dTime = 1;
	
	objHeight = oH;
	objWidth = oW;
	
	width = S_WIDTH;
	height = S_HEIGHT;
	windMult = TILE_SIZE;
	
	minX = windMult+objWidth;
	maxX = S_WIDTH-minX;
	minY = windMult+objHeight;
	maxY = S_HEIGHT-minY;
}

void physObj()::moveX(){
	xVel += xAccel*dTime;
	if(xVel < -maxVel) xVel = -maxVel;
	else if(xVel > maxVel) xVel = maxVel;
	xPos = xPos+xVel*(dTime)+.5*(xAccel)*(dTime*dTime);
}

void physObj::moveY(){
	yVel += yAccel*dTime;
	if(yVel < -maxVel) yVel = -maxVel;
	else if(yVel > maxVel) yVel = maxVel;
	yPos = yPos + yVel*(dTime)+.5*(yAccel)*(dTime*dTime);
}

void PhysObj()::setPos(float x,float y){
	if(!(x > maxX || x < minX)) xPos = x;
	if(!(y > maxY || y < minY)) yPos = y;
}

void PhysObj()::setVel(float x,float y){
	if(!(x > maxVel || x < -maxVel)) xVel = x;
	if(!(y > maxVel || y < -maxVel)) yVel = y;
}

void PhysObj()::setAcc(float x,float y){
	if(!(x > maxAcc || x < -maxAcc)) xAcc = x;
	if(!(y > maxAcc || y < -maxAcc)) yAcc = y;
}