/*
This is the ball class declaration.  Since most of the ball's functionality comes from the physObj class, this class only includes a few functions to initalize appropriate variables, reset position, and change velocity randomly if tossed.
*/

#ifndef BALL_H
#define BALL_H

#include "physObj.h"
using namespace std;

class ball: public physObj{
	public:
		ball(); //constructor
		void reset(); //resets ball position (for goals)
		ball& operator+=(int); //changes velocity randomly to simulate a toss
};

#endif
