/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-18-16
 *Description: ReptilePeople.cpp is a class implementation file for  
 class ReptilePeople. 
 ************************************************************************/

#include "ReptilePeople.hpp"
#include <iostream>
 using std::cout;
 using std::endl;


/*************************************************************************
 *Function: ReptilePeople (Constructor)
 *Description: initializes rp's strength, armor, and dice sides and rolls
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: rp specific characteristics set up
 ************************************************************************/

 ReptilePeople::ReptilePeople() {
 		strength = 18;
 		strengthDefault = 18;
 		armor = 7;
 		attackDice = 3;
 		defDice = 1;
 		name = "Reptile People";
 		d1->setSideCount(6);
 }


/*************************************************************************
 *Function: Attack
 *Description: rolls three 6-sided dice in order to produce an attack 
 number. 
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: sum of rolls saved in variable and returned
 ************************************************************************/
 double ReptilePeople::attack() {

 	//set Dice's rollcount to 3 for attack
 	d1->setRollCount(attackDice);

 	attackRoll = 0;

	attackRoll = d1->rollDie();
	cout << "Sum of roll: " << attackRoll << endl;

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
double ReptilePeople::defense(double aRoll) {

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