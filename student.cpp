#include <string>
#include "student.h"
#include <iostream>
#include "degree.h"
#include "roster.h"
using namespace std;


//default constructor
Student::Student() {
    studentID = "0000";
    firstName = "no name entered";
    lastName = "no name entered";
    email = "no email entered";
    age = 0000;
    degreeTypes = BLANK;
};
//destructor
Student::~Student() {
};
//getters
string Student::getStudentIDFunc() {
    return studentID;
};
string Student::getFirstNameFunc() {
    return firstName;
};
string Student::getLastNameFunc() {
    return lastName;
};
string Student::getEmailFunc() {
    return email;
};
int Student::getAgeFunc() {
    return age;
};
int Student::getNumDaysFunc(int index) {
    return numDays[index];
};
Degree Student::getDegreeTypesFunc() {
    return degreeTypes;
};
//setters
void Student::setStudentIDFunc(string idIn) {
    studentID = idIn;
};
void Student::setFirstNameFunc(string nameFirst) {
    firstName = nameFirst;
};
void Student::setLastNameFunc(string nameLast) {
    lastName = nameLast;
};
void Student::setEmailFunc(string enteredMail) {
    email = enteredMail;
};
void Student::setAgeFunc(int ageIn) {
    age = ageIn;
};
void Student::setNumDaysFunc(int daysIn) {
    //FIXME or delete?
    //numDays = daysIn;
};
void Student::setDegreeTypesFunc(Degree degreeIn) {
    degreeTypes = degreeIn;
};
void Student::setAllFunc(string idIn, string nameFirst, string nameLast, string enteredMail, int ageIn, int daysIn0, int daysIn1, int daysIn2, Degree degreeIn) {
    studentID = idIn;
    firstName = nameFirst;
    lastName = nameLast;
    email = enteredMail;
    age = ageIn;
    numDays[0] = daysIn0;
    numDays[1] = daysIn1;
    numDays[2] = daysIn2;
    degreeTypes = degreeIn;
};
//print
void Student::print() {
    cout << getStudentIDFunc() << "     First Name: " << getFirstNameFunc() << "     Last Name: " << getLastNameFunc();
    cout << "     Age: " << getAgeFunc() << "     daysInCourse: {" << getNumDaysFunc(0) <<", " << getNumDaysFunc(1) << ", " << getNumDaysFunc(2) << "} ";
    cout << "Degree Program: " << reverseDegreeConversionFunc(getDegreeTypesFunc()) << endl;
};