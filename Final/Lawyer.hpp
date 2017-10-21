/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Lawyer.hpp is a class specification file for the Lawyer's
  Office class. This will be a derived class of Space
 ************************************************************************/

#ifndef Lawyer_HPP
#define Lawyer_HPP

#include "Space.hpp"
#include "BlueMenYou.hpp"
#include "ReptilePeople.hpp"
#include <string>
using std::string;

class Lawyer : public Space {

	private:
		ReptilePeople *loanShark;
		BlueMenYou *you;

	public:
		Lawyer();
		~Lawyer();
		virtual string getName();
		virtual bool validMove(Space *);
		virtual void menu();		
		virtual void setPerson(Person *);
		void marriage();
		void loanFight();
};
#endif