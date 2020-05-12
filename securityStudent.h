#ifndef securityStudent_h
#define securityStudent_h
using namespace std;
#include "degree.h"
#include "student.h"

class SecurityStudent : public Student {
public:
	Degree getDegreeProgram();
private:
	Degree degreeType;
};


#endif