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
 #include "List.hpp"
 #include "Person.hpp"
 #include <iostream>
 using std::cout;
 using std::endl;
 using std::cin;


 int main() {

 	//initialize spaces and List
 	//Space *sp = new School;
 	// Space *sp2 = new Apartment;
 	// Space *sp3 = new Work;
 	// Space *sp4 = new Lawyer;
 	// Space *sp5 = new Retire;
 	List *l = new List;
 	Person *p1 = new Person;

 	int input;

 	l->setPlayer(p1);
 	l->createGame();

 	// cout << "original location: " << p1->getLoc() << endl;

 	// cout << "where would you like to move to? "
 	// 	 << "\n Enter 1 for: School "
 	// 	 << "\n Enter 2 for: Apartment "
 	// 	 << "\n Enter 3 for: Work "
 	// 	 << "\n Enter 4 for: Lawyer's Office"
 	// 	 << "\n Enter 5 for: Retirement Community" << endl; 
 	// cin >> input; 

 	// switch (input) {
 	// 	case 1: 
 	// 		l->move(sp);
 	// 		break;
 	// 	case 2: 
 	// 		l->move(sp2);
 	// 		break;
 	// 	case 3:
 	// 		l->move(sp3);
 	// 		break;
 	// 	case 4:
 	// 		l->move(sp4);
 	// 		break;
 	// 	case 5:
 	// 		l->move(sp5);
 	// 		break;
 	// }

 	
 	// cout << "new location: " << p1->getLoc() << endl;


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


 
 	delete l;

 	return 0;
 }