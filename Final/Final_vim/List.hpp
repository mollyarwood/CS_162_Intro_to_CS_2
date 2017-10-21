/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: List.hpp is a class specification file for a Linked List.
 ************************************************************************/

 #ifndef LIST_HPP
 #define LIST_HPP

 #include "Person.hpp"
 #include "Space.hpp"

 class List {

 	private:
 		Space *head;
 		Space *tail;
 		Person *player;
 		Space *personLoc;
 		int listLength;

 	public:
 		List();
 		~List();
 		void createGame();
 		void addSpace( Space *newSpace, int position);
 		void removeSpace(int position);
 		void getNodeNames();
 		void move(int);
 		void setPlayer(Person *);
 		void setPersonLoc(Space *);
 		Space * getPersonLoc();
 		void setHouse(Space *, Space *, Person *);
 		void deleteApt();

 };
 #endif