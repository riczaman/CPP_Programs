/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.h
// Feb.09/18
// Ricky Zaman
// ID: 121942171
// Email: rzaman6@myseneca.ca

///////////////////////////////////////////////////////////
**********************************************************/

#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {

	const int max_name_length = 40; // max number of character in a name 40
	const int min_sin = 100000000;  // minimum social insurance number
	const int max_sin = 999999999;  // maximum social insurance number
	const int max_yrs = 4; // max number of tax years the object can remember 

	class CRA_Account {
		char m_familyName[max_name_length + 1];
		char m_givenName[max_name_length + 1];
		int  m_sin;
		int  tax_return_year[max_yrs]; 
		double  balance[max_yrs]; 
		int  year_stored; 

	public:
		void set(const char*, const char*, int);
		void display() const;
		bool isEmpty() const;
		void set(int, double); 
	};
}

#endif
