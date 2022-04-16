// file name student.cpp
// Author Mohamed Roble
// Date 09/12/2019
#include<iostream>
#include<iomanip>
#include "student.h"
using std::cout;
using std::left;
using std::setw;

Student::Student()//Empty constructor will set all to default values
{
	

	//NOTE that neither Student constructor sets the DegreeType - the type of Student is not known
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[])//The full constructor
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i<daysArraySize; i++) this->days[i] = days[i];
}

//getters
string Student::getStudentID()
{
	return studentID;
}

string Student::getfirstName()
{
	return firstName;
}

string Student::getlastName()
{
	return lastName;
}

string Student::getemailAddress()
{
	return emailAddress;
}

int Student::getage()
{
	return age;
}

int * Student::getDays()
{
	return days;
}

void Student::setStudentID(string ID)
{
	studentID = ID;
}

void Student::setfirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setlastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setemailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setage(int age)
{
	this->age = age;
}

void Student::setDays(double days[])
{
	for (int i = 0; i<daysArraySize; i++)
		this->days[i] = days[i];
}

//The print method displays all fields EXCEPT the degree type!
void Student::print()
{
	
}

Student::~Student()
{
//Student object does not declare anything dynamically for its own use
//So this destructor has an easy job; that is, nothing
}

//NOTE THIS 'ABSTRACT' CLASS SEEMS TO BE DOING A LOT OF WORK!  
//IT WON'T GO TO WASTE; THE DERIVED CLASSES WILL USE IT!
