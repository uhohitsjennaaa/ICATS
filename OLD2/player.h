/*
This is the player class declaration. Much like the ball class, this class mostly contains simple functions to keep track of score, ball possession, and direction.  It also adds a jump functionality and uses a static int to count the number of players, which is used in determining which image file to load as the character.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "physObj.h"
using namespace std;

class player: public physObj{
	public:
		player(); //constructor
		void jump(); //jumping movement
		static int getNum(); //player number
		int getScore(); //increments and returns score
		int hasBall(); //1 if has ball, 0 if not
		void setBall(int); //sets possesion of ball
		int isFlipped(); //check if flipped image
		void setFlip(int); //saves if the image is currently flipped or not
		player& operator++(); //adds to score
		player& operator+=(int); //changes velocity to move
	private:
		static int num; //player counter within class
		int n; //player number
		int score;
		int ball; //1 if has ball, 0 if not
		int flip; //1 if image is flipped, 0 if not
};

#endif
