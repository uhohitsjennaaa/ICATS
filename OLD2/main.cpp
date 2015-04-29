/*
This is the driver program that instantiates the setup class to play #ICATS
*/

#include "setup.h"
using namespace std;

int main(){
	int quit=0;
	
	setup game;
	quit=game.start();
 	while(!quit) quit=game.play();
}
