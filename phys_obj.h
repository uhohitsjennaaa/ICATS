//Andrew Gnott
//March 18, 2015
//A base class for an object that will have be effected by physics
//and have properties such as size, (shape?), position, and gravity

#ifndef PHYS_OBJ_H
#define PHYS_OBJ_H


class PhysicalObject {
	public: 
		//Constructor (height, width, start positionX, start positionY, bounce factor);
		PhysicalObject(int = 10, int = 10, float = 30, float = 30, float = .5);
		
		//Functions to get position of object
		float getPositionX(void);
		float getPositionY(void);

		//Functions to take movement commands, may need to be CHAR, need to understand keyboard input
		void moveUp(int);
		void moveDown(int);
		void moveRight(int);
		void moveLeft(int);
		
	private: 
		int height;
		int width; 
		float positionX;
		float positionY;
		float bounceFactor; //How much speed will be retained after the object hits a wall/boundary

}

#endif
