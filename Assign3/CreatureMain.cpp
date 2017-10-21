/*************************************************************************
 *Name: Moly Arwood
 *Date: 7-18-16
 *Description: CombatDriver.cpp is a driver file used for testing during
 design of Creature class and its subclasses
 ************************************************************************/

 #include <iostream>
 #include <ctime>
 #include <stdlib.h>
 #include "Creature.hpp"
 #include "ReptilePeople.hpp"
 #include "Medusa.hpp"
 #include "Gollum.hpp"
 #include "BlueMen.hpp"
 #include "HarryPotter.hpp"
 using std::cout;
 using std::endl;
 using std::cin;

 int main() {

 	double attackRoll;
 	double lifeStrength;
 	bool dead;
 	int size = 5;

 	//get random number seed
 	unsigned seed;
	seed = time(0);
	srand(seed);

 	Creature *p1[size];
 	Creature *p2;


 	//initialize p1 to NULL for testinig phase
 	for (int i = 0; i < size; i++) 
 		p1[i] = NULL;
 	

 	//initialize p1 spaces to characters
 	p1[0] = new Medusa;
 	p1[1] = new ReptilePeople;
 	p1[2] = new Gollum;
 	p1[3] = new BlueMen;
 	p1[4] = new HarryPotter;


 	//loop through and combat.
 	for (int i = 0; i < size-1; i++) {
 		for (int j = i+1; j < size; j++) {

 			//combat announcement
 			cout << "**** " << p1[i]->getName() << " vs. " 
 				 << p1[j]->getName() << " ****" << endl << endl;


 			//combat until one Creature dies
 			do {

 				//show strengths before each round of attacks/defenses
	 			cout << "Strength of " << p1[i]->getName() << ": "
	 				 << p1[i]->getStrength() << endl;
	 			cout << "Strength of " << p1[j]->getName() << ": "
	 				 << p1[j]->getStrength() << endl;	 


	 			//attack and defense moves of Creature a on b
	 			cout << p1[i]->getName() << "'s attack: " << endl;
	 			attackRoll = p1[i]->attack();

	 			cout << p1[j]->getName() << "'s defense: " << endl;
	 			lifeStrength = p1[j]->defense(attackRoll);
	 			cout << p1[j]->getName() << "'s strength after attack: " 
	 				 << p1[j]->getStrength() << endl << endl;

	 			//determine if Creature b is killed
	 			dead = p1[j]->die();

	 			if (dead) {
	 				cout << p1[j]->getName() << " is dead. Combat End."
	 					 << endl;

	 			}

	 			else {

		 			//attack and defense moves of Creature b on a
		 			cout << p1[j]->getName() << "'s attack turn: " << endl;
		 			attackRoll = p1[j]->attack();

		 			cout << p1[i]->getName() << "'s defense turn: " << endl;
		 			lifeStrength = p1[i]->defense(attackRoll);
		 			cout << p1[i]->getName() << "'s strength after attack: " 
		 				 << p1[i]->getStrength() << endl << endl << endl;


			 		//determine if Creature a is killed
		 			dead = p1[i]->die();

		 			if (dead) {
		 				cout << p1[i]->getName() << " is dead. Combat End."
		 					 << endl;
		 			}

		 		}

	 		} while (!dead);

	 		//ask user to continue to next fight
	 		cout << endl << endl;
	 		if (i != size - 2 ) {
	 			cout << "Press Enter to continue to next fight: ";
	 			cin.get();
	 		}

 			//reset all values for next combat
	 		dead = 0;
	 		attackRoll = 0;
	 		lifeStrength = 0;
	 		p1[i]->resetStrength();
	 		p1[j]->resetStrength();

	 		if (p1[i]->getName() == "Harry Potter")
	 			dynamic_cast <HarryPotter *>(p1[i])->setCatLife(0);
	 		if (p1[j]->getName() == "Harry Potter")
	 			dynamic_cast <HarryPotter *> (p1[j])->setCatLife(0);

		}

 	}

 	//delete dynamically allocated memory
 	for (int i = 0; i < size; i++) {
 		delete p1[i];
 		p1[i] = NULL;
 	}


 	return 0;
 }