// Workshop 6 - Class with a Resource
// w6_Contact.cpp
// Ricky Zaman
// March 15, 2018

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
using namespace std;

namespace sict {

	Contact::Contact() {
		name[0] = '\0';
		phonenumber = nullptr;
		phonearray = 0;
	}



	Contact::Contact(const char*nm, const long long*pnumber, int arrnumber) {

		int country;
		int area;
		int restnum;
		int j = 0;


		if (nm != nullptr && nm[0] != '\0') {
			strncpy(name, nm, 19);
			name[19] = '\0';
		}
		else {
			*this = Contact();
		}



		if (pnumber != nullptr && pnumber[0] != '\0') {
			phonearray = 0;

			for (int i = 0; i < arrnumber; i++) {
				if (pnumber[i] > 10000000000 && pnumber[i] < 999999999999) {
					country = (pnumber[i] / 10000000000);
					area = (pnumber[i] % 10000000000) / 10000000;
					restnum = pnumber[i] % 10000000;

					if ((country > 0 && country <= 99) && (area > 100 && area <= 999) &&
						(restnum > 1000000 && restnum <= 9999999)) {
						phonearray++;
					}
				}
			}
			phonenumber = new (nothrow) long long[phonearray];
			for (int i = 0; i < arrnumber; i++) {
				if (pnumber[i] > 10000000000 && pnumber[i] < 999999999999) {
					country = (pnumber[i] / 10000000000);
					area = (pnumber[i] % 10000000000) / 10000000;
					restnum = pnumber[i] % 10000000;

					if ((country > 0 && country <= 99) && (area > 100 && area <= 999) &&
						(restnum > 1000000 && restnum <= 9999999)) {
						phonenumber[j] = pnumber[i];
						j++;

					}
				}
			}

		}
		else {
			phonenumber = nullptr;
			phonearray = 0;
		}

	}
	Contact::Contact(const Contact& source) {
		strncpy(name, source.name,19);
		name[19] = '\0'; 
		phonearray = source.phonearray;

		if (source.phonenumber != nullptr) {
			phonenumber = new (nothrow) long long[source.phonearray];

			for (int i = 0; i < phonearray; i++)
				phonenumber[i] = source.phonenumber[i];
		}
		else
			phonenumber = nullptr;

	}
	Contact::~Contact() {
		if (phonenumber != nullptr && phonenumber[0] != '\0') {
			delete[] phonenumber;
			phonenumber = nullptr;
		}
	}

	bool Contact::isEmpty()const {
		bool result;
		if (name[0] == '\0' && phonenumber == nullptr && phonenumber[0]=='\0' && phonearray == 0) {
			result = true;
		}
		else {
			result = false;
		}
		return result;
	}

	void Contact::display()const {

		if (isEmpty() == false && name[0]!='\0') {

			cout << name << endl;


			if (phonenumber != nullptr && phonenumber[0] != '\0') {
				for (int i = 0; i < phonearray; i++) {


					int cc = phonenumber[i] / 10000000000;
					int ac = (phonenumber[i] % 10000000000) / 10000000;
					int rmn = phonenumber[i] % 10000000;

					cout << "(+" << cc << ") " << ac << " " << rmn / 10000 << "-" << setw(4) << setfill('0') << rmn % 10000 << endl;

				}
			}
		}else
			cout << "Empty contact!" << endl;
		

	}

	Contact& Contact::operator=(const Contact&source) {
		if (this != &source) {
			strncpy(name, source.name, 19);
			name[19] = '\0';
			phonearray = source.phonearray;
			 
			if (source.phonenumber != nullptr) {
				delete[]phonenumber;
				phonenumber = new (nothrow) long long[phonearray];

				for (int i = 0; i < phonearray; i++)
					phonenumber[i] = source.phonenumber[i];
			}
			else
				phonenumber = nullptr;
		}

		return *this; 
	}

	Contact& Contact::operator+=(const long long newnumb) {
		int country;
		int area;
		int restnum;
	\
			if (newnumb > 10000000000 && newnumb < 999999999999) {
				country = (newnumb / 10000000000);
				area = (newnumb % 10000000000) / 10000000;
				restnum = newnumb % 10000000;

				if ((country > 0 && country <= 99) && (area > 100 && area <= 999) &&
					(restnum > 1000000 && restnum <= 9999999)) {

					long long* test = new (nothrow) long long[phonearray + 1];
					for (int i = 0; i < phonearray; i++) {
						test[i] = phonenumber[i];
					}
					phonearray += 1;
					test[phonearray - 1] = newnumb;
					delete[]phonenumber;
					phonenumber = test;

				}
			}
		
		
		return *this;
	}
}