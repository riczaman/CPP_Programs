// Final Project Milestone 1
//
// Version 1.0
// Date: March 12, 2018
// Author: Ricky Zaman
// Description: Date Class
// Student ID: 121942171
// Email: rzaman6@myseneca.ca 
//
//
// Revision History
// -----------------------------------------------------------
// Name: Ricky Zaman   Date: March 12, 2018   Reason:       
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H
#include <iostream>
namespace AMA {

	const int min_year = 2000;
	const int max_year = 2030;
	const int NO_ERROR = 0;       //better to use const in c++ as opposed to macro directives 
	const int CIN_FAILED = 1;     //istream failed 
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int DAY_ERROR = 4;

	class Date {
		int year; //4 digit int between min_year & max_year
		int ymonth; //month of the year, number between 1 and 12
		int day; //day of the month set by mdays, feb has 29 days in a leap year
		int comparator;  //used to compare 2 date objects 
		int errstate;  //validates a date object or returns the reference to an error 

		int mdays(int, int)const;
		void errCode(int errorCode);
	public:
		Date();
		Date(int, int, int);
		bool isEmpty()const;

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode()const;
		bool bad() const;

		std::istream& read(std::istream&);
		std::ostream& write(std::ostream&) const;


	};

	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);





}
#endif