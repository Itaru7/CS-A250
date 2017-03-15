#include "StudentListChild.h"

StudentListChild::StudentListChild()
{}

void StudentListChild::printStudentsInOrder() const
{
	map<string, int> myMap;
	vector<Student>::const_iterator iter;

	for (iter = studentList->begin(); iter != studentList->end(); iter++)
	{
		string first;
		string last;
		iter->getName(first, last);
		myMap.insert(make_pair(last + ", " + first, iter->getID()));
	}

	map<string, int>::const_iterator mIter;
	for (mIter = myMap.begin(); mIter != myMap.end(); mIter++)
		cout << mIter->second << " - " << mIter->first << endl;
}

StudentListChild::~StudentListChild()
{}