#ifndef PHYSOBJ_H
#define PHYSOBJ_H

#include <sstream>
#include "constants.h"
using namespace std;

class physObj{
	public: 
		physObj(); //constructor
		~physObj(); //destructor
		SDL_Rect* update();
		SDL_Surface* getSurf();
		
		virtual void setPos(float,float)=0; //set position
		physObj& operator+=(int); //change direction and magnitude of velocity
		float getV(); //return xVel
		
		int distance(float,float); //return 1 if within 1 TILE_SIZE of eachother
		
	protected:
		int objHeight;
		int objWidth;
		string s;
		
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
		
		//object variables
		float xPos;
		float yPos;
		float xVel;
		float yVel;
		float xAcc;
		float yAcc;
		float maxXVel;
		float maxYVel;
		float dTime;
		
		SDL_Rect objRect;
		SDL_Surface *objSurf;
		
		void setVel(float,float);
};

#endif