#ifndef PLAYER_H
#define PLAYER_H

#include "physObj.h"
using namespace std;

class player: public physObj{
	public:
		player();
		void jump();
		static int getNum();
		int getScore(int);
		int hasBall();
		void setBall(int);
		void setPos(float,float);
	private:
		static int num;
		int n;
		int score;
		int ball;
};

#endif