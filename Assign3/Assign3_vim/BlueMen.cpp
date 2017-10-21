/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: BlueMen.cpp is a class implementation file for  
 class BlueMen. 
 ************************************************************************/

#include "BlueMen.hpp"
#include <iostream>
 using std::cout;
 using std::endl;


/*************************************************************************
 *Function: BlueMen (Constructor)
 *Description: initializes strength, armor, dice sides and rolls, second
 dice object, and name
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: rp specific characteristics set up
 ************************************************************************/

 BlueMen::BlueMen() {
 		strength = 12;
 		strengthDefault = 12;
 		armor = 3;
 		attackDice = 2;
 		defDice = 3;
 		name = "BlueMen";
 		d1->setSideCount(6);
 		d2 = new Dice;
 		d2->setSideCount(10);
 }


/*************************************************************************
 *Function: Attack
 *Description: rolls two 10-side dice. 
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: sum of rolls saved in variable and returned
 ************************************************************************/
 double BlueMen::attack() {

 	//set Dice's rollcount for attack
 	d2->setRollCount(attackDice);

 	attackRoll = 0;

	attackRoll = d2->rollDie();
	cout << "Sum of roll: " << attackRoll << endl;

 	return attackRoll;

 }



 /*************************************************************************
 *Function: Defense
 *Description: If Medusa does not turn you to stone, rolls three 6-sided
 die. For every 4 points lost in strength, one die is lost.
 *Parameters: int attackRoll
 *Pre-Condition: None
 *Post-Condition: character's strength value is unchanged or deacreased
 ************************************************************************/
double BlueMen::defense(double aRoll) {
	
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

	 	if(damageRoll >=0) {
	 		strength -= damageRoll;

	 		if (strength > (strengthDefault - 4))
	 			defDice = defDice;
	 		else if (strength > (strengthDefault - 8))
	 			defDice = 2;
	 		else
	 			defDice = 1;
	 	}
	}


 	return strength;
 	
 }