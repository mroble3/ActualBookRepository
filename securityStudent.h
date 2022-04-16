// file name securityStudent.h
// Author Mohamed Roble
// Date 09/12/2019
#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SecurityStudent : public Student //A SecurityStudent is a particular degree type of Degree, so it inherits from Student class
{
private:
	DegreeType dtype;
public:
	//CONSTRUCTORS WILL CALL SUPERCONSTRUCTOR FROM Student
	SecurityStudent();
	SecurityStudent(
		string StudentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int days[],
		DegreeType degreetype
	);
	//The following virtual methods from Student are overridden in this class; we CAN create a SecurityStudent object!
	DegreeType getDegreeType();
	void print();

	//DESTRUCTOR WILL CALL SUPERDESTRUCTOR FROM Student
	~SecurityStudent();
};

