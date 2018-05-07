/*
Name:  Ricky Zaman
ID:    121942171
Email: rzaman6@myseneca.ca
Date:  March 18, 2018
File:  ErrorState.h
*/

#ifndef AMA_ErrorState_H
#define AMA_ErrorState_H
#include <iostream>
namespace AMA {

	class ErrorState {

		char* msg;

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;

	};

	std::ostream& operator<<(std::ostream& os, const ErrorState&);




}


#endif 
