// Final Project Milestone 4 - iProduct Interface
// iProduct.h
// 2018-04-04
// Author: Ricky Zaman
// Email: rzaman6@myseneca.ca
// Student ID: 121942171
//////////////////////////////////////////////////

#ifndef AMA_iProduct_H_
#define AMA_iProduct_H_
#include<fstream>
namespace AMA {

	class iProduct {
	public:
		virtual std::fstream& store(std::fstream& file, bool newLine = true) const = 0;
		virtual std::fstream& load(std::fstream& file) = 0;
		virtual std::ostream& write(std::ostream& os, bool linear) const = 0;
		virtual std::istream& read(std::istream& is) = 0;
		virtual bool operator==(const char*) const = 0;
		virtual double total_cost() const = 0;
		virtual const char* name() const = 0;
		virtual void quantity(int) = 0;
		virtual int qtyNeeded() const = 0;
		virtual int quantity() const = 0;
		virtual int operator+=(int) = 0;
		virtual bool operator>(const iProduct&) const = 0;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);
	iProduct* CreateProduct();
	iProduct* CreatePerishable();


}


#endif 
