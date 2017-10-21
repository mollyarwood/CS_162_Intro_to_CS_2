/*************************************************************************
 *Author: Molly Arwood
 *Date: 7-2-16
 *Description: DiceAssign3Mod.cpp is a class implementation file 
 originally for Dice.cpp; however, altered in order to work with Creature
 combat game. 
 ************************************************************************/

#include "Dice.hpp"
#include <iostream>
#include <string>
#include <cstdlib>			//for rand()
#include <fstream>			//to write to a data file
using std::cout;
using std::endl;
using std::ofstream;


/*************************************************************************
 *Function: Dice (Constructor)
 *Description: creates & initializes Dice object with 6 sides
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: Dice object created
 ************************************************************************/
Dice::Dice() {
	setSideCount(6);
}


/*************************************************************************
 *Function: Dice (Constructor)
 *Description: creates & initializes Dice object with n sides
 *Parameters: Number of sides (int)
 *Pre-Condition: None
 *Post-Condition: Dice object created
 ************************************************************************/

Dice::Dice(int sideCountIn) {
	setSideCount(sideCountIn);
}


/*************************************************************************
 *Function: setRollCount
 *Description: sets the number of times the user would like to roll die
 *Parameters: int value
 *Pre-Condition: Dice object must exist
 *Post-Condition: rollCount variable defined
 ************************************************************************/
void Dice::setRollCount(int numRolls) {
	rollCount = numRolls;
}


/*************************************************************************
 *Function: setSideCount
 *Description: sets the number of sides equal to parameter input.
 *Parameters: number of sides (int)
 *Pre-Condition: None (dice can have any number of sides, even odd)
 *Post-Condition: sideCount variable defined
 ************************************************************************/

void Dice::setSideCount(int sideCountIn) {
	sideCount = sideCountIn;
}



/*************************************************************************
 *Function: rollDie
 *Description: generates a random number and keeps a sum
 *Parameters: Dice object
 *Pre-Condition: Dice object with assigned number of sides must exist
 *Post-Condition: summation of roll values calculated
 ************************************************************************/

double Dice::rollDie() {

	int temp;
	double total = 0.0;


	//roll dice to get random numbers
	for (int i = 0; i < rollCount; i++) {

		//Generate random values and store in sideValue variable
		sideValue = (rand() % sideCount) + 1;

		cout << "You rolled a " << sideValue << ". " << endl; //display roll
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

 int Dice::getSideCount() {
 	return sideCount;
 }


