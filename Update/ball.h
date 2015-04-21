//Ball class

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include "phys_obj.h"
#include "field.h"
#include "constants.h"
using namespace std;

#ifndef BALL_H
#define BALL_H

class ball: public PhysObj{
	public:
		ball(float, float, playField &);
		void Update(float, float, float, float);
		void grab(float, float, float, float);
		void throwRight(int);
		void throwLeft(int);
		void xMove(void);
	private:
		int p1Held;
		int p2Held;
		int allowHold;
		int holdCount;

};

#endif

//Constructor
ball::ball(float ixPos, float iyPos, playField &arena) : PhysObj(ixPos, iyPos, .75, 10, 10, arena){
	//Seed random generator
	srand(time(NULL));
	p1Held = 0;
	p2Held = 0;
	allowHold = 1;
	holdCount = 0;
	return;
}

//Find close player and see if they grab the ball
void ball::grab(float xPos1, float yPos1, float xPos2, float yPos2){
	//Allow players to grab the ball if it is close enough
	if(sqrt(pow((xPos2+(P_WIDTH/2.0) - xPos),2)) < 25 && sqrt(pow((yPos2+(P_HEIGHT/2.0) - yPos),2)) < 25 && allowHold == 1){
		p2Held = 1;
	}
	if(sqrt(pow((xPos1+(P_WIDTH/2.0) - xPos),2)) < 25 && sqrt(pow((yPos1+(P_HEIGHT/2.0) - yPos),2)) < 25 && allowHold == 1){
		p1Held = 1;
	}
	return;
}

//Throw left
void ball::throwLeft(int thrower){
	if(p1Held && thrower == 1){	
		xVel = ((rand() % 50 + 200) / 10.0)*-1;
		yVel = ((rand() % 50 + 100) / 10.0)*-1;
		p1Held = 0;
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}else if(p2Held && thrower == 2){
		xVel = ((rand() % 50 + 200) / 10.0)*-1;
		yVel = ((rand() % 50 + 100) / 10.0)*-1;
		p1Held = 0;		
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}
}

void ball::throwRight(int thrower){
	if(p1Held && thrower == 1){	
		xVel = ((rand() % 50 + 200) / 10.0);
		yVel = ((rand() % 50 + 100) / 10.0)*-1;
		p1Held = 0;
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}else if(p2Held && thrower == 2){
		xVel = ((rand() % 50 + 200) / 10.0);
		yVel = ((rand() % 50 + 100) / 10.0)*-1;
		p1Held = 0;		
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}
}


//Update upon each frame
void ball::Update(float xPos1, float yPos1, float xPos2, float yPos2){
	//Allow player to grab the ball
	grab(xPos1, yPos1, xPos2, yPos2);	

	//Ball flies away if players are too close to each other and the ball is held, a steal!
	if(sqrt(pow(((xPos1+(P_WIDTH/2.0)) - (xPos2+(P_WIDTH/2.0))),2)) < 25 
			&& sqrt(pow(((yPos1+(P_HEIGHT/2.0)) - (yPos2+(P_HEIGHT/2.0))),2)) < 25 
			&& (p1Held || p2Held)){

			p1Held = 0;
			p2Held = 0;
			xVel = ((rand() % 50 + 100) / 10.0)*pow(-1.0,rand() % 2);
			yVel = ((rand() % 50 + 75) / 10.0)*-1;						
			allowHold = 0;
			holdCount = 0;
		}
	
	//Follow a player if it's being held
	if(p1Held){
		xPos = xPos1;
		yPos = yPos1;
	}else if(p2Held){
		xPos = xPos2;
		yPos = yPos2;
	}else{
		xMove();
		checkxBounds();
		gravity();
		checkyBounds();
		if(holdCount++ > 20){
			allowHold = 1;
		}
	}
}

//movement along xAxis
void ball::xMove(void){	
	//If velocity is negative
	if(xVel < -.25){
		xVel += (xAccel/5.0)*dTime;
		xPos = xPos+xVel*(dTime)+.5*(xAccel/5.0)*(dTime*dTime);
	}else if(xVel > .25){ //If velocity is positive
		xVel -= (xAccel/5.0)*dTime;
		xPos = xPos+xVel*(dTime)-.5*(xAccel/5.0)*(dTime*dTime);	
	}else{
		xVel = 0;
		xPos = xPos;
	}
}
