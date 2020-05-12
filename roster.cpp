#include <iostream>
using namespace std;
#include "student.h"
#include "degree.h"
#include <vector>
#include "roster.h"
#include <string>
#include <iterator>

int arrayItemsCounter = 0;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Justin,Bourbonniere,jbourb@wgu.edu,36,20,25,30,SOFTWARE"};

void printClassInfo() {
    //this function prints class info to the console
    cout << "C867 - Scripting & Programming Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: #001200647" << endl;
    cout << "Name: Justin Bourbonniere" << endl << endl;
}

Degree degreeConversionFunc(string degreeIn) {
    //this function converts studentData string degree into enum Degree type
    if (degreeIn == "SECURITY") {
        return SECURITY;
    }
    if (degreeIn == "NETWORK") {
        return NETWORK;
    }
    return SOFTWARE;
};

string reverseDegreeConversionFunc(Degree degreeIn) {
    //this function converts Degree degreeIn into a string
    if (degreeIn == SECURITY) {
        return "SECURITY";
    }
    if (degreeIn == NETWORK) {
        return "NETWORK";
    }
    return "SOFTWARE";
}

void defaultConstructorTest() {
    //this function tests the default constuctor output
    NetworkStudent student1; // User-created object of class type RunnerInfo
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
    //this function tests settting Student values functions and outputs results
    NetworkStudent student1; // User-created object of class type RunnerInfo
    Degree degree = NETWORK;
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
    //this function tests adding values to rosterClass and prints results to console
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
    //this function runs all tests
    defaultConstructorTest();
    settingStudentValuesTest();
    rosterAddTest();
};

Roster parseCSVFunc2(const string studentData[]) {
    //this function accepts a csv string and parses the data to a temp vector.
    //Next it calls roster.add() on the data.
    //I don't like calling functions within functions, but the class requirements implies
    //this is required.
    vector<string> tempVector;
    string tempString;
    Degree degreeConversion;
    Roster rosterClass;
    string tempStringForConversion;
    for (int i = 0; i < 5; i++) {
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
            if (j == (studentData[i].length() - 1)) {
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
    }
    return rosterClass;
};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeIn) {
    //This function calls degreeConversion on the provided string to create an enum type
    //Then it adds all the provided data to the classRosterArray.
    //arrayItemsCounter is a global variable which tracks how many items are set in classRosterArray.
    //We are required to use an array of pointers and arrayItemsCounter is used to prevent trying to access a pointer with no data set
    Degree degreeConversion = degreeConversionFunc(degreeIn);
    classRosterArray[arrayItemsCounter]->setAllFunc(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeConversion);
    arrayItemsCounter++;
};

void Roster::printAll() {
    //This function prints all the items in classRosterArray, as checked via arrayItemsCounter
    //It only prints items which are not set to NULL
    //If set to NULL then the items has been deleted and printing it would cause an error
    for (int i = 0; i < arrayItemsCounter; i++) {
        //check for deleted items
        if (classRosterArray[i] != NULL) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
};

void Roster::printByDegreeProgram(int degreeProgram) {
    //This function calls classRosterArray.print() based on the degree program provided.
    //Since this function accepts int type, the series of if statements are required to print the string
    //equivalent to the console.

    //This function is not required to check for NULL items by course requirements, 
    //but it should for a real world use case.
    
    cout << endl << "Showing students in degree program: ";
    //finish string in if statement degree checks
    Degree whichDegree;
    if (degreeProgram == 0) {
        whichDegree = SECURITY;
        cout << "SECURITY" << endl << endl;
    }
    if (degreeProgram == 1) {
        whichDegree = NETWORK;
        cout << "NETWORKING" << endl << endl;
    }
    if (degreeProgram == 2) {
        whichDegree = SOFTWARE;
        cout << "SOFTWARE" << endl << endl;
    }
    for (int i = 0; i < arrayItemsCounter; i++) {
        if (whichDegree == classRosterArray[i]->getDegreeTypesFunc()) {
            classRosterArray[i]->print();
        }
    }
};

void Roster::printDaysInCourse(string studentID) {
    //This function prints the average number of days each student in classRosterArray spends in their courses 
    //(only 3 values are provided, so division by 3 is hardcoded).

    //This function is not required to check for NULL items by course requirements, 
    //but it should for a real world use case.

    for (int i = 0; i < arrayItemsCounter; i++) {
        string currentID = classRosterArray[i]->getStudentIDFunc();
        if (currentID == studentID) {
            int averageDays = (classRosterArray[i]->getNumDaysFunc(0) + classRosterArray[i]->getNumDaysFunc(1) + classRosterArray[i]->getNumDaysFunc(2)) / 3;
            cout << "Student ID: " << studentID << ", averages " << averageDays << " in a course." << endl;
        }
    }
};
void Roster::printInvalidEmails() {
    //This function checks all the emails in classRosterArray and prints out invalid emails.
    //Course requirements define valid emails as have @ and .
    //Course requirements define invalid emails as have a space.

    //This function is not required to check for NULL items by course requirements, 
    //but it should for a real world use case.

    string tempEmail;
    cout << "Displaying Invalid Emails: " << endl << endl;
    //check the email address for each Student in classRosterArray for validity
    for (int i = 0; i < arrayItemsCounter; i++) {
        bool hasAtSymbol = false;
        bool hasPeriodSymbol = false;
        //get the email address
        tempEmail = classRosterArray[i]->getEmailFunc();
        //size_t is the type of .length(), yet another c++ oddity
        for (size_t j = 0; j < tempEmail.length(); j++) {
            //need @ and . cannot have ' '
            if (tempEmail[j] == ' ') {
                //email - No spaces allowed
                cout << tempEmail << " - No spaces allowed." << endl;
            }
            if (tempEmail[j] == '@') {
                hasAtSymbol = true;
            }
            if (tempEmail[j] == '.') {
                hasPeriodSymbol = true;
            }
        }
        if (hasAtSymbol == false) {
            cout << tempEmail << " - Missing an @ symbol." << endl;
        }
        if (hasPeriodSymbol == false) {
            cout << tempEmail << " - Missing a period." << endl;
        }
    }
    cout << endl;
};

void Roster::remove(string studentID) {
    //This function deletes a pointer from classRosterArray based on studentID.
    //Next it sets the deleted index to NULL to allow for checking of deleted indexes.

    //convert type char to type string and find the array Index(+1)
    string arrayIndexString = studentID;
    string str(arrayIndexString);
    arrayIndexString = arrayIndexString.at(1);
    int arrayIndex = stoi(arrayIndexString) - 1;
    //this if statement will be Roster::remove() else statement deletes item
    if (classRosterArray[arrayIndex] != NULL) {
        cout << "Removing " << studentID << ":" << endl;
        delete classRosterArray[arrayIndex];
        //deleted items are set to NULL, to allow us to check for deleted items
        //without a critical error
        classRosterArray[arrayIndex] = NULL;
    }
    else {
        cout << "Removing " << studentID << " again:" << endl << endl;
        cout << "The student with id " << studentID << " was not found." << endl;
    }

};
Roster::Roster() {
};
//destructor
Roster::~Roster() {
};


int main() {
    printClassInfo();
    Roster rosterClass = parseCSVFunc2(studentData);
    rosterClass.printAll();
    rosterClass.printInvalidEmails();
    for (size_t i = 0; i < arrayItemsCounter; i++) {
        rosterClass.printDaysInCourse(rosterClass.classRosterArray[i]->getStudentIDFunc());
    }
    rosterClass.printByDegreeProgram(SOFTWARE);
    rosterClass.remove("A3");
    rosterClass.printAll();
    rosterClass.remove("A3");
    
    return 0;
}