#ifndef student_h
#define student_h
using namespace std;
#include "degree.h"

class Student {
public:
    //getters
    string getStudentIDFunc();
    string getFirstNameFunc();
    string getLastNameFunc();
    string getEmailFunc();
    int getAgeFunc();
    int getNumDaysFunc(int index);
    Degree getDegreeTypesFunc();
    virtual void getDegreeProgram();
    //setters
    void setStudentIDFunc(string studentID);
    void setFirstNameFunc(string firstName);
    void setLastNameFunc(string lastName);
    void setEmailFunc(string email);
    void setAgeFunc(int age);
    void setNumDaysFunc(int numDays);
    void setDegreeTypesFunc(Degree degreeIn);
    void setAllFunc(string idIn, string nameFirst, string nameLast, string enteredMail, int ageIn, int daysIn0, int daysIn1, int daysIn2, Degree degreeIn);
    //print
    virtual void print();
    //constuctor
    Student();
    //deconstructor
    ~Student();
    //degreetypes

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    string stringDays;
    string stringDegreeTypes;
    int numDays[3];
    Degree degreeTypes;
};


#endif