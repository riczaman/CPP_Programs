/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 28, 2018
Project: WS8 in Lab
File:    SavingsAccount.cpp
*******************************/
#include<iostream>
#include<iomanip>
#include "SavingsAccount.h"

namespace sict {

	SavingsAccount::SavingsAccount(double sbalance, double irate) :Account(sbalance) {
		if (irate > 0) {
			srate = irate;
		}
		else {
			srate = 0.0;
		}
	}


	void SavingsAccount::monthEnd() {
		double value;
		value = balance()*srate;
		credit(value);
	}


	void SavingsAccount::display(std::ostream&os)const {
		os << "Account type: Savings" << std::endl;
		os.setf(std::ios::fixed); //used to set to number to exact length 
		os.precision(2);
		os << "Balance: $" << balance() << std::endl;
		os << "Interest Rate (%): " << srate * 100 << std::endl;



	}
}