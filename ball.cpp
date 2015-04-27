#include "ball.h"
using namespace std;

ball::ball() : physObj(){
	bounce=0;
	
	objHeight=TILE_SIZE;
	objWidth=TILE_SIZE;
	
	objRect.w = objWidth;
	objRect.h = objHeight;
	
	maxX = S_WIDTH-mins-objWidth;
	maxY = S_HEIGHT-mins-objHeight;

	ostringstream os;
	os << imPath << "yarn" << imExt;
	string s=os.str();
	
	objSurf=SDL_LoadBMP(s.c_str()); //get picture
}

void ball::toss(int i){
	if(i>0) xVel = (rand() % 5 + 10); //throw right
	else xVel = (rand() % 5 - 15); //throw left
	yVel = (rand() % 5 - 15);
}

void ball::reset(){
	bounce=0;
	xPos=S_WIDTH/2;
	yPos=S_HEIGHT/2;
}

void ball::setPos(float x,float y){
	if(x <= mins-2 || x >= maxX+2){
		xVel*=-2;
		bounce++;
	}else xPos=x;
	
	if(y <= mins-2 || y >= maxY+2){
		yVel*=-.75;
		bounce++;
	}else yPos=y;
}

int ball::getBounces(){
	return bounce;
}

/*
//Find close player and see if they grab the ball
void ball::grab(float xPos1, float yPos1, float xPos2, float yPos2){
	//Allow players to grab the ball if it is close enough, second statement allows blocking
	if(sqrt(pow((xPos2+(P_WIDTH/2.0) - xPos),2)) < 25 && sqrt(pow((yPos2+(P_HEIGHT/2.0) - yPos),2)) < 25 && allowHold == 1){
		p2Held = 1;
		bounces = 0;
	}else if(sqrt(pow((xPos2+(P_WIDTH/2.0) - xPos),2)) < 25 && sqrt(pow((yPos2+(P_HEIGHT/2.0) - yPos),2)) < 25 && allowHold == 0 && holdCount > 3){
		xVel *= -1.25*bounceFactor;
		bounces++;
	}
	if(sqrt(pow((xPos1+(P_WIDTH/2.0) - xPos),2)) < 25 && sqrt(pow((yPos1+(P_HEIGHT/2.0) - yPos),2)) < 25 && allowHold == 1){
		p1Held = 1;
		bounces = 0;
	}else if(sqrt(pow((xPos1+(P_WIDTH/2.0) - xPos),2)) < 25 && sqrt(pow((yPos1+(P_HEIGHT/2.0) - yPos),2)) < 25 && allowHold == 0 && holdCount > 3){
		xVel *= -1.25*bounceFactor;
		bounces++;
	}
	return;
}
*/