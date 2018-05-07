/************************************************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 24, 2018
Updated: April 10, 2018 added explanations & better spacing
Project: MS3
File:    Product.h
************************************************************/

#ifndef AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include <iostream>
#include "iProduct.h"
#include "ErrorState.h"

namespace AMA {
	const int max_sku_length = 7;
	const int max_unit_length = 10;
	const int max_name_length = 75;
	const double taxrate = 0.13;

	class Product: public iProduct {
		char product_type;
		char psku[max_sku_length + 1];
		char prod_description[max_unit_length + 1];
		char* pname;
		int units_on_hand;
		int units_needed;
		double price_no_tax;
		bool ptax;


	protected:
		ErrorState errproduct;
		void name(const char*);
		const char* name() const;
		const char* sku()const;
		const char* unit()const;
		bool taxed()const;
		double price()const;
		double cost() const;
		void message(const char*);
		bool isClear() const;

	public:
		Product();
		Product(char);
		Product(const char*, const char*, const char*);
		Product(const char* sku, const char* name, const char* unit, int qty, bool isTaxed, double price, int qtyNeeded);
		Product(const Product&);
		Product& operator=(const Product&);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iProduct&) const;
		int operator+=(int);

	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	std::istream& operator>>(std::istream&, iProduct&);
	double operator+=(double&, const iProduct&);



}

#endif 
