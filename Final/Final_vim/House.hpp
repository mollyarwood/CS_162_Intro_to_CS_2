/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: House.hpp is a class specification file for the house
  class. This will be a derived class of Space
 ************************************************************************/

#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "Space.hpp"
#include <string>
using std::string;

class House : public Space {

	private: 
		int visitCount;
	public:
		House();
		~House();
		virtual string getName();
		virtual bool validMove(Space *);
		virtual void menu();		
		virtual void setPerson(Person *);
		void cook();
		void newsPaper();
};
#endif