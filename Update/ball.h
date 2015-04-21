//Ball class

#include <iostream>
#include <cmath>
#include <string>
#include "phys_obj.h"
#include "field.h"
#include "constants.h"
using namespace std;

#ifndef BALL_H
#define BALL_H

class ball: public PhysObj{
	public:
		ball(float, float, playField &);
		void Update(float, float, float, float);
	private:
		int p1Held;
		int p2Held;
		int noHold;

};

#endif

//Constructor
ball::ball(float ixPos, float iyPos, playField &arena) : PhysObj(ixPos, iyPos, .75, width, height, arena){
	width = 10;
	height = 10;
	return;
}

//Handle no input keys
void ball::Update(float xPos1, float yPos1, float xPos2, float yPos2){
	if(
	gravity();
	checkxBounds();
	checkyBounds();
}
