//phys_obj.h
//A base class for an object that will have be effected by physics

#ifndef PHYS_OBJ_H
#define PHYS_OBJ_H

#include <iostream>
#include <cmath>

#include "field.h"
#include "constants.h"
using namespace std;

class PhysObj{
	public: 
		//Constructor
		PhysObj(float, float, playField &);
		
		//get Functions
		virtual int getEdgeLeft(void);
		virtual int getEdgeRight(void);
		virtual int getEdgeTop(void);
		virtual int getEdgeBottom(void);
		virtual int getyCenter(void);
		
		virtual float getxPos(void);
		virtual float getyPos(void);
		virtual float getxVel(void);
		virtual float getyVel(void);
		virtual float getxAccel(void);
		virtual float getyAccel(void);
		
		virtual void setxPos(float);
		virtual void setyPos(float);
		
		virtual void checkxBounds(float);
		//virtual void gravity(void);
		
	protected:
		playField arena;
		
		float xPos;
		float yPos;
		float xVel;
		float maxxVel;
		float yVel;
		float maxyVel;
		float xAccel;
		float yAccel;
		float dTime;
		
		float width;
		float height;
		float windMult; //window multiplier
};


PhysObj::PhysObj(){
	xPos = 0;
	yPos = 0;
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

void PhysObj::setxPos(float x){
	xPos = x;
}

void PhysObj::setyPos(float y){
	yPos = y;
}

void PhysObj::checkxBounds(float tempX){
	if(arena.vField[getyCenter()][getEdgeRight()] == '#'
	|| arena.vField[getyCenter()][getEdgeLeft()] == '#'
	|| getxPos() > S_WIDTH
	|| getxPos() < 0)
	setxPos(tempX);
}

#endif