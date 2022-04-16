// file name networkStudent.h 
// Author Mohamed Roble
// Date 09/12/2019
#pragma once
#include <string>
#include "degree.h"
#include "student.h"
class NetworkStudent : public Student //A NetworkStudent is a particular type of Degree, so it inherits from Student class
{
private:
	DegreeType dtype;
public:
	//CONSTRUCTORS WILL CALL SUPERCONSTRUCTOR FROM Student
	NetworkStudent();
	NetworkStudent(
		string StudentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int days[],
		DegreeType degreetype
	);
	//The following virtual methods from Student are overridden in this class; we CAN create a NetworkStudent object!
	DegreeType getDegreeType();
	void print();

	//DESTRUCTOR WILL CALL SUPERDESTRUCTOR FROM Student
	~NetworkStudent();
};

