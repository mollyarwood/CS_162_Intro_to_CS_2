/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-18-16
 *Description: Creature.cpp is a class implementation file for Creature. 
 Creature is an abstract class.
 ************************************************************************/
#include "Creature.hpp"
 #include <iostream>
 using std::cout;
 using std::endl;


 /*************************************************************************
 *Function: Creature (Constructor)
 *Description: creates a creature object and sets strength to 10
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: Creature Object created
 ************************************************************************/
 Creature::Creature() {
 	d1 = new DiceMod;
 }


 /*************************************************************************
 *Function: resetStrength
 *Description: resets the strength of the Creature after combat
 *Parameters: double
 *Pre-Condition: None
 *Post-Condition: strength given new value
 ************************************************************************/
 void Creature::resetStrength(){

 	strength = strengthDefault;

 }


 /*************************************************************************
 *Function: getStrength
 *Description: shows the strength of the Creature
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: None
 ************************************************************************/
 double Creature::getStrength() const {

 	return strength;

 }


 /*************************************************************************
 *Function: setName
 *Description: sets the name of the Creature for user reference purposes
 *Parameters: string
 *Pre-Condition: None
 *Post-Condition: Creature name set
 ************************************************************************/
 void Creature::setName(string nameIn) {

 	name = nameIn;

 }


 /*************************************************************************
 *Function: getName
 *Description: shows the name of the Creature
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: None
 ************************************************************************/
 string Creature::getName() const {

 	return name;

 }

  /*************************************************************************
 *Function: Die()
 *Description: evaluates strength level to determine if creature should die
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: None
 ************************************************************************/
 bool Creature::die() {

 	bool dead = false;

 	if (strength <= 0) {
 		dead = true;
 	}

 	return dead;
 }