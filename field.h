#ifndef FIELD_H
#define FIELD_H

#include<iostream>
#include<vector>
using namespace std;

class playField {
	public:
		playField(int iHeight=400, int iWidth=600);
		void print(void);
	
		//Add n-space border to field
		void addBorder(int thickness);
		//Add a platform starting at position from top left of field and built from top left to bottom right
		void addPlatform(int startRow, int startCol, int pHeight, int pWidth);
		//Add a goal via same process as a platform
		void addGoal(int startRow, int startCol, int gHeight, int gWidth);

	private: 
		vector< vector< char> > vField;
		int height;
		int width;

};
#endif
