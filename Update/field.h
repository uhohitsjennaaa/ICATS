#ifndef FIELD_H
#define FIELD_H

#include<iostream>
#include<vector>
using namespace std;

class playField {
	public:
		playField(int iHeight=40, int iWidth=60);
		void print(void);
		void printPix(void);
	
		//Create playing field elements
		//Add n-space border to field
		void addBorder(int thickness);
		//Add a platform starting at position from top left of field and built from top left to bottom right
		void addPlatform(int startRow, int startCol, int pHeight, int pWidth);
		//Add a goal via same process as a platform
		void addGoal(int startRow, int startCol, int gHeight, int gWidth, char goalSym);
		//Add a point to start a player
		void addStart(int startRow, int startCol, int sHeight, int sWidth, char playerNum);
		//Mirror left half of board
		void mirror(void);

		//Fields
		void makeField1(void);

		//Make pixel field
		void pixels();

		vector< vector< char> > vField;
		vector< vector< char> > pixField;

	private: 
		
		int height;
		int width;
		int playHeight;
		int playWidth;

};
#endif
