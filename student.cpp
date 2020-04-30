#include <string>
#include "student.h"
using namespace std;


//default constructor
Student::Student() {
    studentID = "0000";
    firstName = "no name entered";
    lastName = "no name entered";
    email = "no email entered";
    age = "0000";
    degreeTypes = 0000;
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
string Student::getAgeFunc() {
    return age;
};
int Student::getNumDaysFunc(int *numDays) {
    return *numDays;
};
int Student::getDegreeTypesFunc() {
    return degreeTypes;
};
//setters
void Student::setStudentIDFunc(string idIn) {
    studentID = idIn;;
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
void Student::setAgeFunc(string ageIn) {
    age = ageIn;
};
void Student::setNumDaysFunc(int daysIn) {
    numDays = daysIn;
};
void Student::setDegreeTypesFunc(int degreeIn) {
    degreeTypes = degreeIn;
};