/*Workshop 7 - Derived Classes
File: Hero.h
Date: March 17, 2018
Author: Ricky Zaman
*/

#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>
using namespace std;

namespace sict {
	const int max_rounds = 100;

	class Hero {
	protected: //have to do this so I can intialize my derived 5 parameter constructor properly 
		//protected = derived children have access to these variables 
		char name[41]; //40 + 1 for null byte 
		int health;
		int attack_strength;

	public:
		Hero();
		Hero(const char*, int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend ostream& operator<<(ostream& os, const Hero& hero);
		bool isEmpty()const;

	};
	const Hero& operator*(const Hero& first, const Hero& second);


}
#endif 
