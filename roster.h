#ifndef roster_h
#define roster_h
using namespace std;
//class Roster
// Roster classRoster
// classRoster.classRosterArray <student0,1,2,3,4>
//classRoster.printAll() //loops over array and calls print on each
//classRoster.add() // 
    //move Student.addAll to Roster class
//classRoster.remove(id) // removes a student from the vector classRoster.classRosterArray
class Roster {
public:
    //getters
    void printAll();
    //setters
    //creates a Student student and adds it to the classRoster.classRosterArray
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeIn);
    //print
    //virtual void print();
    //constuctor
    Roster();
    //deconstructor
    ~Roster();
    vector<Student> classRosterArray;

private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    string stringDays;
    string stringDegreeTypes;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    int degreeTypes;
};


#endif