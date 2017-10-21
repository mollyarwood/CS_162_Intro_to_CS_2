/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: School.hpp is a class specification file for the School
  class. This will be a derived class of Space
 ************************************************************************/

#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include "Space.hpp"
#include <string>
using std::string;

class School : public Space {

	public:
		School();
		~School();
		virtual string getName();
		virtual bool validMove(Space *);
		virtual void menu();
		virtual void setPerson(Person *);
		void degree();
		void physDeg();
		void payLoans();
};
#endif