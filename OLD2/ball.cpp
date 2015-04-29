/*
This is the member function definition for the ball class.  Again, note that this is a simple class using an overloaded operator to determine a random velocity and a reset function to reinitiate the ball's position after goals are made.
*/

#include "ball.h"
using namespace std;

ball::ball() : physObj(){
	bFactor=-1.5; //set bounce factor
	
	//object variables
	objHeight=TILE_SIZE;
	objWidth=TILE_SIZE;
	
	//SDL_Rect variables
	objRect.w = objWidth;
	objRect.h = objHeight;
	
	//set bounds
	maxX = S_WIDTH-mins-objWidth+1;
	maxY = S_HEIGHT-mins-objHeight+1;

	//concatenate image file path
	ostringstream os;
	os << imPath << "yarn" << imExt;
	s=os.str();
	
	objSurf=SDL_LoadBMP(s.c_str()); //get picture
}

ball& ball::operator+=(int i){ //toss in random direction
	xVel = i*(rand() % 5 + 10);
	yVel = -(rand() % 5 + 10);
	return (* this);
}

void ball::reset(){
	xPos=S_WIDTH/2;
	yPos=S_HEIGHT/2;
}
