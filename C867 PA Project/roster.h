#include <string>
#include <iostream>
#include "student.h"
using namespace std;

class Roster {
public:
	Roster();

	Roster(int amount);

	void parse(string data);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	
	~Roster();

private:
	int amount;
	int lastIndex;
	Student** classRosterArray;
};
