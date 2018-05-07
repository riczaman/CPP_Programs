/*
Name:  Ricky Zaman
ID:    121942171
Email: rzaman6@myseneca.ca
Date:  March 18, 2018
File:  ErrorState.h
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA {
	//explicit = specifier not a return type
	ErrorState::ErrorState(const char* errorMessage) {
		if (errorMessage == nullptr) {
			msg = nullptr;
		}
		else {
			msg = new char[strlen(errorMessage) + 1];
			strcpy(msg, errorMessage);
		}
	}
	//=delete specifier which means it restricts copying does not need implementation
	//ErrorState::ErrorState(const ErrorState& em) 

	//=delete specifier 
	//ErrorState& ErrorState::operator=(const ErrorState& em) 

	ErrorState::~ErrorState() {
		delete[]msg;
		msg = nullptr;
	}

	void ErrorState::clear() {
		delete[]msg;
		msg = nullptr;
	}

	bool ErrorState::isClear() const {
		bool clear;
		if (msg == nullptr) {
			clear = true;
		}
		else {
			clear = false;
		}
		return clear;
	}

	void ErrorState::message(const char* str) {
		delete[]msg;
		msg = nullptr;
		msg = new char[strlen(str) + 1];
		strcpy(msg, str);

	}

	const char* ErrorState::message()const {
		return msg;
	}

	std::ostream& operator << (std::ostream& os, const ErrorState& error) {
		if (!error.isClear()) {
			os << error.message();
		}


		return os;
	}

}