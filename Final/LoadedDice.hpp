/*************************************************************************
 *Author: Molly Arwood
 *Date: 7-2-16
 *Description: LoadedDice.hpp is a specification file
 ************************************************************************/

#ifndef LOADEDDICE_HPP
#define LOADEDDICE_HPP
#include "Dice.hpp"


class LoadedDice: public Dice {
	
	public:
		LoadedDice();
		LoadedDice(int sideCountIn);
		double* rollDie();		
};
#endif