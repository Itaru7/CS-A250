/* Interface of the class Person */
/*
Kishikawa, Itaru
Santiago, Casey
Palo, Ray

CS A250
Dec 10, 2015

Project 2
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
		Person();
		Person(const string& newFirst, const string& newLast);
		void setName(const string& newFirst, const string& newLast);
		string getLastName() const;
		void getName(string& newFirst, string& newLast) const;
		void printName() const;
		~Person();

	private:
		string lastName;
		string firstName;
};

#endif