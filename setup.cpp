//As of 4/20: opens SDL window, changes background randomly, and creates board from playField.cpp
//To do: timer, scoring

#include "setup.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "playField.h"
using namespace std;

typedef vector< vector <char> > v2;

const int S_WIDTH=600; //set screen width
const int S_HEIGHT=400; //set screen height
const int TILE_SIZE=10;
const int P_WIDTH=15;
const int P_HEIGHT=30;

setup::setup(){
	srand(time(NULL)); //seed rand
	
	win=NULL;
	surf=NULL;
	field=NULL;

	imPath="./images/";
	bgPath="bg/";
	imExt=".bmp";
	
	bg=background();
}

setup::~setup(){
	SDL_FreeSurface(surf);
	SDL_FreeSurface(field);
	SDL_DestroyWindow(win);
	SDL_Quit(); //quit SDL
}

SDL_Window* setup::window(){
	SDL_Surface* tmp;
	
	if(SDL_Init(SDL_INIT_VIDEO)<0){ //initialize SDL
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	}else{ //create window
		win=SDL_CreateWindow("#IDARB",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,S_WIDTH,S_HEIGHT,SDL_WINDOW_SHOWN);
		if(win==NULL){
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
		}else{
			surf=SDL_GetWindowSurface(win); //get surface
			SDL_FillRect(surf,NULL,SDL_MapRGB(surf->format,255,255,255)); //fill white
			tmp=SDL_LoadBMP(bg.c_str()); //get picture
			if(tmp==NULL){
				cout << bg << " could not be loaded! SDL_Error: " << SDL_GetError() << endl;
			}else{
				SDL_BlitSurface(tmp,NULL,surf,NULL); //put image on surface
				makeFieldSurf(); //put field on surface
			}
			SDL_UpdateWindowSurface(win); //update surface
		}
	}
	SDL_FreeSurface(tmp);
	
	return win;
}

string setup::background(){
	ostringstream os;
 	int r;
 	//r=rand()%24+2; 
	r=0;
	
	//os << imPath << bgPath << "b" << r << imExt;
	os << imPath << "ocat" << imExt;
	string s=os.str();
	cout << s << endl;
	return s;
}

void setup::makeFieldSurf(){
	string tile[3]={"tile","goal1","goal2"};
	vector<SDL_Surface*> tSurf;
	int err=0;

	//get field info
	playField arena(S_HEIGHT,S_WIDTH,TILE_SIZE);
	arena.setField();
	v2 vField=arena.getField();

	//SDL_Rect to add field elements
	SDL_Rect tmpRect;
	tmpRect.w=TILE_SIZE;
	tmpRect.h=TILE_SIZE;
	
	//concatenate file name for tile image
	ostringstream os;
	string s;
	
	for(int i=0;i<3;i++){
		s.clear();
		os.str(s);
		os << imPath << tile[i] << imExt << ends;
		s=os.str();
		tSurf.push_back(SDL_LoadBMP(s.c_str())); //get tile
		if(tSurf[i]==NULL){
			cout << s << " could not be loaded! SDL_Error: " << SDL_GetError() << endl;
			err=1;
		} //end if(tmp==NULL)
	} //end for(int i=0;i<v.size();i++)
	
	//Draw the tiles and goals by using the vector fields
	if(!err){
		for(int iRow = 0; iRow < S_HEIGHT/TILE_SIZE; iRow++){
			tmpRect.y=iRow*TILE_SIZE;
			for(int iCol = 0; iCol < S_WIDTH/TILE_SIZE; iCol++){
				tmpRect.x=iCol*TILE_SIZE;
				if(vField[iRow][iCol] == '#') SDL_BlitSurface(tSurf[0],NULL,surf,&tmpRect); //add tile
// 				else if(vField[iRow][iCol] == '$') SDL_BlitSurface(tSurf[1],NULL,surf,&tmpRect); //make goal1
// 				else if(vField[iRow][iCol] == '%') SDL_BlitSurface(tSurf[2],NULL,surf,&tmpRect); //make goal2
			} //end for(int iCol = 0; iCol < width; iCol++)
		} //end for (int iRow = 0; iRow < height; iRow++)
	} //end if(tmp==NULL)...else
	
	for(int i=0;i<tSurf.size();i++) SDL_FreeSurface(tSurf[i]);
}
