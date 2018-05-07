/*
Author: Ricky Zaman
Student Id: 121942171
Email: rzaman6@myseneca.ca
Lab 9: Function Templates in Lab
Date: April 2, 2018
*/
#ifndef _DATA_H
#define _DATA_H
#include<iostream>
namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;
	
	// max returns the largest item in data
	template <typename T> 
	T max(const T*, int);

	// min returns the smallest item in data
	template <typename T>
	T min(const T*, int);


	// sum returns the sum of n items in data
	template <typename T>
	T sum(const T*, int);

	// average returns the average of n items in data
	template <typename T>
	double average(const T*, int);

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template <typename T>
	bool read(std::istream& input, T*data, int n);

	// display inserts n items of data into std::cout
	template <typename T>
	void display(const char* name, const T* data, int n) {
		std::cout.width(20);
		std::cout<< name;

		for (int i = 0; i < n; i++) {
			std::cout.width(COLUMN_WIDTH);
			std::cout<< data[i];
		}
		std::cout << std::endl;
	}

	template <typename T>
	bool readRow(std::istream& input, const char* name, const T* data, int n);
	bool readRow(std::istream& input, const char* name, int* data, int n);    //Had to include these because on matrix kept saying main fx 
	bool readRow(std::istream& input, const char* name, double* data, int n); //was trying to access them
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}
#endif 
