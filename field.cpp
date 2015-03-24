#include<iostream>
#include<vector>
#include<algorithm>
#include"field.h"
using namespace std;

playField::playField(int iHeight, int iWidth){
	height = iHeight;
	width = iWidth;

	//temp vector for storing
	vector <char> tempVec;

	//fill char vector
	for(int iCol=0; iCol<width; iCol++){
		tempVec.push_back(' ');
	}	
	//fill rows
	for(int iRow=0; iRow<height; iRow++){
		vField.push_back(tempVec);
	}
}

void playField::print(void){
	//print board
	for(int iRow=0; iRow<height; iRow++){
		for(int iCol=0; iCol<width; iCol++){
			cout << vField[iRow][iCol] << " ";
		}
		cout << endl;
	}
}

//Create a n-thickness border to playing field
void playField::addBorder(int thickness){
	//Top border
	for(int iRow=0; iRow<thickness; iRow++){
		for(int iCol=0; iCol<width; iCol++){
			vField[iRow][iCol] = '#';
		}
	}
	//bottom border
	for(int iRow=height-1; iRow>=height-thickness; iRow--){
		for(int iCol=0; iCol<width; iCol++){
			vField[iRow][iCol] = '#';
		}
	}
	//left border
	for(int iCol=0; iCol<thickness; iCol++){
		for(int iRow=0; iRow<height; iRow++){
			vField[iRow][iCol] = '#';
		}
	}
	//Right border
	for(int iCol=width-1; iCol>=width-thickness; iCol--){
		for(int iRow=0; iRow<height; iRow++){
			vField[iRow][iCol] = '#';
		}
	}

	//Change playing dimensions of field
	playHeight = height - thickness;
	playWidth = width - thickness;
	return;
}

//Create a new platform
void playField::addPlatform(int startRow, int startCol, int pHeight, int pWidth){
	//loop through area of platform and create it, check bounds also
	for(int iRow=startRow; iRow<startRow+pHeight && iRow>0 && iRow<height; iRow++){
		for(int iCol=startCol; iCol<startCol+pWidth && iCol>0 && iCol<width; iCol++){
			vField[iRow][iCol] = '#';
		}
	}
	return;
}

//Create a new goal
void playField::addGoal(int startRow, int startCol, int gHeight, int gWidth){
	//loop through area of platform and create it, check bounds also
	for(int iRow=startRow; iRow<startRow+gHeight && iRow>0 && iRow<height; iRow++){
		for(int iCol=startCol; iCol<startCol+gWidth && iCol>0 && iCol<width; iCol++){
			vField[iRow][iCol] = '$';
		}
	}
	return;
}

//Create a new goal
void playField::addStart(int startRow, int startCol, int sHeight, int sWidth, char playerNum){
	//loop through area of platform and create it, check bounds also
	for(int iRow=startRow; iRow<startRow+sHeight && iRow>0 && iRow<height; iRow++){
		for(int iCol=startCol; iCol<startCol+sWidth && iCol>0 && iCol<width; iCol++){
			vField[iRow][iCol] = playerNum;
		}
	}
	return;
}
