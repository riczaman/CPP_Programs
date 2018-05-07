/*
Author: Ricky Zaman
Student Id: 121942171
Email: rzaman6@myseneca.ca
Lab 9: Function Templates in Lab
Date: April 2, 2018
*/
#include<iostream>
#include<cstring>
#include<iomanip>
#include "Data.h"
using namespace std; 
namespace sict {
	// readRow extracts a single record from input and stores n data fields in data
	// - includes error checking: checks if the name of the row is valid.
	template <typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	// answers outputs statistics for visual validation of data
	
	void answers(const int* year, const int* population, const int* violentCrime,
		const double* violentCrimeRate, const int* grandTheftAuto, const int n) {

		// Q1: print the population change in millions of people
		// - print answer correct to 2 decimal places.
		// e..g "6.31 million";
		// note that population is an integer, so dividing by 1000000 would yield "6"
		int popchange = population[n - 1] - population[0];
		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is "; 
		cout << fixed;
		cout.precision(2); 
		cout << popchange / 1.0E6 << " million" << endl;  //use 1.0E6 instead of 1000000 to get a precise number




		// Q2. print whether violent crime rate has gone up or down between 2000 and 2005
		const char *v; 
		if (violentCrime[0] < violentCrime[n - 1]) {
			v = "up"; 
		}
		else {
			v = "down";
		}
		cout << "Violent Crime trend is " << v << endl; 





		// Q3 print the GTA number accurate to 0 decimal places
		double gta = average(grandTheftAuto, n) / 1.0E6;
		cout << "There are ";
		cout << fixed; 
		cout.precision(2); 
		cout << gta << " million Grand Theft Auto incidents on average a year" << endl; 




		// Q4. Print the min and max violentCrime rates
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;



	}
	template <typename T>
	T max(const T* data, int n) {
		T result = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (result < data[i])
				result = data[i];
		}
		return result; 
	}

	
	template <typename T>
	T min(const T* data, int n) {
		T result = LARGEST_NUMBER;
		for (int i = 0; i < n; i++) {
			if (result > data[i])
				result = data[i];
		}
		return result; 
	}

	
	template <typename T>
	T sum(const T* data, int n) {
		T total = 0; 
		for (int i = 0; i < n; i++) {
			total += data[i];
		}
		return total; 
	}

	
	template <typename T>
	double average(const T* data, int n) {
		double avg=0.0; 
		avg = sum(data, n) / n;
		return avg;
	}

	template <typename T>
	bool read(std::istream& input, T*data, int n) {
		bool check; 
		char comma; 
		T value; 

		for (int i = 0; i < n; i++) {
			input >> comma;
			if (comma != ',') {
				check = false;
			}
			else {

				if (input >> value) {
					data[i] = value;
					check = true;
				}
				else {
					check = false;
				}
			}
		}
		return check; 
	}

	bool readRow(std::istream& input, const char* name, double* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	bool readRow(std::istream& input, const char* name, int* data, int n) {
		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first

			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (std::strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}
	





}