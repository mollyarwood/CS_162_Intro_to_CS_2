/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-18-16
 *Description: Gollum.cpp is a class implementation file for  
 class Gollum. 
 ************************************************************************/

#include "Gollum.hpp"
#include <iostream>
#include <cstdlib>
 using std::cout;
 using std::endl;


/*************************************************************************
 *Function: Gollum (Constructor)
 *Description: initializes strength, armor, dice sides and rolls, number
 of dice, and name
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: rp specific characteristics set up
 ************************************************************************/

 Gollum::Gollum() {
 		strength = 8;
 		strengthDefault = 8;
 		armor = 3;
 		attackDice = 1;
 		defDice = 1;
 		name = "Gollum";
 		d1->setSideCount(6);
 }


/*************************************************************************
 *Function: Attack
 *Description: rolls one 6-side dice. However, 5% of the time, rolls three
 6-sided dice.
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: sum of rolls saved in variable and returned
 ************************************************************************/
 double Gollum::attack() {

 	attackRoll = 0;
 	int ring = 13;
 	int ringRoll;

 	//Generate random number between 1-20
 	ringRoll = (rand() % 20) + 1;

 	if (ringRoll == ring) {
 		attackDice = 3;
 	}

 	//set Dice's rollcount for attack
 	d1->setRollCount(attackDice);

	attackRoll = d1->rollDie();
	cout << "Sum of roll: " << attackRoll << endl;
	attackDice = 1;

 	return attackRoll;

 }



 /*************************************************************************
 *Function: Defense
 *Description: if Medusa does not turn you to stone, roll the specified
 defense dice and apply any damage to strength
 *Parameters: int attackRoll
 *Pre-Condition: None
 *Post-Condition: character's strength value is unchanged or deacreased
 ************************************************************************/
double Gollum::defense(double aRoll) {

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