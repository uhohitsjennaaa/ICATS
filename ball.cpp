#include "ball.h"
using namespace std;

ball::ball() : physObj(){
	objHeight=TILE_SIZE;
	objWidth=TILE_SIZE;

	ostringstream os;
	os << imPath << "yarn" << imExt;
	string s=os.str();
	
	objSurf=SDL_LoadBMP(s.c_str()); //get picture
	
	allowHold=1;
}

void ball::toss(int i){
	int tmpVx,tmpVy;
	if(i) tmpVx = (rand() % 5 + 10); //throw right
	else tmpVx = (rand() % 5 + 10)*-1; //throw left
	tmpVy = (rand() % 5 + 10)*-1;
	setVel(tmpVx,tmpVy);
	allowHold = 1;
}

int ball::isHeld(){
	return (!allowHold);
}