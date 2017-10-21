/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: List.cpp is a class implementation file for the linked list
  class
 ************************************************************************/

 #include "List.hpp"
 #include "Space.hpp"
 #include "School.hpp"
 #include "Apartment.hpp"
 #include "Work.hpp"
 #include "Retire.hpp"
 #include "Lawyer.hpp"
 #include "List.hpp"
 #include "Person.hpp"
 #include <iostream>
  using std::cout;
  using std::endl;

 /************************************************************************
 *Function: List
 *Description: initiates head and length variables
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition: head and length initiated
 ***********************************************************************/
 List::List() {

 	head = NULL;
 	tail = NULL;
 	listLength = 0;
 	player = NULL;

 }


 /************************************************************************
 *Function: ~List
 *Description: deletes any dynamic nodes left
 *Parameters: None
 *Pre-Condition: None
 *Post-Condition:nodes deleted
 ***********************************************************************/
 List::~List() {

 	while (head != NULL) {

 		Space *prev = head;
 		head = head->next;

 		//if the list can continue to the next cycle, delete the old node
 		cout << prev->getName() << endl;
		prev->ptr1 = NULL;
		prev->ptr2 = NULL;

 		delete prev;
 		prev = NULL;

 	}



 }


 /************************************************************************
 *Function: createGame()
 *Description: builds the structure of the spaces for the game
 *Parameters: 5 Space pointers created in Main
 *Pre-Condition: 5 Space pointers created
 *Post-Condition: all connections for game start will be made
 ***********************************************************************/
 // void List::createGame(Space *schl, Space *apt, Space *wrk, Space *lwr, 
 // 						Space *rtr) {
 void List::createGame() {

 	//create doubly linked structure
 	Space *sp = new School;
 	addSpace(sp, 0);
 	sp = new Apartment;
 	addSpace(sp, 1);
 	sp = new Work;
 	addSpace(sp, 2);
 	sp = new Lawyer;
  	addSpace(sp, 3);
  	sp = new Retire;
	addSpace(sp, 4);
 	//getNodeNames();

 	//assigning other pointers
 	Space *temp = head;

 	//assign school to work and to lawyer 
 	head->ptr1 = head->next->next;
 	head->ptr2 = head->next->next->next;

 	//incrementing temp to Apartment
 	temp = head->next;

 	//Assign apartment to lawyer
 	temp->ptr1 = head->next->next->next;

 	//incrementing temp to work 
 	temp = temp->next; 

	//assign work to school and to retirement
 	temp->ptr1 = head;
 	temp->ptr2 = temp->next->next;

 	//incrementing temp to lawyer
 	temp = temp->next;

 	//assign lawyer to apartment and to school
 	temp->ptr1 = head->next;
 	temp->ptr2 = head;

 	//incrementing temp to retirement
 	temp = temp->next;

 	//assigning retirement to work
 	temp->ptr1 = temp->back->back;

 	//set Person pointer for each room
 	temp = head;
 	while (temp) {
 		temp->setPerson(player);
 		temp = temp->next;
 	}

 }


 /************************************************************************
 *Function: addSpcace
 *Description: adds a new node in the specific position stated
 *Parameters: Node pointer and position
 *Pre-Condition: None
 *Post-Condition: new node added into appropriate location
 ***********************************************************************/
 void List::addSpace(Space *newSpace, int position) {

	Space *ptr = head;
 	Space *prev = head;
 	int count = 0;

 	if (head == NULL) {
 		head = newSpace;
 		head->next = NULL;
 		head->back = NULL;
 		setPersonLoc(head);
 	}

	else {
	 	while (ptr) {

	 		if (position == count) {
	 			prev->next = newSpace;
	 			//cout << "prev next: " << prev->next << endl;
	 			//cout << "newSpace: " << newSpace << endl;
	 			newSpace->next = ptr;
	 			newSpace->back = prev;
	 			listLength++;
	 			cout << "house entered " << endl;
	 		}

	 		prev = ptr;
	 		ptr = ptr->next;
	 		count++;
	 	}

	 	//if you are inserting at the back of the line
 		if (position == count) {
			prev->next = newSpace;
			newSpace->next = ptr;
			newSpace->back = prev;
			tail = newSpace;
			listLength++;
		}

 	}
 }


 /************************************************************************
 *Function: removeSpace
 *Description: removes a node
 *Parameters: Space *ptr
 *Pre-Condition: None
 *Post-Condition: specified node removed
 ***********************************************************************/
 void List::removeSpace(int position) {

	Space *ptr = head->next;
 	Space *prev = head;
 	int count = 0;

 	if (head == NULL) {
 		cout << "list is empty. ";
 	}

 	//if head is to be deleted
 	else if (position == 0) {

 		//set head and ptr to next node over. delete first node
 		ptr->back = NULL;
 		head = head->next;
 		delete prev;
 		prev = ptr;
 		listLength--;
 	}

 	//if other node is to be removed
 	else {
	 	while (ptr != NULL) {

	 		if (count == position - 1) {

	 			prev->next = ptr->next;  //back node leapfrogs over n
	 			delete ptr;
	 			ptr = prev->next;		 //ptr equals n+1
	 			ptr->back = prev;		 //ptr back = n-1
	 			listLength--;
	 			//cout << "apt removed " << endl;
	 		}

	 		prev = ptr;
	 		ptr = ptr->next;
	 		count++;
	 	}


	 	//if back node is to be removed
 		if (position == listLength) {

 			prev->next = NULL; //back node points to null
 			delete ptr;
 			ptr = prev->next;		 //ptr equals n+1
 			tail = prev;		 //tail back = n-1
 			listLength--;
 		}

 	}

 }

 /************************************************************************
 *Function: getNodeName
 *Description: displays name of node
 *Parameters: 
 *Pre-Condition: None
 *Post-Condition: node name displayed
 ***********************************************************************/
 void List::getNodeNames() {

 	Space *temp = head;
 	Space *bckwrds = head;

 	cout << "traverse forwards: " << endl;
 	while (temp != NULL) {
 		cout << "space name: " << temp->getName() << endl;
 		bckwrds = temp;
 		temp = temp->next;
 	}

 	// cout << "Traverse backwards: " << endl;
 	// temp = bckwrds;
 	// while (temp != NULL) {
 	// 	cout << "space name: " << temp->getName() << endl;
 	// 	bckwrds = temp;
 	// 	temp = temp->back;
 	//}

 }

 /************************************************************************
 *Function: move
 *Description: moves from one location to another
 *Parameters: desired location to move to
 *Pre-Condition: None
 *Post-Condition: location poiniter now points to new spot.
 ***********************************************************************/
 void List::move(int input) {
 	Space *nwRm = head;

 	//interpreting input variable to get room
 	if (input == 1) 
 		nwRm = head;

	else if (input == 2) 
		nwRm = head->next; 	

	else if (input == 3)
		nwRm = head->next->next;

	else if (input == 4) {
		nwRm = nwRm->next;
		nwRm = nwRm->next->next;
		cout << "4" << endl;
	}

	else {
		nwRm = nwRm->next->next;
		nwRm = nwRm->next->next;
	}


 	//comparing player's location to suggested room
 	bool vMove = personLoc->validMove(nwRm);
 	//cout << "validMove called" << endl;

 	//if valid move player
 	if (vMove) {
 		setPersonLoc(nwRm);
 		nwRm->menu();
 	}

 }

 /************************************************************************
 *Function: setPlayer
 *Description: sets the player pointer equal to the player
 *Parameters: Person pointer
 *Pre-Condition: 
 *Post-Condition: player initialized
 ***********************************************************************/
 void List::setPlayer(Person *pIn) {
 	player = pIn;
 }


 /************************************************************************
 *Function: setPersonLoc
 *Description: sets the player's position
 *Parameters: Space pointer
 *Pre-Condition: 
 *Post-Condition: player's location noted
 ***********************************************************************/
 void List::setPersonLoc(Space *sp) {
 	personLoc = sp;
 }


 /************************************************************************
 *Function: getPersonLoc
 *Description: gets the player's position
 *Parameters: None
 *Pre-Condition: 
 *Post-Condition: player's location returned
 ***********************************************************************/
 Space * List::getPersonLoc() {
 	return personLoc;
 }


 /************************************************************************
 *Function: setHouse()
 *Description: sets the house's extra pointers up
 *Parameters: None
 *Pre-Condition: 
 *Post-Condition: house points to work and School now, as well as 
 Lawyer's office and retirement comm
 ***********************************************************************/
 void List::setHouse(Space *h, Space *s, Person *p1) {

 	//set House extra pointers to school and work
 	cout << "head: " << head << endl;
 	h->ptr1 = h->next->next;
 	h->ptr2 = h->next->next->next;
 	cout << "house pointers added " << endl;
 	h->setPerson(p1);
 	setPersonLoc(s);
 }


 /************************************************************************
 *Function: deleteApt()
 *Description: deletes the apartment and its pointers
 *Parameters: None
 *Pre-Condition: 
 *Post-Condition: apartment deleted and house takes its spot (almost)
 ***********************************************************************/
 void List::deleteApt() {

 Space *ptr = head->next;
 Space *prev = head;
 int count = 0;

 //Set ptr1 and ptr2 to null
 ptr->ptr1 = NULL;
 ptr->ptr2 = NULL;

 //set prev's next to leapfrog ptr and ptr->next's back to prev
 prev->next = ptr->next;
 ptr->next->back = prev;


//don't worry about dangling pointers becausee they will be assigned to
 //house later

 //NEED TO FIGURE OUT WHY I'M GETTING THE VIRTUAL ERROR WHEN I DELETE APT

 //delete ptr & re-assign
 //delete ptr;
 ptr = prev->next;

 }