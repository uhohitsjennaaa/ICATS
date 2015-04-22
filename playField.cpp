#include "playField.h"

#include <algorithm>
using namespace std;

playField::playField(){
	tSize=TILE_SIZE;
	pHeight=S_HEIGHT;
	pWidth=S_WIDTH;
	height=pHeight/tSize;
	width=pWidth/tSize;

	vector <char> tempVec; //temp vector to create v2
	
	for(int iCol=0; iCol<pWidth; iCol++) tempVec.push_back(' ');
	for(int iRow=0; iRow<height; iRow++) vField.push_back(tempVec);
	
	tempVec.clear();
}

void playField::addBorder(int thickness){
	//Top border
	for(int iRow=0; iRow<thickness; iRow++)
		for(int iCol=0; iCol<width; iCol++)
			vField[iRow][iCol] = '#';

	//bottom border
	for(int iRow=height-1; iRow>=height-thickness; iRow--)
		for(int iCol=0; iCol<width; iCol++)
			vField[iRow][iCol] = '#';

	//left border
	for(int iCol=0; iCol<thickness; iCol++)
		for(int iRow=0; iRow<height; iRow++)
			vField[iRow][iCol] = '#';

	//Right border
	for(int iCol=width-1; iCol>=width-thickness; iCol--)
		for(int iRow=0; iRow<height; iRow++)
			vField[iRow][iCol] = '#';

	//Change playing dimensions of field
	playHeight = pHeight - thickness*tSize;
	playWidth = pWidth - thickness*tSize;
}

void playField::addPlatform(int startRow, int startCol, int plHeight, int plWidth){
	//loop through area of platform and create it, check bounds also
	for(int iRow=startRow; iRow<startRow+plHeight && iRow>0 && iRow<height; iRow++)
		for(int iCol=startCol; iCol<startCol+plWidth && iCol>0 && iCol<width; iCol++)
			vField[iRow][iCol] = '#';
}

void playField::addGoal(int startRow, int startCol, int gHeight, int gWidth){
	//loop through area of platform and create it, check bounds also
	for(int iRow=startRow; iRow<startRow+gHeight && iRow>0 && iRow<height; iRow++)
		for(int iCol=startCol; iCol<startCol+gWidth && iCol>0 && iCol<width; iCol++)
			vField[iRow][iCol] = '%';
}

void playField::addStart(int startRow, int startCol, int sHeight, int sWidth){
	//loop through area of platform and create it, check bounds also
	for(int iRow=startRow; iRow<startRow+sHeight && iRow>0 && iRow<height; iRow++)
		for(int iCol=startCol; iCol<startCol+sWidth && iCol>0 && iCol<width; iCol++)
			vField[iRow][iCol] = '1';
}

void playField::mirror(){
	//iterate through left half and copy to right half
	for(int iRow=0; iRow<height; iRow++)
		for(int iCol=0; iCol<width/2; iCol++){
			//Cover special symbol cases AKA goals and player spawns
 			if(vField[iRow][iCol] == '1') vField[iRow][width-1-iCol] = '2';
 			else if(vField[iRow][iCol] == '%') vField[iRow][width-1-iCol] = '$';
 			else vField[iRow][width-1-iCol] = vField[iRow][iCol];
		} //end for(int iCol=0; iCol<width-1/2; iCol++)
}

void playField::setField(){
	addGoal(8,1,6,6); //create goal

	//Add platforms surrounding goal
	addPlatform(7,1,1,7);
	addPlatform(14,1,1,7);
	addPlatform(8,7,1,1);
	addPlatform(13,7,1,1);
	
// 	//Add middle top
// 	addPlatform(2,28,10,1);
// 	addPlatform(10,24,1,4);

	addPlatform(18,21,1,9); //Add top floor
	addPlatform(23,5,1,9); //Add middle floor
	addPlatform(28,25,1,5); //Add middle floor
	addPlatform(33,15,1,8); //Add bottom floor
	
	addBorder(1); //Add border
	mirror(); //mirror
	
// 	pixels();
// 	return;
}

v2 playField::getField(){
	return vField;
}

ostream &operator<<(ostream &out,v2 &v){
	v2::iterator i;
	vector<char>::iterator j;
	
	for(i=v.begin();i!=v.end();i++){
		for(j=i->begin();j!=i->end();j++) out << *j;
		out << endl;
	} //end for(i=v.begin();i!=v.end();i++)
	
	return out;
}

void playField::print(){
	cout << vField << endl;
}