#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Dainen,Mann,dmann21@wgu.edu,25,30,50,10,SOFTWARE"};

	const int numberStudents = 5;
	Roster* classRoster = new Roster(numberStudents);
	for (int i = 0; i < numberStudents; i++) {
		classRoster->parse(studentData[i]);
	}
	
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 982487" << endl;
	cout << "Name: Dainen Mann" << endl;
	cout << " " << endl;

	classRoster->printAll();

	cout << endl;
	
	classRoster->printInvalidEmails();
	
	classRoster->printAverageDaysInCourse("A1");
	classRoster->printAverageDaysInCourse("A2");
	classRoster->printAverageDaysInCourse("A3");
	classRoster->printAverageDaysInCourse("A4");
	classRoster->printAverageDaysInCourse("A5");

	cout << endl;
	
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << endl;

	classRoster->remove("A3");

	cout << endl;

	classRoster->printAll();

	cout << endl;

	classRoster->remove("A3");

	classRoster->~Roster();
}