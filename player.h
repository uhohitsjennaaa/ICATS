#ifndef PLAYER_H
#define PLAYER_H

#include "physObj.h"
using namespace std;

class player: public physObj{
	public:
		player(int);
		void jump();
};

#endif