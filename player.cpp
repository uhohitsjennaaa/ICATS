#include "player.h"
using namespace std;

int player::num=0;

player::player() : physObj(){
	n=getNum();
	score=0;
	ball=0;
	
	objHeight=P_HEIGHT;
	objWidth=P_WIDTH;
	
	objRect.w = objWidth;
	objRect.h = objHeight;
	
	maxX = S_WIDTH-mins-objWidth;
	maxY = S_HEIGHT-mins-objHeight;
	
	ostringstream os;
	os << imPath << "cat" << n << imExt;
	string s=os.str();
	
	objSurf=SDL_LoadBMP(s.c_str()); //get picture
}

int player::getNum(){
	return ++num;
}

int player::getScore(int i){
	return score+=i;
}

void player::jump(){
	if(yVel >= 0){ //Allow jump if player is not in air
		int tmpVy=-maxYVel; //give initial y-velocity
		setVel(xVel,tmpVy);
		
		int tmpY = yPos+yVel*(dTime)+.5*(yAcc)*(dTime * dTime);
		setPos(xPos,tmpY);
	}
}

int player::hasBall(){
	return ball;
}

void player::setBall(int b){
	ball=b;
}

void player::setPos(float x,float y){
	if(x < mins) xPos = mins;
	else if(x > maxX) xPos = maxX;
	else xPos = x;
	
	if(y < mins) yPos = mins;
	else if(y > maxY) yPos = maxY;
	else yPos = y;
}