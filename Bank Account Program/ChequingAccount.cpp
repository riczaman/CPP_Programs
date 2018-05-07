/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 28, 2018
Project: WS8 in Lab
File:    ChequingAccount.cpp
*******************************/

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double cbalance, double transfee, double monthendfee) :Account(cbalance){
		if (transfee > 0) {
			tfee = transfee;
		}
		else {
			tfee = 0.0;
		}

		if (monthendfee > 0) {
			mefee = monthendfee;
		}
		else {
			mefee = 0.0;
		}
	}



	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited

	bool ChequingAccount::credit(double cred) {
		bool check; 
		check = Account::credit(cred);
		Account::debit(tfee);

		return check; 
	}



	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	
	
	bool ChequingAccount::debit(double debt) {
		return Account::debit(debt + tfee); //function debit gives us a bool return
	}


	// monthEnd debits month end fee

	void ChequingAccount::monthEnd() {
		//monthy fee = month end + transaction
		Account::debit(mefee + tfee);
	}


	// display inserts account information into ostream os

	void ChequingAccount::display(std::ostream& os)const {
		os << "Account type: Chequing" << std::endl;
		os.setf(std::ios::fixed); //used to set to number to exact length 
		os.precision(2);
		os << "Balance: $" << balance() << std::endl;
		os << "Per Transaction Fee: " << tfee << std::endl;
		os << "Monthly Fee: " << mefee << std::endl;
	}





}