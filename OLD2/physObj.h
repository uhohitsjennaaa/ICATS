/*
This is the physObj class declaration. This class serves as a base class for both player and ball derived classes.  This class contains the functions associated with the movement of the objects and handling variables that both classes would require, such as position, velocity, height, width, etc.
*/

#ifndef PHYSOBJ_H
#define PHYSOBJ_H

#include <sstream>
#include "constants.h"
using namespace std;

class physObj{
	public: 
		physObj(); //constructor
		~physObj(); //destructor
		SDL_Rect* update(v2*); //updates variables and returns rect with updated position
		SDL_Surface* getSurf(); //returns object image surface
		string getImgFile(); //returns image file path
		
		void setPos(float,float); //set position
		float getV(); //return xVel
		int distance(float,float); //return 1 if within 1 TILE_SIZE of eachother
		virtual physObj& operator+=(int)=0; //change direction and magnitude of velocity
		
	protected:
		//object variables
		int objHeight;
		int objWidth;
		string s; //image file name
		
		//global variables
		int width;
		int height;
		int windMult; //window multiplier
		int thickness;
		int border;
		
		//playing field bounds
		int mins;
		int maxX;
		int maxY;
		int yPlat; //yPos of platform
		
		//object variables
		float xPos;
		float yPos;
		float xVel;
		float yVel;
		float xAcc;
		float yAcc;
		int maxXVel;
		int maxYVel;
		float dTime;
		float bFactor; //bounce factor to determine how much objects rebound
		
		//SDL objects
		SDL_Rect objRect;
		SDL_Surface *objSurf;
		
		//helper functions
		void setVel(float,float); //check velocity bounds and set velocity
		int isOnPlatform(v2); //checks for platform below object
};

#endif
