/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: House.cpp is a class implementation file for House's
  Office class
 ************************************************************************/

#include "House.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


/************************************************************************
 *Function: House
 *Description: initiates the name variable to "House". pointers will be
 NULL from Space constructor calling
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: name variable and pointeres initiated
 ***********************************************************************/
 House::House() {

 	name = "House";

 	ptr1 = NULL;
	ptr2 = NULL;
	next = NULL;
	back = NULL;
	visitCount = 4;
 }

 /************************************************************************
 *Function: ~House
 *Description: deletes any dynamicacll allocated House objects left
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: House objects deleted
 ***********************************************************************/
 House::~House() {

 }


/************************************************************************
 *Function: getName
 *Description: returns name of room
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: room name variable returned
 ***********************************************************************/
string House::getName() {

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
 bool House::validMove(Space *nwRm) {

 	bool vMove = false;


 	if (this->getName() == nwRm->getName()) {
 		cout << "Re-entering current room. " << endl;
 		vMove = true;
 	}

 	else if (this->ptr1 == nwRm || this->ptr2 == nwRm) {

 		cout << "You are now going to: " << nwRm->getName() << endl
 			 << endl;
 		vMove = true;

 	}

 	else if (this->next == nwRm || this->back == nwRm) {

 		cout << "You are now going to: " << nwRm->getName() << endl
 			 << endl;
 		vMove = true;

 	}

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
 void House::menu() {

 	int input;

 	do {

 		//string name = player1->getName();

	 	cout << "You are at your house. Choose an action: "
	 		 << "\nEnter 1 to: Cook Dinner "
	 		 << "\nEnter 2 to: Pick up newspaper to read "
	 		 << "\nEnter 3 to: leave";
	 	cin >> input;

	 	if (input == 1)
	 		cook();

	 	if (input == 2)
	 		newsPaper();

	} while (input != 3);	

 }

 /************************************************************************
 *Function: setPerson
 *Description: set's room's person pointer to player
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: room can now access person's money
 ***********************************************************************/
 void House::setPerson(Person *pIn) {
 	player1 = pIn;

 }


 /************************************************************************
 *Function: cook()
 *Description: cook rolls dice to decide person's fate while cooking
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: various actions performed by player
 ***********************************************************************/
 void House::cook() {

 	die1 = new DiceMod;	
 	die1->setSideCount(3);
 	double result;
 	int result2;

 	//roll die and get result
 	result = die1->rollDie();
 	result2 = static_cast <int> (result);

 	switch (result2) {
 	
 		case 1: 
	 		cout << "you are cooking spaghetti when suddenly the sauce "
	 		 << "explodes everywhere! \nYou go to the cleaning supply "
	 		 << "closet to get paper towels, but while you are in the "
	 		 << "closet, you find $5! This has been added to your account "
	 		 << endl;
	 		player1->addMoney(5);
	 		break;

	 	case 2:
	 		cout << "you go to the pantry and realize you are out of "
	 			 << "food. you call pizza delivery instead. $10 has been "
	 			 << "removed from your account. " << endl;
	 		player1->addMoney(-10);
	 		break;

	 	case 3:
	 		cout << "your spaghetti turned out perfectly! you eat and "
	 			 << "enjoy the moment of rest. " << endl;
	 		 break;
	} 
 }


 /************************************************************************
 *Function: newsPaper()
 *Description: cook rolls dice to decide person's fate while cooking
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: various actions performed by player
 ***********************************************************************/
void House::newsPaper() {

	char input;
	string *s = new string;
	string np = "newspaper";
	visitCount++;

	cout << "You pick up the newspaper (it's been added to your container"
		 << ") to read. There's a classified add to sell your bone plasma"
	 	 << " for $300. You can only do so every 4th visit to your house. "
	 	 << "Would you like to do it? (Y/N) " << endl;
	cin >> input;

	//add newspaper to items
	s = player1->getContainer();
	for (int i = 0; i < 2; i++){
		if (s[i] == "newsPaper")
			cout << "newsPaper already in possession. " << endl;
		else
			player1->addContainer(np);
	}


	//if player wants to dontate plasma
	if (input == 'Y' || input == 'y'){

		if (visitCount <= 3) {
			cout << "Sorry, you need " << (4 - visitCount) << " more "
				 << "visits in order to donate again. \n" << endl;
		}

		else {
			cout << "Great! $300 has been added to your account for your "
				 << "donation. \n" << endl;
			player1->addMoney(300);
			visitCount = 0;
		}
	}
	else 
		cout << "You have decided not to donate. " << endl;

}

