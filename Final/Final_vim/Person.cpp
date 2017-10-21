/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Person.cpp is a class implementation file for the Person
  class. A player will be a person.
 ************************************************************************/

#include "Person.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


/************************************************************************
*Function: Person
*Description: initiates player data and name
*Parameters: None
*Pre-Condition: game structure must be set up
*Post-Condition: player data and name initiated
***********************************************************************/
Person::Person(string nameIn) {

	pName = nameIn;

	money = 2000;
	studentLoans = 0;
	kidsNum = 0;
	house = false;
	degree = false;
	physDeg = false;
	end = false;
	marriage = false;

	for (int i = 0; i < 2; i++)
		container[i] = "0";


}

/************************************************************************
*Function: Person
*Description: initiates player data 
*Parameters: None
*Pre-Condition: game structure must be set up
*Post-Condition: player data initiated
***********************************************************************/
Person::Person() {

	pName = "Player1";

	money = 2000;
	studentLoans = 0;
	kidsNum = 0;
	house = false;
	degree = false;
	physDeg = false;
	end = false;
	marriage = false;

	for (int i = 0; i < 2; i++)
		container[i] = "0";

}

/************************************************************************
*Function: ~Person
*Description: 
*Parameters: None
*Pre-Condition: None
*Post-Condition: 
***********************************************************************/
Person::~Person() {
}


/************************************************************************
*Function: getName
*Description: retrieves player's name
*Parameters: None
*Pre-Condition: None
*Post-Condition: name sent to function call
***********************************************************************/
string Person::getName() {
	return pName;
}


/************************************************************************
*Function: getStudentLoans
*Description: returns the studenloans owed of player
*Parameters: None
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
double Person::getStudentLoans() {
	return studentLoans;
}



/************************************************************************
*Function: addStudentLoans
*Description: adds to the player's studentLoans account
*Parameters: double
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
void Person::addStudentLoans(double s) {
	studentLoans += s;
}


/************************************************************************
*Function: getMoney
*Description: returns the Money of player
*Parameters: None
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
double Person::getMoney() {
	return money;
}


/************************************************************************
*Function: addMoney
*Description: adds or subtracts from money pot
*Parameters: double
*Pre-Condition: None
*Post-Condition: money reduced or increased
***********************************************************************/
void Person::addMoney(double m) {

	money += m;
}



/************************************************************************
*Function: getHouse
*Description: returns whether the player has bought a house or not
*Parameters: None
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
bool Person::getHouse() {
	return house;
}


/************************************************************************
*Function: setHouse
*Description: updates status if the player has bought a house 
*Parameters: bool
*Pre-Condition: None
*Post-Condition: house variable updated
***********************************************************************/
void Person::setHouse(bool b) {
	house = b;
}



/************************************************************************
*Function: getDegree
*Description: returns whether the person has earned their degree or not
*Parameters: None
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
bool Person::getDegree() {
	return degree;
}


/************************************************************************
*Function: setDegree
*Description: sets whether the person has earned their degree or not
*Parameters: bool
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
void Person::setDegree(bool d) {
	degree = d;
}


/************************************************************************
*Function: getPhysDeg
*Description: returns whether the person has picked up their physical
degree or not
*Parameters: None
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
bool Person::getPhysDeg() {
	return physDeg;
}



/************************************************************************
*Function: setPhysDeg
*Description: returns whether the person is able to pick up their physical
degree or not
*Parameters: None
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
void Person::setPhysDeg(bool pd) {
	physDeg = pd;
}



/************************************************************************
*Function: addContainer
*Description: adds item to container
*Parameters: string;
*Pre-Condition: None
*Post-Condition: item added to person's container
***********************************************************************/
void Person::addContainer(string &s) {

	for (int i = 0; i < 2; i++) {

		if (container[i] == "0") 
			container[i] = s;

		//cout << "cointainer item " << i << ": " << container[i] << endl;
	}
}



/************************************************************************
*Function: getContainer
*Description: returns container pointer to function call
*Parameters: none
*Pre-Condition: None
*Post-Condition: pointer to container returned
***********************************************************************/
string* Person::getContainer() {

	return container;
}


/************************************************************************
*Function: setBonus
*Description: sets bonus to true if boss lost in battle
*Parameters: none
*Pre-Condition: None
*Post-Condition: bonus variable potentially changed
***********************************************************************/
void Person::setBonus(bool in) {
	bonus = in;
}


/************************************************************************
*Function: getBonus
*Description: returns whether or not player got bonus
*Parameters: none
*Pre-Condition: None
*Post-Condition: None
***********************************************************************/
bool Person::getBonus() {

	return bonus;
}

 /************************************************************************
 *Function: setEnd
 *Description: sets the flag for end of game
 *Parameters: bool that comes from Retirement Community
 *Pre-Condition: 
 *Post-Condition: end flag is updated
 ***********************************************************************/
 void Person::setEnd(bool e) {
 	end = e;
 }


 /************************************************************************
 *Function: getEnd
 *Description: returns the flag for end of game
 *Parameters: None
 *Pre-Condition: 
 *Post-Condition: end flag is returned
 ***********************************************************************/
 bool Person::getEnd() {
 	return end;
 }


  /************************************************************************
 *Function: setMarriage
 *Description: sets the marriage bool 
 *Parameters: bool that comes from Retirement Community
 *Pre-Condition: 
 *Post-Condition: marriage is updated
 ***********************************************************************/
 void Person::setMarriage(bool e) {
 	marriage = e;
 }


 /************************************************************************
 *Function: getEnd
 *Description: returns the flag for end of game
 *Parameters: None
 *Pre-Condition: 
 *Post-Condition: end flag is returned
 ***********************************************************************/
 bool Person::getMarriage() {
 	return marriage;
 }