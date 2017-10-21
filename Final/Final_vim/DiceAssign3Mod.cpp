/*************************************************************************
 *Author: Molly Arwood
 *Date: 7-2-16
 *Description: DiceAssign3Mod.cpp is a class implementation file 
 originally for Dice.cpp; however, altered in order to work with Creature
 combat game. 
 ************************************************************************/

#include "DiceMod.hpp"
#include <iostream>
#include <string>
#include <cstdlib>			//for rand()
#include <fstream>			//to write to a data file
using std::cout;
using std::endl;
using std::ofstream;


/*************************************************************************
 *Function: DiceMod (Constructor)
 *Description: creates & initializes Dice object with 6 sides
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: Dice object created
 ************************************************************************/
DiceMod::DiceMod() {
	setSideCount(6);
	rollCount = 1;
}


/*************************************************************************
 *Function: DiceMod (Constructor)
 *Description: creates & initializes Dice object with n sides
 *Parameters: Number of sides (int)
 *Pre-Condition: None
 *Post-Condition: Dice object created
 ************************************************************************/

DiceMod::DiceMod(int sideCountIn) {
	setSideCount(sideCountIn);
}


/*************************************************************************
 *Function: setRollCount
 *Description: sets the number of times the user would like to roll die
 *Parameters: int value
 *Pre-Condition: Dice object must exist
 *Post-Condition: rollCount variable defined
 ************************************************************************/
void DiceMod::setRollCount(int numRolls) {
	rollCount = numRolls;
}


/*************************************************************************
 *Function: setSideCount
 *Description: sets the number of sides equal to parameter input.
 *Parameters: number of sides (int)
 *Pre-Condition: None (dice can have any number of sides, even odd)
 *Post-Condition: sideCount variable defined
 ************************************************************************/

void DiceMod::setSideCount(int sideCountIn) {
	sideCount = sideCountIn;
}



/*************************************************************************
 *Function: rollDie
 *Description: generates a random number and keeps a sum
 *Parameters: Dice object
 *Pre-Condition: Dice object with assigned number of sides must exist
 *Post-Condition: summation of roll values calculated
 ************************************************************************/

double DiceMod::rollDie() {

	int temp;
	double total = 0.0;


	//roll dice to get random numbers
	for (int i = 0; i < rollCount; i++) {

		//Generate random values and store in sideValue variable
		sideValue = (rand() % sideCount) + 1;

		//cout << "You rolled a " << sideValue << ". " << endl; //display roll
		total += sideValue;
	}


	return total;
}



/*************************************************************************
 *Function: getSideCount
 *Description: returns side count 
 *Parameters: None
 *Pre-Condition: Dice object with assigned number of sides must exist
 *Post-Condition: None
 ************************************************************************/

 int DiceMod::getSideCount() {
 	return sideCount;
 }


