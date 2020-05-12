#ifndef roster_h
#define roster_h
#include "degree.h"
#include "student.h"
#include <vector>
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
using namespace std;


class Roster {
public:
    //getters
    void printAll();
    void printByDegreeProgram(int degreeProgram);
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    //setters
    void remove(string studentID);
    //creates a Student student and adds it to the classRoster.classRosterArray
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeIn);
    //print
    //virtual void print();
    //constuctor
    Roster();
    //deconstructor
    ~Roster();
    Student* classRosterArray[5] = { new SecurityStudent, new NetworkStudent, new SoftwareStudent, new SecurityStudent, new SoftwareStudent };
private:

};

string reverseDegreeConversionFunc(Degree degreeIn);
Roster parseCSVFunc2(const string studentData[]);

#endif