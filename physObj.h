#ifndef PHYSOBJ_H
#define PHYSOBJ_H

#include "constants.h"
using namespace std;

class physObj{
	public: 
		physObj(float,float,int,int); //Constructor
		void moveX(); //moves left and right
		void moveY(); //moves up and down
		
		void setPos(float,float);
		void setVel(float,float);
		void setAcc(float,float);
		
	protected:
		//object variables
		float xPos;
		float yPos;
		float xVel;
		float yVel;
		float xAcc;
		float yAcc;
		float maxVel;
		float maxAcc;
		float dTime;
		
		int objHeight;
		int objWidth;
		
		//global variables
		int width;
		int height;
		int windMult; //window multiplier
		
		//playing field bounds
		int minX;
		int maxX;
		int minY;
		int maxY;
};

#endif