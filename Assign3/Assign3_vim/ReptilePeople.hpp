/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-18-16
 *Description: ReptilePeople.hpp is a class specification file for a  
 Creature subclass, ReptilePeople. 
 ************************************************************************/

 #ifndef REPTILEPEOPLE_HPP
 #define REPTILEPEOPLE_HPP

 #include "Creature.hpp"
 #include "Dice.hpp"

 class ReptilePeople : public Creature {

 		public:
 			ReptilePeople();
 			virtual double attack();
 			virtual double defense(double);

 };
 #endif