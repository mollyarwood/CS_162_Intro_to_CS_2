/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-18-16
 *Description: Creature.hpp is a class specification file for Creature. 
 Creature is an abstract class.
 ************************************************************************/


 #ifndef CREATURE_HPP
 #define CREATURE_HPP

 #include "Dice.hpp"
 #include <string>
 using std::string;

 class Creature {

	 protected:
	 	double attackRoll;
	 	double damageRoll;
	 	double strength;
	 	double strengthDefault;
	 	int armor;
	 	int attackDice;
	 	int defDice;
	 	string name;
	 	Dice *d1;


	 public:
	 	Creature();
	 	virtual double attack() = 0;
	 	virtual double defense(double) = 0;
	 	void resetStrength();
	 	double getStrength() const;
	 	void setName(string);
	 	string getName() const;
	 	virtual bool die();

 };
 #endif