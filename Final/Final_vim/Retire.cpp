/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Retire.cpp is a class implementation file for Retirement
  Community class
 ************************************************************************/

#include "Retire.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;


/************************************************************************
 *Function: Retire
 *Description: initiates the name variable to "Retire". pointers will be
 NULL from Space constructor calling
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: name variable and pointeres initiated
 ***********************************************************************/
 Retire::Retire() {

 	name = "Retirement Community";

 	ptr1 = NULL;
	ptr2 = NULL;
	next = NULL;
	back = NULL;
 }

 /************************************************************************
 *Function: ~Retire
 *Description: deletes any dynamicacll allocated Retire objects left
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: Retire objects deleted
 ***********************************************************************/
 Retire::~Retire() {

 }


/************************************************************************
 *Function: getName
 *Description: returns name of room
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: room name variable returned
 ***********************************************************************/
string Retire::getName() {

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
 bool Retire::validMove(Space *nwRm) {

 	bool vMove = false;
 	//Space *temp = player->getLoc();

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
 void Retire::menu() {
 	
 	cout << "Welcome to the Retirement Community! \n Let us verify that "
 		 << "You have met all the necessary requirements...\n" << endl;

 	verify();

 }


 /************************************************************************
 *Function: setPerson
 *Description: set's room's person pointer to player
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: room can now access person's money
 ***********************************************************************/
  void Retire::setPerson(Person *pIn) {
 	player1 = pIn;

 }


 /************************************************************************
 *Function: verify
 *Description: check's player's info to see if they can come in
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: player denied or accepted
 ***********************************************************************/
 void Retire::verify() {

 	//check for degree
 	if (!player1->getDegree()) {
 		cout << "\nIt looks like you did not receive a degree. Go to "
 			 << "school in order to get your degree and try again. "
 			 << endl;
 	}

 	//check for house
 	else if (!player1->getHouse()) {
 		cout << "\nIt looks like you did not buy a house. Go to "
	 		 << "your apartment in order to buy a house and try again. "
	 		 << endl;
 	}

 	//check for bonus
 	else if (!player1->getBonus()) {
 		cout << "\nIt looks like you did not receive a bonus. Go to "
	 		 << "work in order to receive a bonus and try again. "
	 		 << endl;
 	}

 	//check for $1,000
 	else if (player1->getMoney() < 1000) {
 		cout << "\nIt looks like you do not have enough money. Go to "
	 		 << "your work in order to get more money and try again. "
	 		 << endl;
 	}

 	else {
 		cout << "\nYou meet the requirements for our retirement community."
 			 << "Welcome! " << endl;
 		endGame();
 	}
 }

 /************************************************************************
 *Function: endGame()
 *Description: this function is called if all retirement reqs have been
  met. it sends a bool message to setEnd() in Person class to change the 
  end of game flag to true
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: end of game flag updated to true
 ***********************************************************************/
void Retire::endGame() {

	player1->setEnd(true);
}