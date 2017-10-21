/*************************************************************************
 *Name: Molly Arwood
 *Date: 8-2-16
 *Description: Person.hpp is a class specification file for the Person
  class. A player will be a person.
 ************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

//#include "Space.hpp"
#include <string>
using std::string;

class Person {

	private:
		string pName;
		double money;
		double studentLoans;
		int kidsNum;
		string container[2];
		bool house;
		bool degree;
		bool physDeg;
		bool bonus;
		bool end;
		bool marriage;

	public:
		Person(string);
		Person();
		~Person();
		string getName();
		double getStudentLoans();
		void addStudentLoans(double);
		double getMoney();
		void addMoney(double);
		bool getHouse();
		void setHouse(bool);
		bool getDegree();
		void setDegree(bool);
		bool getPhysDeg();
		void setPhysDeg(bool);
		void addContainer(string &);
		string * getContainer();
		void setBonus(bool);
		bool getBonus();
		void setEnd(bool);
 		bool getEnd();
 		bool getMarriage();
 		void setMarriage(bool);

};
#endif