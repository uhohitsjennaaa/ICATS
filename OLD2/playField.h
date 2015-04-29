/*
This is the playField class declaration. This class is used to creat the playing field as a matrix in which borders, platforms, and goals are represented by special characters. This class is mostly composed of helper functions that change the values of specified elements of the matrix and are all used in the makeFielf() function to create and output the final field matrix.
*/

#ifndef FIELD_H
#define FIELD_H

#include "constants.h"
using namespace std;

class playField {
	friend ostream &operator<<(ostream&,v2&); //overloaded operator for v2
	public:
		playField(); //constructor
		v2 makeField(); //create field
		void print(); //print board

	private:
		//Helper functions to create playing field elements
		void addBorder(); //Add border with thickness
		
		//Build platform from top left to bottom right
		void addPlatform(int startRow, int startCol, int pHeight, int pWidth); 
		
		//Build goal from top left to bottom right
		void addGoal(int startRow, int startCol, int gHeight, int gWidth);
		
		//Add a point to start a player
		void addStart(int startRow, int startCol, int sHeight, int sWidth);
		
		void mirror(); //Mirror left half of board
		
		int height;
		int width;
		int tSize;
		int thickness;
		int pHeight;
		int pWidth;
		v2 vField;
};

#endif
