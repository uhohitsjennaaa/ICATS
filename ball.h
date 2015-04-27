#ifndef BALL_H
#define BALL_H

#include "physObj.h"
using namespace std;

class ball: public physObj{
	public:
		ball();
		void toss(int);
		void reset();
		void setPos(float,float);
		int getBounces();
	private:
		int bounce;
};

#endif