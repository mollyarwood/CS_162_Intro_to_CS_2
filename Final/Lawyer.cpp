/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Lawyer.cpp is a class implementation file for Lawyer's
  Office class
 ************************************************************************/

#include "Lawyer.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


/************************************************************************
 *Function: Lawyer
 *Description: initiates the name variable to "Lawyer". pointers will be
 NULL from Space constructor calling
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: name variable and pointeres initiated
 ***********************************************************************/
 Lawyer::Lawyer() {

 	name = "Lawyer's Office";

 	ptr1 = NULL;
	ptr2 = NULL;
	next = NULL;
	back = NULL;
 }

 /************************************************************************
 *Function: ~Lawyer
 *Description: deletes any dynamicacll allocated Lawyer objects left
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: Lawyer objects deleted
 ***********************************************************************/
 Lawyer::~Lawyer() {

 }


/************************************************************************
 *Function: getName
 *Description: returns name of room
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: room name variable returned
 ***********************************************************************/
string Lawyer::getName() {

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
 bool Lawyer::validMove(Space *nwRm) {

 	bool vMove = false;
 	//Space *temp = player->getLoc();

 	if (this->getName() == nwRm->getName()) {
 		cout << "Re-entering current room. " << endl;
 		vMove = true;
 	}

 	else if (this->ptr1 == nwRm || this->ptr2 == nwRm) {

 		cout << "You are now going to: " << nwRm->getName() << endl;
 		vMove = true;
 		//player->setLoc(nwRm);
 	}

 	else if (this->next == nwRm || this->back == nwRm) {

 		cout << "You are now going to: " << nwRm->getName() << endl;
 		vMove = true;
 		//player->setLoc(nwRm);
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
 void Lawyer::menu() {
 	int input;

 	do {
	 	cout << "\nYou are at the Lawyer's Office. Please enter a choice: "
	 		 << "\nEnter 1 to: get Married "
	 		 << "\nEnter 2 to: fight to remove your student loans"
	 		 << "\nEnter 3 to: leave" << endl;
	 	cin >> input;

	 	if (input == 1)
	 		marriage();

	 	if (input == 2)
	 		loanFight();

	} while (input != 3);
 	
 }

 /************************************************************************
 *Function: setPerson
 *Description: set's room's person pointer to player
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: room can now access person's money
 ***********************************************************************/
 void Lawyer::setPerson(Person *pIn) {
 	player1 = pIn;

 }


 /************************************************************************
 *Function: marriage
 *Description: set's player's marriage bool to true
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: marriage bool = true
 ***********************************************************************/
 void Lawyer::marriage() {

 	cout << "\nYou have been with your partner for several years now and "
 		 << "\nare ready to make the plunge! Congrats! You are now "
 		 << " married. " << endl;

 	player1->setMarriage(true);


 }


  /************************************************************************
 *Function: loanFight
 *Description: player battles to see if they can be free of debt
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: studentLoan may or may not be zero
 ***********************************************************************/
 void Lawyer::loanFight() {

 	//intro 
 	cout << "\nYou will battle the computer. if you win, your debt will be "
 		 << "\n erased. It costs $50 to play." << endl << endl;

	cout << "Press Enter to Begin Your Fight. " << endl << endl;
	cin.ignore();
	cin.get();


	player1->addMoney(-50);

	//declare necessary variables
 	you = new BlueMenYou;
 	loanShark = new ReptilePeople;
 	double attackRoll;
 	bool dead;
 	bool youdied = false;
 	double lifeStrength;


	/*********************************************************************
	 *combat until one ;pses the argument
	 ********************************************************************/
	do {

		//show strengths before each round of attacks/defenses
		cout << "Strength of " << you->getName() << ": "
			 << you->getStrength() << endl;
		cout << "Strength of " << loanShark->getName() << ": "
			 << loanShark->getStrength() << endl;	 



		//attack and defense moves of Creature a on b
		cout << loanShark->getName() << "'s attack: " << endl;
		attackRoll = loanShark->attack();

		cout << you->getName() << "'s defense: " << endl;
		lifeStrength = you->defense(attackRoll);
		cout << you->getName() << "'s strength after attack: " 
			 << you->getStrength() << endl << endl;

		//determine if Creature b is killed
		dead = you->die();

		if (dead) {
			cout << you->getName() << " lost the fight. Your debt "
				 << " is not erased. Combat End."
				 << endl;
			youdied = true;
		}

		else {

			//attack and defense moves of Creature b on a
			cout << you->getName() << "'s attack turn: " << endl;
			attackRoll = you->attack();

			cout << loanShark->getName() << "'s defense turn: " << endl;
			lifeStrength = loanShark->defense(attackRoll);
			cout << loanShark->getName() << "'s strength after attack: " 
				 << loanShark->getStrength() << endl << endl << endl;


 		//determine if Creature a is killed
			dead = loanShark->die();

			if (dead) {
				cout << loanShark->getName() << " lost the fight. Your "
					 << "debt is erased! Combat End."
					 << endl;
				youdied = false;
			}
		}


	} while (!dead);

	cout << endl;
	if (youdied) 
		cout << "\nSorry, you do not get to erase your debts. " << endl;
	
	else {
		double mon;
		cout << "Congrats! you're student loans are now gone " << endl;
		mon = player1->getStudentLoans();
		player1->addStudentLoans(-mon);
	}


 }