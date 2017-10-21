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
 using std::cout;
 using std::endl;
 using std::cin;


 int main()  {

 	/*********************************************************************
 	Part 1 Testing: Creature Class and ReptilePeople subclass
 	*********************************************************************/
 	double attackRoll;
 	double lifeStrength;
 	bool dead;

 	//get random number seed
 	unsigned seed;
	seed = time(0);
	srand(seed);

 	Creature *rp1;
 	Creature *rp2;
 	rp1 = new ReptilePeople;
 	rp2 = new ReptilePeople;
 	cout << "rp1 strength: " << rp1->getStrength() << endl;
	cout << "rp2 strength: " << rp2->getStrength() << endl;

	//NOTE: made armor public in Creature.hpp in order to test this value
		//cout << "rp1 armor: " << rp1->armor << endl;


	//Testing basic attack and defense
	attackRoll = rp2->attack();


	//Testing defense response
	lifeStrength = rp1->defense(attackRoll);

	cout << " reptileppl rp1 strength: " << rp1->getStrength() << endl;

	//testing die function
	dead = rp1->die();
	cout << "dead? " << dead << endl;

	if (dead) {
		delete rp1;
		rp1 = NULL;
	}

	delete rp1;
	delete rp2;
	rp1 = rp2 = NULL;

	/*********************************************************************
 	Part 1 Testing: Medusa subclass
 	*********************************************************************/
 	rp1 = new Medusa;
 	rp2 = new Medusa;
 	cout << "rp1 strength: " << rp1->getStrength() << endl;
	cout << "rp2 strength: " << rp2->getStrength() << endl;

 	attackRoll = -1;
 	lifeStrength = -1;
 	dead = 0;

 	attackRoll = rp2->attack();
 	if (attackRoll < -500) {
 		cout << "Medusa turned you to stone. game over." << endl;
 		delete rp1;
 		rp1 = NULL;
 	}
 	else {
 		cout << "Defense Roll: " << endl;
		lifeStrength = rp1->defense(attackRoll);

		cout << "medusa rp1 strength: " << rp1->getStrength() << endl;

		//testing die function
		dead = rp1->die();
		cout << "dead? " << dead << endl;

		if (dead) {
			delete rp1;
			rp1 = NULL;
		}

	}


	//delete pointers
	if (rp1) {
		delete rp1;
		rp1 = NULL;
	}

	if (rp2) {
		delete rp2;
		rp2 = NULL;
	}

 	return 0;
 }