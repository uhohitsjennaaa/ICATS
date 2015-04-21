//phys_obj.h
//A base class for an object that will have be effected by physics

#include<iostream>
#include<cmath>
#include "field.h"
#include "constants.h"

using namespace std;

#ifndef PHYS_OBJ_H
#define PHYS_OBJ_H

class PhysObj{
	public: 
		//Constructor
		PhysObj(float, float, float, int, int, playField &);
		
		//get Functions
		virtual int getEdgeLeft(void);
                virtual int getEdgeRight(void);
                virtual int getEdgeTop(void);
                virtual int getEdgeBottom(void);
		virtual int getyCenter(void);
		virtual int getxCenter(void);
		
		virtual float getxPos(void);
		virtual float getyPos(void);
		virtual float getxVel(void);
		virtual float getyVel(void);
		virtual float getxAccel(void);
		virtual float getyAccel(void);
		
		virtual void setxPos(float);
		virtual void setyPos(float);
		
		virtual void checkxBounds(void);
		virtual void checkyBounds(void);
		virtual void gravity(void);
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
			
		float bounceFactor;
		int jumped;

		int width;
		int height;
		float windMult; //window multiplier
		
};


PhysObj::PhysObj(float ixPos, float iyPos, float bounce, int iwidth, int iheight, playField &field){
	xPos = ixPos;
	yPos = iyPos;
	xVel = 0;
	maxxVel = 7;
	yVel = 0;
	maxyVel = 7;
	xAccel = 3; //0.75;
	yAccel = 1;
	dTime = 1;
	jumped = 0;
	bounceFactor = bounce;
	windMult = 10;
	width = iwidth;
	height = iheight;
	arena = field;
	return;
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
	return ceil((yPos+(height/2.0))/windMult)-1;
}

int PhysObj::getxCenter(){
	return ceil((xPos+(width/2.0))/windMult)-1;
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

void PhysObj::checkxBounds(void){
	//Checking at left, moving object right, bouncing off
	if(arena.vField[getyCenter()][getEdgeLeft()] == '#' || xPos < 0){
		for(int i=getEdgeLeft(); i<getEdgeLeft()+5; i++){
			if(arena.vField[getyCenter()][i] != '#'){
				xPos = i*TILE_SIZE;
				xVel *= -bounceFactor;
				break;
			}
		}
	//If object is off left of screen
	}else if(xPos < 0){
		for(int i=0; i<5; i++){
			if(arena.vField[getyCenter()][i] != '#'){
				xPos = i*TILE_SIZE;
				xVel *= -bounceFactor;
				break;
			}
		}
	//If player runs into '#' on his right
	}else if(arena.vField[getyCenter()][getEdgeRight()] == '#'){
		for(int i=getEdgeRight(); i>getEdgeRight()-5; i--){
			if(arena.vField[getyCenter()][i] != '#'){
				xPos = i*TILE_SIZE-(width-TILE_SIZE);
				xVel *= -bounceFactor;
				break;
			}
		}
	//If object goes beyond screen width
	}else if(xPos > S_WIDTH){
		for(int i=(S_WIDTH/windMult-1); i>((S_WIDTH/windMult)-1)-5; i--){
			if(arena.vField[getyCenter()][i] != '#'){
				xPos = i*TILE_SIZE-(width-TILE_SIZE);
				xVel *= -bounceFactor;
				break;
			}
		}
	}
}

void PhysObj::checkyBounds(void){
	//Off the bottom
	if(getyCenter() >= (S_HEIGHT / windMult)-1){	
		for(int i=(S_HEIGHT / windMult)-1; i>(S_HEIGHT / windMult)-6; i--){
			if(arena.vField[i][getxCenter()] != '#'){
				yPos = i*TILE_SIZE-(height-TILE_SIZE);
				yVel *= -bounceFactor; 
				jumped = 0;
				break;
			}
		}
	//Check object's bottom edge, at '#'
	}else if(arena.vField[getEdgeBottom()][getxCenter()] == '#'){
		for(int i=getEdgeBottom(); i>getEdgeBottom()-5; i--){
			if(arena.vField[i][getxCenter()] != '#'){
				yPos = i*TILE_SIZE-(height-TILE_SIZE);
				yVel *= -bounceFactor;
				jumped = 0;
				break;
			}
		}
	//Off the top of the screen
	}else if(getyCenter() <= 0){
		for(int i=1; i<5; i++){
			if(arena.vField[i][getxCenter()] != '#'){
				yVel *= -bounceFactor;
				yPos = i*TILE_SIZE;
				break;
			}
		}
	//check top of object, at '#'
	}else if(arena.vField[getEdgeTop()][getxCenter()] == '#'){
		for(int i=getEdgeTop(); i<getEdgeTop()+5; i++){
			if(arena.vField[i][getxCenter()] != '#'){
				yVel *= -bounceFactor;
				yPos = i*TILE_SIZE;
				break;
			}
		}
	}
}

//Implement an always-downward acceleration on the object aka gravity
void PhysObj::gravity(void){
	if(yVel > 0){
		yVel += yAccel*dTime;
		yPos = yPos + yVel*(dTime)+.5*(yAccel)*(dTime*dTime);
	}else if(yVel <= 0){
		yVel += yAccel*dTime;
		yPos = yPos + yVel*(dTime)+.5*(yAccel)*(dTime*dTime);
	}
}
#endif
