#include "student.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Student::Student(string name, string code, string major):name(name),code(code),major(major), tries(0), totalGrade(0){}

Student::Student(string name, string code, string major, double totalGrade, int tries):name(name),code(code),major(major), totalGrade(totalGrade), tries(tries){}
string Student::toString(){
	stringstream ss;
	ss 	<< "---------------------------------------" << endl
		<< "Name: " << name << endl
		<< "Code: " << code << endl
		<< "Major: " << major << endl
		<< "Average: " << this->getAverage() << endl
		<< "Total Tries: " << tries << endl
		<< "---------------------------------------" << endl;
	return ss.str();
}

void Student::setNewGrade(double nGrade){
	totalGrade += nGrade;
	tries++;
}
double Student::getAverage() const{
	return tries == 0 ? 0 : totalGrade / tries;
}
string Student::getCode() const{
	return code;
}
bool Student::equals(Student* otherStudent) const{
	return code == otherStudent->getCode();
}