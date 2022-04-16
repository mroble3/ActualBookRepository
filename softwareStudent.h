// file name softwareStudent.h
// Author Mohamed Roble
// Date 09/12/2019
#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class SoftwareStudent : public Student//This class also derives from Student
{
private:
	DegreeType dtype;
public:
	SoftwareStudent();
	SoftwareStudent(
		string StudentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int days[],
		DegreeType degreetype
	);
	DegreeType getDegreeType();//Overrides the virtual method from Student
	void print();

	~SoftwareStudent();
};
