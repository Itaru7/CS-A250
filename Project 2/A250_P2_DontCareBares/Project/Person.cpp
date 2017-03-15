/* Implementation of the class Person */
#include "Person.h"

Person::Person()
{
	firstName = "N/A";
	lastName = "N/A";
}

Person::Person(const string& newFirst, const string& newLast)
{
	firstName = newFirst;
	lastName = newLast;
}

void Person::setName(const string& newFirst, const string& newLast)
{
	firstName = newFirst;
	lastName = newLast;
}

string Person::getLastName() const
{
	return lastName;
}
void Person::getName(string& newFirst, string& newLast) const
{
	newFirst = firstName;
	newLast = lastName;
}

void Person::printName() const
{
	cout << lastName << ", " << firstName << endl;
}

Person::~Person()
{}