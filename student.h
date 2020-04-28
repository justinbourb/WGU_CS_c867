#ifndef student_h
#define student_h
using namespace std;

class Student {
public:
    //getters
    int getStudentIDFunc();
    string getFirstNameFunc();
    string getLastNameFunc();
    string getEmailFunc();
    int getAgeFunc();
    int getNumDaysFunc(int numDays[]);
    int getDegreeTypesFunc();
    //setters
    int setStudentIDFunc(int studentID);
    string setFirstNameFunc(string firstName);
    string setLastNameFunc(string lastName);
    string setEmailFunc(string email);
    int setAgeFunc(int age);
    int setNumDaysFunc(int numDays);
    int setDegreeTypesFunc(int degreeIn);
    //constuctor
    Student();
    //deconstructor
    ~Student();
    //degreetypes

private:
    int studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int numDays;
    int degreeTypes;
};


#endif