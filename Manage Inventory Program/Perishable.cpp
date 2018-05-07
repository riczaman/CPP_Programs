/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    April 07, 2018
Project: MS5
File:    Perishable.cpp
*******************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Perishable.h"

namespace AMA {

	Perishable::Perishable():Product('P') {
		//Base Product constructor will set the product name to P and put everything else in safe empty state
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const {
		Product::store(file, false);
		if (newLine==true) {
			
			file <<','<< Perishable::expiry() << std::endl; 
		}
		else {
			
			file <<','<< Perishable::expiry();
		}
		return file; 
	}

	std::fstream& Perishable::load(std::fstream& file) {
		Product::load(file);
		file.ignore(); 
		date_.read(file);
		file.ignore();
		return file; 
	}

	std::ostream& Perishable::write(std::ostream& os, bool linear) const {
		Product::write(os, linear);
		if (errproduct.isClear()) {
			if (linear == true) {
				os <<std::fixed<< Perishable::expiry(); 
			}
			else {
				os << std::endl; 
				os << " Expiry date: " << Perishable::expiry(); 
			}
		}
		return os; 
	}

	std::istream& Perishable::read(std::istream& is) {
		Date temp; 

		Product::read(is); 
		if (errproduct.isClear()) {
			std::cout << " Expiry date (YYYY/MM/DD): ";
			is >> temp;

			if (temp.errCode() == CIN_FAILED) {
				errproduct.message("Invalid Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == YEAR_ERROR) {
				errproduct.message("Invalid Year in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == MON_ERROR) {
				errproduct.message("Invalid Month in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else if (temp.errCode() == DAY_ERROR) {
				errproduct.message("Invalid Day in Date Entry");
				is.setstate(std::ios::failbit);
			}
			else {
				date_ = temp; 
			}
		}
		return is; 
		
	}

	const Date& Perishable::expiry() const {
		return date_;
	}



}