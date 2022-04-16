// file name softwareStudent.cpp
// Author Mohamed Roble
// Date 09/12/2019
#include <iostream>
#include<iomanip>
#include "softwarestudent.h"
using std::cout;
using std::left;
using std::setw;
//Look at SecurityStudent for explanation - it's the same story
SoftwareStudent::SoftwareStudent()
	:Student()
{
	dtype = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string StudentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degreetype)
	:Student(StudentID, firstName, lastName, emailAddress, age, days)
{
	dtype = SOFTWARE;
}

DegreeType SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::print()
{
	cout << left << setw(5) << getStudentID();
	cout << left << setw(15) << getfirstName();
	cout << left << setw(20) << getlastName();
	cout << left << setw(30) << getemailAddress();
	cout << left << setw(5) << getage();
	cout << left << setw(10) << getDays()[0];
	cout << left << setw(10) << getDays()[1];
	cout << left << setw(10) << getDays()[2];
	//this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
