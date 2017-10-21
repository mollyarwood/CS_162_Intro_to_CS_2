/*************************************************************************
 *Author: Molly Arwood
 *Date: 7-2-16
 *Description: Dice.cpp is a class implementation file
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

double* Dice::rollDie() {

	int temp;
	double total = 0.0;
	double highestNum = 0.0;
	double highestOccur = 0.0;
	pData = new double[rollCount];		//to hold values of rolls
	sideArray = new double[sideCount];	//to hold mode frequqncies
	dataAnswers = new double[4];		//to hold statistics


	//prepopulate sideArray with zeros
	for (int i = 0; i < sideCount; i++) {
		sideArray[i] = 0;
	}


	//roll dice to get random numbers
	for (int i = 0; i < rollCount; i++) {

		//Generate random values and store in sideValue variable
		sideValue = (rand() % sideCount) + 1;

		pData[i] = sideValue;	//gather data for array
		cout << "You rolled a " << sideValue << ". " << endl; //display roll
		total += sideValue;
	
		//find mode by incrementing location by 1
		sideArray[sideValue] +=1;
	}


	//find value that occured the most (mode)
	for (int i = 0; i < sideCount; i++) {
		if (sideArray[i] >= highestOccur) {
			highestOccur  = sideArray[i];
			highestNum = i;
		}
	}


	//find the median
	for (int i = 0; i < sizeof(pData); i++) {
		for (int j = 1; j < sizeof(pData) - 1; j++) {
			if (pData[j] < pData[i]) {
				temp = pData[i];
				pData[i] = pData[j];
				pData[j] = temp;
			}
		}
	}

	median = pData[ sizeof(pData)/2 ];


	//store data in an array to return
	dataAnswers[0] = total;
	dataAnswers[1] = total/rollCount;
	dataAnswers[2] = median;
	dataAnswers[3] = highestNum;

	return dataAnswers;
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


