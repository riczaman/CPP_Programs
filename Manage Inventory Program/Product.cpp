/***********************************************************
Name:    Ricky Zaman
ID:      121942171
Email:   rzaman6@myseneca.ca
Date:    March 24, 2018
Updated: April 10, 2018 added explanations & better spacing
Project: MS3
File:    Product.cpp
***********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "ErrorState.h"
#include "Product.h"
using namespace std;

namespace AMA {

	/*This function checks if the incoming const char string is null if it is not then I 
	dyamically create memory for the pname data member and then copy the string contents
	of the incoming pointer into the pname data member*/

	void Product::name(const char* prodname) {
		if (prodname == nullptr) {
			delete[] pname;
		}
		else {
			pname = new (nothrow) char[strlen(prodname) + 1];
			strcpy(pname, prodname);
		}
	}

	//Returns the pname data member 

	const char* Product::name() const {
		return pname;
	}

	/*This function checks if the ptax data member is true if it is then the tax is added
	to the price and this double is returned if !ptax then return the double with value 
	of just the price with NO tax included*/

	double Product::cost() const {
		double tcost;
		if (ptax == true) {
			tcost = price_no_tax + (price_no_tax*taxrate);
		}
		else {
			tcost = price_no_tax;
		}
		return tcost;
	}
	
	/*This function recieves a string holding an error message and then calls the Errorstate function 
    message using an Errorstate object defined in Product.h to dynamically store the incoming string 
	in the ErrorState object defined in Product.h*/

	void Product::message(const char* errmessage) {
		errproduct.message(errmessage);
	}

	//This function checks if the ErrorState Object is clear 

	bool Product::isClear() const {
		bool clr;

		if (errproduct.isClear()) {
			clr = true;
		}
		else {
			clr = false;
		}
		return clr;
	}

	/*This is the zero parameter constructor by default it sets the product type to N
	and then it sets the current object to a safe empty state*/

	Product::Product() {
		product_type = 'N';
		psku[0] = '\0';
		prod_description[0] = '\0';
		pname = nullptr;
		units_on_hand = 0;
		units_needed = 0;
		price_no_tax = 0.0;
		ptax = true;
	}

	/*One parameter constructor that accepts a character and sets the product_type to 
	the incoming character and then sets the current object to a safe empty state*/

	Product::Product(char n) {
		product_type = n;
		psku[0] = '\0';
		prod_description[0] = '\0';
		pname = nullptr;
		units_on_hand = 0;
		units_needed = 0;
		price_no_tax = 0.0;
		ptax = true;
	}

	/*Three parameter construct created to match the constructor call in MyProduct.cpp. This
	constructor checks if the current object is not empty if it is not empty then it will store
	the sku, name and unit into the respective data members. If the current object is empty
	it sets these data members to a safe empty state. Also, the function name() is called
	to store the pname dynamically.*/

	Product::Product(const char*sku, const char*name, const char*unit) {
		if (!isEmpty()) {
			Product::name(name);
			strcpy(psku, sku);
			strcpy(prod_description, unit);

		}
		else {
			psku[0] = '\0';
			prod_description[0] = '\0';
			pname = nullptr;

		}
	}

	/*7 parameter constructor, checks if the current object is empty if not stores the incoming data into 
	the current object. Once again the function name() is called to allocate memory dynamically for name. 
	Else set the object to a safe empty state*/

	Product::Product(const char* sku, const char* pname, const char* unit, int qty, bool isTaxed, double price, int qtyNeeded) {
		if (!isEmpty()) {
			name(pname);
			strcpy(psku, sku);
			strcpy(prod_description, unit);
			units_on_hand = qty;
			ptax = isTaxed;
			price_no_tax = price;
			units_needed = qtyNeeded;
		}
		else {
			psku[0] = '\0';
			prod_description[0] = '\0';
			pname = nullptr;
			units_on_hand = 0;
			units_needed = 0;
			price_no_tax = 0.0;
			ptax = true;
		}
	}

	/*Copy Constructor this recieves an unmodifiable (const) reference to a Product object
	and then copies it to the current object. Also if the reference Product object contains 
	a pname value that is not equal to nullptr then call the name() function to dynamically
	allocate memory for the current objects pname, else, set the pname of the current object
	to nullptr*/

	Product::Product(const Product& newproduct) {

		strcpy(psku, newproduct.psku);
		strcpy(prod_description, newproduct.prod_description);
		units_on_hand = newproduct.units_on_hand;
		ptax = newproduct.ptax;
		price_no_tax = newproduct.price_no_tax;
		units_needed = newproduct.units_needed;

		if (newproduct.pname != nullptr) {
			name(newproduct.pname);
		}
		else {
			pname = nullptr;
		}
	}

	/*The copy assignment operator is similair to the copy constructor however it deals with an already
	existing object. Also this function returns a reference to the current object.*/

	Product& Product::operator=(const Product& newproduct) {
		if (this != &newproduct) {
			product_type = newproduct.product_type;
			strcpy(psku, newproduct.psku);
			strcpy(prod_description, newproduct.prod_description);
			units_on_hand = newproduct.units_on_hand;
			ptax = newproduct.ptax;
			price_no_tax = newproduct.price_no_tax;
			units_needed = newproduct.units_needed;

			if (newproduct.pname != nullptr) {
				name(newproduct.pname);
			}
			else {
				pname = nullptr;
			}
		}
		return *this;
	}

	//Deconstructor used to deallocate any dynamically allocated memory

	Product::~Product() {
		delete[]pname;
		pname = nullptr;
	}

	/*The store function recieves a reference to a fstream object as well as a bool value
	and then inserts into the fstream object the product type as the first field followed by the 
	rest of the data in the current object seperated by commas. If the bool is true then inserts
	a newline at the end and returns a reference to the file*/

	std::fstream& Product::store(std::fstream& file, bool newLine) const {
		if (file.is_open()) {

			file << product_type << ",";
			file << Product::sku() << ",";
			file << Product::name() << ",";
			file << Product::unit() << ",";
			file << Product::taxed() << ",";
			file << Product::price() << ",";
			file << Product::quantity() << ",";
			file << Product::qtyNeeded();

			if (newLine == true) {
				file << endl;
			}
	
		}
		return file;
	}

	/*The Load function also recieves a reference to a fstream object. First a temporary Product
	object is created and dynamic memory is allocated for the pname of that temp object and then
	we check if the file is open if it is then we extract each line and input it into the temp
	object. I used getline for the char strings to ensure I got the right string and delimited them
	with the comma. I also used file.ignore(1) to ignore commas for the other data. After this 
	I copy assign the temp object to the current object. Then deallocate the memory for the name
	data of the temp object and then finally return a reference to the file*/
	 
	std::fstream& Product::load(std::fstream& file) {
	
		Product prod; 
		prod.pname = new char[max_name_length + 1];

		if (file.is_open()) {
	
			file.getline(prod.psku, max_sku_length, ',');
			file.getline(prod.pname, max_name_length, ',');
			file.getline(prod.prod_description, max_unit_length, ',');
			file >> prod.ptax;
			file.ignore(1);
			file >> prod.price_no_tax;
			file.ignore(1); 
			file >> prod.units_on_hand;
			file.ignore(1);
			file >> prod.units_needed;

		
			
		
			*this = prod; 				
		}
		delete[] prod.pname;
		prod.pname = nullptr;

		return file;
	}

	/*The write function recieves a reference to a ostream object as well as a bool value
	Call os.clear to clear any unwanted characters in the buffer. Then check if there are
	no error messages. Then if the bool is true display the data on a single line seperated
	by vertical lines. Had to use iomanip to setw and I also had to setfill an empty space 
	because on matrix padding zeros showed up. If the bool is false display the data with 
	data descriptions on seperate lines. Then return the ostream reference. */

	std::ostream& Product::write(std::ostream& os, bool linear) const {
		os.clear();
		if (errproduct.isClear()) {
			if (linear == true) {

				os << setfill(' ')<<setw(7) << left << Product::sku() << "|";
				os << setw(20) << left << Product::name() << "|";
				if (psku[0] != '\0') { //had to do this because matrix was not showing the 0 values
					os << setfill(' ')<<setw(7) << fixed << right << setprecision(2) << Product::cost() << "|";
				}
				else {
					os << setw(7) << fixed << right << setprecision(2) << 0.0 << "|";
				}
				if (psku[0] != '\0') {
					os << setw(4) << right << Product::quantity() << "|";
				}
				else {
					os << setw(4) << right << 0 << "|";
				}
				os << setw(10) << left << Product::unit() << "|";
				if (psku[0] != '\0') {
					os << setw(4) << right << Product::qtyNeeded() << "|";
				}
				else {
					os << setw(4) << right << 0 << "|";
				}
			}
			else {
				os << " Sku: " << Product::sku() << endl;
				os << " Name (no spaces): " << Product::name() << endl;
				os << " Price: " << Product::price() << endl;

				if (Product::taxed() == true) {
					os << " Price after tax: " << fixed << Product::cost() << endl;
				}
				else {
					os << " Price after tax:  N/A" << endl;
				}
				os << " Quantity on Hand: " << Product::quantity() <<" "<<Product::unit()<< endl;
				os << " Quantity needed: " << Product::qtyNeeded();

			}
		}
		else {
			os << errproduct.message();
		}
		return os;
	}

	/*The read function recieves a reference to an istream object and I created temp data members
	to input the data into. I check for any failures in the istream and if there was a failure then
	I just returned istream without copying the data into the current object. Also, set the failure 
	bits and appropriate error messages if failures occured during the input. If there are no
	failures then I can copy the temp values into the current object. */

	std::istream& Product::read(std::istream& is) {
		char sku_[max_sku_length + 1];
		char tname[max_name_length + 1];
		char unit[max_unit_length + 1];
		int quantity;
		int	qtyNeeded;
		double price_;
		char taxed_;

		errproduct.clear();

		cout << " Sku: ";
		is >> sku_;
		if (is.fail()) {
			return is;
		}
		else {
			strcpy(psku, sku_);
		}

		cout << " Name (no spaces): ";
		is >> tname;
		if (is.fail()) {
			return is;
		}
		else {
			Product::name(tname);
		}

		cout << " Unit: ";
		is >> unit;
		if (is.fail()) {
			return is;
		}
		else {
			strcpy(prod_description, unit);
		}

		if (errproduct.isClear()) {
			cout << " Taxed? (y/n): ";
			is >> taxed_;
			if (is.fail()) {
				errproduct.message("Only (Y)es or (N)o are acceptable");
				is.setstate(std::ios::failbit);
			}
			else {
				if (taxed_ == 'Y' || taxed_ == 'y' || taxed_ == 'N' || taxed_ == 'n') {
					if (taxed_ == 'Y' || taxed_ == 'y') {
						ptax = true;
					}
					else {
						ptax = false;
					}
				}
				else {
					errproduct.message("Only (Y)es or (N)o are acceptable");
					is.setstate(std::ios::failbit);
				}
			}
		}
		else {
			return is;
		}

		if (errproduct.isClear()) {
			cout << " Price: ";
			is >> price_;
			if (is.fail()) {
				errproduct.message("Invalid Price Entry");
			}
			else {
				price_no_tax = price_;
			}
		}
		else {
			return is;
		}

		if (errproduct.isClear()) {
			cout << " Quantity on hand: ";
			is >> quantity;
			if (is.fail()) {
				errproduct.message("Invalid Quantity Entry");
			}
			else {
				units_on_hand = quantity;
			}
		}
		else {
			return is;
		}

		if (errproduct.isClear()) {
			cout << " Quantity needed: ";
			is >> qtyNeeded;
			if (is.fail()) {
				errproduct.message("Invalid Quantity Needed Entry");
			}
			else {
				units_needed = qtyNeeded;
			}
		}
		else {
			return is;
		}

		return is;
	}

	/*Recieves a unmodifiable cstring and returns true if it matches the psku of the current object.*/
	bool Product::operator==(const char* newsku) const {
		bool check;
		if (strcmp(psku, newsku) == 0) {
			check = true;
		}
		else {
			check = false;
		}
		return check;
	}

	//returns the price of all units on hand including the tax price
	double Product::total_cost() const {
		double total;
		total = (units_on_hand)* (price_no_tax + (price_no_tax*taxrate));
		return total;
	}

	//This function recieves an int value and resets the units on hand to this int value
	void Product::quantity(int pqty) {
		units_on_hand = pqty;
	}

	//Function used to see if the object is in a safe empty state. 
	bool Product::isEmpty() const {
		bool emp;
		if (psku[0] == '\0' && pname == nullptr && prod_description[0] == '\0' && units_on_hand == 0 && units_needed == 0
			&& price_no_tax == 0 && ptax == true) {
			emp = true;
		}
		else {
			emp = false;
		}
		return emp;
	}


	int Product::qtyNeeded() const {
		return units_needed;
	}

	int Product::quantity() const {
		return units_on_hand;
	}

	/*This bool function recieves an unmodifiable reference to a string and then
	a strlen comparison is done between the recieved sku string and the string of the
	current object. Returns true if the current object sku is greater than the recieved
	sku string.*/

	bool Product::operator>(const char* newsku) const {
		bool skutest;
		if (strlen(psku) > strlen(newsku)) {
			skutest = true;
		}
		else {
			skutest = false;
		}
		return skutest;
	}
	/*Similair to the function above but now it has been modified such that it can recieve
	a reference to any object in the hierarchy and it compares the name length. */

	bool Product::operator>(const iProduct& obj) const {
		bool nameprod;
		if (strlen(pname) > strlen(obj.name())) {
			nameprod = true;
		}
		else {
			nameprod = false;
		}
		return nameprod;
	}

	/*This function recieves and int value and if that value is a positive number 
	it gets added to the units on hand if it is not a positive value then just
	return units on hand with no change.*/

	int Product::operator+=(int newunits) {
		if (newunits > 0) {
			units_on_hand += newunits;
		}
		return units_on_hand;
	}

	/*This helper recieves a reference to an ostream object and a reference 
	to any object in the hierarchy and then inserts this object into the ostream
	and returns a reference to the ostream*/

	std::ostream& operator<<(std::ostream& os, const iProduct& prod) {
		prod.write(os, true);
		return os;
	}

	/*This helper recieves a reference to an istream object and a reference
	to any object in the hierarchy and then extracts the data from the object
	in the istream and then returns a reference to istream*/

	std::istream& operator>>(std::istream& is, iProduct& prod) {
		prod.read(is);
		return is;
	}

	/*This helper recieves a double and a reference to any object
	in the hierarchy and then adds the total cost of the object
	to the recieved double and then returns that double*/

	double operator+=(double& total, const iProduct& obj) {
		total += obj.total_cost();
		return total;
	}


	/*These last functions are just used to return values from the current object*/

	const char* Product::sku()const {
		return psku;
	}

	const char* Product::unit()const {
		return prod_description;
	}

	bool Product::taxed()const {
		return ptax;
	}

	double Product::price()const {
		return price_no_tax;
	}




}