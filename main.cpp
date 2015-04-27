#include "setup.h"
using namespace std;

int main(){
	int quit=0;
	
	setup game;
	quit=game.start();
 	while(!quit) quit=game.play();
 	
	/*
	srand(time(NULL)); //seed rand
	
	wind=NULL;
	rend=NULL;
// 	surf=NULL;
	bg=NULL;
	p1Text=NULL;
	p2Text=NULL;
	bText=NULL;
	const Uint8 *keys=NULL;
	
	//set initial object positions
	p1.setPos(0,S_HEIGHT);
	p2.setPos(S_WIDTH,S_HEIGHT);
	b.setPos(S_WIDTH/2,S_HEIGHT);
	
	vField=arena.makeField(); //get field info
	*/
	
}