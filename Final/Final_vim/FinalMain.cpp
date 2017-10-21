/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: FinalMain.cpp
 ************************************************************************/

 #include "Space.hpp"
 #include "School.hpp"
 #include "Apartment.hpp"
 #include "Work.hpp"
 #include "Retire.hpp"
 #include "Lawyer.hpp"
 #include "House.hpp"
 #include "List.hpp"
 #include "Person.hpp"
 #include "BlueMenYou.hpp"
 #include "MedusaBoss.hpp"
 #include <iostream>
 #include <ctime>
 #include <cstdlib>
 using std::cout;
 using std::endl;
 using std::cin;


//prototypes
void moveMenu(List *, Person *);
void personMenu(int, Person *);
void retirementReq();

 int main() {

 	//initialize spaces and List and data
 	int input;
 	List *l = new List;
  	Person *p1 = new Person;
  	Space *h = NULL;
  	Space *schl = NULL;
 	l->setPlayer(p1);
 	l->createGame();

 	//get random number seed
 	unsigned seed;
	seed = time(0);
	srand(seed);


 	/*********************************************************************
 	 *intro dialogue
 	 ********************************************************************/
 	 cout << "\n\nWelcome to the game of Life. \n\n " << endl;

 	 //for aesthetic purposes only
 	 for (long i = 0; i < 400000000; i++) {}


 	 cout << "The goal is to get to the Retirement Community "
 	 	  << "\nhaving completed all the necessary tasks. In order to "
 	 	  << "\ncomplete the tasks, you must visit each room. "
 	 	  << endl << endl << endl;


 	 //for aesthetic purposes only
 	 for (long i = 0; i < 400000000; i++) {}

 	/*********************************************************************
 	 *Main Game Menu
 	 ********************************************************************/
 	do {

 		cout << "\nWhat would you like to do? " 
 			 << "\n Enter 1 to: move to a room "
 			 << "\n Enter 2 to: review items in container "
 			 << "\n Enter 3 to: Confirm you have earned a degree"
 			 << "\n Enter 4 to: View your money and loans"
 			 << "\n Enter 5 to: Review retirement requirements "
 			 << "\n Enter -1 to: Exit Game \n\n";
 		cin >> input;

 		if (input == 1) 
 			moveMenu(l, p1);
 		
 		if (input == 2) 
 			personMenu(input, p1);

 		if (input == 3)
 			personMenu(input, p1);

 		if (input == 4)
 			personMenu(input, p1);

 		if (input == 5)
 			retirementReq();
 		

 		//check for new house & deleting apt
 		if (p1->getHouse() && h == NULL) {
 			h = new House;
 			schl = new School;
 			cout << "house created" << endl;
 			l->deleteApt();
 			l->addSpace(h, 1);
 			l->setHouse(h, schl, p1);
 		}

 		
	 	//if end of game flag is true, end game
	 	if (p1->getEnd()) 
	 		input = -1;
	 	

 	} while (input != -1);

 	//delete objects
 	delete l;
 	delete p1;

 	return 0;
 }


 /************************************************************************
 *Function: moveMenu
 *Description: displays room options for player. Will call list's move
  function, which in-turn, will allow a player to execute an action in 
  the room
 *Parameters: none
 *Pre-Condition: None
 *Post-Condition: Player moves to a room and executes a task
 ***********************************************************************/

 void moveMenu(List *l, Person *p1) {

 	int input;
 	//l->getNodeNames();

 	if (p1->getHouse()) {
	 	cout << "where would you like to move to? "
	 		 << "\n Enter 1 for: School "
	 		 << "\n Enter 2 for: House "
	 		 << "\n Enter 3 for: Work"
	 		 << "\n Enter 4 for: Lawyer's Office "
	 		 << "\n Enter 5 for: Retirement Community" << endl << endl; 
	 }

	 else {
	 	cout << "where would you like to move to? "
	 		 << "\n Enter 1 for: School "
	 		 << "\n Enter 2 for: Apartment "
	 		 << "\n Enter 3 for: Work "
	 		 << "\n Enter 4 for: Lawyer's Office"
	 		 << "\n Enter 5 for: Retirement Community" << endl << endl;  	
	 }

	cin >> input; 
 	l->move(input);


 }



 /************************************************************************
 *Function: PersonMenu
 *Description: calls Person's functions to view degrees, items, money, etc
 *Parameters: int (to know which function to call)
 *Pre-Condition: None
 *Post-Condition: Person's info displayed on screen
 ***********************************************************************/

 void personMenu(int n, Person *p1) {
 	int input = n;
 	bool t;

 	//get items in container
 	if (input == 2) {
 		string *sptr = p1->getContainer();
 		
 		for (int i = 0; i < 2; i++) 
 			cout << "item " << i << ": " << sptr[i] << endl;
 		
 	}

 	//confirm you've earned a degree
 	if (input == 3) {
 		if (p1->getDegree()) 
 			cout << "\nYes, you have earned a degree. ";
 		
 		else
 			cout << "\nNo, you still need to earn a degree. ";

 	}

 	//get money and loans
 	if (input == 4) {
 		cout << "\nMoney in bank: " << p1->getMoney()
 			 << "\nStudent loans: " << p1->getStudentLoans() << endl;
 	}

 }




 void retirementReq() {

 	cout << "\n\nRetirement Community Requirements: "
 		 << "\n\n1) Degree from School "
		 << "\n2) Buy House "
		 << "\n3) Get one bonus at work "
		 << "\n4) Obtain $1,000 "
		 << "\n5) Get Married. " << endl;
 }




 /************************Old test code**********************************/

 // 	l->addSpace(sp, 0);
 // 	l->getNodeNames();
 // 	l->addSpace(sp2, 1);
 // 	l->getNodeNames();
 // 	l->addSpace(sp3, 2);
 // 	l->getNodeNames();
 // 	l->addSpace(sp4, 3);
 // 	l->getNodeNames();
	// l->addSpace(sp5, 4);
 // 	l->getNodeNames();

  // 	cout << "new location: " << p1->getLoc() << endl;
