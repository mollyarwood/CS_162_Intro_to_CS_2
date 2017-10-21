/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: Medusa.hpp is a class specification file for a  
 Creature subclass, Medusa.
 ************************************************************************/

 #ifndef MEDUSA_HPP
 #define MEDUSA_HPP

 #include "Creature.hpp"
 #include "Dice.hpp"

 class Medusa : public Creature {

 		public:
 			Medusa();
 			virtual double attack();
 			virtual double defense(double);

 };
 #endif
