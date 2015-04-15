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
		void gravity(void);
		void updatePos(string);

		//Get functions
		float getxPos(void);
	
	private:
		float xPos;
		float yPos;
		float jump;
		float xVel;
		float yVel;
};

#endif

//Constructor
player::player(float ixPos, float iyPos){
	xPos = ixPos;
	yPos = iyPos;
	xVel = 0;
	yVel = 0;
	jump = 0; 
	return;
}

//Get x position
float player::getxPos(void){
	cout << xPos << endl;
	return xPos;
}

//Move left
void player::moveLeft(void){
	xVel += -0.25;
	xPos = xPos+xVel*(.25)+.25*(-.25)*(.25*.25);
}

//Move right
void player::moveRight(void){
	xVel += 0.25;
	xPos = xPos+xVel*(.25)+.25*(-.25)*(.25*.25);
}


