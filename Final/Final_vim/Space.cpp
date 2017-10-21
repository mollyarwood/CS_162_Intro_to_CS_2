// /*************************************************************************
//  *Name: Molly Arwood
//  *Date: 8-2-16
//  *Description: Space.cpp is a class implementation file for Space
//   class
//  ************************************************************************/

// #include "Space.hpp"
// #include <string>
// #include <iostream>
// using std::string;
// using std::cout;
// using std::endl;


// /************************************************************************
//  *Function: Space
//  *Description: initiates the name variable to "Space" & pointers to NULL
//  *Parameters: None
//  *Pre-Condition: None
//  *Post-Condition: name variable and pointeres initiated
//  ***********************************************************************/
// Space::Space() {

// 	name = "space";

// 	ptr1 = NULL;
// 	ptr2 = NULL;
// 	next = NULL;
// 	back = NULL;
// }



// /************************************************************************
//  *Function: ~Space
//  *Description: deletes any dynamically allocated space objects left
//  *Parameters: None
//  *Pre-Condition: None
//  *Post-Condition: space objects deleted
//  ***********************************************************************/
// Space::~Space() {


// 	// if (ptr1 != NULL) {
// 	// 	ptr1 = NULL;
// 	// }

// 	// if (ptr2 != NULL) {
// 	// 	ptr2 = NULL;
// 	// }

// 	cout << "space deleted" << endl;
// }


// ***********************************************************************
//  *Function: displayName
//  *Description: returns the name of the room
//  *Parameters: None
//  *Pre-Condition: None
//  *Post-Condition: room name returned
//  **********************************************************************
//  string Space::getName() {
//  	return name;
//  }

// /************************************************************************
//  *Function: validMove
//  *Description: returns true if you can get to that room from the current
//  location
//  *Parameters: Space pointer
//  *Pre-Condition: Person must be in a room
//  *Post-Condition: true or false returned
//  ***********************************************************************/
//  bool Space::validMove(Space *nwRm) {

//  	bool vMove = false;
//  	//Space *temp = player->getLoc();

//  	if (this->getName() == nwRm->getName()) {
//  		cout << "You are already in this room. " << endl;
//  		vMove = false;
//  	}

//  	else if (this->ptr1 == nwRm || this->ptr2 == nwRm) {

//  		cout << "You are now going to: " << nwRm->getName() << endl;
//  		vMove = true;
//  		//player->setLoc(nwRm);
//  	}

//  	else if (this->next == nwRm || this->back == nwRm) {

//  		cout << "You are now going to: " << nwRm->getName() << endl;
//  		vMove = true;
//  		//player->setLoc(nwRm);
//  	}

//  	else {
//  		cout << "That move is not legal. pick again. " << endl;
//  		vMove = false;
//  	}

//  	return vMove;

//  }

/************************************************************************
 *Function: setPlayer
 *Description: sets the player pointer equal to the player
 *Parameters: Person pointer
 *Pre-Condition: 
 *Post-Condition: player initialized
 ***********************************************************************/
 // void Space::setPlayer(Person *pIn) {
 // 	player = pIn;
 // }