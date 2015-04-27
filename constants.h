#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int S_WIDTH = 600;
const int S_HEIGHT = 400;
const int TILE_SIZE = 10;
const int B_THICKNESS = 1;
const int P_WIDTH = 20;
const int P_HEIGHT = 40;
const string imPath="./images/";
const string bgPath="bg/";
const string imExt=".bmp";

typedef vector< vector <char> > v2;

#endif
