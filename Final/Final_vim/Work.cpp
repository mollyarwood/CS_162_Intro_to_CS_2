/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Work.cpp is a class implementation file for Work
  class
 ************************************************************************/

#include "Work.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


/************************************************************************
 *Function: Work
 *Description: initiates the name variable to "Work". pointers will be
 NULL from Space constructor calling
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: name variable and pointeres initiated
 ***********************************************************************/
 Work::Work() {

 	name = "Work";

 	ptr1 = NULL;
	ptr2 = NULL;
	next = NULL;
	back = NULL;

	therapyMoney = -1000;
	bonus = 200;
 }

 /************************************************************************
 *Function: ~Work
 *Description: deletes any dynamicacll allocated Work objects left
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: Work objects deleted
 ***********************************************************************/
 Work::~Work() {
 }


/************************************************************************
 *Function: getName
 *Description: returns name of room
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: room name variable returned
 ***********************************************************************/
string Work::getName() {

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
 bool Work::validMove(Space *nwRm) {

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
 void Work::menu() {

 	bool payMoney;
 	double result;
 	die1 = new DiceMod;	

 	/*********************************************************************
 	 *roll die to see if you get a pay day
 	 ********************************************************************/
 	result = die1->rollDie();
 	int input;

 	//randome payday roll
 	if (result == 3.0){
 		cout << "\nBe glad you showed up today, because today is pay day!"
 			 << " $400 has been added to your account." << endl << endl;
 		player1->addMoney(400);
 		cout << "However, ";
 	}


 	/*********************************************************************
 	 *Work menu
 	*********************************************************************/
 	do {
	 	cout << "\nYou are at work. Please choose from the following: "
	 		 << "\nEnter 1 to: Go to your desk"
	 		 << "\nEnter 2 to: turn and get out of here";
	 	cin >> input;

		if (input == 1) {
			payMoney = combat();

			//if you lost argument, must pay for therapy
			if (payMoney) 
				player1->addMoney(therapyMoney);
			
			else {
				player1->addMoney(bonus);
				player1->setBonus(true);
			}
		}

	} while (input != 2);
 }

 /************************************************************************
 *Function: combat
 *Description: initiates and runs combat between you and boss. boss is 
  Medusa creature and you are BlueMen creature
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: either you or boss will lose, resulting in money 
  transaction
 ***********************************************************************/
 bool Work::combat() {

 	//intro 
 	cout << "\nYou arrive at your desk, and your boss is not happy. "
 		 << "\n He comes over to you and starts yelling. You must "
 		 << "combat your boss and stand up for yourself! \n" 
 		 << "(if you win, you get a bonus, if you lose, you must spend "
 		 << "money for therapy to heal your wounds.)" << endl << endl;

	cout << "Press Enter to Begin Your Fight. " << endl << endl;
	cin.ignore();
	cin.get();


	//declare necessary variables
 	you = new BlueMenYou;
 	boss = new MedusaBoss;
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
		cout << "Strength of " << boss->getName() << ": "
			 << boss->getStrength() << endl;	 



		//attack and defense moves of Creature a on b
		cout << boss->getName() << "'s attack: " << endl;
		attackRoll = boss->attack();

		cout << you->getName() << "'s defense: " << endl;
		lifeStrength = you->defense(attackRoll);
		cout << you->getName() << "'s strength after attack: " 
			 << you->getStrength() << endl << endl;

		//determine if Creature b is killed
		dead = you->die();

		if (dead) {
			cout << you->getName() << " lost the fight. You must "
				 << " pay $1000 for therapy. Combat End."
				 << endl;
			youdied = true;
		}

		else {

			//attack and defense moves of Creature b on a
			cout << you->getName() << "'s attack turn: " << endl;
			attackRoll = you->attack();

			cout << boss->getName() << "'s defense turn: " << endl;
			lifeStrength = boss->defense(attackRoll);
			cout << boss->getName() << "'s strength after attack: " 
				 << boss->getStrength() << endl << endl << endl;


 		//determine if Creature a is killed
			dead = boss->die();

			if (dead) {
				cout << boss->getName() << " lost the fight. He "
					 << "rewards your excellent job by giving you a"
					 << " bonus! Combat End."
					 << endl;
				youdied = false;
			}
		}


	} while (!dead);

	cout << endl;
	return youdied;

 }


 /************************************************************************
 *Function: setPerson
 *Description: set's room's person pointer to player
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: room can now access person's money
 ***********************************************************************/
 void Work::setPerson(Person *pIn) {
 	player1 = pIn;

 }