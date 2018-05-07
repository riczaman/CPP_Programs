/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 28, 2018
Project: WS8 in Lab
File:    Account.cpp
*******************************/

#include <iostream>
#include "Account.h"


namespace sict {


	double Account::balance() const {
		return accbalance;
	}


	Account::Account(double amount) {
		if (amount > 0) {
			accbalance = amount;
		}
		else {
			accbalance = 0.0;
		}
	}

	bool Account::credit(double credit) {
		bool total;
		if (credit > 0) {
			accbalance += credit;
			total = true;
		}
		else {
			total = false;
		}
		return total;

	}


	bool Account::debit(double debit) {
		bool total;
		if (debit > 0) {
			accbalance -= debit;
			total = true;
		}
		else {
			total = false;
		}
		return total;
	}





}