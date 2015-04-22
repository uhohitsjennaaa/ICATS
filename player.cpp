#include "player.h"
using namespace std;

player::player(int num) : physObj(){
	n=num;
	objHeight=P_HEIGHT;
	objWidth=P_WIDTH;
	
	ostringstream os;
	os << imPath << "cat" << n << imExt;
	string s=os.str();
	
	objSurf=SDL_LoadBMP(s.c_str()); //get picture
}

void player::jump(){
	if(yVel >= 0){ //Allow jump if player is not in air
		int tmpVy = 15; //give initial yVelocity
		setVel(xVel,tmpVy);
		
		int tmpY = yPos + yVel*(dTime)+.1*(yAcc)*(dTime * dTime);
		setVel(xPos,tmpY);
	}
}