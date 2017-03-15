#ifndef STUDENTLISTCHILD_H
#define STUDENTLISTCHILD_H

#include "StudentList.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;

class StudentListChild : public StudentList
{
public:
	StudentListChild();
	void printStudentsInOrder() const;
	~StudentListChild();
};

#endif