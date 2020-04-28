#include <string>
#include "student.h"
using namespace std;


//default constructor
Student::Student() {
    studentID = 0000;
    firstName = "no name entered";
    lastName = "no name entered";
    email = "no email entered";
    age = 0000;
    degreeTypes = 0000;
};
//destructor
Student::~Student() {
};
//getters
int Student::getStudentIDFunc() {
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
int Student::getNumDaysFunc(int *numDays) {
    return *numDays;
};
int Student::getDegreeTypesFunc() {
    return degreeTypes;
};
//setters
int Student::setStudentIDFunc(int idIn) {
    return studentID = idIn;;
};
string Student::setFirstNameFunc(string nameFirst) {
    return firstName = nameFirst;
};
string Student::setLastNameFunc(string nameLast) {
    return lastName = nameLast;
};
string Student::setEmailFunc(string enteredMail) {
    return email = enteredMail;
};
int Student::setAgeFunc(int ageIn) {
    return age = ageIn;
};
int Student::setNumDaysFunc(int daysIn) {
    return numDays = daysIn;
};
int Student::setDegreeTypesFunc(int degreeIn) {
    return degreeTypes = degreeIn;
};