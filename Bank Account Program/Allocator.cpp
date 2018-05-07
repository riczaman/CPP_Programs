/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 28, 2018
Project: WS8 in Lab
File:    Allocator.cpp
*******************************/

#include <iostream>
#include <cstring>
#include "SavingsAccount.h" 
#include "ChequingAccount.h"



namespace sict {

	// define interest rate

	const double interest = 0.05;
	const double transactionfee = 0.50;
	const double monthlyfee = 2.00;



	// TODO: Allocator function

	iAccount* CreateAccount(const char* acctype, double balance) {
		iAccount *acc = nullptr;

		if (acctype[0] == 'S' || acctype[0] == 's') {
			acc = new SavingsAccount(balance, interest);
		}
		else if(acctype[0] == 'C' || acctype[0] == 'c') {
			acc = new ChequingAccount(balance, transactionfee, monthlyfee);
		}
		else {
			acc = nullptr;
		}
		return acc;
	}


}
