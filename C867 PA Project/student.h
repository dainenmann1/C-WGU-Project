#include <string>
#include <iostream>
#include <vector>
#include "degree.h"
using namespace std;

class Student {
public:
    Student();

    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    ~Student();

    string GetstudentId() const;
    string GetfirstName() const;
    string GetlastName() const;
    string GetemailAddress() const;
    int Getage() const;
    vector<int> GetdaysInCourse() const;
    DegreeProgram GetdegreeProgram() const;

    void SetstudentId(string studentIdToSet);
    void SetfirstName(string firstNameToSet);
    void SetlastName(string lastNameToSet);
    void SetemailAddress(string emailAddressToSet);
    void Setage(int ageToSet);
    void SetdaysInCourse(vector<int> daysInCourseToSet);
    void SetdegreeProgram(DegreeProgram degreeToSet);
    virtual void print();

private:
    string         studentId;
    string         firstName;
    string         lastName;
    string         emailAddress;
    int            age;
    vector<int>    daysInCourse;
    DegreeProgram  degreeProgram;
};