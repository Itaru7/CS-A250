#include "StudentList.h"


// default constructor
StudentList::StudentList()
{
	studentList = new vector<Student>;
}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	studentList->push_back(newStudent);
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return static_cast<int>(studentList->size());
}

// printStudentByID
void StudentList::printStudentByID(int id, double rate) const
{
	if (studentList->empty())
		cerr << "List is empty." << endl;
	else
	{
		vector<Student>::const_iterator iter = studentList->begin();
		bool found = false;

		while (!found && iter != studentList->end())
		{
			if (iter->getID() == id)
			{
				iter->printStudentInfo(rate);
				found = true;
			}
			iter++;
		}

		if (!found)
			cout << "No student with ID " << id << " found in the list." << endl;
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNum) const
{
	if (studentList->empty())
		cerr << "List is empty." << endl;
	else
	{
		vector<Student>::const_iterator iter = studentList->begin();
		int count = 0;

		for (iter; iter != studentList->end(); iter++)
			if (iter->isEnrolledInCourse(courseNum))
			{
				iter->printStudentInfo();
				count++;
			}

		if (count == 0)
			cout << "No student enrolled in " << courseNum << "." << endl;
	}
}

// printStudentByName
void StudentList::printStudentByName(const string& last) const
{
	if (studentList->empty())
		cerr << "List is empty." << endl;
	else
	{
		vector<Student>::const_iterator iter = studentList->begin();
		int count = 0;

		for (iter; iter != studentList->end(); iter++)
			if (iter->getLastName() == last)
			{
				iter->printStudentInfo();
				count++;
			}
		
		if (count == 0)
			cout << "No student with last name " << last << " is inthe list." << endl;
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold(double rate) const
{
	if (studentList->empty())
		cerr << "No students in the list." << endl;
	else
	{
		vector<Student>::const_iterator iter = studentList->begin();
		int count = 0;

		for (iter; iter != studentList->end(); iter++)
			if (iter->isTuitionPaid())
			{
				iter->printStudentInfo();
				cout << "   Amount Due: $" << iter->billingAmount(rate) << endl;
				count++;
			}

		if (count == 0)
			cout << "There are no students on hold." << endl;
	}
}

// printAllStudents
void StudentList::printAllStudents(double rate) const
{
	if (studentList->empty())
		cerr << "List is empty." << endl;
	else
	{
		vector<Student>::const_iterator iter = studentList->begin();

		for (iter; iter != studentList->end(); iter++)
			iter->printStudentInfo(rate);
	}
}

// printStudentsToFile
void StudentList::printStudentsToFile(ofstream& out, double tuitionRate) const
{
	if (studentList->empty())
		cerr << "Cannot print. No students in the list." << endl;
	else
	{
		vector<Student>::iterator iter = studentList->begin();

		for (; iter != studentList->end(); iter++)
			iter->printStudentsToFile(out, tuitionRate);
	}
}

// destroyStudentList
void StudentList::destroyStudentList()
{
	delete studentList;
	studentList = NULL;
}

// destructor
StudentList::~StudentList()
{
	destroyStudentList();
}