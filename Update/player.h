//Player class

#include <iostream>
#include <string>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class player{
	public:
		player(float = 20, float = 20);
		void moveLeft(void);
		void moveRight(void);
		void noMove(void);
		void gravity(void);
		void updatePos(string);

		//Get functions
		float getxPos(void);
		float getyPos(void);
		
		float xPos;
		float yPos;
	private:

		float jump;
		float xVel;
		float yVel;
		float accel;
		float dTime; 
};

#endif

//Constructor
player::player(float ixPos, float iyPos){
	xPos = ixPos;
	yPos = iyPos;
	xVel = 0;
	yVel = 0;
	jump = 0; 
	accel = .5;
	dTime = 1;
	return;
}

//Get x position
float player::getxPos(void){
	return xPos;
}

//Get y position
float player::getyPos(void){
	return yPos;
}

//Move left
void player::moveLeft(void){
	xVel += -1.5;
	xPos += xVel*dTime;
	//xVel += -(accel)*dTime;
	//xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);
}

//Move right
void player::moveRight(void){
	xVel +=	1.5;
	xPos += xVel*dTime;
	//xVel += accel*dTime;
	//xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);
}

//Handle no input keys
void player::noMove(void){
	//If the velocity is negative	
	/*if(xVel < 0){
		xVel += accel*dTime;
		xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);
	}else if(xVel > 0){
		xVel += -(accel)*dTime;
		xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);
	}*/
	xVel = 0;
	xPos += xVel*dTime;
}


