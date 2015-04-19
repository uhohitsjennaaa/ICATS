#include <SDL2/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
using namespace std;

template <typename T>
void is_error(T *ptr){
	if(ptr == NULL){
		cout << "Error with " << ptr << endl;		
		return 1;
	}else{
		return 0;
	}
}
