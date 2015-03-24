#include <iostream>
#include <vector>
#include "field.h"
using namespace std;

int main(){
	playField test(40,60);

	test.addPlatform(10,10,2,5);
	test.addPlatform(10,50,2,20);

	test.addGoal(5,5,5,5);
	test.addGoal(30,50,5,5);

	test.addBorder(2);

	test.print();

	return 0;
}
