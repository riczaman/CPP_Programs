/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 28, 2018
Project: WS8 in lab
File:    iAccount.h
*******************************/

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount {

	public:
		//****Pure virtual functions are set equal to 0 and have to be implemented in the derived class
		//in order to be used*****

		// TODO: credit adds +ve amount to the balance
		virtual bool credit(double credit) = 0;

		// TODO: debit subtracts a +ve amount from the balance
		virtual bool debit(double debit) = 0;

		// TODO: month end adds month end costs
		virtual void monthEnd() = 0;

		// TODO: display inserts the account information into an ostream
		virtual void display(std::ostream& os) const = 0;
	};

	// TODO: add prototype for Allocator function
	iAccount* CreateAccount(const char*, double);
}
#endif

