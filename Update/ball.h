//Ball class

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
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
		void grab(float, float, float, float);
		void reset(void);
		void throwRight(int);
		void throwLeft(int);
		void xMove(void);
		int score(void);
		int inGoal(void);
	private:
		int p1Held;
		int p2Held;
		int p1Score;
		int p2Score;
		int allowHold;
		int holdCount;
		int bounces; //Count number of bounces for scoring
};

#endif

//Constructor
ball::ball(float ixPos, float iyPos, playField &arena) : PhysObj(ixPos, iyPos, .9, 10, 10, arena){
	//Seed random generator
	srand(time(NULL));
	p1Held = 0;
	p2Held = 0;
	p1Score = 0;
	p2Score = 0;
	allowHold = 1;
	holdCount = 0;
	bounces = 0;
	return;
}

void ball::reset(void){
	p1Held = 0;
	p2Held = 0;
	xPos = (S_WIDTH/2);
	yPos = (S_HEIGHT/2);
}

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

//Throw left
void ball::throwLeft(int thrower){
	if(p1Held && thrower == 1){	
		xVel = ((rand() % 50 + 200) / 10.0)*-1;
		yVel = ((rand() % 75 + 100) / 10.0)*-1;
		p1Held = 0;
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}else if(p2Held && thrower == 2){
		xVel = ((rand() % 50 + 200) / 10.0)*-1;
		yVel = ((rand() % 75 + 100) / 10.0)*-1;
		p1Held = 0;		
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}
}

//Throw right
void ball::throwRight(int thrower){
	if(p1Held && thrower == 1){	
		xVel = ((rand() % 50 + 200) / 10.0);
		yVel = ((rand() % 75 + 100) / 10.0)*-1;
		p1Held = 0;
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}else if(p2Held && thrower == 2){
		xVel = ((rand() % 50 + 200) / 10.0);
		yVel = ((rand() % 75 + 100) / 10.0)*-1;
		p1Held = 0;		
		p2Held = 0;
		allowHold = 0;
		holdCount = 0;
	}
}

//Check if ball is in a goal
int ball::inGoal(void){
	if(arena.vField[getyCenter()][getxCenter()] == '$'){
		xVel *= .5;
		if(bounces == 0){
			p1Score += 1;
		}else{
			p1Score += bounces;		
		}		
		reset();
		return 1;
	}else if(arena.vField[getyCenter()][getxCenter()] == '%'){
		xVel *= .5;
		if(bounces == 0){
			p2Score += 1;
		}else{
			p2Score += bounces;		
		}		
		reset();
		return 2;
	}
	return 0;
}

//See if player scores, return player who did
int ball::score(void){
	if(inGoal()==1){
		cout << "Player 1 Scores!" << endl;
		cout << "Score:" << endl;
		cout << p1Score << ":" << p2Score << endl;
		return 1;
	}else if(inGoal()==2){
		cout << "Player 2 Scores!" << endl;
		cout << "Score:" << endl;
		cout << p1Score << ":" << p2Score << endl;
		return 2;
	}
	return 0;
}

//Update upon each frame
void ball::Update(float xPos1, float yPos1, float xPos2, float yPos2){
	//Allow player to grab the ball
	grab(xPos1, yPos1, xPos2, yPos2);	

	//Ball flies away if players are too close to each other and the ball is held, a steal!
	if(sqrt(pow(((xPos1+(P_WIDTH/2.0)) - (xPos2+(P_WIDTH/2.0))),2)) < 25 
			&& sqrt(pow(((yPos1+(P_HEIGHT/2.0)) - (yPos2+(P_HEIGHT/2.0))),2)) < 25 
			&& (p1Held || p2Held)){

		p1Held = 0;
		p2Held = 0;
		xVel = ((rand() % 50 + 100) / 10.0)*pow(-1.0,rand() % 2);
		yVel = ((rand() % 50 + 75) / 10.0)*-1;						
		allowHold = 0;
		holdCount = 0;
	}

	//Follow a player if it's being held
	if(p1Held){
		xPos = xPos1;
		yPos = yPos1;
	}else if(p2Held){
		xPos = xPos2;
		yPos = yPos2;
	}else{
		xMove();
		bounces += checkxBounds();
		gravity();
		bounces += checkyBounds();
		if(holdCount++ > 20){
			allowHold = 1;
		}
	}
}

//movement along xAxis
void ball::xMove(void){	
	xAccel = .75;
	//If velocity is negative
	if(xVel < -.05){
		xVel += (xAccel/5.0)*dTime;
		xPos = xPos+xVel*(dTime)+.5*(xAccel/5.0)*(dTime*dTime);
	}else if(xVel > .05){ //If velocity is positive
		xVel -= (xAccel/5.0)*dTime;
		xPos = xPos+xVel*(dTime)-.5*(xAccel/5.0)*(dTime*dTime);	
	}else{
		xVel = 0;
		xPos = xPos;
	}
}
