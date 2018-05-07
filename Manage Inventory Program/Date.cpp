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
#include<iostream>
#include<iomanip>
#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) {
		switch (errorCode) {
		case 0:
			errstate = NO_ERROR;
			break;
		case 1:
			errstate = CIN_FAILED;
			break;
		case 2:
			errstate = YEAR_ERROR;
			break;
		case 3:
			errstate = MON_ERROR;
			break;
		case 4:
			errstate = DAY_ERROR;
			break;
		}
	}

	Date::Date() {
		year = 0000;
		ymonth = 00;
		day = 00;
		comparator = 0;
		errCode(0);

	}

	Date::Date(int c_year, int c_month, int c_day) {
		int daycheck;
		if (c_year >= min_year && c_year <= max_year) {

			if (c_month >= 1 && c_month <= 12) {

				daycheck = mdays(c_month, c_year);
				if (daycheck >= 1 && daycheck <= 31) {
					year = c_year;
					ymonth = c_month;
					day = c_day;
					comparator = year * 372 + ymonth * 13 + day;
					errCode(0);
				}
				else {
					errCode(4);
					year = 0000;
					ymonth = 00;
					day = 00;
					comparator = 0;
				}
			}
			else {
				errCode(3);
				year = 0000;
				ymonth = 00;
				day = 00;
				comparator = 0;
			}
		}
		else {
			errCode(2);
			year = 0000;
			ymonth = 00;
			day = 00;
			comparator = 0;
		}
	}
	bool Date::isEmpty()const {
		bool emp;
		if (year == 0000 && ymonth == 00 && day == 0) {
			emp = true;
		}
		else {
			emp = false;
		}
		return emp;
	}

	bool Date::operator==(const Date& rhs) const {
		bool check;
		Date obj = *this;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (obj.comparator == rhs.comparator)
				check = true;
			else
				check = false;
		}
		else {
			check = false;
		}
		return check;
	}
	bool Date::operator!=(const Date& rhs) const {
		bool check;
		Date obj = *this;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (obj.comparator != rhs.comparator)
				check = true;
			else
				check = false;
		}
		else {
			check = false;
		}
		return check;
	}
	bool Date::operator<(const Date& rhs) const {
		bool check;
		Date obj = *this;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (obj.comparator < rhs.comparator)
				check = true;
			else
				check = false;
		}
		else {
			check = false;
		}
		return check;
	}

	bool Date::operator>(const Date& rhs) const {
		bool check;
		Date obj = *this;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (obj.comparator > rhs.comparator)
				check = true;
			else
				check = false;
		}
		else {
			check = false;
		}
		return check;
	}
	bool Date::operator<=(const Date& rhs) const {
		bool check;
		Date obj = *this;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (obj.comparator <= rhs.comparator)
				check = true;
			else
				check = false;
		}
		else {
			check = false;
		}
		return check;
	}
	bool Date::operator>=(const Date& rhs) const {
		bool check;
		Date obj = *this;
		if (!isEmpty() && !rhs.isEmpty()) {
			if (obj.comparator >= rhs.comparator)
				check = true;
			else
				check = false;
		}
		else {
			check = false;
		}
		return check;
	}

	int Date::errCode()const {
		return errstate;
	}
	bool Date::bad() const {
		bool test;
		if (errstate != NO_ERROR) {
			test = true;
		}
		else {
			test = false;
		}
		return test;
	}
	std::istream& Date::read(std::istream& istr) {
		char placeholder;

		istr >> year >> placeholder >> ymonth >> placeholder >> day;

		if (istr.fail()) {
			errCode(1);

		}
		else if (year<min_year || year>max_year) {
			errCode(2);
			year = 0;
			ymonth = 00;
			day = 00;
		}
		else if (ymonth < 1 || ymonth>12) {
			errCode(3);
			year = 0;
			ymonth = 00;
			day = 00;
		}
		else if (day<1 || day > mdays(ymonth, year)) {
			errCode(4);
			year = 0;
			ymonth = 00;
			day = 00;
		}

		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const {
		ostr << year << "/" << std::setw(2) << std::setfill('0') << ymonth << "/" << std::setw(2) << std::setfill('0') << day;
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Date& date) {
		date.read(istr);
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& date) {
		date.write(ostr);
		return ostr;
	}


}