/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 28, 2018
Project: WS8 in Lab
File:    ChequingAccount.h
*******************************/

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount: public Account {

		double tfee; 
		double mefee; 

	public:
		// TODO: constructor initializes account balance and transaction fee
		ChequingAccount(double, double, double);

		// TODDO: credit adds +ve amount to the balance
		bool credit(double);

		// TODO: debit subtracts a +ve amount from the balance
		bool debit(double);

		// TODO: month end
		void monthEnd();

		// TODO: display inserts the account information into an ostream
		void display(std::ostream&)const;

	};
}
#endif
