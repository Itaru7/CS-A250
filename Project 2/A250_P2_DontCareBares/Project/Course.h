/*
Kishikawa, Itaru
Santiago, Casey
Palo, Ray

CS A250
Dec 10, 2015

Project 2
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Course
{
public:

	// default constructor
	Course();

	// setCourseInfo
	void setCourseInfo(const string& newName, const string& newNum, char newGrade, int newCredit);

	// printCourseInfo
	void printCourseInfo(bool check) const;

	// getCourseCredits
	int getCourseCredits() const;

	// getCourseNumber
	string getCourseNumber() const;

	// getCourseName
	string getCourseName() const;

	// getCourseGrade
	char getCourseGrade() const;

	// destructor
	~Course();

private:
    string courseName; 	
    string courseNo; 	
    char courseGrade;	
    int courseCredits;	
};

#endif
