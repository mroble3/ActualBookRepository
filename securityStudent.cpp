// file name securityStudent.cpp
// Author Mohamed Roble
// Date 09/12/2019
#include <iostream>
#include<iomanip>
#include "securitystudent.h"
using std::cout;
using std::left;
using std::setw;

SecurityStudent::SecurityStudent():Student()
{
	//This is the only work this constructor needs to do; the Student class will do the rest; NEAT, HUH?
	dtype = SECURITY;
}

SecurityStudent::SecurityStudent(string StudentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType degreetype)
	:Student(StudentID, firstName, lastName, emailAddress, age, days)
{
	dtype = SECURITY;
}

DegreeType SecurityStudent::getDegreeType()
{
	return SECURITY;//Now we can do this - it's not virtual anymore
}

void SecurityStudent::print()
{
	cout << left << setw(5) << getStudentID();
	cout << left << setw(15) << getfirstName();
	cout << left << setw(20) << getlastName();
	cout << left << setw(30) << getemailAddress();
	cout << left << setw(5) << getage();
	cout << left << setw(10) << getDays()[0];
	cout << left << setw(10) << getDays()[1];
	cout << left << setw(10) << getDays()[2];
	//this->Student::print();//Call the print method from the Student class
	cout << "SECURITY" << "\n";//This is the only thing left to display
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();//Call the super destructor from Student in case it needs to release something
	//Note: objects should not destroy themselves; only what they dynamically create for themselves
}
