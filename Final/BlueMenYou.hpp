/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: BlueMenYou.hpp is a class specification file for a  
 Creature subclass, BlueMen.
 ************************************************************************/

 #ifndef BLUEMENYOU_HPP
 #define BLUEMENYOU_HPP

 #include "Creature.hpp"
 #include "DiceMod.hpp"

 class BlueMenYou : public Creature {

 		private:
 			DiceMod *d2;

 		public:
 			BlueMenYou();
 			virtual double attack();
 			virtual double defense(double);

 };
 #endif
