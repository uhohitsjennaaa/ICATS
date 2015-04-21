//Player class

#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>
#include <iostream>
#include <string>

#include "phys_obj.h"
#include "field.h"
#include "constants.h"

using namespace std;

class player: public PhysObj{
	public:
		player(float, float, playField &);
		
	private:
		
};

#endif

player::player(float ixPos, float iyPos, playField &arena) : PhysObj(ixPos, iyPos, arena){
	width = 15;
	height = 30;
}

//Move left
void player::moveLeft(void){
	xVel += -(xAcc)*dTime;
	if(xVel < -maxVel) xVel = -maxVel;
	xPos = xPos+xVel*(dTime)+.5*(xAcc)*(dTime*dTime);
}

//Move right
void player::moveRight(void){
	xVel += xAcc*dTime;
	if(xVel > maxVel) xVel = maxVel;
	xPos = xPos+xVel*(dTime)+.5*(xAcc)*(dTime*dTime);
}

//Handle no input keys
void player::noMove(void){
	//If the velocity is negative	
	if(xVel < -0.25){
		xVel += xAcc*dTime;
		if(xVel < -maxVel){
			xVel = -maxVel;
		}	
		xPos = xPos+xVel*(dTime)+.5*(xAcc)*(dTime*dTime);
	}else if(xVel > 0.25){ //If velocity is positive
		xVel += -(xAcc)*dTime;
		if(xVel > maxVel){
			xVel = maxVel;
		}
		xPos = xPos+xVel*(dTime)+.5*(xAcc)*(dTime*dTime);	
	}else{
		xVel = 0;
		xPos = xPos;
	}
	cout << arena.vField[0][0];
}
