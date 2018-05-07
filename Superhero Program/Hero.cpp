/*Workshop 7 - Derived Classes
File: Hero.cpp
Date: March 17, 2018
Author: Ricky Zaman
*/
#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Hero.h"
#include "SuperHero.h"
using namespace std;

namespace sict {

	Hero::Hero() {
		name[0] = '\0';
		health = 0;
		attack_strength = 0;
	}

	Hero::Hero(const char* hname, int hp, int attpoints) {
		if (hname[0] != '\0' && hp >= 0 && attpoints >= 0) {
			strncpy(name, hname, 40);
			name[40] = '\0';
			health = hp;
			attack_strength = attpoints;
		}
		else
			Hero();
	}

	void Hero::operator-=(int attack) {
		if (attack >= 0) {
			health = health - attack;
			if (health < 0) {
				health = 0;
			}
		}
	}

	bool Hero::isAlive() const {
		bool fight;
		if (health > 0) {
			fight = true;
		}
		else {
			fight = false;
		}
		return fight;
	}

	int Hero::attackStrength() const {
		if (!isEmpty()) {
			return attack_strength;
		}
		else
			return 0;
	}

	ostream& operator<<(ostream& os, const Hero& hero) {
		if (!hero.isEmpty()) {
			os << hero.name;
		}
		else {
			os << "No hero";
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		int rounds = 0;

		//because the objects we recieve are constants have to create new objects we can alter
		Hero one = first;
		Hero two = second;
		const Hero *won = nullptr; //have to make this pointer because we are returning a reference of an object

		cout << "Ancient Battle! ";
		std::cout << one << " vs " << two << " : ";
		for (int i = 0; i < max_rounds; i++) {
			if (one.isAlive() && two.isAlive()) {
				rounds++;
				one -= (two.attackStrength());
				two -= (one.attackStrength());
			}
		}
		if (one.isAlive() && !two.isAlive()) {
			won = &first;   //because won is a pointer have to set it equal to adress of first 
		}
		else if (two.isAlive() && !one.isAlive()) {
			won = &second;
		}
		else {
			won = &first;
		}
		//have to dereference won
		cout << "Winner is " << *won << " in " << rounds << " rounds." << endl;
		return *won;
	}

	bool Hero::isEmpty()const {
		bool emp;
		if (name[0] != '\0' && health != 0 && attack_strength != 0) {
			emp = false;
		}
		else {
			emp = true;
		}
		return emp;
	}






}