#include <string>
#include <iostream>
#include "roster.h"
using namespace std;

//default constructor
Roster::Roster() {
	amount = 0;
	lastIndex = -1;
	classRosterArray = nullptr;
}

//constructor
Roster::Roster(int numberStudents) {
	amount = numberStudents;
	lastIndex = -1;
	classRosterArray = new Student * [numberStudents];
}

//add student to roster function
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	classRosterArray[lastIndex] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

//Parse function
void Roster::parse(string data) {
	if (lastIndex < amount) {
		
		lastIndex++;

		//Student ID
		size_t rhs = data.find(",");
		string item1 = data.substr(0, rhs);

		//First Name
		size_t lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string item2 = data.substr(lhs, rhs - lhs);

		//Last Name
		size_t lhs2 = rhs + 1;
		rhs = data.find(",", lhs2);
		string item3 = data.substr(lhs2, rhs - lhs2);

		//Email
		size_t lhs3 = rhs + 1;
		rhs = data.find(",", lhs3);
		string item4 = data.substr(lhs3, rhs - lhs3);

		//Age
		size_t lhs4 = rhs + 1;
		rhs = data.find(",", lhs4);
		int item5 = stoi(data.substr(lhs4, rhs - lhs4));

		//Day 1
		size_t lhs5 = rhs + 1;
		rhs = data.find(",", lhs5);
		int item6 = stoi(data.substr(lhs5, rhs - lhs5));

		//Day 2
		size_t lhs6 = rhs + 1;
		rhs = data.find(",", lhs6);
		int item7 = stoi(data.substr(lhs6, rhs - lhs6));

		//Day 3
		size_t lhs7 = rhs + 1;
		rhs = data.find(",", lhs7);
		int item8 = stoi(data.substr(lhs7, rhs - lhs7));

		//Degree
		size_t lhs8 = rhs + 1;
		rhs = data.find(",", lhs8);
		string item9 = data.substr(lhs8, rhs - lhs8);

		DegreeProgram degree = DegreeProgram::SECURITY;
		if (item9 == "NETWORK") {
			degree = DegreeProgram::NETWORK;
		}
		else if (item9 == "SOFTWARE") {
			degree = DegreeProgram::SOFTWARE;
		}
		add(item1, item2, item3, item4, item5, item6, item7, item8, degree);
	}
}

//Remove function
void Roster::remove(string studentId) {
	bool find = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (studentId == classRosterArray[i]->GetstudentId()) {
			find = true;
			classRosterArray[i] = nullptr;

			lastIndex--;
			for (i = i; i <= lastIndex; i++) {
				classRosterArray[i] = classRosterArray[i + 1];
			}
		}
	}
	if (find == true) {
		cout << studentId << " removed" << endl;
	}
	else {
		cout << studentId << " not found" << endl;
	}
}

//Print all function
void Roster::printAll() {
	cout << "Displaying all students:" << endl;
	for (int i = 0; i <= lastIndex; i++) {
		(classRosterArray)[i]->print();
	}
	cout << endl;
}

//Average course days function
void Roster::printAverageDaysInCourse(string studentId) {
	for (int i = 0; i <= lastIndex; i++) {
		if (studentId == classRosterArray[i]->GetstudentId()) {
			int averageDays = 0;
			averageDays = (classRosterArray[i]->GetdaysInCourse()[0] + classRosterArray[i]->GetdaysInCourse()[1] + classRosterArray[i]->GetdaysInCourse()[2]) / 3;
			cout << "Student ID: " << studentId << " average days in course is: " << averageDays;
		}
	}
	cout << endl;
}

//invalid emails function
void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastIndex; i++) {
		string email = classRosterArray[i]->GetemailAddress();
		if (email.find(' ') != string::npos)
			cout << email << " is invalid" << endl;
		else if (email.find('@') == string::npos)
			cout << email << " is invalid" << endl;
		else if (email.find('.') == string::npos)
			cout << email << " is invalid" << endl;
	}
	cout << endl;
}

//Degree by student function
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= lastIndex; i++) {
		if (degreeProgram == classRosterArray[i]->GetdegreeProgram()) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

//Destructor function
Roster::~Roster() {
	for (int i = 0; i < lastIndex; ++i) {
		delete classRosterArray[i];
	}
}