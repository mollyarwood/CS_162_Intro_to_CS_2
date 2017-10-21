/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Retire.hpp is a class specification file for the Retirement
  community class. This will be a derived class of Space
 ************************************************************************/

#ifndef Retire_HPP
#define Retire_HPP

#include "Space.hpp"
#include <string>
using std::string;

class Retire : public Space {

	public:
		Retire();
		~Retire();
		virtual string getName();
		virtual bool validMove(Space *);
		virtual void menu();
		virtual void setPerson(Person *);
		void verify();
		void endGame();
};
#endif