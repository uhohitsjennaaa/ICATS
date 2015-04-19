//Andrew Gnott
//March 18, 2015
//A base class for an object that will have be effected by physics
//and have properties such as size, (shape?), position, and gravity

#ifndef PHYS_OBJ_H
#define PHYS_OBJ_H


class PhysObj{
	public: 
		//Constructor
		PhysObj(float = 20, float = 20);
		
		//get Functions
		float getxPos(void);
		float getyPos(void);
		float getxVel(void);
		float getyVel(void);
		float getxAccel(void);
		float getyAccel(void);
		
		void gravity(void);
	protected: 
		//store keys chosen to move object
		float xPos;
		float yPos;
		float xVel;
		float maxxVel;
		float yVel;
		float maxyVel;
		float xAccel;
		float yAccel;
		float dTime;
};

PhysObj::PhysObj(float ixPos, float iyPos){
	xPos = ixPos;
	yPos = iyPos;
	xVel = 0;
	maxxVel = 8;
	yVel = 0;
	maxyVel = 8;
	xAccel = 0.5;
	yAccel = 0.2;
	dTime = 1;
	return;
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



#endif
