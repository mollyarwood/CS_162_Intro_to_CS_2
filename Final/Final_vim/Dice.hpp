/*************************************************************************
 *Author: Molly Arwood
 *Date: 7-2-16
 *Description: Dice.hpp is a class specification file
 ************************************************************************/

#ifndef DICE_HPP
#define DICE_HPP

class Dice {
	
	protected:
		int sideCount;			//to hold number of sides
		int sideValue;			//to hold value rolled
		int rollCount;			//to hold number of times to roll
		double *pData;			//pointer for dynamic array for analysis
		double mean;
		int mode;
		int median;
		double *dataAnswers;
		double *sideArray;
	
	public:
		Dice();
		Dice(int);
		void setRollCount(int);
		void setSideCount(int);
		double* rollDie();

		//functions used for testing purposes.
		int getSideCount();

};

#endif 