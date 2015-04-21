//phys_obj.cpp

#include "phys_obj.h"

#include <iostream>
#include <cmath>

#include "field.h"
using namespace std;

PhysObj::PhysObj(){
	xPos = ixPos;
	yPos = iyPos;
	xVel = 0;
	maxxVel = 8;
	yVel = 0;
	maxyVel = 8;
	xAccel = 0.5;
	yAccel = 0.2;
	dTime = 1;
	windMult = 10;
}

int PhysObj::getEdgeLeft(){
	return ceil(xPos/windMult)-1;
}

int PhysObj::getEdgeRight(){
	return ceil((xPos+width)/windMult)-1;
}

int PhysObj::getEdgeTop(){
	return ceil(yPos/windMult)-1;
}

int PhysObj::getEdgeBottom(){
	return ceil((yPos+height)/windMult)-1;
}

int PhysObj::getyCenter(){
	return ceil((yPos+(height/2))/windMult)-1;
}

float PhysObj::getxPos(){
	return xPos;
}

float PhysObj::getyPos(){
	return yPos;
}

float PhysObj::getxVel(){
	return xVel;
}

float PhysObj::getyVel(){
	return yVel;
}

float PhysObj::getxAccel(){
	return xAccel;
}

float PhysObj::getyAccel(){
	return yAccel;
}

