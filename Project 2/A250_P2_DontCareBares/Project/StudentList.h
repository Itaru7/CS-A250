#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StudentList
{
public:

	// default constructor
	StudentList();

	// addStudent
	void addStudent(const Student& newStudent);

	// getNoOfStudents
	int getNoOfStudents() const;

	// printStudentByID
	void printStudentByID(int id, double rate) const;

	// printStudentsByCourse
	void printStudentsByCourse(const string& courseNum) const;

	// printStudentByName
	void printStudentByName(const string& last) const;

	// printStudentsOnHold
	void printStudentsOnHold(double rate) const;

	// printAllStudents
	void printAllStudents(double rate) const;

	// printStudentsToFile
	void printStudentsToFile(ofstream& out, double tuitionRate) const;

	// destroyStudentList
	void destroyStudentList();

	// destructor
	~StudentList();

protected:
	vector<Student>* studentList;
};

#endif

