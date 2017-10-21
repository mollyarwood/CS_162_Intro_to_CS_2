/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Work.hpp is a class specification file for the Work
  class. This will be a derived class of Space
 ************************************************************************/

#ifndef Work_HPP
#define Work_HPP
#include "Space.hpp"
#include "Creature.hpp"
#include "BlueMenYou.hpp"
#include "MedusaBoss.hpp"
#include <string>
using std::string;

class Work : public Space {

	private: 
		Creature *you;
		Creature *boss;
		double therapyMoney;
		double bonus;
	public:
		Work();
		~Work();
		virtual string getName();
		virtual bool validMove(Space *);
		virtual void menu();
		bool combat();
		virtual void setPerson(Person *);
};
#endif