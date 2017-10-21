/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: BlueMen.hpp is a class specification file for a  
 Creature subclass, BlueMen.
 ************************************************************************/

 #ifndef BLUEMEN_HPP
 #define BLUEMEN_HPP

 #include "Creature.hpp"
 #include "Dice.hpp"

 class BlueMen : public Creature {

 		private:
 			Dice *d2;

 		public:
 			BlueMen();
 			virtual double attack();
 			virtual double defense(double);

 };
 #endif
