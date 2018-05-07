/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 28, 2018
Project: WS8 in Lab
File:    SavingsAccount.h
*******************************/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include <iostream>
#include "Account.h"

namespace sict {

	class SavingsAccount : public Account {
		double srate;

	public:
		// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

		// TODO: perform month end transactions
		void monthEnd();

		// TODO: display inserts the account information into an ostream			
		void display(std::ostream&os)const;
	};
}
#endif
