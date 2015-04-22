#ifndef PHYSOBJ_H
#define PHYSOBJ_H

#include <sstream>
#include "constants.h"
using namespace std;

class physObj{
	public: 
		physObj(); //Constructor
		SDL_Rect update();
		SDL_Surface *getSurf();
		
		void setPos(float,float);
		void setVel(float,float);
		void setAcc(float,float);
		
	protected:
		int objHeight;
		int objWidth;
		int n; //identifier number
		
		//global variables
		int width;
		int height;
		int windMult; //window multiplier
		
		//playing field bounds
		int minX;
		int maxX;
		int minY;
		int maxY;
		
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
		
		SDL_Rect objRect;
		SDL_Surface *objSurf;
};

#endif