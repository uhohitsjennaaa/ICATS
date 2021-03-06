/*
The is the member function definition for the class setup.  Note that most of these functions are simply helper functions to split up the code and (hopefully) make it easier to debug and edit later.
*/

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
	bg=NULL;
	p1Text=NULL;
	p2Text=NULL;
	bText=NULL;
	const Uint8 *keys=NULL;
	
	vField=arena.makeField(); //get field info

	//set initial object positions
	p1.setPos(0,S_HEIGHT);
	p2.setPos(S_WIDTH,S_HEIGHT);
	b.setPos(S_WIDTH/2,S_HEIGHT/2);
	
	//get rects associated with objects
	p1Rect=p1.update(&vField);
	p2Rect=p2.update(&vField);
	bRect=b.update(&vField);
}

setup::~setup(){
	SDL_DestroyTexture(p1Text);
	SDL_DestroyTexture(p2Text);
	SDL_DestroyTexture(bText);
	SDL_DestroyTexture(bg);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(wind);
	SDL_Quit(); //quit SDL
}

void setup::window(){
 	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	else if(SDL_Init(SDL_INIT_VIDEO)<0) cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
	else wind=SDL_CreateWindow("#ICATS",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,S_WIDTH,S_HEIGHT,SDL_WINDOW_SHOWN);
}

void setup::renderer(){
 	rend=SDL_CreateRenderer(wind,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

string setup::background(){
	ostringstream os;
 	os << imPath << bgPath << "bg" << bgExt;
	string s=os.str();
	
	return s;
}

int setup::start(){
	window(); //open window
	renderer(); //open renderer
	
	//temp SDL surfaces
	SDL_Surface* surf=NULL;
	vector<SDL_Surface*> tSurf;

	//SDL_Rect to add field elements
	SDL_Rect tmpRect,tmpPix;
	tmpRect.w=TILE_SIZE;
	tmpRect.h=TILE_SIZE;
	
	//concatenate file name for tile and goal images
	ostringstream os;
	string s,tile[3]={"tile","goal1","goal2"};
	s=background(); //get background file path
	
	surf=SDL_LoadBMP(s.c_str()); //get background picture

	for(int i=0;i<3;i++){
		s.clear();
		os.str(s);
		os << imPath << tile[i] << bgExt << ends;
		s=os.str();
		tSurf.push_back(SDL_LoadBMP(s.c_str())); //get tile and goal images
	} //end for(int i=0;i<v.size();i++)
	
	for(int iRow = 0; iRow < S_HEIGHT/TILE_SIZE; iRow++){
		tmpRect.y=iRow*TILE_SIZE;
		for(int iCol = 0; iCol < S_WIDTH/TILE_SIZE; iCol++){
			tmpRect.x=iCol*TILE_SIZE;
			if(vField[iRow][iCol] == '#') SDL_BlitSurface(tSurf[0],NULL,surf,&tmpRect); //add tile
 			//else if(vField[iRow][iCol] == '%') SDL_BlitSurface(tSurf[1],NULL,surf,&tmpRect); //add goal1
 			//else if(vField[iRow][iCol] == '$') SDL_BlitSurface(tSurf[2],NULL,surf,&tmpRect); //add goal2
		} //end for(int iCol = 0; iCol < width; iCol++)
	} //end for (int iRow = 0; iRow < height; iRow++)

	for(int i=0;i<tSurf.size();i++){
		SDL_FreeSurface(tSurf[i]); //free tile and goal surfaces
		tSurf.pop_back(); //remove vector elements
	} //end for(int i=0;i<tSurf.size();i++)
	
	tmpRect.x=TILE_SIZE;
	tmpRect.y=TILE_SIZE;
	tmpRect.w=S_WIDTH;
	tmpRect.h=S_HEIGHT;
	
	s.clear();
	os.str(s);
	os << imPath << "scores" << imExt << ends;
	s=os.str();
	tSurf.push_back(IMG_Load(s.c_str()));
	SDL_BlitSurface(IMG_Load(s.c_str()),NULL,surf,&tmpRect);

	for(int i=0;i<10;i++){
		s.clear();
		os.str(s);
		os << imPath << i << imExt << ends;
		s=os.str();
		n.push_back(IMG_LoadTexture(rend,s.c_str())); //get tile and goal images
	} //end for(int i=0;i<v.size();i++)

	//create textures from images
	bg=SDL_CreateTextureFromSurface(rend,surf);
 	p1Text=IMG_LoadTexture(rend,(p1.getImgFile()).c_str());
 	p2Text=IMG_LoadTexture(rend,(p2.getImgFile()).c_str());
 	bText=IMG_LoadTexture(rend,(b.getImgFile()).c_str());
	
	SDL_FreeSurface(surf); //free temp surface
	
	//check for errors and render initial screen if none are found
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
	int out=0;
	
	out=getKeyIn(); //handle keyboard inputs
	updateAll(); //update all objects
	goal(); //check for goal
	possession(); //check for new possession
	rerender(); //rerender updated textures
		
	return out;
}

int setup::getKeyIn(){
	keys=SDL_GetKeyboardState(NULL);
		
	SDL_PollEvent(&event);
		
	if(keys[SDL_SCANCODE_ESCAPE]) return 1; //quit if user presses escape
	else{
		//player 1 controls
		if(keys[SDL_SCANCODE_S] && p1.hasBall()){ //toss ball
			if(keys[SDL_SCANCODE_A]){
				b+=-1; //toss left
				p1.setBall(0);
			}else if(keys[SDL_SCANCODE_D]){
				b+=1; //toss right
				p1.setBall(0);
			} //end if(keys[SDL_SCANCODE_A])...else if(keys[SDL_SCANCODE_D])
		}else if(keys[SDL_SCANCODE_A]) p1+=-5; //move left
		else if(keys[SDL_SCANCODE_D]) p1+=5; //move right
		else if(keys[SDL_SCANCODE_W]) p1.jump();
		else if(p1.getV()>0) p1+=-2; //positive velocity
		else if(p1.getV()<0) p1+=2; //negative velocity
		else p1+=0;
		
		//player 2 controls
		if(keys[SDL_SCANCODE_K] && p2.hasBall()){ //toss ball
			if(keys[SDL_SCANCODE_J]){
				b+=-1; //toss left
				p2.setBall(0);
			}else if(keys[SDL_SCANCODE_L]){
				b+=1; //toss right
				p2.setBall(0);
			} //end if(keys[SDL_SCANCODE_J])...else if(keys[SDL_SCANCODE_L])
		}else if(keys[SDL_SCANCODE_J]) p2+=-5; //move left 
		else if(keys[SDL_SCANCODE_L]) p2+=5; //move right
		else if(keys[SDL_SCANCODE_I]) p2.jump();
		else if(p2.getV()>0) p2+=-2; //positive velocity
		else if(p2.getV()<0) p2+=2; //negative velocity
		else p2+=0;
		
		return 0;
	} //end if(keys[SDL_SCANCODE_ESCAPE])...else
}

int setup::isOnPlatform(SDL_Rect* rect){
	int x=floor((rect->x)/TILE_SIZE); //scale pixels to firld matrix
	int y=floor(((rect->y)+(rect->h))/TILE_SIZE); //scale pixels to firld matrix
	int z=TILE_SIZE*floor((rect->y)/TILE_SIZE); //scale pixels to firld matrix
	for(int i=x;i<=x+1;i++) //check for platform under object with field array
		if(x>0 && x<S_WIDTH/TILE_SIZE-2 && y<S_HEIGHT/TILE_SIZE-2 && vField[y][i]=='#') return z;
	return 0;
}

void setup::updateAll(){
	p1Rect=p1.update(&vField); //update p1

	p2Rect=p2.update(&vField); //update p2

	//update ball
	if(p1.hasBall()){ //set ball position to that of p1
		(bRect->x)=(p1Rect->x);
		(bRect->y)=(p1Rect->y);
	}else if(p2.hasBall()){ //set ball position to that of p2
		(bRect->x)=(p2Rect->x);
		(bRect->y)=(p2Rect->y);
	}else bRect=b.update(&vField);
	b.setPos((bRect->x),(bRect->y)); //ensure that ball position updated
}

void setup::goal(){
	if(vField[((bRect->y))/TILE_SIZE][((bRect->x))/TILE_SIZE]=='$'){
		++p1;
		b.reset();
		p1.setBall(0);
		p2.setBall(0);
	}else if(vField[((bRect->y))/TILE_SIZE][((bRect->x))/TILE_SIZE]=='%'){
		++p2;
		b.reset();
		p1.setBall(0);
		p2.setBall(0);
	} //end if...else if(vField[((bRect->y))/TILE_SIZE][((bRect->x))/TILE_SIZE]=='%')
}

void setup::possession(){
	if (!p1.hasBall() && !p2.hasBall()){ //if no one has the ball and someone is close, they take it
		if(p1.distance((bRect->x),(bRect->y))) p1.setBall(1);
		else if(p2.distance((bRect->x),(bRect->y))) p2.setBall(1);
	}else if(p2.distance((p1Rect->x),(p1Rect->y))){ //if someone has the ball and the players are close, random toss
		p1.setBall(0);
		p2.setBall(0);
		b+=(rand()%3-1);
	} //end if (!p1.hasBall() && !p2.hasBall())... else if(p2.distance((p1Rect->x),(p2Rect->y)))
}

void setup::rerender(){
	SDL_RenderCopy(rend,bg,NULL,NULL); //re-render background

	//flip p1 depending on direction
	if(p1.getV()<-1){
		SDL_RenderCopyEx(rend,p1Text,NULL,p1Rect,0,NULL,SDL_FLIP_HORIZONTAL);
		p1.setFlip(1);
	}else if(p1.getV()>1){
		SDL_RenderCopy(rend,p1Text,NULL,p1Rect);
		p1.setFlip(0);
	}else if(p1.isFlipped()) SDL_RenderCopyEx(rend,p1Text,NULL,p1Rect,0,NULL,SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(rend,p1Text,NULL,p1Rect);
		
	//flip p2 depending on direction
	if(p2.getV()<-1){
		SDL_RenderCopy(rend,p2Text,NULL,p2Rect);			
		p2.setFlip(0);
	}else if(p2.getV()>1){
		SDL_RenderCopyEx(rend,p2Text,NULL,p2Rect,0,NULL,SDL_FLIP_HORIZONTAL);
		p2.setFlip(1);
	}else if(p2.isFlipped()) SDL_RenderCopyEx(rend,p2Text,NULL,p2Rect,0,NULL,SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(rend,p2Text,NULL,p2Rect);
	
	SDL_RenderCopy(rend,bText,NULL,bRect); //re-render ball
	
	score();
	
	SDL_RenderPresent(rend);
}

void setup::score(){
	SDL_Rect tmpRect;

	tmpRect.y=0;
	tmpRect.w=30;
	tmpRect.h=30;
	
	for(int i=8;i>1;i--){
		tmpRect.x=20*i+100;
		if(i==8 && p1.getScore()<10) SDL_RenderCopy(rend,n[p1.getScore()],NULL,&tmpRect);
		SDL_RenderCopy(rend,n[0],NULL,&tmpRect);
	} //end for(int i=1;i<=8;i++)
}
