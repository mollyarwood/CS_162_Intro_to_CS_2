/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: HarryPotter.cpp is a class implementation file for  
 class HarryPotter. 
 ************************************************************************/

#include "HarryPotter.hpp"
#include <iostream>
 using std::cout;
 using std::endl;


/*************************************************************************
 *Function: HarryPotter (Constructor)
 *Description: initializes strength, armor, dice sides and rolls, num of
 dice, name, and catLife
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: rp specific characteristics set up
 ************************************************************************/

 HarryPotter::HarryPotter() {
 		strength = 10;
 		strengthDefault = 10;
 		armor = 0;
 		attackDice = 2;
 		defDice = 2;
 		name = "Harry Potter";
 		d1->setSideCount(6);
 		catLife = 0;
 }


/*************************************************************************
 *Function: Attack
 *Description: rolls two 6-side dice. 
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: sum of rolls saved in variable and returned
 ************************************************************************/
 double HarryPotter::attack() {

 	//set Dice's rollcount for attack
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
double HarryPotter::defense(double aRoll) {

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

	}

	if(damageRoll >=0) 
	 	strength -= damageRoll;

 	return strength;
 	
 }

 /*************************************************************************
 *Function: Die()
 *Description: evaluates strength level to determine if Harry should die.
 If catLife is >= 1, Harry will die. otherwise, he will reset. 
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: None
 ************************************************************************/
 bool HarryPotter::die() {

 	bool dead = false;

 	if (strength <= 0) {
 		dead = true;
 		if (catLife == 0) {
 			resetStrength();
 			dead = false;
 			catLife++;
 		}
 	}

 	return dead;
 }


  /*************************************************************************
 *Function: setCatLife
 *Description: sets the value of CatLife
 *Parameters: int 
 *Pre-Condition: None
 *Post-Condition: CatLife value changed
 ************************************************************************/
 void HarryPotter::setCatLife(int n) {

 	catLife = n;

 }
