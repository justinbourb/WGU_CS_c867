#include <iostream>
using namespace std;
#include "student.h"
#include "degree.h"

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY" };

//for loop parses csv in studentData and prints a new line for every ,
//need to upgrade this to pass parameters to create a student object??
void parseCSVFunc(const string studentData[]) {
    for (int i = 0; i < 4; i++) {
        for (size_t j = 0; j < studentData[i].length(); j++) {
            //size_t is the type of .length(), yet another c++ oddity
            if (studentData[i][j] != ',') {
                cout << studentData[i][j];
            }
            else {
                cout << endl;
            }
        }
        cout << endl;
    }
};

void defaultConstructorTest() {
    Student student1; // User-created object of class type RunnerInfo
    cout << "**************************" << endl;
    cout << "Default constructor settings" << endl;
    cout << "ID: " << student1.getStudentIDFunc() << endl;
    cout << "First Name: " << student1.getFirstNameFunc() << endl;
    cout << "Last Name: " << student1.getLastNameFunc() << endl;
    cout << "Email: " << student1.getEmailFunc() << endl;
    cout << "Age: " << student1.getAgeFunc() << endl;
    cout << "Degree Type: " << student1.getDegreeTypesFunc() << endl;
    cout << "**************************" << endl;
};
void settingStudentValuesTest() {
    Student student1; // User-created object of class type RunnerInfo
    Degree degree = NETWORKING;
    student1.setStudentIDFunc(01); // how to run class member function
    student1.setFirstNameFunc("Mike");
    student1.setLastNameFunc("Jones");
    student1.setEmailFunc("mike_jones@jones.net");
    student1.setAgeFunc(25);
    student1.setDegreeTypesFunc(degree);

    cout << "**************************" << endl;
    cout << "Setting Student Values Test" << endl;
    cout << "ID: " << student1.getStudentIDFunc() << endl;
    cout << "First Name: " << student1.getFirstNameFunc() << endl;
    cout << "Last Name: " << student1.getLastNameFunc() << endl;
    cout << "Email: " << student1.getEmailFunc() << endl;
    cout << "Age: " << student1.getAgeFunc() << endl;
    cout << "Degree Type: " << student1.getDegreeTypesFunc() << endl;
    cout << "**************************" << endl;

};

void runAllTestsFunc() {
    defaultConstructorTest();
    settingStudentValuesTest();
};

int main() {

    runAllTestsFunc();

    return 0;
}