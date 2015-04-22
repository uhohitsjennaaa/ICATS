#ifndef BALL_H
#define BALL_H

#include "physObj.h"
using namespace std;

class ball: public PhysObj{
	public:
		ball();
		void Update(float, float, float, float);
	private:
		int p1Held;
		int p2Held;
		int noHold;
};

//Constructor
ball::ball() : PhysObj(){
	objWidth = 20;
	objHeight = 20;
}

//Handle no input keys
void ball::update(){

}

#endif