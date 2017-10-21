/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: MedusaBoss.hpp is a class specification file for a  
 Creature subclass, Medusa.
 ************************************************************************/

 #ifndef MEDUSABOSS_HPP
 #define MEDUSABOSS_HPP

 #include "Creature.hpp"
 #include "DiceMod.hpp"

 class MedusaBoss : public Creature {

 		public:
 			MedusaBoss();
 			virtual double attack();
 			virtual double defense(double);

 };
 #endif
