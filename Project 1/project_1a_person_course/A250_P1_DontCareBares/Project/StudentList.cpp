#include "StudentList.h"


// default constructor
StudentList::StudentList()
{
	first = NULL;
	last = NULL;
	count = 0;
}

// addStudent
void StudentList::addStudent(const Student& newStudent)
{
	Node* newNode = new Node(newStudent , NULL);

	if (first == NULL)
	{
		first = newNode;
		last = newNode;
	}
	else
	{
		newNode->setNext(first);
		first = newNode;
	}

	count++;
}

// getNoOfStudents
int StudentList::getNoOfStudents() const
{
	return count;
}

// printStudentByID
void StudentList::printStudentByID(int id, double rate) const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		bool found = false;
		Node* temp = first;

		while (!found && temp != NULL)
		{
			if (id == temp->getStudent().getID())
			{
				temp->getStudent().printStudentInfo(rate);
				found = true;
			}
			temp = temp->getNext();
		}

		if (!found)
			cout << "No student with ID " << id << " found in the list;" << endl;
	}
}

// printStudentsByCourse
void StudentList::printStudentsByCourse(const string& courseNum) const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node* temp = first;
		int count = 0;

		while (temp != NULL)
		{
			if (temp->getStudent().isEnrolledInCourse(courseNum))
			{
				temp->getStudent().printStudentInfo();
				count++;
			}

			temp = temp->getNext();
		}

		if (count == 0)
			cout << "No student enrolled in " << courseNum << endl;
	}
}

// printStudentByName
void StudentList::printStudentByName(const string& last) const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node* temp = first;
		int count = 0;

		while (temp != NULL)
		{
			if (temp->getStudent().getLastName() == last)
			{
				temp->getStudent().printStudentInfo();
				count++;
			}
			temp = temp->getNext();
		}

		if (count == 0)
			cout << "No student with last name " << last << " is inthe list." << endl;
	}
}

// printStudentsOnHold
void StudentList::printStudentsOnHold(double rate) const
{
	if (first == NULL)
		cerr << "No students in the list." << endl;
	else
	{
		Node* temp = first;
		int count = 0;
		
		while (temp != NULL)
		{
			if (!temp->getStudent().isTuitionPaid())
			{
				temp->getStudent().printStudentInfo();
				cout << "\tAmount Due: $" << temp->getStudent().billingAmount(rate) << endl;
				count++;
			}
			temp = temp->getNext();
		}

		if (count == 0)
			cout << "There are no students on hold." << endl;
	}
}

// printAllStudents
void StudentList::printAllStudents(double rate) const
{
	if (first == NULL)
		cerr << "List is empty." << endl;
	else
	{
		Node* temp = first;
		while (temp != NULL)
		{
			temp->getStudent().printStudentInfo(rate);
			temp = temp->getNext();
		}
	}
}

// printStudentsToFile
void StudentList::printStudentsToFile(ofstream& out, double tuitionRate) const
{
	if (first == NULL)
		cerr << "Cannot print. No students in the list." << endl;
	else
	{
		Node* temp = first;
		while (temp != NULL)
		{
			temp->getStudent().printStudentsToFile(out, tuitionRate);
			temp = temp->getNext();
		}
	}
}

// destroyStudentList
void StudentList::destroyStudentList()
{
	while (first != NULL)
	{
		Node* temp = first;
		first = first->getNext();
		delete temp;
		temp = NULL;
	}

	first = NULL;
	last = NULL;
	count = 0;
}

// destructor
StudentList::~StudentList()
{
	destroyStudentList();
}