#include "Course.h"

// default constructor
Course::Course()
{
	courseGrade = '*';
	courseCredits = 0;
}

// setCourseInfo
void Course::setCourseInfo(const string& newName, const string& newNum, char newGrade, int newCredit)
{
	courseName = newName;
	courseNo = newNum;
	courseGrade = newGrade;
	courseCredits = newCredit;
}

// printCourseInfo
void Course::printCourseInfo(bool check) const
{
	cout.setf(ios::left);
	cout.width(6);
	cout << courseNo << "     ";
	cout.width(17);
	cout << courseName;
	cout << courseCredits << "    ";

	if (!check)
		cout << "***" << endl;
	else
		cout << "  " << courseGrade << endl;
}


// getCourseCredits
int Course::getCourseCredits() const
{
	return courseCredits;
}


// getCourseNumber
string Course::getCourseNumber() const
{
	return courseNo;
}


// getCourseName
string Course::getCourseName() const
{
	return courseName;
}


// getCourseGrade
char Course::getCourseGrade() const
{
	return courseGrade;
}

// destructor
Course::~Course()
{}
