// Workshop 6 - Class with a Resource
// w6_Contact.h
// Ricky Zaman
// March 15, 2018

#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
namespace sict {
	class Contact {
		char name[20];
		long long* phonenumber;
		int phonearray;




	public:
		Contact();
		Contact(const char*, const long long*, int);
		Contact(const Contact&);
		~Contact();
		void display()const;
		bool isEmpty()const;
		Contact& operator=(const Contact&);
		Contact& operator+=(const long long);


	};
}
#endif