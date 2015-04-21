#ifndef FIELD_H
#define FIELD_H

#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector <char> > v2;

class playField {
	friend ostream &operator<<(ostream&,v2&); //overloaded operator for v2
	public:
		playField(int iHeight=400, int iWidth=600, int tileSize=10); //constructor
		void setField(); //create full field
		v2 getField(); //access vField
// 		v2 getPix(); //access pixField
	private:
		//Helper functions to create playing field elements
		void addBorder(int thickness); //Add border with thickness
		
		//Build platform from top left to bottom right
		void addPlatform(int startRow, int startCol, int pHeight, int pWidth); 
		
		//Build goal from top left to bottom right
		void addGoal(int startRow, int startCol, int gHeight, int gWidth);
		
		//Add a point to start a player
		void addStart(int startRow, int startCol, int sHeight, int sWidth);
		
		void mirror(); //Mirror left half of board
// 		void pixels(); //Make pixel field
		void print(); //print board
// 		void printPix(); //print values for each pixel
		
		int height;
		int width;
		int tSize;
		int pHeight;
		int pWidth;
		int playHeight;
		int playWidth;
		v2 vField;
// 		v2 pixField;
};
#endif