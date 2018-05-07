/********************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    April 07, 2018
Project: MS5
File:    Perishable.h
*******************************/

#ifndef AMA_PERISHABLE_H
#define AMA_PERISHABLE_H
#include <iostream>
#include "Product.h"
#include "Date.h"

namespace AMA {

	class Perishable : public Product {
		Date date_;

	public:
		Perishable(); 
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		const Date& expiry() const;




	};
}

#endif 
