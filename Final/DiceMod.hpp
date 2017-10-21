/*************************************************************************
 *Author: Molly Arwood
 *Date: 7-2-16
 *Description: Dice.hpp is a class specification file
 ************************************************************************/

#ifndef DICEMOD_HPP
#define DICEMOD_HPP

class DiceMod {
	
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
		DiceMod();
		DiceMod(int);
		void setRollCount(int);
		void setSideCount(int);
		double rollDie();

		//functions used for testing purposes.
		int getSideCount();

};

#endif 