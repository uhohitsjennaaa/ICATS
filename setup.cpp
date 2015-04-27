#include "setup.h"

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

setup::setup(){
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
	b.setPos(S_WIDTH/2,S_HEIGHT/2);
	
	p1Rect=p1.update();
	p2Rect=p2.update();
	bRect=b.update();
	
	vField=arena.makeField(); //get field info
}

setup::~setup(){
	/*
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_FreeSurface(surf);
	SDL_Quit(); //quit SDL
	*/
	SDL_DestroyTexture(p1Text);
	SDL_DestroyTexture(p2Text);
	SDL_DestroyTexture(bText);
	SDL_DestroyTexture(bg);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(wind);
	SDL_Quit(); //quit SDL
}

// SDL_Window* 
void setup::window(){
// 	SDL_Window* win;
	
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	else if(SDL_Init(SDL_INIT_VIDEO)<0) cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	else wind=SDL_CreateWindow("#IDARB",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,S_WIDTH,S_HEIGHT,SDL_WINDOW_SHOWN);
	
// 	if(wind==NULL) cout << "Could not open window! SDL_Error: " << SDL_GetError() << endl;
	
// 	return win;
}

// SDL_Renderer* 
void setup::renderer(){
// 	SDL_Renderer* ren;
 	
	rend=SDL_CreateRenderer(wind,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
// 	rend=SDL_CreateRenderer(wind,-1,SDL_RENDERER_SOFTWARE|SDL_RENDERER_TARGETTEXTURE);
	
// 	if(rend==NULL) cout << "Could not open renderer! SDL_Error: " << SDL_GetError() << endl;
	
// 	return ren;
}

string setup::background(){
	ostringstream os;
 	int r;
//  r=rand()%24+2; 
	r=0;
	
// 	os << imPath << bgPath << "b" << r << imExt;
	os << imPath << bgPath << "bg" << imExt;
	string s=os.str();
	
	return s;
}

int setup::start(){
	window();
	renderer();
	
	SDL_Surface* surf=NULL;
	vector<SDL_Surface*> tSurf;
	int err=0;

	//SDL_Rect to add field elements
	SDL_Rect tmpRect,tmpPix;
	tmpRect.w=TILE_SIZE;
	tmpRect.h=TILE_SIZE;
	
	//concatenate file name for tile image
	ostringstream os;
	string s,tile[3]={"tile","goal1","goal2"};
	s=background();
	
	surf=SDL_LoadBMP(s.c_str()); //get background picture

	for(int i=0;i<3;i++){
		s.clear();
		os.str(s);
		os << imPath << tile[i] << imExt << ends;
		s=os.str();
		tSurf.push_back(SDL_LoadBMP(s.c_str())); //get tile and goal images
	} //end for(int i=0;i<v.size();i++)
	
	for(int iRow = 0; iRow < S_HEIGHT/TILE_SIZE; iRow++){
		tmpRect.y=iRow*TILE_SIZE;
		for(int iCol = 0; iCol < S_WIDTH/TILE_SIZE; iCol++){
			tmpRect.x=iCol*TILE_SIZE;
			if(vField[iRow][iCol] == '#') SDL_BlitSurface(tSurf[0],NULL,surf,&tmpRect); //add tile
// 			else if(vField[iRow][iCol] == '%') SDL_BlitSurface(tSurf[1],NULL,surf,&tmpRect); //add goal1
// 			else if(vField[iRow][iCol] == '$') SDL_BlitSurface(tSurf[2],NULL,surf,&tmpRect); //add goal2
		} //end for(int iCol = 0; iCol < width; iCol++)
	} //end for (int iRow = 0; iRow < height; iRow++)
	
	for(int i=0;i<tSurf.size();i++) SDL_FreeSurface(tSurf[i]);

	//create textures from images
	bg=SDL_CreateTextureFromSurface(rend,surf);
	if(bg==NULL) cout << "bg SDL_Error: " << SDL_GetError() << endl;
	p1Text=SDL_CreateTextureFromSurface(rend,p1.getSurf());
// 	p1Text=IMG_LoadTexture(rend,(p1.getSurf()).c_str());
	if(p1Text==NULL) cout << "p1Text SDL_Error: " << SDL_GetError() << endl;
	p2Text=SDL_CreateTextureFromSurface(rend,p2.getSurf());
// 	p2Text=IMG_LoadTexture(rend,(p2.getSurf()).c_str());
	if(p2Text==NULL) cout << "p2Text SDL_Error: " << SDL_GetError() << endl;
	bText=SDL_CreateTextureFromSurface(rend,b.getSurf());
// 	bText=IMG_LoadTexture(rend,(b.getSurf()).c_str());
	if(bText==NULL) cout << "bText SDL_Error: " << SDL_GetError() << endl;
	
	SDL_FreeSurface(surf);
	
	
	
	if(wind==NULL||rend==NULL||bg==NULL||p1Text==NULL||p2Text==NULL||bText==NULL){
		cout << "SDL_Error: " << SDL_GetError() << endl;
		return 1;
	}else{
		SDL_RenderCopy(rend,bg,NULL,NULL);
		SDL_RenderCopy(rend,p1Text,NULL,p1Rect);
		SDL_RenderCopy(rend,p2Text,NULL,p2Rect);
		SDL_RenderCopy(rend,bText,NULL,bRect);
		SDL_RenderPresent(rend);
		return 0;
	} //end if(wind==NULL||rend==NULL||bg==NULL||p1Text==NULL||p2Text==NULL||bText==NULL)...else
}

int setup::play(){
	keys=SDL_GetKeyboardState(NULL);
		
	SDL_PollEvent(&event);
		
	//quit if user presses escape
	if(keys[SDL_SCANCODE_ESCAPE]) return 1;
	else{
		//player 1 controls
		if(keys[SDL_SCANCODE_A]) p1+=-5; //move left
		else if(keys[SDL_SCANCODE_D]) p1+=5; //move right
		else if(keys[SDL_SCANCODE_W]) p1.jump();
		else if(keys[SDL_SCANCODE_S]){
			if(keys[SDL_SCANCODE_A] && p1.hasBall()) b.toss(0); //toss left
			else b.toss(1); //toss right
			p1.setBall(0);
		} else if(p1.getV()>0) p1+=-2; //positive velocity
		else if(p1.getV()<0) p1+=.1; //negative velocity
		else p1+=0;
		
		//player 2 controls
		if(keys[SDL_SCANCODE_J]) p2+=-5; //move left
		else if(keys[SDL_SCANCODE_L]) p2+=5; //move right
		else if(keys[SDL_SCANCODE_I]) p2.jump();
		else if(keys[SDL_SCANCODE_K]){
			if(keys[SDL_SCANCODE_J] && p2.hasBall()) b.toss(0); //toss left
			else b.toss(1); //toss right
			p2.setBall(0);
		}else if(p2.getV()>0) p2+=-2; //positive velocity
		else if(p2.getV()<0) p2+=.1; //negative velocity
		else p2+=0;
			
		//update objects
		p1Rect=p1.update();
		p2Rect=p2.update();
		if(p1.hasBall()){ //set ball position to that of p1
			(bRect->x)=(p1Rect->x);
			(bRect->y)=(p1Rect->y);
		}else if(p2.hasBall()){ //set ball position to that of p2
			(bRect->x)=(p2Rect->x);
			(bRect->y)=(p2Rect->y);
		}else bRect=b.update();
		b.setPos((bRect->x),(bRect->y)); //ensure that ball position updated
		
		goal(); //check for goal
		possession(); //check for new possession
		
		//re-render
		SDL_RenderCopy(rend,bg,NULL,NULL);
		if(p1.getV()<0) SDL_RenderCopyEx(rend,p1Text,NULL,p1Rect,0,NULL,SDL_FLIP_HORIZONTAL);
		else SDL_RenderCopy(rend,p1Text,NULL,p1Rect);
		if(p2.getV()>0) SDL_RenderCopyEx(rend,p2Text,NULL,p2Rect,0,NULL,SDL_FLIP_HORIZONTAL);
		else SDL_RenderCopy(rend,p2Text,NULL,p2Rect);
		SDL_RenderCopy(rend,bText,NULL,bRect);

		SDL_RenderPresent(rend);
		
		return 0;
	} //end if(keys[SDL_SCANCODE_ESCAPE])...else
}

void setup::goal(){
	if(vField[((bRect->y))/TILE_SIZE][((bRect->x))/TILE_SIZE]=='$'){
		p1.getScore(b.getBounces()+1);
		b.reset();
		p1.setBall(0);
		p2.setBall(0);
	}else if(vField[((bRect->y))/TILE_SIZE][((bRect->x))/TILE_SIZE]=='%'){
		p2.getScore(b.getBounces()+1);
		b.reset();
		p1.setBall(0);
		p2.setBall(0);
	}
// 	SDL_WaitEventTimeout(&event->keys[SDL_SCANCODE_RETURN],5000); //wait for enter or 5 secs to continue playing
}

void setup::possession(){
	if (!p1.hasBall() && !p2.hasBall()){
		if(p1.distance((bRect->x),(bRect->y))) p1.setBall(1);
// 		cout << bRect->x << "_" << bRect->y << "_" << p1.distance((bRect->x),(bRect->y)) << endl;
		else if(p2.distance((bRect->x),(bRect->y))) p2.setBall(1);
	}else if(p2.distance((p1Rect->x),(p1Rect->y))){
		if(p1.hasBall()) p1.setBall(0);
		else if(p2.hasBall()) p2.setBall(0);
		b.toss(rand()%2);
	} //end if (!p1.hasBall() && !p2.hasBall())... else if(p2.distance((p1Rect->x),(p2Rect->y)))
}