/* Interface of the class Person */
/*
	Kishikawa, Itaru 
	CS A250

	Project 1
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