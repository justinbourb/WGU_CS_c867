#include <iostream>
using namespace std;
#include "student.h"
#include "degree.h"
#include <vector>
#include "roster.h"
#include <string>
#include <iterator>

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY" };

void printClassInfo() {
    cout << "C867 - Scripting & Programming Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: #001200647" << endl;
    cout << "Name: Justin Bourbonniere" << endl;

}
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

Degree degreeConversionFunc(string degreeIn) {
    //converts studentData string degree into enum Degree type
    if (degreeIn == "SECURITY") {
        return SECURITY;
    }
    if (degreeIn == "NETWORKING") {
        return NETWORKING;
    }
    return SOFTWARE;
};

string reverseDegreeConversionFunc(Degree degreeIn) {
    if (degreeIn == SECURITY) {
        return "SECURITY";
    }
    if (degreeIn == NETWORKING) {
        return "NETWORKING";
    }
    return "SOFTWARE";
}

Roster parseCSVFunc2(const string studentData[]) {
    vector<string> tempVector;
    string tempString;
    Degree degreeConversion;
    Roster rosterClass;
    string tempStringForConversion;
    for (int i = 0; i < 4; i++) {
        tempVector.clear();
        for (size_t j = 0; j < studentData[i].length(); j++) {
            //size_t is the type of .length(), yet another c++ oddity
            if (studentData[i][j] != ',') {
                tempString += studentData[i][j];
            }
            //push back every csv to tempVector
            else {
                tempVector.push_back(tempString);
                tempString = "";
            }
            //push back last value to tempVator
            if (j == (studentData[i].length()-1)) {
                tempVector.push_back(tempString);
                tempString = "";
            }
        }
        //0-8 vector items
        //0. id 1. fname 2. lname 3. email 4-7. days array 8. major
        //stoi converts tempStringForConversion to int, this is required since tempVector[i] is type string
        tempStringForConversion = tempVector.at(4);
        int age = stoi(tempStringForConversion);
        tempStringForConversion = tempVector.at(5);
        int num1 = stoi(tempStringForConversion);
        tempStringForConversion = tempVector.at(6);
        int num2 = stoi(tempStringForConversion);
        tempStringForConversion = tempVector.at(7);
        int num3 = stoi(tempStringForConversion);

        rosterClass.add(tempVector.at(0), tempVector.at(1), tempVector.at(2), tempVector.at(3),
            age, num1, num2, num3, tempVector.at(8));
        
        /*
        //c++ cannot dynamically create Student objects, have to hardcode this with WET code
        if (i == 0) {
            Student student0;
            //0-8 vector items
            //0. id 1. fname 2. lname 3. email 4-7. days array 8. major
            //stoi converts string1 to int, this is required since tempVector is type string
            string string1 = tempVector.at(4);
            int age = stoi(string1);
            string1 = tempVector.at(5);
            int num1 = stoi(string1);
            string1 = tempVector.at(6);
            int num2 = stoi(string1);
            string1 = tempVector.at(7);
            int num3 = stoi(string1);
            degreeConversion = degreeConversionFunc(tempVector.at(8));

            student0.setAllFunc(tempVector.at(0), tempVector.at(1), tempVector.at(2), tempVector.at(3),
                age, num1, num2, num3, degreeConversion);
            student0.print();
        }
        if (i == 1) {
            Student student1;
            //0-8 vector items
            //0. id 1. fname 2. lname 3. email 4-7. days array 8. major
             //stoi converts string to int
            int age = stoi(tempVector.at(4));
            int num1 = stoi(tempVector.at(5));
            int num2 = stoi(tempVector.at(6));
            int num3 = stoi(tempVector.at(7));
            degreeConversion = degreeConversionFunc(tempVector.at(8));

            student1.setAllFunc(tempVector.at(0), tempVector.at(1), tempVector.at(2), tempVector.at(3),
                age, num1, num2, num3, degreeConversion);
            student1.print();
        }
        if (i == 2) {
            Student student2;
            //0-8 vector items
            //0. id 1. fname 2. lname 3. email 4-7. days array 8. major
            //stoi converts string to int
            int age = stoi(tempVector.at(4));
            int num1 = stoi(tempVector.at(5));
            int num2 = stoi(tempVector.at(6));
            int num3 = stoi(tempVector.at(7));
            degreeConversion = degreeConversionFunc(tempVector.at(8));

            student2.setAllFunc(tempVector.at(0), tempVector.at(1), tempVector.at(2), tempVector.at(3),
                age, num1, num2, num3, degreeConversion);
            student2.print();
        }
        if (i == 3) {
            Student student3;
            //0-8 vector items
            //0. id 1. fname 2. lname 3. email 4-7. days array 8. major
             //stoi converts string to int
            int age = stoi(tempVector.at(4));
            int num1 = stoi(tempVector.at(5));
            int num2 = stoi(tempVector.at(6));
            int num3 = stoi(tempVector.at(7));
            degreeConversion = degreeConversionFunc(tempVector.at(8));

            student3.setAllFunc(tempVector.at(0), tempVector.at(1), tempVector.at(2), tempVector.at(3),
                age, num1, num2, num3, degreeConversion);
            student3.print();
        }
        */
    }
    return rosterClass;
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
    student1.setStudentIDFunc("01"); // how to run class member function
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


Roster rosterAddTest() {
    Roster rosterClass;
    cout << "**************************" << endl;
    cout << "Roster.add() Test" << endl;
    rosterClass.add("A1", "Mike", "Jones", "mj@mj.net", 25, 24, 23, 22, "NETWORKING");
    rosterClass.add("A2", "Mikey", "Diamonds", "MikeyD@one.net", 21, 20, 19, 18, "SECURITY");
    rosterClass.printAll();
    cout << "**************************" << endl;
    return rosterClass;
}

void runAllTestsFunc() {
    defaultConstructorTest();
    settingStudentValuesTest();
    rosterAddTest();
};


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeIn) {
    Student student;
    Degree degreeConversion = degreeConversionFunc(degreeIn);
    student.setAllFunc(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeConversion);
    classRosterArray.push_back(student);
};
void Roster::printAll() {
    //update to loop over vector items from 0 to size-1
    int size = classRosterArray.size();
    for (int i = 0; i < size; i++) {
        cout << classRosterArray[i].getStudentIDFunc() << "     First Name: " << classRosterArray[i].getFirstNameFunc() << "     Last Name: " << classRosterArray[i].getLastNameFunc();
        cout << "     Age: " << classRosterArray[i].getAgeFunc() << "     daysInCourse: {" << classRosterArray[i].getNumDaysFunc(0) << ", " << classRosterArray[i].getNumDaysFunc(1) << ", " << classRosterArray[i].getNumDaysFunc(2) << "} ";
        cout << "Degree Program: " << reverseDegreeConversionFunc(classRosterArray[i].getDegreeTypesFunc()) << endl;
    }
};
Roster::Roster() {
};
//destructor
Roster::~Roster() {
};
//class Roster
// Roster classRoster
// classRoster.classRosterArray <student0,1,2,3,4>
//classRoster.printAll() //loops over array and calls print on each
//classRoster.add() // creates a Student student and adds it to the classRoster.classRosterArray
    //move Student.addAll to Roster class
//classRoster.remove(id) // removes a student from the vector classRoster.classRosterArray

int main() {
    printClassInfo();
    Roster rosterClass = parseCSVFunc2(studentData);
    rosterClass.printAll();
    
    return 0;
}