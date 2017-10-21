/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Apartment.cpp is a class implementation file for Apartment
  class
 ************************************************************************/

#include "Apartment.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


/************************************************************************
 *Function: Apartment
 *Description: initiates the name variable to "Apartment". pointers will be
 NULL from Space constructor calling
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: name variable and pointeres initiated
 ***********************************************************************/
 Apartment::Apartment() {

 	name = "Apartment";
 	ptr1 = NULL;
	ptr2 = NULL;
	next = NULL;
	back = NULL;
 }

 /************************************************************************
 *Function: ~Apartment
 *Description: deletes any dynamicacll allocated Apartment objects left
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: Apartment objects deleted
 ***********************************************************************/
 Apartment::~Apartment() {

 }


/************************************************************************
 *Function: getName
 *Description: returns name of room
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: room name variable returned
 ***********************************************************************/
string Apartment::getName() {

	return name;
}

/************************************************************************
 *Function: validMove
 *Description: returns true if you can get to that room from the current
 location
 *Parameters: Space pointer
 *Pre-Condition: Person must be in a room
 *Post-Condition: true or false returned
 ***********************************************************************/
 bool Apartment::validMove(Space *nwRm) {

 	bool vMove = false;

 	//if room is same name as current spot
 	if (this->getName() == nwRm->getName()) {
 		cout << "Re-entering current room. " << endl;
 		vMove = true;
 	}

 	//if room is linked to current spot via "other" pointers
 	else if (this->ptr1 == nwRm || this->ptr2 == nwRm) {

 		cout << "You are now going to: " << nwRm->getName() << endl
 			 << endl;
 		vMove = true;
 	}

 	//if room is doubly linked to current spot
 	else if (this->next == nwRm || this->back == nwRm) {

 		cout << "You are now going to: " << nwRm->getName() << endl
 			 << endl;
 		vMove = true;
 	}

 	//room is not linked to current spot
 	else {
 		cout << "That move is not legal. pick again. " << endl;
 		vMove = false;
 	}

 	return vMove;

 }

 /************************************************************************
 *Function: menu
 *Description: display's room's menu of options of tasks
 *Parameters: none
 *Pre-Condition: Person must be in a room
 *Post-Condition: choice interpreted and sent to appropriate function
 ***********************************************************************/
 void Apartment::menu() {

 	char house;

 	cout << "\nYou are in your apartment. Would you like to try to find "
 		 << "a house? (Y/N)";
	cin.ignore();
	house = cin.get();


	if (house == 'Y' || house == 'y') {
		if (player1->getHouse())
			cout << "\nYou already purchased a house" << endl;
		else 
			rollHouseDie();
	}

	else {
		if (player1->getHouse())
			cout << "\nGood. You already purchased a house" << endl;
		else {
			cout << "You do not want to buy this house. \nCome back "
				 << "When you are ready to buy a house." << endl;
		}
	}

 }

 /************************************************************************
 *Function: setPerson
 *Description: set's room's person pointer to player
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: room can now access person's money
 ***********************************************************************/
 void Apartment::setPerson(Person *pIn) {
 	player1 = pIn;

 }


 /************************************************************************
 *Function: setPerson
 *Description: set's room's person pointer to player
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: room can now access person's money
 ***********************************************************************/
void Apartment::rollHouseDie() {
 
 	string houseType;
 	double cost;
 	char buy;
 	bool bought = false;
 	die1 = new DiceMod;	
 	die1->setSideCount(3);
 	double result;
 	int result2;


 	/*********************************************************************
 	 *roll dice and look at results
 	 ********************************************************************/
 	result = die1->rollDie();
 	result2 = static_cast <int> (result);

 	//prompt user to continue
 	cout << "We have selected 1 of 3 options for you."
 		 << "\nPress Enter to see your house type. ";
 	cin.ignore();
 	cin.get();

 	switch (result2) {
 		case 1:
 			cout << "\n\n House Type: Trailer \n Cost: $800 "
 				 << "\n Bedrooms: 2 \n\n Would you like to buy this "
 				 << "house? (Y/N)";
 			buy = cin.get();
 			houseType = "Trailer";
 			cost = -800;
 			break;

 		case 2:
 		 	cout << "\n\n House Type: Split Level \n Cost: $4,000 "
 				 << "\n Bedrooms: 3 \n\n Would you like to buy this "
 				 << "house? (Y/N)\n";
 			buy = cin.get();
 			houseType = "Split Level";
 			cost = -4000;
 			break;	

 		case 3:
 		 	cout << "\n\n House Type: Mansion \n Cost: $10,000 "
 				 << "\n Bedrooms: 3 \n\n Would you like to buy this "
 				 << "house? (Y/N)\n";
 			buy = cin.get();
 			houseType = "Mansion";
 			cost = -10000;
 			break;	
 	}

 	//if user would like to buy house, return true and deduct money
 	if (buy == 'Y' || buy == 'y') {
 		cout << "Congratulations! You just bought a " << houseType
 			 << "! \n You will no longer be able to return to your "
 			 << "\napartment. Go to your house instead. Please go " 
 			 << "\n to the school before continuing. " << endl << endl;
 		bought = true;
 		player1->addMoney(cost);
 		player1->setHouse(bought);

 	}

 	else {
 		cout << "\n You do not want to buy this house. Visit your "
 			 << "apartment again to roll for a different house. "
 			 << endl << endl;
 	}

 }