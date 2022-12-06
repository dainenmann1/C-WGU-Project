#include <iostream>
#include <string>
#include <vector>
#include "student.h"
using namespace std;

//default constructor
Student::Student() {

}

//destructor
Student::~Student() {

}

//add
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    SetstudentId(studentId);
    SetfirstName(firstName);
    SetlastName(lastName);
    SetemailAddress(emailAddress);
    Setage(age);
    daysInCourse.push_back(daysInCourse1);
    daysInCourse.push_back(daysInCourse2);
    daysInCourse.push_back(daysInCourse3);
    SetdegreeProgram(degreeProgram);
}

//set and get studentid
void Student::SetstudentId(string studentIdToSet) {
    studentId = studentIdToSet;
}
 
string Student::GetstudentId() const {
    return studentId;
}

//set and get firstname
void Student::SetfirstName(string firstNameToSet) {
    firstName = firstNameToSet;
}

string Student::GetfirstName() const {
    return firstName;
}

//set and get last name
void Student::SetlastName(string lastNameToSet) {
    lastName = lastNameToSet;
}

string Student::GetlastName() const {
    return lastName;
}

//set and get email
void Student::SetemailAddress(string emailAddressToSet) {
    emailAddress = emailAddressToSet;
}

string Student::GetemailAddress() const {
    return emailAddress;
}

//set and get age
void Student::Setage(int ageToSet) {
    age = ageToSet;
}

int Student::Getage() const {
    return age;
}

//set and get days in course using a vector
void Student::SetdaysInCourse(vector<int> daysInCourseToSet) {
    daysInCourse = daysInCourseToSet;
}

vector<int> Student::GetdaysInCourse() const {
    return daysInCourse;
}

//set and get degree program
DegreeProgram Student::GetdegreeProgram() const {
    return degreeProgram;
}

void Student::SetdegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//print function
void Student::print() {
    string program;
    if (degreeProgram == DegreeProgram::SECURITY) {
        program = "SECURITY";
    }
    else if (degreeProgram == DegreeProgram::NETWORK) {
        program = "NETWORK";
    }
    else if (degreeProgram == DegreeProgram::SOFTWARE) {
        program = "SOFTWARE";
    }
    cout << studentId << "\t"; 
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "Days In Course: {" << daysInCourse.at(0) << ", " << daysInCourse.at(1) << ", " << daysInCourse.at(2) << "}" << "\t";
    cout << "Degree Program: " << program << "\t";

}