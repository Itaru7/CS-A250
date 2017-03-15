#include "Student.h"

//Default constructor   
Student::Student()
{
	studentID = 0;
	numberOfCourses = 0;
	tuitionWasPaid = false;
}

//setStudentInfo
void Student::setStudentInfo(const string& newFirst, const string& newLast, int newId, 
							bool check, const vector<Course>& newCourses)
{
	setName(newFirst, newLast);
	studentID = newId;
	tuitionWasPaid = check;
	numberOfCourses = static_cast<int> (newCourses.size());
	coursesEnrolled = newCourses;
}

//getID
int Student::getID() const
{
	return studentID;
}

//getNumberOfCourses
int Student::getNumberOfCourses() const
{
	return numberOfCourses;
}

//getCreditsEnrolled
int Student::getCreditsEnrolled() const
{
	int result = 0;

	for (int i = 0; i < numberOfCourses; i++)
		result += coursesEnrolled[i].getCourseCredits();

	return result;
}

//isTuitionPaid
bool Student::isTuitionPaid() const
{
	return tuitionWasPaid;
}

//isEnrolledInCourse
bool Student::isEnrolledInCourse(const string& courseNum) const
{
	unsigned int i = 0;
	bool check = false;

	while (!check && i < coursesEnrolled.size())
	{
		if (coursesEnrolled[i].getCourseNumber() == courseNum)
			check = true;
		i++;
	}

	return check;

}

//getGpa
double Student::getGpa() const
{
	double totalNum = 0.0;

	for (unsigned int i = 0; i < coursesEnrolled.size(); i++)
	{
		switch (coursesEnrolled[i].getCourseGrade())
		{
			case 'A':
				totalNum += 4.0 * coursesEnrolled[i].getCourseCredits();
				break;
			case 'B':
				totalNum += 3.0 * coursesEnrolled[i].getCourseCredits();
				break;
			case 'C':
				totalNum += 2.0 * coursesEnrolled[i].getCourseCredits();
				break;
			case 'D':
				totalNum += 1.0 * coursesEnrolled[i].getCourseCredits();
				break;
			default:
				totalNum += 0.0;
				break;
		}
	}

	return totalNum / getCreditsEnrolled();
}

//billingAmount
double Student::billingAmount(double bill) const 
{
	return getCreditsEnrolled() * bill;
}

//printStudentInfo
void Student::printStudentInfo() const
{
	cout << studentID << " - ";
	printName();
}

//printStudentInfo
void Student::printStudentInfo(double tuitionRate) const
{
	cout << "Student Name: ";
	printName();
	cout << endl;

	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses enrolled: " << numberOfCourses << endl;
	cout << endl;
	cout << "Course No  Course Name  Credits Grade" << endl;

	for (int i = 0; i < numberOfCourses; i++)
		coursesEnrolled[i].printCourseInfo(tuitionWasPaid);	

	cout << endl;
	cout << "Total number of credit hours: " << getCreditsEnrolled() << endl;

	if (!tuitionWasPaid)
	{
		cout << "*** Grades are being held for not paying the tuition." << endl;
		cout << "Amount Due: $" << billingAmount(tuitionRate) << endl;
	}
	else
		cout << "Current Term GPA: " << setprecision(2) << showpoint << fixed << getGpa() << endl;
	
	cout << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << endl;
}

//getCoursesEnrolled
vector<Course> Student::getCoursesEnrolled() const
{
	return coursesEnrolled;
}

// printStudentsToFile
void Student::printStudentsToFile(ofstream& out, double tuitionRate)
{
	string first, last;
	Person::getName(first, last);
	out << "Student Name: ";
	out << last << ", " << first << endl;
	out << endl;

	out << "Student ID: " << studentID << endl;
	out << "Number of courses enrolled: " << numberOfCourses << endl;
	out << endl;
	out << "Course No  Course Name  Credits Grade" << endl;

	for (int i = 0; i < numberOfCourses; i++)
	{
		out.setf(ios::left);
		out.width(6);
		out << coursesEnrolled[i].getCourseNumber() << "     ";
		out.width(17);
		out << coursesEnrolled[i].getCourseName();
		out << coursesEnrolled[i].getCourseCredits() << "    ";

		if (!tuitionWasPaid)
			out << "***" << endl;
		else
			out << "  " << coursesEnrolled[i].getCourseGrade() << endl;
	}

	out << endl;
	out << "Total number of credit hours: " << getCreditsEnrolled() << endl;

	if (!tuitionWasPaid)
	{
		out << "*** Grades are being held for not paying the tuition." << endl;
		out << "Amount Due: $" << billingAmount(tuitionRate) << endl;
	}
	else
		out << "Current Term GPA: " << setprecision(2) << showpoint << fixed << getGpa() << endl;

	out << endl;
	out << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-" << endl;
	out << endl;
}

//Destructor
Student::~Student()
{}