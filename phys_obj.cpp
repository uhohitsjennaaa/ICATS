//Andrew Gnott
//March 21, 2015
//A base class for an object that will have be effected by physics
//and have properties such as size, (shape?), position, and gravity
//Function implementation file
/*
		PhysicalObject(int = 10, int = 10, float = 30, float = 30, float = .5);
		
		//Functions to get position of object
		float getPositionX(void);
		float getPositionY(void);

		//Functions to take movement commands, may need to be CHAR, need to understand keyboard input
		void moveUp(int);
		void moveDown(int);
		void moveRight(int);
		void moveLeft(int);*/

#include <iostream>
#include "phys_obj"
using namespace std;

PhysicalObject::PhysicalObject(int iHeight, int iWidth, float iX, float iY, int iUpKey, int iDownKey, int iRightKey, int iLeftKey, float iBounce){
	height = iHeight;
	width = iWidth; 
	upKey = iUpKey;
	downKey = iDownKey;
	rightKey = iRightKey;
	leftKey = iLeftKey;
	positionX = iX;
	positionY = iY;
	bounceFactor = iBounce;
	return;
} 

float PhysicalObject::getPosX(void){
	return positionX;
}

float PhysicalObject::getPosY(void){
	return positionY;
}

void PhysicalObject::move(void){

}





