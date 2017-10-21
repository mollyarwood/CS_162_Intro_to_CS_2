/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-20-16
 *Description: HarryPotter.hpp is a class specification file for a  
 Creature subclass, HarryPotter.
 ************************************************************************/

 #ifndef HARRYPOTTER_HPP
 #define HARRYPOTTER_HPP

 #include "Creature.hpp"
 #include "Dice.hpp"

 class HarryPotter : public Creature {

 		private:
 			int catLife;

 		public:
 			HarryPotter();
 			virtual double attack();
 			virtual double defense(double);
 			virtual bool die();
 			void setCatLife(int);

 };
 #endif