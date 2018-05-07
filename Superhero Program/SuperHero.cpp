/*Workshop 7 - Derived Classes
File: SuperHero.cpp
Date: March 21, 2018
Author: Ricky Zaman
*/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Hero.h"
#include "SuperHero.h"
using namespace std;

namespace sict {

	SuperHero::SuperHero(){
		//the base class calls Hero(); 
		attackbonus = 0; 
		defence = 0; 

	}

	SuperHero::SuperHero(const char* hname, int hp, int attpoints, int attbon, int def) {
		if (hname != nullptr && hname[0] != '\0' && hp >= 0 && attpoints >= 0 && attbon >= 0 && def >= 0) {
			strncpy(name, hname, 40);
			name[40] = '\0';
			health = hp;
			attack_strength = attpoints;
			attackbonus = attbon;
			defence = def;
		}
		else {
			name[0] = '\0';
			health = 0;
			attack_strength = 0;
			attackbonus = 0;
			defence = 0;

		}
	}

	int SuperHero::attackStrength() const {
		int str; 
		if (!isEmpty()) {
			str = Hero::attackStrength() + attackbonus;
		}
		else {
			str = 0; 
		} 
		
		return str; 
	}

	int SuperHero::defend() const {
		int def; 
		if (!isEmpty()) {
			def = defence;
		}
		else {
			def = 0;
		}

		return def; 
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
		int rounds = 0;

		SuperHero one = first;
		SuperHero two = second;
		const SuperHero *won = nullptr;

		cout << "Super Fight! ";
		std::cout << one << " vs " << two << " : ";
		for (int i = 0; i < max_rounds; i++) {

			if (one.isAlive() && two.isAlive()) {
				rounds++;
				one -= (two.attackStrength()-one.defend()) ;
				two -= (one.attackStrength()-two.defend());
			}
		}
		if (one.isAlive() && !two.isAlive()) {
			won = &first;
		}
		else if (two.isAlive() && !one.isAlive()) {
			won = &second;
		}
		else {
			won = &first;
		}

		cout << "Winner is " << *won << " in " << rounds << " rounds." << endl; 
		return *won; 
	}


	

	
}
