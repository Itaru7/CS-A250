/*
Kishikawa, Itaru
Santiago, Casey
Palo, Ray

CS A250
Dec 10, 2015

Project 2
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

using namespace std;

class Student : public Person
{
public:

	//Default constructor   
	Student();

	//setStudentInfo
	void setStudentInfo(const string& newFirst, const string& newLast, int newId, bool check, const vector<Course>& newCourses);

	//getID
	int getID() const;

	//getNumberOfCourses
	int getNumberOfCourses() const;

	//getCreditsEnrolled
	int getCreditsEnrolled() const;

	//isTuitionPaid
	bool isTuitionPaid() const;

	//isEnrolledInCourse
	bool isEnrolledInCourse(const string& courseNum) const;

	//getGpa
	double getGpa() const;

	//billingAmount
	double billingAmount(double bill) const;

	//printStudentInfo
	void printStudentInfo() const;

	//printStudentInfo
	void printStudentInfo(double tuitionRate) const;

	//getCoursesEnrolled
	vector<Course> getCoursesEnrolled() const;

	// printStudentsToFile
	void printStudentsToFile(ofstream& out, double tuitionRate);

	//Destructor
	~Student();

private:
	int studentID;
	int numberOfCourses;
	bool tuitionWasPaid;
	vector<Course> coursesEnrolled;
};

#endif


