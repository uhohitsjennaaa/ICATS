//Player class

#include <iostream>
#include <cmath>
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
		void jump(void);
		void gravity(void);
		void updatePos(string);

		//Get functions
		float getxPos(void);
		float getyPos(void);

		//Functions to return the edges of the player, for working with arena vector
		int returnRight(void);
		int returnLeft(void);
		int returnTop(void);
		int returnBottom(void);
		int returnRow(void);
		
		float xPos;
		float yPos;
	private:

		float xVel;
		float maxxVel;
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
	maxxVel = 8;
	yVel = 0;
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
	xVel += -(accel)*dTime;
	if(xVel < -maxxVel){
		xVel = -maxxVel;
	}	
	xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);
}

//Move right
void player::moveRight(void){
	xVel += accel*dTime;
	if(xVel > maxxVel){
		xVel = maxxVel;
	}	
	xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);
}

//Handle no input keys
void player::noMove(void){
	//If the velocity is negative	
	if(xVel < -0.25){
		xVel += accel*dTime;
		if(xVel < -maxxVel){
			xVel = -maxxVel;
		}	
		xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);
	}else if(xVel > 0.25){ //If velocity is positive
		xVel += -(accel)*dTime;
		if(xVel > maxxVel){
			xVel = maxxVel;
		}
		xPos = xPos+xVel*(dTime)+.5*(accel)*(dTime*dTime);	
	}else{
		xVel = 0;
		xPos = xPos;
	}
}

//Functions to get the edges
int player::returnRight(void){
	return floor((xPos+15)/10)-1;
}
int player::returnLeft(void){
	return floor(xPos/10)-1;
}
int player::returnTop(void){
	return floor(yPos/10)-1;
}
int player::returnBottom(void){
	return floor((yPos+30)/10)-1;
}
int player::returnRow(void){
	return floor((yPos+15)/10)-1;
}
