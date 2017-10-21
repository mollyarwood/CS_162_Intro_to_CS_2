/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Space.hpp is a class specification file for Space
  class. This will be the parent class for derived spaces
 ************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "DiceMod.hpp"
#include "Person.hpp"
#include <string>
using std::string;

class Space {

	protected: 
		DiceMod *die1;
		string name;
		//Space *next;
		Space *back;
		Space *ptr1;
		Space *ptr2;
		Person *player1;
		friend class List;
		
	public:
		virtual string getName() = 0;
		virtual bool validMove(Space *) = 0;
		virtual void menu() = 0;
		virtual void setPerson(Person *) = 0;
		Space *next;

};
#endif