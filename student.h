#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "object.h"
using std::string;

class Student : public Object{
	string name, code, major;
	double totalGrade;
	int tries;
public:
	Student(string, string, string);
	Student(string, string, string, double, int);
	void setNewGrade(double);
	string toString();
	double getAverage()const;
	string getCode()const;
	bool equals(Student*)const;
};
#endif