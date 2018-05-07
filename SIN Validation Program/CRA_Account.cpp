/**********************************************************
// Workshop 3: Classes and Privacy
// CRA_Account.cpp
// Feb.09/18
// Ricky Zaman
// ID: 121942171
// Email: rzaman6@myseneca.ca

///////////////////////////////////////////////////////////
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CRA_Account.h"
#include <iomanip> //allows me to use setprecision  

using namespace std;

namespace sict {
	
	void CRA_Account::set(const char* fn, const char* gn, int sin_)
	{
		
		int sin = sin_;
		
		if (sin >= min_sin && sin <= max_sin && fn[0]!= '\0' && gn[0]!= '\0') {
			int sum = 0; //variable needed to check the weighted sum of SIN
			int i; 
			for (i = 0; i < 5; i++) { //i<5 because the 9 digit SIN goes through 5  
									  //divisions of 100 until it becomes a number less than 0.
				int mod = sin % 100;
				int alt = mod % 10; 
				int otherNumbers = (mod / 10) * 2;
				sum += alt + (otherNumbers / 10) + (otherNumbers % 10); 
				sin = sin / 100; 
			}
			 //the sum which includes the check digit has to be completely divisble
			// by 10 (no remainder) for the SIN to be valid. 

			if (sum % 10 == 0) {
				strncpy(m_familyName, fn, max_name_length + 1);
				m_familyName[max_name_length] = '\0';
				strncpy(m_givenName, gn, max_name_length + 1);
				m_givenName[max_name_length] = '\0';
				m_sin = sin_;
				for (int j = 0; j < max_yrs; j++) {
					balance[j] = 0;   //initializes everything to 0
					year_stored = 0;
				}
			}
		}
		else {
			m_familyName[0] = '\0';
			m_givenName[0] = '\0';
			m_sin = 0;
		}
		
	}

	// set adds a year and balanace to the return records for the
	// current object
	//
	void CRA_Account::display() const
	{
		if (isEmpty()==false) {
			cout << "Family Name: " << m_familyName << endl;
			cout << "Given Name : " << m_givenName << endl;
			cout << "CRA Account: " << m_sin << endl;
			cout << fixed << setprecision(2); // this ensures the cout has 2 digits 
			for (int i = 0; i < year_stored; i++) {
				cout << "Year (" << tax_return_year[i] << ") ";
				if (balance[i] > 2.00) {
					cout << "balance owing: " << balance[i] << endl; 
				}
				else if (balance[i] < -2.00) {
					cout << "refund due: " << -balance[i] << endl; 
				}
				else {
					cout << "No balance owing or refund due!" << endl;
				}
			}
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}

	
	bool CRA_Account::isEmpty() const {
		return m_sin==0;
	}

	void CRA_Account::set(int yr, double bal) {
		if (isEmpty()==0 && year_stored < max_yrs) {
			tax_return_year[year_stored] = yr;
			balance[year_stored] = bal; 
			year_stored++; 
		}

	}
}
