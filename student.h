#ifndef student_h
#define student_h
using namespace std;

class Student {
public:
    //getters
    string getStudentIDFunc();
    string getFirstNameFunc();
    string getLastNameFunc();
    string getEmailFunc();
    string getAgeFunc();
    int getNumDaysFunc(int numDays[]);
    int getDegreeTypesFunc();
    //setters
    void setStudentIDFunc(string studentID);
    void setFirstNameFunc(string firstName);
    void setLastNameFunc(string lastName);
    void setEmailFunc(string email);
    void setAgeFunc(string age);
    void setNumDaysFunc(int numDays);
    void setDegreeTypesFunc(int degreeIn);
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
    string age;
    int numDays;
    int degreeTypes;
};


#endif