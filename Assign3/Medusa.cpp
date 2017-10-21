/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-18-16
 *Description: Medusa.cpp is a class implementation file for subclass
 Medusa 
 ************************************************************************/

#include "Medusa.hpp"
#include <iostream>
 using std::cout;
 using std::endl;


/*************************************************************************
 *Function: Dice (Constructor)
 *Description: creates & initializes Dice object with n sides
 *Parameters: Number of sides (int)
 *Pre-Condition: None
 *Post-Condition: Dice object created
 ************************************************************************/

 Medusa::Medusa() {
 		strength = 8;
 		strengthDefault = 8;
 		armor = 3;
 		attackDice = 2;
 		defDice = 1;
 		name = "Medusa";
 		d1->setSideCount(6);
 }


/*************************************************************************
 *Function: Attack
 *Description: rolls two 6-sided dice in order to produce an attack 
 number. 
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: sum of rolls saved in variable and returned
 ************************************************************************/
 double Medusa::attack() {

 	//set Dice's rollcount to 2 for attack
 	d1->setRollCount(attackDice);

 	attackRoll = 0;
 	double roll = 0;

 	//roll dice. trigger end game if roll = 12
	roll = d1->rollDie();
	if (roll == 12) {
		roll = 550;
	}

	attackRoll += roll;
	cout << "Sum of roll: " << roll << endl;
 

 	return attackRoll;

 }



 /*************************************************************************
 *Function: Defense
 *Description: if other Medusa does not turn you to stone, roll the 
 specified defense dice and apply any damage to strength
 *Parameters: int attackRoll
 *Pre-Condition: None
 *Post-Condition: 
 ************************************************************************/
double Medusa::defense(double aRoll) {

	if (aRoll == 550) {
		strength = -1;
		cout << "Medusa turned you to stone. Game Over" << endl;
	}
	else {
		//set Dice's rollcount to 1 for defense
	 	d1->setRollCount(defDice);

	 	damageRoll = aRoll;
	 	double roll = 0;

	 	//roll die for defense and subtract from attack value (damageRoll)
		roll = d1->rollDie();
		damageRoll -= roll;
		cout << "damageRoll: " << damageRoll << endl;

	 	//subtract armor from total damage and apply to strength
	 	damageRoll -= armor;
	 	 cout << "damageRoll - armor: " << damageRoll << endl;

	 	if(damageRoll >=0) 
	 		strength -= damageRoll;
	}


 	return strength;
 	
 }