/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Apartment.hpp is a class specification file for the aprtmnt
  class. This will be a derived class of Space
 ************************************************************************/

#ifndef APARTMENT_HPP
#define APARTMENT_HPP

#include "Space.hpp"
#include <string>
using std::string;

class Apartment : public Space {


	public:
		Apartment();
		~Apartment();
		virtual string getName();
		virtual bool validMove(Space *);
		virtual void menu();
		virtual void setPerson(Person *);
		void rollHouseDie();
};
#endif