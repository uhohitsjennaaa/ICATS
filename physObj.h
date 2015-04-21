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
		PhysObj(); //Constructor
		
		void move(); //moves left and right
		void noMove(); //Handle no input keys
		void jump();
		
		//get Functions
		void setPos(float,float);
		void setVel(float,float);
		void setAcc(float,float);
/*		
		void setxVel(float);
		void setyVel(float);
		void setxAccel(float);
		void setyAccel(float);
		
		virtual int getEdgeLeft(void);
		virtual int getEdgeRight(void);
		virtual int getEdgeTop(void);
		virtual int getEdgeBottom(void);
		virtual int getyCenter(void);
		
		virtual void checkxBounds(float);
		virtual void gravity(void);
*/	
	protected:
// 		playField arena;
		float xPos;
		float yPos;
		float xVel;
		float yVel;
		float xAcc;
		float yAcc;
		float dTime;
	
	private:
		int width;
		int height;
		int windMult; //window multiplier
		int min;
		int maxY;
		int maxY;
		float maxVel;
		float maxAcc;
};


PhysObj::PhysObj(){
	xPos = 0;
	yPos = 0;
	xVel = 0;
	yVel = 0;
	xAcc = 0.5;
	yAcc = 0.2;
	maxVel = 8;
	maxAcc = 1;
	
	dTime = 1;
	width = 600;
	height = 400;
	windMult = 10;
	min = windMult;
	maxX = width-windMult;
	maxY = height-windMult;
}

void PhysObj()::move(){
	xVel += xAccel*dTime;
	if(xVel < -maxVel) xVel = -maxVel;
	else if(xVel > maxVel) xVel = maxVel;
	xPos = xPos+xVel*(dTime)+.5*(xAccel)*(dTime*dTime);
}

void PhysObj()::noMove(){
	if(xVel < -0.25){ //If the velocity is negative
		xVel += xAccel*dTime;
		if(xVel < -maxVel) xVel = -maxVel;
		xPos = xPos+xVel*(dTime)+.5*(xAccel)*(dTime*dTime);
	}else if(xVel > 0.25){ //If velocity is positive
		xVel += -(xAccel)*dTime;
		if(xVel > maxVel) xVel = maxVel;
		xPos = xPos+xVel*(dTime)+.5*(xAccel)*(dTime*dTime);	
	}else xVel = 0;
}

void PhysObj()::setPos(float x,float y){
	if(!(x > maxX || x < min)) xPos = x;
	if(!(y > maxY || y < min)) yPos = y;
}

void PhysObj()::setVel(float x,float y){
	if(!(x > maxVel || x < -maxVel)) xVel = x;
	if(!(y > maxVel || y < -maxVel)) yVel = y;
}

void PhysObj()::setAcc(float x,float y){
	if(!(x > maxAcc || x < -maxAcc)) xVel = x;
	if(!(y > maxAcc || y < -maxAcc)) yVel = y;
}

/*
void PhysObj()::moveRight(){
	xVel += xAccel*dTime;
	if(xVel > maxxVel) xVel = maxxVel;
	xPos = xPos+xVel*(dTime)+.5*(xAccel)*(dTime*dTime);
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
*/

#endif