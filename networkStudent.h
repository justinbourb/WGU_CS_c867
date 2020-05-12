#ifndef networkStudent_h
#define networkStudent_h
using namespace std;
#include "degree.h"
#include "student.h"

class NetworkStudent : public Student {
public:
	Degree getDegreeProgram();
private:
	Degree degreeType;
};


#endif