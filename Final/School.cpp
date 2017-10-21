/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: School.cpp is a class implementation file for School
  class
 ************************************************************************/

#include "School.hpp"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;


/************************************************************************
 *Function: School
 *Description: initiates the name variable to "School". pointers will be
 NULL from Space constructor calling
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: name variable and pointeres initiated
 ***********************************************************************/
 School::School() {

 	name = "School";

 	ptr1 = NULL;
	ptr2 = NULL;
	next = NULL;
	back = NULL;
 }

 /************************************************************************
 *Function: ~School
 *Description: deletes any dynamicacll allocated school objects left
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: school objects deleted
 ***********************************************************************/
 School::~School() {

 }


/************************************************************************
 *Function: getName
 *Description: returns name of room
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: room name variable returned
 ***********************************************************************/
string School::getName() {

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
 bool School::validMove(Space *nwRm) {

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
 		//player->setLoc(nwRm);
 	}

 	else if (this->next == nwRm || this->back == nwRm) {

 		cout << "You are now going to: " << nwRm->getName() << endl
 			 << endl;
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
 void School::menu() {

 	int input;
 	double loans;
 	
	do {
	 	cout << "\nYou are at school. Please choose what you would like "
	 		 << "to do? "
	 		 << "\n Enter 1 to: Get your degree"
	 		 << "\n Enter 2 to: pay back student loans"
	 		 << "\n Enter 3 to: pick up your physical degree to take home"
	 		 << "\n Enter 4 to: exit"
	 		 << endl;
	 	cin >> input;

	 	if (input == 1) 
	 		degree();

	 	if (input == 2) 
	 		payLoans();
	 		
	 	if (input == 3) 
	 		physDeg();
	 	
 	} while (input != 4);
 	

 }


 /************************************************************************
 *Function: setPerson
 *Description: set's room's person pointer to player
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: room can now access person's money
 ***********************************************************************/
 void School::setPerson(Person *pIn) {
 	player1 = pIn;

 }


 /************************************************************************
 *Function: degree
 *Description: player answers questions to get degree in school
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: student either has or does not have degree
 ***********************************************************************/
 void School::degree() {

 	char ans;
 	bool answered;
 	double result;
 	int result2;
 	die1 = new DiceMod;	
 	die1->setSideCount(3);

 	//Question answers
 	char a[3] = {'b', 'a', 'a'};


 	/*********************************************************************
 	 *inform student of loans
 	 ********************************************************************/
 	cout << "Student loans will be $500. This amount has been added to"
 		 << " your StudentLoans account. " << endl;
 	player1->addStudentLoans(500.0);


 	/*********************************************************************
 	 *roll die to see which set of questions you get
 	 ********************************************************************/
 	result = die1->rollDie();
 	result2 = static_cast <int> (result);

 	switch (result2) {
	case 1:
		cout << "\n\n Q: John Montagu, the man credited with inventing"
			 << "\n the sandwich, held what noble title? "
			 << "\n a) Duke of Sandwhich \n b) Earl of Sandwhich "
			 << "\n c) King of Sandwhich" << endl;
		cin >> ans;
		if (ans == a[0]) {
			cout << "Correct! " << endl;
			answered = true;
		}
		else {
			cout << "Sorry, that's wrong. " << endl;
			answered = false;
		}

		break;

	case 2:
		cout << "\n\n Q: Abraham Lincoln was assassinated in what year?"
			 << "\n a) 1865 \n b) 1876 "
			 << "\n c) 1868 " << endl;
		cin >> ans;
		if (ans == a[1]) {
			cout << "Correct! " << endl;
			answered = true;
		}
		else {
			cout << "Sorry, that's wrong. " << endl;
			answered = false;
		}

		break;	

	case 3:
		cout << "\n\n Q: In the late 1890s, Bayer marketed a cough, cold "
			 << "\n & pain remedy that contained what now illegal drug? "
			 << "\n a) Heroin \n b) Cocaine "
			 << "\n c) marijuana " << endl;
		cin >> ans;
		if (ans == a[2]) {
			cout << "Correct! " << endl;
			answered = true;
		}
		else {
			cout << "Sorry, that's wrong. " << endl;
			answered = false;
		}

		break;	
	}

	if (answered == true) {
		cout << "\nCongrats! you earned your degree! Please pick it up by"
			 << " choosing option 3 in the School menu. " << endl;
		player1->setDegree(answered);
		player1->setPhysDeg(answered);

	}

	else {
		cout << "\nYou did not earn your degree. Please try again but "
			 << "\n note that another student loan will be charged to "
			 << "\nyour account. " << endl;
	}

 }


 /************************************************************************
 *Function: physDeg
 *Description: player picks up physical degree if earned
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: student either has or does not have physical degree
 ***********************************************************************/
 void School::physDeg() {

 	string s = "Physical Degree";

 	if (player1->getPhysDeg()) {
 		cout << "your degree has been added to your container of items. "
 			 << endl;

		player1->addContainer(s);
		string *sptr = player1->getContainer();
 	}


 	else 
 		cout << "you have not earned your degree yet. " << endl;
 	
 }


 /************************************************************************
 *Function: payLoans
 *Description: player pays any outstanding loans
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: student loan account may go down
 ***********************************************************************/
 void School::payLoans() {

 	double amount;
	double loans = player1->getStudentLoans();

	if (loans >= 0.01) {
		cout << "You have " << loans << " left to pay. Please enter the "
			 << "amount you would like to pay off: ";
		cin >> amount;

		amount *= -1;
		player1->addStudentLoans(amount);
		player1->addMoney(amount);

		cout << "Thank you. " << amount*-1 << "has been discounted from "
			 << "your account. " << endl;
 	}

 	else {
 		cout << "You do not have any student loans to pay. " << endl;
 	}
}	