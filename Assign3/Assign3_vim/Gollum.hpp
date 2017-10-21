/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: Gollum.hpp is a class specification file for a  
 Creature subclass, Gollum.
 ************************************************************************/

 #ifndef GOLLUM_HPP
 #define GOLLUM_HPP

 #include "Creature.hpp"
 #include "Dice.hpp"

 class Gollum : public Creature {

 		public:
 			Gollum();
 			virtual double attack();
 			virtual double defense(double);

 };
 #endif
