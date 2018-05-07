/*Workshop 7 - Derived Classes
File: Hero.h
Date: March 21, 2018
Author: Ricky Zaman
*/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include <iostream>
using namespace std;

namespace sict {

	class SuperHero:public Hero {
		//name, health, and attack strength found in base class
		int attackbonus; 
		int defence; 

	public:
		SuperHero(); 
		SuperHero(const char*, int, int, int, int); 
		int attackStrength() const; 
		int defend() const;

	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);


}

#endif 
