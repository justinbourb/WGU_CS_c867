#ifndef softwareStudent_h
#define softwareStudent_h
using namespace std;
#include "degree.h"
#include "student.h"

class SoftwareStudent : public Student {
public:
	Degree getDegreeProgram();
private:
	Degree degreeType;
};


#endif