#include "student.h"
#include "varraylist.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

VArrayList* getStudentsFile();
Student* ask(VArrayList*);
void listStudents(VArrayList*);
void saveAndClose(VArrayList*);

int main(){
	srand(time(NULL));
   	VArrayList* students = getStudentsFile();
	int option; 
   	do {
   		cout << "What do you wanna do?" << endl;
   		cout << "1. List Students" << endl;
   		cout << "2. Ask" << endl;
   		cout << "3. Save and Close" << endl;
   		cout << "4. Close" << endl;
   		cin >> option;
   		if (option == 1) {
   			listStudents(students);
   		} else if (option == 2) {
   			ask(students);
   		} else if (option == 3) {
   			saveAndClose(students);
   			break;
   		} else if (option == 4) {
   			break;
   		} else {
   			cerr << "Invalid Option, try again" << endl;
   			continue;
   		}
   	} while(true);
   	cout << "Good Bye!!" << endl;
    return 0;
}

void listStudents(VArrayList* students) {
	for (int i = 0; i < students->size(); i++) {
		cout << i << endl;
		cout << static_cast<Student*> (students->get(i))->toString() << endl;
   	}

}

void saveAndClose(VArrayList* students) {
	stringstream ss;
	ofstream outputFile;
	for (int i = 0; i < students->size(); i++) {
		Student* selected = static_cast<Student*> (students->get(i));
		ss << selected->getCode() << "," << selected->getAverage() << "\n";
	}
	outputFile.open("grades.csv");
	outputFile << ss.str();
	outputFile.close();
}

Student* ask(VArrayList* students) {
	int	random = rand() % students->size();
   	Student* selected = static_cast<Student*> (students->get(random));

   	cout << "------------SELECTED STUDENT-----------" << endl;
   	cout << selected->toString();

   	double grade;
    cout << "What's the grade? (0-100): ";
    cin >> grade;

    selected->setNewGrade(grade);
   	cout << selected->toString();

}

VArrayList* getStudentsFile() {
	VArrayList* students = new VArrayList(5);
	ifstream studentsFile;
	string texto;
	if(ifstream("alumnos.csv")){
	    fstream studentsFile( "alumnos.csv");
	    string line;
	    int total = 0;
	    while( getline( studentsFile, line ) ) {
			size_t pos = 0;
			int totalAttr = 0;
	    	string atributes[3];
			while (pos < line.size()) {
				if (line.find(",") !=  std::string::npos) {
					pos = line.find(",");
				} else {
					pos = line.size();
				}
			    atributes[totalAttr] = line.substr(0, pos);
			    if (pos >= line.size()) {
			    	break;
			    }
			    line = line.substr(pos + 1, line.size());
			    totalAttr++;
			    pos = 0;
			}
			Student* newStudent = new Student(atributes[0], atributes[1], atributes[2]);
			students->insert(newStudent, total);
	    }
	}
	return students;
}