#ifndef PLAYER_H
#define PLAYER_H

#include <cmath>
#include <string>

#include "physObj.h"
using namespace std;

class player: public PhysObj{
	public:
		player();
		void jump();
	private:
};

player::player() : PhysObj(x,y,40,20){
	setPos(minX,minY);
}

//Jump function
void player::jump(){
	if(jumped == 0){ //Allow jump if player is not in air from a previous jump	
		yVel -= 15; //give initial yVelocity
		yPos = yPos + yVel*(dTime)+.5*(yAccel)*(dTime * dTime);
		jumped = 1;
	}
}

#endif