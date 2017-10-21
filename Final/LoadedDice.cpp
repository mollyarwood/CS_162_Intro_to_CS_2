/*************************************************************************
 *Author: Molly Arwood
 *Date: 7-2-16
 *Description: LoadedDice.cpp is an implementation file
 ************************************************************************/

#include "LoadedDice.hpp"
#include <cstdlib>
#include <iostream>
using std::cout;
using std::endl;

/*************************************************************************
 *Function: LoadedDice (Constructor)
 *Description: creates a LoadedDice object and sets sides equal to 6.
 *Parameters: None
 *Pre-Condition: 
 *Post-Condition: LoadedDice Object w/ 6 sides created
 ************************************************************************/
LoadedDice::LoadedDice() {
	setSideCount(6);
}


/*************************************************************************
 *Function: LoadedDice (Constructor)
 *Description: creates a LoadedDice object with n sides.
 *Parameters: int sideCountIn
 *Pre-Condition: None
 *Post-Condition: LoadedDice Object w/ n sides created
 ************************************************************************/

LoadedDice::LoadedDice(int sideCountIn) {
	setSideCount(sideCountIn);
}


/*************************************************************************
 *Function: rollDie (overloaded)
 *Description: rolls loaded die: if rolled value is not equal to the 
  *number of sides, there is a 5% chance that the int 1 will be added to
  *the value of the roll.
 *Parameters: None
 *Pre-Condition: LoadedDice Object exists
 *Post-Condition: Summation of values of rolls
 ************************************************************************/

double* LoadedDice::rollDie() {

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

		//Increase sideValule if 5%
		if (sideValue != sideCount) {
			int percent = rand() % 100 + 1;	// Random num btwn 1 and 100
			if (percent <= 5) 
				sideValue += 1;
		}

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



	// for (int i = 0; i < rollCount; i++) {

	// 	//Generate random values and store in sideValue variable
	// 	sideValue = (rand() % sideCount) + 1;	

	// 	//Increase sideValule if 5%
	// 	if (sideValue != sideCount) {
	// 		int percent = rand() % 100 + 1;	// Random num btwn 1 and 100
	// 		if (percent <= 5) 
	// 			sideValue += 1;
	// 	}
		
	// 	cout << "You rolled a " << sideValue << ". " << endl;
	// 	total += sideValue;


	// }


